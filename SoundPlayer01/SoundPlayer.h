#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QWidget>
#include <QMessageBox>
#include <QtMultimedia/QSound>
#include <QPushButton>
#include <QHBoxLayout>

// class QSound;
 
class QSoundPlayer: public QWidget
{
     Q_OBJECT

 public:
     QSoundPlayer(QWidget *parent = 0);
 
 private:
    QSound* m_psnd;    
    void initDialog();
    void initButtons();
    void initLayouts();
    void setConnections();
    void setTimer();
    
    QPushButton* pbtnPlay;
    QPushButton* pbtnStop;
    QPushButton* pbtnLoop;
    QTimer *timer;
    
    
 public slots:
     void slotPlay();
     void slotStop();
     void slotLoopToggled(bool);
     
};

 #endif