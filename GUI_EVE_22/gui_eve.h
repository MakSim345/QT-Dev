#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <Ice/Ice.h>
#include <arb.h>
#include <icssw.h>
#include <ventc.h>
#include <trace.h>

#include <QtGui/QDialog>
#include "ui_GUI_EVE.h"

#include "gen.h"	// Added by ClassView
#include "eve_main.h"
#include "ifthread.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MainClass : public QDialog
{
	Q_OBJECT
private:
    // Proxy for Session running in Arbitrator
    ARB::SessionPrx _session;
    ICSSW::ComponentPrx _proxy;
    // Proxy for accessing ventilator
    VENTC::VentComponentRWPrx _vent;

	// Ui::Ui_MainGUI ui;
	Ui_MainGUI ui;
	NotifyThread *m_thread;
	//NotifyThread *m_thread2;

public:
	MainClass(QWidget *parent,
              Qt::WFlags flags,
              ARB::SessionPrx s);
	~MainClass();
	
	bool OnInitDialog(); 
	void SetVersionInfoTxt(QString str);

public slots:
	void ObserverMsgLoop();
	
/****/
	int  getBoxComPortSpeed();
	void setBoxComPortSpeed(int);
	
	int  getBoxComPortNumber();
	void setBoxComPortNumber(int);
	
	int  getBoxRecBytes();
	void setBoxRecBytes(int);
	
	int  getBoxSentBytes();
	void setBoxSentBytes(int);
	
	int  getBoxTimeONVal();
	void setBoxTimeONVal(int);
	
	int  getBoxTimeOFFVal();
	void setBoxTimeOFFVal(int);
	
//******************		
   	int  getChkBxAIRVLV_CNTRL();
	void setChkBxAIRVLV_CNTRL(int);

    int  getChkBxEXHVLV_CNTRL();
	void setChkBxEXHVLV_CNTRL(int);

    int  getChkBxFS_PWR_EN();
	void setChkBxFS_PWR_EN(int);

	int  getChkBxILIM_PSM_EN();
	void setChkBxILIM_PSM_EN(int);
	
	int  getChkBxILIM_MOD_EN();
	void setChkBxILIM_MOD_EN(int);

	int  getChkBxMNVR_OPEN();
	void setChkBxMNVR_OPEN(int);

	int  getChkBxO2VLV_CNTRL();
	void setChkBxO2VLV_CNTRL(int);
	
	int  getChkBxOK_TO_ZERO();
	void setChkBxOK_TO_ZERO(int);
	
	int  getChkBxSAFE_CLS();
	void setChkBxSAFE_CLS(int nVal);

	int  getChkBxZERO_AUXP_EN();
	void setChkBxZERO_AUXP_EN(int);
	
	int  getChkBxZEROINSP_EN();
	void setChkBxZEROINSP_EN(int);
	
	int  getChkBxVC_BUZZER_ON();
	void setChkBxVC_BUZZER_ON(int);	
//***********

	void setBoxO2DAC(int);
	int  getBoxO2DAC();
	
	void setBoxO2Percents(int);
	int  getBoxO2Percents();
	
	void setBoxTotalFlowResult(int);
	int  getBoxTotalFlowResult();
		
	void setBoxTotalFlow(int);
	int  getBoxTotalFlow();
	
	void setBoxAirFlow(int);
	int  getBoxAirFlow();
	
	void setBoxAirDAC(int);
	int  getBoxAirDAC();
	
	void setBoxExhFlow(int);
	int  getBoxExhFlow();
	
	void setBoxExhFlow2(int);
	int  getBoxExhFlow2();
	
	void setBoxExhDAC(int);
	int  getBoxExhDAC();
	
	void setBoxDitherDAC(int);
	int  getBoxDitherDAC();
	
	void setBoxOxigFlow(int);
	int  getBoxOxigFlow();
	
	void setBoxOCTemp(string);
	int  getBoxOCTemp(string *);

	void setBoxTCTemp(string);
	int  getBoxTCTemp(string *);
		
	void setBoxACTemp(string);
	int  getBoxACTemp(string *);
	
	void setBoxO2Comp(string);
	int  getBoxO2Comp(string *);
	
	void setBoxCPULoad(string);
	int  getBoxCPULoad(string *);
		
	void enableBtnRunVent(int);
	void enableBtnConnect(int);
	
	void showMessageBox(string sVal);
	
/*****/	
	
private slots:
	void CloseUI();
	
	void OnDestroy();
	
	void OnConnect();		
	void OnAirvlvCntrl();
	void OnO2vlvCntrl();
	void OnExhvlvCntrl();
	void OnSafeCls();
	
	void OnRunVentilation();	
	// Internal GUI buttons clicks:
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
	void OnExhFlowMinus2();
	void OnExhFlowPlus2();
		
	
private:	
	int CheckVal(double nVal);	
	int	m_DACValue;
	QString	m_GenComInput;
	QString	m_ComInEdit;
	int m_Connected;
	int m_RunVentilation;
	int m_ExhalationFlag;
};

#endif // MAINCLASS_H

