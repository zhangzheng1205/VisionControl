#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>

namespace Ui {
class display;
}

class display : public QWidget
{
    Q_OBJECT

public:
    explicit display(QWidget *parent = 0);
    ~display();
    void setName(QString name);

private:
    Ui::display *ui;
};

#endif // DISPLAY_H
