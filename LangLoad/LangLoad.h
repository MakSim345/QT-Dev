#pragma once

//============================================================
//
//
//============================================================
//
//
//============================================================
// Description:
//==========================================================
#include <QtGui>

#include "gen.h"
#include "appSettings.h"
#include "Controller.h"

class LangLoad : public QWidget
{
    Q_OBJECT

public:
    LangLoad(QWidget *parent = 0);
    ~LangLoad(){};

    void initMainWindow();
    void initLabels();
    void initButtons();
    void initLayouts();
    void tuneMainWindow();
    void setMainWindowTitle(QString strToShow);
    void setConnections();
    void startTimer();
    void stopTimer();
    
    void closeEvent (QCloseEvent *);
    
    QString currentDate();
    
    void sentTextToController();

    void cleanInfoWidgets();
    void showErrorMessageBox();

public slots:        
    void onTimerEvent();    
    
    void onTransferButton();
    void onRemoveLock();
    void onFixCorruptionButton();
    void onEnableWDButton();
        
private:
    Controller *pController;

    int nCounter;
    int m_ButtonFontSize;
    int m_LabelFontSize;
    
    QString strExport;

    QMessageBox *msgBox;

    QTimer *timerRebootWait;
       
    QIcon m_iconMainWindow;

    QString m_FontName;
    const int m_FontSize;
        
    QPushButton *btnStart;
    QPushButton *btnQuit;
            
    QVBoxLayout *vLayoutMain;

    QVBoxLayout *vLayoutButtons;
    QVBoxLayout *vLayoutLabels;
        
    QHBoxLayout *hlayoutTop;
    QHBoxLayout *hLayoutBottom;
    QHBoxLayout *hlayoutExitButton;

    QHBoxLayout *hlayoutIpAddress;
    QHBoxLayout *hlayoutMonitorType;
    QHBoxLayout *hlayoutFileType;
    QHBoxLayout *hLayoutOutputLNGFile;    
        
    QPushButton *btnFixCorruption;
    QPushButton *btnEnableWD;
    QPushButton *btnRemoveLock;
    QPushButton *btnTransfer;
    QProgressBar *prbTransferProgressBar;
       
    void readConfigFile();
    void saveConfigFile();
    void prepareData();
    
    bool sendLngFileToESP();
    void performSendLngFileToESP();
    
    bool convertFileToLNG();
    void performConvertFileToLng();

    bool resetRemoteESP();
    void performResetRemoteESP();

    void updateProgressBar(const int & newValue);
    
    QLabel *fileNameTextLabel;
    QComboBox *fileNameEdit;

    QLabel *monitorTypeTextLabel;    
    QComboBox *monitorTypeEdit;

    QLabel *fileTypeTextLabel;
    QComboBox *fileTypeEdit;
        
    QLabel *ipTextLabel;
    QLineEdit *ipEdit;

    QLabel *outputLngTextLabel;
    QLineEdit *outputLngEdit;

    QLabel *dbgOutputLabel;
    
    FILE* hConfigFile;
    char configFileName[FILE_NAME_LEN_CONFIG];
};
