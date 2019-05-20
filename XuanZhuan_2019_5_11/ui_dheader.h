/********************************************************************************
** Form generated from reading UI file 'dheader.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DHEADER_H
#define UI_DHEADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DHeader
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *data;
    QLabel *note;

    void setupUi(QWidget *DHeader)
    {
        if (DHeader->objectName().isEmpty())
            DHeader->setObjectName(QString::fromUtf8("DHeader"));
        DHeader->resize(118, 86);
        DHeader->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(DHeader);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(DHeader);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame{\n"
"	border-radius:15px;\n"
"	border: 0px solid red;\n"
"	background-color: rgba(0, 255, 127, 100);\n"
"}\n"
"QLabel#data{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	color: rgb(255, 0, 0);\n"
"	font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QLabel#note{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	color: rgb(85, 85, 0);\n"
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
        data = new QLabel(frame);
        data->setObjectName(QString::fromUtf8("data"));
        data->setStyleSheet(QString::fromUtf8(""));
        data->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_3->addWidget(data);

        note = new QLabel(frame);
        note->setObjectName(QString::fromUtf8("note"));
        note->setStyleSheet(QString::fromUtf8(""));
        note->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_3->addWidget(note);


        verticalLayout_2->addWidget(frame);


        retranslateUi(DHeader);

        QMetaObject::connectSlotsByName(DHeader);
    } // setupUi

    void retranslateUi(QWidget *DHeader)
    {
        DHeader->setWindowTitle(QApplication::translate("DHeader", "Form", nullptr));
        data->setText(QApplication::translate("DHeader", "0.0", nullptr));
        note->setText(QApplication::translate("DHeader", "\351\200\232\351\201\2231\346\270\251\345\272\246[\342\204\203]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DHeader: public Ui_DHeader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DHEADER_H
