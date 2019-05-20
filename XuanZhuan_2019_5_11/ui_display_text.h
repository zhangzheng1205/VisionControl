/********************************************************************************
** Form generated from reading UI file 'display_text.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_TEXT_H
#define UI_DISPLAY_TEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_display_text
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *color;
    QLabel *note;

    void setupUi(QWidget *display_text)
    {
        if (display_text->objectName().isEmpty())
            display_text->setObjectName(QString::fromUtf8("display_text"));
        display_text->resize(156, 112);
        gridLayout = new QGridLayout(display_text);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(display_text);
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
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        color = new QLabel(frame);
        color->setObjectName(QString::fromUtf8("color"));
        color->setStyleSheet(QString::fromUtf8(""));
        color->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_3->addWidget(color);

        note = new QLabel(frame);
        note->setObjectName(QString::fromUtf8("note"));
        note->setStyleSheet(QString::fromUtf8(""));
        note->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_3->addWidget(note);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(display_text);

        QMetaObject::connectSlotsByName(display_text);
    } // setupUi

    void retranslateUi(QWidget *display_text)
    {
        display_text->setWindowTitle(QApplication::translate("display_text", "Form", nullptr));
        color->setText(QString());
        note->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class display_text: public Ui_display_text {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_TEXT_H
