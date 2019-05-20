#-------------------------------------------------
#
# Project created by QtCreator 2019-01-15T18:42:16
#
#-------------------------------------------------

QT       += core gui serialport printsupport sql
QT       += axcontainer
QT       += widgets
QT       += core
QT       += gui
Qt       += network
QT       += network widgets

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Yanrun
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
    dev/dcontrol.cpp \
    dev/dheader.cpp \
    dev/display.cpp \
    dev/display_text.cpp \
    dev/logindialog.cpp \
    plot/dplot.cpp \
    plot/qcustomplot.cpp \
    serial/qextserialbase.cpp \
    serial/qextserialport.cpp \
    serial/win_qextserialport.cpp \
    app_autoctl.cpp \
    gbase.cpp \
    get_average.cpp \
    main.cpp \
    mainwindow.cpp \
    prevt.cpp \
    process_file.cpp \
    process_matrix.cpp \
    sqloperate.cpp \
    threadprocess.cpp \
    Matrix.c \
    yieldstress.cpp

HEADERS += \
    dev/dcontrol.h \
    dev/dheader.h \
    dev/display.h \
    dev/display_text.h \
    dev/logindialog.h \
    plot/dplot.h \
    plot/qcustomplot.h \
    serial/qextserialbase.h \
    serial/qextserialport.h \
    serial/win_qextserialport.h \
    app_autoctl.h \
    gbase.h \
    get_average.h \
    iot_pkg.h \
    mainwindow.h \
    matrix.h \
    prevt.h \
    process_file.h \
    process_matrix.h \
    sqloperate.h \
    threadprocess.h \
    yieldstress.h

FORMS += \
    mainwindow.ui \
    dev/dcontrol.ui \
    dev/dheader.ui \
    dev/display.ui \
    dev/display_text.ui \
    dev/logindialog.ui \
    plot/dplot.ui

INCLUDEPATH += \
    ./serial \
    ./login \
    ./plot \
    ./dev

RESOURCES += \
    res.qrc

RC_ICONS = app.ico
