#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "GUIConstants.h"
#include "ProjectEntryComponent.h"
#include "LocalProjectEntryComponent.h"
#include "ProjectBrowserTabComponent.h"
#include "ProjectEntryListComponent.h"

class ProjectBrowserComponent : public Component
{
public:
	ProjectBrowserComponent();
	~ProjectBrowserComponent();
	void resized() override;


private:
	GroupComponent g_group;
	TextButton m_btn;
	Label lbl_name;
	Label lbl_version;
	ProjectBrowserTabComponent m_tabs;
};