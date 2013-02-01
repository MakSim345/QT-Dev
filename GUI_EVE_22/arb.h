// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `arb.ice'

#ifndef __arb_h__
#define __arb_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <Ice/StreamF.h>
#include <icssw.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 302
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace ARB
{

class Client;
bool operator==(const Client&, const Client&);
bool operator!=(const Client&, const Client&);
bool operator<(const Client&, const Client&);
bool operator<=(const Client&, const Client&);
bool operator>(const Client&, const Client&);
bool operator>=(const Client&, const Client&);

class Session;
bool operator==(const Session&, const Session&);
bool operator!=(const Session&, const Session&);
bool operator<(const Session&, const Session&);
bool operator<=(const Session&, const Session&);
bool operator>(const Session&, const Session&);
bool operator>=(const Session&, const Session&);

class Arbitrator;
bool operator==(const Arbitrator&, const Arbitrator&);
bool operator!=(const Arbitrator&, const Arbitrator&);
bool operator<(const Arbitrator&, const Arbitrator&);
bool operator<=(const Arbitrator&, const Arbitrator&);
bool operator>(const Arbitrator&, const Arbitrator&);
bool operator>=(const Arbitrator&, const Arbitrator&);

}

}

namespace ARB
{

class Client;
bool operator==(const Client&, const Client&);
bool operator!=(const Client&, const Client&);
bool operator<(const Client&, const Client&);
bool operator<=(const Client&, const Client&);
bool operator>(const Client&, const Client&);
bool operator>=(const Client&, const Client&);

class Session;
bool operator==(const Session&, const Session&);
bool operator!=(const Session&, const Session&);
bool operator<(const Session&, const Session&);
bool operator<=(const Session&, const Session&);
bool operator>(const Session&, const Session&);
bool operator>=(const Session&, const Session&);

class Arbitrator;
bool operator==(const Arbitrator&, const Arbitrator&);
bool operator!=(const Arbitrator&, const Arbitrator&);
bool operator<(const Arbitrator&, const Arbitrator&);
bool operator<=(const Arbitrator&, const Arbitrator&);
bool operator>(const Arbitrator&, const Arbitrator&);
bool operator>=(const Arbitrator&, const Arbitrator&);

}

namespace IceInternal
{

void incRef(::ARB::Client*);
void decRef(::ARB::Client*);

void incRef(::IceProxy::ARB::Client*);
void decRef(::IceProxy::ARB::Client*);

void incRef(::ARB::Session*);
void decRef(::ARB::Session*);

void incRef(::IceProxy::ARB::Session*);
void decRef(::IceProxy::ARB::Session*);

void incRef(::ARB::Arbitrator*);
void decRef(::ARB::Arbitrator*);

void incRef(::IceProxy::ARB::Arbitrator*);
void decRef(::IceProxy::ARB::Arbitrator*);

}

namespace ARB
{

typedef ::IceInternal::Handle< ::ARB::Client> ClientPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::ARB::Client> ClientPrx;

void __write(::IceInternal::BasicStream*, const ClientPrx&);
void __read(::IceInternal::BasicStream*, ClientPrx&);
void __write(::IceInternal::BasicStream*, const ClientPtr&);
void __patch__ClientPtr(void*, ::Ice::ObjectPtr&);

void __addObject(const ClientPtr&, ::IceInternal::GCCountMap&);
bool __usesClasses(const ClientPtr&);
void __decRefUnsafe(const ClientPtr&);
void __clearHandleUnsafe(ClientPtr&);

typedef ::IceInternal::Handle< ::ARB::Session> SessionPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::ARB::Session> SessionPrx;

void __write(::IceInternal::BasicStream*, const SessionPrx&);
void __read(::IceInternal::BasicStream*, SessionPrx&);
void __write(::IceInternal::BasicStream*, const SessionPtr&);
void __patch__SessionPtr(void*, ::Ice::ObjectPtr&);

void __addObject(const SessionPtr&, ::IceInternal::GCCountMap&);
bool __usesClasses(const SessionPtr&);
void __decRefUnsafe(const SessionPtr&);
void __clearHandleUnsafe(SessionPtr&);

typedef ::IceInternal::Handle< ::ARB::Arbitrator> ArbitratorPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::ARB::Arbitrator> ArbitratorPrx;

void __write(::IceInternal::BasicStream*, const ArbitratorPrx&);
void __read(::IceInternal::BasicStream*, ArbitratorPrx&);
void __write(::IceInternal::BasicStream*, const ArbitratorPtr&);
void __patch__ArbitratorPtr(void*, ::Ice::ObjectPtr&);

void __addObject(const ArbitratorPtr&, ::IceInternal::GCCountMap&);
bool __usesClasses(const ArbitratorPtr&);
void __decRefUnsafe(const ArbitratorPtr&);
void __clearHandleUnsafe(ArbitratorPtr&);

}

