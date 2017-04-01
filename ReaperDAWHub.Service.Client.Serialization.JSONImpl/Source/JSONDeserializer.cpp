#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "../includes/JSONDeserializer.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Model/includes/User.h"
#include "../../Thirdparty/json_dto/0.1/pub.hpp"

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

namespace json_dto
{

	template < typename JSON_IO >
	void
		json_io(JSON_IO & io, Project & msg)
	{
		io
			& json_dto::mandatory("from", msg.getId())
			& json_dto::mandatory("when", msg.m_when)
			& json_dto::mandatory("text", msg.m_text);
	}

} /* namespace json_dto */