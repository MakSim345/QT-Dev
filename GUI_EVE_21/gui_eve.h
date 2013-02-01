#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QtGui/QDialog>
#include "ui_GUI_EVE.h"

#include "gen.h"    // Added by ClassView
#include "iris_if.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MainClass : public QDialog
{
    Q_OBJECT

public:
    MainClass(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~MainClass();

private:
    // Ui::Ui_MainGUI ui;
    Ui_MainGUI ui;


private:    
    int  getComPortSpeed();
    bool OnInitDialog(); 
    void SetVersionInfoTxt(QString str);
    bool m_repeat;
    
    Message *CreateMessage (int msgID);
    Message **IRISmessagePool;
    
private slots:
    void CloseUI();
    
    void OnTimer(UINT nIDEvent);
    void OnDestroy();
    //void OnLButtonDblClk(UINT nFlags, CPoint point);
    //void OnLButtonDown(UINT nFlags, CPoint point);
    
    void OnConnect();    
    void OnSelchangeComSpeed();    
    void OnSendMsg();
    void OnAirvlvCntrl();
    void OnO2vlvCntrl();
    void OnExhvlvCntrl();
    void OnSafeCls();
    void OnSendMsgO2VLV();
    void OnSendMsgExhVLV();
    void OnRunVentilation();    
    void OnTimeONPlus();
    void OnTimeONMinus();
    void OnTimeOFFPlus();
    void OnTimeOFFMinus();
    void OnTotalFlowPlus();
    void OnTotalFlowMinus();
    void OnExhFlowPlus();
    void OnExhFlowMinus();
    void OnO2PercentPlus();
    void OnO2PercentMinus();
    void OnChangeExhFlowSteps2();
    void OnExhFlowMinus2();
    void OnExhFlowPlus2();
    
public:
    
    int UpdateVCBInformation(int MsgId);
    int getComPortNumber();
    //void Send_32_Message (int nCOM);
    void Send_ONOFF_Message (int, int, int);
    void Send_43_Message (int nCOM);
    void Send_44_Message (int nCOM);
    void Send_45_Message (int nCOM);
    void Send_46_Message (int nCOM);
    void CalculateO2Volume();
    void CalculateAirVolume();
    void GasVLvControls(int nONValue);
    int  CheckVal(double nVal);
    
    int g_sComPort;
    int g_nComPortSpeed;
    int    m_DACValue;
    QString    m_GenComInput;
    QString    m_ComInEdit;
    int m_Connected;
    int m_RunVentilation;
    int m_ExhalationFlag;
};

#endif // MAINCLASS_H

