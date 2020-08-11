#pragma once
#define CINTERFACE
#include <functional>

#include "WebView2.h"

// This is a separate class because it needs to be standard-layout.
struct EventInterfaces
{
	EventInterfaces(class EventHandler* parent);

	class EventHandler* Parent;
	ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler EnvironmentCompletedHandler{};
	ICoreWebView2CreateCoreWebView2ControllerCompletedHandler ControllerCompletedHandler{};
};

class EventHandler
{
public:
	EventHandler();
	virtual ~EventHandler();

	EventHandler(const EventHandler&) = delete;
	EventHandler(EventHandler&&) = delete;
	EventHandler& operator=(const EventHandler&) = delete;
	EventHandler& operator=(EventHandler&&) = delete;

	std::function<HRESULT(HRESULT result, ICoreWebView2Environment* created_environment)> EnvironmentCompleted;
	std::function<HRESULT(HRESULT result, ICoreWebView2Controller* controller)> ControllerCompleted;

	EventInterfaces Intf;
};
