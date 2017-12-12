#ifndef _GEN_H_
#define _GEN_H_

// #include <windows.h>
// #include <time.h>

#define INT_BTN_W 100
#define INT_BTN_H 50

#define STR_MAIN_TITLE "TurboButton. Today done"
#define CURRENT_VERSION "ver. 0.0.8"
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

// #define STR_TIMER_GOT_LIMIT "Timer has got it's limit!"
#define STR_TIMER_SHORT_BREAK_OVER "Short break is over."
#define STR_TIMER_LONG_BREAK_OVER "Long break is over."

#define STR_INI_PATH_TOMATO_COUNTER "MainWindow/Values/Tomato_Counter"
#define STR_INI_PATH_BREAK_COUNTER "MainWindow/Values/Break_Counter"
#define STR_INI_PATH_DATE           "MainWindow/Values/Date"


#define INT_MILLISEC_CHECK 500
#define INT_MINUTES_SHORT_BREAK 5
#define INT_MINUTES_LONG_BREAK 30
#define INT_MINUTES_TOMATO 25
#define INT_SECONDS_IN_MINUTE 60

#define DO_INCREMENT 1
#define NO_INCREMENT 0

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
    RED_BUTTON, GREEN_BUTTON
} BUTTON_STYLE;


typedef enum
{
    NO_ACTION,
    RUNNING_TOMATO,
    RUNNING_BREAK_LONG,
    RUNNING_BREAK_SHORT
} CURRENT_STATE;

using namespace std;

#endif
