#include "../includes/ProjectEntryListController.h"
#include "../../ReaperDAWHub.GUI/includes/ProjectEntryComponent.h"
#include "OneTimeGetProjectsStrategy.h"
#include "RepeatedPollingProjectsStrategy.h"

void ProjectEntryListController::processProject( Project *project)
{
	ProjectEntryComponent *pec = new ProjectEntryComponent(std::to_string(project->getId()), project->getVersion());
	m_comp->addListEntry(pec);
	m_comp->repaint();
}

void ProjectEntryListController::initedData()
{
	Logger::writeToLog("inited data");
	strategy->cancelPendingActions();
	Logger::writeToLog("cancelled pending actions");
	strategy = new RepeatedPollingProjectsStrategy(this, 1);
	Logger::writeToLog("new strategy: polling");
	strategy->initData();
}

ProjectEntryListController::ProjectEntryListController(ProjectEntryListComponent *comp) {
	m_comp = comp;
	strategy = new OneTimeGetProjectsStrategy(this);
	strategy->initData();
}
