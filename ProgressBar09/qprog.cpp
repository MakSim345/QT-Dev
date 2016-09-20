#include "qprog.h"

QProg::QProg(QWidget *parent) : QWidget(parent)
{
    initValue();
}

void QProg::initValue()
{
    minVal = 0;
    maxVal = 100;
    actVal = 0;
    nPosValLb = 410; // orig 360
    fontDim = 20;
    precision = 0;
    lengthBar = 0;
    colBar = Qt::green;
    m_sizeW= 90;
    m_sizeH= 470;
    nValueRectX=10;
    nValueRectY= 8;
}

void QProg::paintEvent(QPaintEvent *)
{
    paintBorder();
    paintBar();
    paintLine();
    paintValue();
}

void QProg::paintBorder()
{
    //int m_sizeW= 90;
    //int m_sizeH= 470;
    QPainter painter(this);
    painter.setWindow(0, 0, m_sizeW, m_sizeH);
    painter.setRenderHint(QPainter::Antialiasing);
    
    int m_linGradY = 40;
    //QLinearGradient linGrad(5, 40, 15, 40);
    // QLinearGradient linGrad(36, 5, 5, 15);
    QLinearGradient linGrad (40, m_sizeH-7, 40, m_sizeH-18);
    //QLinearGradient linGrad(m_sizeH, 5, m_sizeH, 15);
    linGrad.setColorAt(0, Qt::white);
    linGrad.setColorAt(1, Qt::black);
    linGrad.setSpread(QGradient::PadSpread);
    painter.setBrush(linGrad);
    QRectF border(5, 5, m_sizeW-10, m_sizeH-10);
    //QRectF border(0, 0, m_sizeW-10, m_sizeH);
    painter.drawRoundRect(border, 20, 5);

    // value rect
    painter.setBrush(QColor(70, 70, 70));
    QRectF value(nValueRectX, nValueRectY, m_sizeW/1.3, m_sizeH/15);
    painter.drawRoundRect(value, 15);

}

void QProg::paintBar()
{
    //int nPosValLb = 401; // orig 360
    QPainter painter(this);
    // painter.setWindow(0, 0, 470, 80);
    painter.setWindow(0, 0, m_sizeW, m_sizeH);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QColor(70, 70, 70));
    // painter.setBrush(QColor(200, 10, 0));
    //background color
    
    // QRectF back(20, 10, 360, 60);
    QRectF back(5, m_sizeH/15 + 10, m_sizeW-10, m_sizeH-60);
    painter.drawRoundRect(back, 3);
    // chech value
    if (actVal > maxVal)
        return;
    if (actVal < minVal)
        return;
    // waiting state if min = max
    if(minVal == maxVal)
    {
      //painter.setBrush(colBar);
      //QRectF bar(40, 10, 40, 60);
      //QRectF bar1(130, 10, 40, 60);
      //QRectF bar2(220, 10, 40, 60);
      //QRectF bar3(310, 10, 40, 60);
      //painter.drawRoundRect(bar, 3);
      //painter.drawRoundRect(bar1, 3);
      //painter.drawRoundRect(bar2, 3);
      //painter.drawRoundRect(bar3, 3);
      return;
	}
	
   	// check positive or negative scale
    if (maxVal >= 0 && minVal >= 0 || maxVal >= 0 && minVal <= 0)
    {
        lengthBar = nPosValLb - nPosValLb * (maxVal-actVal)/(maxVal-minVal);
    }
    if (maxVal <= 0 && minVal <= 0)
    {
        lengthBar = nPosValLb * (minVal-actVal)/(minVal-maxVal);
    }
    // length and color bar
    painter.setBrush(colBar);
    // QRectF bar(20, 10, lengthBar, 60);
    QRectF bar(5, m_sizeH-20, m_sizeW-10, -lengthBar);
    painter.drawRoundRect(bar, 3);
    emit valueChanged(actVal);
}

void QProg::paintLine()
{
    QPainter painter(this);
    int nValTmp = 0;
    int startPic = m_sizeH - 20; 
    // painter.setWindow(0, 0, 470, 80);
    painter.setWindow(0, 0, m_sizeW, m_sizeH);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    qDebug("Start\n");
    // painter.drawLine(5, 470, m_sizeW-5, 470);
    for (int i = 0; i <= 58; i++)
    {
        nValTmp = startPic-420*i/60;
        //painter.drawLine(20 + (360/40*i), 10, 20 + (360/40*i), 70);
        painter.drawLine(6, nValTmp, m_sizeW-7, nValTmp);
        qDebug("Res(%d) = %d", i, nValTmp);
    }
}

void QProg::paintValue()
{
    QPainter painter(this);
    // painter.setWindow(0, 0, 470, 80);
    painter.setWindow(0, 0, m_sizeW, m_sizeH);
    painter.setRenderHint(QPainter::Antialiasing);
    QRectF value(nValueRectX, nValueRectY, m_sizeW/1.3, m_sizeH/15);
    //QRectF value(10, 7, m_sizeW/1.3, m_sizeH/15);
    // QRectF value(385, 10, 75, 60);
    QFont font("Arial", fontDim, QFont::Normal);
    painter.setFont(font);
    painter.setPen(QPen(Qt::white));
    double x = 100;
    double y = 360;
    QString val = QString("%1").arg(lengthBar*(x/y), 0, 'f', precision);
    // val.append("%");
    painter.drawText(value, Qt::AlignCenter, val);

}

void QProg::setProgrBarValue(int nVal)
{
  setValue(nVal); 
}

void QProg::setValue(double value)
{
    if (value > maxVal)
    {
    	actVal = maxVal;
    	update();
    	return;    	
   	}
    if (value < minVal)
    {
    	actVal = minVal;
    	update();
    	return;    	
   	}
    actVal = value;
    update();
}

void QProg::setMinValue(double min)
{
    if (min > maxVal)
    {
    	minVal = maxVal;
    	maxVal = min;
    	actVal = minVal;
    	update();
    	return;
   	}
    minVal = min;
    update();
}

void QProg::setMaxValue(double max)
{
    if (max < minVal)
    {
    	maxVal = minVal;
    	minVal = max;
    	actVal = minVal;
    	update();
    	return;
   	}
    maxVal = max;
    update();
}

void QProg::setFontDim(int font)
{
    fontDim = font;
    update();
}

void QProg::setPrecision(int numPrec)
{
    precision = numPrec;
    update();
}

void QProg::setBarColor(QColor color)
{
    colBar = color;
    update();
}


QSize QProg::minimumSizeHint() const
{
    return QSize(m_sizeW, m_sizeH/10);
}

QSize QProg::sizeHint() const
{
    return QSize(m_sizeW, m_sizeH);
    
}


