#pragma once

class ProjectEntryListController;

enum ProjectLocationsEnum
{
	Local,
	Remote
};

enum ProjectsRepositoryOwnerEnum
{
	Self,
	Friend
};
class ProjectsStrategy
{
public:
	virtual void fetchProjects(ProjectLocationsEnum location, ProjectsRepositoryOwnerEnum owner, ProjectEntryListController *owningController) = 0;
protected:
	ProjectEntryListController *owningController;
};