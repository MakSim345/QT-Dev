/****************************************************************************
*/
#include <QtGui>

#include "graphwidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    GraphWidget *widget = new GraphWidget;

    QMainWindow mainWindow;
    mainWindow.setCentralWidget(widget);

#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5)
    mainWindow.menuBar()->addAction("Shuffle", widget, SLOT(shuffle()));
    mainWindow.menuBar()->addAction("Zoom In", widget, SLOT(zoomIn()));
    mainWindow.menuBar()->addAction("Zoom Out", widget, SLOT(zoomOut()));
    mainWindow.showMaximized();
#else
    mainWindow.show();
#endif
    return app.exec();
}
