#include <string>
#include <stdlib.h>
#include <iostream>
#include "fibo_thread.h"

using namespace std;

FiboThread::FiboThread()
   : m_nValue(0)
   , m_RetValue(0)
   , m_Iteration(0)   
{
	fibo_timer = new QTimer();
	connect (fibo_timer, SIGNAL(timeout()), this, SLOT(slotNextValue()));
    fibo_timer->start(100); 
}

void FiboThread::setMValue(int i)
{
    m_nValue = i;
}

int FiboThread::getMValue(void)
{
    return m_nValue;
}

void FiboThread::setMessage(const QString &message)
{

}

int FiboThread::fib(int f)
{
    m_Iteration++;
    //emit currentIteration(m_Iteration);

    if (f<2)
    {
        return 1;
    }
    else
    {
        return fib(f - 1) + fib(f - 2);
    }
}

void FiboThread::run()
{
    m_RetValue = 0;
    m_Iteration = 0;
    //fibo_timer->start(100); 
    emit currentIteration(m_Iteration);
    emit currentValue(m_RetValue);
    m_RetValue = fib(this->m_nValue);
    emit currentValue(m_RetValue);
	//fibo_timer->stop(); 

    emit finished();

    //connect (&fibo_timer, SIGNAL(timeout()), SLOT(slotNextValue()));
    //exec();  
}

void FiboThread::slotNextValue()
{
    emit currentIteration(m_Iteration);
  
     // qDebug() << "currentIteration" << m_Iteration;
	std::cout << "currentIteration" << m_Iteration << "\n";

     /*if (!m_nValue)
    { 
      emit finished(); 
    }*/
}

