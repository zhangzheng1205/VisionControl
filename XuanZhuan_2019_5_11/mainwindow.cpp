#include "mainwindow.h"
#include "ui_mainwindow.h"

QWaitCondition tempCtr;
QWaitCondition tempCtr2;

int rollReqFlag;        // 0->不向编码盘发送查询请求 1->向编码盘发送查询角度请求AngleInSetTime 2->向编码盘发送查询时间请求TimeInSetAngle

struct GBase m_Base;
struct SharedVariables m_ShVar;
struct PrEvt m_PrEvt;
struct PrEvt m_PrEvt2;
struct PidCtrl m_PidCtrl;
struct PidCtrl m_PidCtrl2;

struct ave_struct *jiujing_ave_struct;
struct ave_struct *erjiban_ave_struct;
struct ave_struct *erjiban_heat_struct;

struct paraTable_9171 paraTable9171Content = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "/", "/", "/"};
struct paraTable_9171 paraTable9171Content2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "/", "/", "/"};

struct process_struct *process_list = new struct process_struct[500];//初始化就有了List
struct result_struct *result_list = new struct result_struct[2];
struct process_struct *search_list = new struct process_struct[500];
double xiuding[10]={0};
double dianliu;
double kkk,bbb;
int rep;
int count=0;
float pingjunzhuansu=0;
int last20times=0;
bool isbehind81=false;
bool isopenexe=false;
float testoiltemp=150;
float stdoiltemp=140;
float targetTemp;
float SAMPLING_PERIOD;
float Max = 0;
int counter=-1;
int recordFlag[2] = {0,0};
int max_counter = 0;

// 系数表 3*8
char filename[100] = "";
// 标准油粘度表 10*8
char viscosity_filename[100] = "";
// 转速表 10*8
char rev_filename[100] = "";

void MainWindow::on_xiugaiButton_clicked()
{
    QString du40 = ui->lineEdit_4->text();//-40°
    QString du35 = ui->lineEdit_5->text();//-35°
    QString du30 = ui->lineEdit_6->text();//-30°
    QString du25 = ui->lineEdit_7->text();//-25°
    QString du20 = ui->lineEdit_8->text();//-20°
    QString du15 = ui->lineEdit_9->text();//-15°
    QString du10 = ui->lineEdit_10->text();//-10°
    QString du5  = ui->lineEdit_11->text();//-5°
    QString du0  = ui->lineEdit_12->text();//0°
    xiuding[0] = du40.toDouble();//在gbase.h中申明全局变量了
    xiuding[1] = du35.toDouble();
    xiuding[2] = du30.toDouble();
    xiuding[3] = du25.toDouble();
    xiuding[4] = du20.toDouble();
    xiuding[5] = du15.toDouble();
    xiuding[6] = du10.toDouble();
    xiuding[7] = du5.toDouble();
    xiuding[8] = du0.toDouble();

    QFile file("xiuding.txt");
    //--参数：QFile::Truncate表示的是将原文件内容清空,
    //--以WriteOnly方式打开文件,如果在工程文件下没有该txt文件,那么程序将创建该文件,若存在,则将原文件内容清空,
    if (file.open(QFile::WriteOnly | QFile :: Truncate))
    {
        //--创建 QTextStream流操作对象, 使与QFile对象file绑定。
        QTextStream out(&file);
        out <<xiuding[0]<<" "<<xiuding[1]<<" "<<xiuding[2]<<" "<<xiuding[3]<<" "<<xiuding[4]<<" "<<xiuding[5]<<" "<<xiuding[6]<<" "<<xiuding[7]<<" "<<xiuding[8];
    }
    file.close();//--关闭文件
    text_read();
}

void MainWindow::text_read()//能够在主函数调用,使其一进界面则显示上次修改过的数据
{
    QFile file("xiuding.txt");
    if(file.open(QFile::ReadOnly))
    {
        /*文本输出流,用于保存数据*/
        QTextStream in(&file);
        in >>xiuding[0];
        in >>xiuding[1];
        in >>xiuding[2];
        in >>xiuding[3];
        in >>xiuding[4];
        in >>xiuding[5];
        in >>xiuding[6];
        in >>xiuding[7];
        in >>xiuding[8];

        QByteArray ba0,ba1,ba2,ba3,ba4,ba5,ba6,ba7,ba8;
        ba0=QString::number(xiuding[0],10,5).toLatin1();
        ba1=QString::number(xiuding[1],10,5).toLatin1();
        ba2=QString::number(xiuding[2],10,5).toLatin1();
        ba3=QString::number(xiuding[3],10,5).toLatin1();
        ba4=QString::number(xiuding[4],10,5).toLatin1();
        ba5=QString::number(xiuding[5],10,5).toLatin1();
        ba6=QString::number(xiuding[6],10,5).toLatin1();
        ba7=QString::number(xiuding[7],10,5).toLatin1();
        ba8=QString::number(xiuding[8],10,5).toLatin1();

        char *xiu0,*xiu1,*xiu2,*xiu3,*xiu4,*xiu5,*xiu6,*xiu7,*xiu8;
        xiu0=ba0.data();
        xiu1=ba1.data();
        xiu2=ba2.data();
        xiu3=ba3.data();
        xiu4=ba4.data();
        xiu5=ba5.data();
        xiu6=ba6.data();
        xiu7=ba7.data();
        xiu8=ba8.data();

        ui->lineEdit_4->setText(delete_zero(xiu0));//最多5位小数
        ui->lineEdit_5->setText(delete_zero(xiu1));
        ui->lineEdit_6->setText(delete_zero(xiu2));
        ui->lineEdit_7->setText(delete_zero(xiu3));
        ui->lineEdit_8->setText(delete_zero(xiu4));
        ui->lineEdit_9->setText(delete_zero(xiu5));
        ui->lineEdit_10->setText(delete_zero(xiu6));
        ui->lineEdit_11->setText(delete_zero(xiu7));
        ui->lineEdit_12->setText(delete_zero(xiu8));

        file.close();
    }
}

QString MainWindow::delete_zero(char *xiu)
{//perfect去掉小数点后面多余的0
    int i,j=-1;
    for(i=strlen(xiu)-1;i>=0;i--)
        if(xiu[i]=='.')
            j=i;//找到小数点的位置
    if(j)//如果j>0,则有小数点//基本没起作用,前面用到了.todouble,强行变成5位小数了
    {
        i=strlen(xiu)-1;
        while(i>j && xiu[i]=='0')
        {
            xiu[i]='\0';
            i--;
        }
        if(i==j)
        {
            xiu[i]='\0';
        }
    }
    return QString(QLatin1String(xiu));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED);

    ui->setupUi(this);
    setWindowTitle(tr("旋转氧弹油样氧化寿命测定(电脑请设置为非睡眠/休眠模式)"));
    ui->pPlotTem1->addGraph2("温度","温度[℃]","压强","压强[Kpa]");             //图中坐标及名称
    ui->pPlotTem2->addGraph2("温度","温度[℃]","压强","压强[Kpa]");

    ui->pShowTem1->setName("油样一温度/(℃)");
    ui->pShowTem2->setName("油样二温度/(℃)");
    ui->pShowPre1->setName("油样一压强/(Kpa)");
    ui->pShowPre2->setName("油样二压强/(Kpa)");

    ui->display_oil_ave->set_color(Qt::blue);
    ui->display_oil_ave->setName("油样电压均值");
    ui->display_oil_ave->setStyleSheet("background-color:rgba(155, 155, 155, 200)");//白色
    ui->display_oil_set_tem->setName("油样渐近目标温度");
    ui->display_oil_set_tem->setStyleSheet("background-color:rgba(255, 255, 255, 100)");
    ui->display_flag->setName("汽轮机油or绝缘油");
    ui->display_flag->setStyleSheet("background-color:rgba(255, 255, 255, 100)");
    ui->display_reguan_ave->set_color(Qt::blue);
    ui->display_reguan_ave->setName("热管电压均值");
    ui->display_reguan_ave->setStyleSheet("background-color:rgba(155, 155, 155, 200)");
    //    ui->pLEDevID->setValidator(new QIntValidator(0,255,this));//只能输0-255

    ui->standard_revtable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->standard_revtable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->standard_revtable->resizeColumnsToContents();
    ui->standard_revtable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->dataTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //    ui->checkBox_isjiujingPID->setChecked(true);//首先选中酒精PID控制

    ui->paraTable_9171->setColumnWidth(0,105);
    ui->paraTable_9171->setColumnWidth(1,105);
    ui->paraTable_9171->setColumnWidth(2,105);

    initKEYComboBox();  //调用内部函数,初始化PID页后边表格
    initDACComboBox();
    initTEMREFComboBox();
//    initREBOOTComboBox();
    text_read();
    debug_paratext_read();
    makePlot();
    makesearchPlot(search_list, 0);
    initResultTab();
    //  ui->tabWidget_2->removeTab(4);//移除设置页！！！！！！！！！！！！！！！！！！！！！！！
    //调试中先不移除
    ui->radioButton_2->setDisabled(true);
    sprintf(filename, "%s", "para.txt");//sprintf(filename, "%s/%s", QCoreApplication::applicationDirPath().toStdString().data(), "para.txt");//拼接出文件路径
    sprintf(viscosity_filename, "%s", "viscosity.txt");
    sprintf(rev_filename, "%s", "rev.txt");

    // 系数表
/*    PROCESS_FILE b_datafile;                  //标准油,8温度*3变量
    b_datafile.make_file(filename);//调用外部process_file.cpp
    double b[3][9];
    b_datafile.get_parameter_from_file(filename, b, 3);
    for(int i=0;i<3;i++){
        for(int j=0; j<9;j++)
        {
            QTableWidgetItem *Item = new QTableWidgetItem();//表设置
            if (b[i][j] != 0.0)
                Item->setText(QString::number(b[i][j],'f',2));//float型,2位精度
            else
                Item->setText(tr(""));
            ui->revtable->setItem(i+10,j,Item);
        }
    }*/

    /*
    // 标准油粘度表
    b_datafile.make_file(viscosity_filename);
    double viscosity_table[10][9];
    b_datafile.get_parameter_from_file(viscosity_filename, viscosity_table, 10);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 9; j++) {
            QTableWidgetItem *Item = new QTableWidgetItem();
            if (viscosity_table[i][j] != 0.0)
                Item->setText(QString::number(viscosity_table[i][j],'f',0));//0不要小数
            else
                Item->setText(tr(""));
            ui->viscositytable->setItem(i,j,Item);
        }
    }
    */
    // 测试
    //StageRefValue 的初始化
    YIELDSTRESS test;
//        test.stageInitDebug(StageRefValue);
    //    StageRefValue.
    //    total_process_state 初始化
    test.totalProcessStateInit(&total_process_state);
    test.totalProcessStateInit(&total_process_state2);

    rollReqFlag = 0;

    pBGUpdateCycle = new QButtonGroup(this);            //形成一组button
    pBGUpdateCycle->addButton(ui->pRB200ms,200);        //200为指定的Button ID号;
    pBGUpdateCycle->addButton(ui->pRB500ms,500);
    pBGUpdateCycle->addButton(ui->pRB1000ms,1000);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        ui->pCom->addItem(info.portName());//添加COM口
    }
    //连接信号与槽  connect(sender,signal,receiver,member)将发射者sender对象中的信号signal与接收者receiver中的member槽函数联系起来
    connect(ui->pPBStart,SIGNAL(clicked(bool)),this,SLOT(onPBStart()));
    connect(pBGUpdateCycle,SIGNAL(buttonClicked(int)),this,SLOT(onBGUpdate(int)));//int 为button的ID号,ID已预设为200ms;500ms;1000s
    connect(ui->pPBWiFiSet,SIGNAL(clicked(bool)),this,SLOT(onPBSetWiFi()));

    connect(&m_Base,SIGNAL(updateSampling(GSimplingData)),this,SLOT(updateSampling(GSimplingData)));//线程中的数据向主线程传递;反过来???
    connect(&m_Base,SIGNAL(logTX(QString)),this,SLOT(logNote1(QString)));
    connect(&m_Base,SIGNAL(logRX(QString)),this,SLOT(logNote2(QString)));
    connect(&m_Base,SIGNAL(logd(QString)),this,SLOT(logDefault(QString)));
    connect(&m_Base,SIGNAL(setStartTimesValue(int)), this, SLOT(setUIStartTimesValue(int)));

    connect(this,SIGNAL(getResult(bool)),this,SLOT(setTestResult(bool)));
    connect(this,SIGNAL(stopSignal()),this,SLOT(stop()));
    connect(this,SIGNAL(setRollAngle(int)),&m_Base,SLOT(setAngleGetTime(int)));
    connect(this,SIGNAL(setRollTime(int)),&m_Base,SLOT(setTimeGetAngle(int)));

    connect(ui->pPlotTem1,SIGNAL(logd(QString)),this,SLOT(logDefault(QString)));
    connect(ui->pPlotTem2,SIGNAL(logd(QString)),this,SLOT(logDefault(QString)));
    connect(ui->PlotButton,SIGNAL(clicked()),this,SLOT(makePlot()));//将"生成表格"与makePlot函数进行槽联系

    std_oilComboBox();
    boxChange(0);
    test_oilComboBox();

    para_tem_test[1]->pComboBox->setCurrentIndex(1);//zc1218初始化在+15  选项还是+10

    //  disabled();

    connect(ui->radioButton_3,SIGNAL(clicked(bool)),this,SLOT(shoudongshuru()));
    connect(ui->stdoil,SIGNAL(clicked(bool)),this,SLOT(std_radiobutton_choose()));
    connect(ui->testoil,SIGNAL(clicked(bool)),this,SLOT(test_radiobutton_choose()));

    connect(&m_PrEvt,SIGNAL(logProcess(QString)),this,SLOT(logProcess(QString)));
    connect(&m_PrEvt,SIGNAL(logProcessComm(QString)),this,SLOT(logProcessComm(QString)));
    connect(&m_PrEvt,SIGNAL(logButtonRevover(int)), this,SLOT(logButtonRevover(int)));
    connect(&m_PrEvt,SIGNAL(changeTableRowBackgroundColor(int, int)),this,SLOT(changeTableRowBackgroundColor(int, int)));
    connect(&m_PrEvt,SIGNAL(trigger_fuwei()),this,SLOT(fuwei()));

    connect(&m_PidCtrl,SIGNAL(logProcess(QString)),this,SLOT(logProcess(QString)));
    connect(&m_PidCtrl,SIGNAL(logAutoCtrl(QString)),this,SLOT(logAutoCtrl(QString)));
    connect(&m_PidCtrl,SIGNAL(logAutoCtrljiujing(QString)),this,SLOT(logAutoCtrljiujing(QString)));

    accessNetwork = new QNetworkAccessManager();
    networkRequest = new QNetworkRequest();
    networkRequest->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    networkRequest->setUrl(QUrl("http://47.92.69.63/iot/iot_upload_data.php"));
    connect(accessNetwork, SIGNAL(finished(QNetworkReply*)), this, SLOT(accessReply(QNetworkReply*)));

    ui->testoil->setChecked(true);  //默认选中,下面变量同步设,否则第一次没温度;
    m_ShVar.testoil_isChecked=true;//标准油or样品油最开始没有默认

    //计算均值
    GET_AVERAGE get_ave;
    jiujing_ave_struct = get_ave.init_list(80);
    erjiban_ave_struct = get_ave.init_list(80);
    erjiban_heat_struct= get_ave.init_list(5);

    //resultTab
    ui->display_oil_set_tem->setColor("NULL");
    ui->display_reguan_ave->setColor("NULL");
    ui->display_oil_ave->setColor("NULL");
    ui->display_reguan_ave->setColor("NULL");

    QThread *anotherThread = new QThread();
    THREADPROCESS *anotherThreadTask = new THREADPROCESS();
    anotherThreadTask->moveToThread(anotherThread);
    anotherThread->start();
    connect(this, SIGNAL(ExcelFileNameSignal(QString, QTableWidget *, QString)), anotherThreadTask, SLOT(Table2ExcelB( QString, QTableWidget *, QString)), Qt::QueuedConnection);
    connect(anotherThreadTask, SIGNAL(Table2ExcelResultSignalA(bool, QString)), this, SLOT(Table2ExcelAResult(bool, QString)));

    autofresh_timer = new QTimer(this);
    autofresh_timer->setInterval(100);//0.01ms
    connect(autofresh_timer,SIGNAL(timeout()),this,SLOT(autofresh()));
    autofresh_timer->start();

    minute_timer = new QTimer(this);
    minute_timer->setInterval(1000);//1s
    connect(minute_timer,SIGNAL(timeout()),this,SLOT(minutefresh()));
    minute_timer->start();

    start_time=QDateTime::currentDateTime();
    ui->label_starttime->setText("程序启动时间:"+start_time.toString("yyyy-MM-dd hh:mm:ss"));
    timers.deviceid_flag=-1;
    ui->menuBar->addAction("启动屏幕录制工具", this,SLOT(screen_video()));
}

