@ECHO OFF
REM============================================================
REM
REM Copyright © 2008 GENERAL ELECTRIC COMPANY
REM
REM============================================================

REM http://www.computerhope.com/batch.htm
REM                                             v. 1.0.0                       
REM    Description: Create a Visual Studio 2005 VC++ project.
REM
REM    by Yuriy Senishch. 2008.
REM 
REM                       INFORMATION
REM *****************************************************************
REM qmake - a utility from QT4 for make projects.
REM *****************************************************************
:INIT

REM Set QMAKESPEC
set QMAKESPEC=win32-msvc2005
echo System variable QMAKESPEC = %QMAKESPEC%

goto START 

:START

REM - 1 - run qmake with key "-project" and projectname if necessary:
call qmake -project
REM - 2 - run qmake with key "-t" and "vcapp" for make VC project. 
REM ATTN: the system variable QMAKESPEC must be set up!
call qmake -t vcapp
REM - 3 - commit all changes to project by "qmake" without parametres.
call qmake

goto END

:FAIL
@echo Error occures!
goto END

:SUCCESS
@echo All OK.
goto END

:END
REM call beep.bat
REM calling a utility for show time diff (end):
REM call Tdiff.exe
@echo Complete.
