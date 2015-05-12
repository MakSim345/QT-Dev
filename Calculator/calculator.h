/* ======================================================================
**  calculator.h
** ======================================================================
*/

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <QWidget>
#include <QStack>
#include <QLCDNumber>
#include <QPushButton>
#include <QGridLayout>

class QLCDNumber;
class QPushButton;

// ======================================================================
class Calculator : public QWidget
{
    Q_OBJECT

private:
    QLCDNumber*     m_plcd;
    QStack<QString> m_stk;

public:
    Calculator(QWidget* pwgt = 0);

    QPushButton* createButton(const QString& str);
    void         calculate   (                  );

public slots:
    void slotButtonClicked();
};

#endif  //_CALCULATOR_H_
