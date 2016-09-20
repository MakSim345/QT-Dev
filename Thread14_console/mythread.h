#ifndef _MY_THREAD_H_
#define _MY_THREAD_H_

#include <QtCore>
#include <iostream> 
#include <fstream> 
#include <string> 

using namespace std; 

class MyThread : public QThread
{
    Q_OBJECT
    
public:
    MyThread();
    //void setMessage(const QString &message);
    //void setMValue(int);
    //int  getMValue(void);
    // void stop();
    void run();    
    QString my_name;    
    
public slots:
	//void slotNextValue();

protected:
    
private:
	int m_nValue;
    QString messageStr;    

    volatile bool stopped;
    
signals:
	void finished();
    void currentValue(int);    
};


class DisplayTask: public QThread
{
    ifstream in;
    string line;
    bool quitFlag;
    int id;
public:
    DisplayTask(const string& file, int ident = 0):
    quitFlag(false),
    id (ident)
    {
        in.open(file.c_str());
        std::cout << id << "DisplayTask - init (Contructor)\n";
    }

    ~DisplayTask()
    {
        in.close();
        std::cout << id << "DisplayTask - completed (Destructor)\n";
    }
    void run()
    {
        while (getline(in, line) && !quitFlag)
        { 
            // std::cout << "thread num:" << id << " - " << countDown << "\n";
            std::cout << line << endl;
            _sleep(500);
        }
    }

    void quit() {quitFlag = true;}
};

#endif // THREAD_H
