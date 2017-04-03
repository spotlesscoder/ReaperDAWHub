#pragma once
#include <string>
#include <vector>
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Model/includes/User.h"

template <class IEntity> class JSONSerializer
{
public:
	static Project deserializeProject(std::string projectString);
	static Projects deserializeProjects(std::string projectsString);
	static vector_strings_t deserializeStringArray(std::string arrayJSONString);
	static std::string serialize(Project entity);
	static std::string serialize(User entity);
};