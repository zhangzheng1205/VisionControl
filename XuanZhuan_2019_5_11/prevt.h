#ifndef PREVT_H
#define PREVT_H

#include <QThread>
#include "gbase.h"
#include "process_file.h"
#include "get_average.h"
#include "app_autoctl.h"
#include "mainwindow.h"
#include <QWaitCondition>


class PrEvt : public QThread  //Process Event
{
    Q_OBJECT
public:
    void ShowDebugInfo();
    explicit PrEvt(QObject *parent = 0);
    ~PrEvt();

    virtual void run();
    void SetPara(struct TotalProcessState *Total,struct STAGE *sta,struct paraTable_9171 *para,int k);

    // 温控函数 原型
    // 降温true/升温false 酒精目标温度 二极板目标温度 电热丝目标温度 程序时间 变化速率(没有要求就是0.0) StageRefValue[][]的两个参数
    bool tempControl(struct TotalProcessState *Total, struct STAGE *sta, struct paraTable_9171 *para, bool isHeating, float alcohol, int duration, float rate, int m, int k);

signals:
    void logd(QString);
    void logButtonRevover(int);
    void clean_stop_ui_recover();
    void logProcess(QString);
    void logProcessComm(QString);
    void logProcessdeeplearning(QString);
    void changeTableRowBackgroundColor(int, int);

    void trigger_fuwei();

public slots:
     void process_event(struct TotalProcessState *Total,struct STAGE *sta,struct paraTable_9171 *para,int k);
private:
    bool isGoing,isRecv;
    struct TotalProcessState *TotalPro;
    struct STAGE *Stage;
    struct paraTable_9171 *Para;
    int num;
};

extern struct PrEvt m_PrEvt;
extern struct PrEvt m_PrEvt2;
extern float testoil_clean_num;
extern float targetTemp;

#endif // PREVT_H
