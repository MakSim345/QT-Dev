15:01 28-MAR-2008


To make project support DEBUG output to CMD, do follow:

 1. Made *.pro file writable - "checkout" it from ClearCase.
 2. Clean project form automatically generated files. For example run "CleanGeneratedFiles.bat".
 3. Run qmake -project
 4. For DEBUGGING output - add to *.pro file follow line: "CONFIG += console".
 5. Run qmake -t vcapp
 6. Run qmake
 7. Open the *.vcproj file.
 8. When VC2005 ask about converting - answer yes.
 9. Press "Build". The VC2005 will ask about save project *.sln file. Press "save".
10. Done. 

01-APR-2008
Got another annoying problem - in project lot of functions occur deprecated warnigs C4996: 'function' was declared deprecated". 

Nothing special, but lot of rubbish in compiler output. Need to "clean" it.

Solution: add to first line of file gen.h (which is included to EVERY file in the project) follow lines:

#define _CRT_SECURE_NO_DEPRECATE

#define _CRT_NONSTDC_NO_DEPRECATE


03-APR-2008
Problem with converting char* to TCHAR.
Solution: 
- multi-byte strings set from settings;
- #include "TCHAR.H";
- use _T() macros;
13:33 17.04.2008

