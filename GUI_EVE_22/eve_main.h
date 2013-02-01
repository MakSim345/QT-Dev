#ifndef EVE_MAIN_H
#define EVE_MAIN_H

#include "gen.h"	

#define DISPL_IN_GUI 1
#define NOT_DISPL_IN_GUI 0

#define MSGID_NOT_IMPLEMENTED     10000
#define MSGID_SET_COM_PORT_SPEED  10001
#define MSGID_SET_COM_PORT_NUMBER 10002
#define MSGID_SET_REC_BYTES       10003
#define MSGID_SET_SENT_BYTES      10004
#define MSGID_SET_TIME_OFF_VAL    10005
#define MSGID_SET_EXHVLV_CNTRL    10006
#define MSGID_SET_AIRVLV_CNTRL    10007
#define MSGID_SET_MNVR_OPEN       10008
#define MSGID_SET_OK_TO_ZERO      10009

#define MSGID_SET_ILIM_MOD_EN     10010
#define MSGID_SET_ZERO_AUXP_EN    10011
#define MSGID_SET_ZEROINSP_EN     10012
#define MSGID_SET_VC_BUZZER_ON    10013
#define MSGID_SET_FS_PWR_EN       10014
#define MSGID_SET_O2DAC           10015
#define MSGID_SET_O2PERCENTS      10016
#define MSGID_SET_TOTAL_FLOW_RES  10017
#define MSGID_SET_TOTAL_FLOW      10018
#define MSGID_SET_AIRDAC          10019

#define MSGID_SET_EXHAL_FLOW      10020
#define MSGID_SET_EXHAL_FLOW2     10021
#define MSGID_SET_EXHDAC          10022
#define MSGID_SET_DITHER_DAC      10023
#define MSGID_SET_AIR_FLOW        10024
#define MSGID_SET_OXIG_FLOW       10025
#define MSGID_SET_TIME_ON_VAL     10026
/*
#define MSGID_ENB_BTN_RUNVENT     10026
#define MSGID_ENB_BTN_CONNECT     10027

#define MSGID_SET_COM_PORT_NUMBER 10028
#define MSGID_SET_COM_PORT_NUMBER 10029

#define MSGID_SET_COM_PORT_NUMBER 10030
#define MSGID_SET_COM_PORT_NUMBER 10031
#define MSGID_SET_COM_PORT_NUMBER 10032
#define MSGID_SET_COM_PORT_NUMBER 10033
#define MSGID_SET_COM_PORT_NUMBER 10034
#define MSGID_SET_COM_PORT_NUMBER 10035
#define MSGID_SET_COM_PORT_NUMBER 10036
#define MSGID_SET_COM_PORT_NUMBER 10037
#define MSGID_SET_COM_PORT_NUMBER 10038
#define MSGID_SET_COM_PORT_NUMBER 10039

#define MSGID_SET_COM_PORT_NUMBER 10040
#define MSGID_SET_COM_PORT_NUMBER 10041
#define MSGID_SET_COM_PORT_NUMBER 10042
#define MSGID_SET_COM_PORT_NUMBER 10043
#define MSGID_SET_COM_PORT_NUMBER 10044
#define MSGID_SET_COM_PORT_NUMBER 10045
#define MSGID_SET_COM_PORT_NUMBER 10046
#define MSGID_SET_COM_PORT_NUMBER 10047
#define MSGID_SET_COM_PORT_NUMBER 10048
#define MSGID_SET_COM_PORT_NUMBER 10049

#define MSGID_SET_COM_PORT_NUMBER 10050
#define MSGID_SET_COM_PORT_NUMBER 10051
#define MSGID_SET_COM_PORT_NUMBER 10052
#define MSGID_SET_COM_PORT_NUMBER 10053
#define MSGID_SET_COM_PORT_NUMBER 10054
#define MSGID_SET_COM_PORT_NUMBER 10055
#define MSGID_SET_COM_PORT_NUMBER 10056
#define MSGID_SET_COM_PORT_NUMBER 10057
#define MSGID_SET_COM_PORT_NUMBER 10058
#define MSGID_SET_COM_PORT_NUMBER 10059
*/

#define MSGID_ENB_BTN_RUNVENT     10060
#define MSGID_ENB_BTN_CONNECT     10061

#ifdef YS_TEST_16JUNE2008

class EVEMainClass
{
	
public:
	EVEMainClass();
	~EVEMainClass();
	
public:

    void OnDestroy();
   	
    void OnSendMsg();
    void OnAirvlvCntrl();
    void OnO2vlvCntrl();
    void OnExhvlvCntrl();
    void OnSafeCls();
    void OnSendMsgO2VLV();
    void OnSendMsgExhVLV();
    void OnRunVentilation();
    void OnTimer(UINT nIDEvent);
     	
    void Send_ONOFF_Message (int, int, int);
    void Send_43_Message (int nCOM);
    void Send_44_Message (int nCOM);
    void Send_45_Message (int nCOM);
    void Send_46_Message (int nCOM);
      
