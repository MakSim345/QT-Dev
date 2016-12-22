#ifndef TURBO_BUTTON_H
#define TURBO_BUTTON_H
//============================================================
//
//
//============================================================
//
// File:           TurboButton.h
//
// Author:         YS
//
//============================================================
// Description:
//==========================================================
#include <QtGui>

#include "gen.h"
#include "appSettings.h"


class TurboButton : public QDialog
{
    Q_OBJECT

public:
    TurboButton(QDialog *parent = 0);
    ~TurboButton(){};

    void initMainWindow();
    void initTimerBoxes();
    void initButtons();
    void initLayouts();
    void initRadioButtons();
    void tuneMainWindow();
    void setMainWindowTitle(QString strToShow);
    void setConnections();
    void startTimer();
    void stopTimer();
    void decrementCounter();
    void updateRemainTxt();
    void raiseAlarm();
    void restoreSettingsFromINI();
    void closeEvent (QCloseEvent *);
    void playSound();
    void updateMainWindowIcon(BUTTON_STYLE);

    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);

public slots:
    void onStart();
    void onPause();
    void onTimerEvent();
    void changeTimeUnit();
    void changeSoundOutput();
    void updateTimeUnits();

private:
    int nCounter;
    int m_ButtonFontSize;
    int m_LabelFontSize;
    int nSeconds;
    int radioButtonsTime;
    int radioButtonsSound;
    int mainTime;
    bool isPause;
    bool isRun;
    
    int prev_seconds;
    int _sec;
    int _min;
    QString min_str;
    QString sec_str;


    QTimer *m_timer_ctd;
    
    QPixmap picOn;
    QPixmap picOff;
    QIcon m_iconMainWindow;

    QString m_FontName;
    const int m_FontSize;
    
    QLabel *txtRemain;

    QPushButton *btnStart;
    QPushButton *btnQuit;

    QRadioButton *radioMin;
    QRadioButton *radioSec;         
    QRadioButton *radioSoundOn;
    QRadioButton *radioSoundOFF;

    QVBoxLayout *mainVlayout;
    QVBoxLayout *radioTimeVlayout;
    QVBoxLayout *radioSoundVlayout;
    QVBoxLayout *textVlayout;
    QVBoxLayout *TimeInsVlayout;
    QHBoxLayout *hLayoutBtns;
    QHBoxLayout *hLayoutTime;
    QHBoxLayout *hLayoutRemainTime;
    QHBoxLayout *hLayoutTimeShow;

    AppSettings *m_settings; 
};

#endif
