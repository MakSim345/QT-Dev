/*
 * led.h
 */

#ifndef LED_H
#define LED_H

#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QSize>

/**
 * 
 * @author Michael Rex
 */
class LED : public QLabel
{
Q_OBJECT
public:
    LED(const QString& style = "default", QWidget *parent = 0);
    ~LED();
    void setActive(bool state);
    bool isActive() const;
    void setStyle(const QString& style);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

private:
    bool lit;
    QPixmap* on;
    QPixmap* off;
};

#endif
