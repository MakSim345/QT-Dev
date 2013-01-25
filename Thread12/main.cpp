
#include <QtCore/QCoreApplication>
#include "mythread.h" 

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mThread1;
    mThread1.my_name ="one";
    mThread1.start();

    MyThread mThread2;
    mThread2.my_name ="two";
    mThread2.start();

    MyThread mThread3;
    mThread3.my_name ="three" ;
    mThread3.start();

    return a.exec();
}
