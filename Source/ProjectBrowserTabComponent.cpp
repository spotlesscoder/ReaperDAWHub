#include "../includes/ProjectBrowserTabComponent.h"

ProjectBrowserTabComponent::ProjectBrowserTabComponent() : TabbedComponent(TabbedButtonBar::TabsAtTop) {
	addTab("Remote projects", Colours::lightgrey, new ProjectEntryListComponent(), true);
	addTab("Local projects", Colours::lightgrey, new ProjectEntryListComponent(), true);
	addTab("Shared projects", Colours::lightgrey, new ProjectEntryListComponent(), true);
	setSize(getLocalBounds().getWidth(), getLocalBounds().getHeight());
}

ProjectBrowserTabComponent::~ProjectBrowserTabComponent() {
}
