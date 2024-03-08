#if !defined(_USER_CFG_H_)
#define _USER_CFG_H_

/*无线网卡文件名*/
#define WLAN_IF         "wlan0"
/*有线网卡文件名*/
#define ETH_IF          "eth0"
/*刷新时间(s)*/
#define REFRESH_TIME    1

#define WIRELESS    "/sys/class/net/"WLAN_IF"/operstate"
#define ETHERNET    "/sys/class/net/"ETH_IF"/operstate"

#endif // _USER_CFG_H_
