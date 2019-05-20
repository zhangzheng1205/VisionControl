/********************************************************************************
** Form generated from reading UI file 'display.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_display
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *note;

    void setupUi(QWidget *display)
    {
        if (display->objectName().isEmpty())
            display->setObjectName(QString::fromUtf8("display"));
        display->resize(147, 85);
        verticalLayout = new QVBoxLayout(display);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(display);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame{\n"
"	border-radius:15px;\n"
"	border: 0px solid red;\n"
"	/*background-color: rgba(0, 255, 127, 100);*/\n"
"     /* background-color: rgba(0, 255, 0,100);*/\n"
"}\n"
"QLabel#color{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	color: rgb(255, 0, 0);\n"
"	font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QLabel#note{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	color: rgb(35, 35, 0);\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        note = new QLabel(frame);
        note->setObjectName(QString::fromUtf8("note"));
        note->setStyleSheet(QString::fromUtf8(""));
        note->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout->addWidget(note, 0, 0, 1, 1);


        verticalLayout->addWidget(frame);

        frame->raise();
        note->raise();

        retranslateUi(display);

        QMetaObject::connectSlotsByName(display);
    } // setupUi

    void retranslateUi(QWidget *display)
    {
        display->setWindowTitle(QApplication::translate("display", "Form", nullptr));
        note->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class display: public Ui_display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_H