MainWindow::~MainWindow()
{
    m_Base.sendCTLPkg(CTL_SET_DAC,0,(float)112*5.0/4095.0); //关闭串口之前,置控制值为门限之下112; 防止串口关闭后,持续电压值
    QThread::msleep(100);
    m_Base.sendCTLPkg(CTL_REBOOT,0,0);
    QThread::msleep(100);

    GET_AVERAGE get_ave;
    get_ave.free_struct(jiujing_ave_struct);
    get_ave.free_struct(erjiban_ave_struct);
    get_ave.free_struct(erjiban_heat_struct);

    //    QMessageBox::warning(this, tr("警告！"),tr("请关闭测试主机！"),QMessageBox::Yes);//退出时关闭提示
    if(isopenexe)
        QMessageBox::warning(this, tr("提示"),tr("请记得结束录屏!"),QMessageBox::Yes);

    m_PrEvt.terminate();//强制结束线程
    m_PrEvt2.terminate();
    m_PidCtrl.terminate();
    m_PidCtrl2.terminate();

    m_Base.stop();
    m_Base.wait();

    delete ui;
}

void MainWindow:: std_radiobutton_choose()//标准油单选按钮,与样品油互斥
{
    ui->testoil->setChecked(false);//样品油取消选中
    ui->paraTable_2->setEnabled(true);
    m_ShVar.testoil_isChecked=false;//样品油不能被选
    m_ShVar.stdoil_isChecked=true;//标准油选中

//    ui->display_flag->setName("标准油");
    ui->display_flag->setStyleSheet("background-color:rgba(0, 255, 127,100)");
}

void MainWindow:: test_radiobutton_choose()//样品油单选按钮,与标准互斥
{
    ui->stdoil->setChecked(false);
    ui->paraTable->setEnabled(true);
    m_ShVar.testoil_isChecked=true;
    m_ShVar.stdoil_isChecked=false;
//    ui->display_flag->setName("样品油");
    ui->display_flag->setStyleSheet("background-color:rgba(255, 0, 127,100)");
}

void MainWindow::onPBSetWiFi()
{
    if(!ui->Config_Password->text().contains("F410F410"))
    {
        ui->pPBWiFiSet->setText("配置失败");
        return;
    }
    else
        ui->pPBWiFiSet->setText("配置成功");

    QString essid = ui->pLEWiFiEssid->text();//输入Essid
    QString passwd = ui->pLEWiFiPassword->text();//输入密码
    if(essid.length() == 0){
        logError("ESSID 不能为空");           //log左边栏输出，对应设备型号字符串
        ui->pLEWiFiEssid->setFocus();        //设置焦点,使光标跳转到ESSID输入栏
        return;
    }
    if(passwd.length() == 0){
        logError("PASSWORD 不能为空");          //对应设备ID字符串
        ui->pLEWiFiPassword->setFocus();
        return ;
    }
    m_Base.reqSetWiFi(essid,passwd);        //调用gbase.cpp,TX发送ID和密码
}

struct ptSettemReq MainWindow:: readSettem(ptSettemReq st)  //PID页各种参数编辑框
{
    motor_jiujing_ctl=ui->lineEdit_motor_jiujing_ctl->text().toFloat();//无此句 仅显示控制值为3370 然而没有传给autoctl线程  必须点击修改确认才传

    QString kp_srt=ui->kplineedit->text();
    QString kd_srt=ui->kdlineedit->text();
    QString ki_srt=ui->kilineedit->text();

    QString kp_srt2=ui->kplineedit_2->text();
    QString kd_srt2=ui->kdlineedit_2->text();
    QString ki_srt2=ui->kilineedit_2->text();

    QString kp_srt3=ui->kplineedit_3->text();
    QString kd_srt3=ui->kdlineedit_3->text();
    QString ki_srt3=ui->kilineedit_3->text();

    QString DjKp_srt4=ui->kplineedit_4->text();
    QString DjKd_srt4=ui->kdlineedit_4->text();
    QString DjKi_srt4=ui->kilineedit_4->text();

    QString erjiban_Max=ui->Erjiban_Max_lineedit->text();
    QString erjiban_Min=ui->Erjiban_Min_lineedit->text();
    QString erjiban_MaxErr=ui->Erjiban_MaxErr_lineedit->text();

    QString erjiban_Max2=ui->Erjiban_Max_lineedit_2->text();
    QString erjiban_Min2=ui->Erjiban_Min_lineedit_2->text();
    QString erjiban_MaxErr2=ui->Erjiban_MaxErr_lineedit_2->text();

    QString erjiban_Max3=ui->Erjiban_Max_lineedit_3->text();
    QString erjiban_Min3=ui->Erjiban_Min_lineedit_3->text();
    QString erjiban_MaxErr3=ui->Erjiban_MaxErr_lineedit_3->text();

    QString jiujing_kp=ui->jiujing_kp_lineedit->text();
    QString jiujing_ki=ui->jiujing_ki_lineedit->text();
    QString jiujing_kd=ui->jiujing_kd_lineedit->text();

    debugPIDsetting.Reguan_Max[0]=erjiban_Max.toFloat();
    debugPIDsetting.Reguan_Min[0]=erjiban_Min.toFloat();
    debugPIDsetting.Reguan_MaxErr[0]=erjiban_MaxErr.toFloat();
    debugPIDsetting.Reguan_Max[1]=erjiban_Max2.toFloat();
    debugPIDsetting.Reguan_Min[1]=erjiban_Min2.toFloat();
    debugPIDsetting.Reguan_MaxErr[1]=erjiban_MaxErr2.toFloat();
    debugPIDsetting.Reguan_Max[2]=erjiban_Max3.toFloat();
    debugPIDsetting.Reguan_Min[2]=erjiban_Min3.toFloat();
    debugPIDsetting.Reguan_MaxErr[2]=erjiban_MaxErr3.toFloat();

    debugPIDsetting.settem.k_p[0]= st.k_p[0]=kp_srt.toFloat();
    if(ki_srt.toFloat()==0)
        Oil.integral=2222;
    else
        Oil.integral=Oil.integral*Oil.Ki/ki_srt.toFloat();               //电机启动后,PID参数波动调整（新加的相对原来的函数,使PID更准确？）
    debugPIDsetting.settem.k_i[0]= st.k_i[0]=ki_srt.toFloat();
    debugPIDsetting.settem.k_d[0]= st.k_d[0]=kd_srt.toFloat();

    debugPIDsetting.settem.k_p[1]= st.k_p[1]=kp_srt2.toFloat();
    if(ki_srt2.toFloat()==0)
        Oil.integral=2222;
    else
        Oil.integral=Oil.integral*Oil.Ki/ki_srt2.toFloat();
    debugPIDsetting.settem.k_i[1]= st.k_i[1]=ki_srt2.toFloat();
    debugPIDsetting.settem.k_d[1]= st.k_d[1]=kd_srt2.toFloat();

    debugPIDsetting.settem.k_p[2]= st.k_p[2]=kp_srt3.toFloat();
    if(ki_srt3.toFloat()==0)
        Oil.integral=2222;
    else
        Oil.integral=Oil.integral*Oil.Ki/ki_srt3.toFloat();
    debugPIDsetting.settem.k_i[2]= st.k_i[2]=ki_srt3.toFloat();
    debugPIDsetting.settem.k_d[2]= st.k_d[2]=kd_srt3.toFloat();

    debugPIDsetting.DjKp=DjKp_srt4.toFloat();
    debugPIDsetting.DjKi=DjKi_srt4.toFloat();
    debugPIDsetting.DjKd=DjKd_srt4.toFloat();

    debugPIDsetting.jiu_kp=jiujing_kp.toFloat();
    debugPIDsetting.jiu_ki=jiujing_ki.toFloat();
    debugPIDsetting.jiu_kd=jiujing_kd.toFloat();

    return st;
}

void MainWindow::onPBSetTEM()           //主界面“开始运行”按钮click时,触发
{
    struct ptSettemReq st;
    st=readSettem(st);                          //调用上面的结构体函数
}

void MainWindow::onBGUpdate(int id)                //buttongroup更新定时
{
    if(ui->pPBStart->text().contains("停止运行")){  //如果按钮上显示停止运行
        start_upload = false;
        killTimer(mTimerID);                       //关闭定时器
        mTimerID = startTimer(id);
        logDefault("重设发送周期为 " + QString::number(id) + "ms");//日志窗口输出
    }
}

void MainWindow::onPBStart()                //主界面“开始运行”按钮click时,触发
{
    timers.ruanjian_time1=QDateTime::currentDateTime();
    QDateTime limitTime = QDateTime::fromString(QString("20201231"), "yyyyMMdd");
    if(timers.ruanjian_time1<=limitTime){
        if(ui->pPBStart->text().contains("开始运行")){//如果按钮显示开始运行
            if(!m_Base.openSerial(ui->pCom->currentText())){
                isstart=false;
                logError(ui->pCom->currentText()+" 打开失败！");
            }
            else
            {
                m_Base.gDeviceID = ui->pLEDevID->text().toInt();//设备ID转换成int型
                m_Base.start();                             //启动m_base 线程
                ui->pCom->setEnabled(false);                //串口复合框停止使能(有COM3.COM4的)
                ui->pLEDevID->setEnabled(false);                //设备ID框停止使能////////////////////////////
                ui->pPBStart->setText("停止运行");                //开始运行按钮变成停止运行

                logSuccess(ui->pCom->currentText()+"打开成功！"); //日志窗口显示（COM3.4）打开成功
                mTimerID = startTimer(pBGUpdateCycle->checkedId());        //采样定时
                logDefault("定时器打开:数据请求周期为" + QString::number(pBGUpdateCycle->checkedId()) + "ms");
                //3-10
                //qDebug()<<"mainwindow 679 "+QString::number(timers.eventflag);
                timers.eventflag=0;
                reqdebug_jishu=0;
                onPBSetTEM();                            //PID 参数传递到ARM板; 替换为传到PC PID端
                //3-10
                qDebug()<<"mainwindow 689 "+QString::number(timers.eventflag);
                fuwei();
                reset_struct();
            }
        }
        else if(ui->pPBStart->text().contains("停止运行") && timers.eventflag==0){//如果显示停止运行

            //3-10
            //qDebug()<<"mainwindow 691 "+QString::number(timers.eventflag);
            isstart=false;
            if(ui->stdoil->isChecked()){
                on_stop_std_pushButton_clicked();
            }
            if(ui->testoil->isChecked()){
                on_stopButton_clicked();//zc+++++
            }
            m_Base.stop();
            start_upload = false;

            m_Base.sendCTLPkg(CTL_SET_DAC,0,(float)112*5.0/4095.0); //关闭串口之前,置控制值为门限之下112; 防止串口关闭后,持续电压值
            m_Base.sendCTLPkg(CTL_SET_DAC,1,(float)112*5.0/4095.0);

            ui->pCom->setEnabled(true);//串口选择和设备ID框再次可选
            ui->pLEDevID->setEnabled(true);
            ui->pPBStart->setText("开始运行");
            m_Base.closeSerial();
            logSuccess(ui->pCom->currentText()+"停止采集数据,关闭成功！");
            killTimer(mTimerID);//关闭定时器
            logDefault("定时器关闭...1234455");
            reqdebug_jishu=0;
        }
        else if(ui->pPBStart->text().contains("停止运行") && (timers.eventflag==1)){
            QMessageBox::warning(this, tr("警告！"),tr("旋转氧弹实验中,请先停止旋转氧弹实验"),QMessageBox::Yes);
        }
        else if(ui->pPBStart->text().contains("停止运行") && timers.eventflag==5){
            QMessageBox::warning(this, tr("警告！"),tr("调试状态中,请先停止调试（点击任意停止键即可）"),QMessageBox::Yes);
        }
        upload_timer = new QTimer(this);
        connect(upload_timer, SIGNAL(timeout()), this, SLOT(uploadData()));
        upload_timer->start(1000);
    }
    else{
        QMessageBox::warning(this, tr("警告！"),tr("软件授权期已到,请续费！"),QMessageBox::Yes);
    }
}

