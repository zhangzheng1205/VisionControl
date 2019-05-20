#ifndef DISPLAY_TEXT_H
#define DISPLAY_TEXT_H

#include <QWidget>

namespace Ui {
class display_text;
}

class display_text : public QWidget
{
    Q_OBJECT

public:
    explicit display_text(QWidget *parent = 0);
    ~display_text();
    void setName(QString name);
    void setColor(QString color);
    void set_color(QColor _color);
    QString getColor();

private:
    Ui::display_text *ui;
};

#endif // DISPLAY_TEXT_H
