#include "AeroButton2.h"

AeroButton2::AeroButton2(QWidget * parent) 
    : QPushButton(parent), 
    m_hovered(false), 
    m_pressed(false), 
    m_color(Qt::gray),
    m_highlight(Qt::lightGray),
    m_shadow(Qt::black),
    m_opacity(1.0),
    m_roundness(0){}

AeroButton2::AeroButton2(const QString & text, QWidget * parent) 
    : QPushButton(text, parent), 
    m_hovered(false), 
    m_pressed(false), 
    m_color(Qt::gray),
    m_highlight(Qt::lightGray),
    m_shadow(Qt::black),
    m_opacity(1.0),
    m_roundness(0){}

AeroButton2::AeroButton2(const QIcon & icon, const QString & text, QWidget * parent) 
    : QPushButton(icon, text, parent), 
    m_hovered(false), 
    m_pressed(false), 
    m_color(Qt::gray),
    m_highlight(Qt::lightGray),
    m_shadow(Qt::black),
    m_opacity(1.0),
    m_roundness(0){}

AeroButton2::~AeroButton2(){}

void AeroButton2::paintEvent(QPaintEvent * pe)
{
    Q_UNUSED(pe);

    QPainter painter(this);  
    painter.setRenderHint(QPainter::Antialiasing); 

    //test for state changes
    QColor button_color;
    if(this->isEnabled())
    {
        m_hovered ? button_color = m_highlight : button_color = m_color;

        if(m_pressed)
        {
            button_color = m_highlight.darker(250);
        }
    }
    else
    {
        button_color = QColor(50, 50, 50);
    }

    QRect button_rect = this->geometry();

    //outline
    painter.setPen(QPen(QBrush(Qt::black), 2.0));
    QPainterPath outline;
    outline.addRoundRect(0, 0, button_rect.width(), button_rect.height(), m_roundness, m_roundness);
    painter.setOpacity(m_opacity);
    painter.drawPath(outline);

    //gradient
    QLinearGradient gradient(0, 0, 0, button_rect.height());
    gradient.setSpread(QGradient::ReflectSpread);
    gradient.setColorAt(0.0, button_color);
    gradient.setColorAt(0.4, m_shadow);
    gradient.setColorAt(0.6, m_shadow);
    gradient.setColorAt(1.0, button_color);

    QBrush brush(gradient);
    painter.setBrush(brush); 
    painter.setPen(QPen(QBrush(button_color), 2.0));

    //main button
    QPainterPath painter_path;
    painter_path.addRoundRect(1, 1, button_rect.width() - 2, button_rect.height() - 2, m_roundness, m_roundness);
    painter.setClipPath(painter_path);

    painter.setOpacity(m_opacity);
    painter.drawRoundRect(1, 1, button_rect.width() - 2, button_rect.height() - 2, m_roundness, m_roundness);

    //glass highlight
    painter.setBrush(QBrush(Qt::white));
    painter.setPen(QPen(QBrush(Qt::white), 0.01));
    painter.setOpacity(0.30);
    painter.drawRect(1, 1, button_rect.width() - 2, (button_rect.height() / 2) - 2);
    
    //button text
    QString text = this->text();
    if(!text.isNull())
    {
        QFont font = this->font();
        painter.setFont(font);
        painter.setPen(Qt::white);
        painter.setOpacity(1.0);
        painter.drawText(0, 0, button_rect.width(), button_rect.height(), Qt::AlignCenter, text);
    }

    //icon
    QIcon icon = this->icon();
    if(!icon.isNull())
    {
        QSize icon_size = this->iconSize();
        QRect icon_position = this->calculateIconPosition(button_rect, icon_size);
        painter.setOpacity(1.0);
        painter.drawPixmap(icon_position, QPixmap(icon.pixmap(icon_size)));
    }
}

void AeroButton2::enterEvent(QEvent * e)
{
    Q_UNUSED(e);

    m_hovered = true;
    this->repaint();
}

void AeroButton2::leaveEvent(QEvent * e)
{
    Q_UNUSED(e);

    m_hovered = false;
    this->repaint();
}

void AeroButton2::mousePressEvent(QMouseEvent * e)
{
    Q_UNUSED(e);

    this->click();

    m_pressed = true;
    this->repaint();
}

void AeroButton2::mouseReleaseEvent(QMouseEvent * e)
{
    Q_UNUSED(e);

    m_pressed = false;
    this->repaint();
}

QRect AeroButton2::calculateIconPosition(QRect button_rect, QSize icon_size)
{
    int x = (button_rect.width() / 2) - (icon_size.width() / 2);
    int y = (button_rect.height() / 2) - (icon_size.height() / 2);
    int width = icon_size.width(); 
    int height = icon_size.height();

    QRect icon_position;
    icon_position.setX(x);
    icon_position.setY(y);
    icon_position.setWidth(width);
    icon_position.setHeight(height);

    return icon_position;
}
