#ifndef CANDYDIALOG_H
#define CANDYDIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QGridLayout>
#include <QFile>

class CandyDialog : public QDialog
{
    Q_OBJECT

public:
    CandyDialog(QWidget *parent = 0);

private:
    QLabel *nameLabel;
    QLabel *passwordLabel;
    QLabel *countryLabel;
    QLabel *professionLabel;
    QComboBox *nameComboBox;
    QLineEdit *passwordLineEdit;
    QComboBox *countryComboBox;
    QListWidget *professionListWidget;
    QCheckBox *acceptCheckBox;
    QDialogButtonBox *buttonBox;
};

#endif
