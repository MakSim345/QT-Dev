#ifndef _ANIM_WIDGET_H_
#define _ANIM_WIDGET_H_

#include <QLabel>
#include <QStateMachine>
#include <QWidget>
 
class AnimWidget : public QWidget 
{
    Q_OBJECT

public:
    AnimWidget();
 
signals:
    /* signal for triggering state machine changes */
    void clicked();
 
protected:
    /* here we will be catching clicks */
    virtual void mouseReleaseEvent(QMouseEvent*);
 
private:
    QStateMachine machine_;
    QLabel* photo_;
};

#endif
