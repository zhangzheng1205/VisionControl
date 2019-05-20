#include "sqloperate.h"

SQLOPERATE::SQLOPERATE() {
    result_table_name = "result_datasheet";
    process_table_name = "process_datasheet";
    database_name = "iot_data.db";
    connection_name = "qt_sql_default_connection";

    // 连接数据库
    if (!QSqlDatabase::contains(connection_name)) {
        database = QSqlDatabase::addDatabase("QSQLITE", connection_name);
        database.setDatabaseName(database_name);
    } else {
        database = QSqlDatabase::database(connection_name);
    }
    // 打开数据库 若未创建datasheet表则自动创建该表 若已创建则忽略
    if (database.open())
    {
        sql_query = new QSqlQuery(database);
        // 查询表是否已经创建 重复创建会报错
        QString query = "select count(*) from sqlite_master where type = 'table' and name = '"+result_table_name+"'";
        sql_query->prepare(query);
        if (!sql_exec()) {
            qDebug() << "Error: Failed to query table sqlite_master." << database.lastError();
            return;
        } else if (sql_query->next() && sql_query->value(0).toInt() < 1) {
            // 表未被创建过，创建表
            QString create_result_table = "CREATE TABLE " + result_table_name + \
                    " (Id INTEGER PRIMARY KEY autoincrement, Number VARCHAR(32), Record_num VARCHAR(32), Staff VARCHAR(32), Date VARCHAR(32), Time VARCHAR(32), Set_temperature VARCHAR(32), Max_pressure VARCHAR(32), Max_pre_timepoint VARCHAR(32), Dec_pre_timepoint VARCHAR(32), Oxidation_period VARCHAR(32));";
            sql_query->prepare(create_result_table);
            if (!sql_exec()) {
                qDebug() << "Error: Failed to create table.";
                return;
            }
        }
        QString query_2 = "select count(*) from sqlite_master where type = 'table' and name = '"+process_table_name+"'";
        sql_query->prepare(query_2);
        if (!sql_exec()) {
            qDebug() << "Error: Failed to query table sqlite_master." << database.lastError();
            return;
        } else if (sql_query->next() && sql_query->value(0).toInt() < 1) {
            // 表未被创建过，创建表
            QString create_process_table = "CREATE TABLE " + process_table_name + \
                    " (Id INTEGER PRIMARY KEY autoincrement, Record_num VARCHAR(32), Number VARCHAR(32), Oil1_pre VARCHAR(32), Oil2_pre VARCHAR(32));";
            sql_query->prepare(create_process_table);
            qDebug()<<"create success";
            if (!sql_exec()) {
                qDebug() << "Error: Failed to create table.";
                return;
            }
        }
    }
    else
    {
        qDebug() << "Error: Failed to open database." << database.lastError();
        return;
    }

/*    // 给两个文件路径赋值
    sync_file = "sync.txt";

    if (!is_file_exist(sync_file)) {
        // 若文件未创建 创建文件
        QFile file(sync_file);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            qDebug() << "Error: Failed to create file.";
        file.close();
    }*/
    return;
}

// 关闭数据库连接
SQLOPERATE::~SQLOPERATE() {
    delete sql_query;
    database.close();
}

// 判断文件是否存在
boolean SQLOPERATE::is_file_exist(QString path) {
    QFileInfo fileinfo(path);
    if (fileinfo.isFile())
        return true;
    else
        return false;
}

// 执行sql语句
boolean SQLOPERATE::sql_exec() {
    if (!sql_query->exec()) {
        qDebug() << "Error: Failed to exec." << sql_query->lastError();
        return false;
    } else
        return true;
}

//刷新表格
boolean SQLOPERATE::refresh_table(QTableWidget *data_table)
{
    int i=0;
    QString fresh_string = "SELECT * FROM " + result_table_name;
    sql_query->prepare(fresh_string);
    if (!sql_exec()) {
        qDebug() << "Error: Failed to select record.";
        return 0;
    } else {
        while (sql_query->next()) {
            if(i == data_table->rowCount()-1)
            {
                data_table->insertRow(i+1);
            }
            data_table->setItem(i, 0, new QTableWidgetItem(sql_query->value(1).toString()));
            data_table->setItem(i, 1, new QTableWidgetItem(sql_query->value(2).toString()));
            data_table->setItem(i, 2, new QTableWidgetItem(sql_query->value(3).toString()));
            data_table->setItem(i, 3, new QTableWidgetItem(sql_query->value(4).toString()));
            data_table->setItem(i, 4, new QTableWidgetItem(sql_query->value(5).toString()));
            data_table->setItem(i, 5, new QTableWidgetItem(sql_query->value(6).toString()));
            data_table->setItem(i, 6, new QTableWidgetItem(sql_query->value(7).toString()));
            data_table->setItem(i, 7, new QTableWidgetItem(sql_query->value(8).toString()));
            data_table->setItem(i, 8, new QTableWidgetItem(sql_query->value(9).toString()));
            data_table->setItem(i, 9, new QTableWidgetItem(sql_query->value(10).toString()));
            i++;
        }
    }
    return true;
}

