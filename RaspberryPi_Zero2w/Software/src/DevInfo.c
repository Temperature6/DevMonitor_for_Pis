#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/statvfs.h>
#include "DevInfo.h"

#define TEMP_FILE_PATH  "/sys/class/thermal/thermal_zone0/temp"
#define MAX_SIZE        32

float cal_cpuoccupy(CPU_OCCUPY *o,CPU_OCCUPY *n)
{
    unsigned long od, nd;
    unsigned long id, sd;
    float cpu_use = 0;
    od = (unsigned long)(o->user + o->nice + o->system + o->idle);  //第一次(用户+优先级+系统+空闲)的时间再赋给od
    nd = (unsigned long)(n->user + n->nice + n->system + n->idle);  //第二次（用户+优先级+系统+空闲）的时间再赋给nd

    id = (unsigned long)(n->user - o->user); //用户第一次和第二次的时间之差再赋给id
    sd = (unsigned long)(n->system - o->system); //系统第一次和第二次的时间之差再赋给sd
    if((nd-od) != 0)
        cpu_use = ((sd+id)*100.0)/(nd-od); //((用户+系统)乘100)除(第一次和第二次的时间差)再赋给g_cpu_used
    else 
        cpu_use = 0;
    return cpu_use;
}

void get_cpuoccupy (CPU_OCCUPY *cpust)  //对无类型get函数含有一个形参结构体类弄的指针o
{
    FILE *fd;
    char buff[256] = "";
    CPU_OCCUPY *cpu_occupy = NULL;
    cpu_occupy = cpust;

    fd = fopen("/proc/stat","r");
    if (fd != NULL)
    {
        fgets(buff,sizeof(buff),fd);
        sscanf(buff,"%s %u %u %u %u",
                cpu_occupy->name,
                &cpu_occupy->user,
                &cpu_occupy->nice,
                &cpu_occupy->system,
                &cpu_occupy->idle);
        fclose(fd);
    }
}

float GetCpuUsage()
{
    CPU_OCCUPY cpu_stat1;
    CPU_OCCUPY cpu_stat2;
    float cpu;
    //第一次获取cpu使用情况
    get_cpuoccupy((CPU_OCCUPY *)&cpu_stat1);
    sleep(1);
    //第二次获取cpu使用情况
    get_cpuoccupy((CPU_OCCUPY *)&cpu_stat2);
    //计算cpu使用率
    cpu = cal_cpuoccupy((CPU_OCCUPY *)&cpu_stat1,(CPU_OCCUPY *)&cpu_stat2);
    return cpu;
}

unsigned long GetMemTotal()
{
    /*Byte*/
    struct sysinfo s_info;

    if(sysinfo(&s_info) == 0)
    {
        return s_info.totalram;
    }
    else
    {
        return -1;
    }
}

unsigned long GetMemFree()
{
    struct sysinfo s_info;
    if(sysinfo(&s_info) == 0)
    {
        return s_info.freeram;
    }
    else
    {
        return -1;
    }
}

float GetMemUsage()
{
    FILE *fp;  
    long total_memory, free_memory, buffers, cached;  
    char buffer[256];  
  
    // 打开 /proc/meminfo 文件  
    fp = fopen("/proc/meminfo", "r");  
    if (fp == NULL) {  
        perror("Error opening /proc/meminfo");  
        return 1;  
    }  
  
    // 读取 total 内存  
    while (fgets(buffer, sizeof(buffer), fp)) {  
        if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {  
            break;  
        }  
    }  
  
    // 读取 free 内存  
    while (fgets(buffer, sizeof(buffer), fp)) {  
        if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {  
            break;  
        }  
    }  
  
    // 读取 buffers 和 cached 内存  
    while (fgets(buffer, sizeof(buffer), fp)) {  
        if (sscanf(buffer, "Buffers: %ld kB", &buffers) == 1) {  
            break;  
        }  
    }  
    while (fgets(buffer, sizeof(buffer), fp)) {  
        if (sscanf(buffer, "Cached: %ld kB", &cached) == 1) {  
            break;  
        }  
    }  
  
    // 关闭文件  
    fclose(fp);  
  
    // 计算已使用的内存  
    long used_memory = total_memory - free_memory - buffers - cached;  
  
    // 计算内存使用率  
    double memory_usage = (double)used_memory / total_memory * 100;  
  
    // 输出内存使用率  
    return memory_usage;
}

float GetCpuTemp()
{   
    FILE* fp;
    char buf[MAX_SIZE] = "";
    double tempVal = 0.0;

    fp = fopen(TEMP_FILE_PATH, "r");
    if (fp == NULL)
    {
        printf("Fail to Read Temp...\n");
    }
    else
    {
        fread(buf, 1, MAX_SIZE, fp);
        tempVal = atof(buf) / 1000;
        fclose(fp);
    }
    
    return tempVal;
}

float GetUsedDiskGB()
{
    struct statvfs diskInfo;
    unsigned long long blockSize = 0, totalSize = 0, freeSize = 0, usedSize = 0;
    
    if (statvfs("/", &diskInfo) == 0) {
        blockSize = diskInfo.f_frsize;
        totalSize = blockSize * diskInfo.f_blocks / (1024*1024*1024); // 总大小，单位GB
        freeSize = blockSize * diskInfo.f_bfree / (1024*1024*1024); // 可用大小，单位GB
        usedSize = totalSize - freeSize; // 已使用大小，单位GB
    } else {
        printf("获取磁盘信息失败\n");
    }
    return usedSize;
}

float GetTotalDiskGB()
{
    struct statvfs diskInfo;
    unsigned long long blockSize = 0, totalSize = 0;
    
    if (statvfs("/", &diskInfo) == 0) {
        blockSize = diskInfo.f_frsize;
        totalSize = blockSize * diskInfo.f_blocks / (1024*1024*1024); // 总大小，单位GB
    } else {
        printf("获取磁盘信息失败\n");
    }
    return totalSize;
}
