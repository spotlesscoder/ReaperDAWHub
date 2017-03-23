#pragma once
#include "../../includes/reaper_plugin_functions.h"
#include "../../includes/action_entry.h"
#include "LoginWindowComponent.h"
class LoginWindow : public ResizableWindow
{
public:
	LoginWindow(const String name);
	int getDesktopWindowStyleFlags() const override;
	void userTriedToCloseWindow() override;

private:
	LoginWindowComponent m_login;
};