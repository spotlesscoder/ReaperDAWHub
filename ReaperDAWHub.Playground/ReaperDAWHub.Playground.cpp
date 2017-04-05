// ReaperDAWHub.Playground.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../ReaperDAWHub.Controller/includes/ProjectsController.h"
#include <iostream>
#include <future>
#include "../ReaperDAWHub.Service.Client.Serialization.JSONImpl/includes/JSONSerializer.h"
#include "../ReaperDAWHub.Service.Client.RESTImpl/includes/RESTClient.h"
#include "../ReaperDAWHub.Service.Client.Impl/includes/ServiceClient.h"

template<typename R>
bool isReady(std::future<R> const& f)
{
	return f.wait_for(std::chrono::seconds(-1)) == std::future_status::ready;
}

int main()
{
	ServiceClient sc;

	std::cout << "requesting projs\n";
	std::future<std::vector<Project>> f = std::async(std::launch::async, &ServiceClient::getAvailableProjects, &sc);
	std::cout << "requested projs\n";
	std::this_thread::sleep_for(std::chrono::microseconds(1000));

	std::vector<Project> projs;
		projs = f.get();
		std::cout << "got projs\n";
	
	RestClient *rc = new RestClient();
	rc->uploadProject(projs[0]);
	for(Project p : projs)
	{
		std::cout << JSONSerializer<Project>::serialize(p);
	}
	std::cout << JSONSerializer<Project>::serialize(projs[1]);


    return 0;
}

