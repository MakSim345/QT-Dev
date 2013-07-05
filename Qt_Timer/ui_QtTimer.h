/********************************************************************************
** Form generated from reading ui file 'QtTimer.ui'
**
** Created: Fri 29. Feb 15:03:12 2008
**      by: Qt User Interface Compiler version 4.3.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QTTIMER_H
#define UI_QTTIMER_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDial>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QSpinBox>
#include <QWidget>

class Ui_QtTimerWidget
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout1;
    QGridLayout *gridLayout2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout3;
    QGridLayout *gridLayout4;
    QRadioButton *mSRadioButton;
    QRadioButton *sRadioButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout5;
    QGridLayout *gridLayout6;
    QDial *dial;
    QSpinBox *spinBox;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout7;
    QGridLayout *gridLayout8;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;

    void setupUi(QWidget *QtTimerWidget)
    {
    if (QtTimerWidget->objectName().isEmpty())
        QtTimerWidget->setObjectName(QString::fromUtf8("QtTimerWidget"));
    QtTimerWidget->resize(309, 241);
    QtTimerWidget->setMinimumSize(QSize(285, 220));
    gridLayout = new QGridLayout(QtTimerWidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox_4 = new QGroupBox(QtTimerWidget);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    gridLayout1 = new QGridLayout(groupBox_4);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    gridLayout2 = new QGridLayout();
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    groupBox = new QGroupBox(groupBox_4);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout3 = new QGridLayout(groupBox);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    gridLayout4 = new QGridLayout();
    gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
    mSRadioButton = new QRadioButton(groupBox);
    mSRadioButton->setObjectName(QString::fromUtf8("mSRadioButton"));
    mSRadioButton->setChecked(false);

    gridLayout4->addWidget(mSRadioButton, 0, 0, 1, 1);

    sRadioButton = new QRadioButton(groupBox);
    sRadioButton->setObjectName(QString::fromUtf8("sRadioButton"));
    sRadioButton->setChecked(true);

    gridLayout4->addWidget(sRadioButton, 1, 0, 1, 1);


    gridLayout3->addLayout(gridLayout4, 0, 0, 1, 1);


    gridLayout2->addWidget(groupBox, 0, 0, 1, 1);

    groupBox_3 = new QGroupBox(groupBox_4);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    gridLayout5 = new QGridLayout(groupBox_3);
    gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
    gridLayout6 = new QGridLayout();
    gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
    dial = new QDial(groupBox_3);
    dial->setObjectName(QString::fromUtf8("dial"));
    dial->setMaximum(999);
    dial->setValue(1);
    dial->setWrapping(false);
    dial->setNotchTarget(50);
    dial->setNotchesVisible(true);

    gridLayout6->addWidget(dial, 0, 0, 1, 1);

    spinBox = new QSpinBox(groupBox_3);
    spinBox->setObjectName(QString::fromUtf8("spinBox"));
    spinBox->setMaximum(999);
    spinBox->setValue(1);

    gridLayout6->addWidget(spinBox, 1, 0, 1, 1);


    gridLayout5->addLayout(gridLayout6, 0, 0, 1, 1);


    gridLayout2->addWidget(groupBox_3, 0, 1, 2, 1);

    groupBox_2 = new QGroupBox(groupBox_4);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    gridLayout7 = new QGridLayout(groupBox_2);
    gridLayout7->setObjectName(QString::fromUtf8("gridLayout7"));
    gridLayout8 = new QGridLayout();
    gridLayout8->setObjectName(QString::fromUtf8("gridLayout8"));
    startButton = new QPushButton(groupBox_2);
    startButton->setObjectName(QString::fromUtf8("startButton"));
    startButton->setCheckable(true);

    gridLayout8->addWidget(startButton, 0, 0, 1, 1);

    stopButton = new QPushButton(groupBox_2);
    stopButton->setObjectName(QString::fromUtf8("stopButton"));
    stopButton->setCheckable(true);
    stopButton->setChecked(true);

    gridLayout8->addWidget(stopButton, 1, 0, 1, 1);

    resetButton = new QPushButton(groupBox_2);
    resetButton->setObjectName(QString::fromUtf8("resetButton"));

    gridLayout8->addWidget(resetButton, 2, 0, 1, 1);


    gridLayout7->addLayout(gridLayout8, 0, 0, 1, 1);


    gridLayout2->addWidget(groupBox_2, 1, 0, 1, 1);


    gridLayout1->addLayout(gridLayout2, 0, 0, 1, 1);


    gridLayout->addWidget(groupBox_4, 0, 0, 1, 1);


    retranslateUi(QtTimerWidget);
    QObject::connect(dial, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    QObject::connect(spinBox, SIGNAL(valueChanged(int)), dial, SLOT(setValue(int)));

    QMetaObject::connectSlotsByName(QtTimerWidget);
    } // setupUi

    void retranslateUi(QWidget *QtTimerWidget)
    {
        QtTimerWidget->setWindowTitle("QtTimerWidget");
        groupBox_4->setTitle(QString());
        groupBox->setTitle("Time Scale");
        mSRadioButton->setText("mS");
        sRadioButton->setText("S");
        groupBox_3->setTitle("Timer Value");
        groupBox_2->setTitle("Power");
        startButton->setText("Start");
        stopButton->setText("Stop");
        resetButton->setText("Reset");
        Q_UNUSED(QtTimerWidget);
    } // retranslateUi

};

namespace Ui {
    class QtTimerWidget: public Ui_QtTimerWidget {};
} // namespace Ui

#endif // UI_QTTIMER_H
