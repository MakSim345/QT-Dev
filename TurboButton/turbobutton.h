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
    void initTimerLabels();
    void initButtons();
    void initLayouts();
    void initRadioButtons();
    void tuneMainWindow();
    void setMainWindowTitle(QString strToShow);
    void setConnections();
    void startTimer();
    void stopTimer();
    void decrementCounter();
    void stateUpdate();
    void breakStatusUpdate();    
    bool isLongBreak();
    void selectBreak();
    void updateRemainTxt();
    void raiseAlarm(QString strMessageP);

    void iniSaveCurrentState();   

    void closeEvent (QCloseEvent* clEv);
    void playSound();
    void updateMainWindowIcon();

    void paintEvent(QPaintEvent* e);
    void resizeEvent(QResizeEvent* e);

    int getTomatoCounter() {return m_CounterTomato;}
    QString currentDate();
    void setTomatoCounter(int incrementP);

    int convertMinutesToSeconds(int nMinutesToConvertP);
    void restoreMainWindowSizePos();
    void iniSaveMainWindowSizePos();

public slots:
    void onStart();
    void onPause();
    void onTimerEvent();
    void changeTimeUnit();
    void changeSoundOutput();
    void updateTimeUnits();

private:
    int m_CounterTimeDown;
    int m_CounterTomato;
    int m_CounterBreaks;

    int m_ButtonFontSize;
    int m_LabelFontSize;
    int m_Seconds;
    int radioButtonsTime;
    int radioButtonsSound;
    int m_breakTime;
    int m_mainTimeMinutes;
    int m_shortBreakTimeMinutes;
    int m_longBreakTimeMinutes;
    bool isPause;
    CURRENT_STATE m_CurrentState;


    int prev_seconds;
    int m_SecInt;
    int m_MinInt;
    QString m_MinStr;
    QString m_SecStr;

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

    QMessageBox *msgBox;
};

#endif
