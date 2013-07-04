#ifndef _BELOWS_PRG_
#define _BELOWS_PRG_

#include <QFrame>

 class BelowsPrg : public QFrame
 {
 	 Q_OBJECT
 	 	 
 protected:
    int m_nProgress;
    virtual void paintEvent(QPaintEvent*);
 
 	 		
 public:
     BelowsPrg(QWidget *parent = 0);
     virtual QSize sizeHint() const;
     
 signals:
 	 void progressChanged(int N);
 
 public slots:
 	 void slotSetProgress(int N);
 };
 
#endif // _BELOWS_PRG_