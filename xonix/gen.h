#ifndef _GEN_H_
#define _GEN_H_

#include <iostream>

#include <QDateTime>
#include <QDebug>
#include <QElapsedTimer>
#include <QFrame>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QImage>
#include <QKeyEvent>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QRadioButton>
#include <QRect>
#include <QSlider>
#include <QSpinBox>
#include <QString>
#include <QTimer>    
#include <QVBoxLayout>
#include <QWidget>
#include <QtWidgets/QApplication>

#define INT_BTN_W 100
#define INT_BTN_H 50

#define STR_MAIN_TITLE " CountDown Timer"
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
#define STR_APP_NAME "CountDown Timer"

enum {NUMBER_OF_BALLS = 2};
enum {UNIVERSE_SIZE = 100};

#endif
