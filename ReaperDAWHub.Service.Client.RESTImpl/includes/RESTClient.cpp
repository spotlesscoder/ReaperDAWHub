#include "../includes/RESTClient.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Service.Client.Serialization.JSONImpl/includes/JSONSerializer.h"
#include <cpprest/http_client.h>
#include <cpprest/rawptrstream.h>
#include <cpprest/filestream.h>
#include <ppltasks.h>

std::vector<Project> RestClient::getAvailableProjects() {
	std::vector<Project> result;
	Projects p1 = JSONSerializer<Projects>::deserializeProjects(getProjects());
	result.push_back(p1.projects[0]);
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

std::string RestClient::getProjects()
{
	web::http::client::http_client client(U("http://localhost:8080/projects"));

	web::http::http_response response = client.request(web::http::methods::GET).get();
	{
		if (response.status_code() != web::http::status_codes::OK)
		{
			// TODO Handle error cases...
			return "";
		}

		// Perform actions here reading from the response stream...
		Concurrency::streams::istream bodyStream = response.body();
		Concurrency::streams::container_buffer<std::string> inStringBuffer;
		bodyStream.read_to_end(inStringBuffer).get();
		{
			const std::string &text = inStringBuffer.collection();
			const std::string json_data{
				R"JSON({
		  "id" : 1,
		  "ownerId" : 1,
		  "timeStampLastModified" : 1474884330,
		  "timeStampCreated" : 1489255882000,
		  "name" : "Test"
		})JSON" };
			return text;
		};		
	};	
}


void RestClient::sendData(std::string body)
{
	std::string a = this->getProjects();
}

RestClient::RestClient() {

}

