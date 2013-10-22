/*
 * clockframe.cpp
 *
 */

#include <QPalette>
#include <QBrush>
#include <QMessageBox>
#include <QPixmap>
#include <QIcon>
#include <QSettings>
#include <QTime>
#include <QApplication>
#include <QPainter>

#include "clockframe.h"

//                           Zahl  Bits
const bool ClockFrame::digital[10][4] = {
    { false, false, false, false },
    { true,  false, false, false },
    { false, true,  false, false },
    { true,  true,  false, false },
    { false, false, true,  false },
    { true,  false, true,  false },
    { false, true,  true,  false },
    { true,  true,  true,  false },
    { false, false, false, true  },
    { true,  false, false, true  },
};

const char* ClockFrame::KEY_STYLE = "style";
const char* ClockFrame::KEY_LOCKED = "locked";
const char* ClockFrame::KEY_XPOS = "x";
const char* ClockFrame::KEY_YPOS = "y";

ClockFrame::ClockFrame(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint),
      hour(0), min(0), sec(0)
{
    setWindowTitle("qBinClock");
    setWindowIcon(QPixmap(":/Resources/qBinClock.png"));
    
    // load application settings
    config = new QSettings(QSettings::UserScope, "rexi.org", "qBinClock");
    
    int x = config->value(KEY_XPOS, 0).toInt();
    int y = config->value(KEY_YPOS, 0).toInt();
    // move(QPoint(x,y));
    
    QPalette palette;
    // palette.setBrush(backgroundRole(), QBrush(QPixmap(":/Resources/bg_brushed.png")));
    palette.setBrush(backgroundRole(), QBrush(QPixmap(":/bkg.jpg")));
    
    setPalette(palette);
    
    // create popup menu
    menu = new ClockMenu(this);
    
    // initialize LED array
    led = new LEDArray();
    led->append(createLEDList(2));
    led->append(createLEDList(4));
    led->append(createLEDList(3));
    led->append(createLEDList(4));
    led->append(createLEDList(3));
    led->append(createLEDList(4));
    
    // position LEDs in layout grid
    QGridLayout* grid = new QGridLayout(this);//, 4, 6, 4, 3);
    
    grid->setMargin(4);
    grid->setSpacing(3);
    addToLayout(grid, led, 0, 2);
    addToLayout(grid, led, 1, 4);
    addToLayout(grid, led, 2, 3);
    addToLayout(grid, led, 3, 4);
    addToLayout(grid, led, 4, 3);
    addToLayout(grid, led, 5, 4);
    //grid->setResizeMode(QLayout::Fixed);
    //resize(QSize().expandedTo(minimumSizeHint()));
    
    // set up timer    
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    sync();
    timer->start(500);
}


ClockFrame::~ClockFrame()
{
}

void ClockFrame::tick()
{
    sync();
    
    int digits[] = { 0,0,0,0,0,0 };
    
    digits[0] = hour / 10;
    digits[1] = hour % 10;
    digits[2] = min / 10;
    digits[3] = min % 10;
    digits[4] = sec / 10;
    digits[5] = sec % 10;

    for(int column = 5; column >= 0; --column)
        for(int row = led->at(column)->size() - 1; row >= 0; --row)
            led->at(column)->at(row)->setActive(digital[digits[column]][row]);
}

void ClockFrame::sync()
{
    QTime time = QTime::currentTime();
    
    hour = time.hour();
    min = time.minute();
    sec = time.second();

    setToolTip(time.toString());
}

void ClockFrame::mouseMoveEvent(QMouseEvent* e)
{
    if(!config->value(KEY_LOCKED).toBool())
        move(e->globalPos() - clickPos);
}

void ClockFrame::mousePressEvent(QMouseEvent* e)
{
    clickPos = e->pos();
    
    if(e->button() == Qt::RightButton)
        menu->popup(QCursor::pos());
}

void ClockFrame::about()
{
    QMessageBox::about(this, tr("About qBinClock"),
        tr("qBinClock v0.2 (2005-07-12)\n"
        "Copyright (c) 2005 Michael Rex\n"
        "Released under the terms of the GNU GPL v2"));
}

bool ClockFrame::isLocked() const
{
    return config->value(KEY_LOCKED).toBool();
}

void ClockFrame::setLocked(bool state)
{
    config->setValue(KEY_LOCKED, state);
}

void ClockFrame::quit()
{
    config->setValue(KEY_XPOS, x());
    config->setValue(KEY_YPOS, y());
    config->sync();
    
    qApp->quit();
}

QList<LED*>* ClockFrame::createLEDList(int items)
{
    QList<LED*>* tmplist = new QList<LED*>;
    for(int i = 0; i < items; ++i)
        tmplist->append(new LED(config->value(KEY_STYLE, "default").toString()));
        
    return tmplist;
}

void ClockFrame::addToLayout(QGridLayout* grid, LEDArray* led, int column, int count)
{
    for(int i = count - 1; i >= 0; --i)
        grid->addWidget(led->at(column)->at(i), 3 - i, column);
}

void ClockFrame::setStyle(QString style)
{
    config->setValue(KEY_STYLE, style);
    
    for(int column = 5; column >= 0; --column)
        for(int row = led->at(column)->size() - 1; row >= 0; --row)
            led->at(column)->at(row)->setStyle(style);
}

