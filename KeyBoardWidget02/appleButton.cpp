#include "appleButton.h"

appleButton::appleButton(QWidget *parent)
    :QWidget(parent)
{
    QWidget *pParent = parentWidget();

    setMinimumSize(150, 200);
       
    maxWidth = 149;
    maxHeight = 199;
    mainViewHeight = 129;
    DeltaOne = 49;
    DeltaTwo = 98;
                        
    min = 0;
    max = 100;
    font = 18;
    precision = 0;
        
    //fstColor = green;
    //sndColor = red;
        
    m_sizeX = 130;
    m_sizeY = 65;
        
    //m_bkgColor = QtCore.Qt.lightGray
    m_bkgColor = QColor(221, 221, 221);
    m_fontName = "Courier";
    m_fontSize = 80;
    //mySize = size()
        
    initPolygon();
}
void appleButton::setMainButtonName(QString strName)
    {
        m_strTopName = strName;
        update();
    }
    
    // reimplementation of paint Event, where actual view is drowing                        
    void appleButton::paintEvent(QPaintEvent *paintEvent)
    {
        paintBigButton();
    }
        
    //Function initialize a Polygon which is represent a"BigButton". Pure mathematical    
    //coordinates calculation.                                                              
    void appleButton::initPolygon()
    {
        mainView = QPolygon(8); 
		mainView[0] = QPoint(1, 1);
		mainView[1] = QPoint(maxWidth, 1);
		mainView[2] = QPoint(maxWidth, mainViewHeight);
		mainView[3] = QPoint(maxWidth - DeltaOne, maxWidth);
		mainView[4] = QPoint(maxWidth - DeltaOne, maxHeight);
		mainView[5] = QPoint(maxWidth - DeltaTwo, maxHeight);
		mainView[6] = QPoint(maxWidth - DeltaTwo, maxWidth);
		mainView[7] = QPoint(1, mainViewHeight);
		
     }

    //Actual drowing                                                                      #  
    void appleButton::paintBigButton()
    {
    // print x(), y(), width(), height(
       QPainter painter(this);
       painter.setRenderHint(QPainter::Antialiasing);
       //linGrad = QtGui.QLinearGradient(x()+width()/2, y(), (x()+width())/2, height());
       QLinearGradient linGrad = QLinearGradient(1, 1, 1, height());
       linGrad.setColorAt(0, Qt::white);
       //linGrad.setColorAt(0.49, QtGui.QColor(8, 25, 41));
       //linGrad.setColorAt(0.51, QtGui.QColor(6, 10, 13));
       linGrad.setColorAt(1, Qt::darkGray);
       painter.setBrush(linGrad)        ;
       //painter.setBrush(m_bkgColor);
       painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
       //painter.drawPolygon(MainView)            ;
       painter.drawPolygon(mainView);
       //painter.setPen(QtGui.QPen(QtCore.Qt.black, 1, Qt.SolidLine, Qt.RoundCap, Qt.RoundJoin))        ;
       QFont labFont = QFont(m_fontName, m_fontSize, QFont::Normal)    ;
       painter.setFont(labFont)        ;
       //painter.drawText(40, 20, Qt.AlignLeft, m_strTopName);
       painter.drawText(40, 100, m_strTopName);
       
       painter.end();
    }
    
    void appleButton::setMainValueColor(int Red, int Green, int Blue)
    {
        m_MainValueColor.setRgb(Red, Green, Blue);
        update();
    }

    void appleButton::setNamesColor(int Red, int Green, int Blue)
    {
        m_NamesColor.setRgb(Red, Green, Blue);
        update();
    }
    
    
	void appleButton::mousePressEvent(QMouseEvent* eMouseEvent)
	{
        QWidget::mousePressEvent(eMouseEvent);
        //print "mousePressEvent for appleButton!", eMouseEvent.pos().x(), eMouseEvent.pos().y()  
        //isPressed = not isPressed
            
        //emit(QtCore.SIGNAL("mouseClick()"))
        //toggleValue()
        //if(eMouseEvent.button() == Qt.LeftButton);
             //update()             
             //m_pos = eMouseEvent.pos() # QPoint  
	}