#include "../includes/ProjectBrowserTabComponent.h"
#include "../includes/TabBarNotifyComponent.h"

ProjectBrowserTabComponent::ProjectBrowserTabComponent() : TabbedComponent(TabbedButtonBar::TabsAtTop) {
	addTab("Remote projects", Colours::lightgrey, new ProjectEntryListComponent(), true);
	addTab("Local projects", Colours::lightgrey, new ProjectEntryListComponent(), true);
	addTab("Shared projects", Colours::lightgrey, new ProjectEntryListComponent(), true);
	setSize(getLocalBounds().getWidth(), getLocalBounds().getHeight());
	TabBarNotifyComponent *tbnc = new TabBarNotifyComponent();
	tbnc->notify();
	tbnc->init(getTabbedButtonBar().getTabButton(2));
	getTabbedButtonBar().getTabButton(2)->setExtraComponent(tbnc, TabBarButton::afterText);
}

ProjectBrowserTabComponent::~ProjectBrowserTabComponent() {
}
