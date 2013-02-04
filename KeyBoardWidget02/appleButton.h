
import sys, traceback 
from PyQt4 import QtCore, QtGui
from PyQt4.QtCore import Qt

class appleButton(QtGui.QWidget):

    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)
                
        self.setMinimumSize(150, 200)
        self.maxWidth = 149
        self.maxHeight = 199
        self.mainViewHeight = 129
        self.DeltaOne = 49
        self.DeltaTwo = 98
                        
        self.min = 0
        self.max = 100
        self.font = 18
        self.precision = 0
        
        #self.fstColor = green
        #self.sndColor = red
        
        self.m_sizeX = 130
        self.m_sizeY = 65
        
        # self.m_bkgColor = QtCore.Qt.lightGray
        self.m_bkgColor = QtGui.QColor(221, 221, 221)
        self.m_fontName = "Courier"
        self.m_fontSize = 80
        self.mySize = self.size()
        self.m_strTopName = QtCore.QString("A")
        
        self.initPolygon()
        
    def setFontName(self, str):
        self.m_fontName = str
        
    def setFontSize(self, nValue):
        self.m_fontSize = nValue    
        
    def setMainButtonName(self, strName):
        self.m_strTopName = strName
        self.update()
    
    #-------------------------------------------------------------------------------------#
    # reimplementation of paint Event, where actual view is drowing                       #  
    #-------------------------------------------------------------------------------------#    
    def paintEvent(self, paintEvent):
        self.paintBigButton()
        
    #-------------------------------------------------------------------------------------#
    # Function initialize a Polygon which is represent a"BigButton". Pure mathematical    #
    # coordinates calculation.                                                             #  
    #-------------------------------------------------------------------------------------#
    def initPolygon(self):
        self.MainView = QtGui.QPolygon([
        QtCore.QPoint(1, 1),
        QtCore.QPoint(self.maxWidth, 1),
        QtCore.QPoint(self.maxWidth, self.mainViewHeight),
        QtCore.QPoint(self.maxWidth - self.DeltaOne, self.maxWidth),
        QtCore.QPoint(self.maxWidth - self.DeltaOne, self.maxHeight),
        QtCore.QPoint(self.maxWidth - self.DeltaTwo, self.maxHeight),
        QtCore.QPoint(self.maxWidth - self.DeltaTwo, self.maxWidth),
        QtCore.QPoint(1, self.mainViewHeight)
        ])
     
    #-------------------------------------------------------------------------------------#
    # Actual drowing                                                                      #  
    #-------------------------------------------------------------------------------------#
    def paintBigButton(self):
        #print self.x(), self.y(), self.width(), self.height()
        
        try:
            painter = QtGui.QPainter()
            painter.begin(self)
            painter.setRenderHint(QtGui.QPainter.Antialiasing)
            # linGrad = QtGui.QLinearGradient(self.x()+self.width()/2, self.y(), (self.x()+self.width())/2, self.height())
            linGrad = QtGui.QLinearGradient(1, 1, 1, self.height())
            linGrad.setColorAt(0, Qt.white)
            #linGrad.setColorAt(0.49, QtGui.QColor(8, 25, 41))
            #linGrad.setColorAt(0.51, QtGui.QColor(6, 10, 13))
            linGrad.setColorAt(1, Qt.darkGray)
            painter.setBrush(linGrad)        
            # painter.setBrush(self.m_bkgColor)
            painter.setPen(QtGui.QPen(QtCore.Qt.black, 1, Qt.SolidLine, Qt.RoundCap, Qt.RoundJoin))
            # painter.drawPolygon(self.MainView)            
            painter.drawPolygon(self.MainView)
            #painter.setPen(QtGui.QPen(QtCore.Qt.black, 1, Qt.SolidLine, Qt.RoundCap, Qt.RoundJoin))        
            labFont = QtGui.QFont(self.m_fontName, self.m_fontSize, QtGui.QFont.Normal)    
            painter.setFont(labFont)        
            # painter.drawText(40, 20, Qt.AlignLeft, self.m_strTopName)
            painter.drawText(40, 100, self.m_strTopName)
        
            painter.end()
        except:
            print "ERROR in paint big button!!"
            traceback.print_exc()
            painter.end()
    
    def setMainValueColor(self, Red, Green, Blue):
        self.m_MainValueColor.setRgb(Red, Green, Blue)
        self.update()

    def setNamesColor(self, Red, Green, Blue):
        m_NamesColor.setRgb(Red, Green, Blue)
        self.update()
        
    def getMainValue(self):
        return self.m_mainValue
        
    def mousePressEvent(self, eMouseEvent):
        QtGui.QPushButton.mousePressEvent(self, eMouseEvent)
        # print "mousePressEvent for appleButton!", eMouseEvent.pos().x(), eMouseEvent.pos().y()  
        #self.isPressed = not self.isPressed
            
        #self.emit(QtCore.SIGNAL("mouseClick()"))
        #self.toggleValue()
        #if(eMouseEvent.button() == Qt.LeftButton):
             #update()             
             #m_pos = eMouseEvent.pos() # QPoint  
    
    def minimumSizeHint(self):
        return QtGui.QPushButton.minimumSizeHint(self)
    
    def setSizeX(self, nValueX):
        m_sizeX = nValueX

    def setSizeY(self, nValueY):
        m_sizeY = nValueY

