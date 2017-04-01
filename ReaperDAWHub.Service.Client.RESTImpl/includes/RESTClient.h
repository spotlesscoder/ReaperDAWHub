#pragma once
#include <vector>
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Service.Client.API/includes/IServiceClientAPI.h"

class RestClient : public IServiceClientAPI {
public:
	RestClient();
	std::vector<Project> getAvailableProjects();
	std::vector<Project> getProjectsChangedSince(long timestampSince);
	void uploadProject(Project project);
};