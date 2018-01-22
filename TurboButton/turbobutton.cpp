//============================================================
//
//
//============================================================
//
// File:           TurboButton.cpp
// Project:
//
// Author:         YS
//
//============================================================
// Description:
//==========================================================
#include "turbobutton.h"

TurboButton::TurboButton(QDialog *parent)
     :QDialog(parent)
     , m_CounterTimeDown(0)
     , radioButtonsTime(0) // 0 - minutes, 1 - seconds
     , radioButtonsSound(0) //
     , m_ButtonFontSize(15)
     , m_LabelFontSize (20)
     , m_FontName ("STENCIL") // ("Sans Serif")// ("MONACO")
     , m_FontSize(75)
     , m_Seconds(INT_SECONDS_IN_MINUTE)
     , m_mainTimeMinutes(INT_MINUTES_TOMATO) // 25 min
     , m_shortBreakTimeMinutes(INT_MINUTES_SHORT_BREAK) // 5 min
     , m_longBreakTimeMinutes(INT_MINUTES_LONG_BREAK) // 30 min
     , m_CounterTomato(0)
     , m_BreakCounter(0)
     , isPause(false)
{
    m_timer_ctd = new QTimer();

    initMainWindow();

    m_settings = new AppSettings(STR_COMPANY_NAME, STR_APP_NAME);
    setTomatoCounter(NO_INCREMENT);

    m_CounterTimeDown = convertMinutesToSeconds(m_mainTimeMinutes); // set to minutes
    
    updateRemainTxt();
    setConnections();

    restoreMainWindowSizePos();
 }

void TurboButton::restoreMainWindowSizePos()
{
    m_settings->restoreAppSizePos(this);
}

void TurboButton::initMainWindow()
{
    initTimerLabels();
    initButtons();
    initLayouts();
    tuneMainWindow();
}

void TurboButton::initTimerLabels()
{
    txtRemain = new QLabel(this);
    txtRemain->setAlignment(Qt::AlignCenter);
    txtRemain->setFont(QFont(m_FontName, m_FontSize));
    txtRemain->setGeometry(QRect(0, 260, 320, 120));
    txtRemain->move(100, 65);
    txtRemain->setStyleSheet("color: black;");
}

void TurboButton::initButtons()
{
    btnStart = new QPushButton(this);
    btnStart->setStyleSheet(
        "background: transparent; border-image: url(://Resources/Button_Restart.png);"
        );
    // setting 1:
    // btnStart->setGeometry(QRect(90, 160, 180, 180));
    // btnStart->move(175, 150);
    // setting 2:
    // btnStart->setGeometry(QRect(0, 0, 100, 100));
    //btnStart->move(-5, 70);
    // setting 3:
    btnStart->setGeometry(QRect(0, 0, 80, 80));
    btnStart->move(5, 90);

    btnQuit = new QPushButton(STR_BTN_QUIT);
    btnQuit->setMinimumSize(INT_BTN_W, INT_BTN_H);
    
    btnStart->setFont(QFont(m_FontName, m_ButtonFontSize));
    btnQuit->setFont(QFont(m_FontName, m_ButtonFontSize));
}

void TurboButton::initLayouts()
{
    txtRemain->show();
    btnStart->show();
}

void TurboButton::initRadioButtons()
{
    radioMin =  new QRadioButton(STR_MINUTES);
    radioSec =  new QRadioButton(STR_SECONDS);

    radioSoundOn =  new QRadioButton(STR_SOUND_ON);
    radioSoundOFF =  new QRadioButton(STR_SOUND_OFF);
}

void TurboButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QRegion r1;

    r1 = QRegion(picOff.rect());
    painter.setClipRegion(r1);
    painter.drawPixmap(picOff.rect(), picOff);
    /*
    switch (m_CurrentState)
    {
    case NO_ACTION:
        r1 = QRegion(picOff.rect());
        painter.setClipRegion(r1);
        painter.drawPixmap(picOff.rect(), picOff);
        break;
    case RUNNING_BREAK_SHORT:
        r1 = QRegion(picOff.rect());
        painter.drawPixmap(picOff.rect(), picOff);
        break;
    case RUNNING_TOMATO:
        r1 = QRegion(picOn.rect());
        painter.setClipRegion(r1);
        painter.drawPixmap(picOn.rect(), picOn);
        break;
    }
   */
}

void TurboButton::resizeEvent(QResizeEvent *e)
{
    /*
    if (isRun == true)
    {
        setMask(picOff.mask());
    }
    else if (isRun == false)
    {
        setMask(picOn.mask());
    }
  */
}

QString TurboButton::currentDate()
{
    QDateTime now = QDateTime::currentDateTime();
    return now.date().toString(STR_DATE_FORMAT);
}

