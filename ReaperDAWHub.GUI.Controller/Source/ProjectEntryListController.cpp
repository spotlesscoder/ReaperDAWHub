#include "../includes/ProjectEntryListController.h"
#include "../../ReaperDAWHub.GUI/includes/ProjectEntryComponent.h"
#include "OneTimeGetProjectsStrategy.h"
#include "RepeatedPollingProjectsStrategy.h"

void ProjectEntryListController::processProject( Project *project)
{
	ProjectEntryComponent *pec = new ProjectEntryComponent(std::to_string(project->getId()), "222");
	m_comp->addListEntry(pec);
	m_comp->repaint();
}

void ProjectEntryListController::initedData()
{
	strategy->cancelPendingActions();
	strategy = new RepeatedPollingProjectsStrategy(this);
}

ProjectEntryListController::ProjectEntryListController(ProjectEntryListComponent *comp) {
	m_comp = comp;
	strategy = new OneTimeGetProjectsStrategy(this);
	strategy->initData();
}
