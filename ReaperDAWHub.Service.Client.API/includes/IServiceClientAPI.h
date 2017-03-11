#pragma once
class IServiceClientAPI {

public:
	// pure virtual function providing interface framework.
	virtual void uploadProject();
	virtual void getAvailableProjects();
};