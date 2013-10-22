/*
 * clockapplication.h
 *
 */

#ifndef CLOCKAPPLICATION_H
#define CLOCKAPPLICATION_H

#include <QApplication>
#include <QSessionManager>

class ClockApplication : public QApplication
{
Q_OBJECT

public:
    ClockApplication(int& argc, char* argv[]);
    ~ClockApplication();
    virtual void commitData(QSessionManager& manager);
    virtual void saveState(QSessionManager& manager);
};

#endif
