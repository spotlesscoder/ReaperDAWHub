#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "../includes/JSONSerializer.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Model/includes/User.h"

using namespace rapidjson;
using namespace std;


string JSONSerializer<Project>::serialize(Project project) {
	return "";

}

string JSONSerializer<User>::serialize(User user) {
	return "";
}