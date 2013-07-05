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
 
#include <QColor>
#include <QtGlobal>
#include <QtGui>
#include <QPolygon>

#include "QtTimer.h"

QtTimer::QtTimer(QWidget *parent)
    : QWidget(parent)
{

    setupUi(this);
    connect(startButton,SIGNAL(released()),this,SLOT(start()));
    connect(stopButton,SIGNAL(released()),this,SLOT(stop()));
    connect(resetButton,SIGNAL(released()),this,SLOT(resetValue()));
    connect(spinBox,SIGNAL(valueChanged(int)),this,SLOT(setValue(int)));
    m_value=0;
    //setAttribute( Qt::WA_DeleteOnClose );

   //setMinimumSize(QSize(50,50));
   //setFocusPolicy(Qt::StrongFocus);
   
}


void QtTimer::setTimer( int value)
{
   dial->setValue(value);	
   stop();
}


void QtTimer::setValue( int value)
{
   m_value=value;	
   stop();
}


void QtTimer::resetValue()
{
   m_value=0;
}


void QtTimer::start()
{
  stopButton->setChecked(false);
  startButton->setStyleSheet("color: red");
 
  if(sRadioButton->isChecked())
    m_timerID=startTimer(dial->value()*1000);
  else    
    m_timerID=startTimer(dial->value());
}


void QtTimer::stop()
{
  startButton->setChecked(false);
  startButton->setStyleSheet("color: black");
  killTimer(m_timerID);
  resetValue();
}


void QtTimer::timerEvent ( QTimerEvent * event )
{
  timeSignal(++m_value);
  timePulse();
}
