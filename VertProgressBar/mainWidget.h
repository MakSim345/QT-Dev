#ifndef _ICS_WIDGET_BP_H_
#define _ICS_WIDGET_BP_H_

#include <QtGui>
#include "customwidget.h"


class ICSWidgetPB : public QWidget
{
  Q_OBJECT
  
  public:
    ICSWidgetPB(QWidget *parent = 0); 
    
	QVBoxLayout *mainVLayout;
	
	CustomWidget *pcw;
	QScrollBar *phsb;
	QPushButton *bShowNum;
	// QLineEdit *line1;
	
  public slots:  
    void closeApp();   
    // void setValue();
    void showValue(int);
    
  private: 
    void initWidgets();
    void setStyleSheets();
    void setAllLayouts();
    void setConnectionsWidgets();

 };
 
#endif // _ICS_WIDGET_BP_H_