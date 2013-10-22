/*
 * clockmenu.cpp
 *
 */

#include <QIcon>
#include <QPixmap>
#include <QApplication>
#include <QKeySequence>

#include "clockmenu.h"
#include "clockframe.h"

ClockMenu::ClockMenu(QWidget *parent)
 : QMenu(parent)
{
    clock = (ClockFrame*)parent;
    
    QMenu* style = new QMenu(tr("Style"), this);
    this->addMenu(style);

    // populate 'Style' submenu    
    QAction* styleAct;
    
    styleAct = createStyleAction("default", tr("Default"));
    connect(styleAct, SIGNAL(triggered()), this, SLOT(setStyleDefault()));
    style->addAction(styleAct);

    styleAct = createStyleAction("flatred", tr("Flat Red"));
    connect(styleAct, SIGNAL(triggered()), this, SLOT(setStyleFlatRed()));
    style->addAction(styleAct);

    styleAct = createStyleAction("flatyellow", tr("Flat Yellow"));
    connect(styleAct, SIGNAL(triggered()), this, SLOT(setStyleFlatYellow()));
    style->addAction(styleAct);

    styleAct = createStyleAction("flatgreen", tr("Flat Green"));
    connect(styleAct, SIGNAL(triggered()), this, SLOT(setStyleFlatGreen()));
    style->addAction(styleAct);

    // populate 'Background' submenu    
    QMenu* background = new QMenu(tr("Background"), this);
    
    this->addMenu(background);
    

    //         
    lockAction = new QAction(tr("Lock position"), this);
    lockAction->setCheckable(true);
    lockAction->setChecked(clock->isLocked());
    connect(lockAction, SIGNAL(triggered()), this, SLOT(toggleLocked()));
    this->addAction(lockAction);
    
    this->addSeparator();
    
    QAction* aboutAction = new QAction(tr("&About"), this);
    connect(aboutAction, SIGNAL(triggered()), clock, SLOT(about()));
    this->addAction(aboutAction);
    
    QAction* aboutQtAction = new QAction(tr("About Qt"), this);
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    this->addAction(aboutQtAction);
    
    this->addSeparator();
    
    QAction* quitAction = new QAction(tr("&Quit"), this);
    quitAction->setShortcut(QKeySequence(tr("Ctrl+Q")));
    connect(quitAction, SIGNAL(triggered()), clock, SLOT(quit()));
    this->addAction(quitAction);
}


ClockMenu::~ClockMenu()
{
}

QAction* ClockMenu::createStyleAction(QString name, QString descr)
{
    QAction* style = new QAction(descr, this);
    QIcon icon(QPixmap(":/Resources/style_" + name + "_on.png"));
    style->setIcon(icon);
    
    return style;
}

void ClockMenu::toggleLocked()
{
    bool locked = !clock->isLocked();
    clock->setLocked(locked);
    lockAction->setChecked(locked);
}

void ClockMenu::setStyleDefault()
{
    clock->setStyle("default");
}

void ClockMenu::setStyleFlatYellow()
{
    clock->setStyle("flatyellow");
}

void ClockMenu::setStyleFlatRed()
{
    clock->setStyle("flatred");
}

void ClockMenu::setStyleFlatGreen()
{
    clock->setStyle("flatgreen");
}

