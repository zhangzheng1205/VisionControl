#include "gbase.h"
#include "mainwindow.h"

      //不能放到gbase.h之中,头文件中只声明类型，不放定义，避免重定义
struct table std_data;
struct time timers;
struct tubiaojiankong tubiaojiankongs;

float oiltem_real;    //给过程状态监控中，实时温度，doPkg（）中获取；
float oil2tem_real;
float debug_para[30];
float sum_reguan_temperature;
float ave_reguan_temperature;
float zhuansu;
float qingxiwendu;
float dianjiwendu;
float col=0;
int tem_flag_erjiban;       //温控是否达标标识
int tem_flag_jiujing;       //温控是否达标标识

QString essid_str;
QString password_str;
QString deviceid_str;

bool isfirst=true;
int nihe_num=2;
int old_nihe_num;

#define WINDOW_Smpling_SIZE 4       //温度消除噪声
float window_Smpling[WINDOW_Smpling_SIZE];
int window_Smpling_flag = 0;
int window_Smpling_set = 0;

float jiujing_window_sampling[WINDOW_Smpling_SIZE];
int jiujing_window_sampling_flag = 0;
int jiujing_window_sampling_set = 0;

#define WINDOW_CTRL_SIZE 60       //控制值取平均
float window_ctrl[WINDOW_CTRL_SIZE];
int window_ctrl_flag = 0;
int window_ctrl_set = 0;
int last_key0=0;
int last_key1=0;
int last_key2=0;
int last_key3=0;
int key0_jishu=0;
int key1_jishu=0;
int key2_jishu=0;
int key3_jishu=0;
int last_tem0=0;
int last_tem1=0;
int last_tem2=0;
int tem0_jishu=0;
int tem1_jishu=0;
int tem2_jishu=0;
int last_Dac0=0;
int last_Dac1=0;
int last_Dac2=0;
int Dac0_jishu=0;
int Dac1_jishu=0;
int Dac2_jishu=0;
int reqdebug_jishu=0;
int checkjiujinflag=0;

bool unlinked=false;
int last5[100]={0};

GBase::GBase(QObject *parent) : QThread(parent)//一个线程
{
    connect(&gSerial,SIGNAL(readyRead()),this,SLOT(onRecvData()));                  //接收串口数据，有数据就调onRecvData()
    connect(this,SIGNAL(recvOnePkg(QByteArray)),this,SLOT(doPKG(QByteArray)));      //如果收到数据包，就doPKG（）解析处理
    isGoing = isRecv = false;
    gRefTem[REF_REGUAN] = 40.0;//这是啥
    gRefTem[REF_JIUJING] = 43.0;
}

void GBase::run()
{
    isGoing = true;
    mPkgList.clear();
    int i = 0;
    int m = 0;
    while(isGoing){
        while(mPkgList.isEmpty() && isGoing){
            Sleep(100);
        }
        if(isGoing){
            struct iotPkg &pkg = mPkgList.first();
            isRecv = false;
            gSerial.write((char *)&pkg,pkg.iHeader.len);
            mPkgList.pop_front();
            for(i=0; i<100 && !isRecv && isGoing; i++){
                Sleep(10);
            }
            if(i<100&&m>0&&last5[m-1]==1){                //???含义》功能
                for(;m>0;m--){
                    last5[m-1]=0;
                }
            }
            if(i==100){
                emit logd("指令发送超时，请检查信号线！");//logd连接到logDefault,这种要用emit发射
                last5[m]=1;
                m++;
            }
            //qDebug()<<last5[0]<<last5[1]<<last5[2]<<last5[3]<<last5[4];
            if(last5[0]==1&&last5[1]==1&&last5[2]==1&&last5[3]==1&&last5[4]==1){
                unlinked=true;
            }
            else
                unlinked=false;
            if(m==100) m=0;
        }
        Sleep(100);
    }
    isGoing = false;
}

