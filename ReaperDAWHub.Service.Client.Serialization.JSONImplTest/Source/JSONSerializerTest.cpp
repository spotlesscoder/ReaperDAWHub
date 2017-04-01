#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rapidjson\rapidjson.h"
#include "../../ReaperDAWHub.Service.Client.Serialization.JSONImpl/includes/JSONDeserializer.h"
#include "../../ReaperDAWHub.Service.Client.Serialization.JSONImpl/includes/JSONSerializer.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Model/includes/User.h"

using namespace std;

string simpleProject = "{\"id\":1,\"ownerId\":1,\"timeStampLastModified\":1489255882000,\"timeStampCreated\":1489255882000,\"name\":\"Test\"}";

TEST_CASE("Serialize project to JSON") {
	Project project;
	project.id = 1;
	project.name = "Test";
	project.ownerId = 1;
	project.timeStampLastModified = 1489255882000;
	project.timeStampCreated = 1489255882000;

	REQUIRE(simpleProject == JSONSerializer<Project>::serialize(project));
	
}