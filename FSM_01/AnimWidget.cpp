#include "AnimWidget.h"
//#include "cengine.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPolygon>
#include <QTimer>
#include <QGradient>
#include <QState>
#include <QVariant>
#include <QPropertyAnimation>
 
AnimWidget::AnimWidget() 
{
    photo_ = new QLabel("", this);
    photo_->setGeometry( 0,  0, 40, 40);
    photo_->setScaledContents(true);
    photo_->setPixmap(QPixmap("ottawa.png"));
 
    /* creating 2 states */
    QState *st1 = new QState();
    QState *st2 = new QState();
 
    /* defining photo's properties for each of them */
    st1->assignProperty(photo_, "geometry", QRect( 0,  0, 40, 40));
    st2->assignProperty(photo_, "geometry", QRect(50, 50, 200, 200));
 
    /* define transitions between states by clicking on main window*/
    st1->addTransition(this, SIGNAL(clicked()), st2);
    st2->addTransition(this, SIGNAL(clicked()), st1);
 
    /* adding states to state machine */
    machine_.addState(st1);
    machine_.addState(st2);
    machine_.setInitialState(st1);
 
    /* adding animation */
    QPropertyAnimation* an1 = new QPropertyAnimation(photo_, "geometry");
    machine_.addDefaultAnimation(an1);
    /* customizing the animation */
    an1->setEasingCurve(QEasingCurve::InOutCubic);
    an1->setDuration(700);
    /* starting machine */
    machine_.start();
}
 
void AnimWidget::mouseReleaseEvent(QMouseEvent*) 
{
    emit clicked();
}