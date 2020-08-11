#define CINTERFACE
#define UNICODE
#define _UNICODE
#include "event.h"
#include "WebView2.h"
#include <typeinfo>
#include <cstddef>
#include <cstdint>

template <class Class, std::size_t Offset, class Member>
Class* MemberToClassImpl(Member* m)
{
	return reinterpret_cast<Class*>(reinterpret_cast<uint8_t*>(m) - Offset);
}

#define MemberToClass(CLASS, MEMBER, PTR) MemberToClassImpl<CLASS, offsetof(CLASS, MEMBER)>(PTR)

static HRESULT STDMETHODCALLTYPE EventInterfaces_EnvironmentCompleted_QueryInterface(
	ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler* This, REFIID riid, void** ppvObject)
{
	return S_OK;
}

static ULONG STDMETHODCALLTYPE EventInterfaces_EnvironmentCompleted_AddRef(
	ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler* This)
{
	return 1;
}

static ULONG STDMETHODCALLTYPE EventInterfaces_EnvironmentCompleted_Release(
	ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler* This)
{
	return 1;
}

static HRESULT STDMETHODCALLTYPE EventInterfaces_EnvironmentCompleted_Invoke(
	ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler* This, HRESULT result,
	ICoreWebView2Environment* created_environment)
{
	return MemberToClass(EventInterfaces, EnvironmentCompletedHandler, This)->Parent->EnvironmentCompleted(
		result, created_environment);
}

static ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandlerVtbl EventInterfaces_EnvironmentCompletedHandlerVtbl =
{
	EventInterfaces_EnvironmentCompleted_QueryInterface,
	EventInterfaces_EnvironmentCompleted_AddRef,
	EventInterfaces_EnvironmentCompleted_Release,
	EventInterfaces_EnvironmentCompleted_Invoke,
};


static HRESULT STDMETHODCALLTYPE EventInterfaces_ControllerCompleted_QueryInterface(
	ICoreWebView2CreateCoreWebView2ControllerCompletedHandler* This, REFIID riid, void** ppvObject)
{
	return S_OK;
}

static ULONG STDMETHODCALLTYPE EventInterfaces_ControllerCompleted_AddRef(
	ICoreWebView2CreateCoreWebView2ControllerCompletedHandler* This)
{
	return 1;
}

static ULONG STDMETHODCALLTYPE EventInterfaces_ControllerCompleted_Release(
	ICoreWebView2CreateCoreWebView2ControllerCompletedHandler* This)
{
	return 1;
}

static HRESULT STDMETHODCALLTYPE EventInterfaces_ControllerCompleted_Invoke(
	ICoreWebView2CreateCoreWebView2ControllerCompletedHandler* This, HRESULT result,
	ICoreWebView2Controller* controller)
{
	return MemberToClass(EventInterfaces, ControllerCompletedHandler, This)->Parent->ControllerCompleted(
		result, controller);
}

static ICoreWebView2CreateCoreWebView2ControllerCompletedHandlerVtbl EventInterfaces_ControllerCompletedHandlerVtbl = {
	EventInterfaces_ControllerCompleted_QueryInterface,
	EventInterfaces_ControllerCompleted_AddRef,
	EventInterfaces_ControllerCompleted_Release,
	EventInterfaces_ControllerCompleted_Invoke,
};


EventInterfaces::EventInterfaces(EventHandler* parent): Parent(parent)
{
	EnvironmentCompletedHandler.lpVtbl = &EventInterfaces_EnvironmentCompletedHandlerVtbl;
	ControllerCompletedHandler.lpVtbl = &EventInterfaces_ControllerCompletedHandlerVtbl;
}

EventHandler::EventHandler() : Intf(this)
{
}

EventHandler::~EventHandler() = default;
