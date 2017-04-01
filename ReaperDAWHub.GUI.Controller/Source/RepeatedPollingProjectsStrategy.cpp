#define BOOST_THREAD_PROVIDES_FUTURE
#include "../includes/RepeatedPollingProjectsStrategy.h"

template<typename R>
bool isReady(std::future<R> const& f)
{
	Logger::writeToLog("check future");
	return f.wait_for(std::chrono::seconds(-1)) == std::future_status::ready;
}


void RepeatedPollingProjectsStrategy::requestProjects()
{
	Logger::writeToLog("requesting projects");
	projectsFuture = std::async(std::launch::async, &ProjectsController::getProjects, &pc);
	Logger::writeToLog("requested projects");
}

void RepeatedPollingProjectsStrategy::backgroundCheckFuture()
{
	timer = new boost::asio::deadline_timer(io_service, boost::posix_time::seconds(interval_secs));
	timer->async_wait(boost::bind(&RepeatedPollingProjectsStrategy::fetchData, this, boost::asio::placeholders::error, timer));
	ioSvcFuture = std::async(std::launch::async, static_cast<size_t(boost::asio::io_service::*)()>(&boost::asio::io_service::run), &io_service);
}

RepeatedPollingProjectsStrategy::RepeatedPollingProjectsStrategy(ProjectEntryListController* owningController, int intervalSeconds): timer(nullptr)
{
	this->owningController = owningController;
	this->interval_secs = intervalSeconds;
}

RepeatedPollingProjectsStrategy::~RepeatedPollingProjectsStrategy()
{
}

void RepeatedPollingProjectsStrategy::initData() {
	requestProjects();
	backgroundCheckFuture();
}

void RepeatedPollingProjectsStrategy::cancelPendingActions()
{
}

void RepeatedPollingProjectsStrategy::fetchData(const boost::system::error_code& /*e*/,
	boost::asio::deadline_timer* tmr) {
	if (isReady(projectsFuture)) {
		projects = projectsFuture.get();
		for (auto project : projects)
		{
			//TODO use observer pattern
			owningController->processProject(project);
		}
		Logger::writeToLog("got projs");
		owningController->initedData();
	}
	else {
		tmr->expires_at(tmr->expires_at() + boost::posix_time::seconds(interval_secs));
		tmr->async_wait(boost::bind(&RepeatedPollingProjectsStrategy::fetchData, this, boost::asio::placeholders::error, tmr));
	}
}
