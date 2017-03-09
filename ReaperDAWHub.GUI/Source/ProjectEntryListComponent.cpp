#include "../includes/ProjectEntryListComponent.h"
#include "../includes/LocalProjectEntryComponent.h"

ProjectEntryListComponent::ProjectEntryListComponent() {
	setSize(500, 600);
	addListEntry((*(new ProjectEntryComponent())));
}

ProjectEntryListComponent::~ProjectEntryListComponent() {

}

void ProjectEntryListComponent::addListEntry(ProjectEntryComponent &pec) {
	addListEntryComponent(pec);
}

void ProjectEntryListComponent::addListEntry(LocalProjectEntryComponent &pec) {
	addListEntryComponent(pec);
}

void ProjectEntryListComponent::addListEntryComponent(Component &pec) {
	listEntries.push_back(&pec);
	addAndMakeVisible(pec);
	pec.setBounds(0, 60 * listEntries.size() - 1, getLocalBounds().getWidth(), 60);
}

void ProjectEntryListComponent::resized() {

}