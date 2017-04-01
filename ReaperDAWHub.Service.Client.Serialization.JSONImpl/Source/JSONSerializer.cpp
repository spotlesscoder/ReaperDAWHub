#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "../../Thirdparty/json_dto/0.1/pub.hpp"
#include "../includes/JSONSerializer.h"
#include "../../ReaperDAWHub.Model/includes/Project.h"
#include "../../ReaperDAWHub.Model/includes/User.h"

using namespace rapidjson;
using namespace std;


namespace json_dto
{
	template < typename JSON_IO >
	void
		json_io(JSON_IO & io, Entity & entity)
	{
		io
			&json_dto::mandatory("id", entity.id);
	}


	template < typename JSON_IO >
	void
		json_io(JSON_IO & io, Project & proj)
	{
		json_dto::json_io(io, static_cast< Entity & >(proj));
		io
			&json_dto::mandatory("ownerId", proj.ownerId)
			&json_dto::mandatory("timeStampLastModified", proj.timeStampLastModified)
			&json_dto::mandatory("timeStampCreated", proj.timeStampCreated)
			&json_dto::mandatory("name", proj.name);
	}

	
} /* namespace json_dto */

string JSONSerializer<Project>::serialize(Project project) {
	return json_dto::to_json(project);

}

string JSONSerializer<User>::serialize(User user) {
	return "";
}