#ifndef SPINBUSYINDICATOR_H
#define SPINBUSYINDICATOR_H

#include <QDeclarativeItem> // same as  #include "qdeclarativeitem.h"
// #include <D:\Qt\Qt5.0.1\5.0.1\msvc2010\include\QtDeclarative\QDeclarativeItem>

class BusyIndicator : public QDeclarativeItem
{
    Q_OBJECT

public:
    BusyIndicator(QDeclarativeItem *parent = 0);

    void setInnerRadius(const qreal& innerRadius);
    qreal innerRadius() const;

    void setOuterRadius(const qreal& outerRadius);
    qreal outerRadius() const;

    void setBackgroundColor(const QColor& color);
    qreal backgroundColor() const ;
    
    void setForegroundColor(const QColor& color);
    qreal foregroundColor() const ;

    qreal actualInnerRadius() const ;
    qreal actualOuterRadius() const ;

   ~BusyIndicator();

signals:
   void innerRadiusCanged();
   void outerRadiusCanged();
   void backgroundColorCahnged();
   void foregroundColorCahnged();
   void actualInnerRadiusCanged();
   void actualOuterRadiusChanged();

protected slots:
    //virtual void updateSpinner();

private:
    qreal m_innerRadius;
    qreal m_outerRadius;
    QColor m_backgroundColor;
    QColor m_foregroundColor;

    qreal m_size;
    qreal m_actualInnerRadius;
    qreal m_actualOuterRadius;
    QString m_cacheKey;

};

#endif // SPINBUSYINDICATOR_H
