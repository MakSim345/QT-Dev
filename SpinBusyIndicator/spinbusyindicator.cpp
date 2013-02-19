#include "spinbusyindicator.h"

BusyIndicator::BusyIndicator( QDeclarativeItem* parent )
    : QDeclarativeItem( parent )
      , m_innerRadius(0.8)
      , m_outerRadius(1.0)
      , m_backgroundColor(177, 210, 143, 70)
      , m_foregroundColor(119, 183, 83, 255)
      , m_actualOuterRadius (100.0)
      , m_actualInnerRadius (90.0)
      , m_cacheKey()
{
    
}

BusyIndicator::~BusyIndicator()
{

}
