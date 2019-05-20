#include "dplot.h"
#include "ui_dplot.h"

DPlot::DPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DPlot)
{
    ui->setupUi(this);

    ui->plot->axisRect()->setupFullAxesBox();
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plot->setNoAntialiasingOnDrag(true);
    ui->plot->xAxis->setAutoTickStep(true);
    ui->plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->plot->xAxis->setDateTimeFormat("HH:mm:ss");
    ui->plot->legend->setVisible(true);
    ui->plot->legend->setBrush(QBrush(QColor(0,255,0,0)));

    pPen[0] = new QPen(Qt::blue);
    pPen[1] = new QPen(Qt::red);

    pBrush[0] = new QBrush(QColor(0, 0, 255, 20));
    pBrush[1] = new QBrush(QColor(0, 0, 255, 20));

    connect(ui->pReset,SIGNAL(clicked(bool)),this,SLOT(clearGraph(bool)));
    connect(ui->pSave,SIGNAL(clicked(bool)),this,SLOT(saveGraph(bool)));
    connect(ui->pSaveData,SIGNAL(clicked(bool)),this,SLOT(saveData(bool)));

}

DPlot::~DPlot()
{
    delete ui;
}

void DPlot::addGraph(QString ch1name,QString ch2name,QString no1){
    ch0_name = ch1name;
    ch1_name = ch2name;
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->yAxis->setVisible(true);
    ui->plot->yAxis->setLabel(no1);

    ui->plot->graph(0)->setName(ch1name);
    ui->plot->graph(1)->setName(ch2name);

    ui->plot->graph(0)->setPen(*pPen[0]);
    ui->plot->graph(1)->setPen(*pPen[1]);

    ui->plot->graph(0)->setBrush(*pBrush[0]);
    ui->plot->graph(1)->setBrush(*pBrush[1]);
}
void DPlot::addGraph2(QString ch1name,QString no1,QString ch2name,QString no2){
    ch0_name = ch1name;
    ch1_name = ch2name;
    ui->plot->addGraph(ui->plot->xAxis,ui->plot->yAxis);
    ui->plot->addGraph(ui->plot->xAxis,ui->plot->yAxis2);

    ui->plot->yAxis->setVisible(true);
    ui->plot->yAxis->setLabel(no1);
    ui->plot->yAxis->setSubTickCount(20);
    ui->plot->yAxis2->setVisible(true);
    ui->plot->yAxis2->setLabel(no2);
    ui->plot->yAxis2->setTickLabels(true);
    ui->plot->yAxis2->setSubTickCount(200);

    ui->plot->graph(0)->setName(ch1name);
    ui->plot->graph(1)->setName(ch2name);

    ui->plot->graph(0)->setPen(*pPen[0]);
    ui->plot->graph(1)->setPen(*pPen[1]);

    ui->plot->graph(0)->setBrush(*pBrush[0]);
    ui->plot->graph(1)->setBrush(*pBrush[1]);
}
void DPlot::setYRange(QPoint c1,QPoint c2)
{
    Q_UNUSED(c2);
    ui->plot->yAxis->setRange(c1.x(),c1.y());
    //ui->plot->yAxis2->setRange(c2.x(),c2.y());
}

void DPlot::addData(float d1,float d2)
{
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    ui->plot->graph(0)->addData(key,d1);
    ui->plot->graph(1)->addData(key,d2);
    ch0_data.push_back(d1);
    ch1_data.push_back(d2);

    //ui->plot->rescaleAxes();
    if(ui->checkBox_X->isChecked()){
        ui->plot->xAxis->rescale(true);
    }
    if(ui->checkBox_Y->isChecked()){
        ui->plot->yAxis->rescale(true);
    }
    if(ui->checkBox_Y2->isChecked()){
        ui->plot->yAxis2->rescale(true);
    }
    ui->plot->replot();
}

void DPlot::clearGraph(bool is)
{
    Q_UNUSED(is);
    ui->plot->graph(0)->clearData();
    ui->plot->graph(1)->clearData();
    ch0_data.clear();
    ch1_data.clear();
}

void DPlot::saveGraph(bool is)
{
    Q_UNUSED(is);
    QDateTime time = QDateTime::currentDateTime();
    QString strtime = time.toString("截图/yyyyMMddhhmmss.png");
    ui->plot->savePng(strtime);
    emit logd("save picture to "+strtime);
}

void DPlot::saveData(bool is)
{
    Q_UNUSED(is);
    saveVector(ch0_data,ch0_name);
    saveVector(ch1_data,ch1_name);
}

void DPlot::saveVector(QVector<float> &vec,QString name)
{
    QDateTime time = QDateTime::currentDateTime();
    QString filename = "数据2/" + name + time.toString("-yyyyMMddhhmm") + ".txt";
    QFile file(filename);
    if(file.open(QIODevice::ReadWrite) < 0){
        emit logd("create file Fail:"+filename);
        return;
    }

    for(int i=0; i<vec.length(); i++){
        QString valstr = QString::number(vec.at(i),'f',3);
        file.write(valstr.toLatin1());
        file.write("\r\n");
    }

    file.close();
    emit logd("save data to "+filename);
}
