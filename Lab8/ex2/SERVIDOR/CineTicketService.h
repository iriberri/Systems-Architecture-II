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
// Generated from file `CineTicketService.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __CineTicketService_h__
#define __CineTicketService_h__

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

class CineTicketService;
void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::UC3M::CineTicketService>&);
::IceProxy::Ice::Object* upCast(::IceProxy::UC3M::CineTicketService*);

}

}

namespace UC3M
{

class CineTicketService;
bool operator==(const CineTicketService&, const CineTicketService&);
bool operator<(const CineTicketService&, const CineTicketService&);
::Ice::Object* upCast(::UC3M::CineTicketService*);
typedef ::IceInternal::Handle< ::UC3M::CineTicketService> CineTicketServicePtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::UC3M::CineTicketService> CineTicketServicePrx;
void __patch(CineTicketServicePtr&, const ::Ice::ObjectPtr&);

}

namespace UC3M
{

typedef ::std::map< ::Ice::Int, ::Ice::Int> Seats;

struct consultasesion
{
    ::Ice::Int hora;
    ::UC3M::Seats s;
};

}

namespace Ice
{
template<>
struct StreamableTraits< ::UC3M::consultasesion>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 5;
    static const bool fixedLength = false;
};

template<class S>
struct StreamWriter< ::UC3M::consultasesion, S>
{
    static void write(S* __os, const ::UC3M::consultasesion& v)
    {
        __os->write(v.hora);
        __os->write(v.s);
    }
};

template<class S>
struct StreamReader< ::UC3M::consultasesion, S>
{
    static void read(S* __is, ::UC3M::consultasesion& v)
    {
        __is->read(v.hora);
        __is->read(v.s);
    }
};

}

namespace UC3M
{

class Callback_CineTicketService_consulta_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_CineTicketService_consulta_Base> Callback_CineTicketService_consultaPtr;

class Callback_CineTicketService_reserva_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_CineTicketService_reserva_Base> Callback_CineTicketService_reservaPtr;

class Callback_CineTicketService_cancela_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_CineTicketService_cancela_Base> Callback_CineTicketService_cancelaPtr;

}

namespace IceProxy
{

namespace UC3M
{

class CineTicketService : virtual public ::IceProxy::Ice::Object
{
public:

