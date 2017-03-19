// ReaperDAWHub.Playground.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../ReaperDAWHub.Controller/includes/ProjectsController.h"
#include <iostream>
#include <future>

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
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << i << "\n";
	}
	std::vector<Project> projs;
	if (isReady(f)) {
		projs = f.get();
		std::cout << "got projs\n";
	}
	
    return 0;
}

