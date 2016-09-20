/* mywidget.cpp */
#include <QtGui>
#include "mywidget.h"
 

// MyWidget::MyWidget()
 MyWidget::MyWidget(QWidget *parent)
      : QWidget(parent)
{
    // resize (300, 200);
    
    nLineEditNum = 1;
    int minX = 150;
    int minY = 50;
    
    line1 = new QLineEdit();
    line2 = new QLineEdit();
    line3 = new QLineEdit();
    
    line1->setMinimumSize(minX, minY);
    line2->setMinimumSize(minX, minY);
    line3->setMinimumSize(minX, minY);
 
    bcalc = new QPushButton ("Calculate");
    bclear = new QPushButton ("Clear");
    bExit  = new QPushButton ("&Exit");
    bRnd   = new QPushButton ("&RND");
    
    bcalc->setMinimumSize(minX, minY);
    bclear->setMinimumSize(minX, minY);
    bExit->setMinimumSize(minX, minY);
    bRnd->setMinimumSize(minX, minY);
    
    labplus = new QLabel ("+");
    labis = new QLabel ("=");
    
  	hLayout2 =new QHBoxLayout;	 
	hLayout = new QHBoxLayout;
	mainLayout = new QVBoxLayout;
	
	hLayout->addWidget(line1);
	hLayout->addWidget(labplus);
	hLayout->addWidget(line2);
	hLayout->addWidget(labis);
	hLayout->addWidget(line3);
	
	hLayout2->addWidget(bcalc);
	hLayout2->addWidget(bclear);
	hLayout2->addWidget(bRnd);
	
	mainLayout->addLayout(hLayout);
	mainLayout->addLayout(hLayout2);
	mainLayout->addWidget(bExit);
	
	setLayout(mainLayout);
	
 /*
    line1->move (20, 30); line1->resize (50, 20);
    labplus->move (85, 30); labplus->resize (20, 20);
    line2->move (110, 30); line2->resize (50, 20);
    labis->move (180, 30); labis->resize (20, 20);
    line3->move (210, 30); line3->resize (50, 20);
    line3->setReadOnly (true);
    bcalc->move (80, 80); bcalc->resize (100, 30);
    bclear->move (180, 80); bclear->resize (80, 30);
    bExit->move (80, 150); bExit->resize (180, 30);
    bRnd->move (180, 150); bExit->resize (180, 30);
*/
    connect (bcalc, SIGNAL(clicked ()), this, SLOT (slotCalc ()));
    connect (bclear, SIGNAL(clicked ()), this, SLOT (slotClear ()));
    connect (bExit, SIGNAL(clicked ()), this, SLOT (onExit ()));
    connect (bRnd, SIGNAL(clicked ()), this, SLOT (GetRNDValue()));
}
 
MyWidget::~MyWidget ()
{
 
}

int MyWidget::GetRNDValue()
{
 
 static int nFirstTime = 0;
 int nRandomValue = 0;
 QString tmp;
   
 if (0 == nFirstTime)
 {
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
   nFirstTime = 1;
 }
 
 nRandomValue = (int)qrand(); 
 
 if (1 == nLineEditNum)
 {
  nLineEditNum = 2;
  line1->setText (tmp.setNum (nRandomValue));
 }
 else if (2 == nLineEditNum)
 {
  nLineEditNum = 1;
  line2->setText (tmp.setNum (nRandomValue));
 }
 
 return 1;
}
 
void MyWidget::onExit()
{
 close();
} 
 
void MyWidget::slotCalc ()
{
    double d;
    QString tmp;
    d = line1->text().toDouble ();
    d += line2->text().toDouble ();
    line3->setText (tmp.setNum (d));
}

void MyWidget::slotClear ()
{
    line1->setText ("");
    line2->setText ("");
    line3->setText ("");
}