GBase::~GBase()
{
    isGoing = false;
    disconnect(&gSerial,SIGNAL(readyRead()),this,SLOT(onRecvData()));
    disconnect(this,SIGNAL(recvOnePkg(QByteArray)),this,SLOT(doPKG(QByteArray)));
    if(gSerial.isOpen()){
        gSerial.close();
    }
}

bool GBase::openSerial(QString com)
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

bool GBase::closeSerial()
{
    if(gSerial.isOpen()){
        gSerial.close();
        return true;
    }
    return false;
}

void GBase::sendData(char *data,qint64 len)
{
    gSerial.write(data,len);
}

void GBase::onRecvData()
{
    gRXBuffer  += gSerial.readAll();
    struct iotHeader *header = (struct iotHeader *)gRXBuffer.data();
    int pkg_len = gRXBuffer.length();
    //先判断前两个字节是不是头标志符 IOTPKG_FLAG
    //如果flag 不为 IOTPKG_FLAG 则删除一个字节
    //qDebug()<<"设备ID:"<<password_str.right(5).toInt()<<"本机ID:"<<gDeviceID<<timers.deviceid_flag;
    while(pkg_len >= 2 && header->flag != IOTPKG_FLAG){
        gRXBuffer.remove(0,1);
        header = (struct iotHeader *)gRXBuffer.data();
        pkg_len = gRXBuffer.length();
    }
    // 判断数据包是否接收完全
    if(pkg_len >= (int)sizeof(struct iotHeader) && header->len <= pkg_len){
        QByteArray pkg((char *)header,header->len);
        gRXBuffer.remove(0,header->len);
        emit recvOnePkg(pkg);
    }
}

