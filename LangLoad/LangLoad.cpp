#include "LangLoad.h"

LangLoad::LangLoad(QWidget *parent)
     : QWidget(parent)
     , m_ButtonFontSize(15)
     , m_LabelFontSize (20)
     , m_FontName ("Sans Serif")// ("STENCIL") // ("Sans Serif")// ("MONACO")
     , m_FontSize(12)
 {
    timerRebootWait = new QTimer();

    pController = new Controller();

    initMainWindow();
    readConfigFile();
    setConnections();

    updateProgressBar(0);
 }

void LangLoad::initMainWindow()
{
    initLabels();
    initButtons();
    initLayouts();
    tuneMainWindow();
}

void LangLoad::saveConfigFile()
{
    // open file:
    hConfigFile = fopen(configFileName, "w");

    // save FileType (import/export). Currently not in use.
    QString strFileType = fileTypeEdit->currentText();

    if (strFileType.compare("Export") == 0)
    {
        strExport = "--export";
    }
    else
    {
        strExport = "";
    }

    fputs("\nFileType=", hConfigFile);
    fputs(strFileType.toStdString().c_str(), hConfigFile);

    // store the IP:
    QString strIpAddress = ipEdit->text();
    fputs("\nIP=", hConfigFile);
    fputs(strIpAddress.toStdString().c_str(), hConfigFile);

    // store the Monitor type:
    QString strMonitorType = monitorTypeEdit->currentText();
    fputs("\nMonitorType=", hConfigFile);
    fputs(strMonitorType.toStdString().c_str(), hConfigFile);

    fclose(hConfigFile);
}

void LangLoad::readConfigFile()
{
    strncpy(configFileName, "LangLoad.cfg", FILE_NAME_LEN_CONFIG);

    hConfigFile = fopen(configFileName, "r");

    char buf[MAX_LEN];

    while(hConfigFile != NULL && fgets(buf, MAX_LEN, hConfigFile))
    {
        if (strstr(buf, "FileType"))
        {
            char* p1 = strstr(buf, "=")+1;
            char* p2 = strstr(p1, "\n");
            if (p2) *p2 = '\0';
            fileTypeEdit->setCurrentIndex(fileTypeEdit->findText(p1));
        }
        else if (strstr(buf, "MonitorType"))
        {
            char* p1 = strstr(buf, "=")+1;
            char* p2 = strstr(p1, "\n");
            if (p2) *p2 = '\0';
            monitorTypeEdit->setCurrentIndex(monitorTypeEdit->findText(p1));
        }
        else if (strstr(buf, "IP="))
        {
            BYTE bOne, bTwo, bThree, bFour;
            char* p1 = strstr(buf, "=")+1;
            bOne = atoi(p1);
            QString a = QString::number(bOne);

            p1 = strstr(p1, ".")+1;
            bTwo = atoi(p1);
            QString b = QString::number(bTwo);

            p1 = strstr(p1, ".")+1;
            bThree = atoi(p1);
            QString c = QString::number(bThree);

            p1 = strstr(p1, ".")+1;
            bFour = atoi(p1);
            QString d = QString::number(bFour);
            //m_ipControl.SetAddress(bOne, bTwo, bThree, bFour);
            ipEdit->setText(a+"."+b+"."+c+"."+d); //("192.168.1.1");
        }
    }
    if (hConfigFile) fclose(hConfigFile);
}

