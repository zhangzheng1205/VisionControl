#include "app_autoctl.h"

QMutex qmutex;
int refValue[3]  = {32769,32769,32769};
bool isstart=false;
int jiujing_last_out_ctl;
int reguan_last_out_ctl;
float motor_jiujing_ctl;//=3200
bool isjiujingPID;
bool is_start_heat;

int ctlFlag[2] = {1,1};


#define REF_JIUJING	1
#define REF_REGUAN  0
#define STDEV_1 250
#define STDEV_2 300

struct autoCTL_Cache Oil,Oil2;
struct SenserPkg sPkg;                //app_adc.c
struct SET_temppkg debugPIDsetting;   //app_conn.c
struct GInitSetting gSetting;

//#define __Rs    100.3
#define __Rs    270
#define __R0    80.6
#define __Kf    (4096.0 * (40.0/__Rs + 0.016))
#define __Ka    (-5.775 * pow(10,-7))
#define __Kb    (3.9083 * pow(10,-3))

short get_ADCVALUE(float t){//将温度转换成AD值
    double r = 100.0 * (1 + __Kb * t + __Ka * t *t);
    return (short)((r - __R0) * __Kf - 32768);
}

float get_TEMP(short samp){//将AD值转换成温度
    double r = (samp + 32768)/__Kf + __R0;
    double c = 1.0 - r/100.0;
    double kk = __Kb * __Kb - 4 * __Ka * c;
    double t = (-__Kb + sqrt(kk))/(2 * __Ka);
    return (float)t;
}

float get_TEMP_revise(short samp){//将AD值转换成修正温度
    double r = (samp + 32768)/__Kf + __R0;
    double c = 1.0 - r/100.0;
    double kk = __Kb * __Kb - 4 * __Ka * c;
    double t = (-__Kb + sqrt(kk))/(2 * __Ka);
    double ceshi_t = (-__Kb + sqrt(kk))/(2 * __Ka);

    if(ceshi_t>=-40 && ceshi_t<-35)      t=t+xiuding[0]+(xiuding[1]-xiuding[0])/5*(ceshi_t+40);//大于等于有问题？？？？
    else if(ceshi_t>=-35 && ceshi_t<-30) t=t+xiuding[1]+(xiuding[2]-xiuding[1])/5*(ceshi_t+35);
    else if(ceshi_t>=-30 && ceshi_t<-25) t=t+xiuding[2]+(xiuding[3]-xiuding[2])/5*(ceshi_t+30);
    else if(ceshi_t>=-25 && ceshi_t<-20) t=t+xiuding[3]+(xiuding[4]-xiuding[3])/5*(ceshi_t+25);
    else if(ceshi_t>=-20 && ceshi_t<-15) t=t+xiuding[4]+(xiuding[5]-xiuding[4])/5*(ceshi_t+20);
    else if(ceshi_t>=-15 && ceshi_t<-10) t=t+xiuding[5]+(xiuding[6]-xiuding[5])/5*(ceshi_t+15);
    else if(ceshi_t>=-10 && ceshi_t<-5)  t=t+xiuding[6]+(xiuding[7]-xiuding[6])/5*(ceshi_t+10);
    else if(ceshi_t>=-5  && ceshi_t<=0)  t=t+xiuding[7]+(xiuding[8]-xiuding[7])/5*(ceshi_t+5);
    else t=t+xiuding[8];

    return (float)t;
}

/*int PidCtrl:: PID_Reguan(struct autoCTL_Cache *out)//改了最多相邻变化400  第一次过冲1.4V  11.17
//PID与否无所谓啊，0最大制冷，4095最大制热，而且目前在达到温度后还在降温。。。
//而且I在下一次实验没有清空
{
    if(!isjiujingPID){
        int32_t vmin=0,vmax=4095;
        if(out->e_val > 0)
            return vmax;
        else
            return vmin;
    }

    //return 3136;//3140 3↑1 3130 2↓2误差差不多不变3135小，3136大
    else{
        jiujing_last_out_ctl=out->ctl_value;//zc11.20

        int vmin=0,vmax=4095;
        if(abs(out->e_val) > 3000)	   {vmin=0; vmax=4095;}
        else if(abs(out->e_val) > 2000){vmin=0; vmax=3800;}
        else if(abs(out->e_val) > 1000){vmin=0; vmax=3500;}
        else if(abs(out->e_val) >  500){vmin=0; vmax=3200;}
        else {vmin=2370; vmax=3170;}
        if(out->dir>0)	//升温   ,参考温度比实际温度高，需要加热
            return (out->e_val<250 ? vmin : vmax);
        else			//降温，（参考温度比实际温度低，是压缩机制冷模式，适当中和制冷量，让温度稳定；制冷量=加热量+外界热量）
            return (out->e_val>-100 ? vmax : vmin);

    }
}*/

