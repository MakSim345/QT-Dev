/********************************************************************************
** Form generated from reading ui file 'GUI_EVE.ui'
**
** Created: Fri 4. Apr 10:59:27 2008
**      by: Qt User Interface Compiler version 4.3.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GUI_EVE_H
#define UI_GUI_EVE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

class Ui_MainGUI
{
public:
    QPushButton *IDE_Exit;
    QPushButton *pushButton_6;
    QPushButton *IDC_Connect;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *IDC_TCTemp;
    QLabel *label_5;
    QLineEdit *IDC_OCTemp;
    QLineEdit *IDC_AirFlow;
    QLineEdit *IDC_OxigFlow;
    QLineEdit *IDC_TotalFlow;
    QLineEdit *IDC_ACTemp;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QLineEdit *IDC_CPULoad;
    QLineEdit *IDC_O2Comp;
    QLabel *label_4;
    QGroupBox *groupBox_3;
    QLabel *label_10;
    QLineEdit *IDC_ComByteCounter;
    QLineEdit *IDC_ComByteCounterSent;
    QLabel *label_11;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_14;
    QGroupBox *groupBox_4;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *IDC_TotalFlowResult;
    QLabel *label_18;
    QLineEdit *IDC_ExhalFlow;
    QLineEdit *IDC_O2Percents;
    QLineEdit *IDC_TimeOff;
    QLineEdit *IDC_TimeON;
    QLineEdit *IDC_ExhalFlow2;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *IDC_TimeONPlus;
    QPushButton *IDC_TimeONMinus;
    QPushButton *IDC_TimeOFFPlus;
    QPushButton *IDC_TimeOFFMinus;
    QPushButton *IDC_TotalFlowMinus;
    QPushButton *IDC_TotalFlowPlus;
    QPushButton *IDC_ExhFlowMinus;
    QPushButton *IDC_ExhFlowPlus;
    QPushButton *IDC_ExhFlowMinus2;
    QPushButton *IDC_ExhFlowPlus2;
    QPushButton *IDC_O2PercentPlus;
    QPushButton *IDC_O2PercentMinus;
    QLineEdit *IDC_O2PercentsSteps;
    QLabel *label_23;
    QLineEdit *IDC_TotalFlowSteps;
    QLineEdit *IDC_ExhFlowSteps;
    QLineEdit *IDC_ExhFlowSteps2;
    QPushButton *IDC_RunVentilation;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QGroupBox *groupBox_5;
    QLabel *label_24;
    QLineEdit *editTotalFlow_7;
    QLineEdit *editTotalFlow_8;
    QLabel *label_15;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_14;
    QLineEdit *editTotalFlow_9;
    QPushButton *pushButton_7;
    QGroupBox *groupBox_6;
    QLabel *label_28;
    QLabel *label_29;
    QLineEdit *IDC_DitherDAC;
    QLabel *label_30;
    QLineEdit *IDC_ExhDAC;
    QLineEdit *IDC_O2DAC;
    QLineEdit *IDC_AirDAC;
    QLabel *label_31;
    QLabel *label_32;
    QCheckBox *IDC_AIRVLV_CNTRL;
    QCheckBox *IDC_O2VLV_CNTRL;
    QCheckBox *IDC_EXHVLV_CNTRL;
    QGroupBox *groupBox_7;
    QLabel *label_33;
    QLineEdit *IDC_COM_NUMBER;
    QLineEdit *IDC_COM_SPEED;
    QLabel *label_34;
    QLineEdit *IDC_InformBox;

    void setupUi(QDialog *MainGUI)
    {
    if (MainGUI->objectName().isEmpty())
        MainGUI->setObjectName(QString::fromUtf8("MainGUI"));
    MainGUI->resize(1023, 714);
    IDE_Exit = new QPushButton(MainGUI);
    IDE_Exit->setObjectName(QString::fromUtf8("IDE_Exit"));
    IDE_Exit->setGeometry(QRect(830, 590, 171, 51));
    pushButton_6 = new QPushButton(MainGUI);
    pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
    pushButton_6->setGeometry(QRect(830, 530, 171, 51));
    IDC_Connect = new QPushButton(MainGUI);
    IDC_Connect->setObjectName(QString::fromUtf8("IDC_Connect"));
    IDC_Connect->setGeometry(QRect(240, 560, 221, 51));
    groupBox = new QGroupBox(MainGUI);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 0, 221, 321));
    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 30, 94, 22));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(-60, 10, 71, 21));
    IDC_TCTemp = new QLineEdit(groupBox);
    IDC_TCTemp->setObjectName(QString::fromUtf8("IDC_TCTemp"));
    IDC_TCTemp->setGeometry(QRect(110, 170, 101, 41));
    label_5 = new QLabel(groupBox);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(10, 80, 90, 22));
    IDC_OCTemp = new QLineEdit(groupBox);
    IDC_OCTemp->setObjectName(QString::fromUtf8("IDC_OCTemp"));
    IDC_OCTemp->setGeometry(QRect(110, 220, 101, 41));
    IDC_AirFlow = new QLineEdit(groupBox);
    IDC_AirFlow->setObjectName(QString::fromUtf8("IDC_AirFlow"));
    IDC_AirFlow->setGeometry(QRect(110, 120, 101, 41));
    IDC_OxigFlow = new QLineEdit(groupBox);
    IDC_OxigFlow->setObjectName(QString::fromUtf8("IDC_OxigFlow"));
    IDC_OxigFlow->setGeometry(QRect(110, 70, 101, 41));
    IDC_TotalFlow = new QLineEdit(groupBox);
    IDC_TotalFlow->setObjectName(QString::fromUtf8("IDC_TotalFlow"));
    IDC_TotalFlow->setGeometry(QRect(110, 20, 101, 41));
    IDC_ACTemp = new QLineEdit(groupBox);
    IDC_ACTemp->setObjectName(QString::fromUtf8("IDC_ACTemp"));
    IDC_ACTemp->setGeometry(QRect(110, 270, 101, 41));
    label_6 = new QLabel(groupBox);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(10, 130, 94, 22));
    label_7 = new QLabel(groupBox);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(10, 180, 94, 22));
    label_8 = new QLabel(groupBox);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setGeometry(QRect(10, 230, 94, 22));
    label_9 = new QLabel(groupBox);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(10, 280, 94, 22));
    groupBox_2 = new QGroupBox(MainGUI);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(10, 440, 221, 111));
    label_3 = new QLabel(groupBox_2);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(20, 20, 72, 21));
    IDC_CPULoad = new QLineEdit(groupBox_2);
    IDC_CPULoad->setObjectName(QString::fromUtf8("IDC_CPULoad"));
    IDC_CPULoad->setGeometry(QRect(110, 10, 101, 41));
    IDC_O2Comp = new QLineEdit(groupBox_2);
    IDC_O2Comp->setObjectName(QString::fromUtf8("IDC_O2Comp"));
    IDC_O2Comp->setGeometry(QRect(110, 60, 101, 41));
    label_4 = new QLabel(groupBox_2);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(20, 70, 71, 21));
    groupBox_3 = new QGroupBox(MainGUI);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(10, 320, 221, 121));
    label_10 = new QLabel(groupBox_3);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    label_10->setGeometry(QRect(20, 30, 72, 21));
    IDC_ComByteCounter = new QLineEdit(groupBox_3);
    IDC_ComByteCounter->setObjectName(QString::fromUtf8("IDC_ComByteCounter"));
    IDC_ComByteCounter->setGeometry(QRect(110, 20, 101, 41));
    IDC_ComByteCounterSent = new QLineEdit(groupBox_3);
    IDC_ComByteCounterSent->setObjectName(QString::fromUtf8("IDC_ComByteCounterSent"));
    IDC_ComByteCounterSent->setGeometry(QRect(110, 70, 101, 41));
    label_11 = new QLabel(groupBox_3);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    label_11->setGeometry(QRect(20, 80, 71, 21));
    pushButton_11 = new QPushButton(MainGUI);
    pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
    pushButton_11->setGeometry(QRect(10, 650, 171, 51));
    pushButton_12 = new QPushButton(MainGUI);
    pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
    pushButton_12->setGeometry(QRect(190, 650, 171, 51));
    pushButton_14 = new QPushButton(MainGUI);
    pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
    pushButton_14->setGeometry(QRect(830, 650, 171, 51));
    groupBox_4 = new QGroupBox(MainGUI);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    groupBox_4->setGeometry(QRect(240, 0, 571, 441));
    label_16 = new QLabel(groupBox_4);
    label_16->setObjectName(QString::fromUtf8("label_16"));
    label_16->setGeometry(QRect(10, 40, 94, 22));
    label_17 = new QLabel(groupBox_4);
    label_17->setObjectName(QString::fromUtf8("label_17"));
    label_17->setGeometry(QRect(-60, 10, 71, 21));
    IDC_TotalFlowResult = new QLineEdit(groupBox_4);
    IDC_TotalFlowResult->setObjectName(QString::fromUtf8("IDC_TotalFlowResult"));
    IDC_TotalFlowResult->setGeometry(QRect(110, 240, 101, 41));
    label_18 = new QLabel(groupBox_4);
    label_18->setObjectName(QString::fromUtf8("label_18"));
    label_18->setGeometry(QRect(10, 110, 90, 22));
    IDC_ExhalFlow = new QLineEdit(groupBox_4);
    IDC_ExhalFlow->setObjectName(QString::fromUtf8("IDC_ExhalFlow"));
    IDC_ExhalFlow->setGeometry(QRect(110, 310, 101, 41));
    IDC_O2Percents = new QLineEdit(groupBox_4);
    IDC_O2Percents->setObjectName(QString::fromUtf8("IDC_O2Percents"));
    IDC_O2Percents->setGeometry(QRect(110, 170, 101, 41));
    IDC_TimeOff = new QLineEdit(groupBox_4);
    IDC_TimeOff->setObjectName(QString::fromUtf8("IDC_TimeOff"));
    IDC_TimeOff->setGeometry(QRect(110, 100, 101, 41));
    IDC_TimeON = new QLineEdit(groupBox_4);
    IDC_TimeON->setObjectName(QString::fromUtf8("IDC_TimeON"));
    IDC_TimeON->setGeometry(QRect(110, 30, 101, 41));
    IDC_ExhalFlow2 = new QLineEdit(groupBox_4);
    IDC_ExhalFlow2->setObjectName(QString::fromUtf8("IDC_ExhalFlow2"));
    IDC_ExhalFlow2->setGeometry(QRect(110, 380, 101, 41));
    label_19 = new QLabel(groupBox_4);
    label_19->setObjectName(QString::fromUtf8("label_19"));
    label_19->setGeometry(QRect(10, 180, 94, 22));
    label_20 = new QLabel(groupBox_4);
    label_20->setObjectName(QString::fromUtf8("label_20"));
    label_20->setGeometry(QRect(10, 250, 94, 22));
    label_21 = new QLabel(groupBox_4);
    label_21->setObjectName(QString::fromUtf8("label_21"));
    label_21->setGeometry(QRect(10, 320, 94, 22));
    label_22 = new QLabel(groupBox_4);
    label_22->setObjectName(QString::fromUtf8("label_22"));
    label_22->setGeometry(QRect(10, 390, 94, 22));
    IDC_TimeONPlus = new QPushButton(groupBox_4);
    IDC_TimeONPlus->setObjectName(QString::fromUtf8("IDC_TimeONPlus"));
    IDC_TimeONPlus->setGeometry(QRect(230, 20, 61, 51));
    IDC_TimeONMinus = new QPushButton(groupBox_4);
    IDC_TimeONMinus->setObjectName(QString::fromUtf8("IDC_TimeONMinus"));
    IDC_TimeONMinus->setGeometry(QRect(310, 20, 61, 51));
    IDC_TimeOFFPlus = new QPushButton(groupBox_4);
    IDC_TimeOFFPlus->setObjectName(QString::fromUtf8("IDC_TimeOFFPlus"));
    IDC_TimeOFFPlus->setGeometry(QRect(230, 90, 61, 51));
    IDC_TimeOFFMinus = new QPushButton(groupBox_4);
    IDC_TimeOFFMinus->setObjectName(QString::fromUtf8("IDC_TimeOFFMinus"));
    IDC_TimeOFFMinus->setGeometry(QRect(310, 90, 61, 51));
    IDC_TotalFlowMinus = new QPushButton(groupBox_4);
    IDC_TotalFlowMinus->setObjectName(QString::fromUtf8("IDC_TotalFlowMinus"));
    IDC_TotalFlowMinus->setGeometry(QRect(310, 230, 61, 51));
    IDC_TotalFlowPlus = new QPushButton(groupBox_4);
    IDC_TotalFlowPlus->setObjectName(QString::fromUtf8("IDC_TotalFlowPlus"));
    IDC_TotalFlowPlus->setGeometry(QRect(230, 230, 61, 51));
    IDC_ExhFlowMinus = new QPushButton(groupBox_4);
    IDC_ExhFlowMinus->setObjectName(QString::fromUtf8("IDC_ExhFlowMinus"));
    IDC_ExhFlowMinus->setGeometry(QRect(310, 300, 61, 51));
    IDC_ExhFlowPlus = new QPushButton(groupBox_4);
    IDC_ExhFlowPlus->setObjectName(QString::fromUtf8("IDC_ExhFlowPlus"));
    IDC_ExhFlowPlus->setGeometry(QRect(230, 300, 61, 51));
    IDC_ExhFlowMinus2 = new QPushButton(groupBox_4);
    IDC_ExhFlowMinus2->setObjectName(QString::fromUtf8("IDC_ExhFlowMinus2"));
    IDC_ExhFlowMinus2->setGeometry(QRect(310, 370, 61, 51));
    IDC_ExhFlowPlus2 = new QPushButton(groupBox_4);
    IDC_ExhFlowPlus2->setObjectName(QString::fromUtf8("IDC_ExhFlowPlus2"));
    IDC_ExhFlowPlus2->setGeometry(QRect(230, 370, 61, 51));
    IDC_O2PercentPlus = new QPushButton(groupBox_4);
    IDC_O2PercentPlus->setObjectName(QString::fromUtf8("IDC_O2PercentPlus"));
    IDC_O2PercentPlus->setGeometry(QRect(230, 160, 61, 51));
    IDC_O2PercentMinus = new QPushButton(groupBox_4);
    IDC_O2PercentMinus->setObjectName(QString::fromUtf8("IDC_O2PercentMinus"));
    IDC_O2PercentMinus->setGeometry(QRect(310, 160, 61, 51));
    IDC_O2PercentsSteps = new QLineEdit(groupBox_4);
    IDC_O2PercentsSteps->setObjectName(QString::fromUtf8("IDC_O2PercentsSteps"));
    IDC_O2PercentsSteps->setGeometry(QRect(460, 160, 101, 41));
    label_23 = new QLabel(groupBox_4);
    label_23->setObjectName(QString::fromUtf8("label_23"));
    label_23->setGeometry(QRect(410, 170, 51, 22));
    IDC_TotalFlowSteps = new QLineEdit(groupBox_4);
    IDC_TotalFlowSteps->setObjectName(QString::fromUtf8("IDC_TotalFlowSteps"));
    IDC_TotalFlowSteps->setGeometry(QRect(460, 230, 101, 41));
    IDC_ExhFlowSteps = new QLineEdit(groupBox_4);
    IDC_ExhFlowSteps->setObjectName(QString::fromUtf8("IDC_ExhFlowSteps"));
    IDC_ExhFlowSteps->setGeometry(QRect(460, 300, 101, 41));
    IDC_ExhFlowSteps2 = new QLineEdit(groupBox_4);
    IDC_ExhFlowSteps2->setObjectName(QString::fromUtf8("IDC_ExhFlowSteps2"));
    IDC_ExhFlowSteps2->setGeometry(QRect(460, 370, 101, 41));
    IDC_RunVentilation = new QPushButton(groupBox_4);
    IDC_RunVentilation->setObjectName(QString::fromUtf8("IDC_RunVentilation"));
    IDC_RunVentilation->setGeometry(QRect(390, 20, 171, 51));
    label_25 = new QLabel(groupBox_4);
    label_25->setObjectName(QString::fromUtf8("label_25"));
    label_25->setGeometry(QRect(410, 240, 51, 22));
    label_26 = new QLabel(groupBox_4);
    label_26->setObjectName(QString::fromUtf8("label_26"));
    label_26->setGeometry(QRect(410, 310, 51, 22));
    label_27 = new QLabel(groupBox_4);
    label_27->setObjectName(QString::fromUtf8("label_27"));
    label_27->setGeometry(QRect(410, 380, 51, 22));
    groupBox_5 = new QGroupBox(MainGUI);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    groupBox_5->setGeometry(QRect(510, 440, 301, 231));
    label_24 = new QLabel(groupBox_5);
    label_24->setObjectName(QString::fromUtf8("label_24"));
    label_24->setGeometry(QRect(-60, 10, 71, 21));
    editTotalFlow_7 = new QLineEdit(groupBox_5);
    editTotalFlow_7->setObjectName(QString::fromUtf8("editTotalFlow_7"));
    editTotalFlow_7->setGeometry(QRect(150, 20, 101, 41));
    editTotalFlow_8 = new QLineEdit(groupBox_5);
    editTotalFlow_8->setObjectName(QString::fromUtf8("editTotalFlow_8"));
    editTotalFlow_8->setGeometry(QRect(150, 70, 101, 41));
    label_15 = new QLabel(groupBox_5);
    label_15->setObjectName(QString::fromUtf8("label_15"));
    label_15->setGeometry(QRect(30, 120, 111, 41));
    label_13 = new QLabel(groupBox_5);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    label_13->setGeometry(QRect(20, 80, 121, 22));
    label_12 = new QLabel(groupBox_5);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setGeometry(QRect(60, 30, 94, 22));
    label_14 = new QLabel(groupBox_5);
    label_14->setObjectName(QString::fromUtf8("label_14"));
    label_14->setGeometry(QRect(260, 80, 51, 22));
    editTotalFlow_9 = new QLineEdit(groupBox_5);
    editTotalFlow_9->setObjectName(QString::fromUtf8("editTotalFlow_9"));
    editTotalFlow_9->setGeometry(QRect(150, 120, 101, 41));
    pushButton_7 = new QPushButton(groupBox_5);
    pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
    pushButton_7->setGeometry(QRect(80, 170, 171, 51));
    groupBox_6 = new QGroupBox(MainGUI);
    groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
    groupBox_6->setGeometry(QRect(820, 0, 191, 321));
    label_28 = new QLabel(groupBox_6);
    label_28->setObjectName(QString::fromUtf8("label_28"));
    label_28->setGeometry(QRect(10, 30, 71, 22));
    label_29 = new QLabel(groupBox_6);
    label_29->setObjectName(QString::fromUtf8("label_29"));
    label_29->setGeometry(QRect(-60, 10, 71, 21));
    IDC_DitherDAC = new QLineEdit(groupBox_6);
    IDC_DitherDAC->setObjectName(QString::fromUtf8("IDC_DitherDAC"));
    IDC_DitherDAC->setGeometry(QRect(80, 170, 101, 41));
    label_30 = new QLabel(groupBox_6);
    label_30->setObjectName(QString::fromUtf8("label_30"));
    label_30->setGeometry(QRect(20, 80, 61, 22));
    IDC_ExhDAC = new QLineEdit(groupBox_6);
    IDC_ExhDAC->setObjectName(QString::fromUtf8("IDC_ExhDAC"));
    IDC_ExhDAC->setGeometry(QRect(80, 120, 101, 41));
    IDC_O2DAC = new QLineEdit(groupBox_6);
    IDC_O2DAC->setObjectName(QString::fromUtf8("IDC_O2DAC"));
    IDC_O2DAC->setGeometry(QRect(80, 70, 101, 41));
    IDC_AirDAC = new QLineEdit(groupBox_6);
    IDC_AirDAC->setObjectName(QString::fromUtf8("IDC_AirDAC"));
    IDC_AirDAC->setGeometry(QRect(80, 20, 101, 41));
    label_31 = new QLabel(groupBox_6);
    label_31->setObjectName(QString::fromUtf8("label_31"));
    label_31->setGeometry(QRect(10, 130, 71, 22));
    label_32 = new QLabel(groupBox_6);
    label_32->setObjectName(QString::fromUtf8("label_32"));
    label_32->setGeometry(QRect(10, 180, 71, 22));
    IDC_AIRVLV_CNTRL = new QCheckBox(groupBox_6);
    IDC_AIRVLV_CNTRL->setObjectName(QString::fromUtf8("IDC_AIRVLV_CNTRL"));
    IDC_AIRVLV_CNTRL->setGeometry(QRect(20, 220, 141, 21));
    IDC_O2VLV_CNTRL = new QCheckBox(groupBox_6);
    IDC_O2VLV_CNTRL->setObjectName(QString::fromUtf8("IDC_O2VLV_CNTRL"));
    IDC_O2VLV_CNTRL->setGeometry(QRect(20, 250, 141, 19));
    IDC_EXHVLV_CNTRL = new QCheckBox(groupBox_6);
    IDC_EXHVLV_CNTRL->setObjectName(QString::fromUtf8("IDC_EXHVLV_CNTRL"));
    IDC_EXHVLV_CNTRL->setGeometry(QRect(20, 280, 151, 19));
    groupBox_7 = new QGroupBox(MainGUI);
    groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
    groupBox_7->setGeometry(QRect(240, 440, 221, 111));
    label_33 = new QLabel(groupBox_7);
    label_33->setObjectName(QString::fromUtf8("label_33"));
    label_33->setGeometry(QRect(20, 20, 72, 21));
    IDC_COM_NUMBER = new QLineEdit(groupBox_7);
    IDC_COM_NUMBER->setObjectName(QString::fromUtf8("IDC_COM_NUMBER"));
    IDC_COM_NUMBER->setGeometry(QRect(110, 10, 101, 41));
    IDC_COM_SPEED = new QLineEdit(groupBox_7);
    IDC_COM_SPEED->setObjectName(QString::fromUtf8("IDC_COM_SPEED"));
    IDC_COM_SPEED->setGeometry(QRect(110, 60, 101, 41));
    label_34 = new QLabel(groupBox_7);
    label_34->setObjectName(QString::fromUtf8("label_34"));
    label_34->setGeometry(QRect(20, 70, 71, 21));
    IDC_InformBox = new QLineEdit(MainGUI);
    IDC_InformBox->setObjectName(QString::fromUtf8("IDC_InformBox"));
    IDC_InformBox->setGeometry(QRect(380, 680, 431, 21));
    QWidget::setTabOrder(IDC_Connect, IDC_RunVentilation);
    QWidget::setTabOrder(IDC_RunVentilation, IDC_TimeONPlus);
    QWidget::setTabOrder(IDC_TimeONPlus, IDC_TimeONMinus);
    QWidget::setTabOrder(IDC_TimeONMinus, IDC_TimeOFFPlus);
    QWidget::setTabOrder(IDC_TimeOFFPlus, IDC_TimeOFFMinus);
    QWidget::setTabOrder(IDC_TimeOFFMinus, IDC_O2PercentPlus);
    QWidget::setTabOrder(IDC_O2PercentPlus, IDC_O2PercentMinus);
    QWidget::setTabOrder(IDC_O2PercentMinus, IDC_TotalFlowPlus);
    QWidget::setTabOrder(IDC_TotalFlowPlus, IDC_TotalFlowMinus);
    QWidget::setTabOrder(IDC_TotalFlowMinus, IDC_ExhFlowPlus);
    QWidget::setTabOrder(IDC_ExhFlowPlus, IDC_ExhFlowMinus);
    QWidget::setTabOrder(IDC_ExhFlowMinus, IDC_ExhFlowPlus2);
    QWidget::setTabOrder(IDC_ExhFlowPlus2, IDC_ExhFlowMinus2);
    QWidget::setTabOrder(IDC_ExhFlowMinus2, pushButton_7);
    QWidget::setTabOrder(pushButton_7, pushButton_6);
    QWidget::setTabOrder(pushButton_6, IDE_Exit);
    QWidget::setTabOrder(IDE_Exit, pushButton_14);
    QWidget::setTabOrder(pushButton_14, IDC_O2Percents);
    QWidget::setTabOrder(IDC_O2Percents, IDC_TimeOff);
    QWidget::setTabOrder(IDC_TimeOff, IDC_TimeON);
    QWidget::setTabOrder(IDC_TimeON, IDC_ExhalFlow2);
    QWidget::setTabOrder(IDC_ExhalFlow2, IDC_TotalFlowResult);
    QWidget::setTabOrder(IDC_TotalFlowResult, IDC_TCTemp);
    QWidget::setTabOrder(IDC_TCTemp, IDC_OCTemp);
    QWidget::setTabOrder(IDC_OCTemp, IDC_AirFlow);
    QWidget::setTabOrder(IDC_AirFlow, IDC_CPULoad);
    QWidget::setTabOrder(IDC_CPULoad, IDC_ACTemp);
    QWidget::setTabOrder(IDC_ACTemp, IDC_ComByteCounter);
    QWidget::setTabOrder(IDC_ComByteCounter, IDC_O2Comp);
    QWidget::setTabOrder(IDC_O2Comp, pushButton_11);
    QWidget::setTabOrder(pushButton_11, IDC_ComByteCounterSent);
    QWidget::setTabOrder(IDC_ComByteCounterSent, IDC_OxigFlow);
    QWidget::setTabOrder(IDC_OxigFlow, IDC_TotalFlow);
    QWidget::setTabOrder(IDC_TotalFlow, IDC_O2PercentsSteps);
    QWidget::setTabOrder(IDC_O2PercentsSteps, IDC_TotalFlowSteps);
    QWidget::setTabOrder(IDC_TotalFlowSteps, IDC_ExhFlowSteps);
    QWidget::setTabOrder(IDC_ExhFlowSteps, IDC_ExhFlowSteps2);
    QWidget::setTabOrder(IDC_ExhFlowSteps2, IDC_ExhalFlow);
    QWidget::setTabOrder(IDC_ExhalFlow, editTotalFlow_7);
    QWidget::setTabOrder(editTotalFlow_7, editTotalFlow_8);
    QWidget::setTabOrder(editTotalFlow_8, editTotalFlow_9);
    QWidget::setTabOrder(editTotalFlow_9, pushButton_12);
    QWidget::setTabOrder(pushButton_12, IDC_DitherDAC);
    QWidget::setTabOrder(IDC_DitherDAC, IDC_ExhDAC);
    QWidget::setTabOrder(IDC_ExhDAC, IDC_O2DAC);
    QWidget::setTabOrder(IDC_O2DAC, IDC_AirDAC);
    QWidget::setTabOrder(IDC_AirDAC, IDC_AIRVLV_CNTRL);
    QWidget::setTabOrder(IDC_AIRVLV_CNTRL, IDC_O2VLV_CNTRL);
    QWidget::setTabOrder(IDC_O2VLV_CNTRL, IDC_EXHVLV_CNTRL);
    QWidget::setTabOrder(IDC_EXHVLV_CNTRL, IDC_COM_NUMBER);
    QWidget::setTabOrder(IDC_COM_NUMBER, IDC_COM_SPEED);
    QWidget::setTabOrder(IDC_COM_SPEED, IDC_InformBox);

    retranslateUi(MainGUI);
    QObject::connect(pushButton_14, SIGNAL(clicked()), MainGUI, SLOT(close()));

    QMetaObject::connectSlotsByName(MainGUI);
    } // setupUi

    void retranslateUi(QDialog *MainGUI)
    {
    MainGUI->setWindowTitle(QApplication::translate("MainGUI", "SW Pilot GUI", 0, QApplication::UnicodeUTF8));
    MainGUI->setStyleSheet(QApplication::translate("MainGUI", "QDialog\n"
"{\n"
"   background-color: grey;\n"
"}\n"
"", 0, QApplication::UnicodeUTF8));
    IDE_Exit->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 18px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDE_Exit->setText(QApplication::translate("MainGUI", "&Exit", 0, QApplication::UnicodeUTF8));
    pushButton_6->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 18px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    pushButton_6->setText(QApplication::translate("MainGUI", "Air / NO2", 0, QApplication::UnicodeUTF8));
    IDC_Connect->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 18px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_Connect->setText(QApplication::translate("MainGUI", "&Connect", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("MainGUI", "EVE Sensor Info", 0, QApplication::UnicodeUTF8));
    label_2->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainGUI", "Total Flow:", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainGUI", "Total Flow:", 0, QApplication::UnicodeUTF8));
    IDC_TCTemp->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_TCTemp->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    label_5->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("MainGUI", "Oxid Flow:", 0, QApplication::UnicodeUTF8));
    IDC_OCTemp->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_OCTemp->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_AirFlow->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_AirFlow->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_OxigFlow->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_OxigFlow->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlow->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlow->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_ACTemp->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ACTemp->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    label_6->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("MainGUI", "Air Flow", 0, QApplication::UnicodeUTF8));
    label_7->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("MainGUI", "TCTemp", 0, QApplication::UnicodeUTF8));
    label_8->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("MainGUI", "OCTemp", 0, QApplication::UnicodeUTF8));
    label_9->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("MainGUI", "ACTemp", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("MainGUI", "Other EVE data", 0, QApplication::UnicodeUTF8));
    label_3->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainGUI", "CPU Load %:", 0, QApplication::UnicodeUTF8));
    IDC_CPULoad->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_CPULoad->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_O2Comp->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_O2Comp->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    label_4->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainGUI", "O2 Comp %", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("MainGUI", "EVE byte transfer info", 0, QApplication::UnicodeUTF8));
    label_10->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("MainGUI", "Received:", 0, QApplication::UnicodeUTF8));
    IDC_ComByteCounter->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: red;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ComByteCounter->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_ComByteCounterSent->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: red;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ComByteCounterSent->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    label_11->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_11->setText(QApplication::translate("MainGUI", "Sent bytes:", 0, QApplication::UnicodeUTF8));
    pushButton_11->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: lightgray;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 lightblue);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 18px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"   background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 RGB(105, 230,230));\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"   background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 gray stop: 0.3 RGB(0, 0, 0), stop: 0.8 RGB(50, 50,50), stop: 1.0 RGB(105, 230,230));\n"
"}", 0, QApplication::UnicodeUTF8));
    pushButton_11->setText(QApplication::translate("MainGUI", "TV ml", 0, QApplication::UnicodeUTF8));
    pushButton_12->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: lightgray;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 lightblue);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 18px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"   background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 RGB(105, 230,230));\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"   background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 gray stop: 0.3 RGB(0, 0, 0), stop: 0.8 RGB(50, 50,50), stop: 1.0 RGB(105, 230,230));\n"
"}", 0, QApplication::UnicodeUTF8));
    pushButton_12->setText(QApplication::translate("MainGUI", "Hoover", 0, QApplication::UnicodeUTF8));
    pushButton_14->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: lightgray;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 lightblue);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 18px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"   background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 RGB(105, 230,230));\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"   background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 gray stop: 0.3 RGB(0, 0, 0), stop: 0.8 RGB(50, 50,50), stop: 1.0 RGB(105, 230,230));\n"
"}", 0, QApplication::UnicodeUTF8));
    pushButton_14->setText(QApplication::translate("MainGUI", "Close Form", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QApplication::translate("MainGUI", "VCB Control", 0, QApplication::UnicodeUTF8));
    label_16->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_16->setText(QApplication::translate("MainGUI", "Time OFF", 0, QApplication::UnicodeUTF8));
    label_17->setText(QApplication::translate("MainGUI", "Total Flow:", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowResult->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowResult->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    label_18->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_18->setText(QApplication::translate("MainGUI", "Time ON", 0, QApplication::UnicodeUTF8));
    IDC_ExhalFlow->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ExhalFlow->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_O2Percents->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_O2Percents->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_TimeOff->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_TimeOff->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_TimeON->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_TimeON->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_ExhalFlow2->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ExhalFlow2->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    label_19->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_19->setText(QApplication::translate("MainGUI", "O2 %", 0, QApplication::UnicodeUTF8));
    label_20->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_20->setText(QApplication::translate("MainGUI", "Total Flow", 0, QApplication::UnicodeUTF8));
    label_21->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_21->setText(QApplication::translate("MainGUI", "Exh Flow H", 0, QApplication::UnicodeUTF8));
    label_22->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_22->setText(QApplication::translate("MainGUI", "Exh Flow L", 0, QApplication::UnicodeUTF8));
    IDC_TimeONPlus->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 38px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_TimeONPlus->setText(QApplication::translate("MainGUI", "+", 0, QApplication::UnicodeUTF8));
    IDC_TimeONMinus->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 38px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_TimeONMinus->setText(QApplication::translate("MainGUI", "-", 0, QApplication::UnicodeUTF8));
    IDC_TimeOFFPlus->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 38px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_TimeOFFPlus->setText(QApplication::translate("MainGUI", "+", 0, QApplication::UnicodeUTF8));
    IDC_TimeOFFMinus->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 38px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_TimeOFFMinus->setText(QApplication::translate("MainGUI", "-", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowMinus->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 38px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowMinus->setText(QApplication::translate("MainGUI", "-", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowPlus->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 38px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowPlus->setText(QApplication::translate("MainGUI", "+", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowMinus->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 38px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowMinus->setText(QApplication::translate("MainGUI", "-", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowPlus->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 38px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowPlus->setText(QApplication::translate("MainGUI", "+", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowMinus2->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 38px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowMinus2->setText(QApplication::translate("MainGUI", "-", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowPlus2->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 38px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowPlus2->setText(QApplication::translate("MainGUI", "+", 0, QApplication::UnicodeUTF8));
    IDC_O2PercentPlus->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 38px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_O2PercentPlus->setText(QApplication::translate("MainGUI", "+", 0, QApplication::UnicodeUTF8));
    IDC_O2PercentMinus->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 38px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_O2PercentMinus->setText(QApplication::translate("MainGUI", "-", 0, QApplication::UnicodeUTF8));
    IDC_O2PercentsSteps->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_O2PercentsSteps->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    label_23->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_23->setText(QApplication::translate("MainGUI", "Step:", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowSteps->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowSteps->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowSteps->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowSteps->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowSteps2->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowSteps2->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_RunVentilation->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 18px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    IDC_RunVentilation->setText(QApplication::translate("MainGUI", "&Run Ventilation", 0, QApplication::UnicodeUTF8));
    label_25->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_25->setText(QApplication::translate("MainGUI", "Step:", 0, QApplication::UnicodeUTF8));
    label_26->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_26->setText(QApplication::translate("MainGUI", "Step:", 0, QApplication::UnicodeUTF8));
    label_27->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_27->setText(QApplication::translate("MainGUI", "Step:", 0, QApplication::UnicodeUTF8));
    groupBox_5->setTitle(QApplication::translate("MainGUI", "IV Pump", 0, QApplication::UnicodeUTF8));
    label_24->setText(QApplication::translate("MainGUI", "Total Flow:", 0, QApplication::UnicodeUTF8));
    editTotalFlow_7->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    editTotalFlow_7->setText(QApplication::translate("MainGUI", "NaN", 0, QApplication::UnicodeUTF8));
    editTotalFlow_8->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    editTotalFlow_8->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    label_15->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_15->setText(QApplication::translate("MainGUI", "Infusion Rate \n"
"     TCI Target:", 0, QApplication::UnicodeUTF8));
    label_13->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_13->setText(QApplication::translate("MainGUI", "Infused Volume:", 0, QApplication::UnicodeUTF8));
    label_12->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_12->setText(QApplication::translate("MainGUI", "Drug name:", 0, QApplication::UnicodeUTF8));
    label_14->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_14->setText(QApplication::translate("MainGUI", "ml/h", 0, QApplication::UnicodeUTF8));
    editTotalFlow_9->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    editTotalFlow_9->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    pushButton_7->setStyleSheet(QApplication::translate("MainGUI", "QPushButton \n"
"{\n"
"  color: black;\n"
"\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);\n"
"  border: 1px solid black;\n"
"  border-radius: 6px;\n"
"  font: bold 18px;  \n"
"}\n"
"\n"
"QPushButton:hover \n"
"{  \n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 darkgray, stop: 1.0 black);\n"
"  border: 1px solid red;\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"  background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.5 RGB(255, 255, 255), stop: 1.0 black);\n"
"}", 0, QApplication::UnicodeUTF8));
    pushButton_7->setText(QApplication::translate("MainGUI", "Start IV Pump", 0, QApplication::UnicodeUTF8));
    groupBox_6->setTitle(QApplication::translate("MainGUI", "VCB Output", 0, QApplication::UnicodeUTF8));
    label_28->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_28->setText(QApplication::translate("MainGUI", "Air DAC", 0, QApplication::UnicodeUTF8));
    label_29->setText(QApplication::translate("MainGUI", "Total Flow:", 0, QApplication::UnicodeUTF8));
    IDC_DitherDAC->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_DitherDAC->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    label_30->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_30->setText(QApplication::translate("MainGUI", "O2 DAC", 0, QApplication::UnicodeUTF8));
    IDC_ExhDAC->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ExhDAC->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_O2DAC->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_O2DAC->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_AirDAC->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: blue;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_AirDAC->setText(QApplication::translate("MainGUI", "0.0", 0, QApplication::UnicodeUTF8));
    label_31->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_31->setText(QApplication::translate("MainGUI", "Exh DAC", 0, QApplication::UnicodeUTF8));
    label_32->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_32->setText(QApplication::translate("MainGUI", "Dith DAC", 0, QApplication::UnicodeUTF8));
    IDC_AIRVLV_CNTRL->setStyleSheet(QApplication::translate("MainGUI", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_AIRVLV_CNTRL->setText(QApplication::translate("MainGUI", "AIRVLV_CNTRL", 0, QApplication::UnicodeUTF8));
    IDC_O2VLV_CNTRL->setStyleSheet(QApplication::translate("MainGUI", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_O2VLV_CNTRL->setText(QApplication::translate("MainGUI", "O2VLV_CNTRL", 0, QApplication::UnicodeUTF8));
    IDC_EXHVLV_CNTRL->setStyleSheet(QApplication::translate("MainGUI", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_EXHVLV_CNTRL->setText(QApplication::translate("MainGUI", "EXHVLV_CNTRL", 0, QApplication::UnicodeUTF8));
    groupBox_7->setTitle(QApplication::translate("MainGUI", "COM Port settings", 0, QApplication::UnicodeUTF8));
    label_33->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_33->setText(QApplication::translate("MainGUI", "COM Port", 0, QApplication::UnicodeUTF8));
    IDC_COM_NUMBER->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_COM_NUMBER->setText(QApplication::translate("MainGUI", "1", 0, QApplication::UnicodeUTF8));
    IDC_COM_SPEED->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_COM_SPEED->setText(QApplication::translate("MainGUI", "9600", 0, QApplication::UnicodeUTF8));
    label_34->setStyleSheet(QApplication::translate("MainGUI", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_34->setText(QApplication::translate("MainGUI", "Baudrate", 0, QApplication::UnicodeUTF8));
    IDC_InformBox->setStyleSheet(QApplication::translate("MainGUI", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 12px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_InformBox->setText(QApplication::translate("MainGUI", "IDC_InformBox", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainGUI);
    } // retranslateUi

};

namespace Ui {
    class MainGUI: public Ui_MainGUI {};
} // namespace Ui

#endif // UI_GUI_EVE_H
