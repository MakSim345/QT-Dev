#include "controller.h"

Controller::Controller()
    : _internal_value(0)
    , status(-1)
    , isLngFileNameDefault(true)
    , strTmpFile("tmp.txt")
{

}

bool Controller::transferFileToESP()
{
    char buf[MAX_LEN];
    char m_strTransferCmd[MAX_LEN];

    // COMMAND = python espl10ntool.py --config espl10ntool.conf create-lng -d . %OVERLAY% %FILE_TO_CONVERT%
    // File strInputXmlFile first fixed by fix_xml_file_for_convertion.py script and new file tmp.txt is use for LNG

    // check is result file have a name:
    if (strLngFile.length() <= 0)
    {
        // showErrorMessageBox("Error in creating LNG file!");
        sprintf(buf, "Error in creating LNG file!");
        showMsgOnDbgLabel(QString(buf));
        return false;
    }

    sprintf(m_strTransferCmd, ".\\bin\\scp -S .\\bin\\ssh -o StrictHostKeyChecking=no -i .\\bin\\%s %s root@%s:/usr/share/esp/%s/localization/",
                            strSshKey.toStdString().c_str(),
                            strLngFile.trimmed().toStdString().c_str(),
                            strIpAddress.toStdString().c_str(),
                            strEspType.toStdString().c_str());

    /*
    sprintf(m_strTransferCmd, ".\\bin\\scp %s root@%s:/usr/share/esp/%s/localization/",        
        strLngFile.toStdString().c_str(),
        strIpAddress.toStdString().c_str(),
        strEspType.toStdString().c_str());
        */
    
    showMsgOnDbgLabel("Transferring file");

    status = system(m_strTransferCmd);
    if (status == 0)
    {
        sprintf(buf, "File transferred successfully - OK");
        showMsgOnDbgLabel(QString(buf));
        return true;
    }
    else
    {
        // showErrorMessageBox("Error in transferring LNG file!");
        sprintf(buf, "Error in transferring LNG file!");
        showMsgOnDbgLabel(QString(buf));
        return false;
    }
}

void Controller::showMsgOnDbgLabel(const QString & strMsgP)
{
    infoLabelPtr->setText(strMsgP);
}

bool Controller::resetESP()
{
    char buf[MAX_LEN];
    char m_strResetCmd[MAX_LEN];

    sprintf(m_strResetCmd, ".\\bin\\ssh -o StrictHostKeyChecking=no root@%s systemctl restart esp", strIpAddress.toStdString().c_str());

    showMsgOnDbgLabel("Reboot remote ESP...");

    status = system(m_strResetCmd);
    if (status == 0)
    {
        sprintf(buf, "Shutting down ESP, please wait");
        showMsgOnDbgLabel(QString(buf));
        return true;
    }
    else
    {   
        sprintf(buf, "Error in sending reboot command to ESP!");
        showMsgOnDbgLabel(QString(buf));        
        return false;
    }
}


bool Controller::convertLngFileRemoveExtra()
{
    // Remove <SourceFile> extra tokens from origin file

    // COMMAND = python espl10ntool.py --config espl10ntool.conf create-lng -d . %OVERLAY% %FILE_TO_CONVERT%
    // File strInputXmlFile first fixed by fix_xml_file_for_convertion.py script and new file tmp.txt is use for LNG

    char buf[MAX_LEN];

    char m_strConvertCmd[MAX_LEN];
    char m_strTransferCmd[MAX_LEN];
    
    // QString.sprintf(m_strConvertCmd, "python.exe .\\bin\\fix_xml_file_for_convertion.py %s %s", strInputXmlFile, strTmpFile);
    // QString("python.exe .\\bin\\fix_xml_file_for_convertion.py %s %s").arg(strInputXmlFile, strTmpFile);

    sprintf(m_strConvertCmd, "python.exe .\\bin\\fix_xml_file_for_convertion.py %s %s", strInputXmlFile.toStdString().c_str(), strTmpFile.toStdString().c_str());

    // sprintf(buf, "Converting xml");
    showMsgOnDbgLabel("Converting xml");
    // m_strInfo.fromUtf8(buf);

    status = system(m_strConvertCmd);
    if (status == 0)
    {
        sprintf(buf, "File <%s> created successfully - OK.", strTmpFile.toStdString().c_str());
        showMsgOnDbgLabel(QString(buf));
        return true;
    }
    else
    {
        sprintf(buf, "Error in conversion xml file: step 1");
        showMsgOnDbgLabel(QString(buf));        
        return false;
    }
}

