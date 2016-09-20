#include <QApplication>
 
#include "SoundPlayer.h" 
 
int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     QSoundPlayer soundPlayer;
     soundPlayer.show();
     return app.exec();
}


#ifdef TEST_YS_27MAR2009 

class MyWidget : public QWidget
 {
 public:
     MyWidget(QWidget *parent = 0);
 };

 MyWidget::MyWidget(QWidget *parent)
     : QWidget(parent)
 {
     // QPushButton *quit = new QPushButton(tr("Quit"));
     QToolButton *quit = new QToolButton();
     quit->setText(tr("Quit"));
     quit->setFont(QFont("Times", 18, QFont::Bold));
     quit->setMinimumSize(150, 50);

     QLCDNumber *lcd = new QLCDNumber(2);
     lcd->setSegmentStyle(QLCDNumber::Filled);
     lcd->setMinimumSize(150, 150);

     QSlider *slider = new QSlider(Qt::Horizontal);
     slider->setRange(0, 99);
     slider->setValue(0);

     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
     connect(slider, SIGNAL(valueChanged(int)),
             lcd, SLOT(display(int)));

     QVBoxLayout *layout = new QVBoxLayout;
     
     layout->addWidget(lcd);
     layout->addWidget(slider);
     layout->addWidget(quit);
     
     setLayout(layout);
 }

#endif