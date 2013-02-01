// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `icssw.ice'

#ifndef __icssw_h__
#define __icssw_h__

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

namespace ICSSW
{

class Component;
bool operator==(const Component&, const Component&);
bool operator!=(const Component&, const Component&);
bool operator<(const Component&, const Component&);
bool operator<=(const Component&, const Component&);
bool operator>(const Component&, const Component&);
bool operator>=(const Component&, const Component&);

class Notifier;
bool operator==(const Notifier&, const Notifier&);
bool operator!=(const Notifier&, const Notifier&);
bool operator<(const Notifier&, const Notifier&);
bool operator<=(const Notifier&, const Notifier&);
bool operator>(const Notifier&, const Notifier&);
bool operator>=(const Notifier&, const Notifier&);

}

}

namespace ICSSW
{

class Component;
bool operator==(const Component&, const Component&);
bool operator!=(const Component&, const Component&);
bool operator<(const Component&, const Component&);
bool operator<=(const Component&, const Component&);
bool operator>(const Component&, const Component&);
bool operator>=(const Component&, const Component&);

class Notifier;
bool operator==(const Notifier&, const Notifier&);
bool operator!=(const Notifier&, const Notifier&);
bool operator<(const Notifier&, const Notifier&);
bool operator<=(const Notifier&, const Notifier&);
bool operator>(const Notifier&, const Notifier&);
bool operator>=(const Notifier&, const Notifier&);

}

namespace IceInternal
{

void incRef(::ICSSW::Component*);
void decRef(::ICSSW::Component*);

void incRef(::IceProxy::ICSSW::Component*);
void decRef(::IceProxy::ICSSW::Component*);

void incRef(::ICSSW::Notifier*);
void decRef(::ICSSW::Notifier*);

void incRef(::IceProxy::ICSSW::Notifier*);
void decRef(::IceProxy::ICSSW::Notifier*);

}

namespace ICSSW
{

typedef ::IceInternal::Handle< ::ICSSW::Component> ComponentPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::ICSSW::Component> ComponentPrx;

void __write(::IceInternal::BasicStream*, const ComponentPrx&);
void __read(::IceInternal::BasicStream*, ComponentPrx&);
void __write(::IceInternal::BasicStream*, const ComponentPtr&);
void __patch__ComponentPtr(void*, ::Ice::ObjectPtr&);

void __addObject(const ComponentPtr&, ::IceInternal::GCCountMap&);
bool __usesClasses(const ComponentPtr&);
void __decRefUnsafe(const ComponentPtr&);
void __clearHandleUnsafe(ComponentPtr&);

typedef ::IceInternal::Handle< ::ICSSW::Notifier> NotifierPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::ICSSW::Notifier> NotifierPrx;

void __write(::IceInternal::BasicStream*, const NotifierPrx&);
void __read(::IceInternal::BasicStream*, NotifierPrx&);
void __write(::IceInternal::BasicStream*, const NotifierPtr&);
void __patch__NotifierPtr(void*, ::Ice::ObjectPtr&);

void __addObject(const NotifierPtr&, ::IceInternal::GCCountMap&);
bool __usesClasses(const NotifierPtr&);
void __decRefUnsafe(const NotifierPtr&);
void __clearHandleUnsafe(NotifierPtr&);

}

namespace ICSSW
{

struct Event
{
    ::Ice::Int code;

    bool operator==(const Event&) const;
    bool operator!=(const Event&) const;
    bool operator<(const Event&) const;
    bool operator<=(const Event& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const Event& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const Event& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

}

namespace IceProxy
{

namespace ICSSW
{

class Component : virtual public ::IceProxy::Ice::Object
{
public:

    ::std::string getName()
    {
        return getName(0);
    }
    ::std::string getName(const ::Ice::Context& __ctx)
    {
        return getName(&__ctx);
    }
    
private:

    ::std::string getName(const ::Ice::Context*);
    
public:
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class Notifier : virtual public ::IceProxy::Ice::Object
{
public:

    void notify(const ::ICSSW::Event& ev)
    {
        notify(ev, 0);
    }
    void notify(const ::ICSSW::Event& ev, const ::Ice::Context& __ctx)
    {
        notify(ev, &__ctx);
    }
    
private:

    void notify(const ::ICSSW::Event&, const ::Ice::Context*);
    
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

namespace ICSSW
{

class Component : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::std::string getName(const ::Ice::Context*) = 0;
};

class Notifier : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void notify(const ::ICSSW::Event&, const ::Ice::Context*) = 0;
};

}

}

namespace IceDelegateM
{

namespace ICSSW
{

class Component : virtual public ::IceDelegate::ICSSW::Component,
                  virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::std::string getName(const ::Ice::Context*);
};

class Notifier : virtual public ::IceDelegate::ICSSW::Notifier,
                 virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void notify(const ::ICSSW::Event&, const ::Ice::Context*);
};

}

}

namespace IceDelegateD
{

namespace ICSSW
{

class Component : virtual public ::IceDelegate::ICSSW::Component,
                  virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::std::string getName(const ::Ice::Context*);
};

class Notifier : virtual public ::IceDelegate::ICSSW::Notifier,
                 virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void notify(const ::ICSSW::Event&, const ::Ice::Context*);
};

}

}

namespace ICSSW
{

class Component : virtual public ::Ice::Object
{
public:

    typedef ComponentPrx ProxyType;
    typedef ComponentPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::std::string getName(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getName(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__ComponentPtr(void*, ::Ice::ObjectPtr&);

class Notifier : virtual public ::Ice::Object
{
public:

    typedef NotifierPrx ProxyType;
    typedef NotifierPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void notify(const ::ICSSW::Event&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___notify(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__NotifierPtr(void*, ::Ice::ObjectPtr&);

}

#endif