bool Controller::convertLngFile()
{
    char buf[MAX_LEN];    
    char m_strConvertCmd[MAX_LEN];

    // actual conversion:
    if (strEspType.compare("ppd") == 0)
    {
        if (isLngFileNameDefault)
        {
            sprintf(m_strConvertCmd
                    , "python .\\bin\\espl10ntool.py --config .\\bin\\espl10ntool.conf create-lng -d . --overlay PPD %s"
                    , strTmpFile.toStdString().c_str());
        }
        else // output LNG file is defined by user.
        {
            sprintf(m_strConvertCmd
                    , "python .\\bin\\espl10ntool.py --config .\\bin\\espl10ntool.conf create-lng -d . -o %s --overlay PPD %s"
                    , strLngFile.toStdString().c_str()
                    , strTmpFile.toStdString().c_str());
        }
    }
    else // MAX
    {   
        if (isLngFileNameDefault)
            sprintf(m_strConvertCmd
                    , "python .\\bin\\espl10ntool.py --config .\\bin\\espl10ntool.conf create-lng -d . %s"
                    , strTmpFile.toStdString().c_str());
        else // output LNG file is defined by user.
            sprintf(m_strConvertCmd
                    , "python .\\bin\\espl10ntool.py --config .\\bin\\espl10ntool.conf create-lng -d . -o %s %s"
                    , strLngFile.toStdString().c_str()
                    , strTmpFile.toStdString().c_str());
    }

    sprintf(buf, "Create LNG file....");    
    showMsgOnDbgLabel(QString(buf));
    
    status = system(m_strConvertCmd);
    if (status == 0)
    {
        sprintf(buf, "LNG file created successfully - OK.");
        showMsgOnDbgLabel(QString(buf));        
        return true;
    }
    else
    {
        // showErrorMessageBox("Error creating LNG file - step 2");
        sprintf(buf, "Error creating LNG file - step 2");
        showMsgOnDbgLabel(QString(buf));        
        return false;
    }
}

bool Controller::convertLngFileMakeName()
{
    char buf[MAX_LEN];
    char m_strConvertCmd[MAX_LEN];
    
    // write result filename to output.txt:    
    sprintf(m_strConvertCmd, 
            "python .\\bin\\espl10ntool.py --config .\\bin\\espl10ntool.conf print-l10n-file-name %s > .\\output.txt", 
            strInputXmlFile.toStdString().c_str());
    
    status = system(m_strConvertCmd);
    if (status == 0)
    {
        sprintf(buf, "Write LNG name to a log file - OK.");
        showMsgOnDbgLabel(QString(buf));        
        return true;
    }
    else
    {
        // showErrorMessageBox("Error in writing LNG name to a log file - step 3");
        sprintf(buf, "Error in writing LNG name to a log file - step 3");
        showMsgOnDbgLabel(QString(buf));        
        return false;
    }

    if(remove(strTmpFile.toStdString().c_str()) != 0)
        perror( "Error deleting file" );
    else
        puts( "File successfully deleted" );
}

bool Controller::doFileNameToTransferV3()
{   
    // get name for the transferable file.
    // if filename was given by user, use it.
    char buf[MAX_LEN];
    isLngFileNameDefault = true;
        
    if ( strOutputLngFile.length() )    
    {
      if (!strOutputLngFile.contains("."))
        strLngFile = strOutputLngFile + ".LNG";
      else
        strLngFile = strOutputLngFile;

      int pos = strLngFile.indexOf(".LNG");
      
      // const char* p = strstr(strLngFile, ".LNG");
      if (pos == 3)
      {       
          isLngFileNameDefault = false;
          return true;
      }
    }
    else
    {   
        char* line;
        strncpy(outputLogFileName, "output.txt", FILE_NAME_LEN_OUTPUT);
        
        hOutputLogFile = fopen(outputLogFileName, "r");

        if (hOutputLogFile)
        {
            while (line = fgets(buf, MAX_LEN, hOutputLogFile))
            {
                if(strstr(line, ".LNG"))
                {
                    strLngFile = QString(line).trimmed(); // remove new line by trimmed()                
                    break;
                }
            }
            fclose(hOutputLogFile);
            return true;
        }
    }
    sprintf(buf, "Incorrect name of the LNG file!");
    showMsgOnDbgLabel(QString(buf));        
    return false;
}

void Controller::setInputXmlFileName(const QString & strFileNameP)
{
    strInputXmlFile = strFileNameP;
}

void Controller::setOutputLngFileName(const QString & strLngFileNameP)
{
    strOutputLngFile = strLngFileNameP;
}

void Controller::setDebugLabel(QLabel & infoLabelP)
{
    infoLabelPtr = &infoLabelP;
}

void Controller::setMonitorType(const QString & strMonitorTypeP)
{
    if (strMonitorTypeP.compare("Max") == 0)
    {
        strEspType.clear();
        strEspType.append("b850v3");

        strSshKey.clear();
        strSshKey.append("id_rsa");
    }
    else if (strMonitorTypeP.compare("Flex") == 0)
    {
        strEspType.clear();
        strEspType.append("b650v3");

        strSshKey.clear();
        strSshKey.append("id_imm");
    }
    else if (strMonitorTypeP.compare("Lite") == 0)
    {
        strEspType.clear();
        strEspType.append("b450v3");

        strSshKey.clear();
        strSshKey.append("id_dsa");
    }
    else if (strMonitorTypeP.compare("ppd") == 0)
    {
        strEspType.clear();
        strEspType.append("ppd");

        strSshKey.clear();
        strSshKey.append("id_dsa");
    }

    // make the commands

    // CLEAN OUTPUT FILE
    /*
    hConfigFile = fopen(outputLogFileName, "w");
    fclose(hConfigFile);
    */

    /* 
    outputLngEdit
    strOutputLngFile.MakeUpper();
    if (strOutputLngFile.GetLength() > 0 && strOutputLngFile.Find(".") < 0)
    {
        strOutputLngFile += ".LNG";
    }
    const char* p = strstr(strOutputLngFile, ".LNG");
    */   
}
