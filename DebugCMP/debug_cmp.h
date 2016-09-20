#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QDialog>
#include "ui_DebugCMP.h"
#include "mythread.h"

#define VERSION "0.0.1"

#define EVE 1001
#define GUI 1002
#define GDU 1003
#define ARB 1004

#define REDLED 2001
#define GRNLED 2002

class DebugCMP : public QDialog
{
	Q_OBJECT

public:
	DebugCMP(QWidget *parent = 0);
	~DebugCMP();
	
	// ICE Interface:
	void printDebugMessage(int nSource, std::string strMsg);
	void printErrorMessage(int nSource, std::string strMsg);
	void printLogMessage(int nSource, std::string strMsg);

private:
	// Ui::Ui_MainGUI ui;
	Ui_DebugCMP ui;
	MyThread m_threadEVE;
	MyThread m_threadGUI;
	QIcon *m_GrnIcon;
	QIcon *m_RedIcon;
	void setVersionInfoTxt(QString);
	
	void setMinimumSizeIDC_VER();
	void setMinimumSizeEXIT_BTN();
	void setMinimumSizeTAB();
	
	void setLedOnTab(int nDest, int nColor);
	
	void InitDialog();
	void initTabs();
    
private slots:
	void CloseUI();
	void setBiggerSize();
	void setSmallerSize();
	void startThreadEVE();
	void startThreadGUI();
	void readEVEMessage(QString str);
	void readGUIMessage(QString str);
};

#endif // MAINCLASS_H
