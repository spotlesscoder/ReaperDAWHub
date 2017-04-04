#include "../includes/ServiceClient.h"

#include <vector>
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Service.Client.Serialization.JSONImpl/includes/JSONSerializer.h"

void ServiceClient::uploadProject(Project project)
{
}

std::vector<Project> ServiceClient::getAvailableProjects() {
	std::vector<Project> result;
	Projects p1 = JSONSerializer<Projects>::deserializeProjects(restClient.getProjects());
	for (Project proj : p1.projects)
	{
		result.push_back(proj);
	}

	return result;
}

std::vector<Project> ServiceClient::getProjectsChangedSince(long timestampSince) {
	std::vector<Project> result;
	Project p1;
	p1.id = 2;
	p1.name = "2";
	p1.timeStampLastModified = 123311;
	p1.ownerId = 33;
	result.push_back(p1);
	std::vector<Project> old = getAvailableProjects();
	result.insert(result.end(), old.begin(), old.end());
	return result;
}