#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#include <QtGui>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QDialog>	

// forward declaration tells the C++ compiler that a class exists,
// without giving all the detail that a class definition:
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;


class FindDialog : public QDialog
 {
     Q_OBJECT

 public:
     FindDialog(QWidget *parent = 0);
 
 signals:
     //void findNext(const QString &str, Qt::CaseSensitivity cs);
     //void findPrevious(const QString &str, Qt::CaseSensitivity cs);

 private slots:
     //void findClicked();
     //void enableFindButton(const QString &text);
 
 private:
     QLabel *label;
     QLineEdit *lineEdit;
     QCheckBox *caseCheckBox;
     QCheckBox *backwardCheckBox;
     QPushButton *findButton;
     QPushButton *closeButton;
 };

#endif
