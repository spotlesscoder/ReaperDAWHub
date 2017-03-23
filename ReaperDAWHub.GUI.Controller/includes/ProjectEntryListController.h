#pragma once
#include "../../ReaperDAWHub.GUI/includes/ProjectEntryListComponent.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include <vector>
#include "ProjectsStrategy.h"

class ProjectEntryListController
{
public:
	ProjectEntryListController(ProjectEntryListComponent *owner);
	void initProjects();
	void initProjectsFetched(std::vector<Project> projects);
	void writeToLog(std::string logMessage);
private:
	ProjectEntryListComponent *component;
	ProjectsStrategy *strategy;
};

