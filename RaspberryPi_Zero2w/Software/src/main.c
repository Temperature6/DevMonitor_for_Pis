#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>
#include "st7789.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "gui_guider.h"
#include "NetTools.h"
#include "DevInfo.h"
#include "user_cfg.h"

#define TEMP_STR_LEN    64
#define IP_STR_LEN      20
#define TO_GB(b)        ((b) / pow(1024, 3))
#define TO_SEC(h, m)    ((h) * 3600 + (m) * 60)

time_t currentTime;
struct tm *localTime;
uint8_t UpdateFlag;
char ipStr[IP_STR_LEN];
char tempStr[TEMP_STR_LEN];
unsigned int freeMem, totalMem;
long int start_rcv_rates = 0;   //保存开始时的流量计数
long int end_rcv_rates = 0;	    //保存结束时的流量计数
long int start_tx_rates = 0;    //保存开始时的流量计数
long int end_tx_rates = 0;      //保存结束时的流量计数
float tx_rates = 0;             //上传速度Bytes/s
float rx_rates = 0;             //下载速度Bytes/s
CPU_OCCUPY cpu_stat1;           //用于CPU利用率计算
CPU_OCCUPY cpu_stat2;
float cpuUsage;
Net_State wlanState;
char netSpeedUnit[4][5] = {
    "B/s",
    "KB/s",
    "MB/s",
    "GB/s",
};
lv_ui guider_ui;

void Timer_Init();
void Timer_Handler();
void UpdateScreen();

int main()
{
    Timer_Init();
    lv_init();
    lv_port_disp_init();

    setup_ui(&guider_ui);
    lv_obj_set_scrollbar_mode(lv_scr_act(), LV_SCROLLBAR_MODE_OFF);
    
    while (1)
    {
        lv_timer_handler();

        GetCurNetFlow(WLAN_IF, &start_rcv_rates, &start_tx_rates);
        get_cpuoccupy((CPU_OCCUPY *)&cpu_stat1);
        pause();    //暂停，等待信号
        get_cpuoccupy((CPU_OCCUPY *)&cpu_stat2);
        GetCurNetFlow(WLAN_IF, &end_rcv_rates, &end_tx_rates);

        //计算CPU利用率
        cpuUsage = cal_cpuoccupy((CPU_OCCUPY *)&cpu_stat1,(CPU_OCCUPY *)&cpu_stat2);
        //计算网速
        rx_rates = (float)(end_rcv_rates - start_rcv_rates) / REFRESH_TIME;
        tx_rates = (float)(end_tx_rates - start_tx_rates) / REFRESH_TIME;
        
        UpdateScreen();
    }
    
}

void UpdateScreen()
{
    /*显示网络状态*/
    wlanState = GetWirelessState();

    if (wlanState == STATE_CONNECT)
    { 
        memset(ipStr, 0, IP_STR_LEN);
        int ret = 0;
        ret = GetLocalIP(WLAN_IF, ipStr);
        if (ret != 0)   memset(ipStr, 0, IP_STR_LEN);
        lv_label_set_text(guider_ui.screen_lb_net_ip, ipStr);

        lv_obj_clear_state(guider_ui.screen_cb_is_wifi, LV_STATE_ANY);
        lv_obj_add_state(guider_ui.screen_cb_is_wifi, LV_STATE_CHECKED); 
    }
    else
    {
        lv_label_set_text(guider_ui.screen_lb_net_ip, "--Null--");
        lv_obj_clear_state(guider_ui.screen_cb_is_wifi, LV_STATE_ANY);
        lv_obj_add_state(guider_ui.screen_cb_is_wifi, LV_STATE_DEFAULT);
    }

    /*显示CPU利用率*/
    memset(tempStr, 0, TEMP_STR_LEN);
    sprintf(tempStr, "%.1f%%\nCPU", cpuUsage);
    lv_label_set_text(guider_ui.screen_lb_cpu, tempStr);
    lv_arc_set_value(guider_ui.screen_arc_cpu, (int16_t)cpuUsage);

    /*显示内存利用率*/
    float memUsage = GetMemUsage();

    memset(tempStr, 0, TEMP_STR_LEN);
    sprintf(tempStr, "%.1lf%%\nMem", memUsage);
    lv_label_set_text(guider_ui.screen_lb_mem, tempStr);
    lv_arc_set_value(guider_ui.screen_arc_mem, (int16_t)memUsage);

    /*显示温度*/
    memset(tempStr, 0, TEMP_STR_LEN);
    sprintf(tempStr, "%.2f C", GetCpuTemp());
    lv_label_set_text(guider_ui.screen_lb_temp, tempStr);

    /*显示网速*/
    uint8_t rxUnitLevel = 0;
    uint8_t txUnitLevel = 0;
    while (tx_rates >= 1000)
    {
        tx_rates /= 1000;
        txUnitLevel++;
    }
    while (rx_rates >= 1000)
    {
        rx_rates /= 1000;
        rxUnitLevel++;
    }
    //显示Tx(Upload)
    memset(tempStr, 0, TEMP_STR_LEN);
    sprintf(tempStr, "%.1lf%s",
            tx_rates,
            netSpeedUnit[txUnitLevel]);
    lv_label_set_text(guider_ui.screen_lb_up_speed, tempStr);
    //显示Rx(Download)
    memset(tempStr, 0, TEMP_STR_LEN);
    sprintf(tempStr, "%.1lf%s",
            rx_rates,
            netSpeedUnit[rxUnitLevel]);
    lv_label_set_text(guider_ui.screen_lb_dl_speed, tempStr);

    /*显示磁盘剩余容量*/

    memset(tempStr, 0, TEMP_STR_LEN);
    float total_gb = GetTotalDiskGB();
    float used_gb = GetUsedDiskGB();
    sprintf(tempStr, "%.1f/%.1fG", used_gb, total_gb);
    lv_label_set_text(guider_ui.screen_lb_disk, tempStr);
    lv_bar_set_value(guider_ui.screen_bar_disk, (int)((used_gb / total_gb) * 100), LV_ANIM_OFF);

    /*显示时间*/
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    sprintf(tempStr, "%02d:%02d", localTime->tm_hour, localTime->tm_min);
    lv_label_set_text(guider_ui.screen_lb_clk, tempStr);
}

void Timer_Init()
{
    struct sigaction sa;
    struct itimerval timer;

    // 设置定时器信号处理函数
    sa.sa_handler = Timer_Handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGALRM, &sa, NULL);

    // 设置定时器的时间间隔
    timer.it_value.tv_sec = 0;          // 初始延迟为0秒
    timer.it_value.tv_usec = 1000;      // 初始延迟为1毫秒
    timer.it_interval.tv_sec = REFRESH_TIME;       // 重复间隔为0秒
    timer.it_interval.tv_usec = 0;   // 重复间隔为1毫秒

    // 启动定时器
    setitimer(ITIMER_REAL, &timer, NULL);
}

void Timer_Handler()
{
    UpdateFlag = 1;
    lv_tick_inc(REFRESH_TIME * 1000);
    //printf("Timer!\n");
}
