
#include <QtCore/QCoreApplication>
#include "mythread.h" 

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mThread1;
    mThread1.my_name ="one";

    MyThread mThread2;
    mThread2.my_name ="two";

    MyThread mThread3;
    mThread3.my_name ="three" ;
    
    mThread1.start(QThread::HighestPriority);
    mThread2.start();
    mThread3.start(QThread::LowestPriority);

    return a.exec();
}
