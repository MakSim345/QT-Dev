//============================================================
//
// Copyright © 2008 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           GuiClientI.h
// Project:        Intrinsic Carestation SW
//
// Author:         PA / ICS SW Team
//
//============================================================
// Description:
// Implements interfaces:
// ARB::Client (arb.ice)
//============================================================
#ifndef __GUICLIENTI_H__
#define __GUICLIENTI_H__

#include <arb.h>
#include <icssw.h>

using namespace std;

namespace GUIC
{

// This component for Arbitrator
class GuiClientI : virtual public ARB::Client
{
    const string _name;

public:
    GuiClientI(const string& name);
    ~GuiClientI();
    virtual ICSSW::ComponentPrx addServant(::ARB::Role,
                                           const Ice::Current&);
    virtual ICSSW::ComponentPrx addServantWithNotify(::ARB::Role,
                                                     const ::ICSSW::NotifierPrx&,
                                                     const Ice::Current&);
    virtual bool removeServant(const ::ICSSW::ComponentPrx&,
                               const Ice::Current&);

    virtual ::ICSSW::NotifierPrx addNotifyServant(const Ice::Current&);

    virtual void removeNotifyServant(const ::ICSSW::NotifierPrx&, 
                                     const Ice::Current&);
        
    virtual void shutdown(const Ice::Current&);
};

} // GUIC
#endif // __GUICLIENTI_H__
