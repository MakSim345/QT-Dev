#include <QtCore>
#include <QApplication>
#include "MyThread.h"
#include "MainWidget.h"

#include "stdlib.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

MainWidget::MainWidget(QWidget *parent)
     : QWidget(parent)
{
    // = QTime::currentTime();
    timeStamp.start();
    // timeStamp.elapsed()
    vector <int> DataArray;

    prb = new QProgressBar();
    filenameEdit = new QLineEdit();
    // resultEdit = new QLineEdit();

    lblThreadsResult = new QLabel("0.0");
    lblSerialResult = new QLabel("0.0");

    _exit_button = new QPushButton("Exit");
    _serial_button = new QPushButton("Start serial calc.");
    _thread_button = new QPushButton("Start threads calc.");

    _exit_button->setMinimumSize(150, 50);
    _serial_button->setMinimumSize(150, 50);
    _thread_button->setMinimumSize(150, 50);

    _counter = new Counter();

    _test_thread_1 = new MyThread();
    _test_thread_2 = new MyThread();
    _test_thread_3 = new MyThread();
    _test_thread_4 = new MyThread();

    vlayout = new QVBoxLayout();
    QHBoxLayout *hlayoutExit = new QHBoxLayout();
    QHBoxLayout *hlayoutTop = new QHBoxLayout();
    QVBoxLayout *hlayoutThreads = new QVBoxLayout();
    QVBoxLayout *hlayoutSerial = new QVBoxLayout();

    hlayoutThreads->addWidget(_thread_button);
    hlayoutThreads->addWidget(lblThreadsResult);

    hlayoutSerial->addWidget(_serial_button);
    hlayoutSerial->addWidget(lblSerialResult);

    hlayoutTop->addLayout(hlayoutThreads);
    hlayoutTop->addLayout(hlayoutSerial);

    hlayoutExit->addWidget(prb);
    hlayoutExit->addWidget(_exit_button);

    vlayout->addLayout(hlayoutTop);
    vlayout->addLayout(hlayoutExit);

    setLayout(vlayout);

    this->setConnections();
}

void MainWidget::setConnections()
{
    connect(_exit_button, SIGNAL(clicked()), this, SLOT (close()) );

    connect(_serial_button, SIGNAL(clicked()), this, SLOT (onStartCalcPressed()) );
    connect(_thread_button, SIGNAL(clicked()), this, SLOT (onStartThreadsPressed()) );

    // connect(_test_thread_1, SIGNAL(thEvent(int)), prb, SLOT (setValue(int) ));

    connect(_test_thread_1, SIGNAL(thEvent(int)), this, SLOT (onThreadEvent(int) ));
    connect(_test_thread_2, SIGNAL(thEvent(int)), this, SLOT (onThreadEvent(int) ));
    connect(_test_thread_3, SIGNAL(thEvent(int)), this, SLOT (onThreadEvent(int) ));
    connect(_test_thread_4, SIGNAL(thEvent(int)), this, SLOT (onThreadEvent(int) ));
}

void MainWidget::onStartCalcPressed()
{
    i_start = timeStamp.elapsed();
    count();
    count();
    count();
    count();
    i_stop = timeStamp.elapsed();
    int res = i_stop - i_start;
    qDebug() << "Serial calculation took " << res << "millseconds";
    lblSerialResult->setText(QString::number(res));
}

void MainWidget::onStartThreadsPressed()
{
    i_start = timeStamp.elapsed();
    _test_thread_1->start();
    _test_thread_2->start();
    _test_thread_3->start();
    _test_thread_4->start();
}

void MainWidget::count()
{
    long n = 10000000000;
    int i = 0;
    for (n; n>0; n--)
    {
      i = i*n;
    }

    /*do
    {
        n--;
        // qDebug() << "count n= " << n;
    } while (n > 0);
    */
    qDebug() << "count Done: n= " << n;
    // lnMSTime->setText(QString::number(Get1msTimeMS() ));
}

void MainWidget::onThreadEvent(int rec)
{
    // _counter->increment();
    // int i_stop = timeStamp.currentTime().elapsed();
    // qDebug() << "Elapsed " << timeStamp.elapsed();
    static int ctr = 0;
    const int threads_number = 4;
    ctr++;
    if (ctr >= threads_number)
    {
        i_stop = timeStamp.elapsed();
        int res = i_stop - i_start;
        qDebug() << "Thread Calculation took " << res << "millseconds";
        lblThreadsResult->setText(QString::number(res));
    }
}