void MainWindow::initKEYComboBox()           //PID页,KEY 0-7
{
    for(int i=0; i<8; i++){
        pKEY[i] = new DControl(CTL_SET_KEY,i,this);
        for(int k=0; k<=5; k++){
            pKEY[i]->pComboBox->addItem(QString::number(k*20)+tr(" %"));//添加6个可选项,0%-100%
        }
        ui->pConfTable->setCellWidget(i,1,pKEY[i]);//i行,1列,显示pKEY
        connect(pKEY[i],SIGNAL(sendCTLCMD(int,int,float)),&m_Base,SLOT(sendCTLPkg(int,int,float)));//连接信号和槽,发送到m_Base
    }
}

void MainWindow::initDACComboBox()            //PID页,DAC 0-3
{
    for(int i=0; i<4; i++){
        pDAC[i] = new DControl(CTL_SET_DAC,i,this);
        for(double v=0; v<=5.0; v+=0.01){
            pDAC[i]->pComboBox->addItem(QString::number(v)+tr(" V"));   //0-5V可选
        }
        ui->pConfTable->setCellWidget(i+8,1,pDAC[i]);                //i+8行,1列,显示pDAC
        connect(pDAC[i],SIGNAL(sendCTLCMD(int,int,float)),&m_Base,SLOT(sendCTLPkg(int,int,float)));
    }
}

void MainWindow::initTEMREFComboBox()     //PID页,TEM 0-1
{
    for(int i=0; i<2; i++){
        pTEMREF[i] = new DControl(CTL_SET_TEMREF,i,this);
        if(i==0)
            for(int t=-40; t<=10; t=t+5){
                pTEMREF[i]->pComboBox->addItem(QString::number(t)+tr(" ℃"));//tem0 -40~10°
                pTEMREF[i]->pComboBox->setCurrentIndex(4);
                
            }
        if(i==1)
            for(int t=-20; t<=15; t=t+5){
                pTEMREF[i]->pComboBox->addItem(QString::number(t)+tr(" ℃"));//tem1 -20~15°
                pTEMREF[i]->pComboBox->setCurrentIndex(4);
            }

        ui->pConfTable->setCellWidget(i+12,1,pTEMREF[i]);                    //i+12行,1列,显示pDAC
        connect(pTEMREF[i],SIGNAL(sendCTLCMD(int,int,float)),&m_Base,SLOT(sendCTLPkg(int,int,float)));
    }
}

/*
void MainWindow::initREBOOTComboBox()               //PID页,重启框
{
    pREBOOT = new DControl(CTL_REBOOT,0,this);
    ui->pConfTable->setCellWidget(14,1,pREBOOT);     //14行,1列
    pREBOOT->pComboBox->setVisible(false);           //不可见（反正也没得选）
    connect(pREBOOT,SIGNAL(sendCTLCMD(int,int,float)),&m_Base,SLOT(sendCTLPkg(int,int,float)));
}
*/
void MainWindow ::std_oilComboBox()                     //标准油表格中,插入相应的条目与选项
{
    QString type[10]={"CL-12","CL-14","CL-19","CL-22","CL-25","CL-28","CL-32","CL-48","CL-60","CL-74"};
    QString tem[2][9]={"-5","-10","-15","-18","-20","-25","-30","-35","-40","5","10","15","20","25"};//后面8个为最初始的酒精温度可选项

    para_std[0]=new DControl(CTL_SET_PARA,0,this);
    for(int t=0;t<10;t++){
        para_std[0]->pComboBox->addItem(type[t]);             //标准油表格中,“油样编号”后添加油样的可选类型,插入第0行第一列处;
    }
    ui->paraTable_2->setCellWidget(0,1,para_std[0]);

    para_std[1] = new DControl(CTL_SET_PARA,1,this);       //标准油表格中,插入清洗时间选项
    for(int t=10;t<40;t+=10){
        para_std[1]->pComboBox->addItem(QString::number(t));
    }
    ui->paraTable_2->setCellWidget(1,1,para_std[1]);

    para_std[2] = new DControl(CTL_SET_PARA,2,this);       //标准油表格中,插入电机运行时间
    for(int t=60;t<91;t+=10){
        para_std[2]->pComboBox->addItem(QString::number(t));
    }
    ui->paraTable_2->setCellWidget(2,1,para_std[2]);

    para_std[3] = new DControl(CTL_SET_PARA,3,this);       //插入清洗次数
    for(int t=1; t<=15; t+=1){
        para_std[3]->pComboBox->addItem(QString::number(t));
    }
    ui->paraTable_2->setCellWidget(3,1,para_std[3]);

    para_std[4] = new DControl(CTL_SET_PARA,4,this);       //插入清洗次数
    for(int t=1; t<=3; t+=1){
        para_std[4]->pComboBox->addItem(QString::number(t));
    }
    ui->paraTable_2->setCellWidget(4,1,para_std[4]);

    para_tem_std[0] = new DControl(CTL_SET_TEMREF,0,this); //插入二极板温度
    for(int t=0; t<9; t++){
        para_tem_std[0]->pComboBox->addItem(tem[0][t]+tr(" ℃"));
    }
    ui->paraTable_2->setCellWidget(5,1,para_tem_std[0]);
    para_tem_std[1] = new DControl(CTL_SET_TEMREF,1,this); //插入酒精温度
    for(int t=0; t<5; t++){
        para_tem_std[1]->pComboBox->addItem(tem[1][t]+tr(" ℃"));
    }
    ui->paraTable_2->setCellWidget(6,1,para_tem_std[1]);

    para_tem_std[2]=new DControl(CTL_SET_TEMREF,7,this);    //插入清洗温度
    for(int t=15; t<=25; t+=5){
        para_tem_std[2]->pComboBox->addItem(QString::number(t)+tr(" ℃"));
    }
    ui->paraTable_2->setCellWidget(7,1,para_tem_std[2]);

    //连接信号和槽
//    connect(para_std[0]->pComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(boxChange(int)));             //更改油样编号,触发更新油样对应的温度值
//    connect(para_tem_std[0]->pComboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(settem1box(QString)));    //更改二极板温度,触发???
//    connect(para_tem_std[1]->pComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(para_tem_std1(int)));
//    connect(para_tem_std[2]->pComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(para_tem_std2(int)));
}

/*void MainWindow::settem1box(QString str)          //根据二极板温度,更新表格中酒精温度可选值;
{
    para_tem_std[1]->pComboBox->clear();
    str=str.section(' ',0,0);
    float tem1=str.toFloat();                      //二极板温度
    float tem0=tem1+10;                             //酒精温度比二极板高+10度+5*k
    m_ShVar.para_tem_std0=tem1;
    m_ShVar.para_tem_std1=tem0;
    QString tem1_str=QString::number(tem0);
    para_tem_std[1]->pComboBox->addItem(tem1_str+tr(" ℃"));
    for(int t=1;t<=4;t++)
    {
        para_tem_std[1]->pComboBox->addItem(QString::number(tem0+5*t)+tr(" ℃"));    //默认是见下一句
    }
    para_tem_std[1]->pComboBox->setCurrentIndex(1);//zc1218默认+15度 为第二个
}*/

void MainWindow::para_tem_std1(int k)         //温度值付给过程process,debugsetting从process中获取温度//para_tem_ 类似几个函数的功能,已经在readcombox中实现,如不影响可以删除
{
    para_tem_std[1]->pComboBox->setCurrentIndex(k);
    m_ShVar.para_tem_std1=para_tem_std[1]->pComboBox->currentText().section(' ',0,0).toFloat();
}

void MainWindow ::test_oilComboBox()                       //作用与std_oilComboBox()相似,样品油表格中,插入相应的条目与选项
{
    QString tem[2][9]={"-5","-10","-15","-18","-20","-25","-30","-35","-40","5","10","15","20","25"};
    para[0] = new DControl(CTL_SET_PARA,0,this);
    for(int t=10;t<=20;t+=10){
        para[0]->pComboBox->addItem(QString::number(t));//para[0] 样品油清洗时间
    }
    ui->paraTable->setCellWidget(0,1,para[0]);

    para[1] = new DControl(CTL_SET_PARA,1,this);        //para[1] 样品油电机运行时间
    for(int t=60;t<91;t+=10){
        para[1]->pComboBox->addItem(QString::number(t));
    }
    ui->paraTable->setCellWidget(1,1,para[1]);

    para[2] = new DControl(CTL_SET_PARA,2,this);        //para[2] 样品油清洗次数
    for(int t=1; t<=15; t+=1){
        para[2]->pComboBox->addItem(QString::number(t));
    }
    ui->paraTable->setCellWidget(2,1,para[2]);

    para[3] = new DControl(CTL_SET_PARA,3,this);        //para[3] 样品油作样次数
    for(int t=1; t<=3; t+=1){
        para[3]->pComboBox->addItem(QString::number(t));
    }
    ui->paraTable->setCellWidget(3,1,para[3]);

    para[4] = new DControl(CTL_SET_PARA,4,this);        //para[4] 样品油静置时间
    for(int t=0; t<=3; t+=1){
        para[4]->pComboBox->addItem(QString::number(t));
    }
    ui->paraTable->setCellWidget(4,1,para[4]);

    para[5] = new DControl(CTL_SET_PARA,5,this);        //para[5] 样品油降温时间
    para[5]->pComboBox->addItem(QString::number(6));    //降温时间6分钟（即框中显示6）
    ui->paraTable->setCellWidget(5,1,para[5]);

    para_tem_test[0] = new DControl(CTL_SET_TEMREF,0,this);
    for(int t=0; t<9; t++){
        para_tem_test[0]->pComboBox->addItem(tem[0][t]+tr(" ℃"));
    }
    ui->paraTable->setCellWidget(6,1,para_tem_test[0]);

    para_tem_test[1] = new DControl(CTL_SET_TEMREF,1,this);
    for(int t=0; t<5; t++){
        para_tem_test[1]->pComboBox->addItem(tem[1][t]+tr(" ℃"));
    }
    ui->paraTable->setCellWidget(7,1,para_tem_test[1]);

    para_tem_test[2]=new DControl(CTL_SET_TEMREF,8,this);
    for(int t=15; t<=25; t+=5){
        para_tem_test[2]->pComboBox->addItem(QString::number(t)+tr(" ℃"));    //para_tem[2] 清洗温度
    }
    ui->paraTable->setCellWidget(8,1,para_tem_test[2]);

//    connect(para_tem_test[0]->pComboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(settem2box(QString)));
//    connect(para_tem_test[1]->pComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(para_tem_test1(int)));
//    connect(para_tem_test[2]->pComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(para_tem_test2(int)));
}

void MainWindow::settem2box(QString str)          //根据热管温度,更新表格中酒精温度可选值;
{
    para_tem_test[1]->pComboBox->clear();
    str=str.section(' ',0,0);
    float tem1=str.toFloat();                      //二极板温度
    float tem0=tem1+10;                             //酒精温度比二极板高+10度+5*k
    m_ShVar.para_tem_test0=tem1;
    m_ShVar.para_tem_test1=tem0;
    QString tem1_str=QString::number(tem0);
    para_tem_test[1]->pComboBox->addItem(tem1_str+tr(" ℃"));
    for(int t=1;t<=4;t++)
    {
        para_tem_test[1]->pComboBox->addItem(QString::number(tem0+5*t)+tr(" ℃"));    //选项变化,可选默认
    }
    para_tem_test[1]->pComboBox->setCurrentIndex(1);//zc1218
    m_ShVar.para_tem_test0=para_tem_test[0]->pComboBox->currentText().section(' ',0,0).toFloat();
    m_ShVar.para_tem_test1=para_tem_test[1]->pComboBox->currentText().section(' ',0,0).toFloat();
}

void MainWindow::para_tem_test1(int k)
{
    para_tem_test[1]->pComboBox->setCurrentIndex(k);
    m_ShVar.para_tem_test1=para_tem_test[1]->pComboBox->currentText().section(' ',0,0).toFloat();
}

void MainWindow::timerEvent(QTimerEvent *e)          //采样周期定时,定时在onBGUpdate()产生,与MainWindow::process_event()是两个不同时钟;
{
    Q_UNUSED(e);
    m_Base.reqSampling();
}

struct GSimplingData Kalman(struct GSimplingData r)//卡尔曼滤波
{
    static struct GSimplingData s = {0,0,0,0,0,0,0,0,0};
    if(s.DAC1==0){
        s=r;
    }
    else{
        s.DAC1=0.5*s.DAC1+0.5*r.DAC1;
        s.DAC0=r.DAC0;
    }
    return s;
}

