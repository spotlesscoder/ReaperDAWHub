#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../includes/ProjectEntryComponent.h"

class ProjectEntryListComponent : public Component
{
public:
	ProjectEntryListComponent();
	~ProjectEntryListComponent();
	void resized() override;
	void addListEntry(ProjectEntryComponent &pec);

private:
	std::vector<ProjectEntryComponent *> listEntries = std::vector<ProjectEntryComponent *>();
};