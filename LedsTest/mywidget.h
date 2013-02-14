/* mywidget.h */
#include <QtGui>
#include "qled.h"
#include <windows.h>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>

long  Get1msTimeMS(void);

class MyWidget : public  QWidget
{
  Q_OBJECT
  public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget ();
      
    private:
     QLineEdit* line3;
     QLineEdit* lnMSTime;
     QPushButton* bExit;        
     QPushButton* bRnd;
     QLed *bLed1;
     QLed *bLed2;
     int GetRNDValue();
        
    public slots:
     void setValue();
     void onExit ();     
};


class CTimer
{
public:
   CTimer();
  ~CTimer();
   void Start();
   unsigned int GetElapsedTimeMs() const;
   unsigned __int64 GetElapsedTimeMks() const; 
    
private:
  LARGE_INTEGER m_liFreq;
  LARGE_INTEGER m_liStart;
  LARGE_INTEGER m_liEnd;
};