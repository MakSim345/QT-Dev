#include "gen.h"

class CFlagButton:QPushButton
{
public:

    CFlagButton(QWidget* parent, const QString flagPicture):QPushButton(parent)
    {
        QFont m_ButtonFont;
        // sets up button font
        //m_ButtonFont.setFamily("1942 Report");    // sets font name
        m_ButtonFont.setPointSize(36);    // sets font size
        m_ButtonFont.setBold(true);    // sets bold on
        this->setFont(m_ButtonFont);    // sets font
        // sets button palette (background and text color)
        this->setAutoFillBackground(true);    // sets auto fill background feature
        QPalette m_ButtonPalette;
        m_ButtonPalette=this->palette();// reads current palette
        m_ButtonPalette.setColor(QPalette::Button, Qt::black);//sets up new palette componenet
        m_ButtonPalette.setColor(QPalette::ButtonText, Qt::white);//sets up new palette componenet
        this->setPalette(m_ButtonPalette);//sets modfied palette
        this->setFocusPolicy(Qt::NoFocus);//disables focus
        QPixmap m_ButtonIcon;
        m_ButtonIcon.load(flagPicture);//creates new icon based on icon
        setIcon(m_ButtonIcon);//sets icon
        setIconSize(QSize(256, 256));// sets icon size
        setMask(m_ButtonIcon.createHeuristicMask());//sets mask
    }
};