    void CalculateO2Volume();
    void CalculateAirVolume();
    void GasVLVControls(int nONValue);
        
//*************INTERFACE TO GUI*****************  
    void OnConnect();
 
    int  isEmpty(void);
    int  getMsgFromStore(void);
   
    void setComPortSpeed(int nComPortSpeed, int nDisplayOnGUI);
    int  getComPortSpeed();
    
    void setComPortNumber(int nComPortNumber, int nDisplayOnGUI);
    int  getComPortNumber();
	
    void setRecBytes(int nRecBytes, int nDisplayOnGUI);
    int  getRecBytes();
	
    void setSentBytes(int nSentBytes, int nDisplayOnGUI);
    int  getSentBytes();
	
    void setTimeONVal(int nTimeONVal, int nDisplayOnGUI);
    int  getTimeONVal();
	
    void setTimeOFFVal(int nTimeOFFVal, int nDisplayOnGUI);
    int  getTimeOFFVal();
	
//******************		
    void setChkBxAIRVLV_CNTRL(int nChecked, int nDisplayOnGUI);
    int  getChkBxAIRVLV_CNTRL();

    void setChkBxEXHVLV_CNTRL(int nChecked, int nDisplayOnGUI);
    int  getChkBxEXHVLV_CNTRL();

    void setChkBxFS_PWR_EN(int nChecked, int nDisplayOnGUI);
    int  getChkBxFS_PWR_EN();	

    void setChkBxILIM_PSM_EN(int nChecked, int nDisplayOnGUI);
    int  getChkBxILIM_PSM_EN();
	
    void setChkBxILIM_MOD_EN(int nChecked, int nDisplayOnGUI);
    int  getChkBxILIM_MOD_EN();

    void setChkBxMNVR_OPEN(int nChecked, int nDisplayOnGUI);
    int  getChkBxMNVR_OPEN();
	
    void setChkBxO2VLV_CNTRL(int nChecked, int nDisplayOnGUI);
    int  getChkBxO2VLV_CNTRL();
	
    void setChkBxOK_TO_ZERO(int nChecked, int nDisplayOnGUI);
    int  getChkBxOK_TO_ZERO();
	
    void setChkBxSAFE_CLS(int nChecked, int nDisplayOnGUI);
    int  getChkBxSAFE_CLS();
	
    void setChkBxZERO_AUXP_EN(int nChecked, int nDisplayOnGUI);
    int  getChkBxZERO_AUXP_EN();
	
    void setChkBxZEROINSP_EN(int nChecked, int nDisplayOnGUI);
    int  getChkBxZEROINSP_EN();
	
    void setChkBxVC_BUZZER_ON(int nChecked, int nDisplayOnGUI);	
    int  getChkBxVC_BUZZER_ON();
//***********

    void setO2DAC(int nBoxO2DAC, int nDisplayOnGUI);
    int  getO2DAC();
	
    void setO2Percents(int nBoxO2Percents, int nDisplayOnGUI);
    int  getO2Percents();
	
    void setTotalFlowResult(int nBoxTotalFlowResult, int nDisplayOnGUI);
    int  getTotalFlowResult();
		
    void setTotalFlow(int nBoxTotalFlow, int nDisplayOnGUI);
    int  getTotalFlow();
	
    void setAirFlow(int nBoxAirFlow, int nDisplayOnGUI);
    int  getAirFlow();
	
    void setAirDAC(int nBoxAirDAC, int nDisplayOnGUI);
    int  getAirDAC();
	
    void setExhalFlow(int nBoxExhalFlow, int nDisplayOnGUI);
    int  getExhalFlow();
	
    void setExhalFlow2(int nBoxExhalFlow2, int nDisplayOnGUI);
    int  getExhalFlow2();
	
    void setExhDAC(int nBoxExhDAC, int nDisplayOnGUI);
    int  getExhDAC();
	
    void setDitherDAC(int nBoxDitherDAC, int nDisplayOnGUI);
    int  getDitherDAC();
	
    void setOxigFlow(int nBoxOxigFlow, int nDisplayOnGUI);
    int  getOxigFlow();
	
    void setOCTemp(string sBoxOCTemp, int nDisplayOnGUI);
    int  getOCTemp(string * sRetVal);

    void setTCTemp(string sBoxTCTemp, int nDisplayOnGUI);
    int  getTCTemp(string * sRetVal);
		
    void setACTemp(string sBoxACTemp, int nDisplayOnGUI);
    int  getACTemp(string * sRetVal);
	
    void setO2Comp(string sBoxO2Comp, int nDisplayOnGUI);
    int  getO2Comp(string * sRetVal);
	
    void setCPULoad(string sBoxCPULoad, int nDisplayOnGUI);
    int  getCPULoad(string * sRetVal);
		
    void enableBtnRunVent(int nEnable);
    void enableBtnConnect(int nEnable);
    
    void setBtnRunVentTxt(const string& sTextToBtn);
    void setBtnConnectTxt(const string& sTextToBtn);

    void showMessageBox(string sMessage);

};

#endif // #ifdef YS_TEST_16JUNE2008

#endif // EVE_MAIN_H

