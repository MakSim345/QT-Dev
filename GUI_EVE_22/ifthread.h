#ifndef _IFTHREAD_H_
#define _IF_THREAD_H_

#include <QtGui>

class NotifyThread : public QThread
{
    Q_OBJECT
    
public:
    NotifyThread();
    NotifyThread(int);
    void setMessage(const QString &message);
    void setMValue(int);
    int  getMValue(void);
    // void stop();

public slots:
	void slotNextValue();

protected:
    void run();
    
private:
	int m_nValue;
    QString messageStr;    
    volatile bool stopped;
    
signals:
	void finished();
    void timerClick();
};

#endif // THREAD_H
