#define BOOST_THREAD_PROVIDES_FUTURE
#include "../includes/ProjectEntryListController.h"

template<typename R>
bool isReady(std::future<R> const& f)
{
	Logger::writeToLog("check future");
	return f.wait_for(std::chrono::seconds(-1)) == std::future_status::ready;
}

ProjectEntryListController::ProjectEntryListController(ProjectEntryListComponent *comp) {
	m_comp = comp;
	requestProjects();
}

void ProjectEntryListController::requestProjects()
{
	Logger::writeToLog("requesting projects");
	projectsFuture = std::async(std::launch::async, &ProjectsController::getProjects, &pc);
	Logger::writeToLog("requested projects");
}

void ProjectEntryListController::backgroundCheckFuture()
{
	timer = new boost::asio::deadline_timer(io_service, boost::posix_time::seconds(interval_secs));
	timer->async_wait(boost::bind(&ProjectEntryListController::fetchData, this, boost::asio::placeholders::error, timer));
	ioSvcFuture = std::async(std::launch::async, static_cast<size_t(boost::asio::io_service::*)()>(&boost::asio::io_service::run), &io_service);
}

void ProjectEntryListController::initData() {
	requestProjects();
	backgroundCheckFuture();
}

void ProjectEntryListController::fetchData(const boost::system::error_code& /*e*/,
	boost::asio::deadline_timer* tmr) {
	if (isReady(projectsFuture)) {
		projects = projectsFuture.get();
		for (auto project : projects)
		{
			ProjectEntryComponent *pec = new ProjectEntryComponent(std::to_string(project.getId()), "222");
			m_comp->addListEntry(pec);
			m_comp->repaint();
		}
		Logger::writeToLog("got projs");
	}
	else {
		tmr->expires_at(tmr->expires_at() + boost::posix_time::seconds(interval_secs));
		tmr->async_wait(boost::bind(&ProjectEntryListController::fetchData, this, boost::asio::placeholders::error, tmr));
	}
}