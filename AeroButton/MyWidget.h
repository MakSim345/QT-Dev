#include "AeroButton.h"
#include "AeroButton2.h"

class MyWidget : public QWidget
{
  Q_OBJECT
    private:
      QLineEdit* line1;
      QLineEdit* line2;
      QLineEdit* line3;
      QPushButton* bcalc;
      QPushButton* bclear;
      QLabel* labplus;
      QLabel* labis;

    public slots:
      void slotCalc ();
      void slotClear ();
      void showMessageBox();
      void closeApp();
      void on_aerobutton_test_clicked();

    public:
     MyWidget(QWidget *parent = 0);
     ~MyWidget ();
      
     AeroButton *aerobutton_quit;
     AeroButton *aerobutton_calc;
     AeroButton *aerobutton_clear;
     AeroButton *aerobutton_new;
      
};

#ifdef YS_23423442234LL
// class MyWidget : public QWidget
class MyWidget : public QMainWindow
{
  Q_OBJECT
  
  public:
    // MyWidget(QWidget *parent = 0);  
    MyWidget();
    ~MyWidget ();  
    
    AeroButton *aerobutton_quit;
    AeroButton *aerobutton_test;
    
  public slots:  
    void showMessageBox();  
    void closeApp();
    void on_aerobutton_test_clicked();
    
 };
#endif // YS_23423442234LL
 
 