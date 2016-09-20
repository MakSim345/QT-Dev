 #include <QtGui>
 #include "SoundPlayer.h"

QSoundPlayer::QSoundPlayer(QWidget *parent) 
: QWidget(parent)
{
    
    /*
    if (!QSound::isAvailable())
    {
        QMessageBox::warning(this, "No Sound", "Sorry, I can not play the sound!");
    }
    else 
    {
     //QMessageBox::information(this, "Sound OK", "Cool, I can play the sound!");
    }
    */
    // m_psnd = new QSound ("ringin.wav", this);
    m_psnd = new QSound ("ringin.wav");
    initDialog();
}

void QSoundPlayer::setTimer()
{
    //timer = new QTimer(this);
    //timer->start(1000);
}


void QSoundPlayer::initDialog()
{
    initButtons();
    setConnections();
    initLayouts();
    setWindowTitle(tr("Sound Player v 0.0.1"));
    //resize(150, 60);
}

void QSoundPlayer::initButtons()
{
    pbtnPlay = new QPushButton("&Play");
    pbtnStop = new QPushButton("&Stop");
    pbtnLoop = new QPushButton("&Loop");
    
    pbtnLoop->setCheckable(true);
    pbtnLoop->setChecked(true);
}

void QSoundPlayer::initLayouts()
{
    QHBoxLayout * phbxLayout = new QHBoxLayout();
    phbxLayout->addWidget(pbtnPlay);
    phbxLayout->addWidget(pbtnStop);
    phbxLayout->addWidget(pbtnLoop);
    setLayout(phbxLayout);
}

void QSoundPlayer::setConnections()
{
    // connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    connect(pbtnPlay, SIGNAL(clicked()), this, SLOT(slotPlay()));
    connect(pbtnStop, SIGNAL(clicked()), this, SLOT(slotStop()));
    connect(pbtnLoop, SIGNAL(toggled(bool)), this, SLOT(slotLoopToggled(bool)));
}

void QSoundPlayer::slotPlay()
{
    m_psnd->play();
}

void QSoundPlayer::slotStop()
{
    m_psnd->stop();
}

void QSoundPlayer::slotLoopToggled(bool b)
{
    m_psnd->setLoops(b? -1 : 1);
    m_psnd->stop();
}