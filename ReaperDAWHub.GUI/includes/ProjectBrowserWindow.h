#pragma once
#include "../../includes/reaper_plugin_functions.h"
#include "../../includes/action_entry.h"
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../../includes/Main.h"
#include "ProjectBrowserComponent.h"

class ProjectBrowserWindow : public DocumentWindow
{
public:
	ProjectBrowserWindow(const String name);
	int getDesktopWindowStyleFlags() const override;
	void userTriedToCloseWindow() override;

private:
	ProjectBrowserComponent m_projbrowser;
};