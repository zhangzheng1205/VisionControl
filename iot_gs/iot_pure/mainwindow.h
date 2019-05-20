#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QTimer>
#include <QTimerEvent>
//第二界面
#include "terminal.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    terminal m_Ter;
public slots:
    void logNote3(QString);
    void logDefault1(QString);
    void onpbserial();
    void onpboil();
    void onpboil2();
    void onpb1();
    void onpb2();
    void onpb3();
    void onpb4();
    void onpb5();
    void onpb6();
    void onpb7();
    void onpb8();
    void onpb9();

    void refresh();
    void refresh2();

//    void updateUI();

private slots:
    void on_setidButton_clicked();

    void on_setuserButton_clicked();

    void on_setpwdButton_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_for100_clicked();

    void on_pushButton_for270_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int N;
    bool isrand;
    QTimer *timer2;
//    int counter;
};

#endif // MAINWINDOW_H
