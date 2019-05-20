#ifndef DPLOT_H
#define DPLOT_H

#include <QWidget>
#include "qcustomplot.h"
#include <QPen>
#include <QBrush>
#include <QList>

namespace Ui {
class DPlot;
}

class DPlot : public QWidget
{
    Q_OBJECT

public:
    explicit DPlot(QWidget *parent = 0);
    ~DPlot();


    void addGraph(QString,QString,QString);
    void addGraph2(QString,QString,QString,QString);
    void addData(float d1,float d2);
    void setYRange(QPoint c1,QPoint c2);
    void saveVector(QVector<float> &vec,QString name);

signals:
    void logd(QString);
public slots:
    void clearGraph(bool);
    void saveGraph(bool);
    void saveData(bool);
private:
    Ui::DPlot *ui;
    QPen *pPen[4];
    QBrush *pBrush[4];
    QVector<float> ch0_data,ch1_data,ch2_data,ch3_data;
    QString ch0_name,ch1_name;

};

#endif // DPLOT_H
