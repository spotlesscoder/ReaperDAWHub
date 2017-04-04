#pragma once
#include "../../ReaperDAWHub.Model/includes/Project.h"

class RestClient {
public:
	RestClient();
	void uploadProject(Project project);
	std::string getProjects();
};