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
     : QDialog(parent, Qt::FramelessWindowHint)
     //: QDialog(parent)
     , nCounter(0)
     , radioButtonsTime(0) // 0 - minutes, 1 - seconds
     , radioButtonsSound(0) //
     , m_ButtonFontSize(15)
     , m_LabelFontSize (20)
     , nSeconds(60)
     , mainTime(25) // 25
     , m_FontName("MONACO")
     , isPause(false)
     , isRun(false)

 {
    m_timer_ctd = new QTimer();

    initMainWindow();
    m_settings = new AppSettings(STR_COMPANY_NAME, STR_APP_NAME);
    restoreSettingsFromINI();
    
    nCounter = mainTime * nSeconds; // set to minutes
    
    // nCounter = timerValue->value() * nSeconds; //  set to minutes
    updateRemainTxt();
    setConnections();    
 }

void TurboButton::initMainWindow()
{
    initTimerBoxes();
    initButtons();
    initLayouts();
    tuneMainWindow();
}

void TurboButton::initTimerBoxes()
{   
    txtRemain = new QLabel(this);
    txtRemain->setAlignment(Qt::AlignCenter);
    txtRemain->setFont(QFont(m_FontName, 80));
    txtRemain->setGeometry(QRect(90, 260, 300, 120));
    txtRemain->move(140, 75);
}

void TurboButton::initButtons()
{
    btnStart = new QPushButton(this);
    btnStart->setStyleSheet(
        "background: transparent;"
        );
     btnStart->setGeometry(QRect(90, 260, 180, 180));
    // btnStart->setGeometry(QRect(90, 260, 18, 18));
    btnStart->move(210, 310);
  
    btnQuit = new QPushButton(STR_BTN_QUIT);
    btnQuit->setMinimumSize(INT_BTN_W, INT_BTN_H);

    // QIcon m_iconPlane(":/Resources/plane.png");
    // QIcon m_iconPlane(STR_PLANE_ICON);
    // btnQuit->setIcon(m_iconPlane);
    // btnQuit->setIconSize(QSize(30, 30));

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
    if (isRun == true)
    {
        QRegion r1(picOn.rect());
        QPainter painter(this);
            
        painter.setClipRegion(r1);
        painter.drawPixmap(picOn.rect(), picOn); 
    }
    else if (isRun == false)
    {
        QRegion r1(picOff.rect());        
        QPainter painter(this);
            
        painter.setClipRegion(r1);
        painter.drawPixmap(picOff.rect(), picOff); 
    }    
}

void TurboButton::resizeEvent(QResizeEvent *e)
{
    if (isRun == true)
    {
        setMask(picOff.mask());
    }
    else if (isRun == false)
    {
        setMask(picOn.mask());
    }
}

void TurboButton::tuneMainWindow()
{
    //set icon:
    // QIcon m_Icon = QIcon(":/plane.png");
    // see - alias:
    QIcon m_iconPlane(STR_PLANE_ICON);
    setWindowIcon(m_iconPlane);
    //set caption:
    setMainWindowTitle("");    
    picOn.load("://Resources/TurboButton01.jpg");
    // picOn.load(":/MainViewOFF");
    picOff.load("://Resources/TurboButton02.jpg");    
    // pic.load("Resources/TurboButton01.png");
    // setStyleSheet("background-image: url(:/Resources/TurboButton01.png)");
}

void TurboButton::setMainWindowTitle(QString strToShow)
{
    setWindowTitle(strToShow + STR_MAIN_TITLE);
}

void TurboButton::setConnections()
{
    connect (btnStart, SIGNAL(clicked()), this, SLOT(onStart()));
    connect(btnQuit,  SIGNAL(clicked()), this, SLOT(close()));
    connect(m_timer_ctd, SIGNAL(timeout()), this, SLOT(onTimerEvent()));
}

void TurboButton::onStart()
{    
    startTimer();
    updateRemainTxt();
    btnStart->setEnabled(false);
    isRun = true;
    this->update();
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
    m_timer_ctd->start(1000);
}
void TurboButton::stopTimer()
{
    m_timer_ctd->stop();
}

void TurboButton::onTimerEvent()
{
    decrementCounter();
}

void TurboButton::decrementCounter()
{
    nCounter = nCounter - 1;
    if (0 > nCounter)
    {
        // updateRemainTxt(); 
        nCounter = mainTime * nSeconds; // set to minutes
        stopTimer();
        btnStart->setEnabled(true);
        raiseAlarm();
        isRun = false;
        this->update();
    }
    updateRemainTxt();
}

void TurboButton::updateRemainTxt()
{
    int nTmpVal = nCounter;
    QString strTmpVal = QString();

    _sec = nTmpVal % 60;
    _min = nTmpVal / 60;
    
        if (0 == _min)
        {
            min_str = "00";
        }
        else
        {
            if (_min < 10)
                min_str = "0" + QString().setNum(_min);
            else
                min_str = QString().setNum(_min);
        }
        
        if (0 == _sec)
        {
            sec_str = "00";
        }
        else
        {
            if (_sec < 10)
                sec_str = "0" + QString().setNum(_sec);
            else               
                sec_str = QString().setNum(_sec);
        }
        
        strTmpVal = min_str + ":" + sec_str;
    
    txtRemain->setText(strTmpVal);
}

void TurboButton::raiseAlarm()
{
    showNormal();
    activateWindow();    
    playSound();
    QMessageBox::information(this, "Timer Info", "Timer has got it's limit!");
/*    QtGui.QMessageBox.critical(None, "OpenGL hellogl",
                            "PyOpenGL must be installed to run this example.",
                            QtGui.QMessageBox.Ok | QtGui.QMessageBox.Default,
                            QtGui.QMessageBox.NoButton)
*/
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
        nSeconds = 1;
        //timerValue->setSuffix(STR_SEC);
    }
    else
    {
        nSeconds = 60;
        //timerValue->setSuffix(STR_MIN);
    }
}

void TurboButton::restoreSettingsFromINI()
{
    int nTmp = 0;

    nTmp = m_settings->restoreIntValues("MainWindow/Values/LastTimerValue");
    m_settings->restoreAppSizePos(this);
    
    // timerValue->setValue (nTmp);

    nTmp = m_settings->restoreIntValues("MainWindow/Values/TimeUnit");
    radioButtonsTime = nTmp;
    
    qDebug ("radioButtonsTime = %d", radioButtonsTime);
    qDebug ("call changeTimeUnit() from restoreSettingsFromINI");    

    //changeTimeUnit();
    
    nTmp = m_settings->restoreIntValues("MainWindow/Values/Sound_ON_OFF");
    radioButtonsSound = nTmp;    
    
}

void TurboButton::closeEvent(QCloseEvent* e)
{
    m_timer_ctd->stop();
    m_settings->saveAppSizePos(this);
    //m_settings->saveValues("MainWindow/Values/LastTimerValue", timerValue->value());

    m_settings->saveValues("MainWindow/Values/TimeUnit", radioButtonsTime);
    m_settings->saveValues("MainWindow/Values/Sound_ON_OFF", radioButtonsSound);
    //qDebug("radioButtonsTime= %d\n", radioButtonsTime);
}

void TurboButton::playSound()
{
    Beep(500, 100);
    Beep(300, 500);    
    //time.sleep(0.2)    
}

