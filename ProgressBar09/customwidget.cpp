#include <QtGui>
#include <QMouseEvent> 
  
 #include "customwidget.h"

 CustomWidget::CustomWidget(QWidget *parent)
     : QFrame(parent),
        m_nProgress(0),
        f(0.0)
 {
    setLineWidth(3);
    setFrameStyle(Sunken);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
 }
 
void CustomWidget::paintEvent(QPaintEvent*)
{
   QPainter painter (this);
   QLinearGradient gradient(0,0, width(), height());
   f = m_nProgress / 100.0f;

   gradient.setColorAt(f, Qt::green);
   gradient.setColorAt(0, Qt::blue);

   painter.fillRect(rect(), Qt::black);
   painter.setBrush(gradient);
   // painter.drawRect(0,0, (int)width() * f, height());
   // painter.drawRect(0,0, (int)height() * f, width());
   
   painter.drawRect(width(), height(), -100 * (int)width(), -(int)height() * f);
   painter.setPen(QPen(Qt::green));
   
   // draw a circle:
   // QRadialGradient gradientRad(50, 50, 50, 30, 30);
   /*
   QRadialGradient::QRadialGradient ( qreal cx, qreal cy, qreal radius, qreal fx, qreal fy )
   Constructs a radial gradient with the given center (cx, cy), radius and focal point (fx, fy).
   */
   //QRadialGradient gradientRad(50, 50, 50, 30, 30);
   //gradientRad.setColorAt(0.2, Qt::white);
   //gradientRad.setColorAt(0.8, Qt::green);
   //gradientRad.setColorAt(1, Qt::black);
   // painter.setBrush(gradientRad);
   painter.setBrush(Qt::blue);
   painter.drawEllipse(width()/4, -(height()*f) + (height()-(width()/4)), width()/2, width()/2);
   //qDebug("height()*f = %f\n", height() * f);
   //qDebug("width()/2 = %d\n", width()/2);
   // painter.drawEllipse(10, -20, 20, 40);

   // QString str = QString().setNum(m_nProgress) + "%";
   // QString str = QString().setNum(m_nProgress);
   // painter.drawText(rect(), Qt::AlignCenter, str);
   drawFrame(&painter);

}

void CustomWidget::dummy(int N)
{
 printf ("n=%d", N);
}

QSize CustomWidget::sizeHint() const
{
 return QSize(20,300);
}

void CustomWidget::slotSetProgress(int n)
{
    m_nProgress = n > 100 ? 100 : n < 0 ? 0 : n;
    repaint();
    emit progressChanged(m_nProgress);
}

void CustomWidget::mouseDoubleClickEvent( QMouseEvent * e )
{
    if(e->button() == Qt::LeftButton)
      printf ("test");
      
    //emit doubleClicked();        
    QFrame::mouseDoubleClickEvent(e);
}

void CustomWidget::mousePressEvent( QMouseEvent * eMouseEvent ) 
{
    if(eMouseEvent->button() == Qt::LeftButton)
    {
       m_pressed = true;
       // print "self.underMouse() = ", self.underMouse()        
       if  (underMouse())
       {
         f = m_nProgress / 100.0;
         m_pos = eMouseEvent->pos();
         m_pressedPoint = height() - m_pos.y();
         //print "m_pressedPoint =", self.height() - pos.y()            
         //print "paintEvent: - self.height()*f = ", - self.height()*f
                
         if ((m_pressedPoint) > (height()*f))
         { 
            if (m_pressedPoint <= (height()*(f+0.1)))
              drawNewLevelUp((m_pressedPoint*100.0)/height());//  draw to cursor
            else
              drawNewLevelUp(0); //draw + 10%;
         }     
         
         if ((m_pressedPoint) < (height()*f))
         {
            if (m_pressedPoint >= (height()*(f-0.1)))
              drawNewLevelDown((m_pressedPoint*100.0)/height()); // draw to cursor
            else
              drawNewLevelDown(0);// draw + 10%
         }
        }       
        //emit pressed();
     }
     else
        m_pressed = false;
            //print "self.m_pressed set to False"

    
}

void CustomWidget::mouseMoveEvent( QMouseEvent *eMouseEvent)
{
  m_pos = eMouseEvent->pos();
  m_pressedPoint = height() - m_pos.y();
  //if pos.x() <= 0:
  //    pos.setX(1)
  //if pos.y() >= self.height():
  //    pos.setY(self.height() - 1)
  //rad = math.atan((float(self.rect().bottom()) - pos.y()) / pos.x())
  //self.setAngle(QtCore.qRound(rad * 180 / 3.14159265))

  //self.m_nProgress = pos.y()
  if(eMouseEvent->button() == Qt::LeftButton)           
    printf ("mouseMoveEvent: LeftButton ON");
  else
    printf ("mouseMoveEvent: LeftButton OFF");
           
  // printf "self.underMouse() = ", self.underMouse()
  // self.TracePrint(eMouseEvent)
  this->drawNewLevelUp((m_pressedPoint*100.0)/height()); // draw to cursor
  this->update();
  QFrame::mouseMoveEvent(eMouseEvent);
}

void CustomWidget::mouseReleaseEvent( QMouseEvent * e ) 
{

    if(m_pressed && e->button() == Qt::LeftButton && hitLabel(e->pos()))
    {
     // emit clicked();
    }
    m_pressed = false;
    // emit released();
}

bool CustomWidget::hitLabel( const QPoint & p )
{
  return rect().contains(p);
} 


void CustomWidget::drawNewLevelUp(int nValue)
{
  
  if (0 == nValue)
      slotSetProgress(m_nProgress + 10 );
  else 
      slotSetProgress(nValue);

}

void CustomWidget::drawNewLevelDown(int nValue)
{
  
  if (0 == nValue)
      slotSetProgress(m_nProgress - 10 );
  else 
      slotSetProgress(nValue);

}