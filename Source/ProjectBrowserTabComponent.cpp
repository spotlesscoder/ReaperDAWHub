#include "../includes/ProjectBrowserTabComponent.h"
#include "../includes/TabBarNotifyComponent.h"

ProjectBrowserTabComponent::ProjectBrowserTabComponent() : TabbedComponent(TabbedButtonBar::TabsAtTop) {
	addTab("Remote projects", Colours::lightgrey, new ProjectEntryListComponent(), true);
	addTab("Local projects", Colours::lightgrey, new ProjectEntryListComponent(), true);
	addTab("Shared projects", Colours::lightgrey, new ProjectEntryListComponent(), true);
	setSize(getLocalBounds().getWidth(), getLocalBounds().getHeight());
	TabBarNotifyComponent *tbnc = new TabBarNotifyComponent();
	tbnc->notify();
	getTabbedButtonBar().getTabButton(2)->setExtraComponent(tbnc, TabBarButton::afterText);
	const Rectangle<int> bounds = getTabbedButtonBar().getTabButton(2)->getBounds();
	getTabbedButtonBar().getTabButton(2)->setBounds(bounds.getX(), bounds.getY(), bounds.getWidth() - 10, bounds.getHeight());
	tbnc->setBounds(-20, 0, (*(tbnc)).getWidth(), (*(tbnc)).getHeight());
}

ProjectBrowserTabComponent::~ProjectBrowserTabComponent() {
}
