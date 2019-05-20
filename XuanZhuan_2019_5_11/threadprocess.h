#ifndef THREADPROCESS_H
#define THREADPROCESS_H
#include "mainwindow.h"
#include "qt_windows.h"

class THREADPROCESS : public QObject
{
    Q_OBJECT
public:
    THREADPROCESS() {}
    ~THREADPROCESS() {}

signals:
    // 在子线程中，Table2ExcelA结束之后，调用主线程中函数通知已完成Excel导出
    void Table2ExcelResultSignalA(bool, QString);
    void Table2ExcelResultSignalB(bool, QString);

public slots:
    void Table2ExcelA( QString, QTableWidget *table1, QTableWidget *table2, QString title1, QString title2);
    void Table2ExcelB(QString, QTableWidget *table, QString title);

};

#endif
