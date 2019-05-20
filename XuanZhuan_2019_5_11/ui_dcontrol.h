/********************************************************************************
** Form generated from reading UI file 'dcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCONTROL_H
#define UI_DCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DControl
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;

    void setupUi(QWidget *DControl)
    {
        if (DControl->objectName().isEmpty())
            DControl->setObjectName(QString::fromUtf8("DControl"));
        DControl->resize(177, 178);
        gridLayout = new QGridLayout(DControl);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox = new QComboBox(DControl);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	color: rgba(255, 0, 0, 100);\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
""));

        horizontalLayout->addWidget(comboBox);

        pushButton = new QPushButton(DControl);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("/*QPushButton {\n"
"	color: rgba(0, 0, 255, 150);\n"
"}*/\n"
"\n"
"\n"
"background: transparent"));

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 2);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(DControl);

        QMetaObject::connectSlotsByName(DControl);
    } // setupUi

    void retranslateUi(QWidget *DControl)
    {
        DControl->setWindowTitle(QApplication::translate("DControl", "Form", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DControl: public Ui_DControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCONTROL_H
