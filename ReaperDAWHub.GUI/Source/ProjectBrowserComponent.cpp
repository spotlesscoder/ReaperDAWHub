#define BOOST_THREAD_PROVIDES_FUTURE
#include "../includes/ProjectBrowserComponent.h"
#include "../includes/ProjectEntryComponent.h"
#include <string>
#include <algorithm>
#include <map>

template<typename R>
bool isReady(std::future<R> const& f)
{
	Logger::writeToLog("check future");
	return f.wait_for(std::chrono::seconds(-1)) == std::future_status::ready;
}

ProjectBrowserComponent::ProjectBrowserComponent() : m_btn("OK") {
	addAndMakeVisible(m_tabs);
	setSize(500, 600);
	initData();
}

ProjectBrowserComponent::~ProjectBrowserComponent() {
}

void ProjectBrowserComponent::resized() {
	m_btn.setBounds(0, 60, 50, cntrl_height);
	m_tabs.setBounds(0, 0, getLocalBounds().getWidth(), getLocalBounds().getHeight());
}

void ProjectBrowserComponent::initData() {
	Logger::writeToLog("requesting projects");
	projectsFuture = std::async(std::launch::async, &ProjectsController::getProjects, &pc);
	Logger::writeToLog("requested projects");
	timer = new boost::asio::deadline_timer(io_service, boost::posix_time::seconds(interval_secs));
	timer->async_wait(boost::bind(&ProjectBrowserComponent::fetchData, this, boost::asio::placeholders::error, timer));
	ioSvcFuture = std::async(std::launch::async, static_cast<size_t(boost::asio::io_service::*)()>(&boost::asio::io_service::run), &io_service);
}

void ProjectBrowserComponent::fetchData(const boost::system::error_code& /*e*/,
	boost::asio::deadline_timer* tmr) {
	if (isReady(projectsFuture)) {
		projects = projectsFuture.get();
		Logger::writeToLog("got projs");
	}
	else {
		tmr->expires_at(tmr->expires_at() + boost::posix_time::seconds(interval_secs));
		// Posts the event
		tmr->async_wait(boost::bind(&ProjectBrowserComponent::fetchData, this, boost::asio::placeholders::error, tmr));
	}
}