void LangLoad::initLabels()
{
    fileNameTextLabel = new QLabel("File to load: ");
    fileNameTextLabel->setFont(QFont(m_FontName, m_FontSize));

    fileNameEdit = new QComboBox();
    fileNameEdit->setFont(QFont(m_FontName, m_FontSize));
    fileNameEdit->setMinimumSize(340, 25);

    // get file listing
    char m_strFileFilter[MAX_LEN];
    strcpy(m_strFileFilter, "*.xml");
    struct _finddata_t fd;
    intptr_t hFile = _findfirst(m_strFileFilter, &fd);
    if (hFile != -1)
    {
        fileNameEdit->addItem(fd.name);
        // filenameEdit.SelectString(0, fd.name);
        while ( _findnext(hFile, &fd) == 0)
        {
            fileNameEdit->addItem(fd.name);
        }
    }

    ipEdit = new QLineEdit();
    ipEdit->setFont(QFont(m_FontName, m_FontSize));
    /* Create a string for a regular expression */
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    /* Create a regular expression with a string
     * as a repeating element
     */
    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");
    /* Create a validation regular expression
     * using a regular expression
     */
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
    /* Set Validator on QLineEdit */
    ipEdit->setValidator(ipValidator);
    ipEdit->setMinimumSize(180, 25);
    // ipEdit->setText("192.168.1.1");

    ipTextLabel = new QLabel("IP Address:");
    ipTextLabel->setFont(QFont(m_FontName, m_FontSize));

    monitorTypeTextLabel = new QLabel("Monitor type: ");
    monitorTypeTextLabel->setFont(QFont(m_FontName, m_FontSize));
    // MonitorTypeLabel->setStyleSheet("color: black;");

    fileTypeTextLabel = new QLabel("File Type:");
    fileTypeTextLabel->setFont(QFont(m_FontName, m_FontSize));

    fileTypeEdit = new QComboBox();
    fileTypeEdit->setFont(QFont(m_FontName, m_FontSize));
    fileTypeEdit->setMinimumSize(180, 25);
    fileTypeEdit->addItem("Export");
    fileTypeEdit->addItem("Import");

    outputLngTextLabel = new QLabel("[Output File]:");
    outputLngTextLabel->setFont(QFont(m_FontName, m_FontSize));

    outputLngEdit = new QLineEdit();
    outputLngEdit->setFont(QFont(m_FontName, m_FontSize));
    outputLngEdit->setMinimumSize(180, 25);

    monitorTypeEdit = new QComboBox();
    monitorTypeEdit->setMinimumSize(180, 25);
    monitorTypeEdit->setFont(QFont(m_FontName, m_FontSize));
    monitorTypeEdit->addItem("Max");
    monitorTypeEdit->addItem("Flex");
    monitorTypeEdit->addItem("Lite");
    monitorTypeEdit->addItem("ppd");

    dbgOutputLabel= new QLabel("");
    dbgOutputLabel->setFont(QFont(m_FontName, m_FontSize));
    dbgOutputLabel->setMinimumSize(400, 25);
}

void LangLoad::initButtons()
{
    btnQuit = new QPushButton(STR_BTN_QUIT);
    btnQuit->setMinimumSize(INT_BTN_W, INT_BTN_H);
    btnQuit->setFont(QFont(m_FontName, m_ButtonFontSize));

    btnFixCorruption = new QPushButton(STR_BTN_FIX_CORRUPTION);
    btnEnableWD = new QPushButton(STR_BTN_ENABLE_WD);
    btnRemoveLock = new QPushButton(STR_BTN_REMOVE_LOCK);
    btnTransfer = new QPushButton(STR_BTN_TRANSFER);

    btnFixCorruption->setMinimumSize(INT_BTN_W, INT_BTN_H);
    btnEnableWD->setMinimumSize(INT_BTN_W, INT_BTN_H);
    btnRemoveLock->setMinimumSize(INT_BTN_W, INT_BTN_H);
    btnTransfer->setMinimumSize(INT_BTN_W, INT_BTN_TR_H);

    btnFixCorruption->setFont(QFont(m_FontName, m_ButtonFontSize));
    btnEnableWD->setFont(QFont(m_FontName, m_ButtonFontSize));
    btnRemoveLock->setFont(QFont(m_FontName, m_ButtonFontSize));
    btnTransfer->setFont(QFont(m_FontName, m_ButtonFontSize));
    /*
    btnTransfer->setStyleSheet(
        "background: transparent; border-image: url(://Resources/transfer.png);"
        );
    */
    // btnEnableWD->setEnabled(false);
}

