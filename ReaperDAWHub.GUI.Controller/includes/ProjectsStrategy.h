#pragma once

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
	virtual void initData() = 0;
	virtual void cancelPendingActions() = 0;
};
