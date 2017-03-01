#ifndef GenieUsabilityLogger_H
#define GenieUsabilityLogger_H

#include "gen.h"

#include <fstream>
#include <iostream>
#include <istream>

#ifdef YS_234523452345

class LogFile
{
public:
    LogFile(void);
    ~LogFile(void);

    bool OpenLogFile(QString name);
    void CloseLogFile();
    void Log(QString name, QString value, QString status);
    void LogPanicStarted(int seconds);
    void LogPanicAdjusted(int seconds);
    void LogTimeOut();

private:

    bool FileExists(QString filename);
    void OpenLog(QString filename);
    //QString mfilename;
    QTime * mLogTime;
    std::ofstream mOut;
};

#endif

#endif // GenieUsabilityLogger_H
