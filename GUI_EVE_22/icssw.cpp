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

#include <icssw.h>
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

static const ::std::string __ICSSW__Component__getName_name = "getName";

static const ::std::string __ICSSW__Notifier__notify_name = "notify";

void
IceInternal::incRef(::ICSSW::Component* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::ICSSW::Component* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::ICSSW::Component* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::ICSSW::Component* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::ICSSW::Notifier* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::ICSSW::Notifier* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::ICSSW::Notifier* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::ICSSW::Notifier* p)
{
    p->__decRef();
}

void
ICSSW::__write(::IceInternal::BasicStream* __os, const ::ICSSW::ComponentPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
ICSSW::__read(::IceInternal::BasicStream* __is, ::ICSSW::ComponentPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::ICSSW::Component;
        v->__copyFrom(proxy);
    }
}

void
ICSSW::__write(::IceInternal::BasicStream* __os, const ::ICSSW::ComponentPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
ICSSW::__write(::IceInternal::BasicStream* __os, const ::ICSSW::NotifierPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
ICSSW::__read(::IceInternal::BasicStream* __is, ::ICSSW::NotifierPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::ICSSW::Notifier;
        v->__copyFrom(proxy);
    }
}

void
ICSSW::__write(::IceInternal::BasicStream* __os, const ::ICSSW::NotifierPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

bool
ICSSW::Event::operator==(const Event& __rhs) const
{
    return !operator!=(__rhs);
}

bool
ICSSW::Event::operator!=(const Event& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(code != __rhs.code)
    {
        return true;
    }
    return false;
}

bool
ICSSW::Event::operator<(const Event& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(code < __rhs.code)
    {
        return true;
    }
    else if(__rhs.code < code)
    {
        return false;
    }
    return false;
}

void
ICSSW::Event::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(code);
}

void
ICSSW::Event::__read(::IceInternal::BasicStream* __is)
{
    __is->read(code);
}

void
ICSSW::__addObject(const ComponentPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
ICSSW::__usesClasses(const ComponentPtr& p)
{
    return p->__usesClasses();
}

void
ICSSW::__decRefUnsafe(const ComponentPtr& p)
{
    p->__decRefUnsafe();
}

void
ICSSW::__clearHandleUnsafe(ComponentPtr& p)
{
    p.__clearHandleUnsafe();
}

void
ICSSW::__addObject(const NotifierPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
ICSSW::__usesClasses(const NotifierPtr& p)
{
    return p->__usesClasses();
}

void
ICSSW::__decRefUnsafe(const NotifierPtr& p)
{
    p->__decRefUnsafe();
}

void
ICSSW::__clearHandleUnsafe(NotifierPtr& p)
{
    p.__clearHandleUnsafe();
}

::std::string
IceProxy::ICSSW::Component::getName(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__ICSSW__Component__getName_name);
            __delBase = __getDelegate();
            ::IceDelegate::ICSSW::Component* __del = dynamic_cast< ::IceDelegate::ICSSW::Component*>(__delBase.get());
            return __del->getName(__ctx);
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
IceProxy::ICSSW::Component::ice_staticId()
{
    return ::ICSSW::Component::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::ICSSW::Component::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::ICSSW::Component);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::ICSSW::Component::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::ICSSW::Component);
}

bool
IceProxy::ICSSW::operator==(const ::IceProxy::ICSSW::Component& l, const ::IceProxy::ICSSW::Component& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ICSSW::operator!=(const ::IceProxy::ICSSW::Component& l, const ::IceProxy::ICSSW::Component& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ICSSW::operator<(const ::IceProxy::ICSSW::Component& l, const ::IceProxy::ICSSW::Component& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ICSSW::operator<=(const ::IceProxy::ICSSW::Component& l, const ::IceProxy::ICSSW::Component& r)
{
    return l < r || l == r;
}

bool
IceProxy::ICSSW::operator>(const ::IceProxy::ICSSW::Component& l, const ::IceProxy::ICSSW::Component& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::ICSSW::operator>=(const ::IceProxy::ICSSW::Component& l, const ::IceProxy::ICSSW::Component& r)
{
    return !(l < r);
}

void
IceProxy::ICSSW::Notifier::notify(const ::ICSSW::Event& ev, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::ICSSW::Notifier* __del = dynamic_cast< ::IceDelegate::ICSSW::Notifier*>(__delBase.get());
            __del->notify(ev, __ctx);
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
IceProxy::ICSSW::Notifier::ice_staticId()
{
    return ::ICSSW::Notifier::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::ICSSW::Notifier::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::ICSSW::Notifier);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::ICSSW::Notifier::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::ICSSW::Notifier);
}

bool
IceProxy::ICSSW::operator==(const ::IceProxy::ICSSW::Notifier& l, const ::IceProxy::ICSSW::Notifier& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ICSSW::operator!=(const ::IceProxy::ICSSW::Notifier& l, const ::IceProxy::ICSSW::Notifier& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ICSSW::operator<(const ::IceProxy::ICSSW::Notifier& l, const ::IceProxy::ICSSW::Notifier& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::ICSSW::operator<=(const ::IceProxy::ICSSW::Notifier& l, const ::IceProxy::ICSSW::Notifier& r)
{
    return l < r || l == r;
}

bool
IceProxy::ICSSW::operator>(const ::IceProxy::ICSSW::Notifier& l, const ::IceProxy::ICSSW::Notifier& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::ICSSW::operator>=(const ::IceProxy::ICSSW::Notifier& l, const ::IceProxy::ICSSW::Notifier& r)
{
    return !(l < r);
}

::std::string
IceDelegateM::ICSSW::Component::getName(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __ICSSW__Component__getName_name, ::Ice::Normal, __context, __compress);
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
        ::std::string __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::ICSSW::Notifier::notify(const ::ICSSW::Event& ev, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __ICSSW__Notifier__notify_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        ev.__write(__os);
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

::std::string
IceDelegateD::ICSSW::Component::getName(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __ICSSW__Component__getName_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::std::string __ret;
        try
        {
            ::ICSSW::Component* __servant = dynamic_cast< ::ICSSW::Component*>(__direct.servant().get());
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
                __ret = __servant->getName(__current);
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
IceDelegateD::ICSSW::Notifier::notify(const ::ICSSW::Event& ev, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __ICSSW__Notifier__notify_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::ICSSW::Notifier* __servant = dynamic_cast< ::ICSSW::Notifier*>(__direct.servant().get());
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
                __servant->notify(ev, __current);
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

::Ice::ObjectPtr
ICSSW::Component::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __ICSSW__Component_ids[2] =
{
    "::ICSSW::Component",
    "::Ice::Object"
};

bool
ICSSW::Component::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__ICSSW__Component_ids, __ICSSW__Component_ids + 2, _s);
}

::std::vector< ::std::string>
ICSSW::Component::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__ICSSW__Component_ids[0], &__ICSSW__Component_ids[2]);
}

const ::std::string&
ICSSW::Component::ice_id(const ::Ice::Current&) const
{
    return __ICSSW__Component_ids[0];
}

const ::std::string&
ICSSW::Component::ice_staticId()
{
    return __ICSSW__Component_ids[0];
}

::IceInternal::DispatchStatus
ICSSW::Component::___getName(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string __ret = getName(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

static ::std::string __ICSSW__Component_all[] =
{
    "getName",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::IceInternal::DispatchStatus
ICSSW::Component::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__ICSSW__Component_all, __ICSSW__Component_all + 5, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __ICSSW__Component_all)
    {
        case 0:
        {
            return ___getName(in, current);
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
ICSSW::Component::__write(::IceInternal::BasicStream* __os) const
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
ICSSW::Component::__read(::IceInternal::BasicStream* __is, bool __rid)
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
ICSSW::Component::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type ICSSW::Component was not generated with stream support";
    throw ex;
}

void
ICSSW::Component::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type ICSSW::Component was not generated with stream support";
    throw ex;
}

void 
ICSSW::__patch__ComponentPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::ICSSW::ComponentPtr* p = static_cast< ::ICSSW::ComponentPtr*>(__addr);
    assert(p);
    *p = ::ICSSW::ComponentPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::ICSSW::Component::ice_staticId();
        throw e;
    }
}

bool
ICSSW::operator==(const ::ICSSW::Component& l, const ::ICSSW::Component& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
ICSSW::operator!=(const ::ICSSW::Component& l, const ::ICSSW::Component& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
ICSSW::operator<(const ::ICSSW::Component& l, const ::ICSSW::Component& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
ICSSW::operator<=(const ::ICSSW::Component& l, const ::ICSSW::Component& r)
{
    return l < r || l == r;
}

bool
ICSSW::operator>(const ::ICSSW::Component& l, const ::ICSSW::Component& r)
{
    return !(l < r) && !(l == r);
}

bool
ICSSW::operator>=(const ::ICSSW::Component& l, const ::ICSSW::Component& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
ICSSW::Notifier::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __ICSSW__Notifier_ids[2] =
{
    "::ICSSW::Notifier",
    "::Ice::Object"
};

bool
ICSSW::Notifier::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__ICSSW__Notifier_ids, __ICSSW__Notifier_ids + 2, _s);
}

::std::vector< ::std::string>
ICSSW::Notifier::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__ICSSW__Notifier_ids[0], &__ICSSW__Notifier_ids[2]);
}

const ::std::string&
ICSSW::Notifier::ice_id(const ::Ice::Current&) const
{
    return __ICSSW__Notifier_ids[0];
}

const ::std::string&
ICSSW::Notifier::ice_staticId()
{
    return __ICSSW__Notifier_ids[0];
}

::IceInternal::DispatchStatus
ICSSW::Notifier::___notify(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::ICSSW::Event ev;
    ev.__read(__is);
    notify(ev, __current);
    return ::IceInternal::DispatchOK;
}

static ::std::string __ICSSW__Notifier_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "notify"
};

::IceInternal::DispatchStatus
ICSSW::Notifier::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__ICSSW__Notifier_all, __ICSSW__Notifier_all + 5, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __ICSSW__Notifier_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___notify(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
ICSSW::Notifier::__write(::IceInternal::BasicStream* __os) const
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
ICSSW::Notifier::__read(::IceInternal::BasicStream* __is, bool __rid)
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
ICSSW::Notifier::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type ICSSW::Notifier was not generated with stream support";
    throw ex;
}

void
ICSSW::Notifier::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type ICSSW::Notifier was not generated with stream support";
    throw ex;
}

void 
ICSSW::__patch__NotifierPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::ICSSW::NotifierPtr* p = static_cast< ::ICSSW::NotifierPtr*>(__addr);
    assert(p);
    *p = ::ICSSW::NotifierPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::ICSSW::Notifier::ice_staticId();
        throw e;
    }
}

bool
ICSSW::operator==(const ::ICSSW::Notifier& l, const ::ICSSW::Notifier& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
ICSSW::operator!=(const ::ICSSW::Notifier& l, const ::ICSSW::Notifier& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
ICSSW::operator<(const ::ICSSW::Notifier& l, const ::ICSSW::Notifier& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
ICSSW::operator<=(const ::ICSSW::Notifier& l, const ::ICSSW::Notifier& r)
{
    return l < r || l == r;
}

bool
ICSSW::operator>(const ::ICSSW::Notifier& l, const ::ICSSW::Notifier& r)
{
    return !(l < r) && !(l == r);
}

bool
ICSSW::operator>=(const ::ICSSW::Notifier& l, const ::ICSSW::Notifier& r)
{
    return !(l < r);
}
