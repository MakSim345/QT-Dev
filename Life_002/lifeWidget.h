#ifndef _LIFE_WIDGET_H_
#define _LIFE_WIDGET_H_

#include <QPainter>
#include <QColor>
#include <QWidget>
#include "colony.h"

class lifeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit lifeWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    colony *my_colony;
    
signals:
    
public slots:
    void startGame(const int &number = -1);
    void stopGame();
    void clear();

    int cellNumber();
    void setCellNumber(const int &s);

    int interval();
    void setInterval(int msec);

    QColor masterColor();
    void setMasterColor(const QColor &color);

    QString dump();
    void setDump(const QString &data);

    int getCellsAlive();
    int getLifeIteration();

private slots:
    void paintGrid(QPainter &p);
    void paintUniverse(QPainter &p);
    void newGeneration();

private:
    QColor m_masterColor;
    QTimer* timer;
    int generations;
    bool universe[102][102]; // map
    int universeSize;
    bool isAlive(int k, int j); // return true if universe[k][j] accept rules
    
};

#endif // mainView_H
