#pragma once

#include <string>
#include <chrono>

class Project {
public:
	long getId();
	void setId(long id);
	std::string getName();
	void setName(std::string name);
	long getOwnerId();
	void setOwnerId(long ownerId);
	std::chrono::system_clock::time_point getLastModified();
	void setLastModified(std::chrono::system_clock::time_point lastModified);

private:
	long id;
	std::string name;
	long ownerId;
	std::chrono::system_clock::time_point lastModified;
};