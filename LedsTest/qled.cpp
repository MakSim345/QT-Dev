#include <QColor>
#include <QtGlobal>
#include <QtGui>
#include <QPolygon>


#include "qled.h"

QLed::QLed(QWidget *parent)
    : QWidget(parent)
{
   m_value=false;
   m_color=Qt::red;
   setMinimumSize(QSize(50,50));
   
}

void QLed::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setWindow( -50,-50,100,100);
	
	painter.setPen(Qt::white);
	painter.drawArc(-25,-25,50,50,0,5670);
	painter.drawArc(-32,-33,66,66,0,5670);
	painter.setPen(Qt::darkGray);
	painter.drawArc(-34,-33,66,66,3400,3000);
	
    if(m_value)
    {
      QRadialGradient radialGrad(QPointF(-8, -8), 20);
      radialGrad.setColorAt(0, Qt::white);       
      radialGrad.setColorAt(1, m_color);
   	  QBrush brush(radialGrad);
      painter.setBrush(brush);
      painter.setPen(Qt::black);
	  painter.drawEllipse(-25,-25,50,50);
    }
    else
    {
      QRadialGradient radialGrad(QPointF(-8, -8), 20);
      radialGrad.setColorAt(0, Qt::white);
      // radialGrad.setColorAt(1, Qt::lightGray);
      radialGrad.setColorAt(1, Qt::green);      
   	  QBrush brush(radialGrad);
      painter.setBrush(brush);
	  painter.drawEllipse(-25,-25,50,50);
    }	
}

void QLed::setColor(QColor newColor)
{
   m_color=newColor;
   update();
}


void QLed::setValue(bool value)
{
   m_value=value;
   update();
}


void QLed::toggleValue()
{ 
	m_value=!m_value;
	update();
	return; 
}
