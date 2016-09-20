#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtGui>

class MyThread : public QThread
{
	Q_OBJECT

public:
	MyThread(QObject *parent);
	void run(); // this is virtual method, we must implement it in our subclass of QThread
};


#endif
