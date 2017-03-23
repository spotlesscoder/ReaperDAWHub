#include "../includes/RepeatedPollingProjectsStrategy.h"
#include "../../ReaperDAWHub.GUI/includes/ProjectEntryListComponent.h"
#define BOOST_THREAD_PROVIDES_FUTURE


template<typename R>
bool isReady(std::future<R> const& f)
{
	Logger::writeToLog("check future");
	return f.wait_for(std::chrono::seconds(-1)) == std::future_status::ready;
}

void RepeatedPollingProjectsStrategy::fetchProjects(ProjectLocationsEnum location, ProjectsRepositoryOwnerEnum owner, ProjectEntryListController *owningController)
{
	this->owningController = owningController;
	requestProjects();
	backgroundCheckFuture();
}

void RepeatedPollingProjectsStrategy::requestProjects()
{
	owningController->writeToLog("requesting projects");
	projectsFuture = std::async(std::launch::async, &ProjectsController::getProjects, &pc);
	owningController->writeToLog("requested projects");
}

void RepeatedPollingProjectsStrategy::backgroundCheckFuture()
{
	timer = new boost::asio::deadline_timer(io_service, boost::posix_time::seconds(interval_secs));
	timer->async_wait(boost::bind(&RepeatedPollingProjectsStrategy::timerTick, this, boost::asio::placeholders::error, timer));
	ioSvcFuture = std::async(std::launch::async, static_cast<size_t(boost::asio::io_service::*)()>(&boost::asio::io_service::run), &io_service);
}

void RepeatedPollingProjectsStrategy::timerTick(const boost::system::error_code& /*e*/,
	boost::asio::deadline_timer* tmr) {
	if (isReady(projectsFuture)) {
		projects = projectsFuture.get();
		owningController->writeToLog("requested projects");
		owningController->initProjectsFetched(projects);
	}
	else {
		tmr->expires_at(tmr->expires_at() + boost::posix_time::seconds(interval_secs));
		tmr->async_wait(boost::bind(&RepeatedPollingProjectsStrategy::timerTick, this, boost::asio::placeholders::error, tmr));
	}
}