    ::UC3M::consultasesion consulta(::Ice::Int horaSesion)
    {
        return consulta(horaSesion, 0);
    }
    ::UC3M::consultasesion consulta(::Ice::Int horaSesion, const ::Ice::Context& __ctx)
    {
        return consulta(horaSesion, &__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_consulta(::Ice::Int horaSesion, const ::IceInternal::Function<void (const ::UC3M::consultasesion&)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_consulta(horaSesion, 0, response, exception, sent);
    }
    ::Ice::AsyncResultPtr
    begin_consulta(::Ice::Int horaSesion, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_consulta(horaSesion, 0, ::Ice::newCallback(completed, sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_consulta(::Ice::Int horaSesion, const ::Ice::Context& ctx, const ::IceInternal::Function<void (const ::UC3M::consultasesion&)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_consulta(horaSesion, &ctx, response, exception, sent);
    }
    ::Ice::AsyncResultPtr
    begin_consulta(::Ice::Int horaSesion, const ::Ice::Context& ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_consulta(horaSesion, &ctx, ::Ice::newCallback(completed, sent));
    }
    
private:

    ::Ice::AsyncResultPtr __begin_consulta(::Ice::Int horaSesion, const ::Ice::Context* ctx, const ::IceInternal::Function<void (const ::UC3M::consultasesion&)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception, const ::IceInternal::Function<void (bool)>& sent)
    {
        class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
        {
        public:

            Cpp11CB(const ::std::function<void (const ::UC3M::consultasesion&)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
                ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
                _response(responseFunc)
            {
                CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
            }

            virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
            {
                ::UC3M::CineTicketServicePrx __proxy = ::UC3M::CineTicketServicePrx::uncheckedCast(__result->getProxy());
                ::UC3M::consultasesion __ret;
                try
                {
                    __ret = __proxy->end_consulta(__result);
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
            
            ::std::function<void (const ::UC3M::consultasesion&)> _response;
        };
        return begin_consulta(horaSesion, ctx, new Cpp11CB(response, exception, sent));
    }
    
public:
#endif

    ::Ice::AsyncResultPtr begin_consulta(::Ice::Int horaSesion)
    {
        return begin_consulta(horaSesion, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_consulta(::Ice::Int horaSesion, const ::Ice::Context& __ctx)
    {
        return begin_consulta(horaSesion, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_consulta(::Ice::Int horaSesion, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_consulta(horaSesion, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_consulta(::Ice::Int horaSesion, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_consulta(horaSesion, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_consulta(::Ice::Int horaSesion, const ::UC3M::Callback_CineTicketService_consultaPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_consulta(horaSesion, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_consulta(::Ice::Int horaSesion, const ::Ice::Context& __ctx, const ::UC3M::Callback_CineTicketService_consultaPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_consulta(horaSesion, &__ctx, __del, __cookie);
    }

    ::UC3M::consultasesion end_consulta(const ::Ice::AsyncResultPtr&);
    
private:

    ::UC3M::consultasesion consulta(::Ice::Int, const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_consulta(::Ice::Int, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:

    ::Ice::Int reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca)
    {
        return reserva(horaSesion, numeroButaca, 0);
    }
    ::Ice::Int reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context& __ctx)
    {
        return reserva(horaSesion, numeroButaca, &__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::IceInternal::Function<void (::Ice::Int)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_reserva(horaSesion, numeroButaca, 0, response, exception, sent);
    }
    ::Ice::AsyncResultPtr
    begin_reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_reserva(horaSesion, numeroButaca, 0, ::Ice::newCallback(completed, sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context& ctx, const ::IceInternal::Function<void (::Ice::Int)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_reserva(horaSesion, numeroButaca, &ctx, response, exception, sent);
    }
    ::Ice::AsyncResultPtr
    begin_reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context& ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_reserva(horaSesion, numeroButaca, &ctx, ::Ice::newCallback(completed, sent));
    }
    
private:

    ::Ice::AsyncResultPtr __begin_reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context* ctx, const ::IceInternal::Function<void (::Ice::Int)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception, const ::IceInternal::Function<void (bool)>& sent)
    {
        class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
        {
        public:

            Cpp11CB(const ::std::function<void (::Ice::Int)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
                ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
                _response(responseFunc)
            {
                CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
            }

            virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
            {
                ::UC3M::CineTicketServicePrx __proxy = ::UC3M::CineTicketServicePrx::uncheckedCast(__result->getProxy());
                ::Ice::Int __ret;
                try
                {
                    __ret = __proxy->end_reserva(__result);
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
            
            ::std::function<void (::Ice::Int)> _response;
        };
        return begin_reserva(horaSesion, numeroButaca, ctx, new Cpp11CB(response, exception, sent));
    }
    
public:
#endif

    ::Ice::AsyncResultPtr begin_reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca)
    {
        return begin_reserva(horaSesion, numeroButaca, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context& __ctx)
    {
        return begin_reserva(horaSesion, numeroButaca, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_reserva(horaSesion, numeroButaca, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_reserva(horaSesion, numeroButaca, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::UC3M::Callback_CineTicketService_reservaPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_reserva(horaSesion, numeroButaca, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_reserva(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context& __ctx, const ::UC3M::Callback_CineTicketService_reservaPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_reserva(horaSesion, numeroButaca, &__ctx, __del, __cookie);
    }

    ::Ice::Int end_reserva(const ::Ice::AsyncResultPtr&);
    
private:

    ::Ice::Int reserva(::Ice::Int, ::Ice::Int, const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_reserva(::Ice::Int, ::Ice::Int, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:

    ::Ice::Int cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca)
    {
        return cancela(horaSesion, numeroButaca, 0);
    }
    ::Ice::Int cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context& __ctx)
    {
        return cancela(horaSesion, numeroButaca, &__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::IceInternal::Function<void (::Ice::Int)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_cancela(horaSesion, numeroButaca, 0, response, exception, sent);
    }
    ::Ice::AsyncResultPtr
    begin_cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_cancela(horaSesion, numeroButaca, 0, ::Ice::newCallback(completed, sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context& ctx, const ::IceInternal::Function<void (::Ice::Int)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_cancela(horaSesion, numeroButaca, &ctx, response, exception, sent);
    }
    ::Ice::AsyncResultPtr
    begin_cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context& ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_cancela(horaSesion, numeroButaca, &ctx, ::Ice::newCallback(completed, sent));
    }
    
private:

    ::Ice::AsyncResultPtr __begin_cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context* ctx, const ::IceInternal::Function<void (::Ice::Int)>& response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& exception, const ::IceInternal::Function<void (bool)>& sent)
    {
        class Cpp11CB : public ::IceInternal::Cpp11FnCallbackNC
        {
        public:

            Cpp11CB(const ::std::function<void (::Ice::Int)>& responseFunc, const ::std::function<void (const ::Ice::Exception&)>& exceptionFunc, const ::std::function<void (bool)>& sentFunc) :
                ::IceInternal::Cpp11FnCallbackNC(exceptionFunc, sentFunc),
                _response(responseFunc)
            {
                CallbackBase::checkCallback(true, responseFunc || exceptionFunc != nullptr);
            }

            virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
            {
                ::UC3M::CineTicketServicePrx __proxy = ::UC3M::CineTicketServicePrx::uncheckedCast(__result->getProxy());
                ::Ice::Int __ret;
                try
                {
                    __ret = __proxy->end_cancela(__result);
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
            
            ::std::function<void (::Ice::Int)> _response;
        };
        return begin_cancela(horaSesion, numeroButaca, ctx, new Cpp11CB(response, exception, sent));
    }
    
public:
#endif

    ::Ice::AsyncResultPtr begin_cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca)
    {
        return begin_cancela(horaSesion, numeroButaca, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context& __ctx)
    {
        return begin_cancela(horaSesion, numeroButaca, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_cancela(horaSesion, numeroButaca, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_cancela(horaSesion, numeroButaca, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::UC3M::Callback_CineTicketService_cancelaPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_cancela(horaSesion, numeroButaca, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_cancela(::Ice::Int horaSesion, ::Ice::Int numeroButaca, const ::Ice::Context& __ctx, const ::UC3M::Callback_CineTicketService_cancelaPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_cancela(horaSesion, numeroButaca, &__ctx, __del, __cookie);
    }

    ::Ice::Int end_cancela(const ::Ice::AsyncResultPtr&);
    
private:

    ::Ice::Int cancela(::Ice::Int, ::Ice::Int, const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_cancela(::Ice::Int, ::Ice::Int, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_secure(bool __secure) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_twoway() const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_oneway() const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_batchOneway() const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_datagram() const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_batchDatagram() const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_compress(bool __compress) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_timeout(int __timeout) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<CineTicketService> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<CineTicketService*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
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

class CineTicketService : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::UC3M::consultasesion consulta(::Ice::Int, const ::Ice::Context*, ::IceInternal::InvocationObserver&) = 0;

    virtual ::Ice::Int reserva(::Ice::Int, ::Ice::Int, const ::Ice::Context*, ::IceInternal::InvocationObserver&) = 0;

    virtual ::Ice::Int cancela(::Ice::Int, ::Ice::Int, const ::Ice::Context*, ::IceInternal::InvocationObserver&) = 0;
};

}

}

namespace IceDelegateM
{

namespace UC3M
{

class CineTicketService : virtual public ::IceDelegate::UC3M::CineTicketService,
                          virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::UC3M::consultasesion consulta(::Ice::Int, const ::Ice::Context*, ::IceInternal::InvocationObserver&);

    virtual ::Ice::Int reserva(::Ice::Int, ::Ice::Int, const ::Ice::Context*, ::IceInternal::InvocationObserver&);

    virtual ::Ice::Int cancela(::Ice::Int, ::Ice::Int, const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace IceDelegateD
{

namespace UC3M
{

class CineTicketService : virtual public ::IceDelegate::UC3M::CineTicketService,
                          virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::UC3M::consultasesion consulta(::Ice::Int, const ::Ice::Context*, ::IceInternal::InvocationObserver&);

    virtual ::Ice::Int reserva(::Ice::Int, ::Ice::Int, const ::Ice::Context*, ::IceInternal::InvocationObserver&);

    virtual ::Ice::Int cancela(::Ice::Int, ::Ice::Int, const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace UC3M
{

class CineTicketService : virtual public ::Ice::Object
{
public:

    typedef CineTicketServicePrx ProxyType;
    typedef CineTicketServicePtr PointerType;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::UC3M::consultasesion consulta(::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___consulta(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int reserva(::Ice::Int, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___reserva(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int cancela(::Ice::Int, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___cancela(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    #ifdef __SUNPRO_CC
    using ::Ice::Object::__writeImpl;
    using ::Ice::Object::__readImpl;
    #endif
};

inline bool operator==(const CineTicketService& l, const CineTicketService& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const CineTicketService& l, const CineTicketService& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

}

namespace UC3M
{

template<class T>
class CallbackNC_CineTicketService_consulta : public Callback_CineTicketService_consulta_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(const ::UC3M::consultasesion&);

    CallbackNC_CineTicketService_consulta(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::UC3M::CineTicketServicePrx __proxy = ::UC3M::CineTicketServicePrx::uncheckedCast(__result->getProxy());
        ::UC3M::consultasesion __ret;
        try
        {
            __ret = __proxy->end_consulta(__result);
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

template<class T> Callback_CineTicketService_consultaPtr
newCallback_CineTicketService_consulta(const IceUtil::Handle<T>& instance, void (T::*cb)(const ::UC3M::consultasesion&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CineTicketService_consulta<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_CineTicketService_consultaPtr
newCallback_CineTicketService_consulta(T* instance, void (T::*cb)(const ::UC3M::consultasesion&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CineTicketService_consulta<T>(instance, cb, excb, sentcb);
}

template<class T, typename CT>
class Callback_CineTicketService_consulta : public Callback_CineTicketService_consulta_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const ::UC3M::consultasesion&, const CT&);

    Callback_CineTicketService_consulta(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::UC3M::CineTicketServicePrx __proxy = ::UC3M::CineTicketServicePrx::uncheckedCast(__result->getProxy());
        ::UC3M::consultasesion __ret;
        try
        {
            __ret = __proxy->end_consulta(__result);
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

template<class T, typename CT> Callback_CineTicketService_consultaPtr
newCallback_CineTicketService_consulta(const IceUtil::Handle<T>& instance, void (T::*cb)(const ::UC3M::consultasesion&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CineTicketService_consulta<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_CineTicketService_consultaPtr
newCallback_CineTicketService_consulta(T* instance, void (T::*cb)(const ::UC3M::consultasesion&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CineTicketService_consulta<T, CT>(instance, cb, excb, sentcb);
}

template<class T>
class CallbackNC_CineTicketService_reserva : public Callback_CineTicketService_reserva_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(::Ice::Int);

    CallbackNC_CineTicketService_reserva(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::UC3M::CineTicketServicePrx __proxy = ::UC3M::CineTicketServicePrx::uncheckedCast(__result->getProxy());
        ::Ice::Int __ret;
        try
        {
            __ret = __proxy->end_reserva(__result);
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

template<class T> Callback_CineTicketService_reservaPtr
newCallback_CineTicketService_reserva(const IceUtil::Handle<T>& instance, void (T::*cb)(::Ice::Int), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CineTicketService_reserva<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_CineTicketService_reservaPtr
newCallback_CineTicketService_reserva(T* instance, void (T::*cb)(::Ice::Int), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CineTicketService_reserva<T>(instance, cb, excb, sentcb);
}

template<class T, typename CT>
class Callback_CineTicketService_reserva : public Callback_CineTicketService_reserva_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(::Ice::Int, const CT&);

    Callback_CineTicketService_reserva(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::UC3M::CineTicketServicePrx __proxy = ::UC3M::CineTicketServicePrx::uncheckedCast(__result->getProxy());
        ::Ice::Int __ret;
        try
        {
            __ret = __proxy->end_reserva(__result);
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

template<class T, typename CT> Callback_CineTicketService_reservaPtr
newCallback_CineTicketService_reserva(const IceUtil::Handle<T>& instance, void (T::*cb)(::Ice::Int, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CineTicketService_reserva<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_CineTicketService_reservaPtr
newCallback_CineTicketService_reserva(T* instance, void (T::*cb)(::Ice::Int, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CineTicketService_reserva<T, CT>(instance, cb, excb, sentcb);
}

template<class T>
class CallbackNC_CineTicketService_cancela : public Callback_CineTicketService_cancela_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(::Ice::Int);

    CallbackNC_CineTicketService_cancela(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::UC3M::CineTicketServicePrx __proxy = ::UC3M::CineTicketServicePrx::uncheckedCast(__result->getProxy());
        ::Ice::Int __ret;
        try
        {
            __ret = __proxy->end_cancela(__result);
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

template<class T> Callback_CineTicketService_cancelaPtr
newCallback_CineTicketService_cancela(const IceUtil::Handle<T>& instance, void (T::*cb)(::Ice::Int), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CineTicketService_cancela<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_CineTicketService_cancelaPtr
newCallback_CineTicketService_cancela(T* instance, void (T::*cb)(::Ice::Int), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CineTicketService_cancela<T>(instance, cb, excb, sentcb);
}

template<class T, typename CT>
class Callback_CineTicketService_cancela : public Callback_CineTicketService_cancela_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(::Ice::Int, const CT&);

    Callback_CineTicketService_cancela(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::UC3M::CineTicketServicePrx __proxy = ::UC3M::CineTicketServicePrx::uncheckedCast(__result->getProxy());
        ::Ice::Int __ret;
        try
        {
            __ret = __proxy->end_cancela(__result);
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

template<class T, typename CT> Callback_CineTicketService_cancelaPtr
newCallback_CineTicketService_cancela(const IceUtil::Handle<T>& instance, void (T::*cb)(::Ice::Int, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CineTicketService_cancela<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_CineTicketService_cancelaPtr
newCallback_CineTicketService_cancela(T* instance, void (T::*cb)(::Ice::Int, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CineTicketService_cancela<T, CT>(instance, cb, excb, sentcb);
}

}

#endif
