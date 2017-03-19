#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rapidjson\rapidjson.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Model/includes/User.h"
#include "../../ReaperDAWHub.Service.Client.RESTImpl/includes/RESTClient.h"

std::string simpleProject = "{\"id\":1,\"name\":\"Test\",\"ownerId\":1,\"lastModified\":1489255882000,\"created\":1489255882000}";

TEST_CASE("Deserialize project JSON") {
	RestClient* rc = new RestClient();
	std::vector<Project> result = rc->getAvailableProjects();
	Project p1 = result.back();
	REQUIRE(1234 == p1.getId());
	REQUIRE(33 == p1.getOwnerId());
	REQUIRE("1234" == p1.getName());
}