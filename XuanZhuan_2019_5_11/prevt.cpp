#include "prevt.h"
#include"yieldstress.h"

QMutex myMutex;
float Sampling_flag = 0;

PrEvt::PrEvt(QObject *parent) : QThread(parent)//一个线程
{
    isGoing = true;                           //isgoing是啥参数
}

PrEvt::~PrEvt()
{
    isGoing = false;
}

void PrEvt::SetPara(struct TotalProcessState *Total, struct STAGE *sta, struct paraTable_9171 *para, int k)
{
    this->TotalPro = Total;
    this->Stage = sta;
    this->Para = para;
    this->num = k;
}

void PrEvt::run()//这个线程中调用process_event//可以看到该函数一直在运行,停止运行按钮也没用
{
    while(isGoing){
        process_event(TotalPro, Stage,Para,num);
    }
}

//拟新建两个类：(1)process_event()对应的过程控制,就在run中循环;相关函数均归到这个类中;(2)PID控制类,专门负责PID计算与端口控制输出;ARM串口读入的数据,均传递到这两个类中;
//通过m_ShVar.para_tem_获取二级板/酒精/清洗,标准油与样品油 设定温度;
//实测温度在upsamping中得到
float testoil_clean_num;

// 函数整体由if else组成 每次仅能执行其中的一个分支 放在while(1) 通过每一步中标志位的处理 看起来是顺序执行下来的
// 温控如果放在另一个线程 且m_Base.sendCTLPkg是非阻塞的 需要线程同步 让这个线程等待温控需要的时间，不然这个线程就会陷入死循环 可以采用互斥锁或者等待条件 不要使用轮询的锁会使CPU占用过高
// 在m_Base.sendCTLPkg 的开头加上加锁 结尾解锁 温度变化速率控制、时间参数传递
void PrEvt::process_event(struct TotalProcessState *Total,struct STAGE *sta,struct paraTable_9171 *para,int k)      //由定时器触发事件,有多个定时器,可以识别多个定时器timeID,这里只一个//6分钟时间限制？有些按钮触发的界面反应,可以立即执行,不必放定时器中,感觉反应不灵敏
{                                //定时器启动的事件执行时间超过定时周期如何处理？加return？加执行中的状态判别？
    msleep(1000);
    QString stage;
    // 样品油

    if (timers.eventflag == 1)
    {
        emit logProcessComm("实验目标温度:"+QString::number(Total->TargetStage.TargetTemperature));

        // paraTable9171Content中totalTime等赋值
        para->flag = 1;

        if(Total->GeneralStage==INIT_Stage){
            // 初始阶段中机油和热管都处于室温
            stage = QString("INIT_Stage");
            if(Total->TargetStage.TargetTemperature >= 25)
            {
                Total->GeneralStage = S1_Stage1_RISE_TEM;
                sta->Isdoing = true;
                //            total_process_state.GeneralStage = S3_Stage1_DOWN_1_TEM;
                //            StageRefValue[0][2].Isdoing = true;
            }
        }
        // 存在温差不达标 Isdoing=1时与GeneralStage取或不等于任何标志位 的情况 不满足下面任何if判断
        // 当程序重启之后
        // if (flag) { // 标识是实验油还是标准油
        if(Total->TargetStage.TargetTemperature >= 25) {     // <=-20的情况 参考表A1
            if (Total->GeneralStage==S1_Stage1_RISE_TEM){
                qDebug()<<"GeneralStage==S1_Stage1_RISE_TEM";
                stage = QString("S1_Stage1_RISE_TEM");
                emit changeTableRowBackgroundColor(1, 0);
                Total->CurrentStageDoingTime = 0;
                sta->StartTime=QDateTime::currentDateTime();

                para->nowStageHaveSpend = 0;
                para->nowStage = 0;
                para->nowStageTotalTime = sta->Duration;
                // 升温到100度 5min
                if (tempControl(Total, sta, para, 1, (Total->TargetStage.TargetTemperature - 10), sta->Duration, 0, 0, k))
                    Total->GeneralStage=S2_Stage1_HOLD_TEM;
                else
                    Total->GeneralStage = STOP_RUNNING;
                //            tempControl(false, 0, 0, 80, 30, 0, 0, 0);
                sta->EndTime = QDateTime::currentDateTime();

                //total_process_state.CurrentTemperature = 80;
                //            StageRefValue[0][0].EndTime=StageRefValue[0][0].StartTime.addSecs(StageRefValue[0][0].Duration);
                sta->EndTime = QDateTime::currentDateTime();
                sta->Isdoing=false;
                sta->Isdone=true;
                (sta+1)->Isdoing=true;

            }
            else if(Total->GeneralStage==S2_Stage1_HOLD_TEM && (sta+1)->Isdoing){
                qDebug()<<"GeneralStage==S2_Stage1_HOLD_TEM";
                stage = QString("S2_Stage1_HOLD_TEM_START");
                emit changeTableRowBackgroundColor(1, 1);
                Total->CurrentStageDoingTime = 0;
                (sta+1)->StartTime=QDateTime::currentDateTime();

                para->nowStageHaveSpend = 0;
                para->nowStage = 1;
                para->nowStageTotalTime = (sta+1)->Duration;
                // 恒温 2h
                if (tempControl(Total, sta+1 , para, 1, (Total->TargetStage.TargetTemperature - 5), (sta+1)->Duration, 1, 1, k))
                    Total->GeneralStage = S3_Stage1_KEEP_TEM;
                else
                    Total->GeneralStage = STOP_RUNNING;
                //            tempControl(false, 0, 0, 80, 15, 0, 0, 1);
                (sta+1)->EndTime = QDateTime::currentDateTime();
                (sta+1)->Isdoing = false;
                (sta+1)->Isdone = true;
                (sta+2)->Isdoing = true;
            }
            else if(Total->GeneralStage==S3_Stage1_KEEP_TEM && (sta+2)->Isdoing){
                qDebug()<<"GeneralStage==S2_Stage1_HOLD_TEM";
                stage = QString("S3_Stage1_KEEP_TEM_START");
                emit changeTableRowBackgroundColor(1, 2);
                Total->CurrentStageDoingTime = 0;
                (sta+2)->StartTime=QDateTime::currentDateTime();

                para->nowStageHaveSpend = 0;
                para->nowStage = 2;
                para->nowStageTotalTime = (sta+2)->Duration;
                // 恒温 2h
                if (tempControl(Total, sta+2, para, 1, Total->TargetStage.TargetTemperature, (sta+2)->Duration, 1, 2, k))
                    Total->GeneralStage = S4_Stage1_REACTION_TEM;
                else
                    Total->GeneralStage = STOP_RUNNING;
                //            tempControl(false, 0, 0, 80, 15, 0, 0, 1);
                (sta+2)->EndTime = QDateTime::currentDateTime();
                (sta+2)->Isdoing = false;
                (sta+2)->Isdone = true;
                (sta+3)->Isdoing = true;
            }
            else if(Total->GeneralStage==S4_Stage1_REACTION_TEM && (sta+3)->Isdoing){
                qDebug()<<"GeneralStage==S2_Stage1_HOLD_TEM";
                stage = QString("S4_Stage1_REACTION_TEM");
                emit changeTableRowBackgroundColor(1, 3);
                Total->CurrentStageDoingTime = 0;
                (sta+3)->StartTime=QDateTime::currentDateTime();

                para->nowStageHaveSpend = 0;
                para->nowStage = 3;
                para->nowStageTotalTime = (sta+3)->Duration;
                // 恒温 2h
                if (tempControl(Total, sta+3, para, 1, Total->TargetStage.TargetTemperature, (sta+3)->Duration, 1, 3, k))
                    Total->GeneralStage = S3_Stage1_KEEP_TEM;
                else
                    Total->GeneralStage = STOP_RUNNING;
                //            tempControl(false, 0, 0, 80, 15, 0, 0, 1);
                (sta+3)->EndTime = QDateTime::currentDateTime();
                (sta+3)->Isdoing = false;
                (sta+3)->Isdone = true;
                (sta+4)->Isdoing = true;
            }
            else if(Total->GeneralStage==S4_Stage1_REACTION_TEM && (sta+4)->Isdoing){
                qDebug()<<"GeneralStage==S2_Stage1_HOLD_TEM";
                stage = QString("StageTargetEnd");
                emit changeTableRowBackgroundColor(1, 4);
                Total->CurrentStageDoingTime = 0;
                (sta+4)->StartTime=QDateTime::currentDateTime();
                Total->GeneralStage = StageTargetEnd;
                para->nowStageHaveSpend = 0;
                para->nowStage = 3;
                para->nowStageTotalTime = (sta+4)->Duration;

                (sta+4)->EndTime = QDateTime::currentDateTime();
                (sta+4)->Isdoing = false;
                (sta+4)->Isdone = true;
            }
        }
        if (timers.eventflag > 1)
            emit logProcessComm("当前阶段:"+stage);
    }
    else if (timers.eventflag == 0)
    {
        msleep(1000);
    }
}

