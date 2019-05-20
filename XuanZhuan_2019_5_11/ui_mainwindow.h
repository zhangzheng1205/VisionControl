/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <dheader.h>
#include <display.h>
#include <display_text.h>
#include <dplot.h>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionShow_S;
    QAction *actionHide_H;
    QAction *action_2;
    QAction *actionHuazhong_Uinversity_of_Science_and_Technology;
    QWidget *centralWidget;
    QGridLayout *gridLayout_17;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QGridLayout *gridLayout_23;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *HL_SERIAL;
    QLabel *label_COM;
    QComboBox *pCom;
    QHBoxLayout *HL_T;
    QLabel *label_T;
    QRadioButton *pRB200ms;
    QRadioButton *pRB500ms;
    QRadioButton *pRB1000ms;
    QHBoxLayout *HL_START;
    QPushButton *pPBStart;
    QHBoxLayout *horizontalLayout_57;
    QLabel *label_17;
    QLabel *label_56;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_53;
    QVBoxLayout *verticalLayout;
    QLabel *equipmentname_lable;
    QLabel *essid_label;
    QLabel *password_label;
    QLabel *label_starttime;
    QLabel *label_runtime;
    QWidget *radiowight;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QRadioButton *testoil;
    QRadioButton *stdoil;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *testoil_num;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_14;
    QLineEdit *experimenter;
    QWidget *oil2table_2;
    QVBoxLayout *oil2table;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_8;
    QLineEdit *testoil2_num;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_10;
    QLineEdit *experimenter2;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_13;
    QLineEdit *record_id;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_16;
    QLineEdit *sampling_period;
    QTableWidget *paraTable_9171;
    QVBoxLayout *verticalLayout_2;
    QPushButton *testoil_start;
    QPushButton *stopButton;
    QPushButton *rebootButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_14;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_13;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_15;
    QWidget *w2;
    QLabel *label_jjjr;
    QLabel *label_jiujinjiare;
    QPlainTextEdit *pLog;
    QPlainTextEdit *pLog_process;
    QGridLayout *gridLayout_2;
    display_text *display_oil_set_tem;
    display *display_flag;
    display_text *display_reguan_ave;
    display_text *display_oil_ave;
    QHBoxLayout *horizontalLayout;
    DHeader *pShowTem1;
    DHeader *pShowTem2;
    DHeader *pShowPre1;
    DHeader *pShowPre2;
    QTabWidget *tabWidget;
    QWidget *pTabTem1;
    QGridLayout *gridLayout_4;
    DPlot *pPlotTem1;
    QWidget *pTabTem2;
    QGridLayout *gridLayout_5;
    DPlot *pPlotTem2;
    QWidget *tab_2;
    QWidget *gridWidget;
    QWidget *resultTab;
    QGridLayout *gridLayout_20;
    QLabel *label_29;
    QGridLayout *gridLayout_9;
    QHBoxLayout *horizontalLayout_46;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_42;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_41;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_48;
    QGridLayout *gridLayout_19;
    QLineEdit *SampleN;
    QPushButton *PlotButton;
    QPushButton *printButton;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *dataTable;
    QSpacerItem *verticalSpacer;
    QPushButton *jisuanButton;
    QLabel *label_27;
    QLineEdit *SampleViscosity2;
    QLineEdit *SampleViscosity;
    QVBoxLayout *verticalLayout_11;
    QCustomPlot *customPlot;
    QWidget *tab_6;
    QGridLayout *gridLayout_24;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_60;
    QTableWidget *standard_revtable;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_6;
    QCustomPlot *searchPlot;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_30;
    QLineEdit *oxidationLine;
    QLineEdit *record_num_search;
    QLineEdit *dateLine;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_15;
    QLabel *label_28;
    QLineEdit *Max_pressureline;
    QLineEdit *oxidationLine2;
    QLabel *label_31;
    QPushButton *searchButton;
    QPushButton *deleteButton;
    QLineEdit *Max_pressureline2;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_13;
    QCheckBox *radioButton_3;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer;
    QPushButton *refreshButton;
    QPushButton *enduceButton;
    QWidget *tab_3;
    QGridLayout *gridLayout_10;
    QWidget *widget_2;
    QGridLayout *gridLayout_22;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_16;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *kplineedit;
    QLabel *label_11;
    QLineEdit *kilineedit;
    QLabel *label_12;
    QLineEdit *kdlineedit;
    QLabel *label_48;
    QLineEdit *Erjiban_Max_lineedit;
    QLabel *label_49;
    QLineEdit *Erjiban_Min_lineedit;
    QLabel *label_50;
    QLineEdit *Erjiban_MaxErr_lineedit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_18;
    QLineEdit *kplineedit_2;
    QLabel *label_19;
    QLineEdit *kilineedit_2;
    QLabel *label_20;
    QLineEdit *kdlineedit_2;
    QLabel *label_57;
    QLineEdit *Erjiban_Max_lineedit_2;
    QLabel *label_61;
    QLineEdit *Erjiban_Min_lineedit_2;
    QLabel *label_62;
    QLineEdit *Erjiban_MaxErr_lineedit_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_21;
    QLineEdit *kplineedit_3;
    QLabel *label_22;
    QLineEdit *kilineedit_3;
    QLabel *label_23;
    QLineEdit *kdlineedit_3;
    QLabel *label_63;
    QLineEdit *Erjiban_Max_lineedit_3;
    QLabel *label_64;
    QLineEdit *Erjiban_Min_lineedit_3;
    QLabel *label_65;
    QLineEdit *Erjiban_MaxErr_lineedit_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_24;
    QLineEdit *kplineedit_4;
    QLabel *label_25;
    QLineEdit *kilineedit_4;
    QLabel *label_26;
    QLineEdit *kdlineedit_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *nihe_lineEdit;
    QHBoxLayout *horizontalLayout_52;
    QPushButton *settempushButton;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_36;
    QCheckBox *checkBox_isjiujingPID;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_55;
    QLineEdit *jiujing_kp_lineedit;
    QLabel *label_54;
    QLineEdit *jiujing_ki_lineedit;
    QLabel *label_53;
    QLineEdit *jiujing_kd_lineedit;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_6;
    QLineEdit *lineEdit_motor_jiujing_ctl;
    QGroupBox *groupBox_6;
    QTableWidget *pConfTable;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton;
    QLabel *label_5;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_21;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_35;
    QLineEdit *lineEdit_4;
    QLabel *label_38;
    QLineEdit *lineEdit_7;
    QLabel *label_41;
    QLineEdit *lineEdit_10;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_36;
    QLineEdit *lineEdit_5;
    QLabel *label_39;
    QLineEdit *lineEdit_8;
    QLabel *label_42;
    QLineEdit *lineEdit_11;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_37;
    QLineEdit *lineEdit_6;
    QLabel *label_40;
    QLineEdit *lineEdit_9;
    QLabel *label_43;
    QLineEdit *lineEdit_12;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *xiugaiButton;
    QSpacerItem *horizontalSpacer_12;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_37;
    QPushButton *BJ_open;
    QLabel *label_32;
    QLineEdit *BJ_bianhao;
    QLabel *label_44;
    QLineEdit *BJ_fangxiang;
    QPushButton *BJdianji_sent;
    QPushButton *BJ_RESET;
    QGroupBox *groupBox_8;
    QPushButton *pushButton_enable;
    QGroupBox *groupBox;
    QLabel *label_arm_in;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *pLEWiFiEssid;
    QLabel *label_2;
    QLineEdit *pLEWiFiPassword;
    QLabel *label_DEVID;
    QLineEdit *pLEDevID;
    QLabel *label_3;
    QLineEdit *Config_Password;
    QHBoxLayout *HL_DEVID;
    QPushButton *pPBWiFiSet;
    QWidget *tab_4;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_13;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *paraTable_2;
    QPushButton *cleanButton;
    QPushButton *startStdoilButton;
    QPushButton *stop_std_pushButton;
    QCheckBox *radioButton_1;
    QCheckBox *radioButton_2;
    QPushButton *calculateButton;
    QPushButton *educeButton;
    QRadioButton *stdoil_2;
    QTableWidget *paraTable;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_IOT;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1100, 811);
        MainWindow->setMinimumSize(QSize(1100, 800));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/login/res/hust.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionShow_S = new QAction(MainWindow);
        actionShow_S->setObjectName(QString::fromUtf8("actionShow_S"));
        actionHide_H = new QAction(MainWindow);
        actionHide_H->setObjectName(QString::fromUtf8("actionHide_H"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        actionHuazhong_Uinversity_of_Science_and_Technology = new QAction(MainWindow);
        actionHuazhong_Uinversity_of_Science_and_Technology->setObjectName(QString::fromUtf8("actionHuazhong_Uinversity_of_Science_and_Technology"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_17 = new QGridLayout(centralWidget);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setEnabled(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_23 = new QGridLayout(tab);
        gridLayout_23->setSpacing(6);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        HL_SERIAL = new QHBoxLayout();
        HL_SERIAL->setSpacing(6);
        HL_SERIAL->setObjectName(QString::fromUtf8("HL_SERIAL"));
        label_COM = new QLabel(tab);
        label_COM->setObjectName(QString::fromUtf8("label_COM"));

        HL_SERIAL->addWidget(label_COM);

        pCom = new QComboBox(tab);
        pCom->setObjectName(QString::fromUtf8("pCom"));

        HL_SERIAL->addWidget(pCom);

        HL_SERIAL->setStretch(0, 1);
        HL_SERIAL->setStretch(1, 3);

        verticalLayout_14->addLayout(HL_SERIAL);

        HL_T = new QHBoxLayout();
        HL_T->setSpacing(0);
        HL_T->setObjectName(QString::fromUtf8("HL_T"));
        label_T = new QLabel(tab);
        label_T->setObjectName(QString::fromUtf8("label_T"));

        HL_T->addWidget(label_T);

        pRB200ms = new QRadioButton(tab);
        pRB200ms->setObjectName(QString::fromUtf8("pRB200ms"));
        pRB200ms->setEnabled(false);

        HL_T->addWidget(pRB200ms);

        pRB500ms = new QRadioButton(tab);
        pRB500ms->setObjectName(QString::fromUtf8("pRB500ms"));
        pRB500ms->setChecked(true);

        HL_T->addWidget(pRB500ms);

        pRB1000ms = new QRadioButton(tab);
        pRB1000ms->setObjectName(QString::fromUtf8("pRB1000ms"));
        pRB1000ms->setEnabled(false);
        pRB1000ms->setChecked(false);

        HL_T->addWidget(pRB1000ms);


        verticalLayout_14->addLayout(HL_T);

        HL_START = new QHBoxLayout();
        HL_START->setSpacing(6);
        HL_START->setObjectName(QString::fromUtf8("HL_START"));
        pPBStart = new QPushButton(tab);
        pPBStart->setObjectName(QString::fromUtf8("pPBStart"));

        HL_START->addWidget(pPBStart);


        verticalLayout_14->addLayout(HL_START);

        horizontalLayout_57 = new QHBoxLayout();
        horizontalLayout_57->setSpacing(6);
        horizontalLayout_57->setObjectName(QString::fromUtf8("horizontalLayout_57"));
        label_17 = new QLabel(tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_57->addWidget(label_17);

        label_56 = new QLabel(tab);
        label_56->setObjectName(QString::fromUtf8("label_56"));

        horizontalLayout_57->addWidget(label_56);


        verticalLayout_14->addLayout(horizontalLayout_57);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_53 = new QHBoxLayout(groupBox_2);
        horizontalLayout_53->setSpacing(0);
        horizontalLayout_53->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_53->setObjectName(QString::fromUtf8("horizontalLayout_53"));
        horizontalLayout_53->setContentsMargins(0, 5, 0, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        equipmentname_lable = new QLabel(groupBox_2);
        equipmentname_lable->setObjectName(QString::fromUtf8("equipmentname_lable"));

        verticalLayout->addWidget(equipmentname_lable);

        essid_label = new QLabel(groupBox_2);
        essid_label->setObjectName(QString::fromUtf8("essid_label"));

        verticalLayout->addWidget(essid_label);

        password_label = new QLabel(groupBox_2);
        password_label->setObjectName(QString::fromUtf8("password_label"));

        verticalLayout->addWidget(password_label);


        horizontalLayout_53->addLayout(verticalLayout);


        verticalLayout_14->addWidget(groupBox_2);

        label_starttime = new QLabel(tab);
        label_starttime->setObjectName(QString::fromUtf8("label_starttime"));

        verticalLayout_14->addWidget(label_starttime);

        label_runtime = new QLabel(tab);
        label_runtime->setObjectName(QString::fromUtf8("label_runtime"));

        verticalLayout_14->addWidget(label_runtime);

        radiowight = new QWidget(tab);
        radiowight->setObjectName(QString::fromUtf8("radiowight"));
        verticalLayout_4 = new QVBoxLayout(radiowight);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        testoil = new QRadioButton(radiowight);
        testoil->setObjectName(QString::fromUtf8("testoil"));
        testoil->setEnabled(true);
        testoil->setCheckable(true);
        testoil->setChecked(false);

        horizontalLayout_14->addWidget(testoil);

        stdoil = new QRadioButton(radiowight);
        stdoil->setObjectName(QString::fromUtf8("stdoil"));

        horizontalLayout_14->addWidget(stdoil);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(radiowight);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        testoil_num = new QLineEdit(radiowight);
        testoil_num->setObjectName(QString::fromUtf8("testoil_num"));

        horizontalLayout_8->addWidget(testoil_num);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_14 = new QLabel(radiowight);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_19->addWidget(label_14);

        experimenter = new QLineEdit(radiowight);
        experimenter->setObjectName(QString::fromUtf8("experimenter"));

        horizontalLayout_19->addWidget(experimenter);


        verticalLayout_4->addLayout(horizontalLayout_19);


        verticalLayout_14->addWidget(radiowight);

        oil2table_2 = new QWidget(tab);
        oil2table_2->setObjectName(QString::fromUtf8("oil2table_2"));
        oil2table = new QVBoxLayout(oil2table_2);
        oil2table->setSpacing(6);
        oil2table->setContentsMargins(11, 11, 11, 11);
        oil2table->setObjectName(QString::fromUtf8("oil2table"));
        oil2table->setSizeConstraint(QLayout::SetDefaultConstraint);
        oil2table->setContentsMargins(9, 9, 9, 9);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_8 = new QLabel(oil2table_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_15->addWidget(label_8);

        testoil2_num = new QLineEdit(oil2table_2);
        testoil2_num->setObjectName(QString::fromUtf8("testoil2_num"));

        horizontalLayout_15->addWidget(testoil2_num);


        oil2table->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_10 = new QLabel(oil2table_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_16->addWidget(label_10);

        experimenter2 = new QLineEdit(oil2table_2);
        experimenter2->setObjectName(QString::fromUtf8("experimenter2"));

        horizontalLayout_16->addWidget(experimenter2);


        oil2table->addLayout(horizontalLayout_16);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_13 = new QLabel(oil2table_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_21->addWidget(label_13);

        record_id = new QLineEdit(oil2table_2);
        record_id->setObjectName(QString::fromUtf8("record_id"));

        horizontalLayout_21->addWidget(record_id);


        oil2table->addLayout(horizontalLayout_21);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_16 = new QLabel(oil2table_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_9->addWidget(label_16);

        sampling_period = new QLineEdit(oil2table_2);
        sampling_period->setObjectName(QString::fromUtf8("sampling_period"));

        horizontalLayout_9->addWidget(sampling_period);


        oil2table->addLayout(horizontalLayout_9);


        verticalLayout_14->addWidget(oil2table_2);

        paraTable_9171 = new QTableWidget(tab);
        if (paraTable_9171->columnCount() < 3)
            paraTable_9171->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        paraTable_9171->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        paraTable_9171->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        paraTable_9171->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (paraTable_9171->rowCount() < 9)
            paraTable_9171->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        paraTable_9171->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        paraTable_9171->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        paraTable_9171->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        paraTable_9171->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        paraTable_9171->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        paraTable_9171->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        paraTable_9171->setVerticalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        paraTable_9171->setVerticalHeaderItem(7, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        paraTable_9171->setVerticalHeaderItem(8, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        paraTable_9171->setItem(0, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(1, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(1, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(2, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(2, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(3, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(3, 1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(4, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(4, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(5, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(5, 1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(6, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        paraTable_9171->setItem(6, 1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(7, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        paraTable_9171->setItem(7, 1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_9171->setItem(8, 0, __qtablewidgetitem27);
        paraTable_9171->setObjectName(QString::fromUtf8("paraTable_9171"));
        paraTable_9171->setStyleSheet(QString::fromUtf8(""));
        paraTable_9171->setFrameShadow(QFrame::Sunken);
        paraTable_9171->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        paraTable_9171->setTabKeyNavigation(false);
        paraTable_9171->setDragDropMode(QAbstractItemView::DragDrop);
        paraTable_9171->setAlternatingRowColors(true);
        paraTable_9171->setSelectionMode(QAbstractItemView::NoSelection);
        paraTable_9171->setSelectionBehavior(QAbstractItemView::SelectRows);
        paraTable_9171->setRowCount(9);
        paraTable_9171->setColumnCount(3);
        paraTable_9171->horizontalHeader()->setVisible(false);
        paraTable_9171->horizontalHeader()->setDefaultSectionSize(90);
        paraTable_9171->horizontalHeader()->setMinimumSectionSize(1);
        paraTable_9171->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        paraTable_9171->horizontalHeader()->setStretchLastSection(true);
        paraTable_9171->verticalHeader()->setVisible(false);
        paraTable_9171->verticalHeader()->setHighlightSections(false);
        paraTable_9171->verticalHeader()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_14->addWidget(paraTable_9171);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        testoil_start = new QPushButton(tab);
        testoil_start->setObjectName(QString::fromUtf8("testoil_start"));
        testoil_start->setStyleSheet(QString::fromUtf8("/*QPushButton{\n"
"border-radius :8px;\n"
"background : rgb(0, 0, 0);\n"
"color:black;\n"
"font-size:20px\n"
"}*/\n"
"font-size:20px;\n"
"color:rgb(0, 0, 0);\n"
""));

        verticalLayout_2->addWidget(testoil_start);

        stopButton = new QPushButton(tab);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setStyleSheet(QString::fromUtf8("/*QPushButton{\n"
"border-radius :8px;\n"
"background : rgb(153, 153, 229);\n"
"color:black;\n"
"font-size:20px\n"
"}*/\n"
"font-size:20px;\n"
"color:blue;\n"
""));

        verticalLayout_2->addWidget(stopButton);

        rebootButton = new QPushButton(tab);
        rebootButton->setObjectName(QString::fromUtf8("rebootButton"));
        rebootButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius :8px;\n"
"background : rgb(153, 153, 229);\n"
"color:black;\n"
"font-size:20px\n"
"}"));

        verticalLayout_2->addWidget(rebootButton);


        verticalLayout_14->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout_14, 0, 0, 1, 1);

        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 698, 723));
        gridLayout_14 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_13 = new QWidget(widget);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        gridLayout_7 = new QGridLayout(widget_13);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(6);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        w2 = new QWidget(widget_13);
        w2->setObjectName(QString::fromUtf8("w2"));
        label_jjjr = new QLabel(w2);
        label_jjjr->setObjectName(QString::fromUtf8("label_jjjr"));
        label_jjjr->setGeometry(QRect(1, 1, 76, 25));
        label_jjjr->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_jiujinjiare = new QLabel(w2);
        label_jiujinjiare->setObjectName(QString::fromUtf8("label_jiujinjiare"));
        label_jiujinjiare->setGeometry(QRect(100, 6, 16, 16));
        label_jiujinjiare->setStyleSheet(QString::fromUtf8("border-image: url(:/login/res/gray.png);\n"
"border-radius:18px;\n"
"background-color:rgba(255, 255, 255, 100)"));

        gridLayout_15->addWidget(w2, 0, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_15, 0, 0, 1, 1);

        pLog = new QPlainTextEdit(widget_13);
        pLog->setObjectName(QString::fromUtf8("pLog"));
        pLog->setReadOnly(true);

        gridLayout_7->addWidget(pLog, 0, 1, 1, 1);

        pLog_process = new QPlainTextEdit(widget_13);
        pLog_process->setObjectName(QString::fromUtf8("pLog_process"));
        pLog_process->setReadOnly(true);

        gridLayout_7->addWidget(pLog_process, 0, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        display_oil_set_tem = new display_text(widget_13);
        display_oil_set_tem->setObjectName(QString::fromUtf8("display_oil_set_tem"));

        gridLayout_2->addWidget(display_oil_set_tem, 1, 0, 1, 1);

        display_flag = new display(widget_13);
        display_flag->setObjectName(QString::fromUtf8("display_flag"));

        gridLayout_2->addWidget(display_flag, 0, 0, 1, 1);

        display_reguan_ave = new display_text(widget_13);
        display_reguan_ave->setObjectName(QString::fromUtf8("display_reguan_ave"));

        gridLayout_2->addWidget(display_reguan_ave, 3, 0, 1, 1);

        display_oil_ave = new display_text(widget_13);
        display_oil_ave->setObjectName(QString::fromUtf8("display_oil_ave"));

        gridLayout_2->addWidget(display_oil_ave, 2, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_2, 0, 3, 1, 1);

        gridLayout_7->setColumnStretch(0, 1);
        gridLayout_7->setColumnStretch(1, 2);
        gridLayout_7->setColumnStretch(2, 2);
        gridLayout_7->setColumnStretch(3, 1);

        verticalLayout_3->addWidget(widget_13);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_14->addWidget(widget, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pShowTem1 = new DHeader(scrollAreaWidgetContents);
        pShowTem1->setObjectName(QString::fromUtf8("pShowTem1"));

        horizontalLayout->addWidget(pShowTem1);

        pShowTem2 = new DHeader(scrollAreaWidgetContents);
        pShowTem2->setObjectName(QString::fromUtf8("pShowTem2"));

        horizontalLayout->addWidget(pShowTem2);

        pShowPre1 = new DHeader(scrollAreaWidgetContents);
        pShowPre1->setObjectName(QString::fromUtf8("pShowPre1"));

        horizontalLayout->addWidget(pShowPre1);

        pShowPre2 = new DHeader(scrollAreaWidgetContents);
        pShowPre2->setObjectName(QString::fromUtf8("pShowPre2"));

        horizontalLayout->addWidget(pShowPre2);


        gridLayout_14->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(scrollAreaWidgetContents);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Aharoni"));
        font.setPointSize(14);
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        tabWidget->setFont(font);
        tabWidget->setToolTipDuration(-1);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab:selected{\n"
"	color:red;\n"
"}\n"
"QTabBar::tab{\n"
"	color:green;\n"
"	min-width:14ex;\n"
"}"));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(16, 16));
        tabWidget->setElideMode(Qt::ElideNone);
        pTabTem1 = new QWidget();
        pTabTem1->setObjectName(QString::fromUtf8("pTabTem1"));
        gridLayout_4 = new QGridLayout(pTabTem1);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pPlotTem1 = new DPlot(pTabTem1);
        pPlotTem1->setObjectName(QString::fromUtf8("pPlotTem1"));
        pPlotTem1->setToolTipDuration(-4);

        gridLayout_4->addWidget(pPlotTem1, 1, 0, 1, 1);

        tabWidget->addTab(pTabTem1, QString());
        pTabTem2 = new QWidget();
        pTabTem2->setObjectName(QString::fromUtf8("pTabTem2"));
        gridLayout_5 = new QGridLayout(pTabTem2);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        pPlotTem2 = new DPlot(pTabTem2);
        pPlotTem2->setObjectName(QString::fromUtf8("pPlotTem2"));

        gridLayout_5->addWidget(pPlotTem2, 0, 1, 1, 1);

        tabWidget->addTab(pTabTem2, QString());

        gridLayout_14->addWidget(tabWidget, 1, 0, 1, 1);

        gridLayout_14->setRowStretch(0, 1);
        gridLayout_14->setRowStretch(1, 4);
        gridLayout_14->setRowStretch(2, 4);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);

        gridLayout_23->addLayout(gridLayout, 0, 0, 1, 1);

        tabWidget_2->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridWidget = new QWidget(tab_2);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(9, 9, 1061, 731));
        resultTab = new QWidget(gridWidget);
        resultTab->setObjectName(QString::fromUtf8("resultTab"));
        resultTab->setGeometry(QRect(0, 0, 1058, 727));
        resultTab->setMaximumSize(QSize(1058, 727));
        gridLayout_20 = new QGridLayout(resultTab);
        gridLayout_20->setSpacing(6);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        label_29 = new QLabel(resultTab);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_20->addWidget(label_29, 0, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setSpacing(6);
        horizontalLayout_46->setObjectName(QString::fromUtf8("horizontalLayout_46"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_46->addItem(horizontalSpacer_5);


        gridLayout_9->addLayout(horizontalLayout_46, 4, 0, 1, 1);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setSpacing(6);
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_42->addItem(horizontalSpacer_4);


        verticalLayout_15->addLayout(horizontalLayout_42);


        gridLayout_9->addLayout(verticalLayout_15, 3, 0, 1, 1);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setSpacing(6);
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        horizontalLayout_41->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_3);


        gridLayout_9->addLayout(horizontalLayout_41, 1, 0, 1, 1);

        horizontalLayout_48 = new QHBoxLayout();
        horizontalLayout_48->setSpacing(6);
        horizontalLayout_48->setObjectName(QString::fromUtf8("horizontalLayout_48"));
        gridLayout_19 = new QGridLayout();
        gridLayout_19->setSpacing(6);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        SampleN = new QLineEdit(resultTab);
        SampleN->setObjectName(QString::fromUtf8("SampleN"));
        SampleN->setMinimumSize(QSize(320, 0));
        SampleN->setMaximumSize(QSize(320, 20));
        SampleN->setAlignment(Qt::AlignCenter);

        gridLayout_19->addWidget(SampleN, 4, 0, 1, 1);

        PlotButton = new QPushButton(resultTab);
        PlotButton->setObjectName(QString::fromUtf8("PlotButton"));
        PlotButton->setMinimumSize(QSize(320, 0));
        PlotButton->setMaximumSize(QSize(320, 20));

        gridLayout_19->addWidget(PlotButton, 1, 0, 1, 1);

        printButton = new QPushButton(resultTab);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        printButton->setMinimumSize(QSize(320, 0));
        printButton->setMaximumSize(QSize(320, 20));

        gridLayout_19->addWidget(printButton, 8, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_19->addItem(verticalSpacer_2, 2, 0, 1, 1);

        dataTable = new QTableWidget(resultTab);
        if (dataTable->columnCount() < 3)
            dataTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        dataTable->setHorizontalHeaderItem(0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        dataTable->setHorizontalHeaderItem(1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        dataTable->setHorizontalHeaderItem(2, __qtablewidgetitem30);
        if (dataTable->rowCount() < 10)
            dataTable->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        dataTable->setVerticalHeaderItem(0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        dataTable->setVerticalHeaderItem(1, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        dataTable->setVerticalHeaderItem(2, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        dataTable->setVerticalHeaderItem(3, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        dataTable->setVerticalHeaderItem(4, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        dataTable->setVerticalHeaderItem(5, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        dataTable->setVerticalHeaderItem(6, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        dataTable->setVerticalHeaderItem(7, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        dataTable->setVerticalHeaderItem(8, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        dataTable->setVerticalHeaderItem(9, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(0, 0, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(0, 1, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(1, 0, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(1, 1, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(2, 0, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(2, 1, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(3, 0, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(3, 1, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        __qtablewidgetitem49->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(4, 0, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(4, 1, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(5, 0, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        __qtablewidgetitem52->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(5, 1, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        __qtablewidgetitem53->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(6, 0, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setTextAlignment(Qt::AlignCenter);
        dataTable->setItem(6, 1, __qtablewidgetitem54);
        dataTable->setObjectName(QString::fromUtf8("dataTable"));
        dataTable->setMinimumSize(QSize(320, 330));
        dataTable->setMaximumSize(QSize(320, 330));
        dataTable->horizontalHeader()->setHighlightSections(true);
        dataTable->verticalHeader()->setVisible(false);

        gridLayout_19->addWidget(dataTable, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_19->addItem(verticalSpacer, 9, 0, 1, 1);

        jisuanButton = new QPushButton(resultTab);
        jisuanButton->setObjectName(QString::fromUtf8("jisuanButton"));
        jisuanButton->setMinimumSize(QSize(320, 0));
        jisuanButton->setMaximumSize(QSize(320, 20));

        gridLayout_19->addWidget(jisuanButton, 5, 0, 1, 1);

        label_27 = new QLabel(resultTab);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(320, 0));
        label_27->setMaximumSize(QSize(320, 20));

        gridLayout_19->addWidget(label_27, 3, 0, 1, 1);

        SampleViscosity2 = new QLineEdit(resultTab);
        SampleViscosity2->setObjectName(QString::fromUtf8("SampleViscosity2"));
        SampleViscosity2->setMinimumSize(QSize(320, 0));
        SampleViscosity2->setMaximumSize(QSize(320, 20));
        SampleViscosity2->setAlignment(Qt::AlignCenter);

        gridLayout_19->addWidget(SampleViscosity2, 7, 0, 1, 1);

        SampleViscosity = new QLineEdit(resultTab);
        SampleViscosity->setObjectName(QString::fromUtf8("SampleViscosity"));
        SampleViscosity->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SampleViscosity->sizePolicy().hasHeightForWidth());
        SampleViscosity->setSizePolicy(sizePolicy);
        SampleViscosity->setMinimumSize(QSize(320, 0));
        SampleViscosity->setMaximumSize(QSize(320, 20));
        SampleViscosity->setAlignment(Qt::AlignCenter);

        gridLayout_19->addWidget(SampleViscosity, 6, 0, 1, 1);


        horizontalLayout_48->addLayout(gridLayout_19);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_11->setContentsMargins(0, -1, -1, -1);
        customPlot = new QCustomPlot(resultTab);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(48);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy1);
        customPlot->setMinimumSize(QSize(700, 400));

        verticalLayout_11->addWidget(customPlot);


        horizontalLayout_48->addLayout(verticalLayout_11);


        gridLayout_9->addLayout(horizontalLayout_48, 2, 0, 1, 1);


        gridLayout_20->addLayout(gridLayout_9, 1, 0, 1, 1);

        tabWidget_2->addTab(tab_2, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_24 = new QGridLayout(tab_6);
        gridLayout_24->setSpacing(6);
        gridLayout_24->setContentsMargins(11, 11, 11, 11);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setSizeConstraint(QLayout::SetMaximumSize);
        label_60 = new QLabel(tab_6);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setStyleSheet(QString::fromUtf8("/*QPushButton{\n"
"border-radius :8px;\n"
"background : rgb(0, 0, 0);\n"
"color:black;\n"
"font-size:20px\n"
"}*/\n"
"font-size:20px;\n"
"color:rgb(0, 0, 0);"));

        verticalLayout_8->addWidget(label_60);

        standard_revtable = new QTableWidget(tab_6);
        if (standard_revtable->columnCount() < 10)
            standard_revtable->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        standard_revtable->setHorizontalHeaderItem(0, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        standard_revtable->setHorizontalHeaderItem(1, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        standard_revtable->setHorizontalHeaderItem(2, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        standard_revtable->setHorizontalHeaderItem(3, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        standard_revtable->setHorizontalHeaderItem(4, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        standard_revtable->setHorizontalHeaderItem(5, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        standard_revtable->setHorizontalHeaderItem(6, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        standard_revtable->setHorizontalHeaderItem(7, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        standard_revtable->setHorizontalHeaderItem(8, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        standard_revtable->setHorizontalHeaderItem(9, __qtablewidgetitem64);
        if (standard_revtable->rowCount() < 10)
            standard_revtable->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        standard_revtable->setVerticalHeaderItem(0, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        standard_revtable->setVerticalHeaderItem(1, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        standard_revtable->setVerticalHeaderItem(2, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        standard_revtable->setVerticalHeaderItem(3, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        standard_revtable->setVerticalHeaderItem(4, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        standard_revtable->setVerticalHeaderItem(5, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        standard_revtable->setVerticalHeaderItem(6, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        standard_revtable->setVerticalHeaderItem(7, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        standard_revtable->setVerticalHeaderItem(8, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        standard_revtable->setVerticalHeaderItem(9, __qtablewidgetitem74);
        standard_revtable->setObjectName(QString::fromUtf8("standard_revtable"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(standard_revtable->sizePolicy().hasHeightForWidth());
        standard_revtable->setSizePolicy(sizePolicy2);

        verticalLayout_8->addWidget(standard_revtable);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        searchPlot = new QCustomPlot(tab_6);
        searchPlot->setObjectName(QString::fromUtf8("searchPlot"));
        searchPlot->setMinimumSize(QSize(845, 300));

        verticalLayout_6->addWidget(searchPlot);


        horizontalLayout_17->addLayout(verticalLayout_6);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_3, 14, 0, 1, 1);

        label_30 = new QLabel(tab_6);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_30, 7, 0, 1, 1);

        oxidationLine = new QLineEdit(tab_6);
        oxidationLine->setObjectName(QString::fromUtf8("oxidationLine"));
        oxidationLine->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(oxidationLine, 11, 0, 1, 1);

        record_num_search = new QLineEdit(tab_6);
        record_num_search->setObjectName(QString::fromUtf8("record_num_search"));
        record_num_search->setMinimumSize(QSize(0, 0));
        record_num_search->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(record_num_search, 2, 0, 1, 1);

        dateLine = new QLineEdit(tab_6);
        dateLine->setObjectName(QString::fromUtf8("dateLine"));
        dateLine->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(dateLine, 6, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_4, 4, 0, 1, 1);

        label_15 = new QLabel(tab_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy3);
        label_15->setMinimumSize(QSize(0, 20));
        label_15->setMaximumSize(QSize(320, 30));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_15, 1, 0, 1, 1);

        label_28 = new QLabel(tab_6);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_28, 5, 0, 1, 1);

        Max_pressureline = new QLineEdit(tab_6);
        Max_pressureline->setObjectName(QString::fromUtf8("Max_pressureline"));
        Max_pressureline->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(Max_pressureline, 8, 0, 1, 1);

        oxidationLine2 = new QLineEdit(tab_6);
        oxidationLine2->setObjectName(QString::fromUtf8("oxidationLine2"));
        oxidationLine2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(oxidationLine2, 12, 0, 1, 1);

        label_31 = new QLabel(tab_6);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_31, 10, 0, 1, 1);

        searchButton = new QPushButton(tab_6);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setMinimumSize(QSize(0, 30));
        searchButton->setMaximumSize(QSize(320, 20));
        searchButton->setStyleSheet(QString::fromUtf8("font-size:20px;"));

        gridLayout_6->addWidget(searchButton, 3, 0, 1, 1);

        deleteButton = new QPushButton(tab_6);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setMinimumSize(QSize(0, 30));
        deleteButton->setStyleSheet(QString::fromUtf8("font-size:20px;"));

        gridLayout_6->addWidget(deleteButton, 13, 0, 1, 1);

        Max_pressureline2 = new QLineEdit(tab_6);
        Max_pressureline2->setObjectName(QString::fromUtf8("Max_pressureline2"));
        Max_pressureline2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(Max_pressureline2, 9, 0, 1, 1);


        horizontalLayout_17->addLayout(gridLayout_6);


        verticalLayout_8->addLayout(horizontalLayout_17);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        radioButton_3 = new QCheckBox(tab_6);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setMinimumSize(QSize(200, 0));

        verticalLayout_13->addWidget(radioButton_3);


        horizontalLayout_13->addLayout(verticalLayout_13);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer);


        horizontalLayout_13->addLayout(horizontalLayout_18);

        refreshButton = new QPushButton(tab_6);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        refreshButton->setMinimumSize(QSize(200, 0));
        refreshButton->setStyleSheet(QString::fromUtf8("font-size:20px;"));

        horizontalLayout_13->addWidget(refreshButton);

        enduceButton = new QPushButton(tab_6);
        enduceButton->setObjectName(QString::fromUtf8("enduceButton"));
        enduceButton->setMinimumSize(QSize(200, 0));
        enduceButton->setStyleSheet(QString::fromUtf8("font-size:20px;"));

        horizontalLayout_13->addWidget(enduceButton);


        verticalLayout_8->addLayout(horizontalLayout_13);


        gridLayout_24->addLayout(verticalLayout_8, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_6, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_10 = new QGridLayout(tab_3);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        widget_2 = new QWidget(tab_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget#widget_2{\n"
"border:2px solid rgba(199, 199, 199, 237);\n"
" \n"
"border-radius: 5px;\n"
"}"));
        gridLayout_22 = new QGridLayout(widget_2);
        gridLayout_22->setSpacing(6);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        groupBox_5 = new QGroupBox(widget_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_16 = new QGridLayout(groupBox_5);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        kplineedit = new QLineEdit(groupBox_5);
        kplineedit->setObjectName(QString::fromUtf8("kplineedit"));

        horizontalLayout_7->addWidget(kplineedit);

        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_7->addWidget(label_11);

        kilineedit = new QLineEdit(groupBox_5);
        kilineedit->setObjectName(QString::fromUtf8("kilineedit"));

        horizontalLayout_7->addWidget(kilineedit);

        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_7->addWidget(label_12);

        kdlineedit = new QLineEdit(groupBox_5);
        kdlineedit->setObjectName(QString::fromUtf8("kdlineedit"));

        horizontalLayout_7->addWidget(kdlineedit);

        label_48 = new QLabel(groupBox_5);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        horizontalLayout_7->addWidget(label_48);

        Erjiban_Max_lineedit = new QLineEdit(groupBox_5);
        Erjiban_Max_lineedit->setObjectName(QString::fromUtf8("Erjiban_Max_lineedit"));

        horizontalLayout_7->addWidget(Erjiban_Max_lineedit);

        label_49 = new QLabel(groupBox_5);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        horizontalLayout_7->addWidget(label_49);

        Erjiban_Min_lineedit = new QLineEdit(groupBox_5);
        Erjiban_Min_lineedit->setObjectName(QString::fromUtf8("Erjiban_Min_lineedit"));

        horizontalLayout_7->addWidget(Erjiban_Min_lineedit);

        label_50 = new QLabel(groupBox_5);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        horizontalLayout_7->addWidget(label_50);

        Erjiban_MaxErr_lineedit = new QLineEdit(groupBox_5);
        Erjiban_MaxErr_lineedit->setObjectName(QString::fromUtf8("Erjiban_MaxErr_lineedit"));

        horizontalLayout_7->addWidget(Erjiban_MaxErr_lineedit);


        gridLayout_16->addLayout(horizontalLayout_7, 0, 0, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_6->addWidget(label_18);

        kplineedit_2 = new QLineEdit(groupBox_5);
        kplineedit_2->setObjectName(QString::fromUtf8("kplineedit_2"));

        horizontalLayout_6->addWidget(kplineedit_2);

        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_6->addWidget(label_19);

        kilineedit_2 = new QLineEdit(groupBox_5);
        kilineedit_2->setObjectName(QString::fromUtf8("kilineedit_2"));

        horizontalLayout_6->addWidget(kilineedit_2);

        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_6->addWidget(label_20);

        kdlineedit_2 = new QLineEdit(groupBox_5);
        kdlineedit_2->setObjectName(QString::fromUtf8("kdlineedit_2"));

        horizontalLayout_6->addWidget(kdlineedit_2);

        label_57 = new QLabel(groupBox_5);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        horizontalLayout_6->addWidget(label_57);

        Erjiban_Max_lineedit_2 = new QLineEdit(groupBox_5);
        Erjiban_Max_lineedit_2->setObjectName(QString::fromUtf8("Erjiban_Max_lineedit_2"));

        horizontalLayout_6->addWidget(Erjiban_Max_lineedit_2);

        label_61 = new QLabel(groupBox_5);
        label_61->setObjectName(QString::fromUtf8("label_61"));

        horizontalLayout_6->addWidget(label_61);

        Erjiban_Min_lineedit_2 = new QLineEdit(groupBox_5);
        Erjiban_Min_lineedit_2->setObjectName(QString::fromUtf8("Erjiban_Min_lineedit_2"));

        horizontalLayout_6->addWidget(Erjiban_Min_lineedit_2);

        label_62 = new QLabel(groupBox_5);
        label_62->setObjectName(QString::fromUtf8("label_62"));

        horizontalLayout_6->addWidget(label_62);

        Erjiban_MaxErr_lineedit_2 = new QLineEdit(groupBox_5);
        Erjiban_MaxErr_lineedit_2->setObjectName(QString::fromUtf8("Erjiban_MaxErr_lineedit_2"));

        horizontalLayout_6->addWidget(Erjiban_MaxErr_lineedit_2);


        gridLayout_16->addLayout(horizontalLayout_6, 1, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_5->addWidget(label_21);

        kplineedit_3 = new QLineEdit(groupBox_5);
        kplineedit_3->setObjectName(QString::fromUtf8("kplineedit_3"));

        horizontalLayout_5->addWidget(kplineedit_3);

        label_22 = new QLabel(groupBox_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_5->addWidget(label_22);

        kilineedit_3 = new QLineEdit(groupBox_5);
        kilineedit_3->setObjectName(QString::fromUtf8("kilineedit_3"));

        horizontalLayout_5->addWidget(kilineedit_3);

        label_23 = new QLabel(groupBox_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_5->addWidget(label_23);

        kdlineedit_3 = new QLineEdit(groupBox_5);
        kdlineedit_3->setObjectName(QString::fromUtf8("kdlineedit_3"));

        horizontalLayout_5->addWidget(kdlineedit_3);

        label_63 = new QLabel(groupBox_5);
        label_63->setObjectName(QString::fromUtf8("label_63"));

        horizontalLayout_5->addWidget(label_63);

        Erjiban_Max_lineedit_3 = new QLineEdit(groupBox_5);
        Erjiban_Max_lineedit_3->setObjectName(QString::fromUtf8("Erjiban_Max_lineedit_3"));

        horizontalLayout_5->addWidget(Erjiban_Max_lineedit_3);

        label_64 = new QLabel(groupBox_5);
        label_64->setObjectName(QString::fromUtf8("label_64"));

        horizontalLayout_5->addWidget(label_64);

        Erjiban_Min_lineedit_3 = new QLineEdit(groupBox_5);
        Erjiban_Min_lineedit_3->setObjectName(QString::fromUtf8("Erjiban_Min_lineedit_3"));

        horizontalLayout_5->addWidget(Erjiban_Min_lineedit_3);

        label_65 = new QLabel(groupBox_5);
        label_65->setObjectName(QString::fromUtf8("label_65"));

        horizontalLayout_5->addWidget(label_65);

        Erjiban_MaxErr_lineedit_3 = new QLineEdit(groupBox_5);
        Erjiban_MaxErr_lineedit_3->setObjectName(QString::fromUtf8("Erjiban_MaxErr_lineedit_3"));

        horizontalLayout_5->addWidget(Erjiban_MaxErr_lineedit_3);


        gridLayout_16->addLayout(horizontalLayout_5, 2, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_24 = new QLabel(groupBox_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_4->addWidget(label_24);

        kplineedit_4 = new QLineEdit(groupBox_5);
        kplineedit_4->setObjectName(QString::fromUtf8("kplineedit_4"));

        horizontalLayout_4->addWidget(kplineedit_4);

        label_25 = new QLabel(groupBox_5);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_4->addWidget(label_25);

        kilineedit_4 = new QLineEdit(groupBox_5);
        kilineedit_4->setObjectName(QString::fromUtf8("kilineedit_4"));

        horizontalLayout_4->addWidget(kilineedit_4);

        label_26 = new QLabel(groupBox_5);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_4->addWidget(label_26);

        kdlineedit_4 = new QLineEdit(groupBox_5);
        kdlineedit_4->setObjectName(QString::fromUtf8("kdlineedit_4"));

        horizontalLayout_4->addWidget(kdlineedit_4);


        gridLayout_16->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        nihe_lineEdit = new QLineEdit(groupBox_5);
        nihe_lineEdit->setObjectName(QString::fromUtf8("nihe_lineEdit"));

        horizontalLayout_3->addWidget(nihe_lineEdit);


        gridLayout_16->addLayout(horizontalLayout_3, 3, 1, 1, 1);

        horizontalLayout_52 = new QHBoxLayout();
        horizontalLayout_52->setSpacing(6);
        horizontalLayout_52->setObjectName(QString::fromUtf8("horizontalLayout_52"));
        settempushButton = new QPushButton(groupBox_5);
        settempushButton->setObjectName(QString::fromUtf8("settempushButton"));

        horizontalLayout_52->addWidget(settempushButton);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_52->addItem(horizontalSpacer_11);


        gridLayout_16->addLayout(horizontalLayout_52, 5, 0, 1, 1);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        checkBox_isjiujingPID = new QCheckBox(groupBox_5);
        checkBox_isjiujingPID->setObjectName(QString::fromUtf8("checkBox_isjiujingPID"));
        checkBox_isjiujingPID->setCheckable(true);

        horizontalLayout_36->addWidget(checkBox_isjiujingPID);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_55 = new QLabel(groupBox_5);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        horizontalLayout_20->addWidget(label_55);

        jiujing_kp_lineedit = new QLineEdit(groupBox_5);
        jiujing_kp_lineedit->setObjectName(QString::fromUtf8("jiujing_kp_lineedit"));

        horizontalLayout_20->addWidget(jiujing_kp_lineedit);

        label_54 = new QLabel(groupBox_5);
        label_54->setObjectName(QString::fromUtf8("label_54"));

        horizontalLayout_20->addWidget(label_54);

        jiujing_ki_lineedit = new QLineEdit(groupBox_5);
        jiujing_ki_lineedit->setObjectName(QString::fromUtf8("jiujing_ki_lineedit"));

        horizontalLayout_20->addWidget(jiujing_ki_lineedit);

        label_53 = new QLabel(groupBox_5);
        label_53->setObjectName(QString::fromUtf8("label_53"));

        horizontalLayout_20->addWidget(label_53);

        jiujing_kd_lineedit = new QLineEdit(groupBox_5);
        jiujing_kd_lineedit->setObjectName(QString::fromUtf8("jiujing_kd_lineedit"));

        horizontalLayout_20->addWidget(jiujing_kd_lineedit);


        horizontalLayout_36->addLayout(horizontalLayout_20);


        gridLayout_16->addLayout(horizontalLayout_36, 4, 0, 1, 2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_12->addWidget(label_6);

        lineEdit_motor_jiujing_ctl = new QLineEdit(groupBox_5);
        lineEdit_motor_jiujing_ctl->setObjectName(QString::fromUtf8("lineEdit_motor_jiujing_ctl"));

        horizontalLayout_12->addWidget(lineEdit_motor_jiujing_ctl);


        gridLayout_16->addLayout(horizontalLayout_12, 5, 1, 1, 1);


        gridLayout_22->addWidget(groupBox_5, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(widget_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(221, 521));
        pConfTable = new QTableWidget(groupBox_6);
        if (pConfTable->columnCount() < 2)
            pConfTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        pConfTable->setHorizontalHeaderItem(0, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        pConfTable->setHorizontalHeaderItem(1, __qtablewidgetitem76);
        if (pConfTable->rowCount() < 15)
            pConfTable->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(0, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(1, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(2, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(3, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(4, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(5, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(6, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(7, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(8, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(9, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(10, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(11, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(12, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(13, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        pConfTable->setVerticalHeaderItem(14, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        pConfTable->setItem(0, 0, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        pConfTable->setItem(1, 0, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        pConfTable->setItem(2, 0, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        pConfTable->setItem(3, 0, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        pConfTable->setItem(4, 0, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        pConfTable->setItem(5, 0, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        pConfTable->setItem(6, 0, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        pConfTable->setItem(7, 0, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        pConfTable->setItem(8, 0, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        pConfTable->setItem(9, 0, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        pConfTable->setItem(10, 0, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        pConfTable->setItem(11, 0, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        pConfTable->setItem(12, 0, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        pConfTable->setItem(13, 0, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        pConfTable->setItem(14, 0, __qtablewidgetitem106);
        pConfTable->setObjectName(QString::fromUtf8("pConfTable"));
        pConfTable->setEnabled(false);
        pConfTable->setGeometry(QRect(10, 22, 200, 460));
        pConfTable->setMinimumSize(QSize(200, 460));
        pConfTable->setMaximumSize(QSize(200, 460));
        pConfTable->setStyleSheet(QString::fromUtf8(""));
        pConfTable->setFrameShadow(QFrame::Sunken);
        pConfTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        pConfTable->setTabKeyNavigation(false);
        pConfTable->setDragDropMode(QAbstractItemView::DragDrop);
        pConfTable->setAlternatingRowColors(true);
        pConfTable->setSelectionMode(QAbstractItemView::NoSelection);
        pConfTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        pConfTable->setRowCount(15);
        pConfTable->setColumnCount(2);
        pConfTable->horizontalHeader()->setVisible(false);
        pConfTable->horizontalHeader()->setDefaultSectionSize(90);
        pConfTable->horizontalHeader()->setMinimumSectionSize(1);
        pConfTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        pConfTable->horizontalHeader()->setStretchLastSection(true);
        pConfTable->verticalHeader()->setVisible(false);
        pConfTable->verticalHeader()->setHighlightSections(false);
        pConfTable->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        layoutWidget1 = new QWidget(groupBox_6);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 488, 191, 25));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(75, 25));

        horizontalLayout_11->addWidget(pushButton);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_11->addWidget(label_5);


        gridLayout_22->addWidget(groupBox_6, 0, 1, 4, 1);

        groupBox_3 = new QGroupBox(widget_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_21 = new QGridLayout(groupBox_3);
        gridLayout_21->setSpacing(6);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_35 = new QLabel(groupBox_3);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_22->addWidget(label_35);

        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_22->addWidget(lineEdit_4);

        label_38 = new QLabel(groupBox_3);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        horizontalLayout_22->addWidget(label_38);

        lineEdit_7 = new QLineEdit(groupBox_3);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        horizontalLayout_22->addWidget(lineEdit_7);

        label_41 = new QLabel(groupBox_3);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_22->addWidget(label_41);

        lineEdit_10 = new QLineEdit(groupBox_3);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        horizontalLayout_22->addWidget(lineEdit_10);


        verticalLayout_12->addLayout(horizontalLayout_22);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        label_36 = new QLabel(groupBox_3);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        horizontalLayout_27->addWidget(label_36);

        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_27->addWidget(lineEdit_5);

        label_39 = new QLabel(groupBox_3);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        horizontalLayout_27->addWidget(label_39);

        lineEdit_8 = new QLineEdit(groupBox_3);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        horizontalLayout_27->addWidget(lineEdit_8);

        label_42 = new QLabel(groupBox_3);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        horizontalLayout_27->addWidget(label_42);

        lineEdit_11 = new QLineEdit(groupBox_3);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        horizontalLayout_27->addWidget(lineEdit_11);


        verticalLayout_12->addLayout(horizontalLayout_27);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        label_37 = new QLabel(groupBox_3);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        horizontalLayout_32->addWidget(label_37);

        lineEdit_6 = new QLineEdit(groupBox_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_32->addWidget(lineEdit_6);

        label_40 = new QLabel(groupBox_3);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        horizontalLayout_32->addWidget(label_40);

        lineEdit_9 = new QLineEdit(groupBox_3);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        horizontalLayout_32->addWidget(lineEdit_9);

        label_43 = new QLabel(groupBox_3);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        horizontalLayout_32->addWidget(label_43);

        lineEdit_12 = new QLineEdit(groupBox_3);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        horizontalLayout_32->addWidget(lineEdit_12);


        verticalLayout_12->addLayout(horizontalLayout_32);


        gridLayout_21->addLayout(verticalLayout_12, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        xiugaiButton = new QPushButton(groupBox_3);
        xiugaiButton->setObjectName(QString::fromUtf8("xiugaiButton"));

        horizontalLayout_10->addWidget(xiugaiButton);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_12);


        gridLayout_21->addLayout(horizontalLayout_10, 1, 0, 1, 1);


        gridLayout_22->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(widget_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        layoutWidget2 = new QWidget(groupBox_4);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 30, 749, 25));
        horizontalLayout_37 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        horizontalLayout_37->setContentsMargins(0, 0, 0, 0);
        BJ_open = new QPushButton(layoutWidget2);
        BJ_open->setObjectName(QString::fromUtf8("BJ_open"));

        horizontalLayout_37->addWidget(BJ_open);

        label_32 = new QLabel(layoutWidget2);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_37->addWidget(label_32);

        BJ_bianhao = new QLineEdit(layoutWidget2);
        BJ_bianhao->setObjectName(QString::fromUtf8("BJ_bianhao"));

        horizontalLayout_37->addWidget(BJ_bianhao);

        label_44 = new QLabel(layoutWidget2);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        horizontalLayout_37->addWidget(label_44);

        BJ_fangxiang = new QLineEdit(layoutWidget2);
        BJ_fangxiang->setObjectName(QString::fromUtf8("BJ_fangxiang"));

        horizontalLayout_37->addWidget(BJ_fangxiang);

        BJdianji_sent = new QPushButton(layoutWidget2);
        BJdianji_sent->setObjectName(QString::fromUtf8("BJdianji_sent"));

        horizontalLayout_37->addWidget(BJdianji_sent);

        BJ_RESET = new QPushButton(layoutWidget2);
        BJ_RESET->setObjectName(QString::fromUtf8("BJ_RESET"));

        horizontalLayout_37->addWidget(BJ_RESET);


        gridLayout_22->addWidget(groupBox_4, 2, 0, 1, 1);

        groupBox_8 = new QGroupBox(widget_2);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        pushButton_enable = new QPushButton(groupBox_8);
        pushButton_enable->setObjectName(QString::fromUtf8("pushButton_enable"));
        pushButton_enable->setGeometry(QRect(130, 10, 131, 23));

        gridLayout_22->addWidget(groupBox_8, 3, 0, 1, 1);

        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label_arm_in = new QLabel(groupBox);
        label_arm_in->setObjectName(QString::fromUtf8("label_arm_in"));
        label_arm_in->setGeometry(QRect(320, 60, 186, 16));
        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(11, 30, 791, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        pLEWiFiEssid = new QLineEdit(layoutWidget3);
        pLEWiFiEssid->setObjectName(QString::fromUtf8("pLEWiFiEssid"));

        horizontalLayout_2->addWidget(pLEWiFiEssid);

        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        pLEWiFiPassword = new QLineEdit(layoutWidget3);
        pLEWiFiPassword->setObjectName(QString::fromUtf8("pLEWiFiPassword"));

        horizontalLayout_2->addWidget(pLEWiFiPassword);

        label_DEVID = new QLabel(layoutWidget3);
        label_DEVID->setObjectName(QString::fromUtf8("label_DEVID"));
        label_DEVID->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_DEVID);

        pLEDevID = new QLineEdit(layoutWidget3);
        pLEDevID->setObjectName(QString::fromUtf8("pLEDevID"));
        pLEDevID->setCursorPosition(5);

        horizontalLayout_2->addWidget(pLEDevID);

        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        Config_Password = new QLineEdit(layoutWidget3);
        Config_Password->setObjectName(QString::fromUtf8("Config_Password"));
        Config_Password->setMaxLength(32767);
        Config_Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(Config_Password);

        HL_DEVID = new QHBoxLayout();
        HL_DEVID->setSpacing(6);
        HL_DEVID->setObjectName(QString::fromUtf8("HL_DEVID"));

        horizontalLayout_2->addLayout(HL_DEVID);

        pPBWiFiSet = new QPushButton(layoutWidget3);
        pPBWiFiSet->setObjectName(QString::fromUtf8("pPBWiFiSet"));
        pPBWiFiSet->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(pPBWiFiSet);


        gridLayout_22->addWidget(groupBox, 4, 0, 1, 1);


        gridLayout_10->addWidget(widget_2, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        layoutWidget = new QWidget(tab_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 80, 260, 486));
        gridLayout_13 = new QGridLayout(layoutWidget);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setVerticalSpacing(21);
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(8);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        paraTable_2 = new QTableWidget(layoutWidget);
        if (paraTable_2->columnCount() < 2)
            paraTable_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        paraTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        paraTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem108);
        if (paraTable_2->rowCount() < 8)
            paraTable_2->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        paraTable_2->setVerticalHeaderItem(0, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        paraTable_2->setVerticalHeaderItem(1, __qtablewidgetitem110);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        paraTable_2->setVerticalHeaderItem(2, __qtablewidgetitem111);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        paraTable_2->setVerticalHeaderItem(3, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        paraTable_2->setVerticalHeaderItem(4, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        paraTable_2->setVerticalHeaderItem(5, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        paraTable_2->setVerticalHeaderItem(6, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        paraTable_2->setVerticalHeaderItem(7, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        paraTable_2->setItem(0, 0, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        __qtablewidgetitem118->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable_2->setItem(1, 0, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        paraTable_2->setItem(2, 0, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        paraTable_2->setItem(2, 1, __qtablewidgetitem120);
        QTableWidgetItem *__qtablewidgetitem121 = new QTableWidgetItem();
        paraTable_2->setItem(3, 0, __qtablewidgetitem121);
        QTableWidgetItem *__qtablewidgetitem122 = new QTableWidgetItem();
        paraTable_2->setItem(4, 0, __qtablewidgetitem122);
        QTableWidgetItem *__qtablewidgetitem123 = new QTableWidgetItem();
        paraTable_2->setItem(5, 0, __qtablewidgetitem123);
        QTableWidgetItem *__qtablewidgetitem124 = new QTableWidgetItem();
        paraTable_2->setItem(6, 0, __qtablewidgetitem124);
        QTableWidgetItem *__qtablewidgetitem125 = new QTableWidgetItem();
        paraTable_2->setItem(7, 0, __qtablewidgetitem125);
        paraTable_2->setObjectName(QString::fromUtf8("paraTable_2"));
        paraTable_2->setStyleSheet(QString::fromUtf8(""));
        paraTable_2->setFrameShadow(QFrame::Sunken);
        paraTable_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        paraTable_2->setTabKeyNavigation(false);
        paraTable_2->setDragDropMode(QAbstractItemView::DragDrop);
        paraTable_2->setAlternatingRowColors(true);
        paraTable_2->setSelectionMode(QAbstractItemView::NoSelection);
        paraTable_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        paraTable_2->setRowCount(8);
        paraTable_2->setColumnCount(2);
        paraTable_2->horizontalHeader()->setVisible(false);
        paraTable_2->horizontalHeader()->setDefaultSectionSize(90);
        paraTable_2->horizontalHeader()->setMinimumSectionSize(1);
        paraTable_2->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        paraTable_2->horizontalHeader()->setStretchLastSection(true);
        paraTable_2->verticalHeader()->setVisible(false);
        paraTable_2->verticalHeader()->setHighlightSections(false);
        paraTable_2->verticalHeader()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_5->addWidget(paraTable_2);

        cleanButton = new QPushButton(layoutWidget);
        cleanButton->setObjectName(QString::fromUtf8("cleanButton"));
        cleanButton->setStyleSheet(QString::fromUtf8("font-size:25px;"));

        verticalLayout_5->addWidget(cleanButton);

        startStdoilButton = new QPushButton(layoutWidget);
        startStdoilButton->setObjectName(QString::fromUtf8("startStdoilButton"));
        startStdoilButton->setStyleSheet(QString::fromUtf8("font-size:25px;"));

        verticalLayout_5->addWidget(startStdoilButton);

        stop_std_pushButton = new QPushButton(layoutWidget);
        stop_std_pushButton->setObjectName(QString::fromUtf8("stop_std_pushButton"));
        stop_std_pushButton->setStyleSheet(QString::fromUtf8("font-size:25px;"));

        verticalLayout_5->addWidget(stop_std_pushButton);

        radioButton_1 = new QCheckBox(layoutWidget);
        radioButton_1->setObjectName(QString::fromUtf8("radioButton_1"));

        verticalLayout_5->addWidget(radioButton_1);

        radioButton_2 = new QCheckBox(layoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_5->addWidget(radioButton_2);

        calculateButton = new QPushButton(layoutWidget);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setStyleSheet(QString::fromUtf8("font-size:25px;"));

        verticalLayout_5->addWidget(calculateButton);

        educeButton = new QPushButton(layoutWidget);
        educeButton->setObjectName(QString::fromUtf8("educeButton"));
        educeButton->setStyleSheet(QString::fromUtf8("font-size:25px;"));

        verticalLayout_5->addWidget(educeButton);


        gridLayout_13->addLayout(verticalLayout_5, 1, 0, 1, 1);

        stdoil_2 = new QRadioButton(layoutWidget);
        stdoil_2->setObjectName(QString::fromUtf8("stdoil_2"));

        gridLayout_13->addWidget(stdoil_2, 0, 0, 1, 1);

        paraTable = new QTableWidget(tab_4);
        if (paraTable->columnCount() < 2)
            paraTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem126 = new QTableWidgetItem();
        paraTable->setHorizontalHeaderItem(0, __qtablewidgetitem126);
        QTableWidgetItem *__qtablewidgetitem127 = new QTableWidgetItem();
        paraTable->setHorizontalHeaderItem(1, __qtablewidgetitem127);
        if (paraTable->rowCount() < 9)
            paraTable->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem128 = new QTableWidgetItem();
        paraTable->setVerticalHeaderItem(0, __qtablewidgetitem128);
        QTableWidgetItem *__qtablewidgetitem129 = new QTableWidgetItem();
        paraTable->setVerticalHeaderItem(1, __qtablewidgetitem129);
        QTableWidgetItem *__qtablewidgetitem130 = new QTableWidgetItem();
        paraTable->setVerticalHeaderItem(2, __qtablewidgetitem130);
        QTableWidgetItem *__qtablewidgetitem131 = new QTableWidgetItem();
        paraTable->setVerticalHeaderItem(3, __qtablewidgetitem131);
        QTableWidgetItem *__qtablewidgetitem132 = new QTableWidgetItem();
        paraTable->setVerticalHeaderItem(4, __qtablewidgetitem132);
        QTableWidgetItem *__qtablewidgetitem133 = new QTableWidgetItem();
        paraTable->setVerticalHeaderItem(5, __qtablewidgetitem133);
        QTableWidgetItem *__qtablewidgetitem134 = new QTableWidgetItem();
        paraTable->setVerticalHeaderItem(6, __qtablewidgetitem134);
        QTableWidgetItem *__qtablewidgetitem135 = new QTableWidgetItem();
        paraTable->setVerticalHeaderItem(7, __qtablewidgetitem135);
        QTableWidgetItem *__qtablewidgetitem136 = new QTableWidgetItem();
        paraTable->setVerticalHeaderItem(8, __qtablewidgetitem136);
        QTableWidgetItem *__qtablewidgetitem137 = new QTableWidgetItem();
        __qtablewidgetitem137->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        paraTable->setItem(0, 0, __qtablewidgetitem137);
        QTableWidgetItem *__qtablewidgetitem138 = new QTableWidgetItem();
        paraTable->setItem(1, 0, __qtablewidgetitem138);
        QTableWidgetItem *__qtablewidgetitem139 = new QTableWidgetItem();
        paraTable->setItem(1, 1, __qtablewidgetitem139);
        QTableWidgetItem *__qtablewidgetitem140 = new QTableWidgetItem();
        paraTable->setItem(2, 0, __qtablewidgetitem140);
        QTableWidgetItem *__qtablewidgetitem141 = new QTableWidgetItem();
        paraTable->setItem(3, 0, __qtablewidgetitem141);
        QTableWidgetItem *__qtablewidgetitem142 = new QTableWidgetItem();
        paraTable->setItem(4, 0, __qtablewidgetitem142);
        QTableWidgetItem *__qtablewidgetitem143 = new QTableWidgetItem();
        paraTable->setItem(5, 0, __qtablewidgetitem143);
        QTableWidgetItem *__qtablewidgetitem144 = new QTableWidgetItem();
        paraTable->setItem(6, 0, __qtablewidgetitem144);
        QTableWidgetItem *__qtablewidgetitem145 = new QTableWidgetItem();
        paraTable->setItem(7, 0, __qtablewidgetitem145);
        QTableWidgetItem *__qtablewidgetitem146 = new QTableWidgetItem();
        paraTable->setItem(8, 0, __qtablewidgetitem146);
        paraTable->setObjectName(QString::fromUtf8("paraTable"));
        paraTable->setGeometry(QRect(320, 80, 251, 316));
        paraTable->setStyleSheet(QString::fromUtf8(""));
        paraTable->setFrameShadow(QFrame::Sunken);
        paraTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        paraTable->setTabKeyNavigation(false);
        paraTable->setDragDropMode(QAbstractItemView::DragDrop);
        paraTable->setAlternatingRowColors(true);
        paraTable->setSelectionMode(QAbstractItemView::NoSelection);
        paraTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        paraTable->setRowCount(9);
        paraTable->setColumnCount(2);
        paraTable->horizontalHeader()->setVisible(false);
        paraTable->horizontalHeader()->setDefaultSectionSize(90);
        paraTable->horizontalHeader()->setMinimumSectionSize(1);
        paraTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        paraTable->horizontalHeader()->setStretchLastSection(true);
        paraTable->verticalHeader()->setVisible(false);
        paraTable->verticalHeader()->setHighlightSections(false);
        paraTable->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tabWidget_2->addTab(tab_4, QString());

        gridLayout_17->addWidget(tabWidget_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1100, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_IOT = new QMenu(menuBar);
        menu_IOT->setObjectName(QString::fromUtf8("menu_IOT"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_IOT->menuAction());
        menu->addAction(menu_2->menuAction());
        menu_2->addAction(actionShow_S);
        menu_2->addAction(actionHide_H);
        menu_IOT->addAction(action_2);
        menu_IOT->addSeparator();
        menu_IOT->addAction(actionHuazhong_Uinversity_of_Science_and_Technology);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\217\221\345\212\250\346\234\272\346\262\271\350\241\250\350\247\202\347\262\230\345\272\246\346\265\213\345\256\232\350\275\257\344\273\266(\347\224\265\350\204\221\350\256\276\347\275\256\344\270\272\351\235\236\347\235\241\347\234\240/\344\274\221\347\234\240\346\250\241\345\274\217)", nullptr));
        actionShow_S->setText(QApplication::translate("MainWindow", "Show", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShow_S->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionHide_H->setText(QApplication::translate("MainWindow", "Hide", nullptr));
#ifndef QT_NO_SHORTCUT
        actionHide_H->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+H", nullptr));
#endif // QT_NO_SHORTCUT
        action_2->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\25420190113Wang", nullptr));
#ifndef QT_NO_TOOLTIP
        action_2->setToolTip(QApplication::translate("MainWindow", "\347\211\210\346\234\2541229 wang", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionHuazhong_Uinversity_of_Science_and_Technology->setText(QApplication::translate("MainWindow", "Developed by Wang. F410, WNLO, Huazhong Uinversity of Science and Technology", nullptr));
        label_COM->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\357\274\232", nullptr));
        label_T->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\233\264\346\226\260\345\221\250\346\234\237\357\274\232", nullptr));
        pRB200ms->setText(QApplication::translate("MainWindow", "200ms", nullptr));
        pRB500ms->setText(QApplication::translate("MainWindow", "500ms", nullptr));
        pRB1000ms->setText(QApplication::translate("MainWindow", "1000ms", nullptr));
        pPBStart->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\350\277\220\350\241\214", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\351\223\276\350\267\257\347\212\266\346\200\201\357\274\232", nullptr));
        label_56->setText(QApplication::translate("MainWindow", "\351\223\276\350\267\257\346\255\243\345\270\270", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\236\213\345\217\267\351\205\215\347\275\256", nullptr));
        equipmentname_lable->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\345\220\215\347\247\260\357\274\232\346\227\213\350\275\254\346\260\247\345\274\271", nullptr));
        essid_label->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\345\236\213\345\217\267\357\274\2329171-2001", nullptr));
        password_label->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207ID\357\274\232", nullptr));
        label_starttime->setText(QApplication::translate("MainWindow", "\347\250\213\345\272\217\345\220\257\345\212\250\346\227\266\351\227\264:", nullptr));
        label_runtime->setText(QApplication::translate("MainWindow", "\347\250\213\345\272\217\350\277\233\350\241\214\346\227\266\351\225\277:", nullptr));
        testoil->setText(QApplication::translate("MainWindow", "\346\261\275\350\275\256\346\234\272\346\262\271\357\274\210150C\302\260\357\274\211", nullptr));
        stdoil->setText(QApplication::translate("MainWindow", "\347\273\235\347\274\230\346\262\271\357\274\210140C\302\260\357\274\211", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\346\262\271\346\240\267\344\270\200\347\274\226\345\217\267", nullptr));
        testoil_num->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\345\256\236\351\252\214\345\221\230", nullptr));
        experimenter->setText(QApplication::translate("MainWindow", "test1", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\346\262\271\346\240\267\344\272\214\347\274\226\345\217\267", nullptr));
        testoil2_num->setText(QApplication::translate("MainWindow", "2", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\345\256\236\351\252\214\345\221\230", nullptr));
        experimenter2->setText(QApplication::translate("MainWindow", "test2", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\346\262\271\346\240\267\346\211\271\345\217\267", nullptr));
        record_id->setText(QApplication::translate("MainWindow", "001", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\351\207\207\346\240\267\345\221\250\346\234\237(s)", nullptr));
        sampling_period->setText(QApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem = paraTable_9171->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = paraTable_9171->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = paraTable_9171->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = paraTable_9171->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\346\240\207\351\242\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = paraTable_9171->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "KEY1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = paraTable_9171->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "KEY2", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = paraTable_9171->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "KEY3", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = paraTable_9171->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "KEY4", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = paraTable_9171->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "KEY5", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = paraTable_9171->verticalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "TEMREF0", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = paraTable_9171->verticalHeaderItem(7);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "TEMREF1", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = paraTable_9171->verticalHeaderItem(8);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "\345\244\207\347\224\250", nullptr));

        const bool __sortingEnabled = paraTable_9171->isSortingEnabled();
        paraTable_9171->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem12 = paraTable_9171->item(0, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = paraTable_9171->item(1, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "\346\216\247\346\270\251\347\264\257\350\256\241\346\227\266\351\225\277", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = paraTable_9171->item(2, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "\345\267\262\350\277\233\350\241\214\346\227\266\351\225\277\345\217\212\346\257\224\344\276\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = paraTable_9171->item(3, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\351\230\266\346\256\265\345\247\213\346\270\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = paraTable_9171->item(4, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "\351\230\266\346\256\265\347\273\210\346\270\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = paraTable_9171->item(5, 0);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "\351\230\266\346\256\265\345\256\214\346\210\220\346\257\224\344\276\213%", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = paraTable_9171->item(6, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\346\234\200\351\253\230\345\216\213\345\274\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = paraTable_9171->item(7, 0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "\346\262\271\346\240\267\345\275\223\345\211\215\346\270\251\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = paraTable_9171->item(8, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "\345\244\207\347\224\250", nullptr));
        paraTable_9171->setSortingEnabled(__sortingEnabled);

        testoil_start->setText(QApplication::translate("MainWindow", "\345\256\236\351\252\214\345\274\200\345\247\213", nullptr));
        stopButton->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        rebootButton->setText(QApplication::translate("MainWindow", "\351\207\215\345\220\257", nullptr));
        label_jjjr->setText(QApplication::translate("MainWindow", "\346\262\271\346\240\267\345\212\240\347\203\255", nullptr));
        label_jiujinjiare->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(pTabTem1), QApplication::translate("MainWindow", "\346\262\271\346\240\267\344\270\200\345\233\276\347\244\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTabTem2), QApplication::translate("MainWindow", "\346\262\271\346\240\267\344\272\214\345\233\276\347\244\272", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("MainWindow", "\347\233\221\346\265\213\347\225\214\351\235\242", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\265\213\350\257\225\347\273\223\346\236\234</span></p></body></html>", nullptr));
        SampleN->setText(QApplication::translate("MainWindow", "175", nullptr));
        PlotButton->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\345\233\276\345\203\217", nullptr));
        printButton->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = dataTable->horizontalHeaderItem(0);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = dataTable->horizontalHeaderItem(1);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "\346\262\271\346\240\267\344\270\200\345\216\213\345\274\272(Kpa)", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = dataTable->horizontalHeaderItem(2);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "\346\262\271\346\240\267\344\272\214\345\216\213\345\274\272(Kpa)", nullptr));

        const bool __sortingEnabled1 = dataTable->isSortingEnabled();
        dataTable->setSortingEnabled(false);
        dataTable->setSortingEnabled(__sortingEnabled1);

        jisuanButton->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227\346\260\247\345\214\226\345\257\277\345\221\275", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "                   \350\257\267\350\276\223\345\205\245\346\262\271\346\240\267\345\216\213\351\231\215", nullptr));
        SampleViscosity->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("MainWindow", "\346\265\213\350\257\225\347\273\223\346\236\234\345\210\206\346\236\220", nullptr));
        label_60->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\254\346\260\247\345\274\271\346\225\260\346\215\256\350\241\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = standard_revtable->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "\346\262\271\346\240\267\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = standard_revtable->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "\346\211\271\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = standard_revtable->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\345\221\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = standard_revtable->horizontalHeaderItem(3);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = standard_revtable->horizontalHeaderItem(4);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = standard_revtable->horizontalHeaderItem(5);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\270\251\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = standard_revtable->horizontalHeaderItem(6);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "\345\271\263\347\250\263\345\216\213\345\274\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = standard_revtable->horizontalHeaderItem(7);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "\350\276\276\345\210\260\345\271\263\347\250\263\345\216\213\345\274\272\346\227\266\351\227\264\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = standard_revtable->horizontalHeaderItem(8);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "\345\216\213\351\231\215175kPa\346\227\266\351\227\264\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = standard_revtable->horizontalHeaderItem(9);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "\346\260\247\345\214\226\345\257\277\345\221\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = standard_revtable->verticalHeaderItem(0);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = standard_revtable->verticalHeaderItem(1);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = standard_revtable->verticalHeaderItem(2);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = standard_revtable->verticalHeaderItem(3);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = standard_revtable->verticalHeaderItem(4);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = standard_revtable->verticalHeaderItem(5);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = standard_revtable->verticalHeaderItem(6);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = standard_revtable->verticalHeaderItem(7);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = standard_revtable->verticalHeaderItem(8);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = standard_revtable->verticalHeaderItem(9);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "10", nullptr));
#ifndef QT_NO_TOOLTIP
        standard_revtable->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_30->setText(QApplication::translate("MainWindow", "\345\271\263\347\250\263\345\216\213\345\274\272", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\351\234\200\350\246\201\346\237\245\346\211\276\347\232\204\346\211\271\345\217\267", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "\346\227\245\346\234\237", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "\346\260\247\345\214\226\345\257\277\345\221\275", nullptr));
        searchButton->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        deleteButton->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        radioButton_3->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\350\276\223\345\205\245", nullptr));
        refreshButton->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        enduceButton->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "\346\265\213\350\257\225\346\225\260\346\215\256\346\261\207\346\200\273\350\241\250", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\345\256\232", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "  t>=140   KP", nullptr));
        kplineedit->setText(QApplication::translate("MainWindow", "0.9", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "KI", nullptr));
        kilineedit->setText(QApplication::translate("MainWindow", "0.012", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "KD", nullptr));
        kdlineedit->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_48->setText(QApplication::translate("MainWindow", "Erjiban_Max", nullptr));
        Erjiban_Max_lineedit->setText(QApplication::translate("MainWindow", "4000", nullptr));
        label_49->setText(QApplication::translate("MainWindow", "Erjiban_Min", nullptr));
        Erjiban_Min_lineedit->setText(QApplication::translate("MainWindow", "818", nullptr));
        label_50->setText(QApplication::translate("MainWindow", "Erjiban_MaxErr", nullptr));
        Erjiban_MaxErr_lineedit->setText(QApplication::translate("MainWindow", "3370", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "-25<=t<-15 KP", nullptr));
        kplineedit_2->setText(QApplication::translate("MainWindow", "0.9", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "KI", nullptr));
        kilineedit_2->setText(QApplication::translate("MainWindow", "0.012", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "KD", nullptr));
        kdlineedit_2->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_57->setText(QApplication::translate("MainWindow", "Erjiban_Max", nullptr));
        Erjiban_Max_lineedit_2->setText(QApplication::translate("MainWindow", "4000", nullptr));
        label_61->setText(QApplication::translate("MainWindow", "Erjiban_Min", nullptr));
        Erjiban_Min_lineedit_2->setText(QApplication::translate("MainWindow", "818", nullptr));
        label_62->setText(QApplication::translate("MainWindow", "Erjiban_MaxErr", nullptr));
        Erjiban_MaxErr_lineedit_2->setText(QApplication::translate("MainWindow", "3370", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "   t<-25   KP", nullptr));
        kplineedit_3->setText(QApplication::translate("MainWindow", "0.9", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "KI", nullptr));
        kilineedit_3->setText(QApplication::translate("MainWindow", "0.012", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "KD", nullptr));
        kdlineedit_3->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_63->setText(QApplication::translate("MainWindow", "Erjiban_Max", nullptr));
        Erjiban_Max_lineedit_3->setText(QApplication::translate("MainWindow", "4000", nullptr));
        label_64->setText(QApplication::translate("MainWindow", "Erjiban_Min", nullptr));
        Erjiban_Min_lineedit_3->setText(QApplication::translate("MainWindow", "818", nullptr));
        label_65->setText(QApplication::translate("MainWindow", "Erjiban_MaxErr", nullptr));
        Erjiban_MaxErr_lineedit_3->setText(QApplication::translate("MainWindow", "3370", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\346\270\251\346\216\247\345\200\215\346\225\260:  P*", nullptr));
        kplineedit_4->setText(QApplication::translate("MainWindow", "1.3", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "I*", nullptr));
        kilineedit_4->setText(QApplication::translate("MainWindow", "0.95", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "D*", nullptr));
        kdlineedit_4->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\213\237\345\220\210\347\202\271\346\225\260", nullptr));
        nihe_lineEdit->setText(QApplication::translate("MainWindow", "2", nullptr));
        settempushButton->setText(QApplication::translate("MainWindow", "PID\344\277\256\346\224\271\347\241\256\350\256\244", nullptr));
        checkBox_isjiujingPID->setText(QApplication::translate("MainWindow", "\351\205\222\347\262\276\346\230\257\345\220\246PID\346\216\247\345\210\266", nullptr));
        label_55->setText(QApplication::translate("MainWindow", "Jiu_kp", nullptr));
        jiujing_kp_lineedit->setText(QApplication::translate("MainWindow", "2", nullptr));
        label_54->setText(QApplication::translate("MainWindow", "Jiu_ki", nullptr));
        jiujing_ki_lineedit->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_53->setText(QApplication::translate("MainWindow", "Jiu_kd", nullptr));
        jiujing_kd_lineedit->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\346\265\213\350\275\254\351\200\237\346\227\266\351\205\222\347\262\276\350\241\245\345\201\277", nullptr));
        lineEdit_motor_jiujing_ctl->setText(QApplication::translate("MainWindow", "3210", nullptr));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\350\260\203\350\257\225", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = pConfTable->horizontalHeaderItem(0);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = pConfTable->horizontalHeaderItem(1);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = pConfTable->verticalHeaderItem(0);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWindow", "KEY0", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = pConfTable->verticalHeaderItem(1);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWindow", "KEY1", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = pConfTable->verticalHeaderItem(2);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWindow", "KEY2", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = pConfTable->verticalHeaderItem(3);
        ___qtablewidgetitem49->setText(QApplication::translate("MainWindow", "KEY3", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = pConfTable->verticalHeaderItem(4);
        ___qtablewidgetitem50->setText(QApplication::translate("MainWindow", "KEY4", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = pConfTable->verticalHeaderItem(5);
        ___qtablewidgetitem51->setText(QApplication::translate("MainWindow", "KEY5", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = pConfTable->verticalHeaderItem(6);
        ___qtablewidgetitem52->setText(QApplication::translate("MainWindow", "KEY6", nullptr));
        QTableWidgetItem *___qtablewidgetitem53 = pConfTable->verticalHeaderItem(7);
        ___qtablewidgetitem53->setText(QApplication::translate("MainWindow", "KEY7", nullptr));
        QTableWidgetItem *___qtablewidgetitem54 = pConfTable->verticalHeaderItem(8);
        ___qtablewidgetitem54->setText(QApplication::translate("MainWindow", "DAC0", nullptr));
        QTableWidgetItem *___qtablewidgetitem55 = pConfTable->verticalHeaderItem(9);
        ___qtablewidgetitem55->setText(QApplication::translate("MainWindow", "DAC1", nullptr));
        QTableWidgetItem *___qtablewidgetitem56 = pConfTable->verticalHeaderItem(10);
        ___qtablewidgetitem56->setText(QApplication::translate("MainWindow", "DAC2", nullptr));
        QTableWidgetItem *___qtablewidgetitem57 = pConfTable->verticalHeaderItem(11);
        ___qtablewidgetitem57->setText(QApplication::translate("MainWindow", "DAC3", nullptr));
        QTableWidgetItem *___qtablewidgetitem58 = pConfTable->verticalHeaderItem(12);
        ___qtablewidgetitem58->setText(QApplication::translate("MainWindow", "TEMREF0", nullptr));
        QTableWidgetItem *___qtablewidgetitem59 = pConfTable->verticalHeaderItem(13);
        ___qtablewidgetitem59->setText(QApplication::translate("MainWindow", "TEMREF1", nullptr));
        QTableWidgetItem *___qtablewidgetitem60 = pConfTable->verticalHeaderItem(14);
        ___qtablewidgetitem60->setText(QApplication::translate("MainWindow", "REBOOT", nullptr));

        const bool __sortingEnabled2 = pConfTable->isSortingEnabled();
        pConfTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem61 = pConfTable->item(0, 0);
        ___qtablewidgetitem61->setText(QApplication::translate("MainWindow", "KEY0(\347\224\265\346\234\272)", nullptr));
        QTableWidgetItem *___qtablewidgetitem62 = pConfTable->item(1, 0);
        ___qtablewidgetitem62->setText(QApplication::translate("MainWindow", "KEY1(\351\205\222\347\262\276)", nullptr));
        QTableWidgetItem *___qtablewidgetitem63 = pConfTable->item(2, 0);
        ___qtablewidgetitem63->setText(QApplication::translate("MainWindow", "KEY2(\345\215\212\345\257\274\344\275\223)", nullptr));
        QTableWidgetItem *___qtablewidgetitem64 = pConfTable->item(3, 0);
        ___qtablewidgetitem64->setText(QApplication::translate("MainWindow", "KEY3(\346\270\205\346\264\227)", nullptr));
        QTableWidgetItem *___qtablewidgetitem65 = pConfTable->item(4, 0);
        ___qtablewidgetitem65->setText(QApplication::translate("MainWindow", "KEY4", nullptr));
        QTableWidgetItem *___qtablewidgetitem66 = pConfTable->item(5, 0);
        ___qtablewidgetitem66->setText(QApplication::translate("MainWindow", "KEY5", nullptr));
        QTableWidgetItem *___qtablewidgetitem67 = pConfTable->item(6, 0);
        ___qtablewidgetitem67->setText(QApplication::translate("MainWindow", "KEY6", nullptr));
        QTableWidgetItem *___qtablewidgetitem68 = pConfTable->item(7, 0);
        ___qtablewidgetitem68->setText(QApplication::translate("MainWindow", "KEY7", nullptr));
        QTableWidgetItem *___qtablewidgetitem69 = pConfTable->item(8, 0);
        ___qtablewidgetitem69->setText(QApplication::translate("MainWindow", "DAC0(\344\272\214\346\236\201\346\235\277)", nullptr));
        QTableWidgetItem *___qtablewidgetitem70 = pConfTable->item(9, 0);
        ___qtablewidgetitem70->setText(QApplication::translate("MainWindow", "DAC1(\351\205\222\347\262\276)", nullptr));
        QTableWidgetItem *___qtablewidgetitem71 = pConfTable->item(10, 0);
        ___qtablewidgetitem71->setText(QApplication::translate("MainWindow", "DAC2", nullptr));
        QTableWidgetItem *___qtablewidgetitem72 = pConfTable->item(11, 0);
        ___qtablewidgetitem72->setText(QApplication::translate("MainWindow", "DAC3", nullptr));
        QTableWidgetItem *___qtablewidgetitem73 = pConfTable->item(12, 0);
        ___qtablewidgetitem73->setText(QApplication::translate("MainWindow", "TEM0(\344\272\214\346\236\201\346\235\277)", nullptr));
        QTableWidgetItem *___qtablewidgetitem74 = pConfTable->item(13, 0);
        ___qtablewidgetitem74->setText(QApplication::translate("MainWindow", "TEM1(\351\205\222\347\262\276)", nullptr));
        QTableWidgetItem *___qtablewidgetitem75 = pConfTable->item(14, 0);
        ___qtablewidgetitem75->setText(QApplication::translate("MainWindow", "\351\207\215\345\220\257", nullptr));
        pConfTable->setSortingEnabled(__sortingEnabled2);

        pushButton->setText(QApplication::translate("MainWindow", "\350\260\203\350\257\225\346\216\247\345\210\266", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "(\347\224\250\346\210\267\345\210\207\345\213\277\351\232\217\346\204\217\346\223\215\344\275\234)", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\344\272\214\346\236\201\346\235\277\346\270\251\345\272\246\344\277\256\350\256\242", nullptr));
        label_35->setText(QApplication::translate("MainWindow", "-40\302\260C", nullptr));
        lineEdit_4->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_38->setText(QApplication::translate("MainWindow", "-25\302\260C", nullptr));
        lineEdit_7->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_41->setText(QApplication::translate("MainWindow", "-10\302\260C", nullptr));
        lineEdit_10->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "-35\302\260C", nullptr));
        lineEdit_5->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_39->setText(QApplication::translate("MainWindow", "-20\302\260C", nullptr));
        lineEdit_8->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_42->setText(QApplication::translate("MainWindow", " -5\302\260C", nullptr));
        lineEdit_11->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_37->setText(QApplication::translate("MainWindow", "-30\302\260C", nullptr));
        lineEdit_6->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_40->setText(QApplication::translate("MainWindow", "-15\302\260C", nullptr));
        lineEdit_9->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_43->setText(QApplication::translate("MainWindow", "  0\302\260C", nullptr));
        lineEdit_12->setText(QApplication::translate("MainWindow", "0", nullptr));
        xiugaiButton->setText(QApplication::translate("MainWindow", "\344\272\214\346\236\201\346\235\277\346\270\251\345\272\246\346\240\241\345\207\206", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "BJDJ", nullptr));
        BJ_open->setText(QApplication::translate("MainWindow", "OPEN BJDJ", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "BJDJ x", nullptr));
        label_44->setText(QApplication::translate("MainWindow", "BJDJ y", nullptr));
        BJdianji_sent->setText(QApplication::translate("MainWindow", "SEND", nullptr));
        BJ_RESET->setText(QApplication::translate("MainWindow", "BJ_RESET", nullptr));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Testoil", nullptr));
        pushButton_enable->setText(QApplication::translate("MainWindow", "\346\240\267\345\223\201\346\262\271\345\256\236\351\252\214\346\241\206\344\275\277\350\203\275", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\236\213\345\217\267\351\205\215\347\275\256Refer to WiFi", nullptr));
        label_arm_in->setText(QApplication::translate("MainWindow", "ARM\350\257\273\345\205\245:CCS6538-2XXX;CCS19XXX;", nullptr));
        label->setText(QApplication::translate("MainWindow", "ESSID", nullptr));
        pLEWiFiEssid->setText(QApplication::translate("MainWindow", "CCS6538-2000", nullptr));
        pLEWiFiEssid->setPlaceholderText(QApplication::translate("MainWindow", "ESSID", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "PPWD", nullptr));
        pLEWiFiPassword->setText(QApplication::translate("MainWindow", "CCS19001", nullptr));
        pLEWiFiPassword->setPlaceholderText(QString());
        label_DEVID->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207ID\357\274\232", nullptr));
        pLEDevID->setText(QApplication::translate("MainWindow", "19001", nullptr));
        pLEDevID->setPlaceholderText(QApplication::translate("MainWindow", "\350\256\276\345\244\207ID", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        Config_Password->setInputMask(QString());
        Config_Password->setText(QString());
        Config_Password->setPlaceholderText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        pPBWiFiSet->setText(QApplication::translate("MainWindow", "\351\205\215\347\275\256", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "\350\256\276\347\275\256\351\241\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem76 = paraTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem76->setText(QApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem77 = paraTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem77->setText(QApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem78 = paraTable_2->verticalHeaderItem(0);
        ___qtablewidgetitem78->setText(QApplication::translate("MainWindow", "KEY0", nullptr));
        QTableWidgetItem *___qtablewidgetitem79 = paraTable_2->verticalHeaderItem(1);
        ___qtablewidgetitem79->setText(QApplication::translate("MainWindow", "KEY1", nullptr));
        QTableWidgetItem *___qtablewidgetitem80 = paraTable_2->verticalHeaderItem(2);
        ___qtablewidgetitem80->setText(QApplication::translate("MainWindow", "KEY2", nullptr));
        QTableWidgetItem *___qtablewidgetitem81 = paraTable_2->verticalHeaderItem(3);
        ___qtablewidgetitem81->setText(QApplication::translate("MainWindow", "KEY3", nullptr));
        QTableWidgetItem *___qtablewidgetitem82 = paraTable_2->verticalHeaderItem(4);
        ___qtablewidgetitem82->setText(QApplication::translate("MainWindow", "KEY4", nullptr));
        QTableWidgetItem *___qtablewidgetitem83 = paraTable_2->verticalHeaderItem(5);
        ___qtablewidgetitem83->setText(QApplication::translate("MainWindow", "TEMREF0", nullptr));
        QTableWidgetItem *___qtablewidgetitem84 = paraTable_2->verticalHeaderItem(6);
        ___qtablewidgetitem84->setText(QApplication::translate("MainWindow", "TEMREF1", nullptr));
        QTableWidgetItem *___qtablewidgetitem85 = paraTable_2->verticalHeaderItem(7);
        ___qtablewidgetitem85->setText(QApplication::translate("MainWindow", "TEMREF2", nullptr));

        const bool __sortingEnabled3 = paraTable_2->isSortingEnabled();
        paraTable_2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem86 = paraTable_2->item(0, 0);
        ___qtablewidgetitem86->setText(QApplication::translate("MainWindow", "\346\262\271\346\240\267\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem87 = paraTable_2->item(1, 0);
        ___qtablewidgetitem87->setText(QApplication::translate("MainWindow", "\346\270\205\346\264\227\346\227\266\351\227\264(\347\247\222)", nullptr));
        QTableWidgetItem *___qtablewidgetitem88 = paraTable_2->item(2, 0);
        ___qtablewidgetitem88->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\350\277\220\350\241\214\346\227\266\351\227\264(\347\247\222)", nullptr));
        QTableWidgetItem *___qtablewidgetitem89 = paraTable_2->item(3, 0);
        ___qtablewidgetitem89->setText(QApplication::translate("MainWindow", "\346\270\205\346\264\227\346\254\241\346\225\260(\346\254\241)", nullptr));
        QTableWidgetItem *___qtablewidgetitem90 = paraTable_2->item(4, 0);
        ___qtablewidgetitem90->setText(QApplication::translate("MainWindow", "\345\201\232\346\240\267\346\254\241\346\225\260(\346\254\241)", nullptr));
        QTableWidgetItem *___qtablewidgetitem91 = paraTable_2->item(5, 0);
        ___qtablewidgetitem91->setText(QApplication::translate("MainWindow", "\344\272\214\346\236\201\346\235\277\346\270\251\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem92 = paraTable_2->item(6, 0);
        ___qtablewidgetitem92->setText(QApplication::translate("MainWindow", "\351\205\222\347\262\276\346\270\251\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem93 = paraTable_2->item(7, 0);
        ___qtablewidgetitem93->setText(QApplication::translate("MainWindow", "\346\270\205\346\264\227\346\270\251\345\272\246", nullptr));
        paraTable_2->setSortingEnabled(__sortingEnabled3);

        cleanButton->setText(QApplication::translate("MainWindow", "\346\270\205\346\264\227\345\220\257\345\212\250", nullptr));
        startStdoilButton->setText(QApplication::translate("MainWindow", "\346\240\207\345\207\206\346\262\271\345\220\257\345\212\250", nullptr));
        stop_std_pushButton->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        radioButton_1->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\350\276\223\345\205\245", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\350\276\223\345\205\245", nullptr));
        calculateButton->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\271\266\350\256\241\347\256\227", nullptr));
        educeButton->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        stdoil_2->setText(QApplication::translate("MainWindow", "\346\240\207\345\207\206\346\262\271\357\274\210\350\257\245\346\240\217\345\217\226\346\266\210\357\274\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem94 = paraTable->horizontalHeaderItem(0);
        ___qtablewidgetitem94->setText(QApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem95 = paraTable->horizontalHeaderItem(1);
        ___qtablewidgetitem95->setText(QApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem96 = paraTable->verticalHeaderItem(0);
        ___qtablewidgetitem96->setText(QApplication::translate("MainWindow", "KEY1", nullptr));
        QTableWidgetItem *___qtablewidgetitem97 = paraTable->verticalHeaderItem(1);
        ___qtablewidgetitem97->setText(QApplication::translate("MainWindow", "KEY2", nullptr));
        QTableWidgetItem *___qtablewidgetitem98 = paraTable->verticalHeaderItem(2);
        ___qtablewidgetitem98->setText(QApplication::translate("MainWindow", "KEY3", nullptr));
        QTableWidgetItem *___qtablewidgetitem99 = paraTable->verticalHeaderItem(3);
        ___qtablewidgetitem99->setText(QApplication::translate("MainWindow", "KEY4", nullptr));
        QTableWidgetItem *___qtablewidgetitem100 = paraTable->verticalHeaderItem(4);
        ___qtablewidgetitem100->setText(QApplication::translate("MainWindow", "KEY5", nullptr));
        QTableWidgetItem *___qtablewidgetitem101 = paraTable->verticalHeaderItem(5);
        ___qtablewidgetitem101->setText(QApplication::translate("MainWindow", "KEY6", nullptr));
        QTableWidgetItem *___qtablewidgetitem102 = paraTable->verticalHeaderItem(6);
        ___qtablewidgetitem102->setText(QApplication::translate("MainWindow", "TEMREF0", nullptr));
        QTableWidgetItem *___qtablewidgetitem103 = paraTable->verticalHeaderItem(7);
        ___qtablewidgetitem103->setText(QApplication::translate("MainWindow", "TEMREF1", nullptr));
        QTableWidgetItem *___qtablewidgetitem104 = paraTable->verticalHeaderItem(8);
        ___qtablewidgetitem104->setText(QApplication::translate("MainWindow", "TEMREF2", nullptr));

        const bool __sortingEnabled4 = paraTable->isSortingEnabled();
        paraTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem105 = paraTable->item(0, 0);
        ___qtablewidgetitem105->setText(QApplication::translate("MainWindow", "\346\270\205\346\264\227\346\227\266\351\227\264(\347\247\222)", nullptr));
        QTableWidgetItem *___qtablewidgetitem106 = paraTable->item(1, 0);
        ___qtablewidgetitem106->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\350\277\220\350\241\214\346\227\266\351\227\264{\347\247\222)", nullptr));
        QTableWidgetItem *___qtablewidgetitem107 = paraTable->item(2, 0);
        ___qtablewidgetitem107->setText(QApplication::translate("MainWindow", "\346\270\205\346\264\227\346\254\241\346\225\260(\346\254\241)", nullptr));
        QTableWidgetItem *___qtablewidgetitem108 = paraTable->item(3, 0);
        ___qtablewidgetitem108->setText(QApplication::translate("MainWindow", "\345\201\232\346\240\267\346\254\241\346\225\260(\346\254\241)", nullptr));
        QTableWidgetItem *___qtablewidgetitem109 = paraTable->item(4, 0);
        ___qtablewidgetitem109->setText(QApplication::translate("MainWindow", "\351\235\231\347\275\256\346\227\266\351\227\264(\345\210\206)", nullptr));
        QTableWidgetItem *___qtablewidgetitem110 = paraTable->item(5, 0);
        ___qtablewidgetitem110->setText(QApplication::translate("MainWindow", "\351\231\215\346\270\251\346\227\266\351\227\264(\345\210\206)", nullptr));
        QTableWidgetItem *___qtablewidgetitem111 = paraTable->item(6, 0);
        ___qtablewidgetitem111->setText(QApplication::translate("MainWindow", "\344\272\214\346\236\201\346\235\277\346\270\251\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem112 = paraTable->item(7, 0);
        ___qtablewidgetitem112->setText(QApplication::translate("MainWindow", "\351\205\222\347\262\276\346\270\251\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem113 = paraTable->item(8, 0);
        ___qtablewidgetitem113->setText(QApplication::translate("MainWindow", "\346\270\205\346\264\227\346\270\251\345\272\246", nullptr));
        paraTable->setSortingEnabled(__sortingEnabled4);

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "\344\273\245\345\211\215\344\270\215\347\224\250\346\216\247\344\273\266\345\255\230\346\224\276", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\350\217\234\345\215\225", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256\351\241\265", nullptr));
        menu_IOT->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
