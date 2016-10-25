#ifndef _STARS_MAIN_VIEW_H_
#define _STARS_MAIN_VIEW_H_

#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <time.h>
#include "worker.h"
#include "imagewindow.h"

class starsMainView : public QWidget
{ 
   Q_OBJECT 

   public:
      starsMainView(QWidget *parent = 0);

   private:
      QPushButton *runButton;
      timeConsumingThread *otherThread;
      ImageWindow *imageWindow;

   public slots:
      void run_thread();
      void displayImage(const QImage &);
};

#endif