void GBase::doPKG(QByteArray pkg)
{
    if(isfirst||(old_nihe_num!=nihe_num)){//zc1.5
        isfirst=false;
        old_nihe_num=nihe_num;
        lastsquare_struct1=get_ave.init_list(nihe_num);
        lastsquare_struct2=get_ave.init_list(nihe_num);
    }
    struct iotHeader *h = (struct iotHeader *)pkg.data();
    isRecv = true;
    switch(h->type){
    case PT_SAMPLING_RES:{
        struct ptSamplingRes *r = (struct ptSamplingRes *)(h+1);
        struct GSimplingData gsd;
        //交换温度传感器的顺序，适配模拟电路精度；  r->tem1 对应电路板PTA（原始版本二极板），r->tem2对应PTB（原始酒精）

        //二级板温度平均
        float sum = 0;
        float jiujingtem,erjibantem;
        // Add reguantem
        //float reguantem;
        window_Smpling[window_Smpling_set++] = get_TEMP_revise(r->tem1);
        if (window_Smpling_set == WINDOW_Smpling_SIZE)
        {
            window_Smpling_flag = 1;
            window_Smpling_set = 0;
        }
        if (window_Smpling_flag == 1)
        {
            for (int i = 0; i < WINDOW_Smpling_SIZE; i++)
                sum += window_Smpling[i];
//            gsd.tem1 = sum/WINDOW_Smpling_SIZE;
            erjibantem = sum/WINDOW_Smpling_SIZE;
        }
        else{
            for (int i = 0; i < window_Smpling_set; i++)
                sum += window_Smpling[i];
//            gsd.tem1 = sum/window_Smpling_set;
            erjibantem = sum/window_Smpling_set;
        }
        //实际与最小二乘法之后的数据差距大  1.4    一句qDebug能影响？？？？
        gsd.ls_tem1=erjibantem;
        get_ave.insert_element(erjibantem,lastsquare_struct1);
        if (lastsquare_struct1->flag == 1)
        {
            int plot_num1 = lastsquare_struct1->len;
            float *xx1 = new float[plot_num1];
            float *yy1 = new float[plot_num1];
            float *p1 = new float[2];
            for (int i = 0; i < plot_num1; i++)
            {
                xx1[i] = i;
                int j = (i + lastsquare_struct1->set) % lastsquare_struct1->len;
                yy1[i] = lastsquare_struct1->array[j];
//                qDebug()<<yy1[i];
            }
            get_ave.least_squares(plot_num1, xx1, yy1, p1);
            gsd.tem1 = p1[0] * (plot_num1 - 1) + p1[1];
//            qDebug()<<erjibantem<<gsd.tem1<<p1[0]<<p1[1]<<plot_num1;
            delete [] xx1;
            delete [] yy1;
            delete [] p1;
        }
        else
            gsd.tem1=erjibantem;
        //get_ave.free_struct(lastsquare_struct1);

        // 酒精温度平均
        float jiujing_sum = 0;
        jiujing_window_sampling[jiujing_window_sampling_set++] = get_TEMP(r->tem2);
        if (jiujing_window_sampling_set == WINDOW_Smpling_SIZE)
        {
            jiujing_window_sampling_flag = 1;
            jiujing_window_sampling_set = 0;
        }
        if (jiujing_window_sampling_flag == 1)
        {
            for (int i = 0; i < WINDOW_Smpling_SIZE; i++)
                jiujing_sum += jiujing_window_sampling[i];
//            gsd.tem2 = jiujing_sum / WINDOW_Smpling_SIZE;
            jiujingtem = jiujing_sum / WINDOW_Smpling_SIZE;
        }
        else{
            for (int i = 0; i < jiujing_window_sampling_set; i++)
                jiujing_sum += jiujing_window_sampling[i];
//            gsd.tem2 = jiujing_sum / jiujing_window_sampling_set;
            jiujingtem = jiujing_sum / jiujing_window_sampling_set;
        }
//新增  酒精跳变太大
        get_ave.insert_element(jiujingtem,lastsquare_struct2);
        // 最小二乘法 线性拟合
        if (lastsquare_struct2->flag == 1)
        {
            int plot_num2 = lastsquare_struct2->len;
            float *xx2 = new float[plot_num2];
            float *yy2 = new float[plot_num2];
            float *p2 = new float[2];
            for (int i = 0; i < plot_num2; i++)
            {
                xx2[i] = i;
                int j = (i + lastsquare_struct2->set) % lastsquare_struct2->len;
                yy2[i] = lastsquare_struct2->array[j];
//                qDebug()<<yy2[i];
            }
            get_ave.least_squares(plot_num2, xx2, yy2, p2);
            gsd.tem2 = p2[0] * (plot_num2 - 1) + p2[1];
            delete [] xx2;
            delete [] yy2;
            delete [] p2;
        }
        else
            gsd.tem2=jiujingtem;

//      sPkg.tem[0]=r->tem1;        //非°C,是AD值，获取温度AD
//zc改  sPkg.tem[1]=r->tem2;
        sPkg.sensor_tem[0]=r->tem1;
        sPkg.sensor_tem[1]=r->tem2;
        sPkg.tem[0]=get_ADCVALUE(get_TEMP_revise(r->tem1));//得到修订过的温度AD值
        sPkg.tem[1]=get_ADCVALUE(get_TEMP_revise(r->tem2));
        sPkg.pre[0]=r->pre1;
        sPkg.pre[1]=r->pre2;

        gsd.envh = r->env_h * 0.1;
        gsd.envt = r->env_t * 0.1;
        gsd.pre1 = r->pre1;
        gsd.pre2 = r->pre2;

        oiltem_real = gsd.tem1;               //°C，不是debugPIDsetting中到的采样原始值
        oil2tem_real = gsd.tem2;

        total_process_state.CurrentTemperature = gsd.tem1;
        total_process_state2.CurrentTemperature = gsd.tem2;
        total_process_state.CurrentPressure = gsd.pre1;
        total_process_state2.CurrentPressure = gsd.pre2;

        udpSocket = new QUdpSocket(this);
        emit updateSampling(gsd);//连接到绘图
        //上传采样数据
    }break;
    case PT_CONTROL_RES:{
        struct ptControlRes *r = (struct ptControlRes *)(h+1);
        Q_UNUSED(r);
    }break;
    case PT_SETWIFI_RES:{
        struct ptSetWiFiRes *r = (struct ptSetWiFiRes *)(h+1);
        emit logRX(tr("上行 == WIFI配置反馈: RESULT=") +QString::number(r->result));
    }break;
    case PT_SETTEM_RES:{
        struct ptSettemRes *r = (struct ptSettemRes *)(h+1);
        emit logRX(tr("设置温度成功") +QString::number(r->result));

    }break;
    case PT_DEBUG_RES:{
        struct ptDebugRes *r =(struct ptDebugRes *)(h+1);
        essid_str=QString::fromUtf8(r->essid);
        password_str=QString::fromUtf8(r->password);
        deviceid_str=QString::number(r->deviceid);
        // arm板重启次数
        emit setStartTimesValue(r->start_times);
        if(password_str.right(5).toInt()==gDeviceID){
            timers.deviceid_flag=1;
            reqdebug_jishu=5;
        }//
        else timers.deviceid_flag=0;
    }break;
    case PT_SETBJ_RES:{
        struct ptSetBJ_DIANJIRes *r = (struct ptSetBJ_DIANJIRes *)(h+1);
        emit logRX(tr("上行 == 步进电机配置反馈: RESULT=") +QString::number(r->result));
        emit logRX(tr("上行 == 步进电机配置反馈: X=") +QString::number(r->BJ_X));
        emit logRX(tr("上行 == 步进电机配置反馈: Y=") +QString::number(r->BJ_Y));
    }break;
    case PT_INSTRUMENTARM_RES:{
        struct ptInstrumentArmTestRes *r = (struct ptInstrumentArmTestRes *)(h+1);
        emit logRX(tr("上行 == 项目类型") + QString::number(r->TestType));
        emit logRX(tr("上行 == 完成反馈 0or1 ")+ QString::number(r->AngleTestResultInSetTime + r->TimeTestResultInSetAngle));

        emit logRX(tr("上行 == 转动角度反馈") +QString::number(r->CurrentAngleInSetTime));
        emit logRX(tr("上行 == 转动角度消耗时间反馈") +QString::number(r->TimeTestResultInSetAngle));
        emit logRX(tr("上行 == 测试时间反馈") +QString::number(r->CurrentTimeInSetAngle));//如有需要再进行扩展
        // 设置UI
        emit setUIAngleAndTime((int)r->CurrentAngleInSetTime, (int)r->CurrentTimeInSetAngle);


        // 半圈、一圈、三圈的赋值 临时测试用
        /*
        // 临时测试的终止条件
        if (r->AngleTestResultInSetTime == 1 || r->TimeTestResultInSetAngle == 1 || (r->TestType==AngleInSetTime && r->CurrentTimeInSetAngle>15000))
        {
            rollReqFlag = 0;        // 完成之后 停止下发查询
            if (r->AngleTestResultInSetTime == 1 || r->CurrentTimeInSetAngle>15000)
            {
                encoderDiskRes.resolution = r->CurrentAngleInSetTime;
                emit getResultFromEncoderDisk(false);       // 转15秒时 传入false
            }
            else
            {
                emit getResultFromEncoderDisk(true);        // 转三圈时 传入true
            }
        }
        */
        /*
        // 半圈、一圈、三圈的赋值
        if (r->TestType == TimeInSetAngle)
        {
            if (r->CurrentAngleInSetTime == encoderDiskResolution / 2)
            {
                encoderDiskRes.halfCircleflag = 1;
                encoderDiskRes.halfCircleTime = r->CurrentTimeInSetAngle;
            }
            if (r->CurrentAngleInSetTime == encoderDiskResolution)
            {
                encoderDiskRes.oneCircleflag = 1;
                encoderDiskRes.oneCircleTime = r->CurrentTimeInSetAngle;
            }
            if (r->CurrentAngleInSetTime == encoderDiskResolution * 3)
            {
                encoderDiskRes.threeCircleflag = 1;
                encoderDiskRes.threeCircleTime = r->CurrentTimeInSetAngle;
            }
        }
        */
    }break;
    default:break;
    }
}

