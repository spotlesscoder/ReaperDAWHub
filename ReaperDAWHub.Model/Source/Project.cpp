#include "../includes/Project.h"

void Project::setId(long id) {
	this->id = id;
}

long Project::getId() {
	return id;
}

std::string Project::getVersion()
{
	return version;
}

void Project::setVersion(std::string version)
{
	this->version = version;
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

void Project::setLastModified(std::chrono::time_point<std::chrono::system_clock> lastModified)
{
	this->lastModified = lastModified;
}
