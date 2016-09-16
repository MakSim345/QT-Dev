#ifndef _APPLE_BUTTON_H_
#define _APPLE_BUTTON_H_

#include "gen.h"

class appleButton : public QWidget
{
    Q_OBJECT

public:
    appleButton(QWidget *parent = 0);
    ~appleButton(){};
	
	QPolygon mainView;
    QString m_fontName;
    int m_fontSize;
    int maxWidth;
    int maxHeight;
    int mainViewHeight;
    int DeltaOne;
    int DeltaTwo;
                        
    int min;
    int max;
    int font;
    int precision;
	int m_mainValue;
	int m_sizeX;
	int m_sizeY;

	QColor m_MainValueColor;
	QColor m_NamesColor;
    QColor m_bkgColor;
    QString m_strTopName; // = QtCore.("A")

    void setFontName(QString str) {m_fontName = str;}       
        
    void setFontSize(int nValue) { m_fontSize = nValue;}
        
    void setMainButtonName(QString strName);
    void mousePressEvent(QMouseEvent* eMouseEvent);
    //reimplementation of paint Event, where actual view is drowing                       #  
    void paintEvent(QPaintEvent* paintEvent);
        
    //Function initialize a Polygon which is represent a"BigButton". Pure mathematical    #
    //coordinates calculation.                                                             #  
    void initPolygon();
    
    //Actual drowing                                                                      #  
    void paintBigButton();
    
    void setMainValueColor(int Red, int Green, int Blue);

    void setNamesColor(int Red, int Green, int Blue);
        
    int getMainValue() { return m_mainValue;}
        
    //void mousePressEvent(eMouseEvent);
    
    int minimumSizeHint() { return minimumSizeHint();}
   
    
    void setSizeX(int nValueX){ m_sizeX = nValueX;}

    void setSizeY(int nValueY){m_sizeY = nValueY;}

};
#endif
