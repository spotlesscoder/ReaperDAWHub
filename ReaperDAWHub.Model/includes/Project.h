#pragma once

#include <string>
#include "Entity.h/Entity.h"

struct Project : Entity {
	std::string name;
	std::int64_t ownerId;
	std::string version;
	std::int64_t timeStampLastModified;
	std::int64_t timeStampCreated;
};
