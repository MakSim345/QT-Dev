#ifndef POWERBUTTON_H
#define POWERBUTTON_H

#include <QtWidgets/QMainWindow>
#include "ui_powerbutton.h"

#include <QtGui>
#include <QWidget>

// class QDESIGNER_WIDGET_EXPORT QPower : public QWidget
class QPower : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor);
    Q_PROPERTY(bool state READ state WRITE setState);

public:

    QPower(QWidget *parent = 0);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    QColor color() const
    {
        return pow_color;
    }

    bool state() const
    {
        return pow_state;
    }

public slots:

    void setColor(QColor);
    void setState(bool);


protected:

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void paintBorder();
    void paintPowerOn();
    void paintPowerOff();


private:

    QColor pow_color;
    bool pow_state;
};

#endif // POWERBUTTON_H