namespace ARB
{

enum Role
{
    READ,
    CONTROL,
    WRITE
};

void __write(::IceInternal::BasicStream*, Role);
void __read(::IceInternal::BasicStream*, Role&);

enum SessionErr
{
    SESSIONCREATED,
    USERNAME,
    PASSWD,
    DEADSERVANT,
    ALREADYONLINE
};

void __write(::IceInternal::BasicStream*, SessionErr);
void __read(::IceInternal::BasicStream*, SessionErr&);

enum HandleErr
{
    HANDLECREATED,
    ALREADYCONNECTED,
    HOSTOFFLINE,
    HOSTNAME,
    ACCESS
};

void __write(::IceInternal::BasicStream*, HandleErr);
void __read(::IceInternal::BasicStream*, HandleErr&);

}

namespace IceProxy
{

namespace ARB
{

class Client : virtual public ::IceProxy::Ice::Object
{
public:

    ::ICSSW::ComponentPrx addServant(::ARB::Role attr)
    {
        return addServant(attr, 0);
    }
    ::ICSSW::ComponentPrx addServant(::ARB::Role attr, const ::Ice::Context& __ctx)
    {
        return addServant(attr, &__ctx);
    }
    
private:

    ::ICSSW::ComponentPrx addServant(::ARB::Role, const ::Ice::Context*);
    
public:

    bool removeServant(const ::ICSSW::ComponentPrx& p)
    {
        return removeServant(p, 0);
    }
    bool removeServant(const ::ICSSW::ComponentPrx& p, const ::Ice::Context& __ctx)
    {
        return removeServant(p, &__ctx);
    }
    
private:

    bool removeServant(const ::ICSSW::ComponentPrx&, const ::Ice::Context*);
    
public:

    ::ICSSW::ComponentPrx addServantWithNotify(::ARB::Role attr, const ::ICSSW::NotifierPrx& p)
    {
        return addServantWithNotify(attr, p, 0);
    }
    ::ICSSW::ComponentPrx addServantWithNotify(::ARB::Role attr, const ::ICSSW::NotifierPrx& p, const ::Ice::Context& __ctx)
    {
        return addServantWithNotify(attr, p, &__ctx);
    }
    
private:

    ::ICSSW::ComponentPrx addServantWithNotify(::ARB::Role, const ::ICSSW::NotifierPrx&, const ::Ice::Context*);
    
public:

    ::ICSSW::NotifierPrx addNotifyServant()
    {
        return addNotifyServant(0);
    }
    ::ICSSW::NotifierPrx addNotifyServant(const ::Ice::Context& __ctx)
    {
        return addNotifyServant(&__ctx);
    }
    
private:

    ::ICSSW::NotifierPrx addNotifyServant(const ::Ice::Context*);
    
public:

    void removeNotifyServant(const ::ICSSW::NotifierPrx& p)
    {
        removeNotifyServant(p, 0);
    }
    void removeNotifyServant(const ::ICSSW::NotifierPrx& p, const ::Ice::Context& __ctx)
    {
        removeNotifyServant(p, &__ctx);
    }
    
private:

    void removeNotifyServant(const ::ICSSW::NotifierPrx&, const ::Ice::Context*);
    
public:

