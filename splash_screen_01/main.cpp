/* ======================================================================
**  main.cpp
** ======================================================================
**
** ======================================================================
**  Copyright (c) 2007 by Max Schlee
** ======================================================================
*/

#include <QApplication>
#include <QTime>
#include <QLabel>
#include "splash_screen.h"

// ----------------------------------------------------------------------
void loadModules(QSplashScreen* psplash)
{
    QTime time;
    time.start();

    for (int i = 0; i < 100; ) 
    {
        if (time.elapsed() > 40) 
        {
            time.start();
            ++i;
        }
        psplash->showMessage("Loading modules: " 
                             + QString::number(i) + "%", 
                             Qt::AlignHCenter | Qt::AlignBottom, 
                             Qt::black
                            );
    }
}
// ----------------------------------------------------------------------

int main (int argc, char** argv)
{
    QApplication  app(argc, argv);
    QSplashScreen splash(QPixmap("Resources/splash.png"));

    splash.show();
  
    QLabel lbl("<H1><CENTER>My Application<BR>"
               "Is Ready!</CENTER></H1>"
              );

    loadModules(&splash);

    splash.finish(&lbl);

    lbl.resize(250, 250);
    lbl.show();

    return app.exec();
}