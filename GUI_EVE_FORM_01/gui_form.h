#ifndef _GUI_FORM_H_
#define _GUI_FORM_H_

#include "gen.h"	// Added by ClassView
#include "ui_GUI_EVE_60.h"

class BelowsPrg : public QFrame
{
 	 Q_OBJECT
 	 	 
 protected:
    int m_nProgress;
    int m_nMaxProgressValue;
    virtual void paintEvent(QPaintEvent*);
 
 	 		
 public:
     BelowsPrg(QWidget *parent = 0);
     virtual QSize sizeHint() const;
     
 signals:
 	 void progressChanged(int N);
 
 public slots:
 	 void slotSetProgress(int N);
};


class GUIForm : public QDialog
{
     Q_OBJECT

 public:
     GUIForm(QWidget *parent = 0);
     BelowsPrg *BelowsProgress;
     
 private:
    int m_vent;
    int m_nShowVwntPrgs;    
    int CheckVal(double);
    void SetVersionInfoTxt(QString str);
    bool OnInitDialog();
    void showMessageBox(std::string sVal);

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
	
	int  getBoxO2PercentsSteps();
	void setBoxO2PercentsSteps(int);
	
	int  getBoxTotalFlowSteps();
	void setBoxTotalFlowSteps(int);
	
	int  getBoxExhFlowSteps();
	void setBoxExhFlowSteps(int);
	
	int  getBoxExhFlowSteps2();
	void setBoxExhFlowSteps2(int);
	
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
	
     
 private slots:
    void slotSetProgress();
    void OnDestroy();
	
	void OnConnect();		
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
     Ui::GUIForm ui;
 };
 #endif