/* mywidget.h */
#include <QLineEdit>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>


// class MyWidget : public QMainWindow
class MyWidget : public QWidget
{
    Q_OBJECT
    
    public:
        // MyWidget();
        MyWidget(QWidget *parent = 0);
        ~MyWidget ();
    private:
        QLineEdit* line1;
        QLineEdit* line2;
        QLineEdit* line3;
        QPushButton* bcalc;
        QPushButton* bExit;
        QPushButton* bclear;
        QPushButton* bRnd;
        QLabel* labplus;
        QLabel* labis;
        
        QHBoxLayout *hLayout2;	 
        QHBoxLayout	*hLayout;
        
        QVBoxLayout *mainLayout;
        int nLineEditNum;

    public slots:
        void slotCalc ();
        void slotClear ();
        void onExit ();
        int GetRNDValue();
};
