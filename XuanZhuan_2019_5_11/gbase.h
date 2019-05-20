#ifndef GBASE_H
#define GBASE_H

#include <QObject>
#include "win_qextserialport.h"
#include <QSerialPortInfo>
#include "iot_pkg.h"
#include <QList>
#include <QTime>
#include <QApplication>
#include <QTableWidget>
#include <ActiveQt/QAxObject>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QtNetwork>
#include <QSqlQuery>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <math.h>

#include "app_autoctl.h"
#include "yieldstress.h"

struct GSimplingData{
    float tem1,tem2;   //热管温度  油样温度
    float pre1,pre2;    //压强
    float envh,envt;
    float DAC0,DAC1;    //热管控制电压，机油控制电压
    float ls_tem1;
};

struct item{
    bool empty;
    double viscosity;     //粘度
    double rev;           //转速
};

struct table{
    int row,column;
    struct item res_data[10][8];
};

struct time{
    int eventflag;    //0：电机运转结束，热管不工作，“停止”按钮触发； 1：“旋转氧弹”实验按钮触发；
    int reguanflag[2];     // 0 热管没工作 1热管工作
    int oil_tempflag;   //机油温度标志
    int tiaoshiflag;  //设置窗口中调试标识，开始调试与调试中，区别于标油样油
    QDateTime ruanjian_time1,ruanjian_time2;  //制冷最大时长, 测粘度时长，清洗时长，静置时长使用期限
    int deviceid_flag;//0表示不匹配，1表示匹配
};

struct tubiaojiankong {
    int oiljiare; //1表示工作 0不工作
    int reguan;     // 0不工作 1加热
};

struct SharedVariables         //发送控制量之前的表示的参数，如果发送控制量之后，则归 debugPIDsetting；
{   //以下变量是需要交互的共享变量，主要从表格中得到酒精与二级板相应的预设温度；
	bool stdoil_isChecked;    //ui->stdoil->isChecked();  ProEvt 线程无法通过ui获取这两个选项；
	bool testoil_isChecked;   //ui->testoil->isChecked();
    bool stdoil2_isChecked;    //ui->stdoil->isChecked();  ProEvt 线程无法通过ui获取这两个选项；
    bool testoil2_isChecked;   //ui->testoil->isChecked();
    bool stopbutton_isChecked;   //目前没实zishiyong
    short para_tem_std0;    //热管温度
    short para_tem_std1;    //机油温度
    short para_tem_test0;          //eijiban=para_tem[0]->pComboBox->currentText().section(' ',0,0);   //热管温度
    short para_tem_test1;          //jiujing=para_tem[1]->pComboBox->currentText().section(' ',0,0);   //机油温度
    short para_BJ_dianjibianhao;    //步进电机横坐标
    short para_BJ_ori;            //步进电机纵坐标
    short para_BJ_RESET;        //步进电机复位 0表示默认 1表示复位
};

extern struct SharedVariables m_ShVar;
extern struct time timers;
extern struct tubiaojiankong tubiaojiankongs;
extern struct table std_data;
extern float oiltem_real;
extern float oil2tem_real;
extern float zhuansu;
extern float qingxiwendu;
extern float dianjiwendu;
extern float col;
extern float niandu1[10][8];
extern float xishu[10][8];
extern int tem_flag_erjiban;
extern int tem_flag_jiujing;
extern QString essid_str;
extern QString password_str;
extern QString deviceid_str;
extern int last20times;
extern float sum_reguan_temperature;
extern float ave_reguan_temperature;
extern bool isbehind81;
extern double xiuding[10];
extern float debug_para[30];
extern float D_ac[4];
extern bool isstart;
extern int nihe_num;
extern float ctl_value;
extern int last_key2;
extern int last_key1;
extern int key2_jishu;
extern int key1_jishu;
extern int last_tem0;
extern int last_tem1;
extern int last_tem2;
extern int tem0_jishu;
extern int tem1_jishu;
extern int tem2_jishu;
extern int last_Dac0;
extern int last_Dac1;
extern int last_Dac2;
extern int Dac0_jishu;
extern int Dac1_jishu;
extern int Dac2_jishu;
extern int reqdebug_jishu;
extern bool unlinked;
extern int key0_jishu,key1_jishu,key2_jishu,key3_jishu;
extern int Dac0_jishu,Dac1_jishu;


#define REF_REGUAN 0
#define REF_JIUJING 1

class GBase : public QThread
{
    Q_OBJECT
public:
    explicit GBase(QObject *parent = 0);
    ~GBase();
    int gDeviceID,gLoginID,gMatchID;
    int messageNo;
    float gRefTem[8];
    QByteArray gRXBuffer;
    Win_QextSerialPort gSerial;
    QUdpSocket *udpSocket;

    GET_AVERAGE get_ave;
    struct ave_struct *lastsquare_struct1;
    struct ave_struct *lastsquare_struct2;

    bool openSerial(QString com);
    bool closeSerial();
    void sendData(char *data,qint64 len);
    void reqSampling();
    void reqDebug();
    virtual void run();
    void stop();

    // 编码盘转动结果记录
    void encoderDiskTest(int, int);

signals:
    void recvOnePkg(QByteArray pkg);
    void updateSampling(struct GSimplingData res);
    void logd(QString);
    void logTX(QString);
    void logRX(QString);

    // 通知mainwindow 修改ui中转动圈数、时间
    void setUIAngleAndTime(int angle, int time);

    // 记录结果
    void getResult(bool);
    // 更新UI中启动次数
    void setStartTimesValue(int);

public slots:
    void onRecvData();
    void doPKG(QByteArray pkg);
    void sendCTLPkg(int,int,float);
    //void set_tubiao(int,int,float );
    void reqSetWiFi(QString,QString);
    void reqSettem(struct ptSettemReq st);
    void reqSetBJ_dianji();
    void delay(int);

    // 获取相应脉冲数对应的时间
    void setAngleGetTime(int);
    // 获取转相应时间(秒)对应的脉冲数
    void setTimeGetAngle(int);
    // 获取采样值 脉冲数、时间
//    void setUIAngleAndTime(int*, int*);

private:
    bool isGoing,isRecv;
    QList<struct iotPkg> mPkgList;
};


extern struct GBase m_Base;

#endif // GBASE_H
