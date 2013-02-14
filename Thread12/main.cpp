
#include <QtCore/QCoreApplication>
#include <QList>
#include <QDebug>
#include "mythread.h" 

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList <int> List;
    for (int i = 0; i < 10; i++)
    {
        List.append(i);
    }

    foreach (int mNumber, List)
    {
        qDebug() << mNumber;
    }
    /*
    MyThread mThread1;
    mThread1.my_name ="one";

    MyThread mThread2;
    mThread2.my_name ="two";

    MyThread mThread3;
    mThread3.my_name ="three" ;
    
    mThread1.start(QThread::HighestPriority);
    mThread2.start();
    mThread3.start(QThread::LowestPriority);
    */
    return a.exec();
}
