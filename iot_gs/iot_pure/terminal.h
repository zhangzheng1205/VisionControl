#ifndef TERMINAL_H
#define TERMINAL_H

#include <QObject>
#include "win_qextserialport.h"
#include <QSerialPortInfo>
#include "iot_pkg.h"
#include <QDateTime>
#include <QList>

#define REF_REGUAN 0
#define REF_JIUJING 1

#define ENVIRONMENT_TEMP 25.0   //环境温度设置为25
#define INITIAL_PRESSURE 60.0
//#define COLD_POWER 500.0        //制冷功率500w
#define _C 2000               //机油比热容单位 j/(kg*C)
#define WEIGHT_a 0.2            //机油质量，单位是kg
#define WEIGHT_p 0.2           //热管等效质量，单位是kg
#define reaction_power 500

extern int KE[];
extern float DA[];
extern float TE[];
extern bool isrelated;
extern float __Rs;

class terminal : public QThread
{
    Q_OBJECT
public:
    explicit terminal(QObject *parent = 0);
    ~terminal();
    QByteArray Buffer;
    Win_QextSerialPort gSerial;
    int gDeviceID,gLoginID,gMatchID;
    float gRefTem[2];

    int flag_a;                     //用于初始化机油,首次运行flag==0
    int flag_p[2];                  //用于初始化热管,首次运行flag==0
    // Add
    int flag_r;                     //用于初始化热管,首次运行flag == 0
    // Add
    int r_switch;                   //用于控制热管工作开关，1 = on; 0 = off
    float oil_temp;                 //机油温度:初始默认为环境温度
    float oil2_temp;                 //热管温度：初始 同上
    float oil_pre;
    float oil2_pre;
    float heat_power[2];               //酒精的制热模块功率:初始为0
    float oil_power;                //油样功率
    float powerJ;                   //热管功率
    float volJ,volE;                //控制包中DAC的值转换得到的电压值

    QDateTime startTime[2],startTime_p[2];
    bool flag_enabled[2];
    float enpower[2];
    float m[2];     //机油质量，热管等效质量
    float ratio;                    //时间常数，调试用(改变速度)


    float dianjispeed;
    float e_wendu;

    int id;
    QString username;
    QString password;

    bool openSerial(QString com);
    bool closeSerial();

    virtual void run();
    void stop(){isGoing = false;}

signals:
    void recvOnePkg(QByteArray pkg);
    void logd(QString);
    void logTX1(QString);
    void logRX1(QString);

public slots:
    void onRecvData();
    void doPKG(QByteArray pkg);
    void resCTL(unsigned short);
    void resSampling(float,float,float,float);
    float env_influence_oil(float);
    float get_oil_temp(float, int);
    float get_pressure(float, float, int);
    void resDebug();
private:
    bool isGoing,isRecv;
    QList<struct iotPkg> mPkgList;
};

#endif // TERMINAL_H
