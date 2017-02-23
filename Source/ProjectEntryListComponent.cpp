#include "../includes/ProjectEntryListComponent.h"

ProjectEntryListComponent::ProjectEntryListComponent() {
	setSize(500, 600);
	addListEntry((*(new ProjectEntryComponent())));
}

ProjectEntryListComponent::~ProjectEntryListComponent() {

}

void ProjectEntryListComponent::addListEntry(ProjectEntryComponent &pec) {
	listEntries.push_back(&pec);
	addAndMakeVisible(pec);
	pec.setBounds(0, 100 * listEntries.size() - 1, getLocalBounds().getWidth(), 100);
}

void ProjectEntryListComponent::resized() {

}