void MainWindow::updateSampling(struct GSimplingData res)     //绘图,显示ARM反馈实时压力/马达转速/温度,并绘图;
{
    need_upload = res;
    need_upload2 = res;
    start_upload = true;

    ui->pPlotTem1->addData(res.tem1,res.pre1);	                    //画图热管温度,机油温度
    ui->pPlotTem2->addData(res.tem2,res.pre2);
    //    ui->pPlotPre->addData(res.pre1,res.pre2);                       //画图通道1,2

    ui->pShowTem1->setValue(QString::number(res.tem1,'f',2));       //显示油样1温度
    ui->pShowTem2->setValue(QString::number(res.tem2,'f',2));       //显示油样2温度
    ui->pShowPre1->setValue(QString::number(res.pre1,'f',2));       //显示油样1压强
    ui->pShowPre2->setValue(QString::number(res.pre2,'f',2));       //显示油样2压强
//    ui->pShowRollNum->setValue(QString::number(res.mcur,'f',3));        //显示电机电流
    timers.oil_tempflag = 1;
}

void MainWindow::logError(QString log)
{
    QDateTime time = QDateTime::currentDateTime();
    QString strtime = time.toString("[yyyy-MM-dd hh:mm:ss ddd]");
    ui->pLog->appendHtml("<label>"+ strtime +"<font color=red size=4>"+ log +"</font></label>");
}

void MainWindow::logSuccess(QString log)
{
    QDateTime time = QDateTime::currentDateTime();
    QString strtime = time.toString("[yyyy-MM-dd hh:mm:ss ddd]");
    ui->pLog->appendHtml("<label>"+ strtime +"<font color=green size=4>"+ log +"</font></label>");
}

void MainWindow::logDefault(QString log)
{
    QDateTime time = QDateTime::currentDateTime();
    QString strtime = time.toString("[yyyy-MM-dd hh:mm:ss ddd]");
    ui->pLog->appendHtml("<label>"+ strtime +"<font color=red size=3>"+ log +"</font></label>");
}

void MainWindow::logNote1(QString log)
{
    QDateTime time = QDateTime::currentDateTime();
    QString strtime = time.toString("[yyyy-MM-dd hh:mm:ss ddd]");
    ui->pLog->appendHtml("<label>"+ strtime +"<font color=olive size=3>"+ log +"</font></label>");
}

void MainWindow::logNote2(QString log)
{
    QDateTime time = QDateTime::currentDateTime();
    QString strtime = time.toString("[yyyy-MM-dd hh:mm:ss ddd]");
    ui->pLog->appendHtml("<label>"+ strtime +"<font color=purple size=3>"+ log +"</font></label>");
}

void MainWindow::logProcess(QString log)                              //调试flag的几个过程,实时能打印log出来;
{
    QDateTime time = QDateTime::currentDateTime();
    QString strtime = time.toString("[yyyy-MM-dd hh:mm:ss ddd]");
    ui->pLog_process->appendHtml("<label>"+ strtime +"<font color=blue size=3>"+ log +"</font></label>");
}

void MainWindow::logProcessComm(QString log)
{
    QDateTime time = QDateTime::currentDateTime();
    QString strtime = time.toString("[yyyy-MM-dd hh:mm:ss ddd]");
    ui->pLog_process->appendHtml("<label>"+ strtime +"<font color=purple size=3>"+ log +"</font></label>");
}

void MainWindow::logAutoCtrl(QString log)
{
    QDateTime time = QDateTime::currentDateTime();
    QString strtime = time.toString("[yyyy-MM-dd hh:mm:ss ddd]");
    ui->pLog->appendHtml("<label>"+ strtime +"<font color=purple size=3>"+ log +"</font></label>");
}

void MainWindow::logAutoCtrljiujing(QString log)
{
    QDateTime time = QDateTime::currentDateTime();
    QString strtime = time.toString("[yyyy-MM-dd hh:mm:ss ddd]");
    ui->pLog->appendHtml("<label>"+ strtime +"<font color=green size=3>"+ log +"</font></label>");
}

void MainWindow::on_settempushButton_clicked()                  //PID页,“修改确认”按钮
{
    onPBSetTEM();                                              //将PID 参数传递到ARM板
    nihe_num=ui->nihe_lineEdit->text().toInt() > 2 ? ui->nihe_lineEdit->text().toInt() : 2;//没存到txt 1.5
    motor_jiujing_ctl=ui->lineEdit_motor_jiujing_ctl->text().toFloat();
    debug_para[24]=motor_jiujing_ctl;
    QString debug_para_kp = ui->kplineedit->text();
    QString debug_para_ki = ui->kilineedit->text();
    QString debug_para_kd = ui->kdlineedit->text();
    QString debug_para_kp2 = ui->kplineedit_2->text();
    QString debug_para_ki2 = ui->kilineedit_2->text();
    QString debug_para_kd2 = ui->kdlineedit_2->text();
    QString debug_para_kp3 = ui->kplineedit_3->text();
    QString debug_para_ki3 = ui->kilineedit_3->text();
    QString debug_para_kd3 = ui->kdlineedit_3->text();
    QString debug_para_DJkp = ui->kplineedit_4->text();
    QString debug_para_DJki = ui->kilineedit_4->text();
    QString debug_para_DJkd = ui->kdlineedit_4->text();
    QString debug_para_Ejiban_Max = ui->Erjiban_Max_lineedit->text();
    QString debug_para_Ejiban_Min = ui->Erjiban_Min_lineedit->text();
    QString debug_para_Ejiban_MaxErr = ui->Erjiban_MaxErr_lineedit->text();
    QString debug_para_Ejiban_Max2 = ui->Erjiban_Max_lineedit_2->text();
    QString debug_para_Ejiban_Min2 = ui->Erjiban_Min_lineedit_2->text();
    QString debug_para_Ejiban_MaxErr2 = ui->Erjiban_MaxErr_lineedit_2->text();
    QString debug_para_Ejiban_Max3 = ui->Erjiban_Max_lineedit_3->text();
    QString debug_para_Ejiban_Min3 = ui->Erjiban_Min_lineedit_3->text();
    QString debug_para_Ejiban_MaxErr3 = ui->Erjiban_MaxErr_lineedit_3->text();
    QString debug_para_jiu_kp = ui->jiujing_kp_lineedit->text();
    QString debug_para_jiu_ki = ui->jiujing_ki_lineedit->text();
    QString debug_para_jiu_kd = ui->jiujing_kd_lineedit->text();
    debug_para[0]=debug_para_kp.toFloat();
    debug_para[1]=debug_para_ki.toFloat();
    debug_para[2]=debug_para_kd.toFloat();
    debug_para[3]=debug_para_kp2.toFloat();
    debug_para[4]=debug_para_ki2.toFloat();
    debug_para[5]=debug_para_kd2.toFloat();
    debug_para[6]=debug_para_kp3.toFloat();
    debug_para[7]=debug_para_ki3.toFloat();
    debug_para[8]=debug_para_kd3.toFloat();
    debug_para[9]=debug_para_DJkp.toFloat();
    debug_para[10]=debug_para_DJki.toFloat();
    debug_para[11]=debug_para_DJkd.toFloat();
    debug_para[12]=debug_para_Ejiban_Max.toFloat();
    debug_para[13]=debug_para_Ejiban_Min.toFloat();
    debug_para[14]=debug_para_Ejiban_MaxErr.toFloat();
    debug_para[15]=debug_para_Ejiban_Max2.toFloat();
    debug_para[16]=debug_para_Ejiban_Min2.toFloat();
    debug_para[17]=debug_para_Ejiban_MaxErr2.toFloat();
    debug_para[18]=debug_para_Ejiban_Max3.toFloat();
    debug_para[19]=debug_para_Ejiban_Min3.toFloat();
    debug_para[20]=debug_para_Ejiban_MaxErr3.toFloat();
    debug_para[21]=debug_para_jiu_kp.toFloat();
    debug_para[22]=debug_para_jiu_ki.toFloat();
    debug_para[23]=debug_para_jiu_kd.toFloat();
    QFile file("debug_para.txt");
    if (file.open(QFile::WriteOnly | QFile :: Truncate))
    {
        QTextStream out(&file);
        out <<debug_para[0]<<" "<<debug_para[1]<<" "<<debug_para[2]<<" "<<debug_para[3]<<" "<<debug_para[4]<<" "<<debug_para[5]<<" "<<debug_para[6]<<" "
                          <<debug_para[7]<<" "<<debug_para[8]<<" "<<debug_para[9]<<" "<<debug_para[10]<<" "<<debug_para[11]<<" "<<debug_para[12]<<" "
                         <<debug_para[13]<<" "<<debug_para[14]<<" "<<debug_para[15]<<" "<<debug_para[16]<<" "<<debug_para[17]<<" "<<debug_para[18]<<" "
                        <<debug_para[19]<<" "<<debug_para[20]<<" "<<debug_para[21]<<" "<<debug_para[22]<<" "<<debug_para[23]<<" "<<debug_para[24];
    }
    file.close();//--关闭文件
    debug_paratext_read();

}
void MainWindow::debug_paratext_read()//在主函数先调用一次,使其一进界面则显示上次修改过的数据
{
    QFile file("debug_para.txt");
    if(file.open(QFile::ReadOnly))
    {
        QTextStream in(&file);
        for(int i=0;i<25;i++)
        {
            in >>debug_para[i];
        }

        QByteArray ba[25];
        for(int i=0;i<25;i++){
            ba[i]=QString::number(debug_para[i],10,5).toLatin1();
        }

        char *xiu0,*xiu1,*xiu2,*xiu3,*xiu4,*xiu5,*xiu6,*xiu7,*xiu8,*xiu9,*xiu10,*xiu11,*xiu12,
                *xiu13,*xiu14,*xiu15,*xiu16,*xiu17,*xiu18,*xiu19,*xiu20,*xiu21,*xiu22,*xiu23,*xiu24;
        xiu0=ba[0].data();
        xiu1=ba[1].data();
        xiu2=ba[2].data();
        xiu3=ba[3].data();
        xiu4=ba[4].data();
        xiu5=ba[5].data();
        xiu6=ba[6].data();
        xiu7=ba[7].data();
        xiu8=ba[8].data();
        xiu9=ba[9].data();
        xiu10=ba[10].data();
        xiu11=ba[11].data();
        xiu12=ba[12].data();
        xiu13=ba[13].data();
        xiu14=ba[14].data();
        xiu15=ba[15].data();
        xiu16=ba[16].data();
        xiu17=ba[17].data();
        xiu18=ba[18].data();
        xiu19=ba[19].data();
        xiu20=ba[20].data();
        xiu21=ba[21].data();
        xiu22=ba[22].data();
        xiu23=ba[23].data();
        xiu24=ba[24].data();

        ui->kplineedit->setText(delete_zero(xiu0));
        ui->kilineedit->setText(delete_zero(xiu1));
        ui->kdlineedit->setText(delete_zero(xiu2));
        ui->kplineedit_2->setText(delete_zero(xiu3));
        ui->kilineedit_2->setText(delete_zero(xiu4));
        ui->kdlineedit_2->setText(delete_zero(xiu5));
        ui->kplineedit_3->setText(delete_zero(xiu6));
        ui->kilineedit_3->setText(delete_zero(xiu7));
        ui->kdlineedit_3->setText(delete_zero(xiu8));
        ui->kplineedit_4->setText(delete_zero(xiu9));
        ui->kilineedit_4->setText(delete_zero(xiu10));
        ui->kdlineedit_4->setText(delete_zero(xiu11));
        ui->Erjiban_Max_lineedit->setText(delete_zero(xiu12));
        ui->Erjiban_Min_lineedit->setText(delete_zero(xiu13));
        ui->Erjiban_MaxErr_lineedit->setText(delete_zero(xiu14));
        ui->Erjiban_Max_lineedit_2->setText(delete_zero(xiu15));
        ui->Erjiban_Min_lineedit_2->setText(delete_zero(xiu16));
        ui->Erjiban_MaxErr_lineedit_2->setText(delete_zero(xiu17));
        ui->Erjiban_Max_lineedit_3->setText(delete_zero(xiu18));
        ui->Erjiban_Min_lineedit_3->setText(delete_zero(xiu19));
        ui->Erjiban_MaxErr_lineedit_3->setText(delete_zero(xiu20));
        ui->jiujing_kp_lineedit->setText(delete_zero(xiu21));
        ui->jiujing_ki_lineedit->setText(delete_zero(xiu22));
        ui->jiujing_kd_lineedit->setText(delete_zero(xiu23));
        ui->lineEdit_motor_jiujing_ctl->setText(delete_zero(xiu24));
        file.close();
    }
}

void MainWindow::on_stop_std_pushButton_clicked()    //标准油“停止”按钮
{
    ui->cleanButton->setEnabled(true);               //停止后其他按钮均使能
    ui->startStdoilButton->setEnabled(true);
    ui->testoil_start->setEnabled(true);
    ui->stdoil->setEnabled(true);
    ui->stop_std_pushButton->setEnabled(true);
    ui->stopButton->setEnabled(true);
    stopProgram();                                   //调用后面停止函数
    m_ShVar.stopbutton_isChecked=true;
}

