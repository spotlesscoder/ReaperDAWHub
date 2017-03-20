#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "GUIConstants.h"
#include "ProjectBrowserTabComponent.h"
#include "../includes/ButtonListenerHandler.h"
#include "../../ReaperDAWHub.Controller/includes/ProjectsController.h"
#include <future>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class ProjectBrowserComponent : public Component, public ButtonListenerHandler
{
public:
	ProjectBrowserComponent();
	~ProjectBrowserComponent();
	void resized() override;
	void initData();
private:
	void fetchData(const boost::system::error_code& /*e*/,
		boost::asio::deadline_timer* t);
	GroupComponent g_group;
	TextButton m_btn;
	Label lbl_name;
	Label lbl_version;
	ProjectBrowserTabComponent m_tabs;
	std::vector<Project> projects;
	ProjectsController pc;
	std::future<std::vector<Project>> projectsFuture;
	std::future<size_t> ioSvcFuture;
	int interval_secs = 1;
	boost::asio::io_service io_service;
	boost::asio::deadline_timer* timer;
};