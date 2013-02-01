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

#include <arb.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>
#include <IceUtil/ScopedArray.h>

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

static const ::std::string __ARB__Client__addServant_name = "addServant";

static const ::std::string __ARB__Client__removeServant_name = "removeServant";

static const ::std::string __ARB__Client__addServantWithNotify_name = "addServantWithNotify";

static const ::std::string __ARB__Client__addNotifyServant_name = "addNotifyServant";

static const ::std::string __ARB__Client__removeNotifyServant_name = "removeNotifyServant";

static const ::std::string __ARB__Client__shutdown_name = "shutdown";

static const ::std::string __ARB__Session__createHandle_name = "createHandle";

static const ::std::string __ARB__Session__closeHandle_name = "closeHandle";

static const ::std::string __ARB__Session__close_name = "close";

static const ::std::string __ARB__Arbitrator__createSession_name = "createSession";

void
IceInternal::incRef(::ARB::Client* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::ARB::Client* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::ARB::Client* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::ARB::Client* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::ARB::Session* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::ARB::Session* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::ARB::Session* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::ARB::Session* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::ARB::Arbitrator* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::ARB::Arbitrator* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::ARB::Arbitrator* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::ARB::Arbitrator* p)
{
    p->__decRef();
}

void
ARB::__write(::IceInternal::BasicStream* __os, const ::ARB::ClientPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
ARB::__read(::IceInternal::BasicStream* __is, ::ARB::ClientPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::ARB::Client;
        v->__copyFrom(proxy);
    }
}