void MainWindow::stop()
{
    //3-10
    //qDebug()<<"mainwindow 1429 "+QString::number(timers.eventflag);
    emit logProcessComm("停止运行");
//    stopProgram();

    timers.eventflag = 0;                                  //调用后面停止函数
    fuwei();
    ui->PlotButton->setEnabled(true);
    ui->calculateButton->setEnabled(true);
    ui->printButton->setEnabled(true);
    ui->jisuanButton->setEnabled(true);
    ui->SampleN->setEnabled(true);
    ui->SampleViscosity->setEnabled(true);
    ui->SampleViscosity2->setEnabled(true);
    ui->searchButton->setEnabled(true);
    ui->record_num_search->setEnabled(true);
    ui->dateLine->setEnabled(true);
    ui->Max_pressureline->setEnabled(true);
    ui->Max_pressureline2->setEnabled(true);
    ui->oxidationLine->setEnabled(true);
    ui->oxidationLine2->setEnabled(true);
    ui->deleteButton->setEnabled(true);
    ui->enduceButton->setEnabled(true);
    ui->refreshButton->setEnabled(true);
    m_ShVar.stopbutton_isChecked=true;
    qDebug()<<"stopButton stop";
    tempCtr.wakeAll();
}
void MainWindow::on_stopButton_clicked()             //样品油界面中,“停止”按钮
{
    //3-10
    //qDebug()<<"mainwindow 1429 "+QString::number(timers.eventflag);
    emit logProcessComm("停止运行");
//    stopProgram();

    timers.eventflag = 0;                                  //调用后面停止函数
    fuwei();
    ui->PlotButton->setEnabled(true);
    ui->calculateButton->setEnabled(true);
    ui->printButton->setEnabled(true);
    ui->jisuanButton->setEnabled(true);
    ui->SampleN->setEnabled(true);
    ui->SampleViscosity->setEnabled(true);
    ui->SampleViscosity2->setEnabled(true);
    ui->searchButton->setEnabled(true);
    ui->record_num_search->setEnabled(true);
    ui->dateLine->setEnabled(true);
    ui->Max_pressureline->setEnabled(true);
    ui->Max_pressureline2->setEnabled(true);
    ui->oxidationLine->setEnabled(true);
    ui->oxidationLine2->setEnabled(true);
    ui->deleteButton->setEnabled(true);
    ui->enduceButton->setEnabled(true);
    ui->refreshButton->setEnabled(true);
    m_ShVar.stopbutton_isChecked=true;
    qDebug()<<"stopButton stop";
    tempCtr.wakeAll();
}

void MainWindow::on_testoil_start_clicked()  //监测界面中“实验开始”按钮
{
    SQLOPERATE searchsql;
    if(timers.oil_tempflag==1) {
        if(ui->pPBStart->text().contains("开始运行"))
        {
            QMessageBox::warning(this, tr("警告！"),tr("请先开始运行 ！"),QMessageBox::Yes);
            return;
        }
        else if(!ui->testoil->isChecked() && !ui->stdoil->isChecked())
        {
            QMessageBox::warning(this, tr("警告！"),tr("请选择(汽轮机油/绝缘油)选项 ！"),QMessageBox::Yes);
            ui->testoil->setFocus();
            return;
        }
        else if(ui->experimenter->text().isEmpty() || ui->experimenter2->text().isEmpty() || ui->testoil_num->text().isEmpty() || ui->testoil2_num->text().isEmpty())
        {
            QMessageBox::warning(this, tr("警告！"),tr("请输入油样编号和实验员名称！"),QMessageBox::Yes);
        }
        else if(ui->record_id->text().isEmpty())
        {
            QMessageBox::warning(this, tr("警告！"),tr("请输入批号！"),QMessageBox::Yes);
        }
        else if(searchsql.search_record(ui->record_id->text()))
        {
            QMessageBox::warning(this, tr("警告！"),tr("请勿输入重复批号！"),QMessageBox::Yes);
        }
        else if(ui->sampling_period->text().isEmpty())
        {
            QMessageBox::warning(this, tr("警告！"),tr("请输入采样周期！"),QMessageBox::Yes);
        }
        else
        {
            //3-10
            //qDebug()<<"mainwindow 1545 "+QString::number(timers.eventflag);
            fuwei();
            //readcombox();                     //获取para下拉表格中运行的时间/次数等参数值
            ui->startStdoilButton->setEnabled(false);
            ui->cleanButton->setEnabled(false);
            ui->stdoil->setEnabled(false);
            ui->stop_std_pushButton->setEnabled(false);
            ui->testoil_start->setEnabled(false);
            timers.eventflag=1;               //process_event状态标志
            SAMPLING_PERIOD = ui->sampling_period->text().toFloat();
            debugPIDsetting.dirTempCtrl=false;
            ui->paraTable->setEnabled(false);
            ui->radiowight->setEnabled(false);
            ui->oil2table_2->setEnabled(false);
            ui->dataTable->clearContents();
            ui->searchButton->setEnabled(false);
            ui->record_num_search->setEnabled(false);
            ui->dateLine->setEnabled(false);
            ui->Max_pressureline->setEnabled(false);
            ui->Max_pressureline2->setEnabled(false);
            ui->oxidationLine->setEnabled(false);
            ui->oxidationLine2->setEnabled(false);
            ui->deleteButton->setEnabled(false);
            ui->enduceButton->setEnabled(false);
            ui->refreshButton->setEnabled(false);
            m_ShVar.stopbutton_isChecked=false;
            if(ui->testoil->isChecked())
            {
                total_process_state.TargetStage.TargetTemperature = testoiltemp;
                total_process_state2.TargetStage.TargetTemperature = testoiltemp;
            }
            else if (ui->stdoil->isChecked())
            {
                total_process_state.TargetStage.TargetTemperature = stdoiltemp;
                total_process_state2.TargetStage.TargetTemperature = stdoiltemp;
            }
            YIELDSTRESS test;
            test.stage_init(StageRefValue);
            test.stage_init(StageRefValue2);
/*            int timeSum = 0;
            for (int i = 0; i < 5; i++) {
                timeSum += StageRefValue[i].Duration;
                //        qDebug()<< StageRefValue[0][i].Duration;
                for (int j = 0; j < 8; j++) {
                    QString showText;
                    QTableWidgetItem *Item = new QTableWidgetItem();

                    if (j == 0) {
                        showText = QString("%1:%2").arg(timeSum/3600, 2, 10, QLatin1Char('0')).arg((timeSum%3600)/60, 2, 10, QLatin1Char('0'));
                    } else if (j == 1) {
                        showText = QString("%1:%2").arg(StageRefValue[i].Duration/3600, 2, 10, QLatin1Char('0')).arg((StageRefValue[i].Duration%3600)/60, 2, 10, QLatin1Char('0'));
                    } else if (j == 4) {
                        if (StageRefValue[i].asymptote == 0)
                            showText = QString("");
                        else
                            showText = QString::number(StageRefValue[i].asymptote, 'f', 1);

                        if (i == 7)
                            showText = QString::number(StageRefValue[i].asymptote, 'f', 2);
                    } else if (j == 5) {
                        if (StageRefValue[i].allowError == 0)
                            showText = QString("");
                        else {
                            showText = QString("±");
                            showText.append(QString::number(StageRefValue[i].allowError, 'f', 1));
                        }
                    } else if (j == 2) {
                        if (i == 0)
                            showText = QString(">20");
                        else
                            showText = QString::number(StageRefValue[i].StartTemptre, 'f', 1);
                    } else if (j == 3) {
                        showText = QString::number(StageRefValue[i].EndTemptre, 'f', 1);
                    } else if (j == 6) {
                        if (StageRefValue[i].RepeatabilityErr == 0)
                            showText = QString("");
                        else
                            showText = QString::number(StageRefValue[i].RepeatabilityErr * 100, 'f', 1);
                    } else if (j == 7) {
                        if (StageRefValue[i].ReproducibilityErr == 0)
                            showText = QString("");
                        else
                            showText = QString::number(StageRefValue[i].ReproducibilityErr * 100, 'f', 1);
                    }

                    Item->setText(showText);
                    ui->viscositytable->setItem(i, j, Item);
                }
            }*/
            total_process_state.GeneralStage = INIT_Stage;
            total_process_state2.GeneralStage = INIT_Stage;

            //total_process_state.
            m_PrEvt.SetPara(&total_process_state, StageRefValue, &paraTable9171Content, 0);
            m_PrEvt2.SetPara(&total_process_state2, StageRefValue2, &paraTable9171Content2, 1);
            m_PrEvt.start();
            m_PrEvt2.start();

            m_PidCtrl.SetPara(&Oil,0);
            m_PidCtrl2.SetPara(&Oil2,1);
            m_PidCtrl.start();    //启动 事件和PID控制 线程
            m_PidCtrl2.start();
            isstart=true;


            // paraTable_9171 的复位
            paraTable9171Content = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "/", "/", "/"};
            for (int i = 0; i < 5; i++)
            {
                paraTable9171Content.totalTime += StageRefValue[i].Duration;
            }
            paraTable9171Content2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "/", "/", "/"};
            for (int i = 0; i < 5; i++)
            {
                paraTable9171Content2.totalTime += StageRefValue2[i].Duration;
            }
        }
    }
    else{
        QMessageBox::warning(this, tr("警告！"),tr("实验无法正常进行！"),QMessageBox::Yes);
    }
}

void MainWindow::on_rebootButton_clicked()    //"重启"ARM板重启
{
    //3-10
    //qDebug()<<"mianwindow 1680 "+QString::number(timers.eventflag);
    timers.eventflag=0;                       //process_event状态标志
    if(ui->pPBStart->text().contains("开始运行"))
    {
        QMessageBox::warning(this, tr("提示"),tr("请先\"开始运行\"!"),QMessageBox::Yes);
        return;
    }
    else
    {
        //3-10
        //qDebug()<<"mainwindow 1704 "+QString::number(timers.eventflag);
        m_Base.sendCTLPkg(CTL_REBOOT,0,0);        //重启
        fuwei();
    }
}

void MainWindow::boxChange(int index)     //index是box的序号 //根据油编号,在标准油粘度表中,选择有粘度的温度值,标准油不可能所有温度都有粘度值
{
/*    QString tem[9]={"-5","-10","-15","-18","-20","-25","-30","-35","-40"};
    para_tem_std[0]->pComboBox->clear();
    for(int j=0;j<9;j++)
    {
        if(ui->viscositytable->item(index,j)&&ui->viscositytable->item(index,j)->text()!=tr(""))
        {
            para_tem_std[0]->pComboBox->addItem(tem[j]+tr(" ℃"));
        }
    }*/
}

int MainWindow::findlocation()                    //找到标准油对应类型--温度交叉对应的格的位置,返回对应行与列（只要列,返回油的类型,而不用温度zc）
{
    QString tabletem[9]={"-5 ℃","-10 ℃","-15 ℃","-18 ℃","-20 ℃","-25 ℃","-30 ℃","-35 ℃","-40 ℃"};
    QString tabletype[10]={"CL-12","CL-14","CL-19","CL-22","CL-25","CL-28","CL-32","CL-48","CL-60","CL-74"};
    for(std_data.column=0;std_data.column<10;std_data.column++)
    {
        if(ui->stdoil->isChecked()){
            if(tabletype[std_data.column]==para_std[0]->pComboBox->currentText())
                break;
        }
    }
    for(std_data.row=0;std_data.row<9;std_data.row++)
    {
        if(ui->stdoil->isChecked()){
            if(tabletem[std_data.row]==para_tem_std[0]->pComboBox->currentText())
                break;
        }
        if(ui->testoil->isChecked()){
            if(tabletem[std_data.row]==para_tem_test[0]->pComboBox->currentText())
                break;
        }
    }
    return std_data.column;//return std_data.row , std_data.column;左边返回无用
}

void MainWindow::on_enduceButton_clicked()
{
    QString title_1=tr("旋转氧弹数据表");  //导出数据表
    QString fileName = QFileDialog::getSaveFileName(ui->standard_revtable, "保存",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"Excel 文件(*.xlsx)");
    emit ExcelFileNameSignal(fileName, ui->standard_revtable, title_1);
}

void MainWindow::stopProgram()                 //标准油与样品油中,“停止”按钮,均调该函数
{
    //3-10
    //qDebug()<<"mainwindow 1990 "+QString::number(timers.eventflag);
    fuwei();
}

void MainWindow::fuwei()
{
    // 左边数值显示
    paraTable9171Content = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "/", "/", "/"};
    paraTable9171Content2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "/", "/", "/"};
    // 指示灯复位 全部置为灰色
    tubiaojiankongs = {0, 0};
    //3-10
    //qDebug()<<"mainwindow 1997 "+QString::number(timers.eventflag);
    timers.eventflag=0;

    counter = -1;
    max_counter = 0;
    Max = 0;
    ctlFlag[0] = 1;
    ctlFlag[1] = 1;
    recordFlag[0] = 0;
    recordFlag[1] = 0;
    Sampling_flag = 0;
    rollReqFlag = 0;
    timers.reguanflag[0]=0;
    timers.reguanflag[1]=0;
    tubiaojiankongs.oiljiare=0;
    paraTable9171Content.flag = 0;
    paraTable9171Content2.flag = 0;

//    YIELDSTRESS test;
//    test.stageInitDebug(StageRefValue);
//    test.totalProcessStateInit(&total_process_state);
    total_process_state.CurrentStageDoingTime = 0;
    total_process_state2.CurrentStageDoingTime = 0;

    tem_flag_erjiban=0;
    sum_reguan_temperature=0;
    ave_reguan_temperature=0;
    jiujing_last_out_ctl=0;
    reguan_last_out_ctl=0;
    m_Base.sendCTLPkg(CTL_SET_KEY,1,0);        //关闭热管加热,
    m_Base.sendCTLPkg(CTL_SET_DAC,0,0);        //机油温控停止
    m_Base.sendCTLPkg(CTL_SET_TEMREF,0,debugPIDsetting.StopPidTemperature);    //温度51>50度,温控停止
    m_Base.sendCTLPkg(CTL_SET_TEMREF,1,debugPIDsetting.StopPidTemperature);

    ui->paraTable->setEnabled(true);            //使能所有选项框
    ui->paraTable_2->setEnabled(true);
    ui->radiowight->setEnabled(true);
    ui->oil2table_2->setEnabled(true);
    ui->startStdoilButton->setEnabled(true);
    ui->cleanButton->setEnabled(true);
    ui->testoil_start->setEnabled(true);
    // 两个radioButton 设置为true
    ui->stdoil->setEnabled(true);
    ui->testoil->setEnabled(true);

    ui->stop_std_pushButton->setEnabled(true);
    ui->stopButton->setEnabled(true);

    ui->pConfTable->setEnabled(false);         //调试窗口灰色

    ui->pConfTable->setEnabled(false);

    ui->PlotButton->setEnabled(false);
    ui->calculateButton->setEnabled(false);
    ui->printButton->setEnabled(false);
    ui->jisuanButton->setEnabled(false);
    ui->SampleN->setEnabled(false);
    ui->SampleViscosity->setEnabled(false);
    ui->SampleViscosity2->setEnabled(false);
}