// 向result_table 插入实验结果
boolean SQLOPERATE::insert_result_record(struct result_struct *oldone) {
//    struct new_struct *newone;
//    change_struct2new(oldone, &newone);

    if (oldone->number == NULL || oldone->staff == NULL) {
        qDebug() << "Error: Failed to insert new record, number or staff is null";
        return false;
    }

    QString sql_string = "INSERT INTO " + result_table_name +
            "(Number, Record_num, Staff, Date, Time, Set_temperature, Max_pressure, Max_pre_timepoint, Dec_pre_timepoint, Oxidation_period) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    sql_query->prepare(sql_string);
    sql_query->addBindValue(oldone->number);
    sql_query->addBindValue(oldone->record_num);
    sql_query->addBindValue(oldone->staff);
    sql_query->addBindValue(oldone->date);
    sql_query->addBindValue(oldone->time);
    sql_query->addBindValue(oldone->set_temperature);
    sql_query->addBindValue(oldone->max_pressure);
    sql_query->addBindValue(oldone->max_pre_timepoint);
    sql_query->addBindValue(oldone->dec_pre_timepoint);
    sql_query->addBindValue(oldone->oxidation_period);

    if (!sql_exec()) {
        qDebug() << "Error: Failed to insert record.";
        return false;
    }
    return true;
}

//向process_table 插入过程值
boolean SQLOPERATE::insert_process_record(struct process_struct *oldone) {
//    struct new_struct *newone;
//    change_struct2new(oldone, &newone);

    if (oldone->number == NULL) {
        qDebug() << "Error: Failed to insert new record, number or staff is null";
        return false;
    }

    QString sql_string_2 = "INSERT INTO " + process_table_name +
            "(Record_num, Number, Oil1_pre, Oil2_pre) VALUES(?, ?, ?, ?)";
    sql_query->prepare(sql_string_2);
    sql_query->addBindValue(oldone->record_num);
    sql_query->addBindValue(oldone->number);
    sql_query->addBindValue(oldone->oil1_pre);
    sql_query->addBindValue(oldone->oil2_pre);

    if (!sql_exec()) {
        qDebug() << "Error: Failed to insert record.";
        return false;
    }
    return true;
}

/*
 * 在限制条件下 从表中读取一定条数的数据 存入list
 * list 查询结果数组指针 函数调用后需要释放list内存
 * rule 查询限制条件
 * 返回list数组长度
 * 查找对应批号的过程值
 */
int SQLOPERATE::search(struct process_struct *list, QString record_num) {
    int i = 0;
    QString sql_string = "SELECT * FROM " + process_table_name + " WHERE Record_num='" + record_num + "'";
    sql_query->prepare(sql_string);
    if (!sql_exec()) {
        qDebug() << "Error: Failed to select record.";
        return 0;
    } else {
        while (sql_query->next()) {
            list[i].id = sql_query->value(0).toInt();
            list[i].record_num = sql_query->value(1).toString();
            list[i].number = sql_query->value(2).toString();
            list[i].oil1_pre = sql_query->value(3).toString();
            list[i].oil2_pre = sql_query->value(4).toString();
            i++;
        }
    }
    return i;
}

//查找对应批号的实验结果
int SQLOPERATE::search_result(struct result_struct *list, QString record_num) {
    int i = 0;
    QString sql_string = "SELECT * FROM " + result_table_name + " WHERE Record_num='" + record_num + "'";
    sql_query->prepare(sql_string);
    if (!sql_exec()) {
        qDebug() << "Error: Failed to select record.";
        return 0;
    } else {
        while (sql_query->next()) {
            list[i].id = sql_query->value(0).toInt();
            list[i].number = sql_query->value(1).toString();
            list[i].record_num = sql_query->value(2).toString();
            list[i].staff = sql_query->value(3).toString();
            list[i].date = sql_query->value(4).toString();
            list[i].time = sql_query->value(5).toString();
            list[i].set_temperature = sql_query->value(6).toString();
            list[i].max_pressure = sql_query->value(7).toString();
            list[i].max_pre_timepoint = sql_query->value(8).toString();
            list[i].dec_pre_timepoint = sql_query->value(9).toString();
            list[i].oxidation_period = sql_query->value(10).toString();
            i++;
        }
    }
    return i;
}

