#include <QtGui>
  
 #include "customwidget.h"

 CustomWidget::CustomWidget(QWidget *parent)
     : QFrame(parent),
        m_nProgress(0)
 {
    setLineWidth(3);
    setFrameStyle(Sunken);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
 }
 
void CustomWidget::paintEvent(QPaintEvent*)
{
   QPainter painter (this);
   QLinearGradient gradient(0,0, width(), height());
   float f = m_nProgress / 100.0f;

   //gradient.setColorAt(f, Qt::black);
   gradient.setColorAt(0, Qt::blue);

   painter.fillRect(rect(), Qt::black);
   painter.setBrush(gradient);
   // painter.drawRect(0,0, (int)width() * f, height());
   // painter.drawRect(0,0, (int)height() * f, width());
   painter.drawRect(width(), height(), -100, -(int)height() * f);
   painter.setPen(QPen(Qt::green));

   QString str = QString().setNum(m_nProgress) + "%";
   painter.drawText(rect(), Qt::AlignCenter, str);
   drawFrame(&painter);

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