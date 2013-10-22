/*
 * led.cpp
 *
 */

#include "led.h"

LED::LED(const QString& style, QWidget *parent)
 : QLabel(parent)
{
    setStyle(style);
}

LED::~LED()
{
    delete on;
    delete off;
}

void LED::setActive(bool state)
{
    lit = state;
    setPixmap(lit ? *on : *off);
}

bool LED::isActive() const
{
    return lit;
}

void LED::setStyle(const QString& style)
{
    on = new QPixmap(":/Resources/style_" + style + "_on.png");
    Q_CHECK_PTR(on);
    off = new QPixmap(":/Resources/style_" + style + "_off.png");
    Q_CHECK_PTR(off);
}

QSize LED::minimumSizeHint() const
{
    return QSize(16,16);
}

QSize LED::sizeHint() const
{
    return QSize(16,16);
}
