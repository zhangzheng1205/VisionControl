#include "terminal.h"
#include <math.h>
#include <QDebug>

//#define __Rs 270//100.3                // 5~6脚之间的Rs电阻，电路图中是261R，值对不上；调试时有更改，以实际测量为准!!!   温度变化范围100度，计算出Rs；式（2-4）或者datasheetp.9
#define __R0 80.6                           //XTR101 in-脚对应的R4;温度下线，计算出约-50度~+50度；
//#define __Kf (4096.0 * (40.0/__Rs + 0.016)) //参阅XTR101datasheet，论文式(2-2)；(sample+32768)/65536=(40/Rs+0.016)(Rt-R0)/16; R0=R4 ；等式右侧是电流变化量0~16mA/16mA,左侧是对应的比例输出
#define __Ka (-5.775 * pow(10,-7))   //论文式（2-1）系数B
#define __Kb (3.9083 * pow(10,-3))   //论文式（2-1）系数A
#define __Rp 0.1                  //计算热管对油样传热的等效电阻

bool isrelated=false;
float __Rs=270;
short get_SAMP(float temp)
{
    float __Kf = (4096.0 * (40.0/__Rs + 0.016));
    int samp = __Kf * (100.0 * (__Ka * temp * temp + __Kb * temp + 1.0) - __R0) - 32768;
    return samp;
}

// 计算等效热功率
// 输入 电压控制值（835-2700）
// 输出 等效热功率
short get_power(float v)
{
    //实际作用电压（1-4v）
    float vv = 5.0 * v / 4095.0 - 1.0;
    //等效热传递功率 (v-1)^2 / __Rp
    return pow(vv,2) / __Rp;
}

terminal::terminal(QObject *parent) : QThread(parent)
{
    connect(&gSerial,SIGNAL(readyRead()),this,SLOT(onRecvData()));
    connect(this,SIGNAL(recvOnePkg(QByteArray)),this,SLOT(doPKG(QByteArray)));
    isGoing = isRecv = false;
}

terminal::~terminal()
{
    isGoing = false;
    disconnect(&gSerial,SIGNAL(readyRead()),this,SLOT(onRecvData()));
    disconnect(this,SIGNAL(recvOnePkg(QByteArray)),this,SLOT(doPKG(QByteArray)));
    if(gSerial.isOpen()){
        gSerial.close();
    }
}

bool terminal::openSerial(QString com)
{
    if(gSerial.isOpen()){
        gSerial.close();
    }
    gSerial.setPortName(com);
    gSerial.setQueryMode(QextSerialBase::EventDriven);
    if(!gSerial.open(QIODevice::ReadWrite))
        return false;
    gSerial.setDataBits(DATA_8);
    gSerial.setFlowControl(FLOW_OFF);
    gSerial.setStopBits(STOP_1);
    gSerial.setParity(PAR_NONE);
    gSerial.setBaudRate(BAUD115200);
    gSerial.setTimeout(1000);
    return true;
}
bool terminal::closeSerial()
{
    if(gSerial.isOpen()){
        gSerial.close();
        return true;
    }
    return false;
}

