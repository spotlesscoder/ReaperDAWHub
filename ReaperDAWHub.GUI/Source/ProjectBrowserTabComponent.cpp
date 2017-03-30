#include "../includes/ProjectBrowserTabComponent.h"
#include "../includes/LocalProjectEntryComponent.h"
#include "../includes/TabBarNotifyComponent.h"

ProjectBrowserTabComponent::ProjectBrowserTabComponent() : TabbedComponent(TabbedButtonBar::TabsAtTop) {
	ProjectEntryListComponent *pelc = new ProjectEntryListComponent();
	LocalProjectEntryComponent *lpec = new LocalProjectEntryComponent();
	viewport_local_proj.setViewedComponent(&m_local_proj, true);
	viewport_local_proj.setSize(200, 500);
	viewport_local_proj.setScrollBarsShown(true, false);
	pelc->addListEntry(lpec);
	addTab("Remote projects", Colours::lightgrey, &m_remote_proj, true);
	addTab("Local projects", Colours::lightgrey, &viewport_local_proj, true);
	addTab("Shared projects", Colours::lightgrey, new ProjectEntryListComponent(), true);
	setSize(getLocalBounds().getWidth(), getLocalBounds().getHeight());
	TabBarNotifyComponent *tbnc = new TabBarNotifyComponent();
	tbnc->notify();
	tbnc->init(getTabbedButtonBar().getTabButton(2));
	getTabbedButtonBar().getTabButton(2)->setExtraComponent(tbnc, TabBarButton::afterText);
	pelcont = new ProjectEntryListController(&m_local_proj);
}

ProjectBrowserTabComponent::~ProjectBrowserTabComponent() {
}
