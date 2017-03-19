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
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

template<typename R>
bool isReady(std::future<R> const& f)
{
	return f.valid() && f.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
}

ProjectBrowserComponent::ProjectBrowserComponent() : m_btn("OK") {

	addAndMakeVisible(m_tabs);
    std::future<std::vector<Project>> f = std::async(&ProjectsController::getProjects,&pc);
	std::vector<Project> projs;
	if (isReady(f)) {
		projs = f.get();
	}
	setSize(500, 600);
}

ProjectBrowserComponent::~ProjectBrowserComponent() {
}

void ProjectBrowserComponent::resized() {
	m_btn.setBounds(0, 60, 50, cntrl_height);
	m_tabs.setBounds(0, 0, getLocalBounds().getWidth(), getLocalBounds().getHeight());
}
