/********************************************************************************
** Form generated from reading UI file 'dplot.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPLOT_H
#define UI_DPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_DPlot
{
public:
    QHBoxLayout *horizontalLayout;
    QCustomPlot *plot;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pReset;
    QPushButton *pSave;
    QPushButton *pSaveData;
    QCheckBox *checkBox_X;
    QCheckBox *checkBox_Y;
    QCheckBox *checkBox_Y2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DPlot)
    {
        if (DPlot->objectName().isEmpty())
            DPlot->setObjectName(QString::fromUtf8("DPlot"));
        DPlot->resize(695, 457);
        horizontalLayout = new QHBoxLayout(DPlot);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        plot = new QCustomPlot(DPlot);
        plot->setObjectName(QString::fromUtf8("plot"));

        horizontalLayout->addWidget(plot);

        verticalWidget = new QWidget(DPlot);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton {\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgba(0, 255, 0, 250);\n"
"	background-color: rgba(85, 0, 255, 100);\n"
"	width: 60px;\n"
"    height: 30px;\n"
"	border-radius:10px;\n"
"	border: 0px solid red;\n"
"}\n"
"QPushButton:hover:!pressed{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgba(0, 255, 0, 250);\n"
"	background-color: rgba(85, 0, 255, 200);\n"
"}\n"
"QPushButton:hover:pressed{\n"
"	\n"
"	font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgba(0, 255, 0, 250);\n"
"	background-color: rgba(85, 0, 255, 150);\n"
"}\n"
"QCheckBox\n"
"{\n"
"	color: rgba(0, 0, 255, 180);\n"
"	background-color: rgba(255, 255, 255, 150);\n"
"    font-family:Consolas;\n"
"    height:30px;\n"
"    font-size:14px;\n"
"    border-radius:5px;\n"
"}\n"
"QCheckBox::indicator\n"
"{\n"
"	width: 20px;\n"
"    height: 20px;\n"
"}"));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, -1);
        pReset = new QPushButton(verticalWidget);
        pReset->setObjectName(QString::fromUtf8("pReset"));

        verticalLayout->addWidget(pReset);

        pSave = new QPushButton(verticalWidget);
        pSave->setObjectName(QString::fromUtf8("pSave"));

        verticalLayout->addWidget(pSave);

        pSaveData = new QPushButton(verticalWidget);
        pSaveData->setObjectName(QString::fromUtf8("pSaveData"));

        verticalLayout->addWidget(pSaveData);

        checkBox_X = new QCheckBox(verticalWidget);
        checkBox_X->setObjectName(QString::fromUtf8("checkBox_X"));
        checkBox_X->setChecked(true);

        verticalLayout->addWidget(checkBox_X);

        checkBox_Y = new QCheckBox(verticalWidget);
        checkBox_Y->setObjectName(QString::fromUtf8("checkBox_Y"));
        checkBox_Y->setChecked(true);

        verticalLayout->addWidget(checkBox_Y);

        checkBox_Y2 = new QCheckBox(verticalWidget);
        checkBox_Y2->setObjectName(QString::fromUtf8("checkBox_Y2"));
        checkBox_Y2->setChecked(true);

        verticalLayout->addWidget(checkBox_Y2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(verticalWidget);

        horizontalLayout->setStretch(0, 9);

        retranslateUi(DPlot);

        QMetaObject::connectSlotsByName(DPlot);
    } // setupUi

    void retranslateUi(QWidget *DPlot)
    {
        DPlot->setWindowTitle(QApplication::translate("DPlot", "Form", nullptr));
        pReset->setText(QApplication::translate("DPlot", "\351\207\215\347\275\256\347\273\230\345\233\276", nullptr));
        pSave->setText(QApplication::translate("DPlot", "\344\277\235\345\255\230\346\210\252\345\233\276", nullptr));
        pSaveData->setText(QApplication::translate("DPlot", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        checkBox_X->setText(QApplication::translate("DPlot", "X-Auto", nullptr));
        checkBox_Y->setText(QApplication::translate("DPlot", "Y-Auto", nullptr));
        checkBox_Y2->setText(QApplication::translate("DPlot", "Y2-Auto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DPlot: public Ui_DPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPLOT_H
