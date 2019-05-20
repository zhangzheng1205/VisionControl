#include "dcontrol.h"
#include "ui_dcontrol.h"

DControl::DControl(unsigned char iType,unsigned char iChannel,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DControl)
{
    m_Type = iType;
    m_Channel = iChannel;
    ui->setupUi(this);

    pComboBox = ui->comboBox;
    pPushButton = ui->pushButton;

    connect(pPushButton,SIGNAL(clicked(bool)),this,SLOT(onSendCmd(bool)));
    connect(pComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(sendCMD_COB(int)));

}

DControl::~DControl()
{
    delete ui;
}

void DControl::onSendCmd(bool is)
{
    Q_UNUSED(is);

    QStringList list = pComboBox->currentText().split(" ");
    //qDebug()<<list;
    QString val = list.at(0);
    emit sendCTLCMD(m_Type,m_Channel,val.toFloat());
}
void  DControl::sendCMD_COB(int t)
{
    if(t>=0){
        QStringList list = pComboBox->currentText().split(" ");
        //qDebug()<<list;
        QString val = list.at(0);
        emit sendCTLCMD(m_Type,m_Channel,val.toFloat());
    }


}