void terminal::onRecvData()
{
    Buffer  += gSerial.readAll();
    struct iotHeader *header = (struct iotHeader *)Buffer.data();
    unsigned int pkg_len = Buffer.length();
    // 先判断前两个字节是不是头标志符 IOTPKG_FLAG
    // 如果flag 不为 IOTPKG_FLAG 则删除一个字节
    while(pkg_len >= 2 && header->flag != IOTPKG_FLAG){
        Buffer.remove(0,1);
        header = (struct iotHeader *)Buffer.data();
        pkg_len = Buffer.length();
    }
    // 判断数据包是否接收完全
    if(pkg_len >= sizeof(struct iotHeader) && header->len <= pkg_len){
        QByteArray pkg((char *)header,header->len);
        Buffer.remove(0,header->len);
        emit recvOnePkg(pkg);
    }
}
int KE[8]={0};
float DA[8]={0};
float TE[8]={160,150};
void terminal::doPKG(QByteArray pkg)
{
    struct iotHeader *h = (struct iotHeader *)pkg.data();
    isRecv = true;
    switch(h->type){
    case PT_SAMPLING_REQ:{
        oil_temp = get_oil_temp(oil_temp,0);//在这两个函数里面控制，没有操作时温度自动波动到室温
        oil2_temp = get_oil_temp(oil2_temp,1);
        oil_pre = get_pressure(oil_temp,oil_pre,0);
        oil2_pre = get_pressure(oil2_temp,oil2_pre,1);
        resSampling(oil_temp, oil2_temp ,oil_pre ,oil2_pre);

    }break;
    case PT_CONTROL_REQ:{
        QString stype;
        struct ptControlReq *r = (struct ptControlReq *)(h+1);
        unsigned short result;
        gDeviceID = r->matchid;
        switch(r->type){
        case CTL_SET_KEY:
            KE[r->channel]=r->value;
            // Add
            if(QString::number(r->channel) == "1")
            {
                //r_switch=1;//用于控制热管开关，1 = on
                if(r->value == 20) r_switch = 1;
                if(r->value == 0)  r_switch = 0;
            }
            stype = "KEY";
            break;
        case CTL_SET_DAC:
            DA[r->channel]=r->value;
            stype = "DAC";

            if(QString::number(r->channel) == "0")
            {
                if(r->value < 819) powerJ = 0;
                else
                {
                    //数字值value转为电压值volJ
                    volJ = r->value * 5.0 / 4095.0;
                    //电压值volJ(1-5v)对应为功率powerJ(0-1000w)
                    powerJ = 62.5 * (volJ - 1) * (volJ - 1);
                }
            }
            if(QString::number(r->channel) == "1")
            {
                if(r->value < 819) powerJ = 0;
                else
                {
                    //数字值value转为电压值volJ
                    volE = r->value * 5.0 / 4095.0;
                    //电压值volJ(1-5v)对应为功率pla_power(0-50w)
                    powerJ = 62.5 * (volE - 1) * (volE - 1);
                }
            }
            if(QString::number(r->channel) == "2")////电热丝 与DAC0差不多
            {
                if(r->value < 819) powerJ = 0;
                else
                {
                    //数字值value转为电压值volJ
                    volE = r->value * 5.0 / 4095.0;
                    //电压值volJ(1-5v)对应为功率pla_power(0-1600w)
//                    pla_power = 100 * (volE - 1) * (volE - 1);
                    powerJ = 62.5 * (volE - 1) * (volE - 1);
                }
            }
            result = CTL_SUCC;
            break;
        case CTL_SET_TEMREF:
            TE[r->channel]=r->value/100.0 - 50;
            //暂不考虑
            stype = "TEMREF";
            break;
        case CTL_REBOOT:
            //暂不考虑
            stype = "REBOOT";
            break;
        default:break;
        }
        resCTL(result);

        emit logTX1(tr("收到 == 控制指令: ") + stype + " 通道：" + QString::number(r->channel) + " 数值= " + QString::number(r->value));
    }break;
    case PT_SETWIFI_REQ:{
        //暂不考虑
    }break;
    case PT_DEBUG_REQ:{
        resDebug();
    }break;
    default:break;
    }
}

void terminal::resDebug()
{
    struct iotPkg pkg;
    struct iotHeader *h = &pkg.iHeader;
    struct ptDebugRes *res = & pkg.iPkg.resDebug;
    h->flag = IOTPKG_FLAG;
    h->version = IOTPKG_VERSION;
    h->type = PT_DEBUG_RES;
    h->len = sizeof(struct iotHeader) + sizeof(struct ptDebugRes);
    h->deviceid = gDeviceID;
    h->loginid = gDeviceID;
    h->crc = 0x0000;
    strcpy(res->essid,username.toLatin1().data());
    strcpy(res->password,password.toLatin1().data());//char
    res->deviceid=id;
    mPkgList.push_back(pkg);
}

void terminal::resSampling(float samp1, float samp2, float samp3, float samp4)
{
    struct iotPkg pkg;
    struct iotHeader *h = &pkg.iHeader;
    struct ptSamplingRes *res = & pkg.iPkg.resSampling;

    samp1 = get_SAMP(samp1);
    samp2 = get_SAMP(samp2);

    h->flag = IOTPKG_FLAG;
    h->version = IOTPKG_VERSION;
    h->type = PT_SAMPLING_RES;
    h->len = sizeof(struct iotHeader) + sizeof(struct ptSamplingRes);
    h->deviceid = gDeviceID;
    h->loginid = gDeviceID;
    h->crc = 0x0000;

    res->channel = 0x00;
    res->res = 0x00;
    res->tem1 = samp1;
    res->tem2 = samp2;
    res->pre1 = samp3;
    res->pre2 = samp4;
    res->cur = 0;
    res->motorspeed = 0;
    res->motorspeed = dianjispeed;
    res->env_h = 0;
    res->env_t = 0;
    mPkgList.push_back(pkg);
}


