#pragma once
#include "../../ReaperDAWHub.Service.Client.API/includes/IServiceClientAPI.h"
#include "../../ReaperDAWHub.Service.Client.RESTImpl/includes/RESTClient.h"

class ServiceClient : public IServiceClientAPI
{
public:
	void uploadProject(Project project) override;
	std::vector<Project> getAvailableProjects() override;
	std::vector<Project> getProjectsChangedSince(long timestampSince)override;

private:
	RestClient restClient;
};
