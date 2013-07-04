#ifndef __main_widget_h__
#define __main_widget_h__

#include <QApplication>
#include <QLCDNumber>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>
#include "qvumeter.h"
#include "mythread.h"
#include "belows_prg.h"
#include "belows_enh.h"

class mainWidget : public QWidget
{
  Q_OBJECT
  
  public:
    mainWidget(QWidget *parent = 0);   
    
    int GetRNDValue(); 
    
    MyThread m_thread;
    QTimer m_timer;
    
    QLCDNumber *lcd;
    QSlider *slider;
    QPushButton *bRnd;
	QPushButton *bQuit;
	QPushButton *bStartThread;
	QPushButton *bTest;
	
	QVUMeter *vumeter;
	BelowsPrg *BelowsProgress; 	
    BelowsEnh *BelowsEnhanced; 
	
	QVBoxLayout *vlayout;
	QVBoxLayout *vlayout2;
	QVBoxLayout *vlayout3;
	QVBoxLayout *vlayout4   ;
	QHBoxLayout *hlayout;
	QHBoxLayout *hlayout2;
	QHBoxLayout *hlayout3;
	
    QHBoxLayout *mlayout;
    // QPower *button_power;
    // QPower *aerobutton_test;
    
  public slots:  
    void showMessageBox();  
    void closeApp();   
    void setValue();
    void StartMyThread(); 
    void onStartThreadClick();
    void onTestClick();
    void onTimerEvent();
    
  private:
    int m_nRandomValue;
    int m_nGoDown;

 };
 
#endif