#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../includes/ProjectEntryComponent.h"
#include "../includes/LocalProjectEntryComponent.h"
#include <future>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Controller/includes/ProjectsController.h"

class ProjectEntryListComponent : public Component
{
public:
	ProjectEntryListComponent();
	~ProjectEntryListComponent();
	void resized() override;
<<<<<<< HEAD
	void addListEntry(ProjectEntryComponent &pec);
	void addListEntry(LocalProjectEntryComponent &pec);
=======
	void addListEntry(ProjectEntryComponent *pec);
	void addListEntry(LocalProjectEntryComponent *pec);
>>>>>>> parent of 0d78d6d... apply mvc pattern

private:
	void initData();
	void requestProjects();
	void backgroundCheckFuture();
	void fetchData(const boost::system::error_code& /*e*/,
		boost::asio::deadline_timer* t);
	std::vector<Component *> listEntries = std::vector<Component *>();
<<<<<<< HEAD
	void addListEntryComponent(Component &pec);
};
=======
	void addListEntryComponent(Component *pec);

	std::vector<Project> projects;
	ProjectsController pc;
	std::future<std::vector<Project>> projectsFuture;
	std::future<size_t> ioSvcFuture;
	int interval_secs = 1;
	boost::asio::io_service io_service;
	boost::asio::deadline_timer* timer;
};
>>>>>>> parent of 0d78d6d... apply mvc pattern