void GBase::reqSampling()
{
    struct iotPkg pkg;
    struct iotHeader *h = &pkg.iHeader;
    struct ptSamplingReq *req = & pkg.iPkg.reqSampling;

    h->flag = IOTPKG_FLAG;
    h->version = IOTPKG_VERSION;
    h->type = PT_SAMPLING_REQ;
    h->len = sizeof(struct iotHeader) + sizeof(struct ptSamplingReq);
    h->deviceid = gDeviceID;
    h->loginid = gDeviceID;
    h->crc = 0x0000;

    req->channel = 0x00;
    req->res = 0x00;
    mPkgList.push_back(pkg);
}

void GBase::reqDebug()
{
    struct iotPkg pkg;
    struct iotHeader *h = &pkg.iHeader;
    struct ptDebugReq *req = & pkg.iPkg.reqDebug;

    h->flag = IOTPKG_FLAG;
    h->version = IOTPKG_VERSION;
    h->type = PT_DEBUG_REQ;
    h->len = sizeof(struct iotHeader) + sizeof(struct ptDebugReq);
    h->deviceid = gDeviceID;
    h->loginid = gDeviceID;
    h->crc = 0x0000;

    req->channel = 0x00;
    req->res = 0x00;
    if(reqdebug_jishu<5){
        mPkgList.push_back(pkg);
        emit logTX("下发 == DeBug配置指令");
        reqdebug_jishu++;
    }
}

