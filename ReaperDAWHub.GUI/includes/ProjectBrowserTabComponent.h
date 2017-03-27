#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "ProjectEntryListComponent.h"
#include "LocalProjectEntryComponent.h"
#include "../../ReaperDAWHub.GUI.Controller/includes/ProjectEntryListController.h"

class ProjectBrowserTabComponent : public TabbedComponent
{
public:
	ProjectBrowserTabComponent();
	~ProjectBrowserTabComponent();
	void initProjects();

private:

	ProjectEntryListComponent m_remote_proj;
	ProjectEntryListComponent m_local_proj;
	ProjectEntryComponent m_entry1;
	LocalProjectEntryComponent m_entry2;
	ProjectEntryListController *pelcontroller;
};
