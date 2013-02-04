// ============================================================
//
//
// ============================================================
//
//
// ============================================================
// Description:
// ============================================================

#include "mainWidget.h"
#include "appleButton.h"
#include <QDebug>

mainWidget::mainWidget(QWidget *parent):
    QWidget(parent)
{
    QWidget *pParent = parentWidget();
    
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    
    btnMinWidth = 50;
    btnMinHeight = 50;
    isShiftOn = true;
    
    // QPainter painter = QPainter();

    setWindowTitle("QT Touch Keyboard");

    // ICSStyleSheet = StyleSheets();
    QPen pen = QPen(QColor("#cccccc"));
    QBrush brush = QBrush(QColor(127,127,255));
    int n = 0;

    minX = 150;
    minY = 65;

    //MySkins = ("BLUE", "BLACK");
    int m_vent = 0;
    // SKIN = MySkins[0];

    // QtGui.QColor(255,0,0);
    GreenColor =  QColor(0,255,0);
    BlueColor =   QColor(0,0,255);
    YellowColor = QColor(255,255,0);

    initWidgets();

    // setBlackSkin();
    
    //extraKey = appleButton();
    //extraKey.setMinimumSize(150, 200);
    //extraKey.hide();    
}

void mainWidget::initWidgets()
{
    QVector<QString> namesFirstRow;
    namesFirstRow.push_back("Q");
    namesFirstRow.push_back("W");
    namesFirstRow.push_back("E");
    namesFirstRow.push_back("R");
    namesFirstRow.push_back("T");
    namesFirstRow.push_back("Y");
    namesFirstRow.push_back("U");
    namesFirstRow.push_back("I");
    namesFirstRow.push_back("O");
    namesFirstRow.push_back("P");

    QVector<QString> namesSecondRow;
    namesSecondRow.push_back("A");
    namesSecondRow.push_back("S");
    namesSecondRow.push_back("D");
    namesSecondRow.push_back("F");
    namesSecondRow.push_back("G");
    namesSecondRow.push_back("H");
    namesSecondRow.push_back("J");
    namesSecondRow.push_back("K");
    namesSecondRow.push_back("L");    

    QVector<QString>namesThirdRow;
    namesThirdRow.push_back("Z");
    namesThirdRow.push_back("X");
    namesThirdRow.push_back("C");
    namesThirdRow.push_back("V");
    namesThirdRow.push_back("B");
    namesThirdRow.push_back("N");
    namesThirdRow.push_back("M");

    vMainLayout = new QVBoxLayout();
    hBtnTopRowOKCancel = new QHBoxLayout();
    hBtnFirstRowLayout = new QHBoxLayout();
    hBtnSecondRowLayout = new QHBoxLayout();
    hBtnThirdRowLayout = new QHBoxLayout();
    hBtnForthRowLayout = new QHBoxLayout();

    
    hBtnFirstRowLayout->addStretch();
    for(int i = 0; i < namesFirstRow.size(); i++) 
    {
        // qDebug() << namesFirstRow[i] << " \n";
        hBtnFirstRowLayout->addWidget(createButton(namesFirstRow[i]));
    }
    hBtnFirstRowLayout->addStretch();

/*    
    hBtnSecondRowLayout.addStretch()
    j = 0
    for currentName in namesSecondRow:
        hBtnSecondRowLayout.addWidget(createButton(currentName))
        j = j + 1
    hBtnSecondRowLayout.addStretch()

    hBtnThirdRowLayout.addStretch()
    createPictureButtonShift("up.png", 80, btnMinHeight)
    hBtnThirdRowLayout.addWidget(btnShift)
    j = 0
    for currentName in namesThirdRow:
        hBtnThirdRowLayout.addWidget(createButton(currentName))
        j = j + 1
    createPictureButtonBackSps("erase.png", 80, btnMinHeight)
    hBtnThirdRowLayout.addWidget(btnBackSps)
    hBtnThirdRowLayout.addStretch()

    hBtnForthRowLayout.addWidget(createCustomButton(".?123", 80, btnMinHeight))
    hBtnForthRowLayout.addWidget(createCustomButton(" SPACE ", 190, btnMinHeight))
    hBtnForthRowLayout.addWidget(createCustomButton("return", 80, btnMinHeight))

    tsDisp = QTextEdit()
    tsDisp.setMinimumSize(550, 300)
    tsDisp.setFont(QFont("Sans", 18))
    // tsDisp.setCursorWidth(20)
    cursor = tsDisp.textCursor()
    cursor.movePosition(QTextCursor.Start)

    hBtnTopRowOKCancel.addStretch()
    hBtnTopRowOKCancel.addWidget(createCustomButton("&OK", 80, btnMinHeight))
    hBtnTopRowOKCancel.addWidget(createCustomButton("&CANCEL", 80, btnMinHeight))

    vMainLayout.addLayout(hBtnTopRowOKCancel)
    vMainLayout.addWidget(tsDisp)
    vMainLayout.addLayout(hBtnFirstRowLayout)
    vMainLayout.addLayout(hBtnSecondRowLayout)
    vMainLayout.addLayout(hBtnThirdRowLayout)
    vMainLayout.addLayout(hBtnForthRowLayout)
    setLayout(vMainLayout)

    btnLog  = QPushButton("?", )
    btnLog.hide()
    */
	vMainLayout->addLayout(hBtnFirstRowLayout);
	setLayout(vMainLayout);
}

