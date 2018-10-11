#ifndef _MAIN_VIEW_H_
#define _MAIN_VIEW_H_

#include "gen.h"
#include "minesweeper.h"

class mainView : public QWidget
{
    Q_OBJECT

public:
    mainView(QWidget *parent = 0);
    ~mainView() {};

    QLineEdit* lnCells;
    // QLineEdit* lnMSTime;
    QLineEdit* lnIteration;
        
    QPushButton* btnRedo;    
    QPushButton *bQuit;
    
    QLCDNumber *lcdTimeDisplay;
    QLCDNumber *lcdMineCounter;
    // MyThread m_thread;

private:
    Minesweeper *mineswpWgt;
    void setConnections();
    void initWidgets();
    void setWidgetLayout();
    QString getThreeDigit(int pnumToConvert);
    QTimer* timer;
    int m_seconds;
    bool gameOver;
    bool gameWon;
    bool gameStarted;
     
public slots:
    void clickBtnRedo();
    void onExit ();
    void StartMyThread();
    void updateTimerDisplay();
    void updateMinesDisplay(int);
    void startGame();
    void stopGame(bool pWinLose);
};

#endif
