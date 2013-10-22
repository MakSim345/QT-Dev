/*
 * clockmenu.h
 */

#ifndef CLOCKMENU_H
#define CLOCKMENU_H

#include <QMenu>
#include <QAction>
#include <QString>

class ClockFrame;

/**
 *
 * @author Michael Rex
 */
class ClockMenu : public QMenu
{
Q_OBJECT
public:
    ClockMenu(QWidget* parent = 0);
    ~ClockMenu();
    
private slots:
    void toggleLocked();
    void setStyleDefault();
    void setStyleFlatYellow();
    void setStyleFlatRed();
    void setStyleFlatGreen();

private:
    QAction* createStyleAction(QString name, QString descr);
    
    ClockFrame* clock;
    QAction* lockAction;
};

#endif