void TurboButton::setTomatoCounter(int incrementP)
{
    if (incrementP)
    {
        m_CounterTomato++;
    }
    else
    {
        QString dateNow = currentDate();
        int n = dateNow.compare(m_settings->restoreStrValues(STR_INI_PATH_DATE));

        if (n == 0)
        {
            m_CounterTomato = m_settings->restoreIntValues(STR_INI_PATH_TOMATO_COUNTER);
            setBreakCounter(m_settings->restoreIntValues(STR_INI_PATH_BREAK_COUNTER));
        }
        else
        {
            m_CounterTomato = 0;
            setBreakCounter(0);
        }
    }
    iniSaveCurrentState();

    // update main window caption:
    setMainWindowTitle(QString().setNum(m_CounterTomato));
}

void TurboButton::tuneMainWindow()
{
    //set icon:
    this->updateMainWindowIcon();

    //set caption:
    setMainWindowTitle(QString().setNum(m_CounterTomato));
    picOn.load("://Resources/TurboButton01.jpg");
    // picOn.load(":/MainViewOFF");
    picOff.load("://Resources/TurboButton01.jpg");
    // pic.load("Resources/TurboButton01.png");
    // setStyleSheet("background-image: url(:/Resources/TurboButton01.png)");

    setWindowFlags(Qt::WindowTitleHint);
    this->setMaximumHeight(3.5 * m_FontSize);
}

void TurboButton::setMainWindowTitle(QString strToShowP)
{
    QString strTitle = STR_MAIN_TITLE;
    // strCombine.append(CURRENT_VERSION);
    strTitle.append(": ");
    strTitle.append(strToShowP);
    strTitle.append(" - ");
    strTitle.append(st.getStrStatus());
    setWindowTitle(strTitle);
}

void TurboButton::setConnections()
{
    connect (btnStart, SIGNAL(clicked()), this, SLOT(onStart()));
    connect(btnQuit,  SIGNAL(clicked()), this, SLOT(close()));
    connect(m_timer_ctd, SIGNAL(timeout()), this, SLOT(onTimerEvent()));
}

void TurboButton::onStart()
{
    /************************************************************************/
    /* Function reacts to a START button press                              */
    /************************************************************************/
    btnStart->setStyleSheet(
        "background: transparent; border-image: url(://Resources/Button_Shutdown.png);"
        );
    startTimer();
    updateRemainTxt();
    btnStart->setEnabled(false);
    st.setStatus(RUNNING_TOMATO);
    setTomatoCounter(NO_INCREMENT);
    this->updateMainWindowIcon();
    this->update();
    prev_seconds = QTime::currentTime().second();
}

void TurboButton::onPause()
{
    if (isPause)
    {
        isPause = false;
        startTimer();
    }
    else
    {
        isPause = true;
        stopTimer();
    }
}

void TurboButton::startTimer()
{
    m_timer_ctd->start(INT_MILLISEC_CHECK);
}
void TurboButton::stopTimer()
{
    m_timer_ctd->stop();
}

void TurboButton::onTimerEvent()
{
    int tmp_seconds = QTime::currentTime().second();

    if (tmp_seconds != prev_seconds)
    {
        prev_seconds = QTime::currentTime().second();
        decrementCounter();
        stateUpdate();
    }
}

int TurboButton::convertMinutesToSeconds(int nMinutesToConvertP)
{
#ifdef DEBUG_ON
    return 3; // DEBUG
#else
    return nMinutesToConvertP * m_Seconds; // set main time to minutes
#endif
}

void TurboButton::decrementCounter()
{
    m_CounterTimeDown = m_CounterTimeDown - 1;
}

void TurboButton::updateBreakStatus()
{
    setBreakCounter(m_BreakCounter + 1);
    m_settings->saveValues(STR_INI_PATH_BREAK_COUNTER,  m_BreakCounter);
}

bool TurboButton::isLongBreak()
{
    if (m_BreakCounter >= INT_BREAKS_BEFORE_LONG)
    {
        setBreakCounter(0);
        return true;
    }
    return false;
}

void TurboButton::stateUpdate()
{
    if (INT_TIME_GONE > m_CounterTimeDown)
    {
        updateRemainTxt(); // show real time counter

        switch (st.state)
        {
        case NO_ACTION:
            break;
        case RUNNING_BREAK_LONG:
            m_CounterTimeDown = convertMinutesToSeconds(m_mainTimeMinutes); // set to minutes
            st.setStatus(NO_ACTION);
            btnStart->setStyleSheet(
                "background: transparent; border-image: url(://Resources/Button_Restart.png);"
                );
            btnStart->setEnabled(true);
            stopTimer();
            raiseAlarm(STR_TIMER_LONG_BREAK_OVER);
            setTomatoCounter(NO_INCREMENT);
            setMainWindowTitle(QString().setNum(m_CounterTomato));
            break;
        case RUNNING_BREAK_SHORT:
            m_CounterTimeDown = convertMinutesToSeconds(m_mainTimeMinutes); // set to minutes
            st.setStatus(NO_ACTION);
            btnStart->setStyleSheet(
                "background: transparent; border-image: url(://Resources/Button_Restart.png);"
                );
            btnStart->setEnabled(true);
            stopTimer();
            raiseAlarm(STR_TIMER_SHORT_BREAK_OVER);
            setTomatoCounter(NO_INCREMENT);
            setMainWindowTitle(QString().setNum(m_CounterTomato));
            break;
        case RUNNING_TOMATO:
            updateBreakStatus(); // increment break numbers
            selectBreak();
            btnStart->setStyleSheet(
                "background: transparent; border-image: url(://Resources/Button_Break.png);"
                );
            raiseAlarm(STR_TIMER_GOT_LIMIT);
            setTomatoCounter(DO_INCREMENT); // increment today counter.
            break;
        }
    }
    this->updateMainWindowIcon();
    this->update();
    updateRemainTxt();
}