void terminal::resCTL(unsigned short result)
{
    struct iotPkg pkg;
    struct iotHeader *h = &pkg.iHeader;
    struct ptControlRes *res = & pkg.iPkg.resControl;

    h->flag = IOTPKG_FLAG;
    h->version = IOTPKG_VERSION;
    h->type = PT_CONTROL_RES;
    h->len = sizeof(struct iotHeader) + sizeof(struct ptControlRes);
    h->deviceid = gDeviceID;
    h->loginid = gDeviceID;
    h->crc = 0x0000;

    res->matchid = gDeviceID;

    mPkgList.push_back(pkg);
    switch(result)
    {
    case CTL_SUCC:{
        emit logRX1(tr("发出 == 控制反馈: MATCHID=") +QString::number(res->matchid) + " SUCCESS");
    }break;
    case CTL_BUSY:{
        emit logRX1(tr("发出 == 控制反馈: MATCHID=") +QString::number(res->matchid) + " BUSY");
    }break;
    case CTL_FAIL:{
        emit logRX1(tr("发出 == 控制反馈: MATCHID=") +QString::number(res->matchid) + " FAIL");
    }break;
    default:break;
    }
}

void terminal::run()
{
    isGoing = true;
    mPkgList.clear();
    int i = 0;
    while(isGoing){
        while(mPkgList.isEmpty() && isGoing){
            Sleep(100);
        }
        if(isGoing){
            struct iotPkg &pkg = mPkgList.first();
            isRecv = false;
            gSerial.write((char *)&pkg,pkg.iHeader.len);
            mPkgList.pop_front();
            for(i=0; i<100 && !isRecv && isGoing; i++) Sleep(100);
            if(i>=100)  emit logd("指令发送超时！");
        }
    }
    isGoing = false;
}

// 将环境对机油温度的影响等效为功率，环境比机油温度高时为正，比机油温度低时为负

// 输入 机油温度
// 输出 等效功率
float terminal::env_influence_oil(float temp)
{
    if(temp > 145)   return  480 - (temp - 145) * 10;    //反应放热，必须用外部散热将其温度降下来
    else if(temp > 25) return 4.0 * temp - 100;
    else return 0.0;
}

// 计算机油温度
// 输入 新的加热功率
// 输出 此刻机油的温度
float terminal::get_oil_temp(float oil_samp, int n)
{
    if(flag_a == 0){//初始化加热功率、计时  打开串口时初始化一次
        flag_a = 1;
        startTime[0] = QDateTime::currentDateTime();
        startTime[1]= QDateTime::currentDateTime();
        heat_power[0] = powerJ;
        heat_power[1] = powerJ;
        return oil_samp;
    }
    // 计算加热时间
    QDateTime stopTime = QDateTime::currentDateTime();
    int elapsed =(stopTime.toTime_t()-startTime[n].toTime_t())*ratio;
    // 上一段加热时间内 机油获取的热量
    float Q;
    if(flag_enabled[n] == 0)//自动？？？
        Q = elapsed * (heat_power[n] - env_influence_oil(oil_samp));//加热 +环境热交换 +反应放热
    else//手动？？？给一个功率
        Q = elapsed * (heat_power[n] - enpower[n]);//加热0W +手动 +反应放热
    float delta_T = Q / (_C * m[n]);
    oil_samp = oil_samp + delta_T;
    // 更新加热功率、计时
    heat_power[n] = powerJ;
    startTime[n] = QDateTime::currentDateTime();
    return oil_samp;
}

float terminal::get_pressure(float oil_samp,float pressure, int n)
{
    if(oil_samp < 149.5)
    {
        return pressure;
    }
    else if(oil_samp >=149.5 && flag_p[n] == 0)
    {
        flag_p[n] = 1;
        startTime_p[n] = QDateTime::currentDateTime();
    }
    QDateTime stopTime = QDateTime::currentDateTime();
    int t = (stopTime.toTime_t()-startTime_p[n].toTime_t())*ratio;
    if ( t>=0 && t<=28)
    {
        pressure = -0.0109 * pow(t,4) + 0.8265 * pow(t,3) - 22.644 * pow(t,2) + 267.86 * t +60;
    }
    else if ( t>28 && t<=220)
    {
        pressure = -0.0387 * t + 1252;
    }
    else if ( t>220 && t<= 270)
    {
        pressure = -0.3476 * pow(t,2) + 149.62 * t - 14845;
    }
    else
    {
        pressure = -0.5 * (t-271) + 64;
    }
    return pressure;
}
