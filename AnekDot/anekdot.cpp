#include "anekdot.h"
#include <QtGui>

anekdot::anekdot(QWidget *parent) 
    : QWidget(parent)
{
    pic.load("Resources/anekdotik.png");
    // pic.load("anekdotik.png");
    // pic.load("Dot");
    move(300,300);
    setFixedSize(480,269);

    QFont font;
    font.setPointSize(16);

    LabelName  = new QLabel(QString::fromLocal8Bit("Анекдотик  v1.0"), th   is);
    LabelName->move(80,35);
    LabelName->setFont(font);
    LabelName->show();

    LabelName  = new QLabel(QString::fromLocal8Bit("12 июля 2009"), this);
    LabelName->move(320,217);
    LabelName->show();


    ButtonExit  = new QLabel(QString::fromLocal8Bit("    Закрыть"), this);
    ButtonExit->setGeometry(QRect(90, 260, 90, 20));
    ButtonExit->move(65,230);
    ButtonExit->setCursor(QCursor(Qt::PointingHandCursor));
    ButtonExit->show();

    ButtonNext  = new QLabel(QString::fromLocal8Bit("    Дальше"), this);
    ButtonNext->setGeometry(QRect(90, 260, 90, 20));
    ButtonNext->move(171,230);
    ButtonNext->setCursor(QCursor(Qt::PointingHandCursor));
    ButtonNext->show();

    textEdit = new QTextEdit(QString::fromUtf8(""),this);
    textEdit->setGeometry(QRect(40, 70, 400, 135));
    textEdit->setReadOnly(true);
    textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ButtonExit->installEventFilter(this);
    ButtonNext->installEventFilter(this);

    btnNext();
}

void anekdot::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) exit(0);
}

void anekdot::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
    {
	    MouseStartPosX=event->globalX();
	    MouseStartPosY=event->globalY();
    }
    
}

void anekdot::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton) 
    {
        this->move((this->x())+(event->globalX()-MouseStartPosX),(this->y())+(event->globalY()-MouseStartPosY));
	    MouseStartPosX=event->globalX();
	    MouseStartPosY=event->globalY();
    }
}

bool anekdot::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::MouseButtonPress) 
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(e);
        if (mouseEvent->button() == Qt::LeftButton)
        {
    	    if (o == ButtonExit) exit(0);
    	    if (o == ButtonNext) btnNext();
        }
    }

    return QWidget::eventFilter(o, e);
}


void anekdot::resizeEvent(QResizeEvent *e)
{
    setMask(pic.mask());
}
        
void anekdot::paintEvent(QPaintEvent *e)
{
    QRegion r1(pic.rect());
    QPainter painter(this);
            
    painter.setClipRegion(r1);
    painter.drawPixmap(pic.rect(), pic);
    
}

void anekdot::btnNext()
{
    textEdit->setHtml(QString::fromLocal8Bit("Загрузка..."));
    http = new QHttp(this);
    connect(http, SIGNAL(done(bool)), this, SLOT(RefreshAnek()));

    
    // 
    // QHttpRequestHeader header = QHttpRequestHeader("GET", "/anekdotik/ank.php", 1, 1);
    QHttpRequestHeader header = QHttpRequestHeader("GET", "www.anekdot.ru/static/rss.html", 1, 1);    
    
    
    header.setValue("User-Agent", "Firefox 4");
    //header.setValue("Host", "anonimsurfer.profikom.ru");    
    //header.setValue("User-Agent", "Mozilla/5.0 (X11; U; Linux x86_64; ru; rv:1.9.0.10) Gecko/2009042809 GranParadiso/3.0.10");
    //header.setValue("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    //header.setValue("Accept-Language", "ru,en-us;q=0.7,en;q=0.3");    
    //header.setValue("Accept-Charset", "windows-1251,utf-8;q=0.7,*;q=0.7");
    //header.setValue("Keep-Alive", "300");
    //header.setValue("Connection", "keep-alive");
    // http->setHost("anonimsurfer.profikom.ru");
    
    http->setHost("http://www.anekdot.ru");    
    http->request(header);       
    return;
}

void anekdot::RefreshAnek()
{
    QString text;
    QByteArray encodedString;

    text = (http->readAll());

    encodedString.append(text);
    QTextCodec *codec = QTextCodec::codecForName("windows-1251");
    text = codec->toUnicode(encodedString);

    text.remove(0,10);
    text.replace("#","");
    text.replace("\r","<BR>");    
    
    textEdit->setHtml("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta http-equiv=\"content-type\" content=\"text/html;charset=windows-1251\"></head><body> "+text+"  </body></html>");
    
}
