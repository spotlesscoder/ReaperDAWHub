#include "../includes/RESTClient.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include <cpprest/http_client.h>
#include <cpprest/rawptrstream.h>
#include <ppltasks.h>

void RestClient::uploadProject(Project project) {
	
}

std::string RestClient::getHttpRequestResponseString(utility::string_t requestUrl)
{
	web::http::client::http_client client(requestUrl);

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
			return text;
		};		
	};
}

std::string RestClient::getProjects()
{
	return getHttpRequestResponseString(utility::conversions::to_string_t("http://localhost:8080/projects"));
}

std::string RestClient::getAvailableSharedProjects(std::int64_t userId)
{
	return getHttpRequestResponseString(utility::conversions::to_string_t("http://localhost:8080/users/" + std::to_string(userId) + "/availableSharedProjects"));
}


RestClient::RestClient() {

}

