#-------------------------------------------------
#
# Project created by QtCreator 2018-04-18T11:04:21
#
#-------------------------------------------------

QT       += core gui serialport printsupport sql

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iot_pure
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    serial/qextserialbase.cpp \
    serial/qextserialport.cpp \
    serial/win_qextserialport.cpp \
    main.cpp \
    mainwindow.cpp \
    terminal.cpp

HEADERS  += \
    serial/qextserialbase.h \
    serial/qextserialport.h \
    serial/win_qextserialport.h \
    iot_pkg.h \
    mainwindow.h \
    terminal.h

FORMS    += mainwindow.ui

INCLUDEPATH += ./serial \

