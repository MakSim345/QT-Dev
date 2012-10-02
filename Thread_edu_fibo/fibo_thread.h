#ifndef _FIBO_THREAD_H_
#define _FIBO_THREAD_H_

#include <QtCore>

class FiboThread : public QThread
{
    Q_OBJECT
    
public:
    FiboThread();
    void setMessage(const QString &message);
    void setMValue(int);
    int  getMValue(void);
    // void stop();
	int fib(int f);

public slots:
	void slotNextValue();

protected:
    void run();
    
private:
	int m_nValue;
    int m_RetValue;
    double m_Iteration;
    QString messageStr;    
    volatile bool stopped;
    QTimer *fibo_timer;
    
signals:
	void finished();
    void currentValue(int);
    void currentIteration(double);
};

#endif // THREAD_H
