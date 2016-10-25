#ifndef _MAIN_VIEW_H_
#define _MAIN_VIEW_H_

#include <QApplication>
#include <QtGui>
#include <time.h>
#include "worker.h"

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QPixmap>

class mainView : public QWidget
{
    Q_OBJECT
public:    
    mainView(QWidget *parent = 0);    
    ~mainView(){};

    int GetRNDValue();

    QLabel *lblNumOfStars;
    QSpinBox *spinBox;
    
    QPushButton* btnStart;
    QPushButton* btnQuit;
    QLabel *viewer;
    QPixmap *pixmap;
    
    Worker *w_thread;

    void setConnections();
    void initWidgets();
    void initLayouts();

 public slots:
    void makePicture();
    void setValue();
    void wExit();
    void StartMyThread();
    void updateUI();
    void addImage(QRect rect, QImage image);
    void test_foo();
    // int GetRNDValue();
};

#endif // mainView_H
