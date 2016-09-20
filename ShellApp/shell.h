#ifndef _SHELL_H_
#define _SHELL_H_

#include <QtGui>
#include <QTextEdit>
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Shell : public QWidget
{
  Q_OBJECT
  
  private:
  	  QProcess*  m_process;
      QLineEdit* m_ptxtCommand;
      QTextEdit* m_ptxtDisplay;
      QLabel*    m_plabel;
      QPushButton* m_pcmd;        
    
  public:
  	  Shell(QWidget* pwgt = 0);
  	  ~Shell();
  
  public slots:
  	  void slotDataOnStdout();
	  void slotReturnPressed();   	  

};

// #endif

class MyWidget : public  QWidget
{
  Q_OBJECT
  public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget ();
      
    private:
     QLineEdit* line3;        
     QPushButton* bExit;        
     QPushButton* bRnd;
     int GetRNDValue();
        
    public slots:
     void setValue();
     void onExit ();     
};

#endif