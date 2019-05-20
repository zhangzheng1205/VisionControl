#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小

    ui->widget_3->setDisabled(true);
    ui->widget_4->setDisabled(true);
    ui->widget_5->setDisabled(true);
    ui->widget_6->setDisabled(true);
    ui->widget_7->setDisabled(true);
    ui->widget_8->setDisabled(true);

    setWindowTitle(tr("IOT模拟终端"));
    N=0;
    isrand=false;

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->cbsim->addItem(info.portName());
    }

    connect(ui->pbserial,SIGNAL(clicked(bool)),this,SLOT(onpbserial()));
    connect(&m_Ter,SIGNAL(logTX1(QString)),this,SLOT(logNote3(QString)));
    connect(&m_Ter,SIGNAL(logRX1(QString)),this,SLOT(logNote3(QString)));
    connect(ui->pbalc,SIGNAL(clicked(bool)),this,SLOT(onpboil()));
    connect(ui->pbalc_2,SIGNAL(clicked(bool)),this,SLOT(onpboil2()));
    connect(ui->pushButton,  SIGNAL(clicked(bool)),this,SLOT(onpb1()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(onpb2()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(onpb3()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(onpb4()));
    connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(onpb5()));
    connect(ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(onpb6()));
    connect(ui->pushButton_7,SIGNAL(clicked(bool)),this,SLOT(onpb7()));
    connect(ui->pushButton_8,SIGNAL(clicked(bool)),this,SLOT(onpb8()));
    connect(ui->pushButton_9,SIGNAL(clicked(bool)),this,SLOT(onpb9()));

    timer = new QTimer(this);
    timer->setInterval(100);//0.01ms
    connect(timer,SIGNAL(timeout()),this,SLOT(refresh()));
    timer->start();

    timer2 = new QTimer(this);
    timer2->setInterval(1000);//1000ms
    connect(timer2,SIGNAL(timeout()),this,SLOT(refresh2()));
    timer2->start();

    on_pushButton_for100_clicked();
}

MainWindow::~MainWindow()
{
    m_Ter.stop();
    m_Ter.wait();//解决了退出时出现runtime error
    delete ui;
}

void MainWindow::logNote3(QString log)
{
    QDateTime time = QDateTime::currentDateTime();
    QString strtime = time.toString("[yyyy-MM-dd hh:mm:ss ddd]");
    ui->pLog2->appendHtml("<label>"+ strtime +"<font color=olive size=3>"+ log +"</font></label>");
}

void MainWindow::logDefault1(QString log)
{
    QDateTime time = QDateTime::currentDateTime();
    QString strtime = time.toString("[yyyy-MM-dd hh:mm:ss ddd]");
    ui->pLog2->appendHtml("<label>"+ strtime +"<font color=black size=3>"+ log +"</font></label>");
}

void MainWindow::onpbserial()
{
    if(ui->pbserial->text().contains("打开串口"))
    {
        if(!m_Ter.openSerial(ui->cbsim->currentText())){
            logDefault1("串口未打开！");
            return;
        }
        m_Ter.start();
        m_Ter.flag_a = 0;                     //用于初始化机油,首次运行flag==0
        m_Ter.flag_p[0] = 0;                     //用于初始化二极板,首次运行flag==0
        m_Ter.flag_p[1] = 0;
//        m_Ter.a_switch = 0;                   //用于控制酒精循环开关，1 = on
        m_Ter.r_switch = 0;                   //用于控制热管工作开关，1 = 制热；-1 = 不工作
        m_Ter.oil_temp = ENVIRONMENT_TEMP;  //酒精温度:初始默认为环境温度,发送到上位机
        m_Ter.oil2_temp = ENVIRONMENT_TEMP;  //二极板温度：初始 同上
        m_Ter.oil_pre = INITIAL_PRESSURE;
        m_Ter.oil2_pre = INITIAL_PRESSURE;
//        m_Ter.cold_power = COLD_POWER;      //酒精制冷功率
        m_Ter.heat_power[0] = 0.0;             //酒精的制热模块功率:初始为0
        m_Ter.heat_power[1] = 0.0;
        m_Ter.powerJ = 0.0;                 //热管功率
        m_Ter.flag_enabled[0] = 0;
        m_Ter.flag_enabled[1] = 0;
        m_Ter.m[0] = WEIGHT_a;
        m_Ter.m[1] = WEIGHT_p;
        m_Ter.ratio = ui->lineEdit_7->text().toFloat();
        m_Ter.dianjispeed=ui->lineEdit_8->text().toFloat()*10/3;
        m_Ter.oil_pre=ui->lineEdit_9->text().toFloat();//初始化很关键
        m_Ter.oil2_pre=ui->lineEdit_9->text().toFloat();
        m_Ter.id=ui->lineEdit_10->text().toInt();
        m_Ter.username=ui->lineEdit_12->text();
        m_Ter.password=ui->lineEdit_11->text();

        ui->widget_3->setEnabled(true);
        ui->widget_4->setEnabled(true);
        ui->widget_5->setEnabled(true);
        ui->widget_6->setEnabled(true);
        ui->widget_7->setEnabled(true);
        ui->widget_8->setEnabled(true);
        ui->cbsim->setEnabled(false);
        ui->pbserial->setText("关闭串口");
        ui->setidButton->setDisabled(true);//？？
        ui->lineEdit_10->setDisabled(true);
    }
    else
    {
        m_Ter.stop();
        ui->widget_3->setDisabled(true);
        ui->widget_4->setDisabled(true);
        ui->widget_5->setDisabled(true);
        ui->widget_6->setDisabled(true);
        ui->widget_7->setDisabled(true);
        ui->widget_8->setDisabled(true);
        ui->cbsim->setEnabled(true);
        ui->pbserial->setText("打开串口");
        m_Ter.closeSerial();
    }
}

void MainWindow::onpb1()
{
    m_Ter.flag_enabled[0] = 1;
    m_Ter.enpower[0] = (ui->lineEdit_3->text().toFloat());
    logDefault1("设置油样一热传导功率= " + QString::number(ui->lineEdit_3->text().toFloat())+"W");
}
void MainWindow::onpb2()
{
    m_Ter.flag_enabled[1] = 1;
    m_Ter.enpower[1] = (ui->lineEdit_4->text().toFloat());
    logDefault1("设置油样二热传导功率= " + QString::number(ui->lineEdit_4->text().toFloat())+"W");
}
void MainWindow::onpb3()
{
    m_Ter.flag_enabled[0] = 0;
    logDefault1("油样一恢复自动环境温控");
}
void MainWindow::onpb4()
{
    m_Ter.flag_enabled[1] = 0;
    logDefault1("油样二恢复自动环境温控");
}
void MainWindow::onpboil()
{
    m_Ter.oil_temp = ui->lineEdit->text().toFloat();
    logDefault1("设置油样一温度= " + QString::number(ui->lineEdit->text().toFloat()));
}
void MainWindow::onpboil2()
{
    m_Ter.oil2_temp = ui->lineEdit_2->text().toFloat();
    logDefault1("设置油样二温度= " + QString::number(ui->lineEdit_2->text().toFloat()));
}
void MainWindow::onpb5()
{
    m_Ter.m[0] = ui->lineEdit_5->text().toFloat();
    logDefault1("设置油样一质量= " + QString::number(ui->lineEdit_5->text().toFloat()));
}
void MainWindow::onpb6()
{
    m_Ter.m[1] = ui->lineEdit_6->text().toFloat();
    logDefault1("设置油样二质量= " + QString::number(ui->lineEdit_6->text().toFloat()));
}

void MainWindow::onpb7()
{
    m_Ter.ratio = ui->lineEdit_7->text().toFloat();
    logDefault1("设置时间系数= " + QString::number(ui->lineEdit_7->text().toFloat()));
}

void MainWindow::onpb8()
{
    m_Ter.dianjispeed=ui->lineEdit_8->text().toFloat()*10/3;
    ui->label_11->setText(QString::number(ui->lineEdit_8->text().toFloat()));
    logDefault1("设置转速= " + QString::number(ui->lineEdit_8->text().toFloat())+" r/min");
}

void MainWindow::onpb9()
{
    m_Ter.oil_pre = ui->lineEdit_9->text().toFloat();
    m_Ter.oil2_pre = ui->lineEdit_9->text().toFloat();
    ui->label_41->setText(QString::number(m_Ter.oil_pre));
    logDefault1("设置压强= " + QString::number((ui->lineEdit_9->text().toFloat()))+"Kpa");
}

void MainWindow::refresh()
{
    ui->label_27->setText(QString::number((KE[0])*5) + '%');
    ui->label_28->setText(QString::number((KE[1])*5) + '%');
    ui->label_29->setText(QString::number((KE[2])*5) + '%');
    ui->label_30->setText(QString::number((KE[3])*5) + '%');
    ui->label_31->setText(QString::number((KE[4])*5) + '%');
    ui->label_32->setText(QString::number((KE[5])*5) + '%');
    ui->label_33->setText(QString::number((KE[6])*5) + '%');
    ui->label_34->setText(QString::number((KE[7])*5) + '%');
    ui->label_35->setText(QString::number((DA[0])*5.0/4095,10,2) + 'V');
    ui->label_36->setText(QString::number((DA[1])*5.0/4095,10,2) + 'V');
    ui->label_37->setText(QString::number((DA[2])*5.0/4095,10,2) + 'V');
    ui->label_38->setText(QString::number((DA[3])*5.0/4095,10,2) + 'V');
    ui->label_39->setText(QString::number(TE[0]) + "℃");
    ui->label_40->setText(QString::number(TE[1]) + "℃");
}

void MainWindow::refresh2()
{
    if(isrand)
    {
        N=m_Ter.e_wendu*100;
        srand(QDateTime::currentDateTime().time().second());
        int randNum = rand()%(2*N+1)-N;
        m_Ter.oil_temp+=(float)randNum/100;
        m_Ter.oil2_temp+=(float)randNum/100;
    }
}
void MainWindow::on_setidButton_clicked()
{
    m_Ter.id=ui->lineEdit_10->text().toInt();
}

void MainWindow::on_setuserButton_clicked()
{
    m_Ter.username=ui->lineEdit_12->text();
}

void MainWindow::on_setpwdButton_clicked()
{
    m_Ter.password=ui->lineEdit_11->text();
}

void MainWindow::on_pushButton_11_clicked()
{
    isrand=false;
}

void MainWindow::on_pushButton_for100_clicked()
{
    __Rs=100.3;
    ui->pushButton_for100->setDisabled(1);
    ui->pushButton_for270->setEnabled(1);
}

void MainWindow::on_pushButton_for270_clicked()
{
    __Rs=270;
    ui->pushButton_for270->setDisabled(1);
    ui->pushButton_for100->setEnabled(1);
}
