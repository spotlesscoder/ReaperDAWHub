#include "../includes/ProjectsController.h"
#include "../../ReaperDAWHub.Service.Client.RESTImpl/includes/RESTClient.h"

ProjectsController::ProjectsController() {
	serviceClient = new RestClient;
}

std::vector<Project> ProjectsController::getProjects() {
	std::vector<Project> result;
	if(serviceClient != nullptr) {
		try
		{
			result = serviceClient->getAvailableProjects();
		}
		catch (const std::exception&)
		{

		}
	}
	
	return result;
}

std::vector<Project> ProjectsController::getProjectsChangedSince(std::chrono::time_point<std::chrono::system_clock> since) {
	std::vector<Project> result;
	if (serviceClient != nullptr) {
		try
		{
			result = serviceClient->getAvailableProjects();
		}
		catch (const std::exception&)
		{

		}
	}

	return result;
}
