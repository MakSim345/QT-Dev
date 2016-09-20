
#include <QtCore/QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*
    MyThread mThread1;
    mThread1.my_name ="one";
    mThread1.start();
    */

    cout << "Press <Enter> to quit:" << endl;
    DisplayTask* dt = new DisplayTask("mythread.h");
    // DisplayTask t(dt);
    dt->run();
    cin.get(); // waitinging for <Enter> all stuff is on thread
    dt->quit();
    // exit(0);
    cout << "Shutting down...." << endl;

    return a.exec();
}
