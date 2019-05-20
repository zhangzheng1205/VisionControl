#ifndef IOT_PKG_H
#define IOT_PKG_H
// @Author: 陈振威(ieczw@qq.com)
// 修订版本：2017.0410.1720
// 协议版本：0x01
// 协议头以后固定为这样的设计

// A:Add		D:Delete	M:Modify
// [A] iotHeader::<unsigned short>loginid	=ChenZhenWei(2017.4.2)
// [D] iotHeader::<unsigned short>password	=ChenZhenWei(2017.4.2)
// [A] iotHeader::<unsigned short>deviceid	=ChenZhenWei(2017.4.2)
// [M] iotHeader::<unsigned int>crc [to] iotHeader::<unsigned short>crc	=ChenZhenWei(2017.4.2)
// [D] ptControlReq::<short> value          =CaiHaoJie(2019-3-5)
// [A] ptControlReq::<unsigned> zijieduiqi  =CaiHaoJie(2019-3-5)
// [A] ptControlReq::<float> value          =CaiHaoJie(2019-3-5)


#define IOTPKG_FLAG     0xF410
// 后期如果有变更，请修改VERSION
#define IOTPKG_VERSION  0x01
/*
 * 所有通信流程都是由上位机发起REQ
 * 终端收到REQ之后，处理结束后，反馈RES
 * 数据包结构如下：
 * | iotHeader | ptXXXXReq/ptXXXXRes |
 */

// 8 bytes Header
struct iotHeader{
    unsigned short flag;    //包头标志位
    unsigned short len;     //包长度 = sizeof(iotHeader) + sizeof(ptXXXReq(s))
    unsigned char  version; //版本号
    unsigned char  type;    //包类型   PT_XXXXX_REQ(S)
    unsigned short deviceid;//控制密码，默认为设备ID吧
    unsigned short loginid;	// LoginID
    unsigned short crc;
};
#define PT_SYNC_REQ			0xFF
#define PT_SYNC_RES			0xFE
struct ptSyncReq{
    #define SYNC_LOGIN	0x00
    #define SYNC_START	0x01
    #define SYNC_RUN		0x02
    #define SYNC_STOP		0x03
    unsigned char	type;
};
struct ptSyncRes{
    unsigned char type;
    unsigned char h;
    unsigned char m;
    unsigned char s;
};

#define PT_SAMPLING_REQ   0x00
#define PT_SAMPLING_RES   0x01
#define PT_CONTROL_REQ  	0x02
#define PT_CONTROL_RES  	0x03
#define PT_SETWIFI_REQ  	0x04
#define PT_SETWIFI_RES  	0x05
#define PT_SETTEM_REQ       0x06
#define PT_SETTEM_RES       0x07
#define PT_DEBUG_REQ        0x08
#define PT_DEBUG_RES       0x09
#define PT_SETBJ_REQ        0x10
#define PT_SETBJ_RES       0x11
struct ptSamplingReq;
struct ptSamplingRes;
struct ptControlReq;
struct ptControlRes;
struct ptSetWiFiReq;
struct ptSetWiFiRes;
struct ptSettemReq;
struct ptSettemRes;
struct ptDebugReq;
struct ptDebugRes;
struct ptSetBJ_DIANJIReq;
struct ptSetBJ_DIANJIRes;


// 包类型定义
// Package Type 缩写为PT
// 采样包请求
struct ptSamplingReq{
    unsigned char channel;  //请求通道0/1/2
    unsigned char res;  		//保留字段
};

struct ptSamplingRes{
    unsigned char channel;  //请求通道0/1/2
    unsigned char res;  		//保留字段
    short tem1;
    short tem2;
    short pre1;
    short pre2;
    short cur;
    unsigned short motorspeed;
    short env_h;
    short env_t;
};
// 控制包请求

