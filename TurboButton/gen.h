#ifndef _GEN_H_
#define _GEN_H_

// #include <windows.h>
// #include <time.h>

#define INT_BTN_W 100
#define INT_BTN_H 50

#define STR_MAIN_TITLE "TurboButton. Today done"
#define CURRENT_VERSION "ver. 0.0.4"
#define STR_SEC " sec"
#define STR_MIN " min"
#define STR_MINUTES  "Minutes"
#define STR_SECONDS  "Seconds"
#define STR_SOUND_ON  "Sound ON"
#define STR_SOUND_OFF  "Sound OFF"
#define STR_REMAINS  "Remains:"
#define STR_INIT_TIME "00:00"
#define STR_SET_TIME  "Set Time: "
#define STR_PLANE_ICON ":/Plane"
#define STR_BTN_PAUSE  "&Pause"
#define STR_BTN_RESUME "&Resume"
#define STR_BTN_START  "&Start"
#define STR_BTN_STOP   "S&top"
#define STR_BTN_QUIT   "&Quit"
#define STR_COMPANY_NAME "YS"
#define STR_DATE_FORMAT "dd.MM.yyyy"
#define STR_APP_NAME "TurboButton"
#define INT_MILLISEC_CHECK 500
#define DO_INCREMENT 1

#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QString>
#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QGroupBox>
#include <QMessageBox>
#include <QtWidgets/QDialog>

typedef enum
{
    RED_BUTTON,
    GREEN_BUTTON
} BUTTON_STYLE;

using namespace std;

#endif
