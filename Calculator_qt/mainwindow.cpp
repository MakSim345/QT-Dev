#include "mainwindow.h"
#include "ui_mainwindow.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}
