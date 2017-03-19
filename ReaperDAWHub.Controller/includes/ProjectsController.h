#pragma once

#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Service.Client.API/includes/IServiceClientAPI.h"

#include <vector>
class ProjectsController {
public:
	ProjectsController();
	std::vector<Project> getProjects();
	std::vector<Project> getProjectsChangedSince(std::chrono::time_point<std::chrono::system_clock> since);

private:
	IServiceClientAPI* serviceClient;
};