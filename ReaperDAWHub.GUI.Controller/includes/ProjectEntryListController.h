#pragma once
#include "../../ReaperDAWHub.GUI/includes/ProjectEntryListComponent.h"
#include "ProjectsStrategy.h"

class ProjectEntryListController {
public:
	ProjectEntryListController(ProjectEntryListComponent *comp);
	void processProject(Project *project);
	void initedData();
private:
	ProjectsStrategy *strategy;
	ProjectEntryListComponent *m_comp;

};
