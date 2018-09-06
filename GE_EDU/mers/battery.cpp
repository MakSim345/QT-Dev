#include "battery.h"
//#include "cengine.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPolygon>
#include <QTimer>
#include <QGradient>

#if defined(Q_WS_WINCE)
#include <windows.h>
#include <pm.h>
#endif

WidgetBattery::WidgetBattery(QWidget *parent) :
QWidget(parent)
{
    QWidget *pParent = parentWidget();
    //if(pParent) setMinimumWidth(pParent->size().height());
    //else
    //setMinimumWidth(CEngine::Get()->getSettingsParam("if/iconbar/height").toInt() * 1.6);
    setMinimumWidth(50);

    m_nBatteryPercent = 100;

#if defined(Q_WS_WINCE)
    MSGQUEUEOPTIONS mqo;
    mqo.dwSize = sizeof(MSGQUEUEOPTIONS);
    mqo.dwFlags = MSGQUEUE_NOPRECOMMIT;
    mqo.dwMaxMessages = 0;
    mqo.cbMaxMessage = sizeof(POWER_BROADCAST_POWER_INFO) + sizeof(POWER_BROADCAST) + MAX_PATH;
    mqo.bReadAccess = TRUE;

    m_hPowerQ = (int)CreateMsgQueue((LPCWSTR)"PowerQ", &mqo);
    if(!m_hPowerQ)
    {
        //QMessageBox::warning(this, "", "!hPowerMsgQ");
    }
    m_hPowerNotify = (int)RequestPowerNotifications((HANDLE)m_hPowerQ, /*POWER_NOTIFY_ALL*/ PBT_POWERINFOCHANGE);
    if(!m_hPowerNotify)
    {
        //QMessageBox::warning(this, "", "!hPowerNotyfy");
    }

    QTimer *pTimer = new QTimer(this);
    QObject::connect(pTimer, SIGNAL(timeout()), this, SLOT(slotBatteryNotify()));
    pTimer->start(2000);
#endif
}

WidgetBattery::~WidgetBattery()
{
#if defined(Q_WS_WINCE)
    StopPowerNotifications((HANDLE)m_hPowerNotify);
    CloseMsgQueue((HANDLE)m_hPowerQ);
#endif
}

void WidgetBattery::paintEvent ( QPaintEvent * event )
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    //painter.setRenderHint(QPainter::Antialiasing, false);

    //////// SETTINGS

    QColor color_battery_border(25, 25, 25);
    //QColor color_battery_border(250, 0, 0);
    QColor color_gradient1 = QColor(0, 220, 0);
    QColor color_gradient2 = QColor(0, 70, 0);

    qreal gradient_pos1 = 0.4;
    qreal gradient_pos2 = 1.0;

    int offset_x = 2;
    int height_battery = 12;
    int sz_nipple = 6;
    int width_nipple = 3;

    int bFlagLines = true;
    QColor color_lines = QColor(70, 70, 70);

    ////////

    int counter = 0;
    QPolygon frame_polygon(8);
    frame_polygon.setPoint(counter++, offset_x, size().height() / 2 - height_battery / 2);
    frame_polygon.setPoint(counter++, size().width() - offset_x * 2 - width_nipple, size().height() / 2 - height_battery / 2);
    frame_polygon.setPoint(counter++, size().width() - offset_x * 2 - width_nipple, size().height() / 2 - sz_nipple / 2);
    frame_polygon.setPoint(counter++, size().width() - offset_x * 2, size().height() / 2 - sz_nipple / 2);
    frame_polygon.setPoint(counter++, size().width() - offset_x * 2, size().height() / 2 + sz_nipple / 2);
    frame_polygon.setPoint(counter++, size().width() - offset_x * 2 - width_nipple, size().height() / 2 + sz_nipple / 2);
    frame_polygon.setPoint(counter++, size().width() - offset_x * 2 - width_nipple, size().height() / 2 + height_battery / 2);
    frame_polygon.setPoint(counter++, offset_x, size().height() / 2 + height_battery / 2);

    painter.setPen(color_battery_border);
    painter.drawPolygon(frame_polygon);

    QLinearGradient gradient(
        QPointF(size().width() / 2, size().height() / 2 - height_battery / 2),
        QPointF(size().width() / 2, size().height() / 2 + height_battery / 2));
    gradient.setColorAt(gradient_pos1, color_gradient1);
    gradient.setColorAt(gradient_pos2, color_gradient2);
    
    int fill_offset_x = 1;
    int fill_offset_y = 1;

    painter.fillRect(offset_x + fill_offset_x,
        (size().height() / 2) - (height_battery / 2) + fill_offset_y,
        (int)((qreal)(size().width() - offset_x * 2 - width_nipple - 5) * (qreal)m_nBatteryPercent / 100.),
        height_battery - 2,
        //QBrush(QColor(200, 200, 200)));
        QBrush(gradient));

    if(m_nBatteryPercent == 100)
    {
        painter.fillRect(size().width() - offset_x * 2 - width_nipple - 1,
            size().height() / 2 - sz_nipple / 2 + 2,
            width_nipple,
            sz_nipple - 3,
            QColor(0, 220, 0));
    }

    if(bFlagLines)
    {
        painter.setPen(color_lines);
        for(size_t i = 0; i < 3; i++)
        {
            int step = (int)((qreal)(size().width() - offset_x * 2 - width_nipple - 5)/3);
            painter.drawLine(
                offset_x + 1 + step * (1 + i),
                size().height() / 2 - height_battery / 2 +1,
                offset_x + 1 + step * (1 + i),
                size().height() / 2 + height_battery / 2 - 1
                );
        }
    }
}

void WidgetBattery::UpdateBatteryStatus(int percent)
{
    m_nBatteryPercent = percent;
    update();
}

void WidgetBattery::slotBatteryNotify()
{
#if defined(Q_WS_WINCE)
    BYTE  buffer[sizeof(POWER_BROADCAST_POWER_INFO) + sizeof(POWER_BROADCAST) + MAX_PATH];
    DWORD dwRead = 0;
    DWORD dwFlags = 0;

    while(ReadMsgQueue((HANDLE)m_hPowerQ, (LPVOID)buffer, sizeof(buffer), &dwRead, 0, &dwFlags))
    {
        POWER_BROADCAST* pPower = (POWER_BROADCAST*)buffer;

        if(pPower->Message & PBT_POWERINFOCHANGE)
        {
            POWER_BROADCAST_POWER_INFO *pInfo = (POWER_BROADCAST_POWER_INFO*)(pPower->SystemPowerState);
            UpdateBatteryStatus(pInfo->bBatteryLifePercent);
        }
    }
#endif
}
