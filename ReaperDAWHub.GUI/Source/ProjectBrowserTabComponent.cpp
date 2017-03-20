#include "../includes/ProjectBrowserTabComponent.h"
#include "../includes/LocalProjectEntryComponent.h"
#include "../includes/TabBarNotifyComponent.h"

ProjectBrowserTabComponent::ProjectBrowserTabComponent() : TabbedComponent(TabbedButtonBar::TabsAtTop) {
	ProjectEntryListComponent *pelc = new ProjectEntryListComponent();
	LocalProjectEntryComponent *lpec = new LocalProjectEntryComponent();
<<<<<<< HEAD
	pelc->addListEntry(*lpec);
=======
	pelc->addListEntry(lpec);
>>>>>>> parent of 0d78d6d... apply mvc pattern
	addTab("Remote projects", Colours::lightgrey, new ProjectEntryListComponent(), true);
	addTab("Local projects", Colours::lightgrey, pelc, true);
	addTab("Shared projects", Colours::lightgrey, new ProjectEntryListComponent(), true);
	setSize(getLocalBounds().getWidth(), getLocalBounds().getHeight());
	TabBarNotifyComponent *tbnc = new TabBarNotifyComponent();
	tbnc->notify();
	tbnc->init(getTabbedButtonBar().getTabButton(2));
	getTabbedButtonBar().getTabButton(2)->setExtraComponent(tbnc, TabBarButton::afterText);
}

ProjectBrowserTabComponent::~ProjectBrowserTabComponent() {
}