// Create button with givem alphabetic letters and connect with an appropriate signals.
QWidget* mainWidget::createButton(QString caption)
{
    // QPushButton* m_button = new QPushButton(caption);
    appleButton* m_button = new appleButton();
    m_button->setFocusPolicy(Qt::ClickFocus);

    
    //arrayOfButtons.append(*m_button);
    
    //m_button.text();
    //m_button.setMinimumSize(40, 40);
    //m_button.setMaximumSize(btnMinWidth, btnMinHeight);
    m_button->setFixedSize(btnMinWidth, btnMinHeight);
    connect(m_button, SIGNAL("clicked()"), SLOT(slotButtonClicked() ));
    connect(m_button, SIGNAL("pressed()"), SLOT(onPressed() ));
    return m_button;
}

/*
import sys, traceback
from PyQt4 import QtCore, QtGui
from ExtraKeyWidget import ExtraKeyWidget
from ExtraKeyWidget02 import ExtraKeyWidget02
from StyleSheets import StyleSheets
from appleButton import appleButton
from TestFile import ShapedClock

class mainWidget(QtGui.QWidget):

    

    #                                                                                     #
    def onDestroy(self):
        print 'Exit pressed'
        # The termination.
        #self.m_timer_ice_connect.stop()
        self.close()

    #                                                                                     #


    

    #                                                                                     #
    def onPressed(self):
        # get button name:
        strBtnName = QtCore.QString()
        strBtnName = QtCore.QObject.sender(self).text()
        pressedKeyPos = QtCore.QObject.sender(self).pos()
        #print "pressed Key ",strBtnName," on pos: ", pressedKeyPos
        #print "strBtnName = ", strBtnName, "show apple widget"
        self.showBigLetter(strBtnName, pressedKeyPos)

    #                                                                                     #
    def onPressedButton(self, btnButton):
        # get button name:
        strBtnName = QtCore.QString()
        strBtnName = btnButton.text()
        pressedKeyPos = btnButton.pos()
        #print "onPressedButton", strBtnName

        if strBtnName in ("&OK", "&Cancel", "&CANCEL", "&ok", "&cancel", " SPACE ", " space ", "return", "RETURN"):
            self.hideBigLetter()
            return

        if strBtnName.contains(QtCore.QRegExp("[0-9]")):
            self.hideBigLetter()
            return

        self.showBigLetter(strBtnName, pressedKeyPos)

    #                                                                                     #
    def onReleased(self):
        print "Button was released"
        self.hideBigLetter()

    def createCustomButton(self, caption, btnWidth, btnHeight):
        m_button = QtGui.QPushButton(caption)
        self.arrayOfButtons.append(m_button)
        m_button.setFixedSize(btnWidth, btnHeight)
        self.connect(m_button, QtCore.SIGNAL("clicked()"), self.slotButtonClicked)
        return m_button

    def createPictureButtonBackSps(self, str_picture, btnWidth, btnHeight):
        self.btnBackSps = QtGui.QPushButton()
        self.arrayOfButtons.append(self.btnBackSps)
        self.btnBackSps.setFixedSize(btnWidth, btnHeight)
        self.btnBackSps.setIcon(QtGui.QIcon(str_picture))
        self.btnBackSps.setIconSize(QtCore.QSize(30, 30))
        self.connect(self.btnBackSps, QtCore.SIGNAL("clicked()"), self.OnBackSpsButtonClicked)

    def createPictureButtonShift(self, str_picture, btnWidth, btnHeight):
        self.btnShift = QtGui.QPushButton()
        self.arrayOfButtons.append(self.btnShift)
        self.btnShift.setFixedSize(btnWidth, btnHeight)
        self.btnShift.setIcon(QtGui.QIcon(str_picture))
        self.btnShift.setIconSize(QtCore.QSize(30, 30))
        self.connect(self.btnShift, QtCore.SIGNAL("clicked()"), self.OnShiftButtonClicked)

    def OnShiftButtonClicked(self):
        print self.isShiftOn
        if self.isShiftOn:
            self.isShiftOn = False
            for i in self.arrayOfButtons:
                i.setText(i.text().toLower())
        else:
            self.isShiftOn = True
            for i in self.arrayOfButtons:
                i.setText(i.text().toUpper())

        self.tsDisp.setFocus()

    def paintEvent(self, paintEvent):
        pass
        #print "paintEvent--------"
        # QtGui.QDialog.paintEvent()
        #self.paintBigButton()

    def paintBigButton(self):
        print "paint big button!!"
        try:
            self.painter.begin(self)
            self.painter.setRenderHint(QtGui.QPainter.Antialiasing)
            # painter.setBrush(linGrad)
            self.painter.setBrush(QtCore.Qt.red)
            # border = QtCore.QRectF(5, 5, self.m_sizeW-10, self.m_sizeH-10)
            # border = QtCore.QRectF(1, 1, self.m_sizeW-1, self.m_sizeH-1)
            border = QtCore.QRectF(100, 100, 400, 400)
            self.painter.drawRoundRect(border, 20, 20)
            #borderUP = QtCore.QRectF(-10, -10, 40, 40)
            #painter.drawRoundRect(borderUP, 20, 20)
            self.painter.drawRoundRect(border, 0, 0)
            self.painter.end()
        except:
            print "ERROR in paint big button!!"
            traceback.print_exc()
            painter.end()

    def OnBackSpsButtonClicked(self):
        self.cursor.deletePreviousChar()
        self.tsDisp.setFocus()

    def slotButtonClicked(self):
        # get button name:
        strBtnName = QtCore.QString()
        strTmp = QtCore.QString()

        strBtnName = QtCore.QObject.sender(self).text()
        pressedKeyPos = QtCore.QObject.sender(self).pos()
        # print "slotButtonClicked(): ", strBtnName," on pos: ", pressedKeyPos
        # QtCore.QObject.sender(self).setFixedSize(self.btnMinWidth+10, self.btnMinHeight+10)

        # if strBtnName == "&OK" or strBtnName == "&Cancel":
        if strBtnName in ("&OK", "&CANCEL", "&ok", "&cancel"):
            self.onDestroy()

        if strBtnName.contains(QtCore.QRegExp("[0-9]")):
            return

        if strBtnName == " SPACE " or strBtnName == " space ":
            self.tsDisp.insertPlainText(" ")
            self.tsDisp.setFocus()
            return

        if strBtnName == "return" or strBtnName == "RETURN":
            self.tsDisp.append("")
            self.tsDisp.setFocus()
            return

        #print "strBtnName = ", strBtnName, "show apple widget"
        #self.showBigLetter(strBtnName, pressedKeyPos)
        self.hideBigLetter()
        #self.cursor.insertText(strBtnName)

        self.tsDisp.insertPlainText(strBtnName)
        self.tsDisp.setFocus()

    def slotButtonReleased(self, btnButton):
        # get button name:
        strBtnName = QtCore.QString()
        strTmp = QtCore.QString()

        strBtnName = btnButton.text()
        pressedKeyPos = btnButton.pos()
        #print "slotButtonReleased(): ", strBtnName," on pos: ", pressedKeyPos

        if strBtnName in ("&OK", "&CANCEL", "&ok", "&cancel"):
            self.onDestroy()

        if strBtnName.contains(QtCore.QRegExp("[0-9]")):
            # strBtnName = strTmp.setNum(self.LCDNum.value()) + strBtnName
            #self.paintBigButton()
            # self.extraKey.show()
            #self.testClock.move(45, 15)
            #self.testClock.show()
            return

        if strBtnName == " SPACE " or strBtnName == " space ":
            self.tsDisp.insertPlainText(" ")
            self.tsDisp.setFocus()
            return

        if strBtnName == "return" or strBtnName == "RETURN":
            self.tsDisp.append("")
            self.tsDisp.setFocus()
            return

        #print "strBtnName = ", strBtnName, "show apple widget"
        #self.showBigLetter(strBtnName, pressedKeyPos)
        self.hideBigLetter()
        #self.cursor.insertText(strBtnName)

        self.tsDisp.insertPlainText(strBtnName)
        self.tsDisp.setFocus()

    def showBigLetter(self, sName = "?", pos = (0,0) ):
        self.extraKey.move(pos.x()-50, pos.y()-150)
        self.extraKey.setMainButtonName(sName)
        self.extraKey.show()

    def hideBigLetter(self):
        # self.btnLog.hide()
        #print "call extraKey.hide()"
        try:
            #self.btnLog.close()
            self.extraKey.hide()
        except:
            print "ERROR in close button!!"
            traceback.print_exc()

    def mousePressEvent(self, event):
        #print "Mouse were clicked on: ", event.pos()
        # if event.button() == QtCore.Qt.LeftButton and self.newBubble is None:
        if event.button() == QtCore.Qt.LeftButton:
            #self.newBubble = Bubble(QtCore.QPointF(event.pos()), 4.0, 1.0 + random.random() * 7, self.randomColor(), self.randomColor())
            #self.bubbleTimer.start(50)
            #print "Mouse were clicked on: ", event.pos()
            self.position = event.pos()
            event.accept()
    # Moving mouse coordinates are compared with all button's coordinates and if they are #
    # matched - function onPressedButton called to show according "BigLetter".            #
    # Some buttons must be ignored, so they coordinates given in absolute values.         #
    def mouseMoveEvent(self, event):
        #print "mouse moving: ", event.pos().x(), event.pos().y()
        for i in self.arrayOfButtons:
            if i.pos().x() <= event.pos().x() <= i.pos().x()+ i.width():#self.btnMinWidth:
                # check SPACE, RETURN and other special buttons:

                if i.pos().y() <= event.pos().y() <= i.pos().y()+ i.height():
                    #print "RESULT: mouse on the key with coordinates:", i.pos().x(), i.pos().y(), i.text()
                    #print "RESULT button has ", i.width(), i.height()
                    if i.pos() == QtCore.QPoint(11, 485) or i.pos() == QtCore.QPoint(489, 485):
                        return
                    self.onPressedButton(i)
                    return
        self.hideBigLetter()

    # When a mouse was released, it's coordinates are compared with all button's          #
    # coordinates and if they are matched - function slotButtonReleased() called with the #
    # button as a parameter.                                                              #
    def mouseReleaseEvent(self, event):
        #print "mouseReleaseEvent on pos" , event.pos()
        self.hideBigLetter()
        for i in self.arrayOfButtons:
            if i.pos().x() <= event.pos().x() <= i.pos().x()+ i.width():
                if i.pos().y() <= event.pos().y() <= i.pos().y()+ i.height():
                    #print "RESULT: mouse released on the key with coordinates:", i.pos().x(), i.pos().y(), i.text()
                    self.slotButtonReleased(i)


    def startTimer(self):
        print "Start Timer - void"
        #self.m_timer_ice_connect.start(2000)

    def setIconsWidgets(self):
        # set icon for Exit button:
        self.iconExit = QtGui.QIcon('plane.png')
        #self.ui.btnExit.setIcon(self.iconExit) # plane.png
        #self.ui.btnExit.setIconSize(QtCore.QSize(50, 50))
        #self.ui.btnExit.setMask(pixmap->createHeuristicMask());

        # set icon for Alarms:
        #self.iconBell = QtGui.QIcon('bell.png')
        #self.ui.lblAlarm1.setPixmap(QtGui.QPixmap('bellred.png')) # bell.png
        #self.ui.lblAlarm1.setText(alarm TEST)
        #self.ui.lblAlarm2.setPixmap(QtGui.QPixmap('bell.png')) # bell.png


    def changeSkin(self):
        if (self.SKIN == self.MySkins[0]) :
           self.setBlackSkin()
           self.SKIN = self.MySkins[1]
        elif (self.SKIN == self.MySkins[1]):
           print "Skin will be blue again!"
           self.setBlueSkin()
           self.SKIN = self.MySkins[0]


    def setBlackSkin(self):
        for i in self.arrayOfButtons:
            self.setBlackSkinToWidget(i)
        self.setStyleSheet(self.ICSStyleSheet.getBlackDlgColor())

    def setBlueSkin(self):
        for i in self.arrayOfButtons:
            self.setBlueSkinToWidget(i)
        self.setStyleSheet(self.ICSStyleSheet.getBlueDlgColor())

    def setBlueSkinToWidget(self, qButton):
        qButton.setStyleSheet(self.ICSStyleSheet.getBlueBtnColor())

    def setBlackSkinToWidget(self, qButton):
        qButton.setStyleSheet(self.ICSStyleSheet.getBlackBtnColor())



*/

