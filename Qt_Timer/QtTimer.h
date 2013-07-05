/***************************************************************************
 *   Copyright (C) 2008 by P. Sereno                                       *
 *   http://www.sereno-online.com                                          *
 *   http://www.qt4lab.org                                                 *
 *   http://www.qphoton.org                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef QTTIMER_H
#define QTTIMER_H

#include <Qt>
#include <QWidget>

#include "ui_QtTimer.h"


class QtTimer : public QWidget, public Ui::QtTimerWidget
{
 Q_OBJECT
    
	Q_PROPERTY( int value READ value WRITE setValue);
	
public: 
   
    QtTimer(QWidget *parent = 0);
    bool value() const { return m_value; }
  
public slots:
	void setValue(int);
	void setTimer(int);
    void start();
    void stop();
    void resetValue();

signals:
    void timeSignal(int);
    void timePulse();

protected:
     int m_value;
     int m_timerID;
     void timerEvent ( QTimerEvent * event );
    //void paintEvent(QPaintEvent *event);

};

#endif
