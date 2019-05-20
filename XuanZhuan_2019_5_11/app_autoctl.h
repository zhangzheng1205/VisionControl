#ifndef _app_autoctl_h_
#define _app_autoctl_h_

#include <Qthread>
#include "stdint.h"
#include "iot_pkg.h"
#include "get_average.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "gbase.h"

short get_ADCVALUE(float);
float get_TEMP(short);
float get_TEMP_revise(short);
#define BULen 100                    // Sum length of Ki for PID

struct GInitSetting{
	unsigned short gDeviceID;
	unsigned short gLoginID;
	short reftem[2];
	unsigned char key[8];
	unsigned short dac[4];
	char essid[32];
	char password[32];
};

extern struct GInitSetting gSetting;

struct SenserPkg{                     //app.h  ARM与PC数据交互格式；修改为从串口doPKG()数据输入!!!
    unsigned char     id;
    unsigned char     version;
    short   tem[2];
    short   sensor_tem[2];//新加的
    short   pre[2];
    short   cur;
    unsigned short   motor_speed;
    short   shidu;
    short   wendu;
};

// 传感器全局变量
extern struct SenserPkg sPkg;

struct SET_temppkg{             //app.h   PC预设传入ARM的温控值；（ave,）;此处修改为PC界面传入!!!void MainWindow::onPBSetTEM
		struct ptSettemReq settem;	
        // 热管部分
        int32_t Reguan_MaxErr[3];
        int32_t Reguan_Max[3];
        int32_t Reguan_Min[3];
        // 机油部分
        int32_t oil_MaxErr;
        int32_t oil_Max;
        int32_t oil_Min;

        float integral;
        float oldkp,oldki,oldkd;   //电机启动时，PID参数可能会改，这三个oldk是记录旧参数，电机停止后恢复旧参数；
	    float kp[4],ki[4],kd[4];
        float jiu_kp,jiu_ki,jiu_kd;
        float temp_oil_setting[2]; //从过程控制获取温度void PrEvt::erjiban_process()/ void PrEvt::jiujing_process();摄氏度;直接传给温控用的refvalue[]
        float StopPidTemperature;   //51为温度PID温控门限，高于该值，不工作；
        float temp_oil_current; //实时测试温度来自于   GBase::doPKG in gbase.cpp， sPkg.tem[REF_ERJIBAN]，sPkg.tem[REF_JIUJING]
//        bool erjibanqingxiflag;  //二极板是否为清洗过程，控温粗控
		bool dirTempCtrl; //是否为直接温控模式；

		//电机旋转时，PID调整系数
		float DjKp,DjKi,DjKd;
		
};

extern struct SET_temppkg debugPIDsetting;     //change name  debugPIDsetting.settem.

struct SumPIDStru{              //app.h       //PID i部分累计误差的统计
	short BLen;                 //PID i部分累计误差的统计长度
	short sum;                  //累计误差值
	short sumi[BULen];          //统计buff长度对应的各个值
	short i;                    // buff中第几个值
};
//extern struct SumPIDStru SumPID;

struct autoCTL_Cache{                  
    int32_t	ctl_value;  //温控输出实际控制值
	// -----------------
	int32_t	e_val;      //目标温度 - 实际温度偏差值(采样温度，非摄氏度）
	int32_t	PID_u_val;  //PID 调节三变量变量和的待定值，防止超调可修正
	// PID
	struct SumPIDStru iPart_SumPID;
    int32_t sumErr,lastErr; //累计偏差，最近偏差，上一次偏差
	float Kp,Ki,Kd;
    float integral;
    int max,min,maxerror;

    #define ECOUNT	12
	int32_t	k;
    int32_t e[ECOUNT];   //用于存储连续ECOUNT个与目标温度的偏差值，判断温度是升or降；
	int dir;   //-1正降温，+1正升温
	short ave;
};

extern struct autoCTL_Cache Oil;
extern struct autoCTL_Cache Oil2;
extern int32_t refValue[3];
extern int jiujing_last_out_ctl;
extern int reguan_last_out_ctl;
extern float motor_jiujing_ctl;
extern bool is_start_heat;
extern bool isjiujingPID;

extern int ctlFlag[2];

#define REF_REGUAN	0    //温控端口0
#define REF_JIUJING	1    //温控端口1

class PidCtrl : public QThread                
{
   Q_OBJECT
public:
    explicit PidCtrl(QObject *parent = 0);
    ~PidCtrl();
    virtual void run();
    void SetPara(struct autoCTL_Cache *oilsamp, int n);
    int PID_Oil(struct autoCTL_Cache *out);
    int PID_Reguan(struct autoCTL_Cache *out);

signals:
	void logPidCtrl_xw(int);
	void logProcess(QString);
	void logAutoCtrl(QString);
    void logAutoCtrljiujing(QString);
	
public slots:
    void autoCTLTask(struct autoCTL_Cache *Oil, int k);

private:
    bool isGoing;
    struct autoCTL_Cache *oilsampling;
    int num;
		
};

extern struct PidCtrl m_PidCtrl;
extern struct PidCtrl m_PidCtrl2;

#endif
