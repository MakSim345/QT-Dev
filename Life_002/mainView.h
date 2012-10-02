#ifndef _MAIN_VIEW_H_
#define _MAIN_VIEW_H_
 
#include <QtGui>
#include <math.h>
#include <QPixmap>
#include <QWidget>
#include "lifeWidget.h"

class mainView : public QWidget
{
 
 Q_OBJECT

 public:
     mainView(QWidget *parent = 0);
     ~mainView() {};

     QLineEdit* lnCells;
     QLineEdit* lnMSTime;
     QLineEdit* lnIteration;

     QPushButton* bStart;
     QPushButton* bRnd;
     QPushButton* bPause;
     QPushButton* bNextStep;
     QPushButton *bQuit;
     QSlider *slider;

     // QLCDNumber *lcd;

     // MyThread m_thread;
private:
    lifeWidget *lifeWgt;
    void setConnections();
    void initWidgets();
    void setWidgetLayout();
    QTimer* timer;

public slots:
     void setValue();
     void onExit ();
     void StartMyThread();
     void updateLabels();
     void startGame();
};

#endif
