#include "display.h"
#include "ui_display.h"

display::display(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);
}
void display::setName(QString name)
{
    ui->note->setText(name);
}

display::~display()
{
    delete ui;
}
