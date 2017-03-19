#include "../includes/ProjectsController.h"
#include "../../ReaperDAWHub.Service.Client.RESTImpl/includes/RESTClient.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp> 

ProjectsController::ProjectsController() {
	serviceClient = new RestClient;
}

std::vector<Project> ProjectsController::getProjects() {
	std::vector<Project> result;
	if(serviceClient != nullptr) {
		try
		{
			std::cout << "controller requesting projs";
			boost::this_thread::sleep(boost::posix_time::seconds(5));
			std::cout << "controller requested projs";
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
