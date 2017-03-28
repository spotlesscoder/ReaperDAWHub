#pragma once
#include "../../ReaperDAWHub.GUI/includes/ProjectEntryListComponent.h"
#include <future>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class ProjectEntryListController {
public:
	ProjectEntryListController(ProjectEntryListComponent *comp);
	
private:
	void backgroundCheckFuture();
	void fetchData(const boost::system::error_code& /*e*/,
		boost::asio::deadline_timer* t);
	void initData();
	void requestProjects();

	ProjectEntryListComponent *m_comp;
	std::vector<Project> projects;
	ProjectsController pc;
	std::future<std::vector<Project>> projectsFuture;
	std::future<size_t> ioSvcFuture;
	int interval_secs = 1;
	boost::asio::io_service io_service;
	boost::asio::deadline_timer* timer;
};