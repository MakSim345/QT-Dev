#ifndef _MAIN_WIDGET_H_
#define _MAIN_WIDGET_H_

// ============================================================
//
//
// ============================================================
// Description:
// ============================================================

#include "gen.h"
//#include "appSettings.h"

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = 0);
    ~mainWidget(){};
    
    void initWidgets();
    QWidget* createButton(QString caption);
    
    /*
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);

    void onDestroy();
    
    
    void onPressed();

    void onPressedButton(btnButton);

    void onReleased();

    void createCustomButton(caption, btnWidth, btnHeight);
    void createPictureButtonBackSps(str_picture, btnWidth, btnHeight);
    void createPictureButtonShift(str_picture, btnWidth, btnHeight);
    void showBigLetter(sName = "?", pos = (0,0) );
    void slotButtonReleased(btnButton);
    
    // When a mouse was released, it's coordinates are compared with all button's          #
    // coordinates and if they are matched - function slotButtonReleased() called with the #
    // button as a parameter.                                                              #
    void mouseReleaseEvent(event);

    // Moving mouse coordinates are compared with all button's coordinates and if they are
    // matched - function onPressedButton called to show according "BigLetter".
    // Some buttons must be ignored, so they coordinates given in absolute values.
    void mouseMoveEvent(event);
    void mousePressEvent(event);

    void setBlueSkinToWidget(qButton);
    void setBlackSkinToWidget(qButton);

    void OnShiftButtonClicked();
    void paintBigButton();
    void OnBackSpsButtonClicked();
    void slotButtonClicked();
    void hideBigLetter();
    void startTimer();
    void setIconsWidgets();
    void changeSkin();
    void setBlackSkin();
    void setBlueSkin();
*/
public slots:

private:
    QVector <QWidget> arrayOfButtons;
    QVBoxLayout* vMainLayout;
    QHBoxLayout* hBtnTopRowOKCancel;
    QHBoxLayout* hBtnFirstRowLayout;
    QHBoxLayout* hBtnSecondRowLayout;
    QHBoxLayout* hBtnThirdRowLayout;
    QHBoxLayout* hBtnForthRowLayout;

    int btnMinWidth;
    int btnMinHeight;
    bool isShiftOn;
    int minX;
    int minY;

    QColor GreenColor;
    QColor BlueColor;
    QColor YellowColor;
};

#endif
