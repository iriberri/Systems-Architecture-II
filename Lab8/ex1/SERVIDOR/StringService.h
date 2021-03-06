// **********************************************************************
//
// Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.5.0
//
// <auto-generated>
//
// Generated from file `StringService.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __StringService_h__
#define __StringService_h__

#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <IceUtil/ScopedArray.h>
#include <IceUtil/Optional.h>
#include <Ice/StreamF.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 305
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 0
#       error Ice patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace UC3M
{

class AgendaService;
void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::UC3M::AgendaService>&);
::IceProxy::Ice::Object* upCast(::IceProxy::UC3M::AgendaService*);

}

}

namespace UC3M
{

class AgendaService;
bool operator==(const AgendaService&, const AgendaService&);
bool operator<(const AgendaService&, const AgendaService&);
::Ice::Object* upCast(::UC3M::AgendaService*);
typedef ::IceInternal::Handle< ::UC3M::AgendaService> AgendaServicePtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::UC3M::AgendaService> AgendaServicePrx;
void __patch(AgendaServicePtr&, const ::Ice::ObjectPtr&);

}

namespace UC3M
{

struct informacionSt
{
    ::std::string nombre;
    ::std::string apellido;
    ::Ice::Int edad;

    bool operator==(const informacionSt& __rhs) const
    {
        if(this == &__rhs)
        {
            return true;
        }
        if(nombre != __rhs.nombre)
        {
            return false;
        }
        if(apellido != __rhs.apellido)
        {
            return false;
        }
        if(edad != __rhs.edad)
        {
            return false;
        }
        return true;
    }

    bool operator<(const informacionSt& __rhs) const
    {
        if(this == &__rhs)
        {
            return false;
        }
        if(nombre < __rhs.nombre)
        {
            return true;
        }
        else if(__rhs.nombre < nombre)
        {
            return false;
        }
        if(apellido < __rhs.apellido)
        {
            return true;
        }
        else if(__rhs.apellido < apellido)
        {
            return false;
        }
        if(edad < __rhs.edad)
        {
            return true;
        }
        else if(__rhs.edad < edad)
        {
            return false;
        }
        return false;
    }

    bool operator!=(const informacionSt& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const informacionSt& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const informacionSt& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const informacionSt& __rhs) const
    {
        return !operator<(__rhs);
    }
};

}

namespace Ice
{
template<>
struct StreamableTraits< ::UC3M::informacionSt>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 6;
    static const bool fixedLength = false;
};

template<class S>
struct StreamWriter< ::UC3M::informacionSt, S>
{
    static void write(S* __os, const ::UC3M::informacionSt& v)
    {
        __os->write(v.nombre);
        __os->write(v.apellido);
        __os->write(v.edad);
    }
};

template<class S>
struct StreamReader< ::UC3M::informacionSt, S>
{
    static void read(S* __is, ::UC3M::informacionSt& v)
    {
        __is->read(v.nombre);
        __is->read(v.apellido);
        __is->read(v.edad);
    }
};

}

namespace UC3M
{

class Callback_AgendaService_ask_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_AgendaService_ask_Base> Callback_AgendaService_askPtr;

}

namespace IceProxy
{

namespace UC3M
{

class AgendaService : virtual public ::IceProxy::Ice::Object
{
public:

