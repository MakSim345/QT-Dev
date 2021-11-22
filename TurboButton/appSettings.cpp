#include "appSettings.h"
#include "turbobutton.h"

AppSettings::AppSettings(QString strCompanyName, QString strAppName)
{
    //settings - save stuff to the Register in Win32
    settings = new QSettings(strCompanyName, strAppName);
}

void AppSettings::restoreAppWidgetSizes(TurboButton *app)
{
    QPoint green_btn_position = settings->value(STR_INI_PATH_MAIN_GREEN_BUTTON_POS, QVariant(QPoint(0, 0))).toPoint();
    // Check if any data were stored already. if not - ignore resizing.
    if (green_btn_position == (QPoint(0, 0)))
    {
        return;
    }
    app->moveButtons(green_btn_position);

    QPoint digital_scr_position = settings->value(STR_INI_PATH_MAIN_DIGITAL_POS, QVariant(QPoint(0, 0))).toPoint();
    // app->move(digital_scr_position);
}

void AppSettings::saveWidgetsSizePos(TurboButton *app)
{
    settings->setValue(STR_INI_PATH_MAIN_GREEN_BUTTON_POS, QVariant(app->getGreenButtonPoints() ));
    settings->setValue(STR_INI_PATH_MAIN_DIGITAL_POS, QVariant(app->getTimerLabelPoints() ) );
}

void AppSettings::restoreAppSizePos(QWidget *app)
{
    QSize size = settings->value(STR_INI_PATH_MAIN_SIZE, QVariant(QSize(0, 0))).toSize();
    // Check if any data were stored already. if not - ignore resizing.
    if (size == (QSize(0, 0)))
    {
        return;
    }

    app->resize(size);
    QPoint position = settings->value(STR_INI_PATH_MAIN_POS, QVariant(QPoint(0, 0))).toPoint();
    app->move(position);
}

void AppSettings::saveAppSizePos(QWidget *app)
{
    settings->setValue(STR_INI_PATH_MAIN_SIZE, QVariant(app->size()));
    settings->setValue(STR_INI_PATH_MAIN_POS, QVariant(app->pos()));
}

int AppSettings::restoreIntValues(QString strPath)
{
    int num = settings->value(strPath, QVariant("0")).toInt();
    return num;
}

QString AppSettings::restoreStrValues(QString strPath)
{
    QString num = settings->value(strPath, QVariant("0")).toString();
    return num;
}

void AppSettings::saveValues(QString strPath, QVariant qValue)
{
    settings->setValue(strPath, QVariant(qValue));
}