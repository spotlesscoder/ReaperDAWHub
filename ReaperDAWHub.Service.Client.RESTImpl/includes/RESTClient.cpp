#include "../includes/RESTClient.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include <cpprest/http_client.h>
#include <cpprest/rawptrstream.h>
#include <cpprest/filestream.h>
#include <ppltasks.h>

void RestClient::uploadProject(Project project) {
	
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
			return text;
		};		
	};	
}

RestClient::RestClient() {

}

