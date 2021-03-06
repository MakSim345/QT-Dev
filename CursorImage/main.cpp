/* ======================================================================
**  main.cpp
** ======================================================================
**
** ======================================================================
**  Copyright (c) 2007 by Max Schlee
** ======================================================================
*/

#include <QtGui>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget      wgt;
    // QPixmap      pix("clock.png");
    // QPixmap      pix(":/Resources/Clock");
    QPixmap      pix(":/Clock");
    QCursor      cur(pix);

    wgt.setCursor(cur);
    wgt.resize(180, 100);
    wgt.show();

    return app.exec();
}