#-----------------------------------------------------
    
    def paintLED3(self, value):
        
        self.mySize = self.size()
        self.setLedRadius()
        self.setLedCoordinates()
        
        #self.m_led_radius = self.mySize.height() / m_fDivider
        #self.m_led_radius = self.mySize.width() / m_fDivider
        #print "self.m_led_radius = ", self.m_led_radius
        #print "paintLED: mySize.width() = ", self.mySize.width()
        #print "paintLED: mySize.height() = ", self.mySize.height()
        
        painter = QtGui.QPainter()
        painter.begin(self)
        painter.setRenderHint(QtGui.QPainter.Antialiasing)
        #painter.setWindow( -50,-50,100,100)
        
        if(value):
            currentColor = self.m_led_color_on
        else:
            currentColor = self.m_led_color_off
                
        #radialGrad = QtGui.QRadialGradient(QtCore.QPointF(-40, -3), 10) 
        #radialGrad = QtGui.QRadialGradient(
        #        QtCore.QPointF(self.m_led_radius, self.m_led_radius), self.m_led_radius,
        #        QtCore.QPointF(self.m_led_radius*0.5, self.m_led_radius*0.5))
        
        radialGrad = QtGui.QRadialGradient(QtCore.QPointF(self.m_led_x+self.m_led_radius*0.4,
                                                          self.m_led_y+self.m_led_radius*0.4),
                                                          self.m_led_radius*0.4)
        #-----------------------------------
        #radialGrad.setColorAt(0, Qt.white)
        #radialGrad.setColorAt(1, currentColor)
        #------------------------------------
        m_add = 5.9
        m_offset = 3
        radialGrad.setColorAt(0, QtGui.QColor(255, 255, 255, 255))
        radialGrad.setColorAt(0.25, Qt.white)
        radialGrad.setColorAt(1, currentColor)
            
        brush = QtGui.QBrush(radialGrad)
        painter.setBrush(brush)
        painter.setPen(Qt.black)
        # painter.setPen(Qt.white)
        # painter.drawEllipse(-25, -25, 50, 50)
        painter.drawEllipse(self.m_led_x-m_offset, self.m_led_y-m_offset, self.m_led_radius+m_add, self.m_led_radius+m_add)
        painter.drawEllipse(self.m_led_x, self.m_led_y, self.m_led_radius, self.m_led_radius)
                
        # painter must be closed:
        painter.end()
       
    def paintLED2(self, value):        
        m_mainWidth = 20.0
        #self.m_led_x = -45
        #self.m_led_y = -15
        
        self.m_led_x = 5
        self.m_led_y = 5
        
        self.radius = m_mainWidth 
        gradient = QtGui.QRadialGradient(
                QtCore.QPointF(self.radius, self.radius), self.radius,
                QtCore.QPointF(self.radius*0.5, self.radius*0.5))

        gradient.setColorAt(0, QtGui.QColor(255, 255, 255, 255))
        gradient.setColorAt(0.25, Qt.white)
        gradient.setColorAt(1, self.m_led_color_on)
        self.brush = QtGui.QBrush(gradient)
    
        painter = QtGui.QPainter()
        painter.begin(self)
        painter.setRenderHint(QtGui.QPainter.Antialiasing)
        #painter.translate(self.position.x() - self.radius, self.position.y() - self.radius)
        painter.setBrush(self.brush)
        painter.setPen(Qt.black) # - add by YS
        #painter.drawEllipse(0.0, 0.0, 2*self.radius, 2*self.radius)
        print "m_led_x = ", self.m_led_x
        print "m_led_y = ", self.m_led_y
        painter.drawEllipse(self.m_led_x, self.m_led_y, 2*self.radius, 2*self.radius)
        #painter.drawEllipse(self.m_led_x-2, self.m_led_y-4, self.m_led_width+4, self.m_led_height+8)
        # painter must be closed:
        painter.end()        
        
    def paintLED(self, value):        
        self.mySize = self.size()
        m_mainWidth = 15.0
        m_mainHeight = m_mainWidth/5.0 
        self.m_led_x = -45
        self.m_led_y = -15
        self.m_led_width  = self.mySize.width() / m_mainWidth
        self.m_led_height = self.mySize.height() / m_mainHeight 
                
        #print "paintLED: mySize.width() = ", mySize.width()
        #print "paintLED: mySize.height() = ", mySize.height()
        
        painter = QtGui.QPainter()
        painter.begin(self)
        painter.setRenderHint(QtGui.QPainter.Antialiasing)
        painter.setWindow( -50,-50,100,100)
        #painter.setPen(Qt.white)
        #painter.drawArc(-25, -25, 50, 50, 0, 5670);
        #painter.drawArc(-32, -33, 66, 66, 0, 5670);
        #painter.setPen(Qt.darkGray);
        #painter.drawArc(-34, -33, 66, 66, 3400, 3000);

        if(value):
            currentColor = self.m_led_color_on
        else:
            currentColor = self.m_led_color_off
                
        radialGrad = QtGui.QRadialGradient(QtCore.QPointF(-40, -3), 10) 
        #radialGrad = QtGui.QRadialGradient(QtCore.QPointF(-8, -8), 20)
            
        #-----------------------------------
        #radialGrad.setColorAt(0, Qt.white)
        #radialGrad.setColorAt(1, currentColor)
        #------------------------------------
        radialGrad.setColorAt(0, QtGui.QColor(255, 255, 255, 255))
        radialGrad.setColorAt(0.25, Qt.white)
        radialGrad.setColorAt(1, currentColor)
            
        brush = QtGui.QBrush(radialGrad)
        painter.setBrush(brush)
        painter.setPen(Qt.black)
        # painter.drawEllipse(-25, -25, 50, 50)
        painter.drawEllipse(self.m_led_x-2, self.m_led_y-4, self.m_led_width+4, self.m_led_height+8)
        painter.drawEllipse(self.m_led_x, self.m_led_y, self.m_led_width, self.m_led_height)
                
        # painter must be closed:
        painter.end()
     
    
class Led:
    
    def __init__(self, position, radius, speed, innerColor, outerColor):
    
        self.position = position
        self.radius = radius
        self.speed = speed
        self.innerColor = innerColor
        self.outerColor = outerColor
        self.updateBrush()
    
    def updateBrush(self):
    
        gradient = QtGui.QRadialGradient(
                QtCore.QPointF(self.radius, self.radius), self.radius,
                QtCore.QPointF(self.radius*0.5, self.radius*0.5))

        gradient.setColorAt(0, QtGui.QColor(255, 255, 255, 255))
        gradient.setColorAt(0.25, self.innerColor)
        gradient.setColorAt(1, self.outerColor)
        self.brush = QtGui.QBrush(gradient)
    
    def drawLed(self, painter):
    
        painter.save()
        painter.translate(self.position.x() - self.radius,
                          self.position.y() - self.radius)
        painter.setBrush(self.brush)
        painter.drawEllipse(0.0, 0.0, 2*self.radius, 2*self.radius)
        painter.restore()