void TurboButton::selectBreak()
{
    if (isLongBreak())
    {
        m_CounterTimeDown = convertMinutesToSeconds(m_longBreakTimeMinutes);
        st.setStatus(RUNNING_BREAK_LONG);
    }
    else
    {
        m_CounterTimeDown = convertMinutesToSeconds(m_shortBreakTimeMinutes);
        st.setStatus(RUNNING_BREAK_SHORT);
    }
}

void TurboButton::updateMainWindowIcon()
{
    switch (st.state)
    {
        case NO_ACTION:
            setWindowIcon(QIcon("://Resources/Button_Restart.png"));
            break;
        case RUNNING_BREAK_SHORT:
        case RUNNING_BREAK_LONG:
            setWindowIcon(QIcon("://Resources/Button_Break.png"));
            break;
        case RUNNING_TOMATO:
            setWindowIcon(QIcon("://Resources/Button_Shutdown.png"));
            break;
    }
}

void TurboButton::updateRemainTxt()
{
    m_SecInt = m_CounterTimeDown % 60;
    m_MinInt = m_CounterTimeDown / 60;

    if (0 >= m_MinInt)
    {
        m_MinStr = STR_TIME_ZERO;
    }
    else
    {
        m_MinStr = convertIntToStrXX(m_MinInt);
    }

    if (0 >= m_SecInt)
    {
        m_SecStr = STR_TIME_ZERO;
    }
    else
    {
        m_SecStr = convertIntToStrXX(m_SecInt);
    }

    txtRemain->setText(m_MinStr + ":" + m_SecStr);
}

QString TurboButton::convertIntToStrXX(int nToConvertP)
{
    if (nToConvertP < 10)
    {
        return "0" + QString().setNum(nToConvertP);
    }
    else
    {
        return QString().setNum(nToConvertP);
    }
}

void TurboButton::setBreakCounter(const int &nNewValueP)
{
    m_BreakCounter = nNewValueP;
}


void TurboButton::raiseAlarm(QString strMessageP)
{
    showNormal();
    activateWindow();
    playSound();
    /*
    msgBox = new QMessageBox(QMessageBox::Information, tr("Timer Info"), strMessageP);    msgBox->setStyleSheet("QLabel{height: 150px; min-height: 100px; max-height: 150px; font: 15pt;} QPushButton {font: 15pt}");    msgBox->exec();    delete msgBox;
    */
    QMessageBox::information(this, "Timer Info", strMessageP);
}

void TurboButton::changeSoundOutput()
{
    qDebug("changeSoundOutput called.");
    bool _rSoundON = radioSoundOn->isChecked();
    bool _rSoundOFF = radioSoundOFF->isChecked();

    if (_rSoundOFF)
    {
       radioButtonsSound = 0;
    }
    else
    {
       radioButtonsSound = 1;
    }
    // updateTimeUnits();
}

void TurboButton::changeTimeUnit()
{
    qDebug("changeTimeUnit called.");
    //qDebug("radioButtonsTime set to %d\n", radioButtonsTime);
    // updateTimeUnits();
}

void TurboButton::updateTimeUnits()
{
    if (radioButtonsTime)
    {
        m_Seconds = 1;
        //timerValue->setSuffix(STR_SEC);
    }
    else
    {
        m_Seconds = 60;
        //timerValue->setSuffix(STR_MIN);
    }
}

void TurboButton::iniSaveMainWindowSizePos()
{
    m_settings->saveAppSizePos(this);
}

void TurboButton::iniSaveCurrentState()
{
    m_settings->saveValues(STR_INI_PATH_DATE, currentDate());
    m_settings->saveValues(STR_INI_PATH_TOMATO_COUNTER, m_CounterTomato);
    m_settings->saveValues(STR_INI_PATH_BREAK_COUNTER,  m_BreakCounter);

    //m_settings->saveValues("MainWindow/Values/LastTimerValue", timerValue->value());
    //m_settings->saveValues("MainWindow/Values/TimeUnit", radioButtonsTime);
    //m_settings->saveValues("MainWindow/Values/Sound_ON_OFF", radioButtonsSound);

    //qDebug("radioButtonsTime= %d\n", radioButtonsTime);
}

void TurboButton::closeEvent(QCloseEvent* e)
{
    m_timer_ctd->stop();
    iniSaveCurrentState();
    iniSaveMainWindowSizePos();
}

void TurboButton::playSound()
{
    Beep(500, 100);
    Beep(300, 500);
}

