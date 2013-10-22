#include "gen.h"

int main (int argc, char **argv)
{

	QApplication app(argc,argv);
    QWidget *w = new QWidget();
    QLabel *display_image;
    QPushButton *btn = new QPushButton();
    QPushButton *btnTest = new QPushButton();
    QToolButton *btnToolBtn = new QToolButton();
    QHBoxLayout *hLayout = new QHBoxLayout();
    QHBoxLayout *mainLayout = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout();
    // QLabel * label = new QLabel("bell.png"); 
    QLabel * label = new QLabel(STR_BELL_ICON); 
    
    display_image = new QLabel();
    display_image->setPixmap(QPixmap(STR_BELL_ICON));
    display_image->adjustSize();
    
    
    vLayout->addWidget(btnTest);
    vLayout->addWidget(btnToolBtn);
    vLayout->addWidget(btn);
    
    hLayout->addWidget(label);
    hLayout->addWidget(display_image);
    mainLayout->addLayout(hLayout);
    mainLayout->addLayout(vLayout);

    // CFlagButton btn(&w,"plane.jpg");
    btn->setText("&Exit");
    btnTest->setText("&Test");
    btnToolBtn->setText("Tool Button");
    // btn->setMinimumSize(110, 35);
    
    //QPalette m_ButtonPalette;
    //m_ButtonPalette=btn->palette();// reads current palette
    //m_ButtonPalette.setColor(QPalette::Button, Qt::black);//sets up new palette componenet
    //m_ButtonPalette.setColor(QPalette::ButtonText, Qt::darkCyan);//sets up new palette componenet
    //btn->setPalette(m_ButtonPalette);//sets modfied palette
    //btn->setFocusPolicy(Qt::NoFocus);//disables focus
    
    
    QIcon m_iconPlane(STR_BELL_ICON);
    QBitmap m_bmpPlane(STR_PLANE_ICON);
    // m_iconPlane.pixmap()
    //btn->setIcon(m_ButtonIcon);//sets icon
     // btn->setIcon(QIcon( "plane.png" ) );
    btn->setIcon(m_iconPlane);    
    // btn->setMask(
    btn->setIconSize(QSize(40, 40));// sets icon size
    btn->setMinimumSize(100, 50);
    // btn->setMask(m_ButtonIcon.createHeuristicMask());//sets mask
    btnTest->setIcon(m_iconPlane);
    btnTest->setIconSize(QSize(40, 40));// sets icon size
    btnTest->setAutoFillBackground(true);
    btnTest->setMinimumSize(100, 50);
    // btnTest->setMask(m_bmpPlane.createHeuristicMask());
    
    btnToolBtn->setMinimumSize(100, 50);
    // btnToolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btnToolBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    btnToolBtn->setIcon(m_iconPlane);
    btnToolBtn->setIconSize(QSize(40, 40));// sets icon size
    // label->setPixmap("plane.jpg"); 
    QPixmap m_ButtonIcon;
    m_ButtonIcon.load("bell.png");//creates new icon based on icon
    label->setPixmap(m_ButtonIcon);  
    w->setMinimumSize(300, 150);
    
    w->setLayout(mainLayout);
    
    // put application to center:
    QRect scr = QApplication::desktop()->screenGeometry();
    w->move( scr.center() - w->rect().center() ); 
    
    w->connect(btn, SIGNAL(clicked()), SLOT(close() ));
    w->show();
    return app.exec();
}
