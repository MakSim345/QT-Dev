#ifndef REDBUTTON_H
#define REDBUTTON_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QProgressDialog>

class RedButton : public QWidget
{
 Q_OBJECT
 public:
  RedButton(); 
  void BuildInterface();
  void ReadFromFile();
  QListWidget *list;
  QPushButton *dirSelect;
  QPushButton *fileSelect;
  QPushButton *redB;
  QPushButton *deleteB;
  QPushButton *saveB;
 public slots:
  //void InsertFile();
  //void InsertDir();
  //void DeleteItem(); 
  //void SaveToFile();
  //void DeleteFiles();
};

#endif
