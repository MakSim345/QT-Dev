#ifndef __main_view_h__
#define __main_view_h__

#include <QtGui>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
	
class mainView : public QWidget
{
  Q_OBJECT

  public:
    mainView(QWidget *parent = 0);

    QPushButton *evebutton;

	QLabel *lblRespRateMs;
    QLabel *display_image;
    QLabel *lbl_actual_value;
    
    QLineEdit *line_First;
    QLineEdit *line_Second;


    QPushButton *btnExit;
    QPushButton *btnOK;
    QToolButton *btnToolBtn;

	// QVUMeter *vumeter;
	QVBoxLayout *vlayout;
	QHBoxLayout *mlayout;
	QHBoxLayout *hlayout;

    QHBoxLayout *horizRRLayout;
    QVBoxLayout *vertRRLayout;

    QHBoxLayout *horizLblLayout;
    QHBoxLayout *horizBtnLayout;
    QHBoxLayout *horizMainScrLayout;
    QVBoxLayout *mainLayout;

    // QPower *button_power;
    // QPower *aerobutton_test;

    int minY;
    int minX;

  public slots:
    void showMessageBox();
    void closeApp();
    void setQ();

  private:
    void initLabels();
    void initButtons();
    void initLayouts();
    void setConnections();

    QString getFirstNumber();
    void setSecondNumber(QString strValue);
 };

#endif
