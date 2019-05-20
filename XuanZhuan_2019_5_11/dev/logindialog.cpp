#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowTitle("登录");
    ui->usrLineEdit->setFocus();
    ui->usrLineEdit->setText("1");
    ui->pwdLineEdit->setText("1");
    ui->usrLineEdit->setDisabled(1);
    ui->pwdLineEdit->setDisabled(1);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginbutton_clicked()
{
    if(ui->usrLineEdit->text().trimmed() == tr("1") && ui->pwdLineEdit->text() == tr("1"))
    {
       accept();
    }
    else{
        QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);
        // 清空内容并定位光标
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }
}
