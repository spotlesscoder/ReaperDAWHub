#pragma once
#include <string>
#include <vector>
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Model/includes/User.h"

template <class IEntity> class JSONSerializer
{
public:
	static Project deserialize(std::string projectString);
	static std::string serialize(Project entity);
	static std::string serialize(User entity);
};