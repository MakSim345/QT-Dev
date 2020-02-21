#pragma once
#include "gen.h"
#include "TetrixBoard.h"

class MainView : public QWidget
{
    Q_OBJECT

public:
    MainView(QWidget *parent = nullptr);
    ~MainView();

private:
    TetrixBoard *board;
    QLabel * nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;

    void setConnections();
    QLabel* createLabel(const QString &text);
};