@echo off
:INIT
REM: no whitespaces in set!!!!
set QT4_UI_FILE=GUI_EVE.ui
set RESULT_H_FILE=ui_GUI_EVE.h
 
echo Converting file %QT4_UI_FILE% to %RESULT_H_FILE%
uic -o %RESULT_H_FILE% %QT4_UI_FILE% 