    void shutdown()
    {
        shutdown(0);
    }
    void shutdown(const ::Ice::Context& __ctx)
    {
        shutdown(&__ctx);
    }
    
private:

    void shutdown(const ::Ice::Context*);
    
public:
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class Session : virtual public ::IceProxy::Ice::Object
{
public:

    ::ICSSW::ComponentPrx createHandle(const ::std::string& name, ::ARB::Role attr, ::ARB::HandleErr& e)
    {
        return createHandle(name, attr, e, 0);
    }
    ::ICSSW::ComponentPrx createHandle(const ::std::string& name, ::ARB::Role attr, ::ARB::HandleErr& e, const ::Ice::Context& __ctx)
    {
        return createHandle(name, attr, e, &__ctx);
    }
    
private:

    ::ICSSW::ComponentPrx createHandle(const ::std::string&, ::ARB::Role, ::ARB::HandleErr&, const ::Ice::Context*);
    
public:

    void closeHandle(const ::ICSSW::ComponentPrx& proxy)
    {
        closeHandle(proxy, 0);
    }
    void closeHandle(const ::ICSSW::ComponentPrx& proxy, const ::Ice::Context& __ctx)
    {
        closeHandle(proxy, &__ctx);
    }
    
private:

    void closeHandle(const ::ICSSW::ComponentPrx&, const ::Ice::Context*);
    
public:

    void close()
    {
        close(0);
    }
    void close(const ::Ice::Context& __ctx)
    {
        close(&__ctx);
    }
    
private:

    void close(const ::Ice::Context*);
    
public:
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class Arbitrator : virtual public ::IceProxy::Ice::Object
{
public:

    ::ARB::SessionPrx createSession(const ::std::string& name, const ::std::string& passwd, const ::ARB::ClientPrx& me, ::ARB::SessionErr& e)
    {
        return createSession(name, passwd, me, e, 0);
    }
    ::ARB::SessionPrx createSession(const ::std::string& name, const ::std::string& passwd, const ::ARB::ClientPrx& me, ::ARB::SessionErr& e, const ::Ice::Context& __ctx)
    {
        return createSession(name, passwd, me, e, &__ctx);
    }
    
private:

    ::ARB::SessionPrx createSession(const ::std::string&, const ::std::string&, const ::ARB::ClientPrx&, ::ARB::SessionErr&, const ::Ice::Context*);
    
public:
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

}

}

namespace IceDelegate
{

namespace ARB
{

class Client : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::ICSSW::ComponentPrx addServant(::ARB::Role, const ::Ice::Context*) = 0;

    virtual bool removeServant(const ::ICSSW::ComponentPrx&, const ::Ice::Context*) = 0;

    virtual ::ICSSW::ComponentPrx addServantWithNotify(::ARB::Role, const ::ICSSW::NotifierPrx&, const ::Ice::Context*) = 0;

    virtual ::ICSSW::NotifierPrx addNotifyServant(const ::Ice::Context*) = 0;

    virtual void removeNotifyServant(const ::ICSSW::NotifierPrx&, const ::Ice::Context*) = 0;

    virtual void shutdown(const ::Ice::Context*) = 0;
};

class Session : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::ICSSW::ComponentPrx createHandle(const ::std::string&, ::ARB::Role, ::ARB::HandleErr&, const ::Ice::Context*) = 0;

    virtual void closeHandle(const ::ICSSW::ComponentPrx&, const ::Ice::Context*) = 0;

    virtual void close(const ::Ice::Context*) = 0;
};

class Arbitrator : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::ARB::SessionPrx createSession(const ::std::string&, const ::std::string&, const ::ARB::ClientPrx&, ::ARB::SessionErr&, const ::Ice::Context*) = 0;
};

}

}

namespace IceDelegateM
{

namespace ARB
{

class Client : virtual public ::IceDelegate::ARB::Client,
               virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::ICSSW::ComponentPrx addServant(::ARB::Role, const ::Ice::Context*);

    virtual bool removeServant(const ::ICSSW::ComponentPrx&, const ::Ice::Context*);