void MainWindow::reset_struct()
{
    for(int i=0; i<500; i++)
    {
        process_list[i].id = 0;
        process_list[i].record_num = "0";
        process_list[i].number = "0";
        process_list[i].oil1_pre = "0";
        process_list[i].oil2_pre = "0";
    }

    for(int i=0; i<500; i++)
    {
        search_list[i].id = 0;
        search_list[i].record_num = "0";
        search_list[i].number = "0";
        search_list[i].oil1_pre = "0";
        search_list[i].oil2_pre = "0";
    }
    for(int i=0; i<2; i++)
    {
        result_list[i].id = 0;
        result_list[i].date = "0";
        result_list[i].time = "0";
        result_list[i].staff = "0";
        result_list[i].number = "0";
        result_list[i].record_num = "0";
        result_list[i].max_pressure = "0";
        result_list[i].set_temperature = "0";
        result_list[i].oxidation_period = "0";
        result_list[i].dec_pre_timepoint = "0";
        result_list[i].max_pre_timepoint = "0";
    }
}

void MainWindow::logButtonRevover(int flag)
{
    if(flag==0&&isstart)
    {
        debugPIDsetting.dirTempCtrl=false;
        debugPIDsetting.temp_oil_setting[0]=debugPIDsetting.StopPidTemperature;   //前两句没起作用(???),传到PID设置？ 初始情况下温度设为51,不温控
        debugPIDsetting.temp_oil_setting[1]=debugPIDsetting.StopPidTemperature;
    }
    if(flag==1)
    {
        //3-10
        //qDebug()<<"mainwindow 2075 "+QString::number(timers.eventflag);
        emit logProcess("开始加热机油");
        fuwei();
        QMessageBox *msgtest;
        msgtest = new QMessageBox(this);
        msgtest->setText("提示：实验已经完成 ！\n"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));   //内存是否存(保护问题?未释放)
        msgtest->show();
        fuwei();
        //        QMessageBox::warning(this, tr("提示！"),tr("实验已经完成 ！"));
    }
}

void MainWindow::accessReply(QNetworkReply* network_replay)
{
    int status_code = network_replay->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    Q_UNUSED(status_code);
    //    qDebug() << "statusCode:" << status_code;
    if(network_replay->error() == QNetworkReply::NoError)
    {
        //        qDebug() << "no error.";
    }
    else
    {
        //        qDebug() << "error!";
    }
    network_replay->deleteLater();
}

QString MainWindow::formatSecond(int second)
{
    return QString("%1:%2:%3").arg(second/3600, 2, 10, QLatin1Char('0'))    \
            .arg((second%3600)/60, 2, 10, QLatin1Char('0'))   \
            .arg((second%3600)%60, 2, 10, QLatin1Char('0'));
}

