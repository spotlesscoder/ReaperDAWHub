#pragma once

#include <string>
#include <chrono>
#include <ctime>
#include "Entity.h"

class Project : Entity {
public:
	std::string getName();
	void setName(std::string name);
	long getOwnerId();
	void setOwnerId(long ownerId);
	std::chrono::system_clock::time_point getLastModified();
	void setLastModified(std::chrono::time_point<std::chrono::system_clock> lastModified);
	void setId(long id) override;
	long getId() override;

private:
	long id;
	std::string name;
	long ownerId;
	std::chrono::time_point<std::chrono::system_clock> lastModified;
	std::chrono::time_point<std::chrono::system_clock> created;
};