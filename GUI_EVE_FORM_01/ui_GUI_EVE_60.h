/********************************************************************************
** Form generated from reading ui file 'GUI_EVE_60.ui'
**
** Created: Mon 11. Aug 09:09:02 2008
**      by: Qt User Interface Compiler version 4.3.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GUI_EVE_60_H
#define UI_GUI_EVE_60_H

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
#include <QtGui/QWidget>

class Ui_GUIForm
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
    QWidget *verticalLayout;
    QPushButton *pushButton;
    QGroupBox *groupBox_5;
    QLabel *label_24;
    QLineEdit *editTotalFlow_7;
    QLineEdit *editTotalFlow_8;
    QLabel *label_15;
    QLabel *label_13;
    QLabel *label_12;
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
    QCheckBox *IDC_SAFE_CLS;
    QCheckBox *IDC_MNVR_OPEN;
    QCheckBox *IDC_OK_TO_ZERO;
    QCheckBox *IDC_FS_PWR_EN;
    QCheckBox *IDC_NEB_ON;
    QCheckBox *IDC_MBUS_RESET;
    QCheckBox *IDC_ZEROINSP_EN;
    QCheckBox *IDC_ZEROAUXP_EN;
    QCheckBox *IDC_VC_BUZZER_ON;
    QCheckBox *IDC_ILIM_MOD_EN;
    QCheckBox *IDC_ILIM_PSM_EN;
    QGroupBox *groupBox_7;
    QLabel *label_33;
    QLineEdit *IDC_COM_NUMBER;
    QLineEdit *IDC_COM_SPEED;
    QLabel *label_34;
    QLineEdit *IDC_InformBox;
    QPushButton *IDC_TestBtn;
    QPushButton *IDC_Connect_2;

    void setupUi(QDialog *GUIForm)
    {
    if (GUIForm->objectName().isEmpty())
        GUIForm->setObjectName(QString::fromUtf8("GUIForm"));
    GUIForm->resize(971, 714);
    IDE_Exit = new QPushButton(GUIForm);
    IDE_Exit->setObjectName(QString::fromUtf8("IDE_Exit"));
    IDE_Exit->setGeometry(QRect(790, 650, 171, 51));
    pushButton_6 = new QPushButton(GUIForm);
    pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
    pushButton_6->setGeometry(QRect(790, 530, 171, 51));
    IDC_Connect = new QPushButton(GUIForm);
    IDC_Connect->setObjectName(QString::fromUtf8("IDC_Connect"));
    IDC_Connect->setGeometry(QRect(250, 620, 201, 51));
    groupBox = new QGroupBox(GUIForm);
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
    groupBox_2 = new QGroupBox(GUIForm);
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
    groupBox_3 = new QGroupBox(GUIForm);
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
    pushButton_11 = new QPushButton(GUIForm);
    pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
    pushButton_11->setGeometry(QRect(10, 650, 171, 51));
    pushButton_12 = new QPushButton(GUIForm);
    pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
    pushButton_12->setGeometry(QRect(790, 590, 171, 51));
    groupBox_4 = new QGroupBox(GUIForm);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    groupBox_4->setGeometry(QRect(240, 0, 521, 441));
    label_16 = new QLabel(groupBox_4);
    label_16->setObjectName(QString::fromUtf8("label_16"));
    label_16->setGeometry(QRect(10, 40, 94, 22));
    label_17 = new QLabel(groupBox_4);
    label_17->setObjectName(QString::fromUtf8("label_17"));
    label_17->setGeometry(QRect(-60, 10, 71, 21));
    IDC_TotalFlowResult = new QLineEdit(groupBox_4);
    IDC_TotalFlowResult->setObjectName(QString::fromUtf8("IDC_TotalFlowResult"));
    IDC_TotalFlowResult->setGeometry(QRect(110, 200, 101, 41));
    label_18 = new QLabel(groupBox_4);
    label_18->setObjectName(QString::fromUtf8("label_18"));
    label_18->setGeometry(QRect(12, 98, 90, 22));
    IDC_ExhalFlow = new QLineEdit(groupBox_4);
    IDC_ExhalFlow->setObjectName(QString::fromUtf8("IDC_ExhalFlow"));
    IDC_ExhalFlow->setGeometry(QRect(110, 250, 101, 41));
    IDC_O2Percents = new QLineEdit(groupBox_4);
    IDC_O2Percents->setObjectName(QString::fromUtf8("IDC_O2Percents"));
    IDC_O2Percents->setGeometry(QRect(110, 140, 101, 41));
    IDC_TimeOff = new QLineEdit(groupBox_4);
    IDC_TimeOff->setObjectName(QString::fromUtf8("IDC_TimeOff"));
    IDC_TimeOff->setGeometry(QRect(110, 88, 101, 41));
    IDC_TimeON = new QLineEdit(groupBox_4);
    IDC_TimeON->setObjectName(QString::fromUtf8("IDC_TimeON"));
    IDC_TimeON->setGeometry(QRect(110, 35, 101, 40));
    IDC_ExhalFlow2 = new QLineEdit(groupBox_4);
    IDC_ExhalFlow2->setObjectName(QString::fromUtf8("IDC_ExhalFlow2"));
    IDC_ExhalFlow2->setGeometry(QRect(110, 310, 101, 41));
    label_19 = new QLabel(groupBox_4);
    label_19->setObjectName(QString::fromUtf8("label_19"));
    label_19->setGeometry(QRect(40, 150, 61, 26));
    label_20 = new QLabel(groupBox_4);
    label_20->setObjectName(QString::fromUtf8("label_20"));
    label_20->setGeometry(QRect(10, 210, 94, 22));
    label_21 = new QLabel(groupBox_4);
    label_21->setObjectName(QString::fromUtf8("label_21"));
    label_21->setGeometry(QRect(10, 260, 94, 22));
    label_22 = new QLabel(groupBox_4);
    label_22->setObjectName(QString::fromUtf8("label_22"));
    label_22->setGeometry(QRect(10, 320, 94, 22));
    IDC_TimeONPlus = new QPushButton(groupBox_4);
    IDC_TimeONPlus->setObjectName(QString::fromUtf8("IDC_TimeONPlus"));
    IDC_TimeONPlus->setGeometry(QRect(220, 30, 61, 51));
    IDC_TimeONMinus = new QPushButton(groupBox_4);
    IDC_TimeONMinus->setObjectName(QString::fromUtf8("IDC_TimeONMinus"));
    IDC_TimeONMinus->setGeometry(QRect(290, 30, 61, 51));
    IDC_TimeOFFPlus = new QPushButton(groupBox_4);
    IDC_TimeOFFPlus->setObjectName(QString::fromUtf8("IDC_TimeOFFPlus"));
    IDC_TimeOFFPlus->setGeometry(QRect(220, 84, 61, 51));
    IDC_TimeOFFMinus = new QPushButton(groupBox_4);
    IDC_TimeOFFMinus->setObjectName(QString::fromUtf8("IDC_TimeOFFMinus"));
    IDC_TimeOFFMinus->setGeometry(QRect(290, 85, 61, 51));
    IDC_TotalFlowMinus = new QPushButton(groupBox_4);
    IDC_TotalFlowMinus->setObjectName(QString::fromUtf8("IDC_TotalFlowMinus"));
    IDC_TotalFlowMinus->setGeometry(QRect(290, 192, 61, 51));
    IDC_TotalFlowPlus = new QPushButton(groupBox_4);
    IDC_TotalFlowPlus->setObjectName(QString::fromUtf8("IDC_TotalFlowPlus"));
    IDC_TotalFlowPlus->setGeometry(QRect(220, 192, 61, 51));
    IDC_ExhFlowMinus = new QPushButton(groupBox_4);
    IDC_ExhFlowMinus->setObjectName(QString::fromUtf8("IDC_ExhFlowMinus"));
    IDC_ExhFlowMinus->setGeometry(QRect(290, 246, 61, 51));
    IDC_ExhFlowPlus = new QPushButton(groupBox_4);
    IDC_ExhFlowPlus->setObjectName(QString::fromUtf8("IDC_ExhFlowPlus"));
    IDC_ExhFlowPlus->setGeometry(QRect(220, 245, 61, 51));
    IDC_ExhFlowMinus2 = new QPushButton(groupBox_4);
    IDC_ExhFlowMinus2->setObjectName(QString::fromUtf8("IDC_ExhFlowMinus2"));
    IDC_ExhFlowMinus2->setGeometry(QRect(290, 300, 61, 51));
    IDC_ExhFlowPlus2 = new QPushButton(groupBox_4);
    IDC_ExhFlowPlus2->setObjectName(QString::fromUtf8("IDC_ExhFlowPlus2"));
    IDC_ExhFlowPlus2->setGeometry(QRect(220, 300, 61, 51));
    IDC_O2PercentPlus = new QPushButton(groupBox_4);
    IDC_O2PercentPlus->setObjectName(QString::fromUtf8("IDC_O2PercentPlus"));
    IDC_O2PercentPlus->setGeometry(QRect(220, 138, 61, 51));
    IDC_O2PercentMinus = new QPushButton(groupBox_4);
    IDC_O2PercentMinus->setObjectName(QString::fromUtf8("IDC_O2PercentMinus"));
    IDC_O2PercentMinus->setGeometry(QRect(290, 139, 61, 51));
    IDC_O2PercentsSteps = new QLineEdit(groupBox_4);
    IDC_O2PercentsSteps->setObjectName(QString::fromUtf8("IDC_O2PercentsSteps"));
    IDC_O2PercentsSteps->setGeometry(QRect(410, 145, 101, 41));
    label_23 = new QLabel(groupBox_4);
    label_23->setObjectName(QString::fromUtf8("label_23"));
    label_23->setGeometry(QRect(360, 150, 51, 22));
    IDC_TotalFlowSteps = new QLineEdit(groupBox_4);
    IDC_TotalFlowSteps->setObjectName(QString::fromUtf8("IDC_TotalFlowSteps"));
    IDC_TotalFlowSteps->setGeometry(QRect(410, 196, 101, 41));
    IDC_ExhFlowSteps = new QLineEdit(groupBox_4);
    IDC_ExhFlowSteps->setObjectName(QString::fromUtf8("IDC_ExhFlowSteps"));
    IDC_ExhFlowSteps->setGeometry(QRect(410, 249, 101, 41));
    IDC_ExhFlowSteps2 = new QLineEdit(groupBox_4);
    IDC_ExhFlowSteps2->setObjectName(QString::fromUtf8("IDC_ExhFlowSteps2"));
    IDC_ExhFlowSteps2->setGeometry(QRect(410, 303, 101, 41));
    IDC_RunVentilation = new QPushButton(groupBox_4);
    IDC_RunVentilation->setObjectName(QString::fromUtf8("IDC_RunVentilation"));
    IDC_RunVentilation->setGeometry(QRect(360, 30, 151, 51));
    label_25 = new QLabel(groupBox_4);
    label_25->setObjectName(QString::fromUtf8("label_25"));
    label_25->setGeometry(QRect(360, 207, 51, 22));
    label_26 = new QLabel(groupBox_4);
    label_26->setObjectName(QString::fromUtf8("label_26"));
    label_26->setGeometry(QRect(360, 260, 51, 22));
    label_27 = new QLabel(groupBox_4);
    label_27->setObjectName(QString::fromUtf8("label_27"));
    label_27->setGeometry(QRect(360, 310, 51, 22));
    verticalLayout = new QWidget(groupBox_4);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setGeometry(QRect(10, 350, 120, 80));
    pushButton = new QPushButton(groupBox_4);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(150, 380, 75, 23));
    groupBox_5 = new QGroupBox(GUIForm);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    groupBox_5->setGeometry(QRect(500, 440, 261, 231));
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
    label_13->setGeometry(QRect(20, 70, 121, 41));
    label_12 = new QLabel(groupBox_5);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setGeometry(QRect(60, 30, 94, 22));
    editTotalFlow_9 = new QLineEdit(groupBox_5);
    editTotalFlow_9->setObjectName(QString::fromUtf8("editTotalFlow_9"));
    editTotalFlow_9->setGeometry(QRect(150, 120, 101, 41));
    pushButton_7 = new QPushButton(groupBox_5);
    pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
    pushButton_7->setGeometry(QRect(60, 170, 191, 51));
    groupBox_6 = new QGroupBox(GUIForm);
    groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
    groupBox_6->setGeometry(QRect(770, 0, 191, 521));
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
    IDC_AIRVLV_CNTRL->setGeometry(QRect(20, 211, 141, 20));
    IDC_O2VLV_CNTRL = new QCheckBox(groupBox_6);
    IDC_O2VLV_CNTRL->setObjectName(QString::fromUtf8("IDC_O2VLV_CNTRL"));
    IDC_O2VLV_CNTRL->setGeometry(QRect(20, 230, 141, 19));
    IDC_EXHVLV_CNTRL = new QCheckBox(groupBox_6);
    IDC_EXHVLV_CNTRL->setObjectName(QString::fromUtf8("IDC_EXHVLV_CNTRL"));
    IDC_EXHVLV_CNTRL->setGeometry(QRect(20, 250, 151, 19));
    IDC_SAFE_CLS = new QCheckBox(groupBox_6);
    IDC_SAFE_CLS->setObjectName(QString::fromUtf8("IDC_SAFE_CLS"));
    IDC_SAFE_CLS->setGeometry(QRect(20, 280, 101, 19));
    IDC_MNVR_OPEN = new QCheckBox(groupBox_6);
    IDC_MNVR_OPEN->setObjectName(QString::fromUtf8("IDC_MNVR_OPEN"));
    IDC_MNVR_OPEN->setGeometry(QRect(20, 300, 121, 19));
    IDC_OK_TO_ZERO = new QCheckBox(groupBox_6);
    IDC_OK_TO_ZERO->setObjectName(QString::fromUtf8("IDC_OK_TO_ZERO"));
    IDC_OK_TO_ZERO->setGeometry(QRect(20, 320, 131, 19));
    IDC_FS_PWR_EN = new QCheckBox(groupBox_6);
    IDC_FS_PWR_EN->setObjectName(QString::fromUtf8("IDC_FS_PWR_EN"));
    IDC_FS_PWR_EN->setGeometry(QRect(20, 340, 121, 19));
    IDC_NEB_ON = new QCheckBox(groupBox_6);
    IDC_NEB_ON->setObjectName(QString::fromUtf8("IDC_NEB_ON"));
    IDC_NEB_ON->setGeometry(QRect(20, 360, 101, 19));
    IDC_MBUS_RESET = new QCheckBox(groupBox_6);
    IDC_MBUS_RESET->setObjectName(QString::fromUtf8("IDC_MBUS_RESET"));
    IDC_MBUS_RESET->setGeometry(QRect(20, 380, 131, 19));
    IDC_ZEROINSP_EN = new QCheckBox(groupBox_6);
    IDC_ZEROINSP_EN->setObjectName(QString::fromUtf8("IDC_ZEROINSP_EN"));
    IDC_ZEROINSP_EN->setGeometry(QRect(20, 410, 151, 19));
    IDC_ZEROAUXP_EN = new QCheckBox(groupBox_6);
    IDC_ZEROAUXP_EN->setObjectName(QString::fromUtf8("IDC_ZEROAUXP_EN"));
    IDC_ZEROAUXP_EN->setGeometry(QRect(20, 430, 151, 19));
    IDC_VC_BUZZER_ON = new QCheckBox(groupBox_6);
    IDC_VC_BUZZER_ON->setObjectName(QString::fromUtf8("IDC_VC_BUZZER_ON"));
    IDC_VC_BUZZER_ON->setGeometry(QRect(20, 450, 151, 19));
    IDC_ILIM_MOD_EN = new QCheckBox(groupBox_6);
    IDC_ILIM_MOD_EN->setObjectName(QString::fromUtf8("IDC_ILIM_MOD_EN"));
    IDC_ILIM_MOD_EN->setGeometry(QRect(20, 480, 151, 19));
    IDC_ILIM_PSM_EN = new QCheckBox(groupBox_6);
    IDC_ILIM_PSM_EN->setObjectName(QString::fromUtf8("IDC_ILIM_PSM_EN"));
    IDC_ILIM_PSM_EN->setGeometry(QRect(20, 500, 131, 19));
    groupBox_7 = new QGroupBox(GUIForm);
    groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
    groupBox_7->setGeometry(QRect(240, 440, 211, 111));
    label_33 = new QLabel(groupBox_7);
    label_33->setObjectName(QString::fromUtf8("label_33"));
    label_33->setGeometry(QRect(20, 20, 72, 21));
    IDC_COM_NUMBER = new QLineEdit(groupBox_7);
    IDC_COM_NUMBER->setObjectName(QString::fromUtf8("IDC_COM_NUMBER"));
    IDC_COM_NUMBER->setGeometry(QRect(100, 10, 101, 41));
    IDC_COM_SPEED = new QLineEdit(groupBox_7);
    IDC_COM_SPEED->setObjectName(QString::fromUtf8("IDC_COM_SPEED"));
    IDC_COM_SPEED->setGeometry(QRect(100, 60, 101, 41));
    label_34 = new QLabel(groupBox_7);
    label_34->setObjectName(QString::fromUtf8("label_34"));
    label_34->setGeometry(QRect(20, 70, 71, 21));
    IDC_InformBox = new QLineEdit(GUIForm);
    IDC_InformBox->setObjectName(QString::fromUtf8("IDC_InformBox"));
    IDC_InformBox->setGeometry(QRect(190, 680, 571, 21));
    IDC_TestBtn = new QPushButton(GUIForm);
    IDC_TestBtn->setObjectName(QString::fromUtf8("IDC_TestBtn"));
    IDC_TestBtn->setGeometry(QRect(10, 597, 171, 51));
    IDC_Connect_2 = new QPushButton(GUIForm);
    IDC_Connect_2->setObjectName(QString::fromUtf8("IDC_Connect_2"));
    IDC_Connect_2->setGeometry(QRect(250, 560, 201, 51));
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
    QWidget::setTabOrder(IDE_Exit, IDC_O2Percents);
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

    retranslateUi(GUIForm);
    QObject::connect(pushButton_12, SIGNAL(clicked()), GUIForm, SLOT(close()));

    QMetaObject::connectSlotsByName(GUIForm);
    } // setupUi

    void retranslateUi(QDialog *GUIForm)
    {
    GUIForm->setWindowTitle(QApplication::translate("GUIForm", "SW Pilot GUI", 0, QApplication::UnicodeUTF8));
    GUIForm->setStyleSheet(QApplication::translate("GUIForm", "QDialog\n"
"{\n"
"   background-color: grey;\n"
"}\n"
"", 0, QApplication::UnicodeUTF8));
    IDE_Exit->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDE_Exit->setText(QApplication::translate("GUIForm", "&Exit", 0, QApplication::UnicodeUTF8));
    pushButton_6->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    pushButton_6->setText(QApplication::translate("GUIForm", "Air / NO2", 0, QApplication::UnicodeUTF8));
    IDC_Connect->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_Connect->setText(QApplication::translate("GUIForm", "&Connect", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("GUIForm", "EVE Sensor Info", 0, QApplication::UnicodeUTF8));
    label_2->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("GUIForm", "Total Flow:", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("GUIForm", "Total Flow:", 0, QApplication::UnicodeUTF8));
    IDC_TCTemp->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_TCTemp->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    label_5->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("GUIForm", "Oxid Flow:", 0, QApplication::UnicodeUTF8));
    IDC_OCTemp->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_OCTemp->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_AirFlow->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_AirFlow->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_OxigFlow->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_OxigFlow->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlow->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlow->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_ACTemp->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ACTemp->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    label_6->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("GUIForm", "Air Flow", 0, QApplication::UnicodeUTF8));
    label_7->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("GUIForm", "TCTemp", 0, QApplication::UnicodeUTF8));
    label_8->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("GUIForm", "OCTemp", 0, QApplication::UnicodeUTF8));
    label_9->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("GUIForm", "ACTemp", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("GUIForm", "Other EVE data", 0, QApplication::UnicodeUTF8));
    label_3->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("GUIForm", "CPU Load %:", 0, QApplication::UnicodeUTF8));
    IDC_CPULoad->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_CPULoad->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_O2Comp->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_O2Comp->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    label_4->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("GUIForm", "O2 Comp %", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("GUIForm", "EVE byte transfer info", 0, QApplication::UnicodeUTF8));
    label_10->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("GUIForm", "Received:", 0, QApplication::UnicodeUTF8));
    IDC_ComByteCounter->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: red;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ComByteCounter->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_ComByteCounterSent->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color: red;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ComByteCounterSent->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    label_11->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_11->setText(QApplication::translate("GUIForm", "Sent bytes:", 0, QApplication::UnicodeUTF8));
    pushButton_11->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    pushButton_11->setText(QApplication::translate("GUIForm", "TV ml", 0, QApplication::UnicodeUTF8));
    pushButton_12->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    pushButton_12->setText(QApplication::translate("GUIForm", "Hoover", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QApplication::translate("GUIForm", "VCB Control", 0, QApplication::UnicodeUTF8));
    label_16->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 20px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_16->setText(QApplication::translate("GUIForm", "Time OFF", 0, QApplication::UnicodeUTF8));
    label_17->setText(QApplication::translate("GUIForm", "Total Flow:", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowResult->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowResult->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    label_18->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 20px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_18->setText(QApplication::translate("GUIForm", "Time ON", 0, QApplication::UnicodeUTF8));
    IDC_ExhalFlow->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ExhalFlow->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_O2Percents->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_O2Percents->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_TimeOff->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_TimeOff->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_TimeON->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_TimeON->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_ExhalFlow2->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ExhalFlow2->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    label_19->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 20px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_19->setText(QApplication::translate("GUIForm", "O2 %", 0, QApplication::UnicodeUTF8));
    label_20->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 18px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_20->setText(QApplication::translate("GUIForm", "Total Flow", 0, QApplication::UnicodeUTF8));
    label_21->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_21->setText(QApplication::translate("GUIForm", "Exh Flow H", 0, QApplication::UnicodeUTF8));
    label_22->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_22->setText(QApplication::translate("GUIForm", "Exh Flow L", 0, QApplication::UnicodeUTF8));
    IDC_TimeONPlus->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_TimeONPlus->setText(QApplication::translate("GUIForm", "+", 0, QApplication::UnicodeUTF8));
    IDC_TimeONMinus->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_TimeONMinus->setText(QApplication::translate("GUIForm", "-", 0, QApplication::UnicodeUTF8));
    IDC_TimeOFFPlus->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_TimeOFFPlus->setText(QApplication::translate("GUIForm", "+", 0, QApplication::UnicodeUTF8));
    IDC_TimeOFFMinus->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_TimeOFFMinus->setText(QApplication::translate("GUIForm", "-", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowMinus->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_TotalFlowMinus->setText(QApplication::translate("GUIForm", "-", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowPlus->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_TotalFlowPlus->setText(QApplication::translate("GUIForm", "+", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowMinus->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_ExhFlowMinus->setText(QApplication::translate("GUIForm", "-", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowPlus->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_ExhFlowPlus->setText(QApplication::translate("GUIForm", "+", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowMinus2->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_ExhFlowMinus2->setText(QApplication::translate("GUIForm", "-", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowPlus2->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_ExhFlowPlus2->setText(QApplication::translate("GUIForm", "+", 0, QApplication::UnicodeUTF8));
    IDC_O2PercentPlus->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_O2PercentPlus->setText(QApplication::translate("GUIForm", "+", 0, QApplication::UnicodeUTF8));
    IDC_O2PercentMinus->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_O2PercentMinus->setText(QApplication::translate("GUIForm", "-", 0, QApplication::UnicodeUTF8));
    IDC_O2PercentsSteps->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_O2PercentsSteps->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    label_23->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_23->setText(QApplication::translate("GUIForm", "Step:", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowSteps->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_TotalFlowSteps->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowSteps->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowSteps->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowSteps2->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ExhFlowSteps2->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_RunVentilation->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_RunVentilation->setText(QApplication::translate("GUIForm", "&Run Ventilation", 0, QApplication::UnicodeUTF8));
    label_25->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_25->setText(QApplication::translate("GUIForm", "Step:", 0, QApplication::UnicodeUTF8));
    label_26->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_26->setText(QApplication::translate("GUIForm", "Step:", 0, QApplication::UnicodeUTF8));
    label_27->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_27->setText(QApplication::translate("GUIForm", "Step:", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("GUIForm", "PushButton", 0, QApplication::UnicodeUTF8));
    groupBox_5->setTitle(QApplication::translate("GUIForm", "IV Pump", 0, QApplication::UnicodeUTF8));
    label_24->setText(QApplication::translate("GUIForm", "Total Flow:", 0, QApplication::UnicodeUTF8));
    editTotalFlow_7->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    editTotalFlow_7->setText(QApplication::translate("GUIForm", "NaN", 0, QApplication::UnicodeUTF8));
    editTotalFlow_8->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    editTotalFlow_8->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    label_15->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_15->setText(QApplication::translate("GUIForm", "Infusion Rate \n"
"     TCI Target:", 0, QApplication::UnicodeUTF8));
    label_13->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_13->setText(QApplication::translate("GUIForm", "Infused Volume: \n"
"        ml/h", 0, QApplication::UnicodeUTF8));
    label_12->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_12->setText(QApplication::translate("GUIForm", "Drug name:", 0, QApplication::UnicodeUTF8));
    editTotalFlow_9->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    editTotalFlow_9->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    pushButton_7->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    pushButton_7->setText(QApplication::translate("GUIForm", "Start IV Pump", 0, QApplication::UnicodeUTF8));
    groupBox_6->setTitle(QApplication::translate("GUIForm", "VCB Output", 0, QApplication::UnicodeUTF8));
    label_28->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_28->setText(QApplication::translate("GUIForm", "Air DAC", 0, QApplication::UnicodeUTF8));
    label_29->setText(QApplication::translate("GUIForm", "Total Flow:", 0, QApplication::UnicodeUTF8));
    IDC_DitherDAC->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_DitherDAC->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    label_30->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_30->setText(QApplication::translate("GUIForm", "O2 DAC", 0, QApplication::UnicodeUTF8));
    IDC_ExhDAC->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ExhDAC->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_O2DAC->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_O2DAC->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    IDC_AirDAC->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
"   color:  RGB(0, 255, 0);\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_AirDAC->setText(QApplication::translate("GUIForm", "0.0", 0, QApplication::UnicodeUTF8));
    label_31->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_31->setText(QApplication::translate("GUIForm", "Exh DAC", 0, QApplication::UnicodeUTF8));
    label_32->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_32->setText(QApplication::translate("GUIForm", "Dith DAC", 0, QApplication::UnicodeUTF8));
    IDC_AIRVLV_CNTRL->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_AIRVLV_CNTRL->setText(QApplication::translate("GUIForm", "AIRVLV_CNTRL", 0, QApplication::UnicodeUTF8));
    IDC_O2VLV_CNTRL->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_O2VLV_CNTRL->setText(QApplication::translate("GUIForm", "O2VLV_CNTRL", 0, QApplication::UnicodeUTF8));
    IDC_EXHVLV_CNTRL->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_EXHVLV_CNTRL->setText(QApplication::translate("GUIForm", "EXHVLV_CNTRL", 0, QApplication::UnicodeUTF8));
    IDC_SAFE_CLS->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_SAFE_CLS->setText(QApplication::translate("GUIForm", "SAFE_CLS", 0, QApplication::UnicodeUTF8));
    IDC_MNVR_OPEN->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_MNVR_OPEN->setText(QApplication::translate("GUIForm", "MNVR_OPEN", 0, QApplication::UnicodeUTF8));
    IDC_OK_TO_ZERO->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_OK_TO_ZERO->setText(QApplication::translate("GUIForm", "OK_TO_ZERO", 0, QApplication::UnicodeUTF8));
    IDC_FS_PWR_EN->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_FS_PWR_EN->setText(QApplication::translate("GUIForm", "FS_PWR_EN", 0, QApplication::UnicodeUTF8));
    IDC_NEB_ON->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_NEB_ON->setText(QApplication::translate("GUIForm", "NEB_ON", 0, QApplication::UnicodeUTF8));
    IDC_MBUS_RESET->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_MBUS_RESET->setText(QApplication::translate("GUIForm", "MBUS_RESET", 0, QApplication::UnicodeUTF8));
    IDC_ZEROINSP_EN->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ZEROINSP_EN->setText(QApplication::translate("GUIForm", "/ZEROINSPP_EN", 0, QApplication::UnicodeUTF8));
    IDC_ZEROAUXP_EN->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ZEROAUXP_EN->setText(QApplication::translate("GUIForm", "/ZEROAUXP_EN", 0, QApplication::UnicodeUTF8));
    IDC_VC_BUZZER_ON->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_VC_BUZZER_ON->setText(QApplication::translate("GUIForm", "/VC_BUZZER_ON", 0, QApplication::UnicodeUTF8));
    IDC_ILIM_MOD_EN->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ILIM_MOD_EN->setText(QApplication::translate("GUIForm", "ILIM_MOD_EN", 0, QApplication::UnicodeUTF8));
    IDC_ILIM_PSM_EN->setStyleSheet(QApplication::translate("GUIForm", "QCheckBox\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 0px;  \n"
"   border-color: black;\n"
"   font: bold 14px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_ILIM_PSM_EN->setText(QApplication::translate("GUIForm", "ILIM_PSM_EN", 0, QApplication::UnicodeUTF8));
    groupBox_7->setTitle(QApplication::translate("GUIForm", "Serial Port settings", 0, QApplication::UnicodeUTF8));
    label_33->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_33->setText(QApplication::translate("GUIForm", "COM Port", 0, QApplication::UnicodeUTF8));
    IDC_COM_NUMBER->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_COM_NUMBER->setText(QApplication::translate("GUIForm", "1", 0, QApplication::UnicodeUTF8));
    IDC_COM_SPEED->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: gray;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 30px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_COM_SPEED->setText(QApplication::translate("GUIForm", "9600", 0, QApplication::UnicodeUTF8));
    label_34->setStyleSheet(QApplication::translate("GUIForm", "QLabel\n"
" {\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 15px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    label_34->setText(QApplication::translate("GUIForm", "Baudrate", 0, QApplication::UnicodeUTF8));
    IDC_InformBox->setStyleSheet(QApplication::translate("GUIForm", "QLineEdit\n"
" {\n"
"   background-color: white;\n"
"   border-style: outset;\n"
"   border-width: 1px;  \n"
"   border-color: black;\n"
"   font: bold 12px;\n"
" }\n"
"", 0, QApplication::UnicodeUTF8));
    IDC_InformBox->setText(QApplication::translate("GUIForm", "IDC_InformBox", 0, QApplication::UnicodeUTF8));
    IDC_TestBtn->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_TestBtn->setText(QApplication::translate("GUIForm", "Test", 0, QApplication::UnicodeUTF8));
    IDC_Connect_2->setStyleSheet(QApplication::translate("GUIForm", "QPushButton \n"
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
    IDC_Connect_2->setText(QApplication::translate("GUIForm", "C&hange comm port", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(GUIForm);
    } // retranslateUi

};

namespace Ui {
    class GUIForm: public Ui_GUIForm {};
} // namespace Ui

#endif // UI_GUI_EVE_60_H
