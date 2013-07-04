#include <QtGui>
  
 #include "belows_prg.h"

 BelowsPrg::BelowsPrg(QWidget *parent)
     : QFrame(parent),
        m_nProgress(0)
 {
    setLineWidth(3);
    setFrameStyle(Box | Sunken);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
 }
 
void BelowsPrg::paintEvent(QPaintEvent*)
{
   QPainter painter (this);
       
   painter.setPen(Qt::NoPen);
   painter.setBrush(Qt::darkGray);
   painter.drawEllipse(7, 7, 20, 20);

   QRadialGradient gradient(3, 3, 10);
   if (1)//(option->state & QStyle::State_Sunken) 
   {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, QColor(Qt::yellow).light(120));
        gradient.setColorAt(0, QColor(Qt::darkYellow).light(120));
   }
   else 
   {
        gradient.setColorAt(0, Qt::yellow);
        gradient.setColorAt(1, Qt::darkYellow);
   }
   painter.setBrush(gradient);
   painter.setPen(QPen(Qt::black, 0));
   painter.drawEllipse(10, 10, 20, 20);
    
    return;
   
   //QLinearGradient gradient(0,0, width(), height());
   float f = m_nProgress / 1000.0f;

   // gradient.setColorAt(f, Qt::black);
   
   gradient.setColorAt(1, Qt::blue);
   gradient.setColorAt(0, Qt::gray);

   painter.fillRect(rect(), Qt::black);
   painter.setBrush(gradient);
   // painter.drawRect(0,0, (int)width() * f, height());
   // painter.drawRect(0,0, (int)height() * f, width());
   painter.drawRect(width(), height(), -100, -(int)height() * f);
   painter.setPen(QPen(Qt::green));

   //QString str = QString().setNum(m_nProgress) + " %";
   QString str = QString().setNum(m_nProgress);
   painter.drawText(rect(), Qt::AlignCenter, str);
   drawFrame(&painter);

}

QSize BelowsPrg::sizeHint() const
{
 return QSize(90,300);
}

void BelowsPrg::slotSetProgress(int n)
{
    m_nProgress = n > 1000 ? 1000 : n < 0 ? 0 : n;
    repaint();
    emit progressChanged(m_nProgress);
}