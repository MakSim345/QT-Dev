/********************************************************************************
** Form generated from reading ui file 'myqtapp.ui'
**
** Created: Tue 19. Aug 15:02:20 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MYQTAPP_H
#define UI_MYQTAPP_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_myQtAppDLG
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *myQtAppDLG)
    {
    if (myQtAppDLG->objectName().isEmpty())
        myQtAppDLG->setObjectName(QString::fromUtf8("myQtAppDLG"));
    myQtAppDLG->resize(292, 75);
    centralwidget = new QWidget(myQtAppDLG);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    pushButton = new QPushButton(centralwidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(190, 10, 75, 24));
    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 10, 171, 16));
    myQtAppDLG->setCentralWidget(centralwidget);
    menubar = new QMenuBar(myQtAppDLG);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 292, 19));
    myQtAppDLG->setMenuBar(menubar);
    statusbar = new QStatusBar(myQtAppDLG);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setGeometry(QRect(0, 56, 292, 19));
    myQtAppDLG->setStatusBar(statusbar);

    retranslateUi(myQtAppDLG);

    QMetaObject::connectSlotsByName(myQtAppDLG);
    } // setupUi

    void retranslateUi(QMainWindow *myQtAppDLG)
    {
        myQtAppDLG->setWindowTitle("MainWindow");
        pushButton->setText("Hello");
        label->setText("Simple UI form with one button");
        Q_UNUSED(myQtAppDLG);
    } // retranslateUi

};

namespace Ui {
    class myQtAppDLG: public Ui_myQtAppDLG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQTAPP_H
