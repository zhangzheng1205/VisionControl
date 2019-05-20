#include "threadprocess.h"

void THREADPROCESS::Table2ExcelA(QString fileName, QTableWidget *table1, QTableWidget *table2,QString title1, QString title2)
{
    HRESULT r = OleInitialize(0);
    if (r != S_OK && r != S_FALSE)
    {
        qDebug("Qt: Could not initialize OLE (error %x)", (unsigned int)r);
    }

    if (fileName!="")
    {
        QAxObject *excel = new QAxObject;
        if (excel->setControl("Excel.Application")) //连接Excel控件
        {
            excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
            excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
            QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
            workbooks->dynamicCall("Add");//新建一个工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
            int i,j,colcount=table1->columnCount();
            QAxObject *cell,*col;
            //导出第1个表
            //标题行
            cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
            cell->dynamicCall("SetValue(const QString&)", title1);
            cell->querySubObject("Font")->setProperty("Size", 18);
            col=worksheet->querySubObject("Cells(int,int)", 1, 1);
            col->dynamicCall("SetValue(const QString&)", title1);
            col->querySubObject("Font")->setProperty("Size", 18);
            //调整行高
            worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
            //合并标题行
            QString cellTitle;
            //拼接字符串,令cellTitle为A1:H1,其中'H'与'A'在ASCII表中差为colcount-1
            cellTitle.append("A1:");
            cellTitle.append(QChar(colcount + 1 + 'A'));
            cellTitle.append(QString::number(1));
            QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
            range->setProperty("WrapText", true);
            range->setProperty("MergeCells", true);
            range->setProperty("HorizontalAlignment", -4108);//xlCenter
            range->setProperty("VerticalAlignment", -4108);//xlCenter
            //列标题
            for(i=0;i<=colcount;i++)
            {
                QString columnName;
                columnName.append(QChar(i + 'A'));
                columnName.append(":");
                columnName.append(QChar(i + 'A'));
                col = worksheet->querySubObject("Columns(const QString&)", columnName);
                col->setProperty("ColumnWidth", table1->columnWidth(i)/7);
                cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                if (i == 0)
                {
                    cell->dynamicCall("SetValue(const QString&)", "");
                }else if(i == colcount){
                    // -40℃ 的位置很奇怪，在i+2的位置
                    //设置-40℃的列宽
                    columnName=QChar(i+1+'A') + ':' + QChar(i+1+'A');
                    col = worksheet->querySubObject("Columns(const QString&)", columnName);
                    col->setProperty("ColumnWidth", table1->columnWidth(1)/7);
                    columnName=table1->horizontalHeaderItem(i-1)->text();
                    cell=worksheet->querySubObject("Cells(int,int)", 2, i+2);
                    cell->dynamicCall("SetValue(const QString&)", columnName);
                }else{
                    columnName=table1->horizontalHeaderItem(i-1)->text();
                    cell->dynamicCall("SetValue(const QString&)", columnName);
                }

                cell->querySubObject("Font")->setProperty("Bold", true);
                cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                cell->setProperty("VerticalAlignment", -4108);//xlCenter
            }

            //行标题
            int rowCount = table1->rowCount();
            for (i = 0; i < rowCount; i++)
            {
                QString rowName;
                cell=worksheet->querySubObject("Cells(int,int)", i+3, 1);
                rowName=table1->verticalHeaderItem(i)->text();

                cell->dynamicCall("SetValue(const QString&)", rowName);
                cell->querySubObject("Font")->setProperty("Bold", true);
                cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                cell->setProperty("VerticalAlignment", -4108);//xlCenter
            }

            //数据区
            for(i=0;i<table1->rowCount();i++)
            {
                for (j=0;j<colcount;j++)
                {
                    if (j == colcount - 1)
                        worksheet->querySubObject("Cells(int,int)", i+3, j+3)->dynamicCall("SetValue(const QString&)", table1->item(i,j)?table1->item(i,j)->text():"");
                    else
                        worksheet->querySubObject("Cells(int,int)", i+3, j+2)->dynamicCall("SetValue(const QString&)", table1->item(i,j)?table1->item(i,j)->text():"");
                }
            }//画框线
            QString lrange;
            lrange.append("A2:");
            lrange.append(colcount + 1 + 'A');
            lrange.append(QString::number(table1->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", lrange);
            range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
            range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));//调整数据区行高
            QString rowsName;
            rowsName.append("2:");
//            rowsName.append(QString::number(table1->rowCount() + 2));
            rowsName.append(QString::number(table1->rowCount() + table2->rowCount() + 5));
            range = worksheet->querySubObject("Range(const QString&)", rowsName);
            range->setProperty("RowHeight", 20);


            //导出第二个表
            //标题行
            cell=worksheet->querySubObject("Cells(int,int)", 4+table1->rowCount(), 1);
            cell->dynamicCall("SetValue(const QString&)", title2);
            cell->querySubObject("Font")->setProperty("Size", 18);
            col=worksheet->querySubObject("Cells(int,int)", 4+table1->rowCount(), 1);
            col->dynamicCall("SetValue(const QString&)", title2);
            col->querySubObject("Font")->setProperty("Size", 18);

            //调整行高 ??
            worksheet->querySubObject("Range(const QString&)", QString::number(4+table1->rowCount())+':'+QString::number(4+table1->rowCount()))->setProperty("RowHeight", 30);
            //合并标题行
            //拼接字符串,令cellTitle为A1:H1,其中'H'与'A'在ASCII表中差为colcount-1
            colcount = table2->columnCount();
            cellTitle='A';
            cellTitle.append(QString::number(4+table1->rowCount())+':');
            cellTitle.append(QChar(colcount + 1 + 'A'));
            cellTitle.append(QString::number(4+table1->rowCount()));
            range = worksheet->querySubObject("Range(const QString&)", cellTitle);
            range->setProperty("WrapText", true);
            range->setProperty("MergeCells", true);
            range->setProperty("HorizontalAlignment", -4108);//xlCenter
            range->setProperty("VerticalAlignment", -4108);//xlCenter

            //列标题
            for(i=0;i<=colcount;i++)
            {
                QString columnName;
                cell=worksheet->querySubObject("Cells(int,int)", 5+table1->rowCount(), i+1);
                if (i == 0)
                {
                    cell->dynamicCall("SetValue(const QString&)", "");
                }else if(i == colcount){
                    // -40℃ 的位置很奇怪，在i+2的位置

                    columnName=table2->horizontalHeaderItem(i-1)->text();
                    cell=worksheet->querySubObject("Cells(int,int)", 5+table1->rowCount(), i+2);
                    cell->dynamicCall("SetValue(const QString&)", columnName);
                }else{
                    columnName=table2->horizontalHeaderItem(i-1)->text();
                    cell->dynamicCall("SetValue(const QString&)", columnName);
                }

                cell->querySubObject("Font")->setProperty("Bold", true);
                cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                cell->setProperty("VerticalAlignment", -4108);//xlCenter
            }

            //行标题
            rowCount = table2->rowCount();
            for (i = 0; i < rowCount; i++)
            {
                cell=worksheet->querySubObject("Cells(int,int)", i+6+table1->rowCount(), 1);
                QString rowName=table2->verticalHeaderItem(i)->text();

                cell->dynamicCall("SetValue(const QString&)", rowName);
                cell->querySubObject("Font")->setProperty("Bold", true);
                cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                cell->setProperty("VerticalAlignment", -4108);//xlCenter
            }

            //数据区
            for(i=0;i<table2->rowCount();i++)
            {
                for (j=0;j<colcount;j++)
                {
                    if (j == colcount - 1)
                        worksheet->querySubObject("Cells(int,int)", i+6+table1->rowCount(), j+3)->dynamicCall("SetValue(const QString&)", table2->item(i,j)?table2->item(i,j)->text():"");
                    else
                        worksheet->querySubObject("Cells(int,int)", i+6+table1->rowCount(), j+2)->dynamicCall("SetValue(const QString&)", table2->item(i,j)?table2->item(i,j)->text():"");
                }
            }//画框线

            lrange='A';
            lrange.append(QString::number(4+table1->rowCount()));
            lrange.append(':');
            lrange.append(QChar(colcount + 1 + 'A'));
            lrange.append(QString::number(5 + table1->rowCount() + table2->rowCount()));
            range = worksheet->querySubObject("Range(const QString&)", lrange);
            range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
            range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
            //调整数据区行高

            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
            workbook->dynamicCall("Close()");//关闭工作簿
            excel->dynamicCall("Quit()");//关闭excel
            delete excel;
            excel=NULL;

            emit Table2ExcelResultSignalA(true, "file:///" + QDir::toNativeSeparators(fileName));
        }

        else{
            emit Table2ExcelResultSignalA(false, NULL);
        }
    }
    OleUninitialize();
}

void THREADPROCESS::Table2ExcelB(QString fileName, QTableWidget *table, QString title)
{
    Q_UNUSED(title);
    HRESULT r = OleInitialize(0);
    if(r != S_OK && r != S_FALSE){
        qDebug("Qt: Could not initialize OLE (error %x)", (unsigned int)r);
    }
    if(fileName!=""){
        QAxObject *excel = new QAxObject;
        if (excel->setControl("Excel.Application")){ //连接Excel控件
            excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
            excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
            QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
            workbooks->dynamicCall("Add");//新建一个工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

            QList<QVariant> rowdata;//, aline;
            int rows = table->rowCount();
//            for(int j=0;j<table->columnCount();++j){
//                rowdata.append(list(table->horizontalHeaderItem(j)->text()));
//            }//应该直接定义双重的QVariant zc0329
            for(int i=0;i<rows;++i){
                if(i==0){//先把表头存起来
                    QList<QVariant> li;
                    for(int j=0;j<table->columnCount();++j){
                        li.append(QVariant(table->horizontalHeaderItem(j)->text()));
                    }
                    QVariant co(li);
                    rowdata.append(co);
                }
                if(table->item(i,0)==NULL){//如果第i+1行数据为空，跳出for循环
                    rows=i+1;
                    break;
                }
                //如果不为空，创建一个list，存入每一行的数据
                QList<QVariant> aline;
                for(int j=0;j<table->columnCount();++j){
                    aline.append(QVariant(table->item(i,j)->text()));
                }
                QVariant conv(aline);//list赋值到QVariant
                rowdata.append(conv);//添加到rowdata中
            }

            QVariant _data(rowdata);
//            qDebug()<<table->columnCount();//'A'+12-1='L';
            QString s = "A1:"+QString('A'+table->columnCount()-1)+QString::number(rows);//这里rows决定了输出显示多少行 A1-L(rows)//没写前面的序号123456等等 所以少一列
            QAxObject *range = worksheet->querySubObject("Range(QString)", s);
            range->setProperty("Value", _data);
            QAxObject *font = worksheet->querySubObject("Range(QString)", ("A1:"+QString('A'+table->columnCount()-1)+QString::number(1)))->querySubObject("Font");//A1-L1
            font->setProperty("Name", QStringLiteral("宋体"));  //设置单元格字体
            font->setProperty("Bold", true);  //设置单元格字体加粗
            //设置列宽
            worksheet->querySubObject("Range(const QString&)", "A:A")->setProperty("ColumnWidth", 16);
            worksheet->querySubObject("Range(const QString&)", "B:B")->setProperty("ColumnWidth", 8);
            worksheet->querySubObject("Range(const QString&)", "C:C")->setProperty("ColumnWidth", 12);
            worksheet->querySubObject("Range(const QString&)", "D:D")->setProperty("ColumnWidth", 10);
            worksheet->querySubObject("Range(const QString&)", "E:E")->setProperty("ColumnWidth", 16);
            worksheet->querySubObject("Range(const QString&)", "F:F")->setProperty("ColumnWidth", 8);
            worksheet->querySubObject("Range(const QString&)", "G:G")->setProperty("ColumnWidth", 6);
            worksheet->querySubObject("Range(const QString&)", "H:I")->setProperty("ColumnWidth", 8);//2为一个汉字宽度
            worksheet->querySubObject("Range(const QString&)", "J:K")->setProperty("ColumnWidth", 12);
            worksheet->querySubObject("Range(const QString&)", "L:L")->setProperty("ColumnWidth", 10);

            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
            workbook->dynamicCall("Close()");//关闭工作簿
            excel->dynamicCall("Quit()");//关闭excel
            delete excel;
            excel=NULL;

            emit Table2ExcelResultSignalA(true, "file:///" + QDir::toNativeSeparators(fileName));
        }
        else{
            emit Table2ExcelResultSignalA(false, NULL);
        }
    }
    OleUninitialize();
}
