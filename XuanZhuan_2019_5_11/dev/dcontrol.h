#ifndef DCONTROL_H
#define DCONTROL_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QDebug>
#include "iot_pkg.h"
#include "gbase.h"

namespace Ui {
class DControl;
}

class DControl : public QWidget
{
    Q_OBJECT

public:
    explicit DControl(unsigned char,unsigned char,QWidget *parent = 0);
    ~DControl();
    QComboBox *pComboBox;
    QPushButton *pPushButton;
signals:
    void sendCTLCMD(int,int,float);
public slots:
    void onSendCmd(bool);
    void sendCMD_COB(int);
private:
    Ui::DControl *ui;
    unsigned char m_Type,m_Channel;
};

#endif // DCONTROL_H
