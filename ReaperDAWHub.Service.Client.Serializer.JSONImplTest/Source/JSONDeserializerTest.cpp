#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rapidjson\rapidjson.h"

TEST_CASE("Factorials are computed", "[factorial]") {
	REQUIRE(1 == 1);
	REQUIRE(2 == 2);
	REQUIRE(6 == 6);
	REQUIRE(3628800 == 3628800);
}