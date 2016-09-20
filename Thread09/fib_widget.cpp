#include "fib_widget.h"

fib_widget::fib_widget(QWidget *parent)
     : QWidget(parent)
{
    setWindowTitle(tr("Test thread project"));
    setFixedSize(450, 220);

    bQuit = new QPushButton(tr("&Quit"));
    bRnd = new QPushButton ("&RND");
    bCountDown = new QPushButton ("&Start Fibo Calc");

    bQuit->setFont(QFont("Courier", 18, QFont::Bold));
    bRnd->setFont(QFont("Courier", 18, QFont::Bold));
    bCountDown->setFont(QFont("Courier", 18, QFont::Bold));

    lcdInitNumber = new QLCDNumber();
    lcdInitNumber->setSegmentStyle(QLCDNumber::Filled);
    lcdInitNumber->setAutoFillBackground(1);
    lcdInitNumber->display(0);

    lcdResult = new QLCDNumber();
    lcdResult->setSegmentStyle(QLCDNumber::Filled);
    lcdResult->setAutoFillBackground(1);
    lcdResult->display(0);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 999);
    slider->setValue(0);

    line4 =    new QLineEdit (this);
    lsdFibNumber = new QLCDNumber();
    lsdFibNumber->setSegmentStyle(QLCDNumber::Filled);
    lsdFibNumber->setAutoFillBackground(1);
    lsdFibNumber->display(0);

    lblInit = new QLabel("Init number:");

    QVBoxLayout *mainVlayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    QHBoxLayout *topHLayout = new QHBoxLayout;
    connect(bQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    
    connect(bCountDown, SIGNAL(clicked()), this, SLOT (StartMyThread()));
    connect(bRnd, SIGNAL(clicked ()), this, SLOT (calcFib ()));
    connect(slider, SIGNAL(valueChanged(int)), lcdInitNumber, SLOT(display(int)));
    
    connect (&m_thread, SIGNAL(currentIteration(double)), this, SLOT(DisplayIteration(double)));
    connect (&m_thread, SIGNAL(currentValue(int)), lsdFibNumber, SLOT(display(int)) );
    // connect (&m_thread, SIGNAL(finished()), qApp, SLOT(quit()));
    connect (&m_thread, SIGNAL(finished()), this, SLOT(EndOfCalculation()));

    topHLayout->addWidget(lblInit);
    topHLayout->addWidget(lcdInitNumber);
    mainVlayout->addLayout(topHLayout);
    mainVlayout->addWidget(slider);
    mainVlayout->addWidget(lcdResult);
    mainVlayout->addWidget(line4);
    mainVlayout->addWidget(lsdFibNumber);

    hLayout->addWidget(bRnd);
    hLayout->addWidget(bCountDown);
    hLayout->addWidget(bQuit);
    mainVlayout->addLayout(hLayout);
    
    setLayout(mainVlayout);
 }

void fib_widget::StartMyThread()
{
	line4->setText("Running....");
    bCountDown->setEnabled(false);
	m_thread.setMValue( lcdInitNumber->intValue() );
	m_thread.start();
}
void fib_widget::EndOfCalculation()
{
    bCountDown->setEnabled(true);
    line4->setText("Done!");
}

void fib_widget::DisplayIteration(double nIteration)
{
    //lsdFibNumber->display(Fibonacci)
	// line3->setText(QString::number(nIteration));
    lcdResult->display(QString::number(nIteration));
}

void fib_widget::hello(QString name)
 {
     qDebug() << "Hello" << name << "from" << QThread::currentThread();
 }


void fib_widget::calcFib()
{
#ifndef QT_NO_CONCURRENT	
	//using namespace QtConcurrent;
	int res = lcdInitNumber->value();
	
	// QFuture<int> *m_future = run(&fib, res);
    //QFuture<void> f1 = run(hello, QString("Alice"));

	lsdFibNumber->display(res);
#else

    qDebug() << "Qt Concurrent is not yet supported on this platform";
#endif
    QApplication::beep();
}

void fib_widget::onExit()
{
    close();
}
