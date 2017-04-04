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

	template < typename JSON_IO >
		void
		json_io(JSON_IO & io, Projects & projs)
	{
		io
			& json_dto::mandatory("projects", projs.projects);
	}

	template < typename JSON_IO >
	void
		json_io(JSON_IO & io, vector_strings_t & vector)
	{
		io
			& json_dto::mandatory("strings", vector.strings);
	}
} /* namespace json_dto */

string JSONSerializer<Project>::serialize(Project project) {
	return json_dto::to_json(project);
}

Project JSONSerializer<Project>::deserializeProject(std::string projectString) {
	return json_dto::from_json<Project>(projectString);
}

Projects JSONSerializer<Projects>::deserializeProjects(std::string projectsString) {
	projectsString = "{\"projects\":" + projectsString + "}";
	return json_dto::from_json<Projects>(projectsString);
}

vector_strings_t JSONSerializer<vector<string>>::deserializeStringArray(std::string arrayJSONString)
{
	return json_dto::from_json<vector_strings_t>(arrayJSONString);
}

string JSONSerializer<User>::serialize(User user) {
	return "";
}
