/*
 * clockframe.h
 *
 */

#ifndef CLOCKFRAME_H
#define CLOCKFRAME_H

#include <QWidget>
#include <QTimer>
#include <QEvent>
#include <QPoint>
#include <QList>
#include <QGridLayout>
#include <QMenu>
#include <QMouseEvent>
#include <QAction>
#include <QSettings>

#include "led.h"
#include "clockmenu.h"

/**
 */
class ClockFrame : public QWidget
{
Q_OBJECT
public:
    ClockFrame(QWidget *parent = 0);
    ~ClockFrame();
    void setStyle(QString style);
    bool isLocked() const;
    void setLocked(bool state);
    
protected:
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    
    QPoint clickPos;
    
private slots:
    void tick();
    void about();
    void quit();

private:
    typedef QList<LED*> LEDColumn;
    typedef QList<LEDColumn*> LEDArray;
    
    void sync();
    QList<LED*>* createLEDList(int count);
    void addToLayout(QGridLayout* grid, LEDArray* led, int column, int count);
    
    LEDArray* led;
    QTimer* timer;
    QSettings* config;
    ClockMenu* menu;
    int hour;
    int min;
    int sec;
    
    static const bool digital[10][4];     // hier heiﬂt static dasselbe wie in Java: digital ist eine Klassenvariable
    static const char* KEY_STYLE;
    static const char* KEY_LOCKED;
    static const char* KEY_XPOS;
    static const char* KEY_YPOS;
};

#endif
