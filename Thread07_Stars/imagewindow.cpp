#include "imagewindow.h"
//----------------------------------------------------------------------------
// image window
//----------------------------------------------------------------------------

// constructor
ImageWindow::ImageWindow(QWidget *parent) : QWidget(parent)
{
   setFixedSize(600, 600);
   setWindowTitle("Qt Example 02: Image");
}

//-----------------------------------------------------------------------------
// paint the image
//-----------------------------------------------------------------------------
void ImageWindow::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   // painter.drawPixmap(0, 0, plot);
   painter.drawPixmap(rect_plot_to_drow, plot);
}