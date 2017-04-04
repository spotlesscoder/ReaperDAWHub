#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../../ReaperDAWHub.Service.Client.Serialization.JSONImpl/includes/JSONSerializer.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"

using namespace std;

string simpleProject = "{\"id\":1,\"ownerId\":1,\"timeStampLastModified\":1489255882000,\"timeStampCreated\":1489255882000,\"name\":\"Test\"}";
string simpleSingleProjectInArray = "[{\"id\":1, \"name\" : \"Test\", \"ownerId\" : 12137, \"timeStampLastModified\" : 1493244000000, \"timeStampCreated\" : 1492812000000}]";
string simpleMultipleProjectsInArray = "[{\"id\":1, \"name\" : \"Test\", \"ownerId\" : 12137, \"timeStampLastModified\" : 1493244000000, \"timeStampCreated\" : 1492812000000},{\"id\":2, \"name\" : \"Test\", \"ownerId\" : 12137, \"timeStampLastModified\" : 1493244000000, \"timeStampCreated\" : 1492812000000}]";
string json_data = "{\"id\" : 1,\"ownerId\" : 1,  \"timeStampLastModified\" : 1474884330,	 \"timeStampCreated\" : 1489255882000,	 \"name\" : \"Test\"}";
string stringarray = "{\"strings\":[\"test1\", \"test2\"]}";

TEST_CASE("Serialize project to JSON") {
	Project project;
	project.id = 1;
	project.name = "Test";
	project.ownerId = 1;
	project.timeStampLastModified = 1489255882000;
	project.timeStampCreated = 1489255882000;

	REQUIRE(simpleProject == JSONSerializer<Project>::serialize(project));
	
}


TEST_CASE("Deserialize project from JSON") {
	Project project = JSONSerializer<Project>::deserializeProject(json_data);

	REQUIRE(project.id == 1);

}


TEST_CASE("Deserialize stringarray from JSON") {
	vector_strings_t data = JSONSerializer<vector<string>>::deserializeStringArray(stringarray);
	std::cout << data.strings[0] + "\n";
	std::cout << data.strings[1] + "\n";

	
	REQUIRE(data.strings[0] == "test1");

}


TEST_CASE("Deserialize single project from JSON array") {
	Project project;
	project.id = 1;
	project.name = "Test";
	project.ownerId = 1;
	project.timeStampLastModified = 1489255882000;
	project.timeStampCreated = 1489255882000;

	Project project2;

	Projects projects = JSONSerializer<Projects>::deserializeProjects(simpleSingleProjectInArray);

	REQUIRE(projects.projects.size() == 1);
}

TEST_CASE("Deserialize multiple projects from JSON array") {
	Project project;
	project.id = 1;
	project.name = "Test";
	project.ownerId = 1;
	project.timeStampLastModified = 1489255882000;
	project.timeStampCreated = 1489255882000;

	Project project2;

	Projects projects = JSONSerializer<Projects>::deserializeProjects(simpleMultipleProjectsInArray);

	REQUIRE(projects.projects.size() == 2);
}