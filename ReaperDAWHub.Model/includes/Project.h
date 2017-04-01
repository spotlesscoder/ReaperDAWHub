#pragma once

#include "Entity.h"
#include <string>

struct Project : Entity {
	std::string name;
	long ownerId;
	std::string version;
	long timeStampLastModified;
	long timeStampCreated;
};