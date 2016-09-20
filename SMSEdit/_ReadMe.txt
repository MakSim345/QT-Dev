10:41 19-MAR-2008

D:\dev\QT-Dev\GUI_Run002

This project was create for testing GIUI for EVE.

1. Create the "main.cpp" file.
2. Create the "SMSEdit.ui" in the QT4 Designer.
3. Convert "SMSEdit.ui" with uic.exe application.
       uic -o %RESULT_H_FILE% %QT4_UI_FILE% 
4. Run qmake -project
5. Run qmake -t vcapp
6. Run qmake
7. Open the *.vcproj file.
8. When VC2005 ask about converting - answer yes.
9. Press "Build". The VC2005 will ask about save project *.sln file. Press "save".
10.Done. 


10:54 26-MAR-2008

Solutions: 
1. After I add #include <windows.h> all WIN API are avaliable.

Problems:
1. OpenClipboard()
     doesn't work - req. more than 0 parameters.

2. lstrcpy (szSubkey, "Software\\SMSEdit\\Settings");
     : cannot convert parameter 2 from 'const char [26]' to 'LPCWSTR'

3. Reg.ReadIniDword(&nRegMaxLimit, szSubkey, "MaxLimit");
     : cannot convert parameter 3 from 'const char [9]' to 'TCHAR *'
