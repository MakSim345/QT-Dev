#include "eve_main.h"

#include "gen.h"
#include "utils.h"

#ifdef YS_TEST_16JUNE2008

EVEMainClass::EVEMainClass()
{
	   
}

EVEMainClass::~EVEMainClass()
{

}

// Follow is an interface between GUI and EVE Core.
// 
void EVEMainClass::OnDestroy() {}
void EVEMainClass::OnConnect() {}
void EVEMainClass::OnAirvlvCntrl() {}
void EVEMainClass::OnO2vlvCntrl() {}
void EVEMainClass::OnExhvlvCntrl() {}
void EVEMainClass::OnSafeCls() {}
void EVEMainClass::OnSendMsgO2VLV() {}
void EVEMainClass::OnSendMsgExhVLV() {}
void EVEMainClass::OnRunVentilation() {}
void EVEMainClass::Send_ONOFF_Message(int, int, int) { }
void EVEMainClass::GasVLVControls(int) {}

//void EVEMainClass::ObserverMsgLoop(DynBuff*){}
//int  EVEMainClass::NotifyMsgHandler(DynBuff*) {return 0;}     
int  EVEMainClass::getMsgFromStore(void) {return 10001;}
int  EVEMainClass::isEmpty(){return 1;}

void EVEMainClass::setComPortSpeed(int, int){}
int  EVEMainClass::getComPortSpeed(){return 0;}
    
void EVEMainClass::setComPortNumber(int, int) {}
int  EVEMainClass::getComPortNumber(){return 0;}

void EVEMainClass::setRecBytes(int, int) {}
int  EVEMainClass::getRecBytes(){return 0;}
	
void EVEMainClass::setSentBytes(int, int) {}
int  EVEMainClass::getSentBytes(){return 0;}

void EVEMainClass::setTimeONVal(int, int) {}
int  EVEMainClass::getTimeONVal(){return 0;}
	
void EVEMainClass::setTimeOFFVal(int, int) {}
int  EVEMainClass::getTimeOFFVal(){return 0;}
	
//******************		
void EVEMainClass::setChkBxAIRVLV_CNTRL(int, int) {}
int  EVEMainClass::getChkBxAIRVLV_CNTRL(){return 0;}

void EVEMainClass::setChkBxEXHVLV_CNTRL(int, int) {}
int  EVEMainClass::getChkBxEXHVLV_CNTRL(){return 0;}

void EVEMainClass::setChkBxFS_PWR_EN(int, int) {}
int  EVEMainClass::getChkBxFS_PWR_EN(){return 0;}

void EVEMainClass::setChkBxILIM_PSM_EN(int, int) {}
int  EVEMainClass::getChkBxILIM_PSM_EN(){return 0;}
	
void EVEMainClass::setChkBxILIM_MOD_EN(int, int) {}
int  EVEMainClass::getChkBxILIM_MOD_EN(){return 0;}

void EVEMainClass::setChkBxMNVR_OPEN(int, int) {}
int  EVEMainClass::getChkBxMNVR_OPEN(){return 0;}
	
void EVEMainClass::setChkBxO2VLV_CNTRL(int, int) {}
int  EVEMainClass::getChkBxO2VLV_CNTRL(){return 0;}
	
void EVEMainClass::setChkBxOK_TO_ZERO(int, int) {}
int  EVEMainClass::getChkBxOK_TO_ZERO(){return 0;}
	
void EVEMainClass::setChkBxSAFE_CLS(int, int) {}
int  EVEMainClass::getChkBxSAFE_CLS(){return 0;}
	
void EVEMainClass::setChkBxZERO_AUXP_EN(int, int) {}
int  EVEMainClass::getChkBxZERO_AUXP_EN(){return 0;}
	
void EVEMainClass::setChkBxZEROINSP_EN(int, int) {}
int  EVEMainClass::getChkBxZEROINSP_EN(){return 0;}
	
void EVEMainClass::setChkBxVC_BUZZER_ON(int, int) {}	
int  EVEMainClass::getChkBxVC_BUZZER_ON(){return 0;}
//***********

void EVEMainClass::setO2DAC(int, int){}
int  EVEMainClass::getO2DAC(){return 0;}
	
void EVEMainClass::setO2Percents(int, int){}
int  EVEMainClass::getO2Percents(){return 0;}
	
void EVEMainClass::setTotalFlowResult(int, int){}
int  EVEMainClass::getTotalFlowResult(){return 0;}
		
void EVEMainClass::setTotalFlow(int, int){}
int  EVEMainClass::getTotalFlow(){return 0;}
	
void EVEMainClass::setAirFlow(int, int){}
int  EVEMainClass::getAirFlow(){return 0;}
	
void EVEMainClass::setAirDAC(int, int){}
int  EVEMainClass::getAirDAC(){return 0;}
	
void EVEMainClass::setExhalFlow(int, int){}
int  EVEMainClass::getExhalFlow(){return 0;}
	
void EVEMainClass::setExhalFlow2(int, int){}
int  EVEMainClass::getExhalFlow2(){return 0;}
	
void EVEMainClass::setExhDAC(int, int){}
int  EVEMainClass::getExhDAC(){return 0;}
	
void EVEMainClass::setDitherDAC(int, int){}
int  EVEMainClass::getDitherDAC(){return 0;}
	
void EVEMainClass::setOxigFlow(int, int){}
int  EVEMainClass::getOxigFlow(){return 0;}
	
void EVEMainClass::setOCTemp(string, int){}
int  EVEMainClass::getOCTemp(string *){return 0;}

void EVEMainClass::setTCTemp(string, int){}
int  EVEMainClass::getTCTemp(string *){return 0;}
		
void EVEMainClass::setACTemp(string, int){}
int  EVEMainClass::getACTemp(string *){return 0;}
	
void EVEMainClass::setO2Comp(string, int){}
int  EVEMainClass::getO2Comp(string *){return 0;}
	
void EVEMainClass::setCPULoad(string, int){}
int  EVEMainClass::getCPULoad(string *){return 0;}
		
void EVEMainClass::enableBtnRunVent(int){}
void EVEMainClass::enableBtnConnect(int){}
    
void EVEMainClass::setBtnRunVentTxt(const string &){}
void EVEMainClass::setBtnConnectTxt(const string &){}

void EVEMainClass::showMessageBox(string){}


#endif // #ifdef YS_TEST_16JUNE2008