#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "GUIConstants.h"
#include "ProjectBrowserTabComponent.h"
#include "../includes/ButtonListenerHandler.h"
#include "../../ReaperDAWHub.Controller/includes/ProjectsController.h"


class ProjectBrowserComponent : public Component, public ButtonListenerHandler
{
public:
	ProjectBrowserComponent();
	~ProjectBrowserComponent();
	void resized() override;
	void initProjects();

private:
	GroupComponent g_group;
	TextButton m_btn;
	Label lbl_name;
	Label lbl_version;
	ProjectBrowserTabComponent m_tabs;
};