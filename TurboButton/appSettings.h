#ifndef APP_SETTINGS_H
#define APP_SETTINGS_H
//============================================================
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

class TurboButton;

class AppSettings
{
public:
    AppSettings();
    AppSettings(QString strCompanyName, QString strAppName);
    ~AppSettings(){};


    void restoreAppSizePos(QWidget *app);
    void saveAppSizePos(QWidget *app);

    void restoreAppWidgetSizes(TurboButton *app);
    void saveWidgetsSizePos(TurboButton *app);
    
    int restoreIntValues(QString strPath);
    QString restoreStrValues(QString strPath);
    void saveValues(QString strPath, QVariant qValue);

private:    
    QSettings *settings;
    // void restoreAppSettings();

};

#endif

