#ifndef _GEN_H_
#define _GEN_H_

#include <iostream>
#include <QWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <QPixmap>
#include <QString>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateTime>
#include <QImage>
#include <QPointer>
#include <QRect>
#include <QRadioButton>
// #include <QRandomGenerator>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QGroupBox>
#include <QMessageBox>
#include <QLCDNumber>
#include <QtWidgets/QApplication>
#include <QPainter>

#define STR_MAIN_TITLE " Minesweeper"
#define CURRENT_VERSION "ver. 0.0.4"

#define WINWIN 1
#define LOSE 0

enum {UNIVERSE_SIZE = 100};
enum {CELL_SIZE = 20};
enum {MINES_TOTAL = 20};
enum {GRID_W = 16, GRID_H = 16};

enum TetrixShape { NoShape, ZShape, SShape,
                   LineShape, TShape, SquareShape,
                   LShape, MirroredLShape };

#endif
