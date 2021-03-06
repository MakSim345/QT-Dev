//============================================================
//
//
//============================================================
//
// File:           Worker.cpp
//
//============================================================
// Description:
//============================================================
#include "worker.h"
//----------------------------------------------------------------------------
//
// thread which runs the time-consuming image generation
//
//----------------------------------------------------------------------------

// constructor
timeConsumingThread::timeConsumingThread(QObject *parent)
 : QThread(parent)
{
    //_rndGen = new RND_Generator();
}

// run - paint the QImage
void timeConsumingThread::run()
{
   int i_ctr = 60;
   int j_ctr = 60;
   QImage myQImage(i_ctr, j_ctr, QImage::Format_RGB32);
   QPainter painter(&myQImage);
   for (int nMainCounter = 0; nMainCounter < 1000; nMainCounter++)
   {
    for (int i=0; i<i_ctr; i++)
    {
      for (int j=0; j<j_ctr; j++)
      {
         double hue = (double)(i + j + i*j)/361200.0;
         QColor myColor;
         myColor.setHsvF(hue, 1.0, 1.0, 1.0);
         painter.setPen(myColor);
         painter.drawPoint(i, j);
      }
    }   
    // emit theImage(myQImage);
    int x = GetRNDValue(0, 600);
    int y = GetRNDValue(0, 600);
    emit theImage(QRect(x, y, i_ctr, j_ctr), myQImage);
   }
}

int timeConsumingThread::GetRNDValue(int minVal, int nMaxVal)
{
// #define QT_RANDOM
    int nRetVal=0;
    static int nFirstTime = 1;

#ifdef QT_RANDOM
    
    if (0 == nFirstTime)
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        nFirstTime = 1;
    }

    int RND=(int)qrand();
    
    qDebug("qrand: %d", RND);

    nRetVal = minVal + (RND % nMaxVal);
    
    qDebug("nRetVal: %d", nRetVal);
    //nRetVal = (int)qrand(); 
#endif

#ifndef QT_RANDOM
    if (1 == nFirstTime)
    {
        srand (time (NULL));
        nFirstTime = 0;
    }
    int RND=rand();
    
    qDebug("RND: %d", RND);

    nRetVal = minVal + (RND % nMaxVal);
    
    qDebug("nRetVal: %d", nRetVal);

#endif

    //qDebug() << "Execution done";
    return nRetVal;
}


Worker::Worker()
{   
    exiting = false;
    //m_size = new QSize(0,0);
    stars = 0;
    
    QPainterPath path = QPainterPath();
    double angle = 2*M_PI/5;
    outerRadius = 20;
    innerRadius = 8;
    path.moveTo(outerRadius, 0);
    for (int step = 1; step < 6; step++) // in range(1,6):
    {
    
        path.lineTo(
                     innerRadius * cos((step - 0.5 )* angle),
                     innerRadius * sin((step - 0.5 )* angle)
                   );
        path.lineTo(
                    innerRadius * cos(step * angle),
                    innerRadius * sin(step * angle)
                   );
   
        path.closeSubpath();
    }
}

void Worker::render(QSize rend_size, int rend_stars)
{
    m_size = rend_size;
    stars = rend_stars;
    start(); //call RUN method.
}

void Worker::setMValue(int i)
{
    m_nValue = i;
}

int Worker::getMValue(void)
{
    return m_nValue;
}

void Worker::setMessage(const QString &message)
{

}

void Worker::slotNextValue()
{
    emit currentValue(--m_nValue);
  
    if (!m_nValue)
    { 
      //emit finished(); 
    }
}

int Worker::GetRNDValue(int minVal, int nMaxVal)
{
    int nRetVal=0;
    static int nFirstTime = 1;

    int RND_MAX = 65;

    if (1 == nFirstTime)
    {
        srand (time (NULL));
        nFirstTime = 0;
    }
    nRetVal = minVal + (rand() % nMaxVal);

    //qDebug() << "Time: " << nRetVal;
    //qDebug() << "Execution done";
    return nRetVal;
}

void Worker::run()
{
    // Note: this is never called directly. It is called by Qt once the 
    // thread environment has been set up        
    // random.seed();
    int n = stars;
    int m_width = m_size.width();
    int m_height= m_size.height();
        
    do {
        QImage myQImage = QImage(outerRadius * 2, outerRadius * 2, QImage::Format_ARGB32);
        myQImage.fill(qRgba(255, 255, 256, 0));
            
        int x = GetRNDValue(0, m_width);
        int y = GetRNDValue(0, m_height);
        
        int angle = GetRNDValue(0, 360);
        int red = GetRNDValue(0, 256);
        
        int green = GetRNDValue(0, 256);
        int blue = GetRNDValue(0, 256);
        int alpha = GetRNDValue(0, 256);
        
        //QPainter *painter = new QPainter();
        //painter->begin(&myQImage);
        QPainter painter(&myQImage);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(Qt::red);
        painter.setBrush(QColor(red, green, blue, alpha));
        painter.translate(outerRadius, outerRadius);
        painter.rotate(angle);
        painter.drawPath(path);
        //painter.end();              

      /*-----------
       QImage myQImage(60, 60, QImage::Format_RGB32);
       QPainter painter1(&myQImage);
        for (int i=0; i<60; i++)
        {
            for (int j=0; j<60; j++)
            {
                double hue = (double)(i + j + i*j)/361200.0;
                QColor myColor;
                myColor.setHsvF(hue, 1.0, 1.0, 1.0);
                painter1.setPen(myColor);
                painter1.drawPoint(i, j);
            }
        }
        */ //-----------

        emit output (QRect(x - outerRadius, y - outerRadius, outerRadius * 2, outerRadius * 2), myQImage);
        
        sleep(0.01);
        n --;
        qDebug("Iteration number %d\n", n);
    } while ((!exiting) && (n > 0));
}

#ifdef YS_TEST_15_SEP_2011

void Worker::run()
{
    QTimer timer;
    connect (&timer, SIGNAL(timeout()), SLOT(slotNextValue()));
    timer.start(1000); 
    exec();  
}

#endif
