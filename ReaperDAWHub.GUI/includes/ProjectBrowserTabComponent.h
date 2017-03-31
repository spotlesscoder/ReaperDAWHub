#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../../ReaperDAWHub.GUI.Controller/includes/ProjectEntryListController.h"
#include "ProjectEntryListComponent.h"

class ProjectBrowserTabComponent : public TabbedComponent
{
public:
	ProjectBrowserTabComponent();
	~ProjectBrowserTabComponent();

private:
	void initTabBarNotifyComponent() const;
	void initViewport(Viewport *viewport, ProjectEntryListComponent *component) const;
	void initComponents();

	ScopedPointer<ProjectEntryListComponent> m_local_proj = new ProjectEntryListComponent();
	ScopedPointer<ProjectEntryListComponent> m_remote_proj = new ProjectEntryListComponent();
	ScopedPointer<ProjectEntryListComponent> m_shared_proj = new ProjectEntryListComponent();

	ProjectEntryListController *pelcLocal;
	ProjectEntryListController *pelcShared;
	ProjectEntryListController *pelcRemote;

	ScopedPointer<Viewport> vp_local = new Viewport;
	ScopedPointer<Viewport> vp_remote = new Viewport;
	ScopedPointer<Viewport> vp_shared = new Viewport;
};