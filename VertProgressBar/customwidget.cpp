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
   painter.drawRect(width(), height(), -100 * (int)width(), -(int)height() * f);
   painter.setPen(QPen(Qt::green));
   
   // draw a circle:
   painter.setBrush(Qt::blue);
   painter.drawEllipse(width()/4, -(height()*f) + (height()-(width()/4)), width()/2, width()/2);
   //qDebug("height()*f = %f\n", height() * f);
   //qDebug("width()/2 = %d\n", width()/2);
   drawFrame(&painter);

}

QSize CustomWidget::sizeHint() const
{
 return QSize(20,300);
}

void CustomWidget::slotSetProgress(int n)
{
    m_nProgress = n > 100 ? 100 : n < 0 ? 0 : n;
    emit progressChanged(m_nProgress);
    repaint();
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
       if  (underMouse())
       {
         f = m_nProgress / 100.0;
         m_pos = eMouseEvent->pos();
         m_pressedPoint = height() - m_pos.y();
         //qDebug ("m_pressedPoint =", self.height() - pos.y());
         //qDebug ("paintEvent: - self.height()*f = ", - self.height()*f);
                
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
        //qDebug ("self.m_pressed set to False");
}

void CustomWidget::mouseMoveEvent( QMouseEvent *eMouseEvent)
{
  m_pos = eMouseEvent->pos();
  m_pressedPoint = height() - m_pos.y();
  
  if(eMouseEvent->button() == Qt::LeftButton)           
    {
     //qDebug("mouseMoveEvent: LeftButton ON");
    }    
  else
    {
     //qDebug("mouseMoveEvent: LeftButton OFF");
    }
           
  // qDebug ("self.underMouse() = ", self.underMouse());
  // TracePrint(eMouseEvent)
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