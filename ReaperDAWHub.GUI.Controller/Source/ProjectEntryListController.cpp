#include "../includes/ProjectEntryListController.h"
#include "../../ReaperDAWHub.GUI/includes/ProjectEntryComponent.h"
#include "OneTimeGetProjectsStrategy.h"
#include "RepeatedPollingProjectsStrategy.h"

void ProjectEntryListController::processProject(Project project) const
{
	ProjectEntryComponent *pec = new ProjectEntryComponent(std::to_string(project.id), "222");
	m_comp.get()->addListEntry(pec);
	m_comp.get()->repaint();
}

void ProjectEntryListController::initedData()
{
	strategy->cancelPendingActions();
	strategy = new RepeatedPollingProjectsStrategy(this, 10);
	strategy->initData();
}

ProjectEntryListController::ProjectEntryListController(ScopedPointer<ProjectEntryListComponent> comp) {
	m_comp = comp;
	strategy = new OneTimeGetProjectsStrategy(this);
	strategy->initData();
}