void LangLoad::initLayouts()
{
    prbTransferProgressBar = new QProgressBar();
    prbTransferProgressBar->setMinimumWidth(200);
    prbTransferProgressBar->setRange(0,100);
    prbTransferProgressBar->setValue(40);
    prbTransferProgressBar->setTextVisible(false);

    vLayoutMain = new QVBoxLayout();

    hlayoutTop = new QHBoxLayout();

    hlayoutExitButton = new QHBoxLayout();

    hLayoutBottom = new QHBoxLayout();
    hlayoutIpAddress = new QHBoxLayout();

    hlayoutMonitorType = new QHBoxLayout();
    hlayoutFileType = new QHBoxLayout();
    hLayoutOutputLNGFile = new QHBoxLayout();

    vLayoutButtons = new QVBoxLayout();
    vLayoutLabels = new QVBoxLayout();

    hlayoutTop->addWidget(fileNameTextLabel);
    hlayoutTop->addWidget(fileNameEdit);

    hlayoutIpAddress->addWidget(ipTextLabel);
    hlayoutIpAddress->addStretch();
    hlayoutIpAddress->addWidget(ipEdit);

    hlayoutMonitorType->addWidget(monitorTypeTextLabel);
    hlayoutMonitorType->addStretch();
    hlayoutMonitorType->addWidget(monitorTypeEdit);

    hlayoutFileType->addWidget(fileTypeTextLabel);
    hlayoutFileType->addStretch();
    hlayoutFileType->addWidget(fileTypeEdit);

    hLayoutOutputLNGFile->addWidget(outputLngTextLabel);
    hLayoutOutputLNGFile->addStretch();
    hLayoutOutputLNGFile->addWidget(outputLngEdit);

    vLayoutLabels->addLayout(hlayoutIpAddress);
    vLayoutLabels->addLayout(hlayoutMonitorType);
    vLayoutLabels->addLayout(hlayoutFileType);
    vLayoutLabels->addLayout(hLayoutOutputLNGFile);

    vLayoutButtons->addWidget(btnFixCorruption);
    vLayoutButtons->addWidget(btnEnableWD);
    vLayoutButtons->addWidget(btnRemoveLock);
    vLayoutButtons->addWidget(btnTransfer);

    hLayoutBottom->addLayout(vLayoutLabels);
    hLayoutBottom->addLayout(vLayoutButtons);

    hlayoutExitButton->addWidget(prbTransferProgressBar);
    hlayoutExitButton->addWidget(btnQuit);

    vLayoutMain->addLayout(hlayoutTop);
    vLayoutMain->addLayout(hLayoutBottom);

    vLayoutMain->addLayout(hlayoutExitButton);
    vLayoutMain->addWidget(dbgOutputLabel);

    setLayout(vLayoutMain);
}

QString LangLoad::currentDate()
{
    QDateTime now = QDateTime::currentDateTime();
    return now.date().toString(STR_DATE_FORMAT);
}

void LangLoad::tuneMainWindow()
{
    //set caption:
    setMainWindowTitle(CURRENT_VERSION);
}

void LangLoad::setMainWindowTitle(QString strToShow)
{
    QString strCombine = STR_MAIN_TITLE;
    QString strCompilationTime;
    strCompilationTime.sprintf(". %s, %s", __DATE__, __TIME__);

    strCombine.append(" - ");
    setWindowTitle(strCombine + strToShow + strCompilationTime);
}

void LangLoad::setConnections()
{
    connect(timerRebootWait, SIGNAL(timeout()), this, SLOT(onTimerEvent()));

    connect(btnQuit,  SIGNAL(clicked()), this, SLOT(close()));

    connect(btnEnableWD, SIGNAL(clicked()), SLOT(onEnableWDButton()) );
    connect(btnFixCorruption, SIGNAL(clicked()), SLOT(onFixCorruptionButton()) );
    connect(btnRemoveLock, SIGNAL(clicked()), SLOT(onRemoveLock()) );

    connect(btnTransfer, SIGNAL(clicked()), SLOT(onTransferButton()) );
}

void LangLoad::onRemoveLock()
{
    // performConvertFileToLng();
}

void LangLoad::performConvertFileToLng()
{
    // DEBUG. convert File To LNG:
    if ( convertFileToLNG() )
        updateProgressBar(30);
    else
    {
        showErrorMessageBox();
        cleanInfoWidgets();
        return;
    }
}

