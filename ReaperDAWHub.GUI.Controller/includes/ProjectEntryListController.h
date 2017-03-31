#pragma once
#include "../../ReaperDAWHub.GUI/includes/ProjectEntryListComponent.h"
#include "ProjectsStrategy.h"

class ProjectEntryListController {
public:
	ProjectEntryListController(ScopedPointer<ProjectEntryListComponent> comp);
	void processProject(Project *project);
	void initedData();
private:
	ProjectsStrategy *strategy;
	ScopedPointer<ProjectEntryListComponent> m_comp;

};