void GBase::reqSetWiFi(QString essid,QString password)
{
    struct iotPkg pkg;
    struct iotHeader *h = &pkg.iHeader;
    struct ptSetWiFiReq *req = & pkg.iPkg.reqSetWifi;

    h->flag = IOTPKG_FLAG;
    h->version = IOTPKG_VERSION;
    h->type = PT_SETWIFI_REQ;
    h->len = sizeof(struct iotHeader) + sizeof(struct ptSetWiFiReq);
    h->deviceid = gDeviceID;
    h->loginid = gDeviceID;
    h->crc = 0x0000;

    sprintf(req->essid,"%s",essid.toLatin1().data());
    sprintf(req->password,"%s",password.toLatin1().data());
    emit logTX("下发 == WIFI配置指令: ESSID=[" + essid + "], PASSWORD=[" + password + "]");
    mPkgList.push_back(pkg);
}

void GBase::reqSettem(ptSettemReq st){
    struct iotPkg pkg;
    struct iotHeader *h = &pkg.iHeader;
    struct ptSettemReq *req = & pkg.iPkg.reqSettem;
    h->flag = IOTPKG_FLAG;
    h->version = IOTPKG_VERSION;
    h->type = PT_SETTEM_REQ;
    h->len = sizeof(struct iotHeader) + sizeof(struct ptSettemReq);
    h->deviceid = gDeviceID;
    h->loginid = gDeviceID;
    h->crc = 0x0000;
    req->kd=st.kd;
    req->ki=st.ki;
    req->kp=st.kp;
    mPkgList.push_back(pkg);
}

void GBase::reqSetBJ_dianji()
{
    struct iotPkg pkg;
    struct iotHeader *h = &pkg.iHeader;
    struct ptSetBJ_DIANJIReq *req = & pkg.iPkg.reqSetBJ_dianji;
    h->flag = IOTPKG_FLAG;
    h->version = IOTPKG_VERSION;
    h->type = PT_SETBJ_REQ;
    h->len = sizeof(struct iotHeader) + sizeof(struct ptSetBJ_DIANJIReq);
    h->deviceid = gDeviceID;
    h->loginid = gDeviceID;
    h->crc = 0x0000;
    req->BJ_dianjibianhao=m_ShVar.para_BJ_dianjibianhao;
    req->BJ_ori=m_ShVar.para_BJ_ori;
    req->BJ_reset=m_ShVar.para_BJ_RESET;
    emit logTX("下发 ==步进电机控制指令:步进电机横坐标: [" + QString::number(req->BJ_dianjibianhao) + "]" );
    emit logTX("下发 ==步进电机控制指令:步进电机纵坐标: [" + QString::number(req->BJ_ori) + "]" );
    emit logTX("下发 ==步进电机控制指令:步进电机复位: [" + QString::number(req->BJ_reset) + "]" );
    mPkgList.push_back(pkg);
}

