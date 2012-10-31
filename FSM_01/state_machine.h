#ifndef _STATE_MACHINE_H_
#define _STATE_MACHINE_H_

#include <QWidget>

class state_machine : public QWidget
{
    Q_OBJECT
public:
    explicit state_machine(QWidget *parent = 0);
    ~state_machine();
    
protected:
    //void paintEvent ( QPaintEvent * event );
    int m_nBatteryPercent;    

private:
    int m_hPowerQ;
    int m_hPowerNotify;

signals:

public slots:
    //void UpdateBatteryStatus(int percent);

private slots:
    //void slotBatteryNotify();
};
#endif // WIDGETBATTERY_H
