#pragma once
#include "ProjectsStrategy.h"
#include <future>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "../includes/ProjectEntryListController.h"

class OneTimeGetProjectsStrategy : public ProjectsStrategy
{
public:
	OneTimeGetProjectsStrategy(ProjectEntryListController* owningController);
	~OneTimeGetProjectsStrategy();
	void initData() override;
	void cancelPendingActions() override;

private:
	void backgroundCheckFuture();
	void fetchData(const boost::system::error_code& /*e*/,
		boost::asio::deadline_timer* t);
	void requestProjects();

	std::vector<Project> projects;
	ProjectsController pc;
	std::future<std::vector<Project>> projectsFuture;
	std::future<size_t> ioSvcFuture;
	int interval_secs = 1;
	boost::asio::io_service io_service;
	boost::asio::deadline_timer* timer;
	ProjectEntryListController *owningController;
};