void MainWindow::on_printButton_clicked()
{
    if(ui->SampleViscosity->text() != "NULL" && paraTable9171Content.Down175PressureTime != "/")
    {
        emit getResult(true);
        SQLOPERATE insertsql;
        for(int i=0; process_list[i].oil1_pre != "0"; i++)
        {
            insertsql.insert_process_record(&process_list[i]);
        }
        ui->dataTable->clearContents();
        ui->SampleViscosity->clear();
        ui->SampleViscosity2->clear();
        makePlot();
        reset_struct();
        QMessageBox::information(this, tr("提示"),tr("实验已完成！"),QMessageBox::Yes);
    }
    else if(paraTable9171Content.Down175PressureTime == "/")
    {
        QMessageBox::information(this, tr("错误"),tr("实验并未完成！请清空数据重新开始！"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::information(this, tr("错误"),tr("未计算氧化寿命！"),QMessageBox::Yes);
    }
}

void MainWindow::on_jisuanButton_clicked()
{
    float Max1=0,Pressure1=0,Max2=0,Pressure2=0;
    float MaxPoint1=0,DownPoint1=0,MaxPoint2=0,DownPoint2=0;
    timers.ruanjian_time2=QDateTime::currentDateTime();
    QDateTime limitTime = QDateTime::fromString(QString("20200930"), "yyyyMMdd");
    if(timers.ruanjian_time2>=limitTime){
        ui->SampleViscosity->setText("授权期?!");
        ui->jisuanButton->setText("试用期已到,软件功能限制,需授权开放权限！");
        ui->jisuanButton->setStyleSheet("color: red");
        return;
    }

    if(ui->dataTable->item(1,0)!=NULL && ui->SampleN->text() != NULL)
    {
        for(int i = 0; i < ui->dataTable->rowCount(); i++)
        {
            Pressure1 = ui->dataTable->item(i,1)->text().toFloat();
            Pressure2 = ui->dataTable->item(i,2)->text().toFloat();
            if (Pressure1 >= Max1)
            {
                Max1 = Pressure1;
                MaxPoint1 = ui->dataTable->item(i,0)->text().toFloat();
                paraTable9171Content.MaxPressureTime = formatSecond((int)MaxPoint1 * SAMPLING_PERIOD);
                paraTable9171Content.MaxPressure = Max1;
            }
            if (Pressure2 >= Max2)
            {
                Max2 = Pressure2;
                MaxPoint2 = ui->dataTable->item(i,0)->text().toFloat();
                paraTable9171Content2.MaxPressureTime = formatSecond((int)MaxPoint2 * SAMPLING_PERIOD);
                paraTable9171Content2.MaxPressure = Max2;
            }
        }
        for(int i = (int)MaxPoint1; i < ui->dataTable->rowCount(); i++)
        {
            Pressure1 = ui->dataTable->item(i,1)->text().toFloat();
            Pressure2 = ui->dataTable->item(i,2)->text().toFloat();
            if (Pressure1 <= Max1 - ui->SampleN->text().toFloat() && recordFlag[0] == 0)
            {
                recordFlag[0] = 1;
                DownPoint1 = ui->dataTable->item(i,0)->text().toFloat();
                paraTable9171Content.Down175PressureTime = formatSecond((int)DownPoint1 * SAMPLING_PERIOD);
            }
            if (Pressure2 <= Max2 - ui->SampleN->text().toFloat() && recordFlag[1] == 0)
            {
                recordFlag[1] = 1;
                DownPoint2 = ui->dataTable->item(i,0)->text().toFloat();
                paraTable9171Content2.Down175PressureTime = formatSecond((int)DownPoint2 * SAMPLING_PERIOD);
            }
        }
        paraTable9171Content.OxidationPeriod = formatSecond((int)(DownPoint1-MaxPoint1) * SAMPLING_PERIOD);
        paraTable9171Content2.OxidationPeriod = formatSecond((int)(DownPoint2-MaxPoint2) * SAMPLING_PERIOD);
        ui->SampleViscosity->setText(paraTable9171Content.OxidationPeriod);
        ui->SampleViscosity2->setText(paraTable9171Content2.OxidationPeriod);
    }
    else if(ui->SampleN->text() == NULL)
    {
        ui->SampleViscosity->setText("");
        QMessageBox::information(this, tr("错误"),tr("请输入压降！"),QMessageBox::Yes);
    }
    else{
        ui->SampleViscosity->setText("");
        QMessageBox::information(this, tr("错误"),tr("已知数据不足,无法完成计算！"),QMessageBox::Yes);
    }
}

void MainWindow::on_deleteButton_clicked()
{
    SQLOPERATE searchsql;
    QString record_num = ui->record_num_search->text();
    if(record_num == NULL)
    {
        QMessageBox::information(this, tr("错误"),tr("请输入油样批号！"),QMessageBox::Yes);
    }
    else if(searchsql.search(search_list, record_num) == 0)
    {
        QMessageBox::information(this, tr("错误"),tr("未找到相应的批号！"),QMessageBox::Yes);
    }
    else
    {
        reset_struct();
        makesearchPlot(process_list, 0);
        ui->record_num_search->clear();
        ui->dateLine->clear();
        ui->Max_pressureline->clear();
        ui->Max_pressureline2->clear();
        ui->oxidationLine->clear();
        ui->oxidationLine2->clear();
        searchsql.delete_table(record_num);

        QMessageBox::information(this, tr("提示"),tr("删除成功！"),QMessageBox::Yes);
    }
}

void MainWindow::on_refreshButton_clicked()
{
    SQLOPERATE refreshsql;
    if(refreshsql.refresh_table(ui->standard_revtable))
    {
        QMessageBox::information(this, tr("提示"),tr("刷新成功！"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::information(this, tr("错误"),tr("刷新失败！"),QMessageBox::Yes);
    }
}

void MainWindow::on_searchButton_clicked()
{
    SQLOPERATE searchsql;
    QString record_num = ui->record_num_search->text();
    if(record_num == NULL)
    {
        QMessageBox::information(this, tr("错误"),tr("请输入油样批号！"),QMessageBox::Yes);
    }
    else if(searchsql.search(search_list, record_num) == 0)
    {
        QMessageBox::information(this, tr("错误"),tr("未找到相应的批号！"),QMessageBox::Yes);
    }
    else
    {
        int i = searchsql.search(search_list, record_num);
        searchsql.search_result(result_list, record_num);
        makesearchPlot(search_list, i);
        ui->dateLine->setText(result_list[0].date);
        ui->Max_pressureline->setText(result_list[0].max_pressure);
        ui->Max_pressureline2->setText(result_list[1].max_pressure);
        ui->oxidationLine->setText(result_list[0].oxidation_period);
        ui->oxidationLine2->setText(result_list[1].oxidation_period);
    }
}

void MainWindow::initResultTab()
{
    //测试结果tab的选填项如需同步,请在次修改
    ui->SampleViscosity->setPlaceholderText("油样一");
    ui->SampleViscosity2->setPlaceholderText("油样二");
    ui->Max_pressureline->setPlaceholderText("油样一");
    ui->Max_pressureline2->setPlaceholderText("油样二");
    ui->oxidationLine->setPlaceholderText("油样一");
    ui->oxidationLine2->setPlaceholderText("油样二");

    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");

    ui->dataTable->setColumnWidth(0,105);
    ui->dataTable->setColumnWidth(1,105);
    ui->dataTable->setColumnWidth(2,105);

    for(int i=0;i<10;i++){
        for(int k=0;k<3;k++){
            ui->dataTable->setItem(i,k,new QTableWidgetItem(""));
        }
    }
}

void MainWindow::makesearchPlot(struct process_struct *data, int k)
{
    ui->searchPlot->clearGraphs();
    ui->searchPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom| QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    ui->searchPlot->legend->setVisible(true);
    ui->searchPlot->legend->setBrush(QBrush(QColor(0,255,0,0)));
    //create graph and assign data to it:
    ui->searchPlot->addGraph();
    ui->searchPlot->addGraph();

    ui->searchPlot->graph(0)->setName("油样一压强");
    ui->searchPlot->graph(1)->setName("油样二压强");

    ui->searchPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->searchPlot->graph(1)->setPen(QPen(Qt::red));

    ui->searchPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->searchPlot->graph(1)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    for(int i = 0 ; i < k ; i++){ //遍历样油
        //描点
        ui->searchPlot->graph(0)->addData(data[i].number.toDouble(), data[i].oil1_pre.toDouble());
        ui->searchPlot->graph(1)->addData(data[i].number.toDouble(), data[i].oil2_pre.toDouble());
    }

    // give the axes some labels:
    ui->searchPlot->xAxis->setLabel("采样点");
    ui->searchPlot->xAxis->setVisible(true);
    ui->searchPlot->yAxis->setLabel("压强");
    ui->searchPlot->yAxis->setVisible(true);

    // set x,y axies2 visible右边和上面的坐标轴
    ui->searchPlot->xAxis2->setVisible(true);
    ui->searchPlot->xAxis2->setTicks(false);
    ui->searchPlot->xAxis2->setTickLabels(false);
    ui->searchPlot->yAxis2->setVisible(true);
    ui->searchPlot->yAxis2->setTicks(false);
    ui->searchPlot->yAxis2->setTickLabels(false);

    // set axes ranges, so we see all data:
    ui->searchPlot->xAxis->setRange(0, 600);
    ui->searchPlot->yAxis->setRange(0, 1500);
    ui->searchPlot->replot();

    ui->searchPlot->xAxis->setSubTickCount(20);//小刻度
    ui->searchPlot->yAxis->setSubTickCount(20);

    ui->searchPlot->xAxis->grid()->setSubGridPen(QPen((Qt::gray),0,Qt::DotLine));//网格线
    ui->searchPlot->xAxis->grid()->setSubGridVisible(true);
    ui->searchPlot->yAxis->grid()->setSubGridPen(QPen((Qt::gray),0,Qt::DotLine));
    ui->searchPlot->yAxis->grid()->setSubGridVisible(true);
}

void MainWindow::makePlot()//点击生成表格即调用,事先在MainWindow主函数里调用一次,图像就不会出问题
{
    ui->customPlot->clearGraphs();
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom| QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setBrush(QBrush(QColor(0,255,0,0)));
    //create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();

    ui->customPlot->graph(0)->setName("油样一压强");
    ui->customPlot->graph(1)->setName("油样二压强");

    ui->customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));

    ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->customPlot->graph(1)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    for(int i = 0 ; i < ui->dataTable->rowCount() ; i++){ //遍历样油
        //描点
        if(ui->dataTable->item(i,0)&&ui->dataTable->item(i,0)->text()!=tr(""))
        {
            ui->customPlot->graph(0)->addData(ui->dataTable->item(i,0)->text().toDouble(),ui->dataTable->item(i,1)->text().toDouble());
            ui->customPlot->graph(1)->addData(ui->dataTable->item(i,0)->text().toDouble(),ui->dataTable->item(i,2)->text().toDouble());
        }
        else
            break;
    }

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("采样点");
    ui->customPlot->xAxis->setVisible(true);
    ui->customPlot->yAxis->setLabel("压强");
    ui->customPlot->yAxis->setVisible(true);

    // set x,y axies2 visible右边和上面的坐标轴
    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTicks(false);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis2->setTicks(false);
    ui->customPlot->yAxis2->setTickLabels(false);

    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 600);
    ui->customPlot->yAxis->setRange(0, 1500);
    ui->customPlot->replot();

    ui->customPlot->xAxis->setSubTickCount(20);//小刻度
    ui->customPlot->yAxis->setSubTickCount(20);

    ui->customPlot->xAxis->grid()->setSubGridPen(QPen((Qt::gray),0,Qt::DotLine));//网格线
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen((Qt::gray),0,Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
}

void MainWindow::uploadData()//借用
{
    // paraTable_9171 內容显示
    if (paraTable9171Content.flag)
    {
        // 累积控温时长
        ui->paraTable_9171->setItem(1, 1, new QTableWidgetItem(formatSecond(paraTable9171Content.totalTime)));
        ui->paraTable_9171->item(1, 1)->setTextAlignment(Qt::AlignCenter);
        // 已进行时长及比例
        ui->paraTable_9171->setItem(2, 1, new QTableWidgetItem(
                                        formatSecond(paraTable9171Content.haveSpent)
                                        + '('
                                        + (paraTable9171Content.totalTime?QString::number((float)paraTable9171Content.haveSpent/paraTable9171Content.totalTime*100, 'f', 1):"0")
                                        + "%)"));
        ui->paraTable_9171->item(2, 1)->setTextAlignment(Qt::AlignCenter);
        // 阶段始温
        ui->paraTable_9171->setItem(3, 1, new QTableWidgetItem(QString::number(StageRefValue[paraTable9171Content.nowStage].StartTemptre, 'f', 2)));
        ui->paraTable_9171->item(3, 1)->setTextAlignment(Qt::AlignCenter);
        // 阶段终温
        ui->paraTable_9171->setItem(4, 1, new QTableWidgetItem(QString::number(StageRefValue[paraTable9171Content.nowStage].EndTemptre, 'f', 2)));
        ui->paraTable_9171->item(4, 1)->setTextAlignment(Qt::AlignCenter);
        // 当前阶段已进行时长及比例
        ui->paraTable_9171->setItem(5, 1, new QTableWidgetItem(
                                        formatSecond(paraTable9171Content.nowStageHaveSpend)
                                        + '('
                                        + (paraTable9171Content.nowStageHaveSpend?QString::number((float)paraTable9171Content.nowStageHaveSpend/paraTable9171Content.nowStageTotalTime*100, 'f', 1):"0")
                                        + "%)"));
        ui->paraTable_9171->item(5, 1)->setTextAlignment(Qt::AlignCenter);
        // 最高压强
        ui->paraTable_9171->setItem(6, 1, new QTableWidgetItem(QString::number(paraTable9171Content.MaxPressureFresh, 'f', 2) + "Kpa"));
        ui->paraTable_9171->item(6, 1)->setTextAlignment(Qt::AlignCenter);
        // 油样当前温度
        if (paraTable9171Content.oilFlag)

            ui->paraTable_9171->setItem(7, 1, new QTableWidgetItem(QString::number(total_process_state.CurrentTemperature, 'f', 2) + "℃"));
        else
            ui->paraTable_9171->setItem(7, 1, new QTableWidgetItem("\\"));
        ui->paraTable_9171->item(7, 1)->setTextAlignment(Qt::AlignCenter);
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            ui->paraTable_9171->setItem(i, 1, new QTableWidgetItem("\\"));
            ui->paraTable_9171->item(i, 1)->setTextAlignment(Qt::AlignCenter);
        }
    }

    if (paraTable9171Content2.flag)
    {
        // 累积控温时长
        ui->paraTable_9171->setItem(1, 2, new QTableWidgetItem(formatSecond(paraTable9171Content2.totalTime)));
        ui->paraTable_9171->item(1, 2)->setTextAlignment(Qt::AlignCenter);
        // 已进行时长及比例
        ui->paraTable_9171->setItem(2, 2, new QTableWidgetItem(
                                        formatSecond(paraTable9171Content2.haveSpent)
                                        + '('
                                        + (paraTable9171Content2.totalTime?QString::number((float)paraTable9171Content2.haveSpent/paraTable9171Content2.totalTime*100, 'f', 1):"0")
                                        + "%)"));
        ui->paraTable_9171->item(2, 2)->setTextAlignment(Qt::AlignCenter);
        // 阶段始温
        ui->paraTable_9171->setItem(3, 2, new QTableWidgetItem(QString::number(StageRefValue2[paraTable9171Content2.nowStage].StartTemptre, 'f', 2)));
        ui->paraTable_9171->item(3, 2)->setTextAlignment(Qt::AlignCenter);
        // 阶段终温
        ui->paraTable_9171->setItem(4, 2, new QTableWidgetItem(QString::number(StageRefValue2[paraTable9171Content2.nowStage].EndTemptre, 'f', 2)));
        ui->paraTable_9171->item(4, 2)->setTextAlignment(Qt::AlignCenter);
        // 当前阶段已进行时长及比例
        ui->paraTable_9171->setItem(5, 2, new QTableWidgetItem(
                                        formatSecond(paraTable9171Content2.nowStageHaveSpend)
                                        + '('
                                        + (paraTable9171Content2.nowStageHaveSpend?QString::number((float)paraTable9171Content2.nowStageHaveSpend/paraTable9171Content2.nowStageTotalTime*100, 'f', 1):"0")
                                        + "%)"));
        ui->paraTable_9171->item(5, 2)->setTextAlignment(Qt::AlignCenter);
        // 最高压强
        ui->paraTable_9171->setItem(6, 2, new QTableWidgetItem(QString::number(paraTable9171Content2.MaxPressureFresh, 'f', 2) + "Kpa"));
        ui->paraTable_9171->item(6, 2)->setTextAlignment(Qt::AlignCenter);
        // 油样当前温度
        if (paraTable9171Content2.oilFlag)

            ui->paraTable_9171->setItem(7, 2, new QTableWidgetItem(QString::number(total_process_state2.CurrentTemperature, 'f', 2) + "℃"));
        else
            ui->paraTable_9171->setItem(7, 2, new QTableWidgetItem("\\"));
        ui->paraTable_9171->item(7, 2)->setTextAlignment(Qt::AlignCenter);
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            ui->paraTable_9171->setItem(i, 2, new QTableWidgetItem("\\"));
            ui->paraTable_9171->item(i, 2)->setTextAlignment(Qt::AlignCenter);
        }
    }

    // 指示灯变换->图片变换
    if(tubiaojiankongs.oiljiare==1){
        // 油样加热 红色
        ui->label_jiujinjiare->setStyleSheet("border-image: url(:/login/res/red.png);");
    }
    else{
        // 油样不加热 灰色
        ui->label_jiujinjiare->setStyleSheet("border-image: url(:/login/res/gray.png);");
    }

    if (timers.eventflag == 1)
    {
        ui->display_flag->setName("实验中");
        ui->display_flag->setStyleSheet("background-color:rgba(0, 255, 127, 100)");
    }
    else if (timers.eventflag == 0)
    {
        ui->display_flag->setName("未启动");
        ui->display_flag->setStyleSheet("background-color:rgba(255, 0, 127,100)");
    }

    struct GSimplingData s;
    s.DAC0=D_ac[1];   //获取控制电压
    s.DAC1=D_ac[2];
    s=Kalman(s);


    ui->display_reguan_ave->setColor(QString::number(s.DAC0,10,2) + 'V');
    ui->display_oil_ave->setColor(QString::number(s.DAC1,10,2) + 'V');//加热时5V 不加热0V

    if(debugPIDsetting.temp_oil_setting[0] ==debugPIDsetting.StopPidTemperature){
        ui->display_oil_set_tem->setColor("NULL");
    }
    if(debugPIDsetting.temp_oil_setting[1] ==debugPIDsetting.StopPidTemperature){
        ui->display_oil_set_tem->setColor("NULL");
    }

    // A1 A2表前几个过程一样所以不用再判断 S1_Stage2_RISE_TEM S2_Stage2_HOLD_TEM
    if (paraTable9171Content.flag == 0)
    {
        ui->display_oil_set_tem->setColor("未启动");
        ui->display_oil_set_tem->set_color(Qt::gray);
    }
    else
    {
        ui->display_oil_set_tem->setColor(QString::number(paraTable9171Content.oilTemp, 10, 2)+"℃");
        ui->display_oil_set_tem->set_color(Qt::blue);
    }

    //当实验为反应阶段，每30s对油样压强进行一次采样
    if(Sampling_flag == 1)
    {
        count++;
        if(count == SAMPLING_PERIOD)
        {
            count = 0;
            if(counter == ui->dataTable->rowCount()-1)
            {
                ui->dataTable->insertRow(counter+1);
            }
            counter++;
            ui->dataTable->setItem(counter,0,new QTableWidgetItem(QString::number((float)counter, 'f', 2)));
            ui->dataTable->setItem(counter,1,new QTableWidgetItem(QString::number(total_process_state.CurrentPressure, 'f', 2)));
            ui->dataTable->setItem(counter,2,new QTableWidgetItem(QString::number(total_process_state2.CurrentPressure, 'f', 2)));
            process_list[counter].record_num = ui->record_id->text();
            process_list[counter].number = QString::number((float)counter, 'f', 2);
            process_list[counter].oil1_pre = QString::number(total_process_state.CurrentPressure, 'f', 2);
            process_list[counter].oil2_pre = QString::number(total_process_state2.CurrentPressure, 'f', 2);
            if(total_process_state.CurrentPressure >= Max)
            {
                Max = total_process_state.CurrentPressure;
            }
            else
            {
                if(max_counter >= 10)
                {
                    if(total_process_state.CurrentPressure <= Max/2)
                    {
                        emit stopSignal();
                    }
                }
                else
                {
                    max_counter++;
                }
            }
        }
    }
    upload_flag++;
    if (start_upload && upload_flag == 10)//为10/2=5s传一次
    {
        upload_flag = 0;
        struct GSimplingData res = need_upload;
        QString upload_str = upload_sampling_encode(&res);
        upload_send(upload_str);
        //qDebug()<<upload_str;
    }
    m_Base.reqDebug();
    //    ui->essid_label->setText("设备型号: "+essid_str);
    ui->essid_label->setText("设备型号: CCS6538-2000");
    if(timers.deviceid_flag==0){
        //        ui->password_label->setText("设备ID: "+password_str+" || 软硬件版本不匹配");    //参照链路异常,不匹配时显示为红色
        ui->password_label->setText("设备ID: ... || 软硬件版本匹配?");	  //参照链路异常,不匹配时显示为红色
        QPalette pa1;
        //        pa1.setColor(QPalette::WindowText,Qt::red);
        ui->password_label->setPalette(pa1);
    }
    else if(timers.deviceid_flag==1){
        ui->password_label->setText("设备ID: "+password_str+" || 软硬件版本匹配");
        QPalette pa2;
        pa2.setColor(QPalette::WindowText,Qt::black);
        ui->password_label->setPalette(pa2);
    }
    else ui->password_label->setText("设备ID: ...软硬件版本待校验...");

    //    if(ui->password_label->text().contains("软硬件版本不匹配")||ui->password_label->text()=="设备ID: "){
    if(ui->password_label->text().contains("软硬件版本不匹配")){
        //  disabled();
        //        para_tem_test[0]->pComboBox->setDisabled(true);   //这两行暂时注释，便于调试，勿删除；
        //        ui->paraTable_2->setDisabled(true);
    }

    ui->label_arm_in->setText("ARM读入:"+essid_str+";"+password_str+";");
    if(unlinked)
    {
        ui->label_56->setText("信号传输异常,请拧紧信号线接头,设备断电重启!");
        QFont ft;
        ft.setPointSize(12);
        ui->label_56->setFont(ft);
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label_56->setPalette(pa);
    }
    else{
        ui->label_56->setText("链路正常");
        QFont ft;
        ft.setPointSize(9);
        ui->label_56->setFont(ft);
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::black);
        ui->label_56->setPalette(pa);
    }
}

QString MainWindow::upload_sampling_encode(GSimplingData * res)
{
    return QString("{\"type\":1,\"time\":\"%1\",\"tem1\":%2,\"tem2\":%3,\"pre1\":%4,\"pre2\":%5,\"mcur\":%6,\"mspe\":%7,\"envh\":%8,\"envt\":%9,\"dev_id\":%10}").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(res->tem1).arg(res->tem2).arg(res->envh).arg(res->envt).arg(ui->pLEDevID->text());
}

void MainWindow::on_BJdianji_sent_clicked()
{
    //readcombox();
    m_Base.reqSetBJ_dianji();
}

void MainWindow::on_BJ_open_clicked()
{
    m_Base.sendCTLPkg(CTL_SET_KEY,5,100);
    emit m_Base.logTX("下发 == 控制指令:步进电机打开 " );
}

