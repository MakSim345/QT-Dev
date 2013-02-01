@ECHO OFF
REM============================================================
REM
REM Copyright © 2008 GENERAL ELECTRIC COMPANY
REM
REM============================================================

REM http://www.computerhope.com/batch.htm
REM                                             v. 1.0.0                       
REM    Description: remove generated files for make new project under QT4
REM    
REM    by Yuriy Senishch. 2008.
REM 
REM                       INFORMATION
REM *****************************************************************
REM qmake - a utility from QT4 for make projects.
REM *****************************************************************
:INIT

REM Set QMAKESPEC
rem set QMAKESPEC=win32-msvc2005
echo System variable QMAKESPEC = %QMAKESPEC%

REM delete follow files: (*.pdb, *.idb, Makefile*, *.vcproj, *.suo, *.sln, *.ncb )

set PDB=*.pdb
set IDB=*.idb
set MAKEFILE=Makefile*
set VCPROJ=*.vcproj
set SUO=*.suo
set SLN=*.sln
set NCB=*.ncb
set USER=*.user

goto START 

:START

REM - 1 - run qmake with key "-project" and projectname if necessary:
REM call qmake -project
REM - 2 - run qmake with key "-t" and "vcapp" for make VC project. 
REM ATTN: the system variable QMAKESPEC must be set up!
REM call qmake -t vcapp
REM - 3 - commit all changes to project by "qmake" without parametres.
REM call qmake

:PDB_LABEL
If NOT EXIST %PDB% goto IDB_LABEL
del %PDB%

:IDB_LABEL
If NOT EXIST %IDB% goto MAKEFILE_LABEL
del %IDB%

:MAKEFILE_LABEL
If NOT EXIST %MAKEFILE% goto VCPROJ_LABEL
del %MAKEFILE%

:VCPROJ_LABEL
If NOT EXIST %VCPROJ% goto SUO_LABEL
del %VCPROJ%

:SUO_LABEL
If NOT EXIST %SUO% goto SLN_LABEL
del %SUO%

:SLN_LABEL
If NOT EXIST %SLN% goto NCB_LABEL
del %SLN%

:NCB_LABEL
If NOT EXIST %NCB% goto USER_LABEL
del %NCB%

:USER_LABEL
If NOT EXIST %USER% goto END
del %USER%

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
