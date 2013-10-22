/*
 * clockapplication.cpp
 *
 */

#include "clockapplication.h"

ClockApplication::ClockApplication(int& argc, char* argv[])
    : QApplication(argc, argv)
{
}


ClockApplication::~ClockApplication()
{
}

void ClockApplication::commitData(QSessionManager& manager)
{

}

void ClockApplication::saveState(QSessionManager& manager)
{

}
