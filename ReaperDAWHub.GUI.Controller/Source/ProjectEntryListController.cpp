#include "../includes/ProjectEntryListController.h"
#include <string>
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "RepeatedPollingProjectsStrategy.h"

void ProjectEntryListController::initProjectsFetched(std::vector<Project> projects)
{
	for (auto project : projects)
	{
		ProjectEntryComponent *pec = new ProjectEntryComponent(std::to_string(project.getId()), "222");
		component->addListEntry(pec);
		component->writeToLog("got projs");
	}
}

void ProjectEntryListController::initProjects()
{
	strategy->fetchProjects(ProjectLocationsEnum::Remote, ProjectsRepositoryOwnerEnum::Self, this);
}


void ProjectEntryListController::writeToLog(std::string logMessage)
{
	component->writeToLog(logMessage);
}

ProjectEntryListController::ProjectEntryListController(ProjectEntryListComponent *owner) {
	this->component = owner;
	strategy = new RepeatedPollingProjectsStrategy();
}