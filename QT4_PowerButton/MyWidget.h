// #include "AeroButton.h"
#include <QApplication>

#include "qpower.h"

class MyWidget : public QWidget
{
  Q_OBJECT
  
  public:
    MyWidget(QWidget *parent = 0);    
    
    QPower *button_power;
    // QPower *aerobutton_test;
    
  public slots:  
    void showMessageBox();  
    void closeApp();
    void on_aerobutton_test_clicked();
    
 };
 