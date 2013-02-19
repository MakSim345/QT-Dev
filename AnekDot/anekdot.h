#ifndef ANEKDOTIK_H
#define ANEKDOTIK_H

#include <QtGui>
// #include <QNetwork>
// #include <D:\Qt\Qt5.0.1\5.0.1\msvc2010\include\QNetwork\QHttp>
// #include <QHttp.h>
#include <QApplication>
#include <QLabel>
#include <QTextEdit>


class anekdot : public QWidget 
{
	Q_OBJECT
    public:
	anekdot(QWidget *parent = 0);    

    private:
	QPixmap pic;
	int MouseStartPosX;
	int MouseStartPosY;
	QLabel *LabelName;
	QLabel *ButtonExit;
	QLabel *ButtonNext;
    QTextEdit *textEdit;
    QHttp *http;
	
	void btnNext();
	
    protected:
	void resizeEvent(QResizeEvent */*e*/);
	void paintEvent(QPaintEvent *e);
	void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    bool eventFilter(QObject*, QEvent *);
	void keyPressEvent(QKeyEvent *event);

    private slots:
	void RefreshAnek();
        	
};

#endif