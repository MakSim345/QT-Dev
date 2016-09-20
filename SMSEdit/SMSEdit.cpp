#include <QtGui>
#include "SMSEdit.h"

#include "gen.h"
#include "LogServ.h" 


SMSEditForm::SMSEditForm(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	
	connect(ui.ID_CLEAR_TEXT, SIGNAL(clicked()), this, SLOT(OnClearText()) );
	connect(ui.ID_COPY_TO_BUFFER, SIGNAL(clicked()), this, SLOT(OnCopyToBuffer()) );
	connect(ui.IDC_EDIT1, SIGNAL(textChanged()), this, SLOT(OnChangeEdit1()));
	
	connect(ui.ID_EXIT_BUTTON, SIGNAL(clicked()), this, SLOT(OnExitPress()));
	
	/*
	connect(ui.IDOK, SIGNAL(clicked()), this, SLOT(OnExitPress()));
	connect(ui.ID_CLEAR_TEXT, SIGNAL(clicked()), this, SLOT(OnClearText()) );
	connect(ui.ID_COPY_TO_BUFFER, SIGNAL(clicked()), this, SLOT(OnCopyToBuffer()) );
	// connect(ui.IDOK, SIGNAL(clicked()), this, SLOT(OnExitPress()));
	connect(ui.IDC_EDIT1, SIGNAL(textChanged()), this, SLOT(OnChangeEdit1()));
	// ui.IDC_EDIT1->textChanged
	*/
	OnInitDialog();
	
	//connect(ui.pbStartVent, SIGNAL(clicked()), this, SLOT(CloseUI()));
}

SMSEditForm::~SMSEditForm()
{

}


void SMSEditForm::CloseUI()
{
 // quit();
 // QMessageBox::warning(this, "TEST", "Want to close application?");
 close();
 //ui.editTotalFlow->setText(QString::number(i++)); 
}

int SMSEditForm::OnInitDialog()
{
	QString str;
	TCHAR szSubkey[256];  
	// LPWSTR szSubkey; //[256];
	int nRegMaxLimit = MAX_LIMIT;

	t = new CTRACE(1,0, "SMS-Edit.log");
	   
	str.sprintf("Ver: %s. Compiled: %s %s", VERSION, __DATE__, __TIME__);
	SetVersionInfoTxt(str);

	// Read Registry and set necessary settingse from there:
	/*
	lstrcpy (szSubkey, "Software\\SMSEdit\\Settings");	
	Reg.ReadIniDword(&nRegMaxLimit, szSubkey, "MaxLimit");
	*/	
	SetLimitBoxTxt(QString::number(nRegMaxLimit) );
	SetCounterBoxTxt(QString::number(0) );
	SetEditBoxTxt("");

	return TRUE;
}

void SMSEditForm::SetVersionInfoTxt(QString str)
{
 ui.IDC_VERSION_INFO->setText(str);
}


void SMSEditForm::SetLimitBoxTxt(QString str)
{
 ui.ID_LimitBox->setText(str);
}

void SMSEditForm::SetCounterBoxTxt(QString str)
{
 ui.ID_CounterBox->setText(str);
}

void SMSEditForm::OnChangeEdit1() 
{
	
	int nMaxVal = 0;	
	int nStrCtr = 0;
	QString str;
  
	str = GetEditBoxTxt();
	nStrCtr = str.length();
	
	SetCounterBoxTxt(QString::number(nStrCtr) );
	
	// nMaxVal = GetDlgItemInt(IDC_LimitBox, NULL, 1);	
	nMaxVal = GetLimitBoxTxt();
	
	if (nMaxVal < nStrCtr)
	{
		// Beep();
		//MessageBeep(2);	
	}
}


QString SMSEditForm::GetEditBoxTxt()
{
  return ui.IDC_EDIT1->toPlainText();
}

void SMSEditForm::SetEditBoxTxt(QString str)
{
  ui.IDC_EDIT1->setText(str); 
}

int SMSEditForm::GetCounterBoxTxt()
{
  ui.IDC_EDIT1->toPlainText().toInt();
  return 0;
}

int SMSEditForm::GetLimitBoxTxt()
{
  return 0;
}

void SMSEditForm::OnCopyToBuffer() 
{
			
	QString str;
	char * buffer;

	str = GetEditBoxTxt();	
	
  /*    
  if((OpenClipboard())
	{
	 HGLOBAL clipbuffer;	 
	 EmptyClipboard();
	 clipbuffer = GlobalAlloc(GMEM_DDESHARE, str.GetLength()+1);
	 buffer = (char*)GlobalLock(clipbuffer);
	 strcpy(buffer, LPCSTR(str));
	 GlobalUnlock(clipbuffer);
	 SetClipboardData(CF_TEXT,clipbuffer);
	 CloseClipboard();
	}
 
	 // also copy text to a log file:
	 
	 t->TIMESTAMP(0); 
	 t->TRACEY("["); 
	 t->TRACEY(buffer, "]\n"); 
	*/ 
}

void SMSEditForm::OnClearText() 
{
	SetEditBoxTxt("");
	SetCounterBoxTxt(QString::number(0) );
}

void SMSEditForm::OnExitPress() 
{
	// TCHAR szSubkey[256];
	char szSubkey[256];
	int nRegMaxLimit=1;
		
//**************************Registry*******
	// Write settings to the Registry:
	// lstrcpy (szSubkey, "Software\\SMSEdit\\Settings");

	nRegMaxLimit = GetLimitBoxTxt();
	//= m_pComBoxPortNum->GetCurSel();
				
	// Reg.WriteIniDword(&nRegMaxLimit, szSubkey, "MaxLimit");	
//*****************************************
	// delete t;
	CloseUI();
}
