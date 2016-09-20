#ifndef __main_widget_h__
#define __main_widget_h__

#include <QApplication>
#include "qvumeter.h"
#include "mythread.h"

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
    
    // QPower *button_power;
    // QPower *aerobutton_test;
    
  public slots:  
    void showMessageBox();  
    void closeApp();   
    void setValue();
    void StartMyThread(); 

 };
 
#endif