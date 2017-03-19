#include "../includes/ProjectBrowserComponent.h"
#include "../includes/ProjectEntryComponent.h"
#define BOOST_THREAD_PROVIDES_FUTURE
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <future>
#include <string>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <map>
#include <functional>

template<typename R>
bool isReady(std::future<R> const& f)
{
	return f.wait_for(std::chrono::seconds(-1)) == std::future_status::ready;
}

ProjectBrowserComponent::ProjectBrowserComponent() : m_btn("OK") {

	addAndMakeVisible(m_tabs);
//	setHandler(&m_btn);
	setSize(500, 600);
}

ProjectBrowserComponent::~ProjectBrowserComponent() {
}

void ProjectBrowserComponent::resized() {
	m_btn.setBounds(0, 60, 50, cntrl_height);
	m_tabs.setBounds(0, 0, getLocalBounds().getWidth(), getLocalBounds().getHeight());
}

void ProjectBrowserComponent::initData() {
	std::cout << "requesting projs";
	std::future<std::vector<Project>> f = std::async(std::launch::async, &ProjectsController::getProjects, &pc);
	std::cout << "requested projs";
	std::vector<Project> projs;
	if (isReady(f)) {
		projs = f.get();
		std::cout << "got projs";
	}
}