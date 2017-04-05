#pragma once
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include <cpprest/asyncrt_utils.h>

class RestClient {
public:
	RestClient();
	void uploadProject(Project project);	
	std::string getProjects();
	std::string RestClient::getAvailableSharedProjects(std::int64_t userId);
private:
	std::string getHttpRequestResponseString(utility::string_t requestUrl);
};