struct ptControlReq{
#define CTL_REBOOT  		0x00

#define CTL_SET_KEY     	0x01
#define CTL_SET_DAC     	0x02
#define CTL_SET_TEMREF  	0x03
#define CTL_SET_PARA        0x04

#define CTL_START_LEVEL0	0x10
#define CTL_START_LEVEL1	0x11
#define CTL_START_LEVEL2	0x12
#define CTL_START_LEVEL3	0x13
#define CTL_START_LEVEL4	0x14
#define CTL_START_LEVEL5	0x15
#define CTL_START_LEVEL6	0x16
#define CTL_START_LEVEL7	0x17
#define CTL_START_LEVEL8	0x18
#define CTL_START_LEVEL9	0x19
    unsigned char   type;
    unsigned char   channel;
    //  温度值有short型传过来 只保留了整数部分
    short  value;
    unsigned short  matchid;    //指令匹配id
};
struct ptControlRes{
    unsigned short  matchid;    //指令匹配id
#define CTL_SUCC    0
#define CTL_BUSY    1
#define CTL_FAIL    2
    unsigned short  result;
};
// WIFI配置请求

struct ptSetWiFiReq{
    // AP名和密码
    char essid[32];
    char password[32];
};
struct ptSetWiFiRes{
#define SET_WIFI_SUCC   0
#define SET_WIFI_FAIL   1
    unsigned char result;
};

struct ptSettemReq{
        short temp_diff_3;
        short temp_diff_5;
        short temp_diff_10;
        short temp_diff_15;
        short temp_diff_20;
        short temp_diff_25;
        short std_1;
        short std_2;   //偏差25度以上时，二级控制值
        short pidbias;       //std_PID;    //PID bias,控制超调量边界
        short BoolPIDcontrol;
        float kp,ki,kd;
        float xishu;
        float k_p[3],k_i[3],k_d[3];//新增
};

struct ptSettemRes{
#define SET_TEM_SUCC   0
#define SET_TEM_FAIL   1
    unsigned char result;
};

struct ptDebugReq{
    unsigned char channel;  //请求通道0/1/2
    unsigned char res;
};

struct ptDebugRes{
    short dir;
    short e_val;
    short ref_erjiban;
    short spkg_erjiban;
    short ctl_value;
    short temp_diff_3,temp_diff_5,temp_diff_10,temp_diff_15,temp_diff_20,temp_diff_25,std_1,std_2,std_PID;
    float Kp,Ki,Kd,Xishu;
    short dir_J,e_val_J;
    short ref_Jiujin,spkg_Jiujin,ctl_value_jiujing;
    short BoolPIDcontrol;
    short ave,PID_u_val;
    short PID_sum,PID_sumi,PID_i;
    short loginid;
    int deviceid;
    char essid[32];
    char password[32];
};

struct ptSetBJ_DIANJIReq{
    short BJ_dianjibianhao;
    short BJ_ori;
    short BJ_quanshu;

};

struct ptSetBJ_DIANJIRes{
#define SET_BJ_SUCC   0
#define SET_BJ_FAIL   1
    unsigned char result;
};

struct iotPkg{
    struct iotHeader iHeader;
    union{
        struct ptSyncReq 		 reqSync;
        struct ptSyncRes		 resSync;
        struct ptSamplingReq reqSampling;
        struct ptSamplingRes resSampling;
        struct ptControlReq  reqControl;
        struct ptControlRes  resControl;
        struct ptSetWiFiReq  reqSetWifi;
        struct ptSetWiFiRes  resSetWifi;
        struct ptSettemReq   reqSettem;
        struct ptSettemRes   resSettem;
        struct ptSetBJ_DIANJIReq reqSetBJ_dianji;
        struct ptSetBJ_DIANJIRes resSetBJ_dianji;
        struct ptDebugReq   reqDebug;
        struct ptDebugRes   resDebug;
    }iPkg;
};
// 包最大长度
#define PKG_MAX_SIZE    sizeof(struct iotPkg)

#endif // IOT_PKG_H
