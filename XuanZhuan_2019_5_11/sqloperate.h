#ifndef SQLOPERATE_H
#define SQLOPERATE_H
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QTextStream>

struct result_struct{
    int id;
    QString number;
    QString record_num;
    QString staff;
    QString date;
    QString time;
    QString set_temperature;
    QString max_pressure;
    QString max_pre_timepoint;
    QString dec_pre_timepoint;
    QString oxidation_period;
};

struct process_struct{
    int id;
    QString record_num;
    QString number;
    QString oil1_pre;
    QString oil2_pre;
};

class SQLOPERATE : public QObject
{
    Q_OBJECT
public:
    SQLOPERATE();
    ~SQLOPERATE();

    QString sync_file;
    struct result_struct r_one;
    boolean refresh_table(QTableWidget *);
    boolean create_process_table(QString);
    boolean search_record(QString);
    boolean insert_result_record( struct result_struct *);
    boolean insert_process_record( struct process_struct *);
    boolean delete_table( QString);
    boolean delete_page_record( int, int);
    boolean delete_by_datetime( QString, QString);
    boolean is_file_exist(QString);
    boolean delete_by_batch(QString, QString);
    int search( struct process_struct *, QString);
    int search_result(struct result_struct *, QString);
    int last_insert_id();

private:
    QSqlQuery *sql_query;
    QString result_table_name;
    QString process_table_name;
    QString database_name;
    QString connection_name;
    QSqlDatabase database;
    QString path;
    QString old_path;
    boolean sql_exec();
    boolean file_insert(QString);

};
#endif // SQLOPERATE_H

