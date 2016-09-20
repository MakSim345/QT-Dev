#ifndef _CUSTOM_WIDGET_
#define _CUSTOM_WIDGET_

#include <QtGui>
#include <QFrame>
#include <QPoint>
#include <QSize>

 class CustomWidget : public QFrame
 {
 	 Q_OBJECT
 	 	 
 protected:
    int m_nProgress;
    int m_pressed;
    float f;
    int m_pressedPoint;
    QPoint m_pos;
    bool hitLabel(const QPoint &p);
    virtual void paintEvent(QPaintEvent*);
    
    void mouseDoubleClickEvent ( QMouseEvent * e );
    void mousePressEvent( QMouseEvent *e);
    void mouseMoveEvent( QMouseEvent *e);
    void mouseReleaseEvent( QMouseEvent *e);
    void drawNewLevelUp(int nValue);
    void drawNewLevelDown(int nValue);
  	 		
 public:
     CustomWidget(QWidget *parent = 0);
     virtual QSize sizeHint() const;
     
 signals:
 	 void progressChanged(int N);
 
 public slots:
 	 void slotSetProgress(int N);
 	 void dummy(int N);
 };
 
#endif // _CUSTOM_WIDGET_