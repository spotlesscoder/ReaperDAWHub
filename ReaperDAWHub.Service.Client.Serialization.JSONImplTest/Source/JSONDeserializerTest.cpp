#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rapidjson\rapidjson.h"
#include "../../ReaperDAWHub.Service.Client.Serialization.JSONImpl/includes/JSONDeserializer.h"
#include "../../ReaperDAWHub.Service.Client.Serialization.JSONImpl/includes/JSONSerializer.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Model/includes/User.h"

using namespace std;

string simpleProject = "{\"id\":1,\"name\":\"Test\",\"ownerId\":1,\"lastModified\":1489255882000,\"created\":1489255882000}";

TEST_CASE("Deserialize project JSON") {
	REQUIRE(1 == 1);
	REQUIRE(2 == 2);
	REQUIRE(6 == 6);
	REQUIRE(3628800 == 3628800);
	Project project;
	User user;

	string str = JSONSerializer<Project>::serialize(project);
	string str2 = JSONSerializer<User>::serialize(user);
	REQUIRE(str == "abc"); //only shows usage examples ... fails at intendedly the moment. serialization needs to be implemented
	REQUIRE(str2 == "cde"); 

	cout << "String:  " << str;
}