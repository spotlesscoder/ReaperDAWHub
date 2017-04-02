#include "../includes/RESTClient.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Service.Client.Serialization.JSONImpl/includes/JSONSerializer.h"
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

std::vector<Project> RestClient::getAvailableProjects() {
	std::vector<Project> result;
	Project p1;
	p1.id = 1234;
	p1.name = "1234";
	p1.timeStampLastModified = 1233;
	p1.ownerId = 33;
	result.push_back(p1);
	return result;
}

std::vector<Project> RestClient::getProjectsChangedSince(long timestampSince) {
	std::vector<Project> result;
	Project p1;
	p1.id = 2;
	p1.name = "2";
	p1.timeStampLastModified = 123311;
	p1.ownerId = 33;
	result.push_back(p1);
	std::vector<Project> old = getAvailableProjects();
	result.insert(result.end(), old.begin(), old.end());
	return result;
}

void RestClient::uploadProject(Project project) {
	sendData(JSONSerializer<Project>::serialize(project));
}

void RestClient::sendData(std::string body)
{
	
}

RestClient::RestClient() {

}

