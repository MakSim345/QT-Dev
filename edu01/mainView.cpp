#include "mainView.h"

//#define QT_RND_SERVER
#ifndef QT_RND_SERVER
 #include <time.h>
#endif

mainView::mainView(QWidget *parent)
     : QWidget(parent)
{

    //Instantiate the labels:
    initLabels();

    //Instantiate buttons:
    initButtons();

    //Set Layouts:
    initLayouts();

    // Set Stylesheets for widgets:
    //initStyleSheets();

    // Set connections between widgets:
    setConnections();

    //Start the Timer?:
    // startTimer()
    // changeSkin()
}

void mainView::setConnections()
{
    connect(btnExit, SIGNAL(clicked()), this, SLOT(closeApp()));
    connect(btnOK,   SIGNAL(clicked()), this, SLOT(setQ()));
}

void mainView::setQ()
{
    setSecondNumber(getFirstNumber());
}

QString mainView::getFirstNumber()
{
    QString result = line_First->text();
    return result;
}

void mainView::setSecondNumber(QString strValue)
{
    line_Second->setText(strValue);
}

void mainView::showMessageBox()
{
    //QMessageBox::about(this, "Application", "Vista aero style");
}

void mainView::closeApp()
{
    qDebug("Exit pressed");
    close();
}

void mainView::initButtons()
{
    btnExit = new QPushButton();
    btnOK = new QPushButton();
    btnToolBtn = new QToolButton();
    
    btnExit->setText("&Exit");
    btnOK->setText("&OK");
    btnToolBtn->setText("Tool Button");

    btnExit->setMinimumSize(100, 50);
    btnOK->setMinimumSize(100, 50);
    btnToolBtn->setMinimumSize(100, 50);
    // btnToolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //btnToolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //btnToolBtn->setIcon(m_iconPlane);
    //btnToolBtn->setIconSize(QSize(40, 40));// sets icon size
}

void mainView::initLabels()
{
    display_image = new QLabel();
    display_image->setPixmap(QPixmap("bell.png"));
    display_image->adjustSize();

    lbl_actual_value = new QLabel("bell.png");

    QPixmap m_ButtonIcon;
    m_ButtonIcon.load("bell.png");//creates new icon based on icon
    lbl_actual_value->setPixmap(m_ButtonIcon);

    line_First = new QLineEdit();
    line_Second = new QLineEdit();

    line_First->setMinimumSize(100, 50);
    line_Second->setMinimumSize(100, 50);
}

void mainView::initLayouts()
{

    QHBoxLayout *mainLayout = new QHBoxLayout();
    QHBoxLayout *hLayout = new QHBoxLayout();
    
    QVBoxLayout *vLayout = new QVBoxLayout();

    vLayout->addWidget(line_First);
    vLayout->addWidget(btnOK);
    vLayout->addWidget(line_Second);
    // vLayout->addWidget(btnToolBtn);
    vLayout->addWidget(btnExit);

    //hLayout->addWidget(lbl_actual_value);
    //hLayout->addWidget(display_image);

    //mainLayout->addLayout(hLayout);
    mainLayout->addLayout(vLayout);

    setMinimumSize(200, 350);
    setLayout(mainLayout);
}

    
