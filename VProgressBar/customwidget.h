#ifndef _CUSTOM_WIDGET_
#define _CUSTOM_WIDGET_

#include <QFrame>

 class CustomWidget : public QFrame
 {
 	 Q_OBJECT
 	 	 
 protected:
    int m_nProgress;
    virtual void paintEvent(QPaintEvent*);
 
 	 		
 public:
     CustomWidget(QWidget *parent = 0);
     virtual QSize sizeHint() const;
     
 signals:
 	 void progressChanged(int N);
 
 public slots:
 	 void slotSetProgress(int N);
 };
 
#endif // _CUSTOM_WIDGET_