#include "fib_widget.h"

fib_widget::fib_widget(QWidget *parent)
     : QWidget(parent)
{
    setWindowTitle(tr("Test thread project"));
    setFixedSize(550, 420);

    bQuit = new QPushButton(tr("&Quit"));
    bRnd = new QPushButton ("&RND");
    bCountDown = new QPushButton ("&Start Fibo Calc");

    bQuit->setFont(QFont("Courier", 18, QFont::Bold));
    bRnd->setFont(QFont("Courier", 18, QFont::Bold));
    bCountDown->setFont(QFont("Courier", 18, QFont::Bold));

    lcd = new QLCDNumber();
    lcd->setSegmentStyle(QLCDNumber::Filled);
    lcd->setAutoFillBackground(1);
    lcd->display(0);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 999);
    slider->setValue(0);

    line3 =    new QLineEdit (this);
    line4 =    new QLineEdit (this);
    lnResut =  new QLineEdit (this);

    lsdFibNumber = new QLCDNumber();
    lsdFibNumber->setSegmentStyle(QLCDNumber::Filled);
    lsdFibNumber->setAutoFillBackground(1);
    lsdFibNumber->display(0);

    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    connect(bQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    
    connect(bCountDown, SIGNAL(clicked()), this, SLOT (StartMyThread()));
    connect(bRnd, SIGNAL(clicked ()), this, SLOT (calcFib ()));
    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
    
    connect (&m_thread, SIGNAL(currentIteration(double)), this, SLOT(DisplayIteration(double)));
    connect (&m_thread, SIGNAL(currentValue(double)), lsdFibNumber, SLOT(display(double)) );
    connect (&m_thread, SIGNAL(currentValue(double)), this, SLOT(DisplayResult(double)) );
    // connect (&m_thread, SIGNAL(finished()), qApp, SLOT(quit()));
    connect (&m_thread, SIGNAL(finished()), this, SLOT(EndOfCalculation()));

    layout->addWidget(lcd);
    layout->addWidget(slider);
    layout->addWidget(line3);
    layout->addWidget(line4);
    layout->addWidget(lnResut);
    layout->addWidget(lsdFibNumber);

    hLayout->addWidget(bRnd);
    hLayout->addWidget(bCountDown);
    hLayout->addWidget(bQuit);
    layout->addLayout(hLayout);
    
    setLayout(layout);
 }

void fib_widget::StartMyThread()
{
	line4->setText("Running....");
    lnResut->setText("Running...");
    bCountDown->setEnabled(false);
	m_thread.setMValue( lcd->intValue() );
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
	line3->setText(QString::number(nIteration));
}

void fib_widget::DisplayResult(double result)
{
    lnResut->setText(QString::number(result));
}

void fib_widget::hello(QString name)
 {
     qDebug() << "Hello" << name << "from" << QThread::currentThread();
 }


void fib_widget::calcFib()
{
#ifndef QT_NO_CONCURRENT	
	using namespace QtConcurrent;
	int res = lcd->value();
	
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
