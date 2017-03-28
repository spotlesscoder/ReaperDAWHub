#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../../ReaperDAWHub.GUI.Controller/includes/ProjectEntryListController.h"
#include "ProjectEntryListComponent.h"
#include "LocalProjectEntryComponent.h"

class ProjectBrowserTabComponent : public TabbedComponent
{
public:
	ProjectBrowserTabComponent();
	~ProjectBrowserTabComponent();

private:
	ProjectEntryListComponent m_remote_proj;
	ProjectEntryListComponent m_local_proj;
	ProjectEntryComponent m_entry1;
	LocalProjectEntryComponent m_entry2;
	ProjectEntryListController *pelcont = new ProjectEntryListController(&m_remote_proj);
	ProjectEntryListController *pelccont2 = new ProjectEntryListController(&m_local_proj);
};