#include "../includes/ProjectBrowserTabComponent.h"
#include "../includes/LocalProjectEntryComponent.h"
#include "../includes/TabBarNotifyComponent.h"

void ProjectBrowserTabComponent::initTabBarNotifyComponent()
{
	TabBarNotifyComponent *tbnc = new TabBarNotifyComponent();
	tbnc->notify();
	tbnc->init(getTabbedButtonBar().getTabButton(2));
	getTabbedButtonBar().getTabButton(2)->setExtraComponent(tbnc, TabBarButton::afterText);
}

void ProjectBrowserTabComponent::initViewport(Viewport *viewport, ProjectEntryListComponent *component)
{
	viewport->setSize(100, 200);
	viewport->setViewedComponent(component, false);
	viewport->setScrollBarsShown(true, false);
}

void ProjectBrowserTabComponent::initComponents()
{
	this->initViewport(vp_local, m_local_proj);
	this->initViewport(vp_shared, m_shared_proj);
	this->initViewport(vp_remote, m_remote_proj);
	addTab("Remote projects", Colours::lightgrey, vp_remote, true);
	addTab("Local projects", Colours::lightgrey, vp_local, false);
	addTab("Shared projects", Colours::lightgrey, vp_shared, false);
	setSize(getLocalBounds().getWidth(), getLocalBounds().getHeight());
	initTabBarNotifyComponent();
}

ProjectBrowserTabComponent::ProjectBrowserTabComponent() : TabbedComponent(TabbedButtonBar::TabsAtTop) {
	initComponents();
	pelcLocal = new ProjectEntryListController(m_local_proj);
	pelcRemote = new ProjectEntryListController(m_remote_proj);
	pelcShared = new ProjectEntryListController(m_shared_proj);
}

ProjectBrowserTabComponent::~ProjectBrowserTabComponent() {
	delete m_local_proj;
}
