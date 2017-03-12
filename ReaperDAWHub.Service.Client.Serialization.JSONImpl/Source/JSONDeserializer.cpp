#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "../includes/JSONDeserializer.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Model/includes/User.h"

using namespace rapidjson;
using namespace std;


Project JSONDeserializer<Project>::deserializeProject(string JSONstr) {
	Project result;
	return result;

}

User JSONDeserializer<User>::deserializeUser(string JSONstr) {
	User result;
	return result;
}