#ifndef WIDGETBATTERY_H
#define WIDGETBATTERY_H

#include <QWidget>

class WidgetBattery : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetBattery(QWidget *parent = 0);
    ~WidgetBattery();
    
protected:
    void paintEvent ( QPaintEvent * event );
    int m_nBatteryPercent;    

private:
    int m_hPowerQ;
    int m_hPowerNotify;

signals:

public slots:
    void UpdateBatteryStatus(int percent);

private slots:
    void slotBatteryNotify();
};

#endif // WIDGETBATTERY_H
