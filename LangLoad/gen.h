#ifndef _GEN_H_
#define _GEN_H_

// #include <windows.h>
// #include <time.h>

#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QString>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QGroupBox>
#include <QMessageBox>
#include <QtWidgets/QDialog>

#include <stdio.h>
#include <io.h>
using namespace std;


#define INT_BTN_W 150
#define INT_BTN_H 40
#define INT_BTN_TR_H 70

enum {MAX_LEN = 256};
enum {FILE_NAME_LEN_CONFIG = 13, FILE_NAME_LEN_OUTPUT = 11};

#define STR_MAIN_TITLE "Langload"
#define CURRENT_VERSION "v1.0.0.19 (ESP3)"

#define STR_BTN_FIX_CORRUPTION "&Fix Corruption" // "&Restart ESP"
#define STR_BTN_ENABLE_WD      "Enable &WD"      // "&Send to ESP"
#define STR_BTN_REMOVE_LOCK    "&Remove Lock"    // "&Convert File"
#define STR_BTN_TRANSFER       "&Transfer"

#define STR_BTN_QUIT   "&Quit"

#define STR_DATE_FORMAT "dd.MM.yyyy"
#define INT_MILLISEC_CHECK 500

#define INT_MILLISEC_WAIT_FOR_REBOOT 5000

#define DO_INCREMENT 1

#endif
