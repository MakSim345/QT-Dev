#ifndef EVE_MAIN_H
#define EVE_MAIN_H

#include "gen.h"    
#include "iris_if.h"


class EVEMainClass
{
    
public:
    EVEMainClass();
    ~EVEMainClass();

private:
    // Ui::Ui_MainGUI ui;
    // Ui_MainGUI ui;


private:    
    int  getComPortSpeed();
    bool OnInitDialog(); 
    //void SetVersionInfoTxt(CString str);
    bool m_repeat;
    
    Message *CreateMessage (int msgID);
    Message **IRISmessagePool;
    
private:
    
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

    void OnTimer(UINT nIDEvent);
    int UpdateVCBInformation(int MsgId);
    int getComPortNumber();    
    void Send_ONOFF_Message (int, int, int);
    void Send_43_Message (int nCOM);
    void Send_44_Message (int nCOM);
    void Send_45_Message (int nCOM);
    void Send_46_Message (int nCOM);
    void CalculateO2Volume();
    void CalculateAirVolume();
    void GasVLvControls(int nONValue);
    int  CheckVal(double nVal);
    
    void thReadSerialPort(void *dummy );    
            
    int g_sComPort;
    int g_nComPortSpeed;
    int    m_DACValue;
    int m_Connected;
    int m_RunVentilation;
    int m_ExhalationFlag;
    
};

#endif // EVE_MAIN_H

