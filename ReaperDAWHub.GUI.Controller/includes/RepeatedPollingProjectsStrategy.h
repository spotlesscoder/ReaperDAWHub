#pragma once
#include "ProjectsStrategy.h"
#include <future>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "../ReaperDAWHub.Model/includes/Project.h"
#include "../ReaperDAWHub.Controller/includes/ProjectsController.h"
#include "../ReaperDAWHub.GUI.Controller/includes/ProjectEntryListController.h"

class RepeatedPollingProjectsStrategy : public ProjectsStrategy
{
public:
	void fetchProjects(ProjectLocationsEnum location, ProjectsRepositoryOwnerEnum owner, ProjectEntryListController *owningController) override;
private:
	void timerTick(const boost::system::error_code& /*e*/,
						 boost::asio::deadline_timer* tmr);
	void requestProjects();
	void backgroundCheckFuture();

	std::vector<Project> projects;
	ProjectsController pc;
	std::future<std::vector<Project>> projectsFuture;
	std::future<size_t> ioSvcFuture;
	int interval_secs = 1;
	boost::asio::io_service io_service;
	boost::asio::deadline_timer* timer;
	ProjectLocationsEnum location;
	ProjectsRepositoryOwnerEnum owner;
};