    virtual ::ICSSW::ComponentPrx addServantWithNotify(::ARB::Role, const ::ICSSW::NotifierPrx&, const ::Ice::Context*);

    virtual ::ICSSW::NotifierPrx addNotifyServant(const ::Ice::Context*);

    virtual void removeNotifyServant(const ::ICSSW::NotifierPrx&, const ::Ice::Context*);

    virtual void shutdown(const ::Ice::Context*);
};

class Session : virtual public ::IceDelegate::ARB::Session,
                virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::ICSSW::ComponentPrx createHandle(const ::std::string&, ::ARB::Role, ::ARB::HandleErr&, const ::Ice::Context*);

    virtual void closeHandle(const ::ICSSW::ComponentPrx&, const ::Ice::Context*);

    virtual void close(const ::Ice::Context*);
};

class Arbitrator : virtual public ::IceDelegate::ARB::Arbitrator,
                   virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::ARB::SessionPrx createSession(const ::std::string&, const ::std::string&, const ::ARB::ClientPrx&, ::ARB::SessionErr&, const ::Ice::Context*);
};

}

}

namespace IceDelegateD
{

namespace ARB
{

class Client : virtual public ::IceDelegate::ARB::Client,
               virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::ICSSW::ComponentPrx addServant(::ARB::Role, const ::Ice::Context*);

    virtual bool removeServant(const ::ICSSW::ComponentPrx&, const ::Ice::Context*);

    virtual ::ICSSW::ComponentPrx addServantWithNotify(::ARB::Role, const ::ICSSW::NotifierPrx&, const ::Ice::Context*);

    virtual ::ICSSW::NotifierPrx addNotifyServant(const ::Ice::Context*);

    virtual void removeNotifyServant(const ::ICSSW::NotifierPrx&, const ::Ice::Context*);

    virtual void shutdown(const ::Ice::Context*);
};

class Session : virtual public ::IceDelegate::ARB::Session,
                virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::ICSSW::ComponentPrx createHandle(const ::std::string&, ::ARB::Role, ::ARB::HandleErr&, const ::Ice::Context*);

    virtual void closeHandle(const ::ICSSW::ComponentPrx&, const ::Ice::Context*);

    virtual void close(const ::Ice::Context*);
};

class Arbitrator : virtual public ::IceDelegate::ARB::Arbitrator,
                   virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::ARB::SessionPrx createSession(const ::std::string&, const ::std::string&, const ::ARB::ClientPrx&, ::ARB::SessionErr&, const ::Ice::Context*);
};

}

}

namespace ARB
{

class Client : virtual public ::Ice::Object
{
public:

    typedef ClientPrx ProxyType;
    typedef ClientPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::ICSSW::ComponentPrx addServant(::ARB::Role, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___addServant(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool removeServant(const ::ICSSW::ComponentPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___removeServant(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::ICSSW::ComponentPrx addServantWithNotify(::ARB::Role, const ::ICSSW::NotifierPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___addServantWithNotify(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::ICSSW::NotifierPrx addNotifyServant(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___addNotifyServant(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeNotifyServant(const ::ICSSW::NotifierPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___removeNotifyServant(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void shutdown(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___shutdown(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__ClientPtr(void*, ::Ice::ObjectPtr&);

class Session : virtual public ::Ice::Object
{
public:

    typedef SessionPrx ProxyType;
    typedef SessionPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::ICSSW::ComponentPrx createHandle(const ::std::string&, ::ARB::Role, ::ARB::HandleErr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___createHandle(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void closeHandle(const ::ICSSW::ComponentPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___closeHandle(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void close(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___close(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__SessionPtr(void*, ::Ice::ObjectPtr&);

class Arbitrator : virtual public ::Ice::Object
{
public:

    typedef ArbitratorPrx ProxyType;
    typedef ArbitratorPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::ARB::SessionPrx createSession(const ::std::string&, const ::std::string&, const ::ARB::ClientPrx&, ::ARB::SessionErr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___createSession(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__ArbitratorPtr(void*, ::Ice::ObjectPtr&);

}

#endif
