#pragma once

#include <string>
#include <chrono>
#include "Entity.h"

class Project : Entity {
public:
	std::string getName();
	void setName(std::string name);
	long getOwnerId();
	void setOwnerId(long ownerId);
	std::chrono::system_clock::time_point getLastModified();
	void setLastModified(std::chrono::system_clock::time_point lastModified);
	void setId(long id) override;
	long getId() override;

private:
	long id;
	std::string name;
	long ownerId;
	std::chrono::system_clock::time_point lastModified;
};