//查找result_table中是否有重复批号的数据
boolean SQLOPERATE::search_record(QString record_num)
{
    QString sql_string = "SELECT * FROM " + result_table_name + " WHERE Record_num='" + record_num + "'";
    sql_query->prepare(sql_string);
    if(!sql_exec())
    {
        qDebug() << "Error: Failed to select record.";
        return false;
    }
    else
    {
        sql_query->next();
        if(sql_query->value(1).toString() == "")
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

/*
 * 按record_num删除
 * record_num 要删除的数据的批号
 * 返回是否删除成功
 */
boolean SQLOPERATE::delete_table(QString record_num) {
    QString sql_string = "DELETE FROM " + process_table_name + " WHERE Record_num='" + record_num + "'";
    QString sql_string2 = "DELETE FROM " + result_table_name + " WHERE Record_num='" + record_num + "'";
    sql_query->prepare(sql_string);
    if (!sql_query->exec()) {
        qDebug() << "Error: Failed to delete record Record_num table = " + record_num;
        return false;
    } else {
        // 压缩db文件
        QString sql_string = "Vacuum " + result_table_name;
        sql_query->prepare(sql_string);
        sql_exec();
    }
    sql_query->prepare(sql_string2);
    if (!sql_query->exec()) {
        qDebug() << "Error: Failed to delete record Record_num result = " + record_num;
        return false;
    } else {
        // 压缩db文件
        QString sql_string = "Vacuum " + process_table_name;
        sql_query->prepare(sql_string);
        sql_exec();
    }
    return true;
}

/*
 * 删除范围内id记录
 * start 起始id
 * end 终止id
 * 返回是否删除成功
 */
boolean SQLOPERATE::delete_page_record( int start, int end) {
    QString sql_string = "DELETE FROM " + result_table_name + " WHERE Id >= " + QString::number(start) + " and Id <= " + QString::number(end);
    sql_query->prepare(sql_string);
    if (!sql_query->exec()) {
        qDebug() << "Error: Failed to delete record id between " + QString::number(start) + " and " + QString::number(end);
        return false;
    }

    QString content = "- " + QString::number(start) + "|" + QString::number(end);
    if (!file_insert(content)) {
        qDebug() << "Error: Failed to insert " + content;
        return false;
    } else
        return true;
}

/*
 * 删除指定日期时间的行
 * date 日期
 * time 时间
 * 返回是否删除成功
 */
boolean SQLOPERATE::delete_by_datetime( QString date, QString time) {
    QString sql_string = "DELETE FROM " + result_table_name + " WHERE Date = '" + date + "' AND Time = '" + time + "'";
    sql_query->prepare(sql_string);
    if (!sql_exec()) {
        qDebug() << "Error: Failed to delete record Date = " + date + ", Time = " + time;
        return false;
    }else {
        QString sql_string = "Vacuum " + result_table_name;
        sql_query->prepare(sql_string);
        sql_exec();
    }

    QString content = "/\\ " + date + "|" + time;//原来是"/\ "
    if (!file_insert(content)) {
        qDebug() << "Error: Failed to insert " + content;
        return false;
    } else
        return true;
}

/*
 * 向文件中插入一行
 * content 要插入的文本
 * 返回是否插入成功
 */
boolean SQLOPERATE::file_insert(QString content) {
    QFile file(sync_file);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Error: Failed to open " + sync_file;
        return false;
    }

    QTextStream file_output(&file);
    file_output << content << endl;
    file.close();
    return true;
}

/*
 * 返回刚插入记录的id
 */
int SQLOPERATE::last_insert_id() {
    QString sql_string = "SELECT Id from " + result_table_name + " WHERE rowid = last_insert_rowid()";
    sql_query->prepare(sql_string);
    if (!sql_query->exec()) {
        qDebug() << "Error: Failed to get last id";
        return 0;
    } else {
        sql_query->next();
        return sql_query->value(0).toInt();
    }
}

/*
 * 根据批号删除
 * start 起始批号
 * end 截止批号
 * 返回是否删除成功
 */
boolean SQLOPERATE::delete_by_batch(QString start, QString end) {
    QString sql_string = "DELETE FROM " + result_table_name + " WHERE Batch >= '" + start + "' AND Batch <= '" + end + "'";
    sql_query->prepare(sql_string);

    if (!sql_query->exec()) {
        qDebug() << "Error: Failed to delete batch between " + start + " and " + end;
        return false;
    } else {
        QString sql_string = "Vacuum " + result_table_name;
        sql_query->prepare(sql_string);
        sql_exec();
    }
    QString content = "* " + start + "|" + end;
    if (!file_insert(content)) {
        qDebug() << "Error: Failed to insert " + content;
        return false;
    } else
        return true;
}
