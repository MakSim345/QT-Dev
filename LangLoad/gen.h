#ifndef _GEN_H_
#define _GEN_H_

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
#include <windows.h>
#include <WinBase.h>
#include <tchar.h>

using namespace std;

#define INT_BTN_W 150
#define INT_BTN_H 40
#define INT_BTN_TR_H 70

#define INT_LABEL_H 25
#define INT_LABEL_W 180
#define INT_LABEL_DBG_W 400
#define INT_LABEL_FILE_W 340

#define INT_LNG_LENGHT 3 // file extension: "LNG"

enum {MAX_LEN = 256};
enum {INT_CONFIG_FILE_NAME_LEN = 13, INT_OUTPUT_FILE_NAME_LEN = 11};
enum {INT_BUTTON_FONT_SIZE = 13, INT_LABEL_FONT_SIZE = 15};

#define STR_OUTPUT_FILE_NAME "output.txt"
#define STR_CONFIG_FILE_NAME "LangLoad.cfg"

#define STR_MAIN_TITLE "Langload"
#define CURRENT_VERSION "v1.0.0.20 (ESP3)"

#define STR_BTN_FIX_CORRUPTION "&Fix Corruption" // "&Restart ESP"
#define STR_BTN_ENABLE_WD      "Enable &WD"      // "&Send to ESP"
#define STR_BTN_REMOVE_LOCK    "&Remove Lock"    // "&Convert File"
#define STR_BTN_TRANSFER       "&Transfer"
#define STR_BTN_QUIT   "&Quit"

#define STR_PPD   "ppd"
#define STR_MAX   "Max"
#define STR_FLEX  "Flex"
#define STR_LITE  "Lite"

#define STR_DATE_FORMAT "dd.MM.yyyy"

#define INT_MILLISEC_WAIT_FOR_REBOOT 5000

#endif
