#pragma once
#include <string>
#include <vector>
#include "../../ReaperDAWHub.Model/includes/IEntity.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Model/includes/User.h"

template <class IEntity> class JSONDeserializer
{
public:
	static Project deserializeProject(std::string JSONstr);
	static User deserializeUser(std::string JSONstr);
};