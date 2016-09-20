#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QDialog>
#include "ui_SMSEdit.h"
#include "LogServ.h"
#include "RegIf.h"

class SMSEditForm : public QDialog
{
	Q_OBJECT

public:
	SMSEditForm(QWidget *parent = 0);
	~SMSEditForm();

private:
	// Ui::Ui_MainGUI ui;	
	int OnInitDialog();
	CTRACE *t;
	RegIf Reg;
	Ui_SMSEditForm ui;
	
private slots:
	void CloseUI();
	
	void OnExitPress();
	void OnClearText();
	void OnCopyToBuffer();
	void OnChangeEdit1();
	
	QString GetEditBoxTxt();
	void SetEditBoxTxt(QString str);
		
	void SetLimitBoxTxt(QString str);
	int  GetLimitBoxTxt();
	
	void SetCounterBoxTxt(QString str);
	int  GetCounterBoxTxt();
	
	void SetVersionInfoTxt(QString str);
	
	
};

#endif // MAINCLASS_H
