#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../../ReaperDAWHub.Service.Client.RESTImpl/includes/RESTClient.h"

std::string simpleProject = "{\"id\":1,\"name\":\"Test\",\"ownerId\":1,\"lastModified\":1489255882000,\"created\":1489255882000}";

TEST_CASE("Deserialize project JSON") {
	RestClient rc;
	std::string result = rc.getProjects();
	
}