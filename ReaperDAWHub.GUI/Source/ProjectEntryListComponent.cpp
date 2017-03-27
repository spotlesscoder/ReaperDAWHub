#define BOOST_THREAD_PROVIDES_FUTURE
#include "../includes/ProjectEntryListComponent.h"
#include "../includes/LocalProjectEntryComponent.h"
#include "ProjectBrowserComponent.h"
#include <string>

template<typename R>
bool isReady(std::future<R> const& f)
{
	Logger::writeToLog("check future");
	return f.wait_for(std::chrono::seconds(-1)) == std::future_status::ready;
}

ProjectEntryListComponent::ProjectEntryListComponent() {
	setSize(500, 600);
	addListEntry((new ProjectEntryComponent()));
	initData();
}

ProjectEntryListComponent::~ProjectEntryListComponent() {

}

void ProjectEntryListComponent::addListEntry(ProjectEntryComponent *pec) {
	addListEntryComponent(pec);
}

void ProjectEntryListComponent::addListEntry(LocalProjectEntryComponent *pec) {
	addListEntryComponent(pec);
}

void ProjectEntryListComponent::addListEntryComponent(Component *pec) {
	listEntries.push_back(pec);
	pec->setBounds(0, 60 * (listEntries.size() - 1), getLocalBounds().getWidth(), 60);
	setSize(200, 150);
	addAndMakeVisible(pec);
	repaint();
}

void ProjectEntryListComponent::resized() {

}

void ProjectEntryListComponent::requestProjects()
{
	Logger::writeToLog("requesting projects");
	projectsFuture = std::async(std::launch::async, &ProjectsController::getProjects, &pc);
	Logger::writeToLog("requested projects");
}

void ProjectEntryListComponent::backgroundCheckFuture()
{
	timer = new boost::asio::deadline_timer(io_service, boost::posix_time::seconds(interval_secs));
	timer->async_wait(boost::bind(&ProjectEntryListComponent::fetchData, this, boost::asio::placeholders::error, timer));
	ioSvcFuture = std::async(std::launch::async, static_cast<size_t(boost::asio::io_service::*)()>(&boost::asio::io_service::run), &io_service);
}

void ProjectEntryListComponent::initData() {
	requestProjects();
	backgroundCheckFuture();
}

void ProjectEntryListComponent::fetchData(const boost::system::error_code& /*e*/,
	boost::asio::deadline_timer* tmr) {
	if (isReady(projectsFuture)) {
		projects = projectsFuture.get();
		for (auto project : projects)
		{
			ProjectEntryComponent *pec = new ProjectEntryComponent(std::to_string(project.getId()), "222");
			addListEntry(pec);
		}
		Logger::writeToLog("got projs");
	}
	else {
		tmr->expires_at(tmr->expires_at() + boost::posix_time::seconds(interval_secs));
		tmr->async_wait(boost::bind(&ProjectEntryListComponent::fetchData, this, boost::asio::placeholders::error, tmr));
	}
}