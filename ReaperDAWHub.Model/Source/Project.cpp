#include "../includes/Project.h"

void Project::setId(long id) {
	this->id = id;
}

long Project::getId() {
	return id;
}

std::string Project::getName()
{
	return name;
}

void Project::setName(std::string name)
{
	this->name = name;
}

long Project::getOwnerId()
{
	return ownerId;
}

void Project::setOwnerId(long ownerId)
{
	this->ownerId = ownerId;
}

std::chrono::system_clock::time_point Project::getLastModified()
{
	return lastModified;
}

void Project::setLastModified(std::chrono::system_clock::time_point lastModified)
{
	this->lastModified = lastModified;
}
