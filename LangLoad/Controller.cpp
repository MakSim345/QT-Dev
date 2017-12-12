#include "controller.h"

Controller::Controller()
    : _internal_value(0)
    , status(-1)
    , isLngFileNameDefault(true)
    , strTmpFile("tmp.txt")
{
    strncpy(outputLogFileName, STR_OUTPUT_FILE_NAME, INT_OUTPUT_FILE_NAME_LEN);
}

bool Controller::transferFileToESP()
{
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
    //status = executeProcess(LPCTSTR(m_strTransferCmd), LPCTSTR(outputLogFileName), exitCode, "Transferring file");
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
    sprintf(m_strResetCmd, ".\\bin\\ssh -o StrictHostKeyChecking=no root@%s systemctl restart esp", strIpAddress.toStdString().c_str());

    showMsgOnDbgLabel("Reboot remote ESP...");

    status = system(m_strResetCmd);
    // status = executeProcess(LPCTSTR(m_strResetCmd), LPCTSTR(outputLogFileName), exitCode, "Reboot remote ESP...");
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

    // QString.sprintf(m_strConvertCmd, "python.exe .\\bin\\fix_xml_file_for_convertion.py %s %s", strInputXmlFile, strTmpFile);
    // QString("python.exe .\\bin\\fix_xml_file_for_convertion.py %s %s").arg(strInputXmlFile, strTmpFile);

    sprintf(m_strConvertCmd, "python.exe .\\bin\\fix_xml_file_for_convertion.py %s %s", strInputXmlFile.toStdString().c_str(), strTmpFile.toStdString().c_str());

    // sprintf(buf, "Converting xml");
    showMsgOnDbgLabel("Converting xml");
    
    status = system(m_strConvertCmd);
    //status = executeProcess(LPCTSTR(m_strConvertCmd), LPCTSTR(outputLogFileName), exitCode, "Converting xml.");
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
    
    char okText[] = "ok";
    char failedText[] = "failed";
    
    status = system(m_strConvertCmd);
    //status = executeProcess(LPCWSTR(m_strConvertCmd), LPCWSTR(outputLogFileName), exitCode, buf, okText, failedText);
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
    // write result filename to output.txt:    
    sprintf(m_strConvertCmd, 
            "python.exe .\\bin\\espl10ntool.py --config .\\bin\\espl10ntool.conf print-l10n-file-name %s > .\\%s", 
            strInputXmlFile.toStdString().c_str(),
            STR_OUTPUT_FILE_NAME);
    
    status = system(m_strConvertCmd);    
    // status = executeProcess(LPCTSTR(m_strConvertCmd), LPCTSTR(outputLogFileName), exitCode, "Get output file name");
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
    isLngFileNameDefault = true;
        
    if ( strOutputLngFile.length() )    
    {
      if (!strOutputLngFile.contains("."))
        strLngFile = strOutputLngFile + ".LNG";
      else
        strLngFile = strOutputLngFile;

      int pos = strLngFile.indexOf(".LNG");
            
      if (pos == INT_LNG_LENGHT)
      {       
          isLngFileNameDefault = false;
          return true;
      }
    }
    else
    {   
        char* line;
        
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
}


bool Controller::executeProcess(LPCTSTR processCmdLineP
                              , LPCTSTR outputFileNameP
                              , int& rExitCodeP
                              , char* commentP
                              , char* okP
                              , char* failP
                              , bool bShowP
                              , bool showFailingP)
{
    SECURITY_ATTRIBUTES saAttr;
    HANDLE hSaveStdout;
    HANDLE hChildStdoutRd;
    HANDLE hChildStdoutWr;
    HANDLE hChildStdoutRdDup;
    HANDLE hOutput;
    BOOL fSuccess;
    PROCESS_INFORMATION piProcInfo;
    STARTUPINFO siStartInfo;
    BOOL bFuncRetn = FALSE;
    DWORD dwRead;
    DWORD dwWritten;
    DWORD dwFlags = 0;
    const int BUFSIZE = 1024;
    CHAR chBuf[BUFSIZE];
    bool bres = true;
    
    if (commentP)
    {
        sprintf(chBuf, commentP);
        showMsgOnDbgLabel(QString(chBuf));
    }

    // Set the bInheritHandle flag so pipe handles are inherited.
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;
    // Save current STDOUT handle
    hSaveStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    // Create a pipe for the child process's STDOUT.
    if (CreatePipe(&hChildStdoutRd, &hChildStdoutWr, &saAttr, 0))
    {
        // Set a write handle to the pipe to be STDOUT.
        if (SetStdHandle(STD_OUTPUT_HANDLE, hChildStdoutWr))
        {
            // Create non-inheritable read handle and close the inheritable read handle.
            fSuccess = DuplicateHandle(
                GetCurrentProcess(), hChildStdoutRd,
                GetCurrentProcess(), &hChildStdoutRdDup , 0,
                FALSE,
                DUPLICATE_SAME_ACCESS);
            if(fSuccess)
            {
                CloseHandle(hChildStdoutRd);
                hChildStdoutRd = NULL;
                // Create child process
                ZeroMemory( &piProcInfo, sizeof(PROCESS_INFORMATION) );
                ZeroMemory( &siStartInfo, sizeof(STARTUPINFO) );
                siStartInfo.cb = sizeof(STARTUPINFO);
                siStartInfo.dwFlags = STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
                siStartInfo.hStdOutput = hChildStdoutWr;
                siStartInfo.hStdError = hChildStdoutWr;
                siStartInfo.hStdInput = NULL;
                siStartInfo.wShowWindow = bShowP ? SW_SHOWDEFAULT : SW_HIDE;
                bFuncRetn = CreateProcess(
                    NULL,
                    (LPWSTR)processCmdLineP,  // command line
                    NULL,          // process security attributes
                    NULL,          // primary thread security attributes
                    TRUE,          // handles are inherited
                    dwFlags,       // creation flags
                    NULL,          // use parent's environment
                    NULL,          // use parent's current directory
                    &siStartInfo,  // STARTUPINFO pointer
                    &piProcInfo);  // receives PROCESS_INFORMATION
                if (bFuncRetn)
                {
                    WaitForSingleObject(piProcInfo.hProcess, 10000);
                    if (GetExitCodeProcess(piProcInfo.hProcess, (DWORD*)&rExitCodeP))
                    {
                        // write child process output to file
                        hOutput = CreateFile(
                            outputFileNameP,
                            GENERIC_WRITE,
                            0,
                            NULL,
                            OPEN_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
                        if (hOutput != INVALID_HANDLE_VALUE)
                        {
                            //if (showFailingP==false) // dont show output if not needed
                            //{
                            //    rExitCodeP = 0;
                            //}
                            SetFilePointer(hOutput, 0, 0, FILE_END);
                            if (CloseHandle(hChildStdoutWr))
                            {
                                hChildStdoutWr = NULL;
                                for (;;)
                                {
                                    if (!ReadFile(hChildStdoutRdDup, chBuf, BUFSIZE, &dwRead, NULL) || dwRead == 0)
                                    {
                                        break;
                                    }
                                    if (!WriteFile(hOutput, chBuf, dwRead, &dwWritten, NULL))
                                    {
                                        break;
                                    }
                                }
                            }
                        }
                        else
                        {
                            bres = false;
                        }
                    }
                    else
                    {
                        bres = false;
                    }
                }
                else
                {
                    bres = false;
                }
            }
            else
            {
                bres = false;
            }
        }
        else
        {
            bres = false;
        }
    }
    else
    {
        bres = false;
    }

    if (hOutput != INVALID_HANDLE_VALUE)
    {
        if (bres && (rExitCodeP == 0 /*|| showFailingP*/) && commentP && okP)
        {
            sprintf(chBuf, "INFO - %s... %s\n", commentP, okP);
            WriteFile(hOutput, chBuf, strlen(chBuf), &dwWritten, NULL);
        }
        else if(commentP && failP)
        {
            sprintf(chBuf, "INFO - %s... %s\n", commentP, failP);
            WriteFile(hOutput, chBuf, strlen(chBuf), &dwWritten, NULL);
        }
    }
    // Clean up
    CloseHandle(piProcInfo.hProcess);
    CloseHandle(piProcInfo.hThread);
    CloseHandle(hOutput);
    CloseHandle(hChildStdoutRdDup);
    if (hChildStdoutRd)
    {
        CloseHandle(hChildStdoutRd);
    }
    if (hChildStdoutWr)
    {
        CloseHandle(hChildStdoutWr);
    }

    return (bres && (rExitCodeP == 0 || showFailingP));
}


int Controller::windowsSystem(const char *cmd)
{    
    /*
    PROCESS_INFORMATION p_info;
    STARTUPINFO s_info;
    LPSTR cmdline, programpath;
    
    memset(&s_info, 0, sizeof(s_info));
    memset(&p_info, 0, sizeof(p_info));
    s_info.cb = sizeof(s_info);

    cmdline     = (LPSTR)cmd);

    if (CreateProcess(NULL, cmdline, NULL, NULL, 0, 0, NULL, NULL, &s_info, &p_info))
    {
        WaitForSingleObject(p_info.hProcess, INFINITE);
        CloseHandle(p_info.hProcess);
        CloseHandle(p_info.hThread);
    }
    */
    
    return 0;
}
