#ifndef APP_SETTINGS_H
#define APP_SETTINGS_H
//============================================================
//
//
//============================================================
//
// File:           AppSettings.h
//
//============================================================
// Description:
//==========================================================
#include <QtGui>
#include <QtCore>
#include "gen.h"
#include <time.h>

class AppSettings
{
public:
    AppSettings();
    AppSettings(QString strCompanyName, QString strAppName);
    ~AppSettings(){};
    
    
    void restoreAppSizePos(QWidget *app);
    void saveAppSizePos(QWidget *app);
    int restoreIntValues(QString strPath);
    QString restoreStrValues(QString strPath);
    void saveValues(QString strPath, QVariant qValue);

private:
    int nCounter;
    QSettings *settings;
    // void restoreAppSettings();
    
};

#endif

