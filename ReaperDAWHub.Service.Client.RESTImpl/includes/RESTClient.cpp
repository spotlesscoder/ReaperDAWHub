#include "../includes/RESTClient.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"

std::vector<Project> RestClient::getAvailableProjects() {
	std::vector<Project> result;
	Project p1;
	p1.setId(1234);
	p1.setName("1234");
	p1.setLastModified(std::chrono::system_clock::now());
	p1.setOwnerId(33);
	result.push_back(p1);
	return result;
}

std::vector<Project> RestClient::getProjectsChangedSince(std::chrono::time_point<std::chrono::system_clock> since) {
	std::vector<Project> result;
	Project p1;
	p1.setId(2);
	p1.setName("2");
	p1.setLastModified(std::chrono::system_clock::now());
	p1.setOwnerId(33);
	result.push_back(p1);
	std::vector<Project> old = getAvailableProjects();
	result.insert(result.end(), old.begin(), old.end());
	return result;
}

void RestClient::uploadProject(Project project) {
	return;
}

RestClient::RestClient() {

}