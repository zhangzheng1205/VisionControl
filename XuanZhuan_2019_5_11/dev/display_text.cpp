#include "display_text.h"
#include "ui_display_text.h"

display_text::display_text(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::display_text)
{
    ui->setupUi(this);
}

void display_text::setName(QString name)
{
    ui->note->setText(name);
}
void display_text::setColor(QString color)
{
    ui->color->setText(color);
}
void display_text::set_color(QColor _color)
{
    if(_color==Qt::red){
        ui->color->setStyleSheet("color: rgb(255, 0, 0)");
    }
    if(_color==Qt::blue){
        ui->color->setStyleSheet("color: rgb(0, 0, 255)");
    }

    if(_color==Qt::yellow){
        ui->color->setStyleSheet("color: rgb(255, 125, 64)");
    }
    if(_color==Qt::green){
        ui->color->setStyleSheet("color: rgb(0, 255, 127)");
    }
    if(_color==Qt::white){//借用 浅紫色
        ui->color->setStyleSheet("color: rgb(218,112,214)");
    }
    if(_color==Qt::black){//借用 青色
        ui->color->setStyleSheet("color: rgb(30,144,255)");
    }
    if(_color==Qt::gray){//借用 灰色
        ui->color->setStyleSheet("color: rgb(192,192,192)");
    }
}

QString display_text::getColor()
{
    return ui->color->text();
}

display_text::~display_text()
{
    delete ui;
}
