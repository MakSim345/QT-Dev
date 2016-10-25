#ifndef _MAIN_VIEW_H_
#define _MAIN_VIEW_H_

#include <QtGui>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QPixmap>
#include <time.h>
#include "worker.h"
#include "imagewindow.h"

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
    
    // QLabel *imageWindow;
    ImageWindow *imageWindow;
    QPixmap *pixmap;
    
    Worker *w_thread;
    timeConsumingThread *img_thread;

    void setConnections();
    void initWidgets();
    void initLayouts();

 public slots:
    void makePicture();
    void setValue();
    void wExit();
    void StartMyThread();
    void updateUI();
    void addImage(QRect rect, const QImage &image);
    void addImage(const QImage &image);
    // void addImage(QRect rect, QImage image);
    void test_foo();
    // int GetRNDValue();
};

#endif // mainView_H
