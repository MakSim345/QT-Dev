#ifndef _RENDERTHREAD_H
#define _RENDERTHREAD_H
//============================================================
//
// Copyright (c) 2011 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           RenderThread.h
// Project:        Genie Carestation SW
//
// Author:         YS / Genie SW Team
//
//============================================================
// Description:
//============================================================

#include <QtGui>
#include <QMutex>
#include <QSize>
#include <QThread>
#include <QWaitCondition>

#include <math.h>

// class QImage;

class RenderThread : public QThread
 {
     Q_OBJECT

 public:
     RenderThread(QObject *parent = 0);
     ~RenderThread();

     void render(double centerX, double centerY, double scaleFactor, QSize resultSize);

 signals:
     void renderedImage(const QImage &image, double scaleFactor);

 protected:
     void run();

 private:
     uint rgbFromWaveLength(double wave);

     QMutex mutex;
     QWaitCondition condition;
     double centerX;
     double centerY;
     double scaleFactor;
     QSize resultSize;
     bool restart_thread;
     bool abort_thread;

     enum { ColormapSize = 512 };
     uint colormap[ColormapSize];
 };

 #endif