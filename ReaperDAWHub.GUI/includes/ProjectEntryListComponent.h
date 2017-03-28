#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../includes/ProjectEntryComponent.h"
#include "../includes/LocalProjectEntryComponent.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Controller/includes/ProjectsController.h"

class ProjectEntryListComponent : public Component
{
public:
	ProjectEntryListComponent();
	~ProjectEntryListComponent();
	void resized() override;
	void addListEntry(ProjectEntryComponent *pec);
	void addListEntry(LocalProjectEntryComponent *pec);

private:
	std::vector<Component *> listEntries = std::vector<Component *>();
	void addListEntryComponent(Component *pec);

};