void MainWindow::shoudongshuru()
{
    if(ui->radioButton_3->isChecked()){
        ui->standard_revtable->setEditTriggers(QAbstractItemView::DoubleClicked);
    }
    if(!ui->radioButton_3->isChecked()){
        ui->standard_revtable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}

void MainWindow::on_actionShow_S_triggered()
{
    LoginDialog dlg;
    if(dlg.exec() == QDialog::Accepted){
        ui->tabWidget_2->addTab(ui->tab_3,"设置页");
        isshow=true;
    }
}

void MainWindow::on_actionHide_H_triggered()
{
    ui->tabWidget_2->removeTab(4);
    isshow=false;
}

void MainWindow::on_action_2_triggered()
{
    QMessageBox::information(this, tr("软件版本！"), tr("版本3.3.3333,2019/1/13,版权归属,请支持正版软件！"), QMessageBox::Yes);
}

void MainWindow::loading(bool k)
{
    int seed = QDateTime::currentDateTime().time().second();//随机变化
    srand(seed);
    int randNum = rand()%3;
    QColor c;
    switch (randNum) {
    case 0:
        c=Qt::white;//借用 浅紫色
        break;
    case 1:
        c=Qt::yellow;
        break;
    case 2:
        c=Qt::black;//借用 青色
        break;
    default:
        break;
    }
    //顺序变化就是用一个int i=0;i++; int ii=i%4;(ii=0 1 2 3)
    if(k==1) ui->display_oil_set_tem->set_color(c);
}
void MainWindow::Table2ExcelAResult(bool result, QString str)
{
    if (result)
    {
        if (QMessageBox::question(NULL,"完成","文件已经导出,是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
            QDesktopServices::openUrl(QUrl(str));
    }else{
        QMessageBox::warning(NULL,"错误","未能创建 Excel 对象,请安装 Microsoft Excel。",QMessageBox::Apply);
    }
}

void MainWindow::autofresh()
{
    if((!ui->stdoil->isChecked()) && (!ui->testoil->isChecked())){
        ui->display_flag->setName("样品油or标准油");
        if(timers.eventflag==5){
            ui->display_flag->setName("仅限调试状态");
        }
        ui->display_flag->setStyleSheet("background-color:rgba(255, 255, 255, 100)");
    }
    if(!ui->stdoil->isChecked()){
        ui->paraTable_2->setDisabled(true);
    }
    if(!ui->testoil->isChecked()){
        ui->paraTable->setDisabled(true);
    }
    if(isshow){
        ui->actionShow_S->setDisabled(true);
        ui->actionHide_H->setEnabled(true);
    }
    else{
        ui->actionHide_H->setDisabled(true);
        ui->actionShow_S->setEnabled(true);
    }
    if(ui->checkBox_isjiujingPID->isChecked()){
        isjiujingPID=true;
    }
    else isjiujingPID=false;
}

void MainWindow::minutefresh()
{
    int start=start_time.toTime_t();
    int now=QDateTime::currentDateTime().toTime_t();
    int run=now-start;
    int h=run/3600;
    int m=(run%3600)/60;
    int s=(run%3600)%60;
    ui->label_runtime->setText("程序运行时间:"+QString::number(h)+"小时"+QString::number(m)+"分钟"+QString::number(s)+"秒");

    //    qDebug()<<run<<h<<m<<s;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->pPBStart->text().contains("开始运行")){
        QMessageBox::warning(this, tr("警告！"),tr("请先开始运行!"),QMessageBox::Yes);
        return;
    }
    if(timers.eventflag==1||timers.eventflag==2){  //!=0&&!=5
        QMessageBox::warning(this, tr("警告！"),tr("请先终止当前标准油实验!"),QMessageBox::Yes);
    }
    else if(timers.eventflag==3){
        QMessageBox::warning(this, tr("警告！"),tr("请先终止当前样品油实验!"),QMessageBox::Yes);
    }
    else{
        ui->pConfTable->setEnabled(true);
        ui->display_flag->setName("仅限调试状态");
        m_Base.sendCTLPkg(CTL_SET_TEMREF,0,-20);   //调试状态,初始温度设置
        m_Base.sendCTLPkg(CTL_SET_TEMREF,1,0);
        timers.eventflag=5;
        timers.tiaoshiflag=0;
    }
}

void MainWindow::upload_send(QString upload_str)
{
    QByteArray append("content=");
    append.append(upload_str.toUtf8().data());
    accessNetwork->post(*networkRequest, append);
}

/*QString MainWindow::upload_record_encode(old_struct *oldone, int record_id)
{
    return QString("{\"type\":2,\"device_id\":%1,\"record_id\":%2,\"experimenter\":\"%3\",\"date\":\"%4\",\"time\":\"%5\",\"set_temprassure\":\"%6\",\"max_pressure\":\"%7\",\"max_pre_timepoint\":\"%8\",\"dec_pre_timepoint\":\"%9\",\"oxidation_period\":\"%10\"}")\
            .arg(ui->pLEDevID->text()).arg(record_id).arg(oldone->experimenter).arg(oldone->date).arg(oldone->time).arg(oldone->set_temperature).arg(oldone->max_pressure).arg(oldone->max_pre_timepoint).arg(oldone->dec_pre_timepoint).arg(oldone->oxidation_period);
}*/
// 对content 内容进行加密 dev_id与f410@f410.com对原content进行md5加密 考虑到服务器端负载问题 暂时未加入
//QString MainWindow::upload_encrypt(QString oldstr, int dev_id) {
//    QByteArray hash_byte_array = QCryptographicHash::hash(byte_array, QCryptographicHash::Md5);
//    byte_file.append(hash_byte_array.toHex());
//}

void MainWindow::screen_video()
{
    //    bool k=QProcess::startDetached("E:/tlxsoft/屏录专家.exe",QStringList());//注意改成相对位置  \\和/一样？
    bool k=QProcess::startDetached(QCoreApplication::applicationDirPath()+"/tlxsoft/屏录专家.exe",QStringList());
    logError(QCoreApplication::applicationDirPath()+"/tlxsoft/屏录专家.exe");
    if(!k)
        QMessageBox::warning(this, tr("提示"),tr("未在相应位置找到软件"),QMessageBox::Yes);
    else
        isopenexe=true;
    //    QMessageBox msg1(QMessageBox::NoIcon, "录屏步骤", "");
    //    msg1.setIconPixmap(QPixmap("tip1.png"));
    //    msg1.exec();
    //    QMessageBox msg2(QMessageBox::NoIcon, "录屏步骤", "");
    //    msg2.setIconPixmap(QPixmap("tip2.png"));
    //    msg2.exec();
}


void MainWindow::on_pushButton_enable_clicked()
{
    for(int i=0;i<6;i++){
        para[i]->pComboBox->setEnabled(true);
    }
    for(int i=1;i<3;i++){
        para_tem_test[i]->pComboBox->setEnabled(true);
    }
}

void MainWindow::disabled()
{
    for(int i=0;i<6;i++){
        para[i]->pComboBox->setDisabled(true);
    }
    for(int i=1;i<3;i++){
        para_tem_test[i]->pComboBox->setDisabled(true);
    }
}

void MainWindow::changeTableRowBackgroundColor(int table, int rowNum)
{
/*    int col = ui->viscositytable->columnCount();
    int row = ui->viscositytable->rowCount();
    QTableWidgetItem *item = NULL;
    QTableWidget *tableWidget = NULL;
    // 判断rowNum是否超过范围 rowNum==-1时将所有背景色去掉
    if (rowNum > row || rowNum < -1)
        return;

    if (table == 1)
        tableWidget = ui->viscositytable;
    else
        return;

    if (tableWidget == NULL)
        return;

    // 先将所有背景色都去掉
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            item = tableWidget->item(i, j);
            if (item != NULL)
                item->setBackgroundColor(QColor(255, 255, 255));
        }
    }

    if (rowNum != -1)
    {
        // 再对特定行加上颜色
        for (int i = 0; i < col; i++)
        {
            item = tableWidget->item(rowNum, i);
            if (item != NULL)
                item->setBackgroundColor(QColor(180, 180, 0));
        }
    }*/
}

// 实验结束后向汇总表中填充数据
void MainWindow::setTestResult(bool isRecord)
{
    int row = 0;
    QTableWidget *QTW;
    QDateTime time = QDateTime::currentDateTime();

    QTW = ui->standard_revtable;

    // 找到要填充的行 根据第8列和第9列最后被填充的行数来决定 如果相等 则向下一行填充 如果不等 则优先填满最下面那行
    for (int i = 0; i < QTW->rowCount(); ++i)
    {
        if (QTW->item(i, 0) == NULL)
        {
            row = i;
            break;
        }

        if (i == QTW->rowCount() - 1)
        {
            row = i+1;
            QTW->insertRow(i+1);
            QTW->insertRow(i+2);
            continue;
        }
    }

    if(isRecord)
    {
        // 前面的公共信息还未填充
        // 油样编号
        QTW->setItem(row, 0, new QTableWidgetItem(ui->testoil_num->text()));
        // 油样批号
        QTW->setItem(row, 1, new QTableWidgetItem(ui->record_id->text()));
        // 测试员
        QTW->setItem(row, 2, new QTableWidgetItem(ui->experimenter->text()));
        // 日期
        QTW->setItem(row, 3, new QTableWidgetItem(time.toString("yyyy-MM-dd")));
        // 时间
        QTW->setItem(row, 4, new QTableWidgetItem(time.toString("hh:mm:ss")));
        // 设置温度
        QTW->setItem(row, 5, new QTableWidgetItem(QString::number(total_process_state.TargetStage.TargetTemperature)));
        // 最大压强
        QTW->setItem(row, 6, new QTableWidgetItem(QString::number(paraTable9171Content.MaxPressure)));
        // 到达最大压强时间点
        QTW->setItem(row, 7, new QTableWidgetItem(paraTable9171Content.MaxPressureTime));
        // 降压175kPa时间点
        QTW->setItem(row, 8, new QTableWidgetItem(paraTable9171Content.Down175PressureTime));
        // 油样氧化寿命
        QTW->setItem(row, 9, new QTableWidgetItem(paraTable9171Content.OxidationPeriod));
        // 油样二编号
        QTW->setItem(row+1, 0, new QTableWidgetItem(ui->testoil2_num->text()));
        //油样批号
        QTW->setItem(row+1, 1, new QTableWidgetItem(ui->record_id->text()));
        // 测试员
        QTW->setItem(row+1, 2, new QTableWidgetItem(ui->experimenter2->text()));
        // 日期
        QTW->setItem(row+1, 3, new QTableWidgetItem(time.toString("yyyy-MM-dd")));
        // 时间
        QTW->setItem(row+1, 4, new QTableWidgetItem(time.toString("hh:mm:ss")));
        // 设置温度
        QTW->setItem(row+1, 5, new QTableWidgetItem(QString::number(total_process_state2.TargetStage.TargetTemperature)));
        // 最大压强
        QTW->setItem(row+1, 6, new QTableWidgetItem(QString::number(paraTable9171Content2.MaxPressure)));
        // 到达最大压强时间点
        QTW->setItem(row+1, 7, new QTableWidgetItem(paraTable9171Content2.MaxPressureTime));
        // 降压175kPa时间点
        QTW->setItem(row+1, 8, new QTableWidgetItem(paraTable9171Content2.Down175PressureTime));
        // 油样氧化寿命
        QTW->setItem(row+1, 9, new QTableWidgetItem(paraTable9171Content2.OxidationPeriod));
    }
    SQLOPERATE sql;
    sql.r_one.number = QTW->item(row,0)->text();
    sql.r_one.record_num = QTW->item(row,1)->text();
    sql.r_one.staff = QTW->item(row,2)->text();
    sql.r_one.date = QTW->item(row,3)->text();
    sql.r_one.time = QTW->item(row,4)->text();
    sql.r_one.set_temperature = QTW->item(row,5)->text();
    sql.r_one.max_pressure = QTW->item(row,6)->text();
    sql.r_one.max_pre_timepoint = QTW->item(row,7)->text();
    sql.r_one.dec_pre_timepoint = QTW->item(row,8)->text();
    sql.r_one.oxidation_period = QTW->item(row,9)->text();
    sql.insert_result_record(&sql.r_one);
    sql.r_one.number = QTW->item(row+1,0)->text();
    sql.r_one.record_num = QTW->item(row+1,1)->text();
    sql.r_one.staff = QTW->item(row+1,2)->text();
    sql.r_one.date = QTW->item(row+1,3)->text();
    sql.r_one.time = QTW->item(row+1,4)->text();
    sql.r_one.set_temperature = QTW->item(row+1,5)->text();
    sql.r_one.max_pressure = QTW->item(row+1,6)->text();
    sql.r_one.max_pre_timepoint = QTW->item(row+1,7)->text();
    sql.r_one.dec_pre_timepoint = QTW->item(row+1,8)->text();
    sql.r_one.oxidation_period = QTW->item(row+1,9)->text();
    sql.insert_result_record(&sql.r_one);
}

//    qDebug()<< row9<<"   "<<row10;
    /*
    for (int i = 0; i < ui->sample_revtable->rowCount(); i++)
    {
        qDebug()<<"row count: "+QString::number(ui->sample_revtable->rowCount())+"  i : "+QString::number(i);

//        if (ui->standard_revtable->item(i,0) == NULL || (ui->standard_revtable->item(i,0)&&ui->standard_revtable->item(i,0)->text()==tr("")))
        if (ui->sample_revtable->item(i,0) == NULL)
        {
            qDebug()<<"is null";
            QTableWidgetItem *Item = new QTableWidgetItem();
            ui->sample_revtable->setItem(i, 0, Item);
            ui->sample_revtable->item(i,0)->setText(QString::number(i));
            break;
        }
        else
            qDebug()<<"zc";

        if (i == ui->sample_revtable->rowCount() - 1)
        {
            qDebug()<<"cz";
            ui->sample_revtable->insertRow(i+1);
            continue;
        }
    }
    */


// 更新UI中启动次数
void MainWindow::setUIStartTimesValue(int startTimes)
{
    if (ui->pConfTable->item(14, 1) == NULL)
    {
        QTableWidgetItem *item = new QTableWidgetItem(startTimes);
        ui->pConfTable->setItem(14, 1, item);
    }
    else
        ui->pConfTable->item(14, 1)->setText(QString::number(startTimes));
}
