#include "../includes/ProjectsController.h"
#include "../../ReaperDAWHub.Service.Client.RESTImpl/includes/RESTClient.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp> 
#include <iostream>
#include <chrono>
#include <thread>
#include "../../ReaperDAWHub.Service.Client.Impl/includes/ServiceClient.h"

ProjectsController::ProjectsController() {
	serviceClient = new ServiceClient();
}

std::vector<Project> ProjectsController::getProjects() {
	std::vector<Project> result;
	if(serviceClient != nullptr) {
		try
		{
			std::cout << "controller requested projs\n";
			result = serviceClient->getAvailableProjects();
		}
		catch (const std::exception&)
		{

		}
	}
	
	return result;
}

std::vector<Project> ProjectsController::getProjectsChangedSince(long timestampSince) {
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
