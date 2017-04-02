// ReaperDAWHub.Playground.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../ReaperDAWHub.Controller/includes/ProjectsController.h"
#include <iostream>
#include <future>
#include "../ReaperDAWHub.Service.Client.Serialization.JSONImpl/includes/JSONSerializer.h"
#include "../ReaperDAWHub.Service.Client.RESTImpl/includes/RESTClient.h"

template<typename R>
bool isReady(std::future<R> const& f)
{
	return f.wait_for(std::chrono::seconds(-1)) == std::future_status::ready;
}

int main()
{
	ProjectsController pc;

	std::cout << "requesting projs\n";
	std::future<std::vector<Project>> f = std::async(std::launch::async, &ProjectsController::getProjects, &pc);
	std::cout << "requested projs\n";
	for (int i = 0; i < 10; i++) {
		std::this_thread::sleep_for(std::chrono::microseconds(100));
		std::cout << i << "\n";
	}

	std::vector<Project> projs;
	if (isReady(f)) {
		projs = f.get();
		std::cout << "got projs\n";
	}
	RestClient *rc = new RestClient();
	rc->uploadProject(projs[0]);
	std::cout << JSONSerializer<Project>::serialize(projs[0]);

    return 0;
}