float D_ac[4]={0};

void GBase::sendCTLPkg(int type,int channel,float val)
{
    struct iotPkg pkg;
    struct iotHeader *h = &pkg.iHeader;
    struct ptControlReq *req = &pkg.iPkg.reqControl;

    h->flag = IOTPKG_FLAG;
    h->version = IOTPKG_VERSION;
    h->type = PT_CONTROL_REQ;
    h->len = sizeof(struct iotHeader) + sizeof(struct ptControlReq);
    h->deviceid = gDeviceID;
    h->loginid = gDeviceID;
    h->crc = 0x0000;

    req->matchid = gDeviceID;
    req->type = type;
    req->channel = channel;                         //计算马达转速  启动时间tstrt，tstrt45；

    //
    //set_tubiao(type,channel,val);

	QString stype;
    switch(type){
    case CTL_SET_KEY:
//        req->value = (unsigned short)(val/5.0);
        // channel 用来编码盘查询指令发送 val==100对应TimeInSetAngle val==0对应AngleInSetTime
        req->value = val/5.0;
        stype = "KEY";
        if(val==100) gSetting.key[channel] =1;
        if(val==0)   gSetting.key[channel] =0;
        break;
    case CTL_SET_DAC:
//        req->value = (unsigned short)(4095 * val/5.0);
        req->value = 4095 * val/5.0;
        stype = "DAC";
        D_ac[channel]=val;//输出控制电压

        //控制值平均 channel==0 实际并没有使用
        if(channel==0)                               //???以下部分没有被实际yong，功能
        {
            float sum = 0;                                 //滑动窗的'小'与温度统计一致；
            window_ctrl[window_ctrl_set++] = req->value;
            if (window_ctrl_set == WINDOW_CTRL_SIZE)       //如果控制值窗口填满
            {
                window_ctrl_flag = 1;                 //填满标志位
                window_ctrl_set = 0;                  //再从0开始填
            }
            if (window_ctrl_flag == 1)
            {
                for (int i = 0; i < WINDOW_CTRL_SIZE; i++)   //累加满窗口中的值
                    sum += window_ctrl[i];
            }else{
                for (int i = 0; i < window_ctrl_set; i++)    //累加从0到当前的值
                    sum += window_ctrl[i];
            }
        }
        break;
    case CTL_SET_TEMREF:
        gRefTem[channel] = val;
        debugPIDsetting.temp_oil_setting[0] = gRefTem[0];
        debugPIDsetting.temp_oil_setting[1] = gRefTem[1];

        //req->value =  (short)(get_ADCVALUE(val));
//        req->value =  (short)(val);
        req->value = (short)(val+50)*100;
        stype = "TEMREF";
        break;
       // return ;//与10.8号不同     //温度不下发，被拦截dswang 2018-4-8
    case CTL_REBOOT:
        stype = "REBOOT";
        req->value = 0;
        break;     
    default:break;
    }
    if(stype=="KEY"){//以下要简化表达 KEY 0:二级板 1:酒精 2:热管
        if(channel==2){
            if(last_key2==req->value&&key2_jishu<=5){
                 key2_jishu++;
                 mPkgList.push_back(pkg);
                 emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                 last_key2=req->value;
            }
            else if(last_key2!=req->value){
                key2_jishu=0;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_key2=req->value;
            }
            else{
                QTime timexx =QTime::currentTime();
                if(timexx.second()*2 % 7 ==0){          //显示下采样，5s
                    mPkgList.push_back(pkg);
                    emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                }
            }
        }
        else if(channel==1){
            if(last_key1==req->value&&key1_jishu<=5){
                key1_jishu++;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_key1=req->value;
            }
            else if(last_key1!=req->value){
                key1_jishu=0;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_key1=req->value;
            }
            else{
				QTime timexx =QTime::currentTime();
                if(timexx.second()*2 % 11 ==0){          //显示下采样，5s
                    mPkgList.push_back(pkg);
                    emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                }
            }
        }
        else if(channel==0){
            if(last_key0==req->value&&key0_jishu<=5){
                key0_jishu++;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_key0=req->value;
            }
            else if(last_key0!=req->value){
                key0_jishu=0;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_key0=req->value;
            }
            else{
				QTime timexx =QTime::currentTime();
                if(timexx.second()*2 % 7 ==0){          //显示下采样，5s
                    mPkgList.push_back(pkg);
                    emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                }
            }
        }
        else if(channel==3){
            if(last_key3==req->value&&key3_jishu<=5){
                key3_jishu++;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_key3=req->value;
            }
            else if(last_key3!=req->value){
                key3_jishu=0;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_key3=req->value;
            }
            else{
				QTime timexx =QTime::currentTime();
                if(timexx.second()*2 % 5 ==0){          //显示下采样，5s
                    mPkgList.push_back(pkg);
                    emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                }
            }
        }
        else{
            mPkgList.push_back(pkg);
            emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value));
        }
    }
    else if(stype=="DAC"){
        if(channel==0){
            // 暂时注释掉Dac0_jishu
            Dac0_jishu = 0;
            if(last_Dac0==req->value&&Dac0_jishu<=5){
                Dac0_jishu++;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令油样一: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_Dac0=req->value;
            }
            else if(last_Dac0!=req->value){
                Dac0_jishu=0;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令油样一: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_Dac0=req->value;
            }
        }
        else if(channel==1){
            if(last_Dac1==req->value&&Dac1_jishu<=5){
                Dac1_jishu++;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令油样二: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_Dac1=req->value;
            }
            else if(last_Dac1!=req->value){
                Dac1_jishu=0;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令油样二: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_Dac1=req->value;
            }
        }
        else if (channel==2)
        {
            if(last_Dac2==req->value&&Dac2_jishu<=5){
                Dac2_jishu++;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令热管: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_Dac2=req->value;
            }
            else if(last_Dac2!=req->value){
                Dac2_jishu=0;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令热管: " + stype + QString::number(channel) + " = " + QString::number(req->value));
                last_Dac2=req->value;
            }
        }
    }
    else if(stype=="TEMREF"){
        if(channel==0){
            if(last_tem0==(req->value/100 - 50)&&tem0_jishu<=3){     //相同指令，只发送3次；
                tem0_jishu++;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value/100 - 50));
                last_tem0=(req->value/100 - 50);
            }
            else if(last_tem0!=(req->value/100 - 50)){
               tem0_jishu=0;
               mPkgList.push_back(pkg);
               emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value/100 - 50));
               last_tem0=(req->value/100 - 50);
            }
        }
        else if(channel==1){
            if(last_tem1==(req->value/100 - 50)&&tem1_jishu<=3){
                tem1_jishu++;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value/100 - 50));
                last_tem1=(req->value/100 - 50);
            }
            else if(last_tem1!=(req->value/100 - 50)){
                tem1_jishu=0;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value/100 - 50));
                last_tem1=(req->value/100 - 50);
            }
        } else if (channel == 2) {      // 电热丝控制
            if(last_tem2==(req->value/100 - 50)&&tem2_jishu<=3){
                tem2_jishu++;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value/100 - 50));
                last_tem2=(req->value/100 - 50);
            }
            else if(last_tem2!=(req->value/100 - 50)){
                tem2_jishu=0;
                mPkgList.push_back(pkg);
                emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number((req->value/100 - 50)));
                last_tem2=(req->value/100 - 50);
            }
        }
    }
    else {
        mPkgList.push_back(pkg);
        emit logTX("下发 == 控制指令: " + stype + QString::number(channel) + " = " + QString::number(req->value/100 - 50));
    }
}
//void GBase::set_tubiao(int type,int channel,float val)
//{
//    switch(type){
//    case CTL_SET_KEY:
//        if(channel==0){
//            if(val==100)
//                tubiaojiankongs.dianji=1;
//            else tubiaojiankongs.dianji=0;
//        }
//        if(channel==1){
//            if(val==100)
//                tubiaojiankongs.jiujinxunhuan=1;
//            else tubiaojiankongs.jiujinxunhuan=0;
//        }
//        if(channel==2){
//            if(val==100)
//                tubiaojiankongs.erjibanzhuangtai=1;
//            else if(val==0) tubiaojiankongs.erjibanzhuangtai=2;
//            else tubiaojiankongs.erjibanzhuangtai=0;
//        }
//        if(channel==3){
//            if(val==100)
//                tubiaojiankongs.clean=1;
//            else tubiaojiankongs.clean=0;
//        }
//        if(channel==4){
//            if(val==100)
//                tubiaojiankongs.dianjijiare=1;
//            else tubiaojiankongs.dianjijiare=0;
//        }
//        break;
//    case CTL_SET_DAC:
//        if(channel==1){
//            if(val>1)
//                tubiaojiankongs.jiujinjiare=1;
//            else tubiaojiankongs.jiujinjiare=0;
//        }
//        break;

//    default:break;
//    }

//}

void GBase::delay(int i)//Gbase是为了能让函数知道isgoing是gbase.h里面声明的？？？？ zc     //该函数有bug，一旦进入延时，期间无法中断；
{
//    QDateTime reachTime=QDateTime::currentDateTime().addSecs(i);
//    while(QDateTime::currentDateTime()<reachTime){
//      QCoreApplication::processEvents(QEventLoop::AllEvents,100);
//    }
    QThread::msleep(1000*i);      //网传占CPU资源少,  https://blog.csdn.net/x_nazgul/article/details/49333053
}

void GBase::stop()
{
    isGoing = false;
}

// 获取相应脉冲数对应的时间
void GBase::setAngleGetTime(int number)
{
    struct iotPkg pkg;
    struct iotHeader *h = &pkg.iHeader;
    struct ptInstrumentArmTestReq *req =&pkg.iPkg.reqInstrumentArm;
    h->flag = IOTPKG_FLAG;
    h->version = IOTPKG_VERSION;
    h->type=PT_INSTRUMENTARM_REQ;
    h->len = sizeof(struct iotHeader) + sizeof(struct ptInstrumentArmTestReq);
    h->deviceid = gDeviceID;
    h->loginid = gDeviceID;
    h->crc = 0x0000;
    req->TestType=TimeInSetAngle;
    req->ReqType=0;
    req->AngleofSetAngle=number;
    req->TimeofSetTime=0;
    emit logRX("[编码盘]下发 设置脉冲数:"+QString::number(number));
    mPkgList.push_back(pkg);
}

// 获取转相应时间(毫秒)对应的脉冲数
void GBase::setTimeGetAngle(int mseconds)
{
    struct iotPkg pkg;
    struct iotHeader *h = &pkg.iHeader;
    struct ptInstrumentArmTestReq *req =&pkg.iPkg.reqInstrumentArm;
    h->flag = IOTPKG_FLAG;
    h->version = IOTPKG_VERSION;
    h->type=PT_INSTRUMENTARM_REQ;
    h->len = sizeof(struct iotHeader) + sizeof(struct ptInstrumentArmTestReq);
    h->deviceid = gDeviceID;
    h->loginid = gDeviceID;
    h->crc = 0x0000;
    req->TestType=AngleInSetTime;
    // 设置编码盘为记录15转动角度模式
    req->ReqType=0;
    req->AngleofSetAngle=0;
    req->TimeofSetTime=mseconds;
    emit logRX("[编码盘]下发 设置时间(毫秒):"+QString::number(mseconds));
    mPkgList.push_back(pkg);
}