void LangLoad::onFixCorruptionButton()
{
    // performResetRemoteESP();
}

void LangLoad::performResetRemoteESP()
{
    // reset Remote ESP:
    if ( resetRemoteESP() )
        updateProgressBar(100);
    else
    {
        showErrorMessageBox();
        cleanInfoWidgets();
        return;
    }
}

void LangLoad::onEnableWDButton()
{
    // performSendLngFileToESP();
}

void LangLoad::performSendLngFileToESP()
{
    // send LNG File To ESP:
    if ( sendLngFileToESP() )
        updateProgressBar(60);
    else
    {
        showErrorMessageBox();
        cleanInfoWidgets();
        return;
    }
}

void LangLoad::onTransferButton()
{
    btnTransfer->setEnabled(false);
    updateProgressBar(0);

    if ( convertFileToLNG() )
        updateProgressBar(30);
    else
    {
        showErrorMessageBox();
        cleanInfoWidgets();
        return;
    }

    if ( sendLngFileToESP() )
        updateProgressBar(60);
    else
    {
        showErrorMessageBox();
        cleanInfoWidgets();
        return;
    }

    if ( resetRemoteESP() )
        updateProgressBar(100);
    else
    {
        showErrorMessageBox();
        cleanInfoWidgets();
        return;
    }

    startTimer();
}

void LangLoad::sentTextToController()
{
    QString strIpAddress = ipEdit->text();
    pController->setIpAddress(strIpAddress);

    QString strMonitorType = monitorTypeEdit->currentText();
    pController->setMonitorType(strMonitorType);

    QString strFileName = fileNameEdit->currentText();
    pController->setInputXmlFileName(strFileName);

    QString strOutputLngName = outputLngEdit->text().toUpper();
    pController->setOutputLngFileName(strOutputLngName);

    pController->setDebugLabel(*dbgOutputLabel);
}

void LangLoad::prepareData()
{
    saveConfigFile();
    sentTextToController();
}

bool LangLoad::convertFileToLNG()
{
    prepareData();
    if (!pController->convertLngFileRemoveExtra())
    {
        return false;
    }

    if (!pController->convertLngFileMakeName())
    {
        return false;
    }

    if ( !pController->doFileNameToTransferV3() )
    {
        return false;
    }
    
    if (!pController->convertLngFile())
    {
        return false;
    }

    return true;
}

bool LangLoad::sendLngFileToESP()
{
    prepareData();

    if ( !pController->transferFileToESP() )
        return false;

    return true;
}

bool LangLoad::resetRemoteESP()
{
    prepareData();

    if ( pController->resetESP() )
        return true;
    else
        return false;
}

void LangLoad::cleanInfoWidgets()
{
    updateProgressBar(0);
    dbgOutputLabel->setText("");
    btnTransfer->setEnabled(true);
}

void LangLoad::updateProgressBar(const int & newValueP)
{
    prbTransferProgressBar->setValue(newValueP);
}

void LangLoad::showErrorMessageBox()
{
    msgBox = new QMessageBox(QMessageBox::Critical, tr("ERROR"), dbgOutputLabel->text() );
    msgBox->setStyleSheet("QLabel{height: 150px; min-height: 150px; max-height: 300px; font: 15pt;}  QPushButton{font: 15pt}");

    //msgBox.setStandardButtons(QMessageBox::Ok);
    //msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox->exec();
    delete msgBox;
}


void LangLoad::startTimer()
{
    timerRebootWait->start( INT_MILLISEC_WAIT_FOR_REBOOT);
}

void LangLoad::stopTimer()
{
    timerRebootWait->stop();
}

void LangLoad::onTimerEvent()
{

    cleanInfoWidgets();
    stopTimer();

    // int tmp_seconds = QTime::currentTime().second();

    /*
    if (tmp_seconds != prev_seconds)
    {
        prev_seconds = QTime::currentTime().second();
        // add handler here.
    }
    */
}

void LangLoad::closeEvent(QCloseEvent* e)
{
    timerRebootWait->stop();
    // INISettingsSave();
}
