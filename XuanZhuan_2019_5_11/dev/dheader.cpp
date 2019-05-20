#include "dheader.h"
#include "ui_dheader.h"

DHeader::DHeader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DHeader)
{
    ui->setupUi(this);
}
void DHeader::setName(QString name)
{
    ui->note->setText(name);
}
void DHeader::setValue(QString value)
{
    ui->data->setText(value);
}
DHeader::~DHeader()
{
    delete ui;
}