    ::UC3M::informacionSt ask()
    {
        return ask(0);
    }
    ::UC3M::informacionSt ask(const ::Ice::Context& __ctx)
    {
        return ask(&__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_ask(const ::IceInternal::Function<void (const ::UC3M::informacionSt&)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_ask(0, response, exception, sent);
    }
    ::Ice::AsyncResultPtr
    begin_ask(const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_ask(0, ::Ice::newCallback(completed, sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_ask(const ::Ice::Context& ctx, const ::IceInternal::Function<void (const ::UC3M::informacionSt&)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_ask(&ctx, response, exception, sent);
    }
    ::Ice::AsyncResultPtr
    begin_ask(const ::Ice::Context& ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_ask(&ctx, ::Ice::newCallback(completed, sent));
    }
    
private:

    ::Ice::AsyncResultPtr __begin_ask(const ::Ice::Context* ctx, const ::IceInternal::Function<void (const ::UC3M::informacionSt&)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception, const ::IceInternal::Function<void (bool)>& sent)
    {
        class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
        {
        public:

            Cpp11CB(const ::std::function<void (const ::UC3M::informacionSt&)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
                ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
                _response(responseFunc)
            {
                CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
            }

            virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
            {
                ::UC3M::AgendaServicePrx __proxy = ::UC3M::AgendaServicePrx::uncheckedCast(__result->getProxy());
                ::UC3M::informacionSt __ret;
                try
                {
                    __ret = __proxy->end_ask(__result);
                }
                catch(::Ice::Exception& ex)
                {
                    Cpp11FnCallbackNC::__exception(__result, ex);
                    return;
                }
                if(_response != nullptr)
                {
                    _response(__ret);
                }
            }
        
        private:
            
            ::std::function<void (const ::UC3M::informacionSt&)> _response;
        };
        return begin_ask(ctx, new Cpp11CB(response, exception, sent));
    }
    
public:
#endif

    ::Ice::AsyncResultPtr begin_ask()
    {
        return begin_ask(0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_ask(const ::Ice::Context& __ctx)
    {
        return begin_ask(&__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_ask(const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_ask(0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_ask(const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_ask(&__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_ask(const ::UC3M::Callback_AgendaService_askPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_ask(0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_ask(const ::Ice::Context& __ctx, const ::UC3M::Callback_AgendaService_askPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_ask(&__ctx, __del, __cookie);
    }

    ::UC3M::informacionSt end_ask(const ::Ice::AsyncResultPtr&);
    
private:

    ::UC3M::informacionSt ask(const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_ask(const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:
    
    ::IceInternal::ProxyHandle<AgendaService> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_secure(bool __secure) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_twoway() const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_oneway() const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_batchOneway() const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_datagram() const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_batchDatagram() const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_compress(bool __compress) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_timeout(int __timeout) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<AgendaService> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<AgendaService*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

namespace IceDelegate
{

namespace UC3M
{

class AgendaService : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::UC3M::informacionSt ask(const ::Ice::Context*, ::IceInternal::InvocationObserver&) = 0;
};

}

}

namespace IceDelegateM
{

namespace UC3M
{

class AgendaService : virtual public ::IceDelegate::UC3M::AgendaService,
                      virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::UC3M::informacionSt ask(const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace IceDelegateD
{

namespace UC3M
{

class AgendaService : virtual public ::IceDelegate::UC3M::AgendaService,
                      virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::UC3M::informacionSt ask(const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace UC3M
{

class AgendaService : virtual public ::Ice::Object
{
public:

    typedef AgendaServicePrx ProxyType;
    typedef AgendaServicePtr PointerType;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::UC3M::informacionSt ask(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___ask(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    #ifdef __SUNPRO_CC
    using ::Ice::Object::__writeImpl;
    using ::Ice::Object::__readImpl;
    #endif
};

inline bool operator==(const AgendaService& l, const AgendaService& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const AgendaService& l, const AgendaService& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

}

namespace UC3M
{

template<class T>
class CallbackNC_AgendaService_ask : public Callback_AgendaService_ask_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(const ::UC3M::informacionSt&);

    CallbackNC_AgendaService_ask(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::UC3M::AgendaServicePrx __proxy = ::UC3M::AgendaServicePrx::uncheckedCast(__result->getProxy());
        ::UC3M::informacionSt __ret;
        try
        {
            __ret = __proxy->end_ask(__result);
        }
        catch(::Ice::Exception& ex)
        {
            ::IceInternal::CallbackNC<T>::__exception(__result, ex);
            return;
        }
        if(response)
        {
            (::IceInternal::CallbackNC<T>::callback.get()->*response)(__ret);
        }
    }

    Response response;
};

template<class T> Callback_AgendaService_askPtr
newCallback_AgendaService_ask(const IceUtil::Handle<T>& instance, void (T::*cb)(const ::UC3M::informacionSt&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_AgendaService_ask<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_AgendaService_askPtr
newCallback_AgendaService_ask(T* instance, void (T::*cb)(const ::UC3M::informacionSt&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_AgendaService_ask<T>(instance, cb, excb, sentcb);
}

template<class T, typename CT>
class Callback_AgendaService_ask : public Callback_AgendaService_ask_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const ::UC3M::informacionSt&, const CT&);

    Callback_AgendaService_ask(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::UC3M::AgendaServicePrx __proxy = ::UC3M::AgendaServicePrx::uncheckedCast(__result->getProxy());
        ::UC3M::informacionSt __ret;
        try
        {
            __ret = __proxy->end_ask(__result);
        }
        catch(::Ice::Exception& ex)
        {
            ::IceInternal::Callback<T, CT>::__exception(__result, ex);
            return;
        }
        if(response)
        {
            (::IceInternal::Callback<T, CT>::callback.get()->*response)(__ret, CT::dynamicCast(__result->getCookie()));
        }
    }

    Response response;
};

template<class T, typename CT> Callback_AgendaService_askPtr
newCallback_AgendaService_ask(const IceUtil::Handle<T>& instance, void (T::*cb)(const ::UC3M::informacionSt&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_AgendaService_ask<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_AgendaService_askPtr
newCallback_AgendaService_ask(T* instance, void (T::*cb)(const ::UC3M::informacionSt&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_AgendaService_ask<T, CT>(instance, cb, excb, sentcb);
}

}

#endif
