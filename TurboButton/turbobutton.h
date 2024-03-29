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

class StatusTomato
{
public:
    StatusTomato()
    {
        setStatus(NO_ACTION);
    }

    ~StatusTomato(){};
    
    CURRENT_STATE state;
    
    QString getStrStatus() {return this->str_status;}
    
    void setStatus(CURRENT_STATE newStatusP)
    {
        state = newStatusP;
        switch (newStatusP)
        {
        case NO_ACTION:
            str_status = STR_STATUS_IDLE;
            break;
        case RUNNING_BREAK_SHORT:
            str_status = STR_STATUS_SHORT_BREAK;
            break;
        case RUNNING_BREAK_LONG:
            str_status = STR_STATUS_LONG_BREAK;
            break;
        case RUNNING_TOMATO:
            str_status = STR_STATUS_RUN;
            break;
        }
    }

private:
    QString str_status;
};


class TurboButton : public QDialog
{
    Q_OBJECT

public:
    TurboButton(QDialog *parent = 0);
    ~TurboButton(){};

    void initMainWindow();
    void initTimerLabel();
    void initButtons();
    void initLayouts();
    void initRadioButtons();
    void moveButtons(QPoint move_pointP);
    void moveTimerLabel(QPoint move_pointP);
    void tuneMainWindow();
    void setMainWindowTitle(QString strToShow);
    void setConnections();
    void startTimer();
    void stopTimer();
    void decrementCounter();
    void stateUpdate();
    void updateBreakStatus();    
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

    QPoint getGreenButtonPoints() {return green_btn_point;}
    QPoint getTimerLabelPoints()  {return timer_lbl_point;}
    
    void setTomatoCounter(int incrementP);

    int convertMinutesToSeconds(int nMinutesToConvertP);
    void restoreMainWindowSizePos();
    void restoreMainWindowWidgetSizes();

    void iniSaveMainWindowSizePos();

public slots:
    void onStart();
    void onPause();
    void onTimerEvent();
    void changeTimeUnit();
    void changeSoundOutput();
    void updateTimeUnits();

private:
    QString convertIntToStrXX(int nToConvertP);
    void setBreakCounter(const int &nNewValueP);
    
    int m_CounterTimeDown;
    int m_CounterTomato;
    int m_BreakCounter;

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
    // CURRENT_STATE state;
    StatusTomato st;
    
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

    QLabel *lblTimeCounter;
    QRect *rectRemain; 

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

    QPoint green_btn_point;
    QPoint timer_lbl_point;

    QMessageBox *msgBox;
};

#endif
