#define BOOST_THREAD_PROVIDES_FUTURE
#include "../includes/OneTimeGetProjectsStrategy.h"

template<typename R>
bool isReady(std::future<R> const& f)
{
	Logger::writeToLog("check future");
	return f.wait_for(std::chrono::seconds(-1)) == std::future_status::ready;
}

OneTimeGetProjectsStrategy::OneTimeGetProjectsStrategy(ProjectEntryListController *owningController)
{
	this->owningController = owningController;
}

OneTimeGetProjectsStrategy::~OneTimeGetProjectsStrategy()
{
}

void OneTimeGetProjectsStrategy::requestProjects()
{
	Logger::writeToLog("requesting projects");
	projectsFuture = std::async(std::launch::async, &ProjectsController::getProjects, &pc);
	Logger::writeToLog("requested projects");
}

void OneTimeGetProjectsStrategy::backgroundCheckFuture()
{
	timer = new boost::asio::deadline_timer(io_service, boost::posix_time::seconds(interval_secs));
	timer->async_wait(boost::bind(&OneTimeGetProjectsStrategy::fetchData, this, boost::asio::placeholders::error, timer));
	ioSvcFuture = std::async(std::launch::async, static_cast<size_t(boost::asio::io_service::*)()>(&boost::asio::io_service::run), &io_service);
}

void OneTimeGetProjectsStrategy::initData() {
	requestProjects();
	backgroundCheckFuture();
}

void OneTimeGetProjectsStrategy::cancelPendingActions()
{
	timer->cancel();
}

void OneTimeGetProjectsStrategy::fetchData(const boost::system::error_code& /*e*/,
	boost::asio::deadline_timer* tmr) {
	if (isReady(projectsFuture)) {
		projects = projectsFuture.get();
		for (auto project : projects)
		{
			//TODO use observer pattern
			owningController->processProject(&project);
		}
		Logger::writeToLog("got projs");
		owningController->initedData();
	}
	else {
		tmr->expires_at(tmr->expires_at() + boost::posix_time::seconds(interval_secs));
		tmr->async_wait(boost::bind(&OneTimeGetProjectsStrategy::fetchData, this, boost::asio::placeholders::error, tmr));
	}
}
