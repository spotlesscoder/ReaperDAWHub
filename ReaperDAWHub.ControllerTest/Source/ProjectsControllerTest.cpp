#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rapidjson\rapidjson.h"
#include "../../ReaperDAWHub.Controller/includes/ProjectsController.h"

TEST_CASE("Test ProjectsController") {
	ProjectsController pc;
	std::vector<Project> result = pc.getProjects();
	REQUIRE(1 == result.size());

}