#pragma once

#include "gen.h"

class Controller
{
public:
    Controller();

    bool transferFileToESP();
    bool resetESP();

    bool convertLngFileRemoveExtra();
    bool convertLngFile();
    bool convertLngFileMakeName();

    bool doFileNameToTransferV3();

    void setIpAddress(QString ipAddressP) {this->strIpAddress = ipAddressP;}
    void setMonitorType(const QString & strMonitorTypeP);
    void setInputXmlFileName(const QString & strFileNameP);
    void setOutputLngFileName(const QString & strLngFileNameP);

    void setDebugLabel(QLabel &infoLabelP);
    void showMsgOnDbgLabel(const QString & str);    

    int systemNoOutput(std::string strCommandP);
    
private:
    
    int statusExeCmd;
    QString strTmpFile;
    QString strEspType;
    QString strSshKey;
    QString strLngFile;
    QString strIpAddress;
    QString strInputXmlFile;
    QString strOutputLngFile;

    QMessageBox msgBox;
    QLabel *infoLabelPtr;

    char outputLogFileName[INT_OUTPUT_FILE_NAME_LEN];
    // LPCWSTR m_strConvertCmd;//[MAX_LEN];
    char m_strConvertCmd[MAX_LEN];
    char m_strTransferCmd[MAX_LEN];
    char m_strResetEspCmd[MAX_LEN];
    char buf[MAX_LEN];

    FILE* hOutputLogFile;

    bool isLngFileNameDefault;
    int exitCode;
};