//	油样，out->Kp/out->Ki/out->Kd 对应的值，取自于设置界面；热管与二级板切换控制时，积分制要及时清零；需要初始化，初始化kp=1;ki=0.01;kd=0;
int PidCtrl::PID_Oil(struct autoCTL_Cache *out)
{
    int out_maxlimit=3888,out_minlimit=818,MaxErr=3300,index=0;      //加热管最da与最小电压控制值；     // Max/Min标识Ui界面中输入的控制值最da最小值，实际代码中没有没用，out_mXXlimit具有同样功能；MaxErr是开始积分的偏差门限；index表示积分项是否参与输出值计算，如果温差很da，比例部分已经超出输出控制值数字，则不必考虑积分项；
    {
        if (out->PID_u_val>out_maxlimit)
        {
            //20190309 替代上一条，上一条在原程序中，因out->ctl_value后面限幅3888，导致该语句不执行，因为Max=4000；
            emit logAutoCtrl("[Reguan]积分项：控制量过高");
            if (abs(out->e_val)>MaxErr) index=0; //MaxErr = 6670
            else {
                index=1;
                if (out->e_val<0) { 	//积分就只积负误差;实际温度已经高于设定温度，积分值偏da；
                    out->integral+=out->e_val;
                }
            }
        }
        else if (out->ctl_value<out_minlimit)   //如果上一次的控制量已经低于极限范围，说明积分可能已经负饱和
        {
            emit logAutoCtrl("[Reguan]积分项：控制量过低");
            if (abs(out->e_val)>MaxErr) index=0;
            else {
                index=1;
                if (out->e_val>0) { 	//积分就只积正误差
                    out->integral+=out->e_val;
                }
            }
        }
        else {      //如果上一次实际控制值zai输出电压范围之内
            if (abs(out->e_val)>MaxErr) {
                emit logAutoCtrl("[Reguan]积分项：温度偏过大");
                index=0;
            } else {
                emit logAutoCtrl("[Reguan]积分项：可正常积分");
                index=1;
                out->integral+=out->e_val;
            }
        }
        if(out->integral>1.03*out_maxlimit/out->Ki)
        {
            out->integral=1.03*out_maxlimit/out->Ki;
            emit logAutoCtrl("[Reguan]积分偏高，修正为极值1.03倍");
        }
        if(out->integral<out_minlimit/out->Ki)
            out->integral=out_minlimit/out->Ki;

        float err_sub = out->e_val - out->lastErr;
        out->lastErr = out->e_val;
        out->PID_u_val=round(out->Kp*out->e_val+out->Ki*(out->integral)*index+out->Kd*(err_sub));//round 四舍五入函数，保留0位  round(1.1)=1
        out->ctl_value=out->PID_u_val;//直接赋值

        if(out->ctl_value<out_minlimit) out->ctl_value=out_minlimit;  // 限制输出minlimit~maxlimit之间
        if(out->ctl_value>out_maxlimit) out->ctl_value=out_maxlimit;

        //以下辅助显示调试状态过程

        QTime timexx =QTime::currentTime();
        if(timexx.second()*2 % 10 ==0)			//显示下采样，5s
        {
            emit logAutoCtrl("[Reguan]P:"+QString::number(round(out->e_val))+"*Kp:"+QString::number(round((out->Kp)))+"+I:"+QString::number(out->integral)+" *Ki:"+QString::number(out->Ki*index)+"+D:"+QString::number(round((err_sub)))+"*Kd:"+QString::number(out->Kd)+"="+QString::number(out->PID_u_val));
        }
    }
    return out->ctl_value;
}

