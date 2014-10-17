#include "mythread.h"

MyThread::MyThread(QObject *parent)
: QThread(parent)
{
}

void MyThread::run()
{
	qDebug() << "Executing in new independant thread, GUI is NOT blocked";
		
	for(int i=0;i<10;i++)
	{
		qDebug() << "Time: " << 10-i;	

		int t=1;

		// some OS specific stuff
		// mingw (3.4.2) sleep on windows is called _sleep and uses microseconds
		#ifdef Q_OS_WIN32
		t = t * 1000;
		_sleep(t);
		#else
		sleep(t);
		#endif

	}
	
	qDebug() << "Execution done";
	
	exec();
}




