#pragma once
#include <vector>
#include "../../ReaperDAWHub.Model/includes/Project.h"

class IServiceClientAPI {

public:
	virtual void uploadProject(Project project) = 0;
	virtual std::vector<Project> getAvailableProjects() = 0;
    virtual std::vector<Project> getProjectsChangedSince(long timestampSince) = 0;
	
	virtual std::vector<Project> getAvailableSharedProjects() = 0;
};