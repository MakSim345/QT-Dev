//============================================================
//
// Copyright © 2008 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           GuiClientI.cpp
// Project:        Intrinsic Carestation SW
//
// Author:         PA / ICS SW Team
//
//============================================================
// Description:
// Implementation of GuiClientI class that provides backend
// to Arbitrator
//============================================================
#include <Ice/Ice.h>
#include <arb.h>
//#include <icssw.h>
#include <GuiClientI.h>
#include <trace.h>

using namespace std;

namespace GUIC
{

// Arbitrator client implementation
GuiClientI::GuiClientI(const string& name) :
    _name(name)
{
    TRACE("Instantiated servant "+_name+" for Arbitrator.");
}

GuiClientI::~GuiClientI()
{
    TRACE("Destroyed servant "+_name+" for Arbitrator.");
}


// Return null proxy because GUI does not provide interfaces
ICSSW::ComponentPrx
GuiClientI::addServant(ARB::Role r,
                       const Ice::Current& c)
{    
    ASSERT(0); // this function should no be called
    return 0;
}

// Deprecate
::ICSSW::ComponentPrx
GuiClientI::addServantWithNotify(::ARB::Role r,
                                 const ::ICSSW::NotifierPrx& p,
                                 const Ice::Current& c)
{
    ASSERT(0); // this function should no be called
    return addServant(r, c);
}

// Return true, GUI has no interfaces
bool
GuiClientI::removeServant(const ::ICSSW::ComponentPrx& p,
                          const Ice::Current& c)
{
    ASSERT(0); // this function should no be called
    return true;
}


// Deprecate
::ICSSW::NotifierPrx
GuiClientI::addNotifyServant(const Ice::Current& c)
{
    ASSERT(0); // this function should no be called
    return 0;
}


// Deprecate
void
GuiClientI::removeNotifyServant(const ::ICSSW::NotifierPrx& p, 
                                const Ice::Current& c)
{
    ASSERT(0); // this function should no be called
    return;
}


void
GuiClientI::shutdown(const Ice::Current& c)
{
    ASSERT(0); // this function should no be called
    ASSERT(&c);
    // shutdown ICE server
    c.adapter->getCommunicator()->shutdown();
    return;
}


} // GUIC
// EOF
