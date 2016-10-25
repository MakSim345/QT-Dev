//============================================================
//
// Copyright (c) 2011 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           starsMainView.cpp
// Project:        Genie Carestation SW
//
// Author:         YS / Genie SW Team
//
//============================================================
// Description:
//============================================================
#include "starsMainView.h"

//----------------------------------------------------------------------------
// the main GUI
//----------------------------------------------------------------------------

// constructor:
starsMainView::starsMainView(QWidget *parent) : QWidget(parent)
{
   setWindowTitle("Qt example 02");
   runButton = new QPushButton("Generate image...");
   connect(runButton, SIGNAL(clicked()), this, SLOT(run_thread()));

   QHBoxLayout *layout = new QHBoxLayout;
   layout->addWidget(runButton);
   setLayout(layout);

// window to display the image

   imageWindow = new ImageWindow();

// the QImage generation thread
   //qRegisterMetaType<QImage>("QImage");
   otherThread = new timeConsumingThread();

// slot to respond to the QImage generation thread
// - display the image in a window

   connect(otherThread, SIGNAL(theImage(const QImage &)), this, SLOT(displayImage(const QImage &)));
}

// slot to run thread
void starsMainView::run_thread()
{
   if (!otherThread->isRunning())
   {
      otherThread->start();
   }
}

// display the QImage
void starsMainView::displayImage(const QImage &image)
{
   imageWindow->plot = QPixmap::fromImage(image);
   imageWindow->show();
   imageWindow->update();
   imageWindow->raise();
   imageWindow->activateWindow();
}