//自动控制任务
//OS_STK autoCTLTaskSTK[128];
//从外输入参数：sPkg.tem[REF_ERJIBAN]，sPkg.tem[REF_JIUJING]，debugPIDsetting（包含refValue[REF_ERJIBAN]，refValue[REF_JIUJING]）；
//对外输出参数：PC控制端口m_Base.sendCTLPkg(CTL_SET_DAC,0,Erjiban.ctl_value*5/4095); gSetting.dac[REF_ERJIBAN]，gSetting.dac[REF_JIUJING]，ARM控制端口DacOut(REF_JIUJING,Jiujing.ctl_value);
//判断是否为erjibanqingxiflag清洗过程，如果是清洗，则可以设为加热；否则制冷为制冷过程；
void PidCtrl:: autoCTLTask(struct autoCTL_Cache *oilsamp, int n)
{
    int mm = 0;
    int i = 0;
    int AdConvertRange=32768;  //16位正负两部分；-32768~32768
    memset(oilsamp,0x00,sizeof(*oilsamp));
    emit logAutoCtrl(" autoCTLTask start");

    // 初始化数据,refValue[2]  = {32769,32769}，zai可控温度之外，温控不工作；sPkg.tem[1]=r->tem2，从doPkg中得到测量值;
    oilsamp->e_val = refValue[n] - sPkg.tem[n];  //油样      目标温度 - 当前实际测量温度
    for(i=0; i<ECOUNT; i++){
        oilsamp->e[oilsamp->k] = oilsamp->e_val;   //初始化buff，12个都填一样值,
        oilsamp->k ++;oilsamp->k %= ECOUNT;       //k参数负责循环移位的
    }

    // 控制任务正式开始
    oilsamp->Kp = debugPIDsetting.jiu_kp;
    oilsamp->Ki = debugPIDsetting.jiu_ki;
    oilsamp->Kd = debugPIDsetting.jiu_kd;
    oilsamp->dir = -1;

    debugPIDsetting.oil_MaxErr = 6670;
    debugPIDsetting.oil_Max = 3999;
    debugPIDsetting.oil_Min = 0;

    debugPIDsetting.dirTempCtrl=false;

    //油样调节参数初始化
    oilsamp->ctl_value = 0;
    oilsamp->e_val = 0;
    oilsamp->PID_u_val = 0;
    oilsamp->iPart_SumPID.BLen=BULen;oilsamp->iPart_SumPID.i=0;oilsamp->iPart_SumPID.sum=0;
    for(int g=0;g<=oilsamp->iPart_SumPID.BLen-1;g++)oilsamp->iPart_SumPID.sumi[g]=0;
    oilsamp->sumErr=0;oilsamp->lastErr=0;
    for(int g=0;g<=12;g++)oilsamp->e[g]=0;
    oilsamp->dir=-1;

    while(1){

        if (ctlFlag[n]==2 )
        {
            // ctlFlag == 2 热管控温
            if(timers.reguanflag[n] == 0){
                qmutex.lock();
                m_Base.sendCTLPkg(CTL_SET_KEY, 1, 100);
                qmutex.unlock();
                timers.reguanflag[n] = 1;
            }       // 打开热管
              if(isstart){//发包速度小于收包速度，List长度一直累加
                for(i=0; i<5; i++){//酒精温控仅i=0时控制一次，二级板每次都温控；酒精温控比二级板慢5倍
                    // 更新数据
                    refValue[n]= get_ADCVALUE(debugPIDsetting.temp_oil_setting[n]);            //获取油样设定温度

                    //qDebug()<<"二级板目标温度:"+QString::number(debugPIDsetting.temp_erjiban_setting)+"酒精目标温度:"+QString::number(debugPIDsetting.temp_jiujing_setting);

                    // 根据目标温度范围确定选用三组PID参数中的哪一组
                    if(debugPIDsetting.temp_oil_setting[n]<=140){
                        mm=0;
                    }
                    else if(debugPIDsetting.temp_oil_setting[n]>140 &&debugPIDsetting.temp_oil_setting[n]<=145){
                        mm=1;
                    }
                    else{
                        mm=2;
                    }
                    oilsamp->Kp = debugPIDsetting.settem.k_p[mm];     //初始调试，采单PID的模式；后期，此处根据设定温度，选取对应debugPIDsetting.kp[i] 等
                    oilsamp->Ki = debugPIDsetting.settem.k_i[mm];
                    oilsamp->Kd = debugPIDsetting.settem.k_d[mm];
                    //qDebug()<<"ki["<<mm<<"]="<<debugPIDsetting.settem.k_i[mm];
                    oilsamp->maxerror = debugPIDsetting.Reguan_MaxErr[mm];
                    oilsamp->max = debugPIDsetting.Reguan_Max[mm];
                    oilsamp->min = debugPIDsetting.Reguan_Min[mm];
                    //sPkg.tem[],已实时测试温度，来自于   GBase::doPKG in gbase.cpp
                    oilsamp->e_val = refValue[n] - sPkg.tem[n];      //误差值 = 参考值-当前值；酒精参考温度/二级板参考温度
                    oilsamp->e[oilsamp->k] = oilsamp->e_val;                           //误差值序列中的第k次值
                    oilsamp->dir = ((oilsamp->e[oilsamp->k]-oilsamp->e[(oilsamp->k+(ECOUNT>>1))%ECOUNT])>0 ? -1 : 1);   //与前6个采样作比较，OSTimeDly(200)，1秒前，酒精比较慢；-1表示降温，1为升温

                    if(refValue[n] > -1*AdConvertRange && refValue[n] < AdConvertRange){          //二级板控温范围，初始32769，不在范围电平之内，不会进入该循环；
                        oilsamp->ctl_value = PID_Oil(oilsamp);
                        //qDebug()<<"old ctl_value:" + QString::number(Erjiban.ctl_value);
 //                       Oil.ctl_value = (Oil.ctl_value-reguan_last_out_ctl>400) ? (reguan_last_out_ctl+400) :Oil.ctl_value;//zc11.20
                        //qDebug()<<"new ctl_value:" + QString::number(Erjiban.ctl_value)+" timers.erjibanflag:"+QString::number(timers.erjibanflag);
                        if(timers.reguanflag[n]==1){
                            if (oilsamp->ctl_value < 819)
                                tubiaojiankongs.oiljiare = 0;
                            else
                                tubiaojiankongs.oiljiare = 1;
                            qmutex.lock();
                            m_Base.sendCTLPkg(CTL_SET_DAC,0,(float)oilsamp->ctl_value*5.0/4095.0);     // PC端浮点强制转换，（float， 5.0 4095.0 ）
                            qmutex.unlock();
                            reguan_last_out_ctl=oilsamp->ctl_value;
                        }
                        else{
                            tubiaojiankongs.reguan = 0;
                            m_Base.sendCTLPkg(CTL_SET_DAC,0,0.5);
                            reguan_last_out_ctl=(float)0.5*4095.0/5.0;
                        }
                    }
                    oilsamp->k ++;oilsamp->k %= ECOUNT;
                    msleep(1500);    //可调  1000
                }
            }
        }
        else
        {
            // ctlFlag == 1 不进行控温
//            m_Base.sendCTLPkg(CTL_SET_KEY,1,0);
            m_Base.sendCTLPkg(CTL_SET_KEY,1, 0);  //热管停止加热
            m_Base.sendCTLPkg(CTL_SET_DAC,0, 0);
//            m_Base.sendCTLPkg(CTL_SET_DAC, 1, 0);
//            m_Base.sendCTLPkg(CTL_SET_DAC, 2, 0);
            msleep(1000);
        }
    }

    msleep(1000);
}

void PidCtrl::SetPara(struct autoCTL_Cache *oilsamp, int n)
{
    this->oilsampling = oilsamp;
    this->num = n;
}

void PidCtrl::run()//这个线程中调用autoCTLTask
{
    while(isGoing){
        autoCTLTask(oilsampling, num);   //不()陷入循环while（1）
    }
}

PidCtrl::PidCtrl(QObject *parent) : QThread(parent)
{
    isGoing = true;
}

PidCtrl::~PidCtrl()
{
    isGoing = false;
}
