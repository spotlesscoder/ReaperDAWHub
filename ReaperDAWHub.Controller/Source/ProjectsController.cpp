#include "../includes/ProjectsController.h"
#include "../../ReaperDAWHub.Service.Client.RESTImpl/includes/RESTClient.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp> 
#include <iostream>
#include <chrono>
#include <thread>

ProjectsController::ProjectsController() {
	serviceClient = new RestClient;
}

std::vector<Project> ProjectsController::getProjects() {
	std::vector<Project> result;
	if(serviceClient != nullptr) {
		try
		{
			std::this_thread::sleep_for(std::chrono::seconds(3));
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