void PrEvt::ShowDebugInfo()
{
    //    qDebug()<<
    //   qDebug()<<
    ;
}

// 温控函数 原型
// 机油目标温度 热管目标温度 持续时间(单位秒) 变化速率(没有要求就是0.0)
bool PrEvt::tempControl(struct TotalProcessState *Total, struct STAGE *sta, struct paraTable_9171 *para, bool isHeating, float alcohol, int duration, float rate, int m, int k)
{
    emit logProcessComm("----------0x"+QString::number(Total->GeneralStage, 16)+" Duration: "+QString::number(duration));
    qDebug()<<"----------0x"+QString::number(Total->GeneralStage, 16)+" Duration: "+QString::number(duration);
    // c两次控制之间间隔时间 最好取可以整除的时间  b 控制次数 用于渐近控温
    int TEN = 0, count = 0;
    int c = 5;
    int b = sta->Duration / c;
    float a = Total->CurrentTemperature;
    float data_visible[10] = {0}, Max, Pressure, sum;
    // 第一种渐进方法
//    float init = a;
    // 第二种渐进方法
    float startTemp = sta->StartTemptre;
    Total->CurrentStageSequence.TemperatureSetting = sta->EndTemptre;


    //3-10
    //qDebug()<<"prevt 1443 "+QString::number(timers.eventflag);

    // endtime starttime 比较 sleep() 实现
    //    QDateTime alarm = temp.addSecs(duration);
    while ((para->nowStageHaveSpend < duration) && timers.eventflag != 0)
    {
        //3-10
        //qDebug()<<"prevt 1450 "+QString::number(timers.eventflag);

        // S3_Stage1_DOWN_1_TEM = S3_Stage2_DOWN_1_TEM = 0xe000
        // 80->0 降温阶段
        if(Total->GeneralStage == S4_Stage1_REACTION_TEM)
        {
            Sampling_flag = 1;
            Pressure = sPkg.pre[k];
            if (Pressure >= Max)
            {
                Max = Pressure;
                if(TEN!=9)
                {
                    data_visible[TEN] = Max;
                    TEN++;
                }
                else
                {
                    data_visible[TEN] = Max;
                    TEN = 0;
                }
                count = 0;
                for(int z=0; z < 10; z++)
                {
                    if(data_visible[z] != 0)
                    {
                        count++;
                        sum += data_visible[z];
                    }
                }
                if(k == 0)
                {
                    paraTable9171Content.MaxPressureFresh = sum/count;
                }
                else
                {
                    paraTable9171Content2.MaxPressureFresh = sum/count;
                }
                sum = 0;
            }
        }
        if (isHeating)
        {

            para->oilFlag = 1;
            // 热管设置为加热模式

            // autoCTLTask 中开启油样控温
            ctlFlag[k] = 2;
            // 加热
            if (rate > 0)
            {
                // 需要渐近控温
                // 1.采用目标温度与进入阶段的温差来进行渐进控温
                // a += (erjiban - init) / b;
                // 2.采用规定的目标温度与初始温度进行渐进控温
                // 1、2两种渐进控温的方法选择一种 第一种会导致温度上升速率放缓
                startTemp += (sta->EndTemptre - sta->StartTemptre)/b;
                a = startTemp;

                myMutex.lock();
                m_Base.sendCTLPkg(CTL_SET_TEMREF,k, a); //降温0 酒精
                myMutex.unlock();
                para->oilTemp = a;
                emit logProcessComm("渐进控温 油样目标值:"+QString::number(a));
            } else {
                // 不需要渐近控温
                myMutex.lock();
                m_Base.sendCTLPkg(CTL_SET_TEMREF,k,alcohol); // 油样
                myMutex.unlock();
                para->oilTemp = alcohol;

                emit logProcessComm(" 油样目标值:"+QString::number(alcohol));
            }
            // 还是应该在sendPkgCTL 里面修改
        }
        if (timers.eventflag != 0 && para->flag != 0)
        {
            para->nowStageHaveSpend += c;
            para->haveSpent += c;
//            total_process_state.CurrentStageDoingTime = QDateTime::currentDateTime().toTime_t() - StageRefValue[m][n].StartTime.toTime_t();
            emit logProcessComm("温控时间:"+QString::number(para->nowStageHaveSpend)+"/"+QString::number(duration));
        }
        qDebug()<<"have speed "+QString::number(para->nowStageHaveSpend)+" / "+QString::number(duration)      \
                  + " nowStageHaveSpeet " + QString::number(para->nowStageHaveSpend);

        myMutex.lock();
        tempCtr.wait(&myMutex, c*1000);
        myMutex.unlock();

        if (timers.eventflag == 0)
        {
            //3-10
            //qDebug()<<"prevt 1528 "+QString::number(timers.eventflag);
            Total->GeneralStage = STOP_RUNNING;
            // 需要停止控温
            ctlFlag[k]=1;
            return false;
        }
    }
    return true;
}

