//============================================================
//
// Copyright © 2008 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           mainc.cpp 
// Project:        Intrinsic Carestation SW
//
// Author:         PA & YS / ICS SW Team
//
//============================================================
// Description:
// Engstrom Ventilator and ICE implementation
//============================================================
#include <Ice/Ice.h>
#include <arb.h>
#include <icssw.h>
#include <ventc.h>
#include <trace.h>
#include <GuiClientI.h>

#include <QtGui>
#include <QtGui/QApplication>
#include "gui_eve.h"
#include "gen.h"

#include "eve_main.h"

//#include "utils.h"

using namespace std;
using namespace ARB;

// Example ICE Application class
class ICS_GUIApp : public Ice::Application
{
    const string _name;
    const string _passwd;

    // Ice runtime pointers
    Ice::ObjectAdapterPtr _adapter;
    
    // Loopback proxy and proxy to Arbitrator
    ClientPrx _arbClient;
    ArbitratorPrx _guru;
    // Proxy for Session running in Arbitrator
    SessionPrx _session;

public:
    ICS_GUIApp();
    ~ICS_GUIApp();

    virtual int run(int, char*[]);
};


int main(int argc, char* argv[])
{
    ICS_GUIApp app;
    return app.main(argc, argv, "config.gui");
}



// Constructor for the application
ICS_GUIApp::ICS_GUIApp() :
    Ice::Application(),
    _name("DemoGUI"),
    _passwd("demo"),
    _adapter(0),
    _arbClient(0),
    _guru(0),
    _session(0)
{
}

ICS_GUIApp::~ICS_GUIApp()
{
}


int
ICS_GUIApp::run(int argc, char* argv[])
{
    try
    {
        // Create a proxy to access Arbitrator
        _guru = ARB::ArbitratorPrx::checkedCast(
            communicator()->propertyToProxy("ArbitratorProxyStr"));
    }
    catch(const Ice::ConnectionRefusedException& ex)
    {
        // Print info about exception
        TRACE(ex);
        TRACE("Arbitrator cannot be connected!");
    }

    if(!_guru)
    {
        return EXIT_FAILURE;
    }
     
    // Create an adapter
    _adapter = communicator()->createObjectAdapter("VentilatorAdapter");
    // Add a servant "name" for Arbitrator
    _arbClient = ClientPrx::uncheckedCast(
        _adapter->addWithUUID( new GUIC::GuiClientI(_name)));
    // Activate adapter
    _adapter->activate();

    // Open session to Arbitrator
    SessionErr e;
    _session = _guru->createSession( _name, _passwd,
                                     _arbClient, e);
    if(!_session)
    {
        switch(e)
        {
        case USERNAME:
            TRACE("Invalid user name");
            break;
        case PASSWD:
            TRACE("Invalid passwd");
            break;
        case DEADSERVANT:
            TRACE("Dead ClientPrx");
            break;
        case ALREADYONLINE:
            TRACE(_name+" already online");
            break;
        default:
            // Invalid error msg
            ASSERT(0);
            break;
        }

        return EXIT_FAILURE;
    }

    // Start Qt UI
	QApplication a(argc, argv);

    // Pass session handle to MainClass
	MainClass w(0,0,_session);
	w.setWindowTitle("SW Pilot project GUI");
	w.show();
	
	return a.exec();
}
