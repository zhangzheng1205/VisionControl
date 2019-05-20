#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QComboBox>
#include <QPushButton>
#include <QTimer>
#include <QDateTime>
#include <QTimerEvent>
#include <QFile>
#include <QTableWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QAction>
#include <QDebug>
#include <ActiveQt/QAxObject>
#include <QMessageBox>
#include <QMenu>
#include <QCursor>
#include <QProcess>
#include <valarray>
#include <stdlib.h>
#include <QtCore/qmath.h>
#include "dcontrol.h"
#include "logindialog.h"
#include "app_autoctl.h"
#include "gbase.h"
#include "get_average.h"
#include "matrix.h"
#include "prevt.h"
#include "process_file.h"
#include "process_matrix.h"
#include "sqloperate.h"
#include "threadprocess.h"
#include "yieldstress.h"
#include <QButtonGroup>
#include <QWaitCondition>
#include <QMutex>

extern float SAMPLING_PERIOD;
extern QWaitCondition tempCtr;
extern QWaitCondition tempCtr2;
extern int rollReqFlag;
extern int rollReqFlag;

namespace Ui {
class MainWindow;
}

//用来存放QWidgetTable paraTable_9171中的数据
struct paraTable_9171 {
    // 时间先用秒存着 显示时转换成 时:分 的形式
    // 1->已赋值 正常显示 0->未赋值 都显示 '\'
    int flag;
    // 总共需要的时间
    int totalTime;
    // 已经进行的时间
    int haveSpent;
    // 当前阶段号
    int nowStage;
    // 当前阶段总时间
    int nowStageTotalTime;
    // 当前阶段已经进行的时间
    int nowStageHaveSpend;
    // 是否显示酒精温度的flag
    int oilFlag;
    // 酒精设定温度 实时的目标值
    float oilTemp;
    // 热管温度
    float reguanTemp;
    float MaxPressure;
    float MaxPressurePoint;
    float MaxPressureFresh;
    QString MaxPressureTime;
    QString Down175PressureTime;
    QString OxidationPeriod;
    // QCheckBox选中的项的行id 若==0 表示没有被选中的项
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual void timerEvent(QTimerEvent *);
    struct ptSettemReq readSettem(ptSettemReq st);
    void text_read();
    void debug_paratext_read();
    QString delete_zero(char*);
    void db2show(struct old_struct * stu);


signals:
    void logd();
    void stopSignal();

    // 在主线程中，文件绝对路径获取完之后，通过他调用Table2ExcelA处理以及文件保存操作
    void ExcelFileNameSignal(QString, QTableWidget *, QString);
    void getResult(bool);
    // 设定转动时间 单位秒
    void setRollTime(int);
    // 设定转动脉冲数
    void setRollAngle(int);



public slots:
    void logButtonRevover(int);
    void onPBStart();
    void onBGUpdate(int);
    void logError(QString);
    void logSuccess(QString);
    void logDefault(QString);
    void logNote1(QString);
    void logNote2(QString);
    void updateSampling(struct GSimplingData res);
    void onPBSetWiFi();
    void onPBSetTEM();
    void stopProgram();
    void std_radiobutton_choose();
    void test_radiobutton_choose();
    void boxChange(int);
    void settem2box(QString);
    void std_oilComboBox();
    void test_oilComboBox();
    int findlocation();
   
    void para_tem_test1(int);

    void para_tem_std1(int);

    void logProcess(QString);
    void logProcessComm(QString);
    void logAutoCtrl(QString);
    void logAutoCtrljiujing(QString);

    void accessReply(QNetworkReply*);
    void uploadData();

    // Table2ExcelA 完成后调用
    void Table2ExcelAResult(bool, QString);

    void autofresh();
    void minutefresh();
    void fuwei();
    void reset_struct();

    void changeTableRowBackgroundColor(int, int);

    // 结束试验后向实验汇总表填充数据
    void setTestResult(bool);
    // 更新UI中启动次数
    void setUIStartTimesValue(int);

private slots:
    void on_settempushButton_clicked();
    void on_stopButton_clicked();
    void stop();
    void on_rebootButton_clicked();
    void on_enduceButton_clicked();

    void on_testoil_start_clicked();
    void on_stop_std_pushButton_clicked();

    void screen_video();

    void on_xiugaiButton_clicked();
    void on_BJdianji_sent_clicked();
    void on_BJ_open_clicked();
    void shoudongshuru();
    void on_actionShow_S_triggered();
    void on_actionHide_H_triggered();
    void on_action_2_triggered();
    void disabled();
    void on_pushButton_clicked();

    void on_deleteButton_clicked();
    void on_pushButton_enable_clicked();
    void on_searchButton_clicked();
    void on_refreshButton_clicked();

    void on_jisuanButton_clicked();
    void initResultTab();
    void makePlot();
    void makesearchPlot(struct process_struct *, int);
    void on_printButton_clicked();

private:
    Ui::MainWindow *ui;

    QButtonGroup *pBGUpdateCycle;
    Win_QextSerialPort *p_Serial;
    DControl *pKEY[8];
    DControl *pDAC[4];
    DControl *pTEMREF[2];
    DControl *para[8];
    DControl *para_tem_test[3];
    DControl *pREBOOT;
    DControl *para_std[5];
    DControl *para_tem_std[2];    //热管温度，机油温度
    QPen *pPen[4];
    QBrush *pBrush[4];
    QTimer *upload_timer;
    QTimer *upload_timer2;
    QTimer *autofresh_timer;
    QTimer *minute_timer;
    struct GSimplingData need_upload;
    struct GSimplingData need_upload2;
    QNetworkAccessManager* accessNetwork;
    QNetworkRequest *networkRequest;
    bool start_upload = false;
    bool isshow=false;
    QDateTime start_time;
    int mTimerID;
    void initKEYComboBox();
    void initDACComboBox();
    void initTEMREFComboBox();
//    void initREBOOTComboBox();
    void initDELComboBox();
    void loading(bool k);
    void del_fromto();
    QAction *action_del;

    //数据上传需要用到的函数
    //数据编码为json
    QString upload_sampling_encode(struct GSimplingData *);
//    QString upload_record_encode(struct old_struct *, int);
    //数据简单的加密
    QString upload_encrypt(QString, int);
    //数据发送
    void upload_send(QString);
    //采样上传的计数
    int upload_flag = 0;

    // 启动按钮是否灰色


    // 秒 转 时:分:秒 的格式
    QString formatSecond(int);
};

extern float Sampling_flag;
extern int recordFlag[2];
extern struct paraTable_9171 paraTable9171Content;
extern struct paraTable_9171 paraTable9171Content2;

#endif // MAINWINDOW_H
