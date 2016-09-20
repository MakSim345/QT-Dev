//#include <QtGui>
#include <QApplication>
#include <QPushButton>
#include "shell.h"


Shell::Shell(QWidget* pwgt) : QWidget(pwgt)
{
 m_process     = new QProcess (this);
 m_ptxtDisplay = new QTextEdit;
 m_plabel      = new QLabel("&Command");
 m_ptxtCommand = new QLineEdit("dir");
 m_plabel->setBuddy(m_ptxtCommand);
 m_pcmd = new QPushButton("&Enter");
 
 
 connect (m_process, SIGNAL(readyReadStandardOutput()), SLOT (slotDataOnStdout()));
 connect (m_ptxtCommand, SIGNAL(returnPressed()), SLOT (slotReturnPressed())); 
 connect (m_pcmd, SIGNAL(clicked()), SLOT (slotReturnPressed())); 
 
 // lay-out setup:
 QHBoxLayout* phbxLayout = new QHBoxLayout;
 phbxLayout->addWidget(m_plabel);
 phbxLayout->addWidget(m_ptxtCommand);
 phbxLayout->addWidget(m_pcmd);
 
 QVBoxLayout* pvbxLayout = new QVBoxLayout;
 pvbxLayout->addWidget(m_ptxtDisplay);
 pvbxLayout->addLayout(phbxLayout);
 
 setLayout(pvbxLayout);
 
}

Shell::~Shell()
{

}

void Shell::slotDataOnStdout()
{
  m_ptxtDisplay->append(m_process->readAllStandardOutput());
}


void Shell::slotReturnPressed()
{
  QString strCommand = "";
  strCommand = "cmd /C";
  strCommand += m_ptxtCommand->text();
  m_process->start(strCommand);
}

 
MyWidget::MyWidget (QWidget *parent)
      : QWidget(parent)
{
    setFixedSize(350, 220);    
    line3 = new QLineEdit (this); 
    bExit  = new QPushButton ("&Exit", this);
    bRnd   = new QPushButton ("&RND", this);    
    QVBoxLayout *mainLayout = new QVBoxLayout;
 
    line3->setReadOnly (true);        
    mainLayout->addWidget(line3);    
    mainLayout->addWidget(bRnd);
    mainLayout->addWidget(bExit);            
    setLayout(mainLayout);    
    
    connect (bRnd, SIGNAL(clicked ()), this, SLOT (setValue()));
    connect (bExit, SIGNAL(clicked ()), this, SLOT (onExit ()));
}
 
MyWidget::~MyWidget ()
{
 
}

void MyWidget::setValue()
{ 
 line3->setText(QString::number(GetRNDValue()));
}

int MyWidget::GetRNDValue()
{
int nRetVal=0;
static int nFirstTime = 1;

 if (1 == nFirstTime)
 {
  qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
  nFirstTime = 0;
 }
 nRetVal = (int)qrand(); 
 
 return nRetVal;
}
 
void MyWidget::onExit()
{
 close(); 
}	