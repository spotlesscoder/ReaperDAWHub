#pragma once

#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Service.Client.API/includes/IServiceClientAPI.h"

#include <vector>
class ProjectsController {
public:
	ProjectsController();
	std::vector<Project> getProjects();
	std::vector<Project> getProjectsChangedSince(long timestampSince);

private:
	IServiceClientAPI* serviceClient;
};