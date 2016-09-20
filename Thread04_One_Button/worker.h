#ifndef _MY_THREAD_H_
#define _MY_THREAD_H_

//============================================================
//
// Copyright (c) 2011 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           Worker.h
// Project:        Genie Carestation SW
//
// Author:         YS / Genie SW Team
//
//============================================================
// Description:
//==========================================================
#include <QtCore>
#include <QtGui>

class Worker : public QThread
{
    Q_OBJECT
    
public:
    Worker();
    void setMessage(const QString &message);
    void setMValue(int);
    int  getMValue(void);
    void render(QSize size, int stars);
    int  GetRNDValue(int minVal, int nMaxVal);
    // void stop();

public slots:
	void slotNextValue();

protected:
    void run();
    
private:
	int m_nValue;
    int stars;
    bool exiting;
    QSize m_size;
    QString messageStr;    
    volatile bool stopped;
    int outerRadius;
    int innerRadius;
    QPainterPath path;
    
signals:
	//void finished();
    void currentValue(int);    
    void output(QRect, QImage);
};

#endif // THREAD_H