void
ARB::__write(::IceInternal::BasicStream* __os, const ::ARB::ClientPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
ARB::__write(::IceInternal::BasicStream* __os, const ::ARB::SessionPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
ARB::__read(::IceInternal::BasicStream* __is, ::ARB::SessionPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::ARB::Session;
        v->__copyFrom(proxy);
    }
}

void
ARB::__write(::IceInternal::BasicStream* __os, const ::ARB::SessionPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
ARB::__write(::IceInternal::BasicStream* __os, const ::ARB::ArbitratorPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
ARB::__read(::IceInternal::BasicStream* __is, ::ARB::ArbitratorPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::ARB::Arbitrator;
        v->__copyFrom(proxy);
    }
}

void
ARB::__write(::IceInternal::BasicStream* __os, const ::ARB::ArbitratorPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
ARB::__write(::IceInternal::BasicStream* __os, ::ARB::Role v)
{
    __os->write(static_cast< ::Ice::Byte>(v));
}

void
ARB::__read(::IceInternal::BasicStream* __is, ::ARB::Role& v)
{
    ::Ice::Byte val;
    __is->read(val);
    v = static_cast< ::ARB::Role>(val);
}

void
ARB::__write(::IceInternal::BasicStream* __os, ::ARB::SessionErr v)
{
    __os->write(static_cast< ::Ice::Byte>(v));
}

void
ARB::__read(::IceInternal::BasicStream* __is, ::ARB::SessionErr& v)
{
    ::Ice::Byte val;
    __is->read(val);
    v = static_cast< ::ARB::SessionErr>(val);
}

void
ARB::__write(::IceInternal::BasicStream* __os, ::ARB::HandleErr v)
{
    __os->write(static_cast< ::Ice::Byte>(v));
}

void
ARB::__read(::IceInternal::BasicStream* __is, ::ARB::HandleErr& v)
{
    ::Ice::Byte val;
    __is->read(val);
    v = static_cast< ::ARB::HandleErr>(val);
}

void
ARB::__addObject(const ClientPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
ARB::__usesClasses(const ClientPtr& p)
{
    return p->__usesClasses();
}

void
ARB::__decRefUnsafe(const ClientPtr& p)
{
    p->__decRefUnsafe();
}

void
ARB::__clearHandleUnsafe(ClientPtr& p)
{
    p.__clearHandleUnsafe();
}

void
ARB::__addObject(const SessionPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
ARB::__usesClasses(const SessionPtr& p)
{
    return p->__usesClasses();
}

void
ARB::__decRefUnsafe(const SessionPtr& p)
{
    p->__decRefUnsafe();
}

void
ARB::__clearHandleUnsafe(SessionPtr& p)
{
    p.__clearHandleUnsafe();
}

void
ARB::__addObject(const ArbitratorPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
ARB::__usesClasses(const ArbitratorPtr& p)
{
    return p->__usesClasses();
}

void
ARB::__decRefUnsafe(const ArbitratorPtr& p)
{
    p->__decRefUnsafe();
}

void
ARB::__clearHandleUnsafe(ArbitratorPtr& p)
{
    p.__clearHandleUnsafe();
}

::ICSSW::ComponentPrx
IceProxy::ARB::Client::addServant(::ARB::Role attr, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__ARB__Client__addServant_name);
            __delBase = __getDelegate();
            ::IceDelegate::ARB::Client* __del = dynamic_cast< ::IceDelegate::ARB::Client*>(__delBase.get());
            return __del->addServant(attr, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

bool
IceProxy::ARB::Client::removeServant(const ::ICSSW::ComponentPrx& p, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__ARB__Client__removeServant_name);
            __delBase = __getDelegate();
            ::IceDelegate::ARB::Client* __del = dynamic_cast< ::IceDelegate::ARB::Client*>(__delBase.get());
            return __del->removeServant(p, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::ICSSW::ComponentPrx
IceProxy::ARB::Client::addServantWithNotify(::ARB::Role attr, const ::ICSSW::NotifierPrx& p, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__ARB__Client__addServantWithNotify_name);
            __delBase = __getDelegate();
            ::IceDelegate::ARB::Client* __del = dynamic_cast< ::IceDelegate::ARB::Client*>(__delBase.get());
            return __del->addServantWithNotify(attr, p, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::ICSSW::NotifierPrx
IceProxy::ARB::Client::addNotifyServant(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__ARB__Client__addNotifyServant_name);
            __delBase = __getDelegate();
            ::IceDelegate::ARB::Client* __del = dynamic_cast< ::IceDelegate::ARB::Client*>(__delBase.get());
            return __del->addNotifyServant(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::ARB::Client::removeNotifyServant(const ::ICSSW::NotifierPrx& p, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::ARB::Client* __del = dynamic_cast< ::IceDelegate::ARB::Client*>(__delBase.get());
            __del->removeNotifyServant(p, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::ARB::Client::shutdown(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::ARB::Client* __del = dynamic_cast< ::IceDelegate::ARB::Client*>(__delBase.get());
            __del->shutdown(__ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::ARB::Client::ice_staticId()
{
    return ::ARB::Client::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::ARB::Client::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::ARB::Client);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::ARB::Client::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::ARB::Client);
}

bool
IceProxy::ARB::operator==(const ::IceProxy::ARB::Client& l, const ::IceProxy::ARB::Client& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ARB::operator!=(const ::IceProxy::ARB::Client& l, const ::IceProxy::ARB::Client& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ARB::operator<(const ::IceProxy::ARB::Client& l, const ::IceProxy::ARB::Client& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ARB::operator<=(const ::IceProxy::ARB::Client& l, const ::IceProxy::ARB::Client& r)
{
    return l < r || l == r;
}

bool
IceProxy::ARB::operator>(const ::IceProxy::ARB::Client& l, const ::IceProxy::ARB::Client& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::ARB::operator>=(const ::IceProxy::ARB::Client& l, const ::IceProxy::ARB::Client& r)
{
    return !(l < r);
}

::ICSSW::ComponentPrx
IceProxy::ARB::Session::createHandle(const ::std::string& name, ::ARB::Role attr, ::ARB::HandleErr& e, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__ARB__Session__createHandle_name);
            __delBase = __getDelegate();
            ::IceDelegate::ARB::Session* __del = dynamic_cast< ::IceDelegate::ARB::Session*>(__delBase.get());
            return __del->createHandle(name, attr, e, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::ARB::Session::closeHandle(const ::ICSSW::ComponentPrx& proxy, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::ARB::Session* __del = dynamic_cast< ::IceDelegate::ARB::Session*>(__delBase.get());
            __del->closeHandle(proxy, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::ARB::Session::close(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::ARB::Session* __del = dynamic_cast< ::IceDelegate::ARB::Session*>(__delBase.get());
            __del->close(__ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::ARB::Session::ice_staticId()
{
    return ::ARB::Session::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::ARB::Session::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::ARB::Session);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::ARB::Session::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::ARB::Session);
}

bool
IceProxy::ARB::operator==(const ::IceProxy::ARB::Session& l, const ::IceProxy::ARB::Session& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ARB::operator!=(const ::IceProxy::ARB::Session& l, const ::IceProxy::ARB::Session& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ARB::operator<(const ::IceProxy::ARB::Session& l, const ::IceProxy::ARB::Session& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ARB::operator<=(const ::IceProxy::ARB::Session& l, const ::IceProxy::ARB::Session& r)
{
    return l < r || l == r;
}

bool
IceProxy::ARB::operator>(const ::IceProxy::ARB::Session& l, const ::IceProxy::ARB::Session& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::ARB::operator>=(const ::IceProxy::ARB::Session& l, const ::IceProxy::ARB::Session& r)
{
    return !(l < r);
}

::ARB::SessionPrx
IceProxy::ARB::Arbitrator::createSession(const ::std::string& name, const ::std::string& passwd, const ::ARB::ClientPrx& me, ::ARB::SessionErr& e, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__ARB__Arbitrator__createSession_name);
            __delBase = __getDelegate();
            ::IceDelegate::ARB::Arbitrator* __del = dynamic_cast< ::IceDelegate::ARB::Arbitrator*>(__delBase.get());
            return __del->createSession(name, passwd, me, e, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::ARB::Arbitrator::ice_staticId()
{
    return ::ARB::Arbitrator::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::ARB::Arbitrator::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::ARB::Arbitrator);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::ARB::Arbitrator::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::ARB::Arbitrator);
}

bool
IceProxy::ARB::operator==(const ::IceProxy::ARB::Arbitrator& l, const ::IceProxy::ARB::Arbitrator& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ARB::operator!=(const ::IceProxy::ARB::Arbitrator& l, const ::IceProxy::ARB::Arbitrator& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ARB::operator<(const ::IceProxy::ARB::Arbitrator& l, const ::IceProxy::ARB::Arbitrator& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ARB::operator<=(const ::IceProxy::ARB::Arbitrator& l, const ::IceProxy::ARB::Arbitrator& r)
{
    return l < r || l == r;
}

bool
IceProxy::ARB::operator>(const ::IceProxy::ARB::Arbitrator& l, const ::IceProxy::ARB::Arbitrator& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::ARB::operator>=(const ::IceProxy::ARB::Arbitrator& l, const ::IceProxy::ARB::Arbitrator& r)
{
    return !(l < r);
}

::ICSSW::ComponentPrx
IceDelegateM::ARB::Client::addServant(::ARB::Role attr, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __ARB__Client__addServant_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        ::ARB::__write(__os, attr);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::ICSSW::ComponentPrx __ret;
        ::ICSSW::__read(__is, __ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

bool
IceDelegateM::ARB::Client::removeServant(const ::ICSSW::ComponentPrx& p, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __ARB__Client__removeServant_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        ::ICSSW::__write(__os, p);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        bool __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::ICSSW::ComponentPrx
IceDelegateM::ARB::Client::addServantWithNotify(::ARB::Role attr, const ::ICSSW::NotifierPrx& p, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __ARB__Client__addServantWithNotify_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        ::ARB::__write(__os, attr);
        ::ICSSW::__write(__os, p);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::ICSSW::ComponentPrx __ret;
        ::ICSSW::__read(__is, __ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::ICSSW::NotifierPrx
IceDelegateM::ARB::Client::addNotifyServant(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __ARB__Client__addNotifyServant_name, ::Ice::Normal, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::ICSSW::NotifierPrx __ret;
        ::ICSSW::__read(__is, __ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::ARB::Client::removeNotifyServant(const ::ICSSW::NotifierPrx& p, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __ARB__Client__removeNotifyServant_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        ::ICSSW::__write(__os, p);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::ARB::Client::shutdown(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __ARB__Client__shutdown_name, ::Ice::Normal, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::ICSSW::ComponentPrx
IceDelegateM::ARB::Session::createHandle(const ::std::string& name, ::ARB::Role attr, ::ARB::HandleErr& e, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __ARB__Session__createHandle_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
        ::ARB::__write(__os, attr);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::ICSSW::ComponentPrx __ret;
        ::ARB::__read(__is, e);
        ::ICSSW::__read(__is, __ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::ARB::Session::closeHandle(const ::ICSSW::ComponentPrx& proxy, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __ARB__Session__closeHandle_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        ::ICSSW::__write(__os, proxy);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::ARB::Session::close(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __ARB__Session__close_name, ::Ice::Normal, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::ARB::SessionPrx
IceDelegateM::ARB::Arbitrator::createSession(const ::std::string& name, const ::std::string& passwd, const ::ARB::ClientPrx& me, ::ARB::SessionErr& e, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __ARB__Arbitrator__createSession_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
        __os->write(passwd);
        ::ARB::__write(__os, me);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::ARB::SessionPrx __ret;
        ::ARB::__read(__is, e);
        ::ARB::__read(__is, __ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::ICSSW::ComponentPrx
IceDelegateD::ARB::Client::addServant(::ARB::Role attr, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __ARB__Client__addServant_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::ICSSW::ComponentPrx __ret;
        try
        {
            ::ARB::Client* __servant = dynamic_cast< ::ARB::Client*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->addServant(attr, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

bool
IceDelegateD::ARB::Client::removeServant(const ::ICSSW::ComponentPrx& p, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __ARB__Client__removeServant_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        bool __ret;
        try
        {
            ::ARB::Client* __servant = dynamic_cast< ::ARB::Client*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->removeServant(p, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::ICSSW::ComponentPrx
IceDelegateD::ARB::Client::addServantWithNotify(::ARB::Role attr, const ::ICSSW::NotifierPrx& p, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __ARB__Client__addServantWithNotify_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::ICSSW::ComponentPrx __ret;
        try
        {
            ::ARB::Client* __servant = dynamic_cast< ::ARB::Client*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->addServantWithNotify(attr, p, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::ICSSW::NotifierPrx
IceDelegateD::ARB::Client::addNotifyServant(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __ARB__Client__addNotifyServant_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::ICSSW::NotifierPrx __ret;
        try
        {
            ::ARB::Client* __servant = dynamic_cast< ::ARB::Client*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->addNotifyServant(__current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::ARB::Client::removeNotifyServant(const ::ICSSW::NotifierPrx& p, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __ARB__Client__removeNotifyServant_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::ARB::Client* __servant = dynamic_cast< ::ARB::Client*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->removeNotifyServant(p, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::ARB::Client::shutdown(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __ARB__Client__shutdown_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::ARB::Client* __servant = dynamic_cast< ::ARB::Client*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->shutdown(__current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::ICSSW::ComponentPrx
IceDelegateD::ARB::Session::createHandle(const ::std::string& name, ::ARB::Role attr, ::ARB::HandleErr& e, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __ARB__Session__createHandle_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::ICSSW::ComponentPrx __ret;
        try
        {
            ::ARB::Session* __servant = dynamic_cast< ::ARB::Session*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->createHandle(name, attr, e, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::ARB::Session::closeHandle(const ::ICSSW::ComponentPrx& proxy, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __ARB__Session__closeHandle_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::ARB::Session* __servant = dynamic_cast< ::ARB::Session*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->closeHandle(proxy, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::ARB::Session::close(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __ARB__Session__close_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::ARB::Session* __servant = dynamic_cast< ::ARB::Session*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->close(__current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::ARB::SessionPrx
IceDelegateD::ARB::Arbitrator::createSession(const ::std::string& name, const ::std::string& passwd, const ::ARB::ClientPrx& me, ::ARB::SessionErr& e, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __ARB__Arbitrator__createSession_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::ARB::SessionPrx __ret;
        try
        {
            ::ARB::Arbitrator* __servant = dynamic_cast< ::ARB::Arbitrator*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->createSession(name, passwd, me, e, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Ice::ObjectPtr
ARB::Client::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __ARB__Client_ids[2] =
{
    "::ARB::Client",
    "::Ice::Object"
};

bool
ARB::Client::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__ARB__Client_ids, __ARB__Client_ids + 2, _s);
}

::std::vector< ::std::string>
ARB::Client::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__ARB__Client_ids[0], &__ARB__Client_ids[2]);
}

const ::std::string&
ARB::Client::ice_id(const ::Ice::Current&) const
{
    return __ARB__Client_ids[0];
}

const ::std::string&
ARB::Client::ice_staticId()
{
    return __ARB__Client_ids[0];
}

::IceInternal::DispatchStatus
ARB::Client::___addServant(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::ARB::Role attr;
    ::ARB::__read(__is, attr);
    ::ICSSW::ComponentPrx __ret = addServant(attr, __current);
    ::ICSSW::__write(__os, __ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
ARB::Client::___removeServant(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::ICSSW::ComponentPrx p;
    ::ICSSW::__read(__is, p);
    bool __ret = removeServant(p, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
ARB::Client::___addServantWithNotify(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::ARB::Role attr;
    ::ICSSW::NotifierPrx p;
    ::ARB::__read(__is, attr);
    ::ICSSW::__read(__is, p);
    ::ICSSW::ComponentPrx __ret = addServantWithNotify(attr, p, __current);
    ::ICSSW::__write(__os, __ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
ARB::Client::___addNotifyServant(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::ICSSW::NotifierPrx __ret = addNotifyServant(__current);
    ::ICSSW::__write(__os, __ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
ARB::Client::___removeNotifyServant(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::ICSSW::NotifierPrx p;
    ::ICSSW::__read(__is, p);
    removeNotifyServant(p, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
ARB::Client::___shutdown(::IceInternal::Incoming&, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    shutdown(__current);
    return ::IceInternal::DispatchOK;
}

static ::std::string __ARB__Client_all[] =
{
    "addNotifyServant",
    "addServant",
    "addServantWithNotify",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "removeNotifyServant",
    "removeServant",
    "shutdown"
};

::IceInternal::DispatchStatus
ARB::Client::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__ARB__Client_all, __ARB__Client_all + 10, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __ARB__Client_all)
    {
        case 0:
        {
            return ___addNotifyServant(in, current);
        }
        case 1:
        {
            return ___addServant(in, current);
        }
        case 2:
        {
            return ___addServantWithNotify(in, current);
        }
        case 3:
        {
            return ___ice_id(in, current);
        }
        case 4:
        {
            return ___ice_ids(in, current);
        }
        case 5:
        {
            return ___ice_isA(in, current);
        }
        case 6:
        {
            return ___ice_ping(in, current);
        }
        case 7:
        {
            return ___removeNotifyServant(in, current);
        }
        case 8:
        {
            return ___removeServant(in, current);
        }
        case 9:
        {
            return ___shutdown(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
ARB::Client::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
ARB::Client::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
ARB::Client::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type ARB::Client was not generated with stream support";
    throw ex;
}

void
ARB::Client::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type ARB::Client was not generated with stream support";
    throw ex;
}

void 
ARB::__patch__ClientPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::ARB::ClientPtr* p = static_cast< ::ARB::ClientPtr*>(__addr);
    assert(p);
    *p = ::ARB::ClientPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::ARB::Client::ice_staticId();
        throw e;
    }
}

bool
ARB::operator==(const ::ARB::Client& l, const ::ARB::Client& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
ARB::operator!=(const ::ARB::Client& l, const ::ARB::Client& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
ARB::operator<(const ::ARB::Client& l, const ::ARB::Client& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
ARB::operator<=(const ::ARB::Client& l, const ::ARB::Client& r)
{
    return l < r || l == r;
}

bool
ARB::operator>(const ::ARB::Client& l, const ::ARB::Client& r)
{
    return !(l < r) && !(l == r);
}

bool
ARB::operator>=(const ::ARB::Client& l, const ::ARB::Client& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
ARB::Session::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __ARB__Session_ids[2] =
{
    "::ARB::Session",
    "::Ice::Object"
};

bool
ARB::Session::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__ARB__Session_ids, __ARB__Session_ids + 2, _s);
}

::std::vector< ::std::string>
ARB::Session::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__ARB__Session_ids[0], &__ARB__Session_ids[2]);
}

const ::std::string&
ARB::Session::ice_id(const ::Ice::Current&) const
{
    return __ARB__Session_ids[0];
}

const ::std::string&
ARB::Session::ice_staticId()
{
    return __ARB__Session_ids[0];
}

::IceInternal::DispatchStatus
ARB::Session::___createHandle(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string name;
    ::ARB::Role attr;
    __is->read(name);
    ::ARB::__read(__is, attr);
    ::ARB::HandleErr e;
    ::ICSSW::ComponentPrx __ret = createHandle(name, attr, e, __current);
    ::ARB::__write(__os, e);
    ::ICSSW::__write(__os, __ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
ARB::Session::___closeHandle(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::ICSSW::ComponentPrx proxy;
    ::ICSSW::__read(__is, proxy);
    closeHandle(proxy, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
ARB::Session::___close(::IceInternal::Incoming&, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    close(__current);
    return ::IceInternal::DispatchOK;
}

static ::std::string __ARB__Session_all[] =
{
    "close",
    "closeHandle",
    "createHandle",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::IceInternal::DispatchStatus
ARB::Session::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__ARB__Session_all, __ARB__Session_all + 7, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __ARB__Session_all)
    {
        case 0:
        {
            return ___close(in, current);
        }
        case 1:
        {
            return ___closeHandle(in, current);
        }
        case 2:
        {
            return ___createHandle(in, current);
        }
        case 3:
        {
            return ___ice_id(in, current);
        }
        case 4:
        {
            return ___ice_ids(in, current);
        }
        case 5:
        {
            return ___ice_isA(in, current);
        }
        case 6:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
ARB::Session::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
ARB::Session::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
ARB::Session::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type ARB::Session was not generated with stream support";
    throw ex;
}

void
ARB::Session::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type ARB::Session was not generated with stream support";
    throw ex;
}

void 
ARB::__patch__SessionPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::ARB::SessionPtr* p = static_cast< ::ARB::SessionPtr*>(__addr);
    assert(p);
    *p = ::ARB::SessionPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::ARB::Session::ice_staticId();
        throw e;
    }
}

bool
ARB::operator==(const ::ARB::Session& l, const ::ARB::Session& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
ARB::operator!=(const ::ARB::Session& l, const ::ARB::Session& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
ARB::operator<(const ::ARB::Session& l, const ::ARB::Session& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
ARB::operator<=(const ::ARB::Session& l, const ::ARB::Session& r)
{
    return l < r || l == r;
}

bool
ARB::operator>(const ::ARB::Session& l, const ::ARB::Session& r)
{
    return !(l < r) && !(l == r);
}

bool
ARB::operator>=(const ::ARB::Session& l, const ::ARB::Session& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
ARB::Arbitrator::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __ARB__Arbitrator_ids[2] =
{
    "::ARB::Arbitrator",
    "::Ice::Object"
};

bool
ARB::Arbitrator::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__ARB__Arbitrator_ids, __ARB__Arbitrator_ids + 2, _s);
}

::std::vector< ::std::string>
ARB::Arbitrator::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__ARB__Arbitrator_ids[0], &__ARB__Arbitrator_ids[2]);
}

const ::std::string&
ARB::Arbitrator::ice_id(const ::Ice::Current&) const
{
    return __ARB__Arbitrator_ids[0];
}

const ::std::string&
ARB::Arbitrator::ice_staticId()
{
    return __ARB__Arbitrator_ids[0];
}

::IceInternal::DispatchStatus
ARB::Arbitrator::___createSession(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string name;
    ::std::string passwd;
    ::ARB::ClientPrx me;
    __is->read(name);
    __is->read(passwd);
    ::ARB::__read(__is, me);
    ::ARB::SessionErr e;
    ::ARB::SessionPrx __ret = createSession(name, passwd, me, e, __current);
    ::ARB::__write(__os, e);
    ::ARB::__write(__os, __ret);
    return ::IceInternal::DispatchOK;
}

static ::std::string __ARB__Arbitrator_all[] =
{
    "createSession",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::IceInternal::DispatchStatus
ARB::Arbitrator::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__ARB__Arbitrator_all, __ARB__Arbitrator_all + 5, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __ARB__Arbitrator_all)
    {
        case 0:
        {
            return ___createSession(in, current);
        }
        case 1:
        {
            return ___ice_id(in, current);
        }
        case 2:
        {
            return ___ice_ids(in, current);
        }
        case 3:
        {
            return ___ice_isA(in, current);
        }
        case 4:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
ARB::Arbitrator::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
ARB::Arbitrator::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
ARB::Arbitrator::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type ARB::Arbitrator was not generated with stream support";
    throw ex;
}

void
ARB::Arbitrator::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type ARB::Arbitrator was not generated with stream support";
    throw ex;
}

void 
ARB::__patch__ArbitratorPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::ARB::ArbitratorPtr* p = static_cast< ::ARB::ArbitratorPtr*>(__addr);
    assert(p);
    *p = ::ARB::ArbitratorPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::ARB::Arbitrator::ice_staticId();
        throw e;
    }
}

bool
ARB::operator==(const ::ARB::Arbitrator& l, const ::ARB::Arbitrator& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
ARB::operator!=(const ::ARB::Arbitrator& l, const ::ARB::Arbitrator& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
ARB::operator<(const ::ARB::Arbitrator& l, const ::ARB::Arbitrator& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
ARB::operator<=(const ::ARB::Arbitrator& l, const ::ARB::Arbitrator& r)
{
    return l < r || l == r;
}

bool
ARB::operator>(const ::ARB::Arbitrator& l, const ::ARB::Arbitrator& r)
{
    return !(l < r) && !(l == r);
}

bool
ARB::operator>=(const ::ARB::Arbitrator& l, const ::ARB::Arbitrator& r)
{
    return !(l < r);
}
