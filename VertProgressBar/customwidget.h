#ifndef _CUSTOM_WIDGET_
#define _CUSTOM_WIDGET_

#include <QtGui>

 class CustomWidget : public QFrame
 {
 	 Q_OBJECT
 	 	 
 protected:
    int m_nProgress;
    int m_pressed;    
    int m_pressedPoint;
    float f;
    QPoint m_pos;
    
    bool hitLabel(const QPoint &p);
    virtual void paintEvent(QPaintEvent*);
    
    void mouseDoubleClickEvent ( QMouseEvent * eMouseEvent);
    void mousePressEvent( QMouseEvent *eMouseEvent);
    void mouseMoveEvent( QMouseEvent *eMouseEvent);
    void mouseReleaseEvent( QMouseEvent *eMouseEvent);
    
    void drawNewLevelUp(int nValue);
    void drawNewLevelDown(int nValue);
  	 		
 public:
     CustomWidget(QWidget *parent = 0);
     virtual QSize sizeHint() const;
     
 signals:
 	 void progressChanged(int nValue);
 
 public slots:
 	 void slotSetProgress(int nValue);
 };
 
#endif // _CUSTOM_WIDGET_