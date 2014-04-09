#ifndef __main_widget_h__
#define __main_widget_h__

#include "gen.h"
#include "qvumeter.h"
#include "mythread.h"



#include "qvumeter.h"
#include "mythread.h"

class OvenTimer : public QWidget
{
    Q_OBJECT
public:
    OvenTimer(QWidget *parent = 0);
    void setDuration(int secs);
    int duration() const;
    void draw(QPainter *painter);
signals:
    void timeout();
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    QDateTime finishTime;
    QTimer *updateTimer;
    QTimer *finishTimer;
};

class mainWidget : public QWidget
{
  Q_OBJECT
  
  public:
    mainWidget(QWidget *parent = 0);   
    
    int GetRNDValue(); 
    
    MyThread m_thread;
    
    QLCDNumber *lcd;
    QSlider *slider;
    QPushButton *test;
	QPushButton *quit;
	QVUMeter *vumeter;
	QVBoxLayout *vlayout;
	QHBoxLayout *mlayout;
	QHBoxLayout *hlayout;
	OvenTimer * ovenTimer;
    
    // QPower *button_power;
    // QPower *aerobutton_test;
    
  public slots:  
    void showMessageBox();  
    void closeApp();   
    void setValue();
    void StartMyThread(); 

 };
 


#endif