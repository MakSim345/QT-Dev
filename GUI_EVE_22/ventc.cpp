// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `ventc.ice'

#include <ventc.h>
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

static const ::std::string __VENTC__VentComponentRO__getComPortSpeed_name = "getComPortSpeed";

static const ::std::string __VENTC__VentComponentRW__OnConnect_name = "OnConnect";

static const ::std::string __VENTC__VentComponentRW__OnRunVentilation_name = "OnRunVentilation";

static const ::std::string __VENTC__VentComponentRW__OnDestroy_name = "OnDestroy";

static const ::std::string __VENTC__VentComponentRW__isEmpty_name = "isEmpty";

static const ::std::string __VENTC__VentComponentRW__getMsgFromStore_name = "getMsgFromStore";

static const ::std::string __VENTC__VentComponentRW__setComPortSpeed_name = "setComPortSpeed";

static const ::std::string __VENTC__VentComponentRW__getComPortSpeed_name = "getComPortSpeed";

static const ::std::string __VENTC__VentComponentRW__setComPortNumber_name = "setComPortNumber";

static const ::std::string __VENTC__VentComponentRW__getComPortNumber_name = "getComPortNumber";

static const ::std::string __VENTC__VentComponentRW__setRecBytes_name = "setRecBytes";

static const ::std::string __VENTC__VentComponentRW__getRecBytes_name = "getRecBytes";

static const ::std::string __VENTC__VentComponentRW__setSentBytes_name = "setSentBytes";

static const ::std::string __VENTC__VentComponentRW__getSentBytes_name = "getSentBytes";

static const ::std::string __VENTC__VentComponentRW__setTimeONVal_name = "setTimeONVal";

static const ::std::string __VENTC__VentComponentRW__getTimeONVal_name = "getTimeONVal";

static const ::std::string __VENTC__VentComponentRW__setTimeOFFVal_name = "setTimeOFFVal";

static const ::std::string __VENTC__VentComponentRW__getTimeOFFVal_name = "getTimeOFFVal";

static const ::std::string __VENTC__VentComponentRW__setChkBxAIRVLVCNTRL_name = "setChkBxAIRVLVCNTRL";

static const ::std::string __VENTC__VentComponentRW__getChkBxAIRVLVCNTRL_name = "getChkBxAIRVLVCNTRL";

static const ::std::string __VENTC__VentComponentRW__setChkBxEXHVLVCNTRL_name = "setChkBxEXHVLVCNTRL";

static const ::std::string __VENTC__VentComponentRW__getChkBxEXHVLVCNTRL_name = "getChkBxEXHVLVCNTRL";

static const ::std::string __VENTC__VentComponentRW__setChkBxFSPWREN_name = "setChkBxFSPWREN";

static const ::std::string __VENTC__VentComponentRW__getChkBxFSPWREN_name = "getChkBxFSPWREN";

static const ::std::string __VENTC__VentComponentRW__setChkBxILIMPSMEN_name = "setChkBxILIMPSMEN";

static const ::std::string __VENTC__VentComponentRW__getChkBxILIMPSMEN_name = "getChkBxILIMPSMEN";

static const ::std::string __VENTC__VentComponentRW__setChkBxILIMMODEN_name = "setChkBxILIMMODEN";

static const ::std::string __VENTC__VentComponentRW__getChkBxILIMMODEN_name = "getChkBxILIMMODEN";

static const ::std::string __VENTC__VentComponentRW__setChkBxMNVROPEN_name = "setChkBxMNVROPEN";

static const ::std::string __VENTC__VentComponentRW__getChkBxMNVROPEN_name = "getChkBxMNVROPEN";

static const ::std::string __VENTC__VentComponentRW__setChkBxO2VLVCNTRL_name = "setChkBxO2VLVCNTRL";

static const ::std::string __VENTC__VentComponentRW__getChkBxO2VLVCNTRL_name = "getChkBxO2VLVCNTRL";

static const ::std::string __VENTC__VentComponentRW__setChkBxOKTOZERO_name = "setChkBxOKTOZERO";

static const ::std::string __VENTC__VentComponentRW__getChkBxOKTOZERO_name = "getChkBxOKTOZERO";

static const ::std::string __VENTC__VentComponentRW__setChkBxSAFECLS_name = "setChkBxSAFECLS";

static const ::std::string __VENTC__VentComponentRW__getChkBxSAFECLS_name = "getChkBxSAFECLS";

static const ::std::string __VENTC__VentComponentRW__setChkBxZEROAUXPEN_name = "setChkBxZEROAUXPEN";

static const ::std::string __VENTC__VentComponentRW__getChkBxZEROAUXPEN_name = "getChkBxZEROAUXPEN";

static const ::std::string __VENTC__VentComponentRW__setChkBxZEROINSPEN_name = "setChkBxZEROINSPEN";

static const ::std::string __VENTC__VentComponentRW__getChkBxZEROINSPEN_name = "getChkBxZEROINSPEN";

static const ::std::string __VENTC__VentComponentRW__setChkBxVCBUZZERON_name = "setChkBxVCBUZZERON";

static const ::std::string __VENTC__VentComponentRW__getChkBxVCBUZZERON_name = "getChkBxVCBUZZERON";

static const ::std::string __VENTC__VentComponentRW__setO2DAC_name = "setO2DAC";

static const ::std::string __VENTC__VentComponentRW__getO2DAC_name = "getO2DAC";

static const ::std::string __VENTC__VentComponentRW__setO2Percents_name = "setO2Percents";

static const ::std::string __VENTC__VentComponentRW__getO2Percents_name = "getO2Percents";

static const ::std::string __VENTC__VentComponentRW__setTotalFlowResult_name = "setTotalFlowResult";

static const ::std::string __VENTC__VentComponentRW__getTotalFlowResult_name = "getTotalFlowResult";

static const ::std::string __VENTC__VentComponentRW__setTotalFlow_name = "setTotalFlow";

static const ::std::string __VENTC__VentComponentRW__getTotalFlow_name = "getTotalFlow";

static const ::std::string __VENTC__VentComponentRW__setAirFlow_name = "setAirFlow";

static const ::std::string __VENTC__VentComponentRW__getAirFlow_name = "getAirFlow";

static const ::std::string __VENTC__VentComponentRW__setAirDAC_name = "setAirDAC";

static const ::std::string __VENTC__VentComponentRW__getAirDAC_name = "getAirDAC";

static const ::std::string __VENTC__VentComponentRW__setExhalFlow_name = "setExhalFlow";

static const ::std::string __VENTC__VentComponentRW__getExhalFlow_name = "getExhalFlow";

static const ::std::string __VENTC__VentComponentRW__setExhalFlow2_name = "setExhalFlow2";

static const ::std::string __VENTC__VentComponentRW__getExhalFlow2_name = "getExhalFlow2";

static const ::std::string __VENTC__VentComponentRW__setExhDAC_name = "setExhDAC";

static const ::std::string __VENTC__VentComponentRW__getExhDAC_name = "getExhDAC";

static const ::std::string __VENTC__VentComponentRW__setDitherDAC_name = "setDitherDAC";

static const ::std::string __VENTC__VentComponentRW__getDitherDAC_name = "getDitherDAC";

static const ::std::string __VENTC__VentComponentRW__setOxigFlow_name = "setOxigFlow";

static const ::std::string __VENTC__VentComponentRW__getOxigFlow_name = "getOxigFlow";

static const ::std::string __VENTC__VentComponentRW__setOCTemp_name = "setOCTemp";

static const ::std::string __VENTC__VentComponentRW__getOCTemp_name = "getOCTemp";

static const ::std::string __VENTC__VentComponentRW__setTCTemp_name = "setTCTemp";

static const ::std::string __VENTC__VentComponentRW__getTCTemp_name = "getTCTemp";

static const ::std::string __VENTC__VentComponentRW__setACTemp_name = "setACTemp";

static const ::std::string __VENTC__VentComponentRW__getACTemp_name = "getACTemp";

static const ::std::string __VENTC__VentComponentRW__setO2Comp_name = "setO2Comp";

static const ::std::string __VENTC__VentComponentRW__getO2Comp_name = "getO2Comp";

static const ::std::string __VENTC__VentComponentRW__setCPULoad_name = "setCPULoad";

static const ::std::string __VENTC__VentComponentRW__getCPULoad_name = "getCPULoad";

static const ::std::string __VENTC__VentComponentRW__enableBtnRunVent_name = "enableBtnRunVent";

static const ::std::string __VENTC__VentComponentRW__enableBtnConnect_name = "enableBtnConnect";

void
IceInternal::incRef(::VENTC::VentComponentRO* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::VENTC::VentComponentRO* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::VENTC::VentComponentRO* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::VENTC::VentComponentRO* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::VENTC::VentComponentRW* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::VENTC::VentComponentRW* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::VENTC::VentComponentRW* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::VENTC::VentComponentRW* p)
{
    p->__decRef();
}

void
VENTC::__write(::IceInternal::BasicStream* __os, const ::VENTC::VentComponentROPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
VENTC::__read(::IceInternal::BasicStream* __is, ::VENTC::VentComponentROPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::VENTC::VentComponentRO;
        v->__copyFrom(proxy);
    }
}

void
VENTC::__write(::IceInternal::BasicStream* __os, const ::VENTC::VentComponentROPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
VENTC::__write(::IceInternal::BasicStream* __os, const ::VENTC::VentComponentRWPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
VENTC::__read(::IceInternal::BasicStream* __is, ::VENTC::VentComponentRWPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::VENTC::VentComponentRW;
        v->__copyFrom(proxy);
    }
}

void
VENTC::__write(::IceInternal::BasicStream* __os, const ::VENTC::VentComponentRWPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
VENTC::__addObject(const VentComponentROPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
VENTC::__usesClasses(const VentComponentROPtr& p)
{
    return p->__usesClasses();
}

void
VENTC::__decRefUnsafe(const VentComponentROPtr& p)
{
    p->__decRefUnsafe();
}

void
VENTC::__clearHandleUnsafe(VentComponentROPtr& p)
{
    p.__clearHandleUnsafe();
}

void
VENTC::__addObject(const VentComponentRWPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
VENTC::__usesClasses(const VentComponentRWPtr& p)
{
    return p->__usesClasses();
}

void
VENTC::__decRefUnsafe(const VentComponentRWPtr& p)
{
    p->__decRefUnsafe();
}

void
VENTC::__clearHandleUnsafe(VentComponentRWPtr& p)
{
    p.__clearHandleUnsafe();
}

::Ice::Int
IceProxy::VENTC::VentComponentRO::getComPortSpeed(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRO__getComPortSpeed_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRO* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRO*>(__delBase.get());
            return __del->getComPortSpeed(__ctx);
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
IceProxy::VENTC::VentComponentRO::ice_staticId()
{
    return ::VENTC::VentComponentRO::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::VENTC::VentComponentRO::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::VENTC::VentComponentRO);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::VENTC::VentComponentRO::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::VENTC::VentComponentRO);
}

bool
IceProxy::VENTC::operator==(const ::IceProxy::VENTC::VentComponentRO& l, const ::IceProxy::VENTC::VentComponentRO& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::VENTC::operator!=(const ::IceProxy::VENTC::VentComponentRO& l, const ::IceProxy::VENTC::VentComponentRO& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::VENTC::operator<(const ::IceProxy::VENTC::VentComponentRO& l, const ::IceProxy::VENTC::VentComponentRO& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::VENTC::operator<=(const ::IceProxy::VENTC::VentComponentRO& l, const ::IceProxy::VENTC::VentComponentRO& r)
{
    return l < r || l == r;
}

bool
IceProxy::VENTC::operator>(const ::IceProxy::VENTC::VentComponentRO& l, const ::IceProxy::VENTC::VentComponentRO& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::VENTC::operator>=(const ::IceProxy::VENTC::VentComponentRO& l, const ::IceProxy::VENTC::VentComponentRO& r)
{
    return !(l < r);
}

void
IceProxy::VENTC::VentComponentRW::OnConnect(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->OnConnect(__ctx);
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
IceProxy::VENTC::VentComponentRW::OnRunVentilation(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->OnRunVentilation(__ctx);
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
IceProxy::VENTC::VentComponentRW::OnDestroy(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->OnDestroy(__ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::isEmpty(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__isEmpty_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->isEmpty(__ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getMsgFromStore(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getMsgFromStore_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getMsgFromStore(__ctx);
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
IceProxy::VENTC::VentComponentRW::setComPortSpeed(::Ice::Int nComPortSpeed, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setComPortSpeed(nComPortSpeed, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getComPortSpeed(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getComPortSpeed_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getComPortSpeed(__ctx);
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
IceProxy::VENTC::VentComponentRW::setComPortNumber(::Ice::Int nComPortNumber, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setComPortNumber(nComPortNumber, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getComPortNumber(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getComPortNumber_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getComPortNumber(__ctx);
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
IceProxy::VENTC::VentComponentRW::setRecBytes(::Ice::Int nRecBytes, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setRecBytes(nRecBytes, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getRecBytes(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getRecBytes_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getRecBytes(__ctx);
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
IceProxy::VENTC::VentComponentRW::setSentBytes(::Ice::Int nSentBytes, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setSentBytes(nSentBytes, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getSentBytes(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getSentBytes_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getSentBytes(__ctx);
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
IceProxy::VENTC::VentComponentRW::setTimeONVal(::Ice::Int nTimeONVal, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setTimeONVal(nTimeONVal, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getTimeONVal(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getTimeONVal_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getTimeONVal(__ctx);
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
IceProxy::VENTC::VentComponentRW::setTimeOFFVal(::Ice::Int nTimeOFFVal, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setTimeOFFVal(nTimeOFFVal, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getTimeOFFVal(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getTimeOFFVal_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getTimeOFFVal(__ctx);
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
IceProxy::VENTC::VentComponentRW::setChkBxAIRVLVCNTRL(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setChkBxAIRVLVCNTRL(nChecked, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getChkBxAIRVLVCNTRL(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getChkBxAIRVLVCNTRL_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getChkBxAIRVLVCNTRL(__ctx);
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
IceProxy::VENTC::VentComponentRW::setChkBxEXHVLVCNTRL(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setChkBxEXHVLVCNTRL(nChecked, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getChkBxEXHVLVCNTRL(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getChkBxEXHVLVCNTRL_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getChkBxEXHVLVCNTRL(__ctx);
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
IceProxy::VENTC::VentComponentRW::setChkBxFSPWREN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setChkBxFSPWREN(nChecked, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getChkBxFSPWREN(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getChkBxFSPWREN_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getChkBxFSPWREN(__ctx);
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
IceProxy::VENTC::VentComponentRW::setChkBxILIMPSMEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setChkBxILIMPSMEN(nChecked, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getChkBxILIMPSMEN(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getChkBxILIMPSMEN_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getChkBxILIMPSMEN(__ctx);
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
IceProxy::VENTC::VentComponentRW::setChkBxILIMMODEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setChkBxILIMMODEN(nChecked, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getChkBxILIMMODEN(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getChkBxILIMMODEN_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getChkBxILIMMODEN(__ctx);
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
IceProxy::VENTC::VentComponentRW::setChkBxMNVROPEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setChkBxMNVROPEN(nChecked, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getChkBxMNVROPEN(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getChkBxMNVROPEN_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getChkBxMNVROPEN(__ctx);
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
IceProxy::VENTC::VentComponentRW::setChkBxO2VLVCNTRL(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setChkBxO2VLVCNTRL(nChecked, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getChkBxO2VLVCNTRL(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getChkBxO2VLVCNTRL_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getChkBxO2VLVCNTRL(__ctx);
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
IceProxy::VENTC::VentComponentRW::setChkBxOKTOZERO(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setChkBxOKTOZERO(nChecked, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getChkBxOKTOZERO(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getChkBxOKTOZERO_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getChkBxOKTOZERO(__ctx);
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
IceProxy::VENTC::VentComponentRW::setChkBxSAFECLS(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setChkBxSAFECLS(nChecked, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getChkBxSAFECLS(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getChkBxSAFECLS_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getChkBxSAFECLS(__ctx);
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
IceProxy::VENTC::VentComponentRW::setChkBxZEROAUXPEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setChkBxZEROAUXPEN(nChecked, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getChkBxZEROAUXPEN(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getChkBxZEROAUXPEN_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getChkBxZEROAUXPEN(__ctx);
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
IceProxy::VENTC::VentComponentRW::setChkBxZEROINSPEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setChkBxZEROINSPEN(nChecked, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getChkBxZEROINSPEN(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getChkBxZEROINSPEN_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getChkBxZEROINSPEN(__ctx);
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
IceProxy::VENTC::VentComponentRW::setChkBxVCBUZZERON(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setChkBxVCBUZZERON(nChecked, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getChkBxVCBUZZERON(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getChkBxVCBUZZERON_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getChkBxVCBUZZERON(__ctx);
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
IceProxy::VENTC::VentComponentRW::setO2DAC(::Ice::Int nBoxO2DAC, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setO2DAC(nBoxO2DAC, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getO2DAC(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getO2DAC_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getO2DAC(__ctx);
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
IceProxy::VENTC::VentComponentRW::setO2Percents(::Ice::Int nBoxO2Percents, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setO2Percents(nBoxO2Percents, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getO2Percents(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getO2Percents_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getO2Percents(__ctx);
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
IceProxy::VENTC::VentComponentRW::setTotalFlowResult(::Ice::Int nBoxTotalFlowResult, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setTotalFlowResult(nBoxTotalFlowResult, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getTotalFlowResult(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getTotalFlowResult_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getTotalFlowResult(__ctx);
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
IceProxy::VENTC::VentComponentRW::setTotalFlow(::Ice::Int nBoxTotalFlow, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setTotalFlow(nBoxTotalFlow, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getTotalFlow(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getTotalFlow_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getTotalFlow(__ctx);
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
IceProxy::VENTC::VentComponentRW::setAirFlow(::Ice::Int nBoxAirFlow, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setAirFlow(nBoxAirFlow, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getAirFlow(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getAirFlow_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getAirFlow(__ctx);
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
IceProxy::VENTC::VentComponentRW::setAirDAC(::Ice::Int nBoxAirDAC, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setAirDAC(nBoxAirDAC, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getAirDAC(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getAirDAC_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getAirDAC(__ctx);
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
IceProxy::VENTC::VentComponentRW::setExhalFlow(::Ice::Int nBoxExhalFlow, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setExhalFlow(nBoxExhalFlow, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getExhalFlow(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getExhalFlow_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getExhalFlow(__ctx);
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
IceProxy::VENTC::VentComponentRW::setExhalFlow2(::Ice::Int nBoxExhalFlow2, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setExhalFlow2(nBoxExhalFlow2, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getExhalFlow2(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getExhalFlow2_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getExhalFlow2(__ctx);
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
IceProxy::VENTC::VentComponentRW::setExhDAC(::Ice::Int nBoxExhDAC, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setExhDAC(nBoxExhDAC, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getExhDAC(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getExhDAC_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getExhDAC(__ctx);
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
IceProxy::VENTC::VentComponentRW::setDitherDAC(::Ice::Int nBoxDitherDAC, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setDitherDAC(nBoxDitherDAC, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getDitherDAC(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getDitherDAC_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getDitherDAC(__ctx);
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
IceProxy::VENTC::VentComponentRW::setOxigFlow(::Ice::Int nBoxOxigFlow, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setOxigFlow(nBoxOxigFlow, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getOxigFlow(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getOxigFlow_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getOxigFlow(__ctx);
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
IceProxy::VENTC::VentComponentRW::setOCTemp(const ::std::string& sBoxOCTemp, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setOCTemp(sBoxOCTemp, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getOCTemp(::std::string& sRetVal, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getOCTemp_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getOCTemp(sRetVal, __ctx);
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
IceProxy::VENTC::VentComponentRW::setTCTemp(const ::std::string& sBoxTCTemp, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setTCTemp(sBoxTCTemp, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getTCTemp(::std::string& sRetVal, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getTCTemp_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getTCTemp(sRetVal, __ctx);
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
IceProxy::VENTC::VentComponentRW::setACTemp(const ::std::string& sBoxACTemp, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setACTemp(sBoxACTemp, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getACTemp(::std::string& sRetVal, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getACTemp_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getACTemp(sRetVal, __ctx);
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
IceProxy::VENTC::VentComponentRW::setO2Comp(const ::std::string& sBoxO2Comp, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setO2Comp(sBoxO2Comp, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getO2Comp(::std::string& sRetVal, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getO2Comp_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getO2Comp(sRetVal, __ctx);
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
IceProxy::VENTC::VentComponentRW::setCPULoad(const ::std::string& sBoxCPULoad, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->setCPULoad(sBoxCPULoad, nDisplayOnGUI, __ctx);
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

::Ice::Int
IceProxy::VENTC::VentComponentRW::getCPULoad(::std::string& sRetVal, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__VENTC__VentComponentRW__getCPULoad_name);
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            return __del->getCPULoad(sRetVal, __ctx);
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
IceProxy::VENTC::VentComponentRW::enableBtnRunVent(::Ice::Int nEnable, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->enableBtnRunVent(nEnable, __ctx);
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
IceProxy::VENTC::VentComponentRW::enableBtnConnect(::Ice::Int nEnable, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::VENTC::VentComponentRW* __del = dynamic_cast< ::IceDelegate::VENTC::VentComponentRW*>(__delBase.get());
            __del->enableBtnConnect(nEnable, __ctx);
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
IceProxy::VENTC::VentComponentRW::ice_staticId()
{
    return ::VENTC::VentComponentRW::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::VENTC::VentComponentRW::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::VENTC::VentComponentRW);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::VENTC::VentComponentRW::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::VENTC::VentComponentRW);
}

bool
IceProxy::VENTC::operator==(const ::IceProxy::VENTC::VentComponentRW& l, const ::IceProxy::VENTC::VentComponentRW& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::VENTC::operator!=(const ::IceProxy::VENTC::VentComponentRW& l, const ::IceProxy::VENTC::VentComponentRW& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::VENTC::operator<(const ::IceProxy::VENTC::VentComponentRW& l, const ::IceProxy::VENTC::VentComponentRW& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::VENTC::operator<=(const ::IceProxy::VENTC::VentComponentRW& l, const ::IceProxy::VENTC::VentComponentRW& r)
{
    return l < r || l == r;
}

bool
IceProxy::VENTC::operator>(const ::IceProxy::VENTC::VentComponentRW& l, const ::IceProxy::VENTC::VentComponentRW& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::VENTC::operator>=(const ::IceProxy::VENTC::VentComponentRW& l, const ::IceProxy::VENTC::VentComponentRW& r)
{
    return !(l < r);
}

::Ice::Int
IceDelegateM::VENTC::VentComponentRO::getComPortSpeed(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRO__getComPortSpeed_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::OnConnect(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__OnConnect_name, ::Ice::Normal, __context, __compress);
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
IceDelegateM::VENTC::VentComponentRW::OnRunVentilation(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__OnRunVentilation_name, ::Ice::Normal, __context, __compress);
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
IceDelegateM::VENTC::VentComponentRW::OnDestroy(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__OnDestroy_name, ::Ice::Normal, __context, __compress);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::isEmpty(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__isEmpty_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getMsgFromStore(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getMsgFromStore_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setComPortSpeed(::Ice::Int nComPortSpeed, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setComPortSpeed_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nComPortSpeed);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getComPortSpeed(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getComPortSpeed_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setComPortNumber(::Ice::Int nComPortNumber, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setComPortNumber_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nComPortNumber);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getComPortNumber(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getComPortNumber_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setRecBytes(::Ice::Int nRecBytes, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setRecBytes_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nRecBytes);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getRecBytes(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getRecBytes_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setSentBytes(::Ice::Int nSentBytes, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setSentBytes_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nSentBytes);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getSentBytes(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getSentBytes_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setTimeONVal(::Ice::Int nTimeONVal, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setTimeONVal_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nTimeONVal);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getTimeONVal(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getTimeONVal_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setTimeOFFVal(::Ice::Int nTimeOFFVal, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setTimeOFFVal_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nTimeOFFVal);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getTimeOFFVal(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getTimeOFFVal_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setChkBxAIRVLVCNTRL(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setChkBxAIRVLVCNTRL_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nChecked);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getChkBxAIRVLVCNTRL(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getChkBxAIRVLVCNTRL_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setChkBxEXHVLVCNTRL(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setChkBxEXHVLVCNTRL_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nChecked);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getChkBxEXHVLVCNTRL(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getChkBxEXHVLVCNTRL_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setChkBxFSPWREN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setChkBxFSPWREN_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nChecked);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getChkBxFSPWREN(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getChkBxFSPWREN_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setChkBxILIMPSMEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setChkBxILIMPSMEN_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nChecked);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getChkBxILIMPSMEN(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getChkBxILIMPSMEN_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setChkBxILIMMODEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setChkBxILIMMODEN_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nChecked);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getChkBxILIMMODEN(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getChkBxILIMMODEN_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setChkBxMNVROPEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setChkBxMNVROPEN_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nChecked);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getChkBxMNVROPEN(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getChkBxMNVROPEN_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setChkBxO2VLVCNTRL(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setChkBxO2VLVCNTRL_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nChecked);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getChkBxO2VLVCNTRL(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getChkBxO2VLVCNTRL_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setChkBxOKTOZERO(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setChkBxOKTOZERO_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nChecked);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getChkBxOKTOZERO(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getChkBxOKTOZERO_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setChkBxSAFECLS(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setChkBxSAFECLS_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nChecked);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getChkBxSAFECLS(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getChkBxSAFECLS_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setChkBxZEROAUXPEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setChkBxZEROAUXPEN_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nChecked);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getChkBxZEROAUXPEN(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getChkBxZEROAUXPEN_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setChkBxZEROINSPEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setChkBxZEROINSPEN_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nChecked);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getChkBxZEROINSPEN(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getChkBxZEROINSPEN_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setChkBxVCBUZZERON(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setChkBxVCBUZZERON_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nChecked);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getChkBxVCBUZZERON(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getChkBxVCBUZZERON_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setO2DAC(::Ice::Int nBoxO2DAC, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setO2DAC_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nBoxO2DAC);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getO2DAC(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getO2DAC_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setO2Percents(::Ice::Int nBoxO2Percents, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setO2Percents_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nBoxO2Percents);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getO2Percents(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getO2Percents_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setTotalFlowResult(::Ice::Int nBoxTotalFlowResult, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setTotalFlowResult_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nBoxTotalFlowResult);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getTotalFlowResult(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getTotalFlowResult_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setTotalFlow(::Ice::Int nBoxTotalFlow, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setTotalFlow_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nBoxTotalFlow);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getTotalFlow(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getTotalFlow_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setAirFlow(::Ice::Int nBoxAirFlow, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setAirFlow_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nBoxAirFlow);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getAirFlow(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getAirFlow_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setAirDAC(::Ice::Int nBoxAirDAC, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setAirDAC_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nBoxAirDAC);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getAirDAC(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getAirDAC_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setExhalFlow(::Ice::Int nBoxExhalFlow, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setExhalFlow_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nBoxExhalFlow);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getExhalFlow(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getExhalFlow_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setExhalFlow2(::Ice::Int nBoxExhalFlow2, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setExhalFlow2_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nBoxExhalFlow2);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getExhalFlow2(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getExhalFlow2_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setExhDAC(::Ice::Int nBoxExhDAC, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setExhDAC_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nBoxExhDAC);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getExhDAC(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getExhDAC_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setDitherDAC(::Ice::Int nBoxDitherDAC, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setDitherDAC_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nBoxDitherDAC);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getDitherDAC(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getDitherDAC_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setOxigFlow(::Ice::Int nBoxOxigFlow, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setOxigFlow_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nBoxOxigFlow);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getOxigFlow(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getOxigFlow_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setOCTemp(const ::std::string& sBoxOCTemp, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setOCTemp_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(sBoxOCTemp);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getOCTemp(::std::string& sRetVal, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getOCTemp_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(sRetVal);
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setTCTemp(const ::std::string& sBoxTCTemp, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setTCTemp_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(sBoxTCTemp);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getTCTemp(::std::string& sRetVal, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getTCTemp_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(sRetVal);
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setACTemp(const ::std::string& sBoxACTemp, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setACTemp_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(sBoxACTemp);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getACTemp(::std::string& sRetVal, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getACTemp_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(sRetVal);
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setO2Comp(const ::std::string& sBoxO2Comp, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setO2Comp_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(sBoxO2Comp);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getO2Comp(::std::string& sRetVal, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getO2Comp_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(sRetVal);
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::setCPULoad(const ::std::string& sBoxCPULoad, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__setCPULoad_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(sBoxCPULoad);
        __os->write(nDisplayOnGUI);
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

::Ice::Int
IceDelegateM::VENTC::VentComponentRW::getCPULoad(::std::string& sRetVal, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__getCPULoad_name, ::Ice::Normal, __context, __compress);
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
        ::Ice::Int __ret;
        __is->read(sRetVal);
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::VENTC::VentComponentRW::enableBtnRunVent(::Ice::Int nEnable, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__enableBtnRunVent_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nEnable);
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
IceDelegateM::VENTC::VentComponentRW::enableBtnConnect(::Ice::Int nEnable, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __VENTC__VentComponentRW__enableBtnConnect_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(nEnable);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRO::getComPortSpeed(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRO__getComPortSpeed_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRO* __servant = dynamic_cast< ::VENTC::VentComponentRO*>(__direct.servant().get());
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
                __ret = __servant->getComPortSpeed(__current);
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
IceDelegateD::VENTC::VentComponentRW::OnConnect(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__OnConnect_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->OnConnect(__current);
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
IceDelegateD::VENTC::VentComponentRW::OnRunVentilation(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__OnRunVentilation_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->OnRunVentilation(__current);
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
IceDelegateD::VENTC::VentComponentRW::OnDestroy(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__OnDestroy_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->OnDestroy(__current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::isEmpty(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__isEmpty_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->isEmpty(__current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getMsgFromStore(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getMsgFromStore_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getMsgFromStore(__current);
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
IceDelegateD::VENTC::VentComponentRW::setComPortSpeed(::Ice::Int nComPortSpeed, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setComPortSpeed_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setComPortSpeed(nComPortSpeed, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getComPortSpeed(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getComPortSpeed_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getComPortSpeed(__current);
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
IceDelegateD::VENTC::VentComponentRW::setComPortNumber(::Ice::Int nComPortNumber, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setComPortNumber_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setComPortNumber(nComPortNumber, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getComPortNumber(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getComPortNumber_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getComPortNumber(__current);
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
IceDelegateD::VENTC::VentComponentRW::setRecBytes(::Ice::Int nRecBytes, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setRecBytes_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setRecBytes(nRecBytes, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getRecBytes(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getRecBytes_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getRecBytes(__current);
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
IceDelegateD::VENTC::VentComponentRW::setSentBytes(::Ice::Int nSentBytes, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setSentBytes_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setSentBytes(nSentBytes, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getSentBytes(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getSentBytes_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getSentBytes(__current);
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
IceDelegateD::VENTC::VentComponentRW::setTimeONVal(::Ice::Int nTimeONVal, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setTimeONVal_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setTimeONVal(nTimeONVal, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getTimeONVal(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getTimeONVal_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getTimeONVal(__current);
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
IceDelegateD::VENTC::VentComponentRW::setTimeOFFVal(::Ice::Int nTimeOFFVal, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setTimeOFFVal_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setTimeOFFVal(nTimeOFFVal, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getTimeOFFVal(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getTimeOFFVal_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getTimeOFFVal(__current);
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
IceDelegateD::VENTC::VentComponentRW::setChkBxAIRVLVCNTRL(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setChkBxAIRVLVCNTRL_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setChkBxAIRVLVCNTRL(nChecked, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getChkBxAIRVLVCNTRL(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getChkBxAIRVLVCNTRL_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getChkBxAIRVLVCNTRL(__current);
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
IceDelegateD::VENTC::VentComponentRW::setChkBxEXHVLVCNTRL(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setChkBxEXHVLVCNTRL_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setChkBxEXHVLVCNTRL(nChecked, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getChkBxEXHVLVCNTRL(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getChkBxEXHVLVCNTRL_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getChkBxEXHVLVCNTRL(__current);
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
IceDelegateD::VENTC::VentComponentRW::setChkBxFSPWREN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setChkBxFSPWREN_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setChkBxFSPWREN(nChecked, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getChkBxFSPWREN(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getChkBxFSPWREN_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getChkBxFSPWREN(__current);
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
IceDelegateD::VENTC::VentComponentRW::setChkBxILIMPSMEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setChkBxILIMPSMEN_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setChkBxILIMPSMEN(nChecked, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getChkBxILIMPSMEN(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getChkBxILIMPSMEN_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getChkBxILIMPSMEN(__current);
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
IceDelegateD::VENTC::VentComponentRW::setChkBxILIMMODEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setChkBxILIMMODEN_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setChkBxILIMMODEN(nChecked, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getChkBxILIMMODEN(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getChkBxILIMMODEN_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getChkBxILIMMODEN(__current);
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
IceDelegateD::VENTC::VentComponentRW::setChkBxMNVROPEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setChkBxMNVROPEN_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setChkBxMNVROPEN(nChecked, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getChkBxMNVROPEN(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getChkBxMNVROPEN_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getChkBxMNVROPEN(__current);
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
IceDelegateD::VENTC::VentComponentRW::setChkBxO2VLVCNTRL(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setChkBxO2VLVCNTRL_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setChkBxO2VLVCNTRL(nChecked, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getChkBxO2VLVCNTRL(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getChkBxO2VLVCNTRL_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getChkBxO2VLVCNTRL(__current);
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
IceDelegateD::VENTC::VentComponentRW::setChkBxOKTOZERO(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setChkBxOKTOZERO_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setChkBxOKTOZERO(nChecked, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getChkBxOKTOZERO(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getChkBxOKTOZERO_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getChkBxOKTOZERO(__current);
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
IceDelegateD::VENTC::VentComponentRW::setChkBxSAFECLS(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setChkBxSAFECLS_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setChkBxSAFECLS(nChecked, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getChkBxSAFECLS(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getChkBxSAFECLS_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getChkBxSAFECLS(__current);
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
IceDelegateD::VENTC::VentComponentRW::setChkBxZEROAUXPEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setChkBxZEROAUXPEN_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setChkBxZEROAUXPEN(nChecked, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getChkBxZEROAUXPEN(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getChkBxZEROAUXPEN_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getChkBxZEROAUXPEN(__current);
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
IceDelegateD::VENTC::VentComponentRW::setChkBxZEROINSPEN(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setChkBxZEROINSPEN_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setChkBxZEROINSPEN(nChecked, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getChkBxZEROINSPEN(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getChkBxZEROINSPEN_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getChkBxZEROINSPEN(__current);
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
IceDelegateD::VENTC::VentComponentRW::setChkBxVCBUZZERON(::Ice::Int nChecked, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setChkBxVCBUZZERON_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setChkBxVCBUZZERON(nChecked, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getChkBxVCBUZZERON(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getChkBxVCBUZZERON_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getChkBxVCBUZZERON(__current);
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
IceDelegateD::VENTC::VentComponentRW::setO2DAC(::Ice::Int nBoxO2DAC, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setO2DAC_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setO2DAC(nBoxO2DAC, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getO2DAC(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getO2DAC_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getO2DAC(__current);
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
IceDelegateD::VENTC::VentComponentRW::setO2Percents(::Ice::Int nBoxO2Percents, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setO2Percents_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setO2Percents(nBoxO2Percents, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getO2Percents(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getO2Percents_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getO2Percents(__current);
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
IceDelegateD::VENTC::VentComponentRW::setTotalFlowResult(::Ice::Int nBoxTotalFlowResult, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setTotalFlowResult_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setTotalFlowResult(nBoxTotalFlowResult, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getTotalFlowResult(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getTotalFlowResult_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getTotalFlowResult(__current);
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
IceDelegateD::VENTC::VentComponentRW::setTotalFlow(::Ice::Int nBoxTotalFlow, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setTotalFlow_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setTotalFlow(nBoxTotalFlow, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getTotalFlow(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getTotalFlow_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getTotalFlow(__current);
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
IceDelegateD::VENTC::VentComponentRW::setAirFlow(::Ice::Int nBoxAirFlow, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setAirFlow_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setAirFlow(nBoxAirFlow, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getAirFlow(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getAirFlow_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getAirFlow(__current);
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
IceDelegateD::VENTC::VentComponentRW::setAirDAC(::Ice::Int nBoxAirDAC, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setAirDAC_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setAirDAC(nBoxAirDAC, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getAirDAC(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getAirDAC_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getAirDAC(__current);
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
IceDelegateD::VENTC::VentComponentRW::setExhalFlow(::Ice::Int nBoxExhalFlow, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setExhalFlow_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setExhalFlow(nBoxExhalFlow, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getExhalFlow(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getExhalFlow_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getExhalFlow(__current);
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
IceDelegateD::VENTC::VentComponentRW::setExhalFlow2(::Ice::Int nBoxExhalFlow2, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setExhalFlow2_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setExhalFlow2(nBoxExhalFlow2, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getExhalFlow2(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getExhalFlow2_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getExhalFlow2(__current);
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
IceDelegateD::VENTC::VentComponentRW::setExhDAC(::Ice::Int nBoxExhDAC, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setExhDAC_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setExhDAC(nBoxExhDAC, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getExhDAC(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getExhDAC_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getExhDAC(__current);
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
IceDelegateD::VENTC::VentComponentRW::setDitherDAC(::Ice::Int nBoxDitherDAC, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setDitherDAC_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setDitherDAC(nBoxDitherDAC, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getDitherDAC(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getDitherDAC_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getDitherDAC(__current);
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
IceDelegateD::VENTC::VentComponentRW::setOxigFlow(::Ice::Int nBoxOxigFlow, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setOxigFlow_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setOxigFlow(nBoxOxigFlow, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getOxigFlow(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getOxigFlow_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getOxigFlow(__current);
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
IceDelegateD::VENTC::VentComponentRW::setOCTemp(const ::std::string& sBoxOCTemp, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setOCTemp_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setOCTemp(sBoxOCTemp, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getOCTemp(::std::string& sRetVal, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getOCTemp_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getOCTemp(sRetVal, __current);
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
IceDelegateD::VENTC::VentComponentRW::setTCTemp(const ::std::string& sBoxTCTemp, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setTCTemp_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setTCTemp(sBoxTCTemp, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getTCTemp(::std::string& sRetVal, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getTCTemp_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getTCTemp(sRetVal, __current);
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
IceDelegateD::VENTC::VentComponentRW::setACTemp(const ::std::string& sBoxACTemp, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setACTemp_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setACTemp(sBoxACTemp, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getACTemp(::std::string& sRetVal, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getACTemp_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getACTemp(sRetVal, __current);
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
IceDelegateD::VENTC::VentComponentRW::setO2Comp(const ::std::string& sBoxO2Comp, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setO2Comp_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setO2Comp(sBoxO2Comp, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getO2Comp(::std::string& sRetVal, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getO2Comp_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getO2Comp(sRetVal, __current);
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
IceDelegateD::VENTC::VentComponentRW::setCPULoad(const ::std::string& sBoxCPULoad, ::Ice::Int nDisplayOnGUI, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__setCPULoad_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->setCPULoad(sBoxCPULoad, nDisplayOnGUI, __current);
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

::Ice::Int
IceDelegateD::VENTC::VentComponentRW::getCPULoad(::std::string& sRetVal, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__getCPULoad_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __ret = __servant->getCPULoad(sRetVal, __current);
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
IceDelegateD::VENTC::VentComponentRW::enableBtnRunVent(::Ice::Int nEnable, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__enableBtnRunVent_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->enableBtnRunVent(nEnable, __current);
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
IceDelegateD::VENTC::VentComponentRW::enableBtnConnect(::Ice::Int nEnable, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __VENTC__VentComponentRW__enableBtnConnect_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::VENTC::VentComponentRW* __servant = dynamic_cast< ::VENTC::VentComponentRW*>(__direct.servant().get());
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
                __servant->enableBtnConnect(nEnable, __current);
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
VENTC::VentComponentRO::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __VENTC__VentComponentRO_ids[3] =
{
    "::ICSSW::Component",
    "::Ice::Object",
    "::VENTC::VentComponentRO"
};

bool
VENTC::VentComponentRO::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__VENTC__VentComponentRO_ids, __VENTC__VentComponentRO_ids + 3, _s);
}

::std::vector< ::std::string>
VENTC::VentComponentRO::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__VENTC__VentComponentRO_ids[0], &__VENTC__VentComponentRO_ids[3]);
}

const ::std::string&
VENTC::VentComponentRO::ice_id(const ::Ice::Current&) const
{
    return __VENTC__VentComponentRO_ids[2];
}

const ::std::string&
VENTC::VentComponentRO::ice_staticId()
{
    return __VENTC__VentComponentRO_ids[2];
}

::IceInternal::DispatchStatus
VENTC::VentComponentRO::___getComPortSpeed(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getComPortSpeed(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

static ::std::string __VENTC__VentComponentRO_all[] =
{
    "getComPortSpeed",
    "getName",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::IceInternal::DispatchStatus
VENTC::VentComponentRO::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__VENTC__VentComponentRO_all, __VENTC__VentComponentRO_all + 6, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __VENTC__VentComponentRO_all)
    {
        case 0:
        {
            return ___getComPortSpeed(in, current);
        }
        case 1:
        {
            return ___getName(in, current);
        }
        case 2:
        {
            return ___ice_id(in, current);
        }
        case 3:
        {
            return ___ice_ids(in, current);
        }
        case 4:
        {
            return ___ice_isA(in, current);
        }
        case 5:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
VENTC::VentComponentRO::__write(::IceInternal::BasicStream* __os) const
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
VENTC::VentComponentRO::__read(::IceInternal::BasicStream* __is, bool __rid)
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
VENTC::VentComponentRO::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type VENTC::VentComponentRO was not generated with stream support";
    throw ex;
}

void
VENTC::VentComponentRO::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type VENTC::VentComponentRO was not generated with stream support";
    throw ex;
}

void 
VENTC::__patch__VentComponentROPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::VENTC::VentComponentROPtr* p = static_cast< ::VENTC::VentComponentROPtr*>(__addr);
    assert(p);
    *p = ::VENTC::VentComponentROPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::VENTC::VentComponentRO::ice_staticId();
        throw e;
    }
}

bool
VENTC::operator==(const ::VENTC::VentComponentRO& l, const ::VENTC::VentComponentRO& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
VENTC::operator!=(const ::VENTC::VentComponentRO& l, const ::VENTC::VentComponentRO& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
VENTC::operator<(const ::VENTC::VentComponentRO& l, const ::VENTC::VentComponentRO& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
VENTC::operator<=(const ::VENTC::VentComponentRO& l, const ::VENTC::VentComponentRO& r)
{
    return l < r || l == r;
}

bool
VENTC::operator>(const ::VENTC::VentComponentRO& l, const ::VENTC::VentComponentRO& r)
{
    return !(l < r) && !(l == r);
}

bool
VENTC::operator>=(const ::VENTC::VentComponentRO& l, const ::VENTC::VentComponentRO& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
VENTC::VentComponentRW::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __VENTC__VentComponentRW_ids[3] =
{
    "::ICSSW::Component",
    "::Ice::Object",
    "::VENTC::VentComponentRW"
};

bool
VENTC::VentComponentRW::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__VENTC__VentComponentRW_ids, __VENTC__VentComponentRW_ids + 3, _s);
}

::std::vector< ::std::string>
VENTC::VentComponentRW::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__VENTC__VentComponentRW_ids[0], &__VENTC__VentComponentRW_ids[3]);
}

const ::std::string&
VENTC::VentComponentRW::ice_id(const ::Ice::Current&) const
{
    return __VENTC__VentComponentRW_ids[2];
}

const ::std::string&
VENTC::VentComponentRW::ice_staticId()
{
    return __VENTC__VentComponentRW_ids[2];
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___OnConnect(::IceInternal::Incoming&, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    OnConnect(__current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___OnRunVentilation(::IceInternal::Incoming&, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    OnRunVentilation(__current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___OnDestroy(::IceInternal::Incoming&, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    OnDestroy(__current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___isEmpty(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = isEmpty(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getMsgFromStore(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getMsgFromStore(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setComPortSpeed(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nComPortSpeed;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nComPortSpeed);
    __is->read(nDisplayOnGUI);
    setComPortSpeed(nComPortSpeed, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getComPortSpeed(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getComPortSpeed(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setComPortNumber(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nComPortNumber;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nComPortNumber);
    __is->read(nDisplayOnGUI);
    setComPortNumber(nComPortNumber, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getComPortNumber(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getComPortNumber(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setRecBytes(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nRecBytes;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nRecBytes);
    __is->read(nDisplayOnGUI);
    setRecBytes(nRecBytes, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getRecBytes(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getRecBytes(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setSentBytes(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nSentBytes;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nSentBytes);
    __is->read(nDisplayOnGUI);
    setSentBytes(nSentBytes, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getSentBytes(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getSentBytes(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setTimeONVal(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nTimeONVal;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nTimeONVal);
    __is->read(nDisplayOnGUI);
    setTimeONVal(nTimeONVal, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getTimeONVal(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getTimeONVal(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setTimeOFFVal(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nTimeOFFVal;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nTimeOFFVal);
    __is->read(nDisplayOnGUI);
    setTimeOFFVal(nTimeOFFVal, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getTimeOFFVal(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getTimeOFFVal(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setChkBxAIRVLVCNTRL(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nChecked;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nChecked);
    __is->read(nDisplayOnGUI);
    setChkBxAIRVLVCNTRL(nChecked, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getChkBxAIRVLVCNTRL(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getChkBxAIRVLVCNTRL(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setChkBxEXHVLVCNTRL(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nChecked;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nChecked);
    __is->read(nDisplayOnGUI);
    setChkBxEXHVLVCNTRL(nChecked, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getChkBxEXHVLVCNTRL(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getChkBxEXHVLVCNTRL(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setChkBxFSPWREN(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nChecked;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nChecked);
    __is->read(nDisplayOnGUI);
    setChkBxFSPWREN(nChecked, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getChkBxFSPWREN(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getChkBxFSPWREN(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setChkBxILIMPSMEN(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nChecked;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nChecked);
    __is->read(nDisplayOnGUI);
    setChkBxILIMPSMEN(nChecked, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getChkBxILIMPSMEN(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getChkBxILIMPSMEN(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setChkBxILIMMODEN(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nChecked;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nChecked);
    __is->read(nDisplayOnGUI);
    setChkBxILIMMODEN(nChecked, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getChkBxILIMMODEN(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getChkBxILIMMODEN(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setChkBxMNVROPEN(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nChecked;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nChecked);
    __is->read(nDisplayOnGUI);
    setChkBxMNVROPEN(nChecked, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getChkBxMNVROPEN(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getChkBxMNVROPEN(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setChkBxO2VLVCNTRL(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nChecked;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nChecked);
    __is->read(nDisplayOnGUI);
    setChkBxO2VLVCNTRL(nChecked, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getChkBxO2VLVCNTRL(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getChkBxO2VLVCNTRL(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setChkBxOKTOZERO(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nChecked;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nChecked);
    __is->read(nDisplayOnGUI);
    setChkBxOKTOZERO(nChecked, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getChkBxOKTOZERO(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getChkBxOKTOZERO(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setChkBxSAFECLS(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nChecked;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nChecked);
    __is->read(nDisplayOnGUI);
    setChkBxSAFECLS(nChecked, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getChkBxSAFECLS(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getChkBxSAFECLS(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setChkBxZEROAUXPEN(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nChecked;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nChecked);
    __is->read(nDisplayOnGUI);
    setChkBxZEROAUXPEN(nChecked, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getChkBxZEROAUXPEN(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getChkBxZEROAUXPEN(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setChkBxZEROINSPEN(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nChecked;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nChecked);
    __is->read(nDisplayOnGUI);
    setChkBxZEROINSPEN(nChecked, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getChkBxZEROINSPEN(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getChkBxZEROINSPEN(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setChkBxVCBUZZERON(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nChecked;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nChecked);
    __is->read(nDisplayOnGUI);
    setChkBxVCBUZZERON(nChecked, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getChkBxVCBUZZERON(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getChkBxVCBUZZERON(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setO2DAC(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nBoxO2DAC;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nBoxO2DAC);
    __is->read(nDisplayOnGUI);
    setO2DAC(nBoxO2DAC, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getO2DAC(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getO2DAC(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setO2Percents(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nBoxO2Percents;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nBoxO2Percents);
    __is->read(nDisplayOnGUI);
    setO2Percents(nBoxO2Percents, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getO2Percents(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getO2Percents(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setTotalFlowResult(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nBoxTotalFlowResult;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nBoxTotalFlowResult);
    __is->read(nDisplayOnGUI);
    setTotalFlowResult(nBoxTotalFlowResult, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getTotalFlowResult(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getTotalFlowResult(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setTotalFlow(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nBoxTotalFlow;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nBoxTotalFlow);
    __is->read(nDisplayOnGUI);
    setTotalFlow(nBoxTotalFlow, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getTotalFlow(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getTotalFlow(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setAirFlow(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nBoxAirFlow;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nBoxAirFlow);
    __is->read(nDisplayOnGUI);
    setAirFlow(nBoxAirFlow, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getAirFlow(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getAirFlow(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setAirDAC(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nBoxAirDAC;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nBoxAirDAC);
    __is->read(nDisplayOnGUI);
    setAirDAC(nBoxAirDAC, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getAirDAC(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getAirDAC(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setExhalFlow(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nBoxExhalFlow;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nBoxExhalFlow);
    __is->read(nDisplayOnGUI);
    setExhalFlow(nBoxExhalFlow, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getExhalFlow(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getExhalFlow(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setExhalFlow2(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nBoxExhalFlow2;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nBoxExhalFlow2);
    __is->read(nDisplayOnGUI);
    setExhalFlow2(nBoxExhalFlow2, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getExhalFlow2(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getExhalFlow2(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setExhDAC(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nBoxExhDAC;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nBoxExhDAC);
    __is->read(nDisplayOnGUI);
    setExhDAC(nBoxExhDAC, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getExhDAC(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getExhDAC(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setDitherDAC(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nBoxDitherDAC;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nBoxDitherDAC);
    __is->read(nDisplayOnGUI);
    setDitherDAC(nBoxDitherDAC, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getDitherDAC(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getDitherDAC(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setOxigFlow(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nBoxOxigFlow;
    ::Ice::Int nDisplayOnGUI;
    __is->read(nBoxOxigFlow);
    __is->read(nDisplayOnGUI);
    setOxigFlow(nBoxOxigFlow, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getOxigFlow(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = getOxigFlow(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setOCTemp(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string sBoxOCTemp;
    ::Ice::Int nDisplayOnGUI;
    __is->read(sBoxOCTemp);
    __is->read(nDisplayOnGUI);
    setOCTemp(sBoxOCTemp, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getOCTemp(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sRetVal;
    ::Ice::Int __ret = getOCTemp(sRetVal, __current);
    __os->write(sRetVal);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setTCTemp(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string sBoxTCTemp;
    ::Ice::Int nDisplayOnGUI;
    __is->read(sBoxTCTemp);
    __is->read(nDisplayOnGUI);
    setTCTemp(sBoxTCTemp, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getTCTemp(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sRetVal;
    ::Ice::Int __ret = getTCTemp(sRetVal, __current);
    __os->write(sRetVal);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setACTemp(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string sBoxACTemp;
    ::Ice::Int nDisplayOnGUI;
    __is->read(sBoxACTemp);
    __is->read(nDisplayOnGUI);
    setACTemp(sBoxACTemp, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getACTemp(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sRetVal;
    ::Ice::Int __ret = getACTemp(sRetVal, __current);
    __os->write(sRetVal);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setO2Comp(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string sBoxO2Comp;
    ::Ice::Int nDisplayOnGUI;
    __is->read(sBoxO2Comp);
    __is->read(nDisplayOnGUI);
    setO2Comp(sBoxO2Comp, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getO2Comp(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sRetVal;
    ::Ice::Int __ret = getO2Comp(sRetVal, __current);
    __os->write(sRetVal);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___setCPULoad(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string sBoxCPULoad;
    ::Ice::Int nDisplayOnGUI;
    __is->read(sBoxCPULoad);
    __is->read(nDisplayOnGUI);
    setCPULoad(sBoxCPULoad, nDisplayOnGUI, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___getCPULoad(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sRetVal;
    ::Ice::Int __ret = getCPULoad(sRetVal, __current);
    __os->write(sRetVal);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___enableBtnRunVent(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nEnable;
    __is->read(nEnable);
    enableBtnRunVent(nEnable, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
VENTC::VentComponentRW::___enableBtnConnect(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nEnable;
    __is->read(nEnable);
    enableBtnConnect(nEnable, __current);
    return ::IceInternal::DispatchOK;
}

static ::std::string __VENTC__VentComponentRW_all[] =
{
    "OnConnect",
    "OnDestroy",
    "OnRunVentilation",
    "enableBtnConnect",
    "enableBtnRunVent",
    "getACTemp",
    "getAirDAC",
    "getAirFlow",
    "getCPULoad",
    "getChkBxAIRVLVCNTRL",
    "getChkBxEXHVLVCNTRL",
    "getChkBxFSPWREN",
    "getChkBxILIMMODEN",
    "getChkBxILIMPSMEN",
    "getChkBxMNVROPEN",
    "getChkBxO2VLVCNTRL",
    "getChkBxOKTOZERO",
    "getChkBxSAFECLS",
    "getChkBxVCBUZZERON",
    "getChkBxZEROAUXPEN",
    "getChkBxZEROINSPEN",
    "getComPortNumber",
    "getComPortSpeed",
    "getDitherDAC",
    "getExhDAC",
    "getExhalFlow",
    "getExhalFlow2",
    "getMsgFromStore",
    "getName",
    "getO2Comp",
    "getO2DAC",
    "getO2Percents",
    "getOCTemp",
    "getOxigFlow",
    "getRecBytes",
    "getSentBytes",
    "getTCTemp",
    "getTimeOFFVal",
    "getTimeONVal",
    "getTotalFlow",
    "getTotalFlowResult",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "isEmpty",
    "setACTemp",
    "setAirDAC",
    "setAirFlow",
    "setCPULoad",
    "setChkBxAIRVLVCNTRL",
    "setChkBxEXHVLVCNTRL",
    "setChkBxFSPWREN",
    "setChkBxILIMMODEN",
    "setChkBxILIMPSMEN",
    "setChkBxMNVROPEN",
    "setChkBxO2VLVCNTRL",
    "setChkBxOKTOZERO",
    "setChkBxSAFECLS",
    "setChkBxVCBUZZERON",
    "setChkBxZEROAUXPEN",
    "setChkBxZEROINSPEN",
    "setComPortNumber",
    "setComPortSpeed",
    "setDitherDAC",
    "setExhDAC",
    "setExhalFlow",
    "setExhalFlow2",
    "setO2Comp",
    "setO2DAC",
    "setO2Percents",
    "setOCTemp",
    "setOxigFlow",
    "setRecBytes",
    "setSentBytes",
    "setTCTemp",
    "setTimeOFFVal",
    "setTimeONVal",
    "setTotalFlow",
    "setTotalFlowResult"
};

::IceInternal::DispatchStatus
VENTC::VentComponentRW::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__VENTC__VentComponentRW_all, __VENTC__VentComponentRW_all + 80, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __VENTC__VentComponentRW_all)
    {
        case 0:
        {
            return ___OnConnect(in, current);
        }
        case 1:
        {
            return ___OnDestroy(in, current);
        }
        case 2:
        {
            return ___OnRunVentilation(in, current);
        }
        case 3:
        {
            return ___enableBtnConnect(in, current);
        }
        case 4:
        {
            return ___enableBtnRunVent(in, current);
        }
        case 5:
        {
            return ___getACTemp(in, current);
        }
        case 6:
        {
            return ___getAirDAC(in, current);
        }
        case 7:
        {
            return ___getAirFlow(in, current);
        }
        case 8:
        {
            return ___getCPULoad(in, current);
        }
        case 9:
        {
            return ___getChkBxAIRVLVCNTRL(in, current);
        }
        case 10:
        {
            return ___getChkBxEXHVLVCNTRL(in, current);
        }
        case 11:
        {
            return ___getChkBxFSPWREN(in, current);
        }
        case 12:
        {
            return ___getChkBxILIMMODEN(in, current);
        }
        case 13:
        {
            return ___getChkBxILIMPSMEN(in, current);
        }
        case 14:
        {
            return ___getChkBxMNVROPEN(in, current);
        }
        case 15:
        {
            return ___getChkBxO2VLVCNTRL(in, current);
        }
        case 16:
        {
            return ___getChkBxOKTOZERO(in, current);
        }
        case 17:
        {
            return ___getChkBxSAFECLS(in, current);
        }
        case 18:
        {
            return ___getChkBxVCBUZZERON(in, current);
        }
        case 19:
        {
            return ___getChkBxZEROAUXPEN(in, current);
        }
        case 20:
        {
            return ___getChkBxZEROINSPEN(in, current);
        }
        case 21:
        {
            return ___getComPortNumber(in, current);
        }
        case 22:
        {
            return ___getComPortSpeed(in, current);
        }
        case 23:
        {
            return ___getDitherDAC(in, current);
        }
        case 24:
        {
            return ___getExhDAC(in, current);
        }
        case 25:
        {
            return ___getExhalFlow(in, current);
        }
        case 26:
        {
            return ___getExhalFlow2(in, current);
        }
        case 27:
        {
            return ___getMsgFromStore(in, current);
        }
        case 28:
        {
            return ___getName(in, current);
        }
        case 29:
        {
            return ___getO2Comp(in, current);
        }
        case 30:
        {
            return ___getO2DAC(in, current);
        }
        case 31:
        {
            return ___getO2Percents(in, current);
        }
        case 32:
        {
            return ___getOCTemp(in, current);
        }
        case 33:
        {
            return ___getOxigFlow(in, current);
        }
        case 34:
        {
            return ___getRecBytes(in, current);
        }
        case 35:
        {
            return ___getSentBytes(in, current);
        }
        case 36:
        {
            return ___getTCTemp(in, current);
        }
        case 37:
        {
            return ___getTimeOFFVal(in, current);
        }
        case 38:
        {
            return ___getTimeONVal(in, current);
        }
        case 39:
        {
            return ___getTotalFlow(in, current);
        }
        case 40:
        {
            return ___getTotalFlowResult(in, current);
        }
        case 41:
        {
            return ___ice_id(in, current);
        }
        case 42:
        {
            return ___ice_ids(in, current);
        }
        case 43:
        {
            return ___ice_isA(in, current);
        }
        case 44:
        {
            return ___ice_ping(in, current);
        }
        case 45:
        {
            return ___isEmpty(in, current);
        }
        case 46:
        {
            return ___setACTemp(in, current);
        }
        case 47:
        {
            return ___setAirDAC(in, current);
        }
        case 48:
        {
            return ___setAirFlow(in, current);
        }
        case 49:
        {
            return ___setCPULoad(in, current);
        }
        case 50:
        {
            return ___setChkBxAIRVLVCNTRL(in, current);
        }
        case 51:
        {
            return ___setChkBxEXHVLVCNTRL(in, current);
        }
        case 52:
        {
            return ___setChkBxFSPWREN(in, current);
        }
        case 53:
        {
            return ___setChkBxILIMMODEN(in, current);
        }
        case 54:
        {
            return ___setChkBxILIMPSMEN(in, current);
        }
        case 55:
        {
            return ___setChkBxMNVROPEN(in, current);
        }
        case 56:
        {
            return ___setChkBxO2VLVCNTRL(in, current);
        }
        case 57:
        {
            return ___setChkBxOKTOZERO(in, current);
        }
        case 58:
        {
            return ___setChkBxSAFECLS(in, current);
        }
        case 59:
        {
            return ___setChkBxVCBUZZERON(in, current);
        }
        case 60:
        {
            return ___setChkBxZEROAUXPEN(in, current);
        }
        case 61:
        {
            return ___setChkBxZEROINSPEN(in, current);
        }
        case 62:
        {
            return ___setComPortNumber(in, current);
        }
        case 63:
        {
            return ___setComPortSpeed(in, current);
        }
        case 64:
        {
            return ___setDitherDAC(in, current);
        }
        case 65:
        {
            return ___setExhDAC(in, current);
        }
        case 66:
        {
            return ___setExhalFlow(in, current);
        }
        case 67:
        {
            return ___setExhalFlow2(in, current);
        }
        case 68:
        {
            return ___setO2Comp(in, current);
        }
        case 69:
        {
            return ___setO2DAC(in, current);
        }
        case 70:
        {
            return ___setO2Percents(in, current);
        }
        case 71:
        {
            return ___setOCTemp(in, current);
        }
        case 72:
        {
            return ___setOxigFlow(in, current);
        }
        case 73:
        {
            return ___setRecBytes(in, current);
        }
        case 74:
        {
            return ___setSentBytes(in, current);
        }
        case 75:
        {
            return ___setTCTemp(in, current);
        }
        case 76:
        {
            return ___setTimeOFFVal(in, current);
        }
        case 77:
        {
            return ___setTimeONVal(in, current);
        }
        case 78:
        {
            return ___setTotalFlow(in, current);
        }
        case 79:
        {
            return ___setTotalFlowResult(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
VENTC::VentComponentRW::__write(::IceInternal::BasicStream* __os) const
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
VENTC::VentComponentRW::__read(::IceInternal::BasicStream* __is, bool __rid)
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
VENTC::VentComponentRW::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type VENTC::VentComponentRW was not generated with stream support";
    throw ex;
}

void
VENTC::VentComponentRW::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type VENTC::VentComponentRW was not generated with stream support";
    throw ex;
}

void 
VENTC::__patch__VentComponentRWPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::VENTC::VentComponentRWPtr* p = static_cast< ::VENTC::VentComponentRWPtr*>(__addr);
    assert(p);
    *p = ::VENTC::VentComponentRWPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::VENTC::VentComponentRW::ice_staticId();
        throw e;
    }
}

bool
VENTC::operator==(const ::VENTC::VentComponentRW& l, const ::VENTC::VentComponentRW& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
VENTC::operator!=(const ::VENTC::VentComponentRW& l, const ::VENTC::VentComponentRW& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
VENTC::operator<(const ::VENTC::VentComponentRW& l, const ::VENTC::VentComponentRW& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
VENTC::operator<=(const ::VENTC::VentComponentRW& l, const ::VENTC::VentComponentRW& r)
{
    return l < r || l == r;
}

bool
VENTC::operator>(const ::VENTC::VentComponentRW& l, const ::VENTC::VentComponentRW& r)
{
    return !(l < r) && !(l == r);
}

bool
VENTC::operator>=(const ::VENTC::VentComponentRW& l, const ::VENTC::VentComponentRW& r)
{
    return !(l < r);
}
