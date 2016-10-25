#ifndef IMAGEWINDOW_H_
#define IMAGEWINDOW_H_

#include <QWidget>
#include <QPixmap>
#include <QPainter>

class ImageWindow : public QWidget
{
   Q_OBJECT

   public:
      ImageWindow(QWidget *parent = 0);
      QPixmap plot;
      QRect rect_plot_to_drow;

   private:


   protected:
      void paintEvent(QPaintEvent *event);

};

#endif /*IMAGEWINDOW_H_*/