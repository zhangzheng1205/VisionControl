#ifndef DHEADER_H
#define DHEADER_H

#include <QWidget>

namespace Ui {
class DHeader;
}

class DHeader : public QWidget
{
    Q_OBJECT

public:
    explicit DHeader(QWidget *parent = 0);
    ~DHeader();

    void setName(QString name);
    void setValue(QString value);
private:
    Ui::DHeader *ui;
};

#endif // DHEADER_H
