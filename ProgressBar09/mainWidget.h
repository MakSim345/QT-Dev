#ifndef __main_widget_h__
#define __main_widget_h__

#include <QApplication>
#include <QLCDNumber>
#include <QSlider>    
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>   
#include <QMessageBox>

#include "belows_enh.h"
#include "mythread.h"
#include "qprog.h"
#include "customwidget.h"

class mainWidget : public QWidget
{
  Q_OBJECT
  
  public:
    mainWidget(QWidget *parent = 0);   
    
    int GetRNDValue(); 
    MyThread m_thread;
    
    QLCDNumber *lcd;
    QSlider *slider;
    QProg * qProgBar;
    QPushButton *test;
	QPushButton *quit;
	BelowsEnh *vumeter;
	CustomWidget *cwTouchBar;
	QVBoxLayout *vlayout;
	QHBoxLayout *mlayout;
	QHBoxLayout *hlayout;
    
    
    void initWidgets();
    void setConnectionsWidgets();
    void setAllLayouts();
    void setStyleSheets();
    void initStyleSheetVars();
  
    // QPower *button_power;
    // QPower *aerobutton_test;
    
  public slots:  
    void showMessageBox();  
    void closeApp();   
    void setValue();
    void StartMyThread(); 
    
  private:
    int minX;
    int minY;
    QString strButtonsStSheet;
      

 };
 
#endif