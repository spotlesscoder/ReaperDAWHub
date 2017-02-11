#pragma once
#include "../includes/reaper_plugin_functions.h"
#include <vector>
#include <functional>

enum toggle_state { CannotToggle, ToggleOff, ToggleOn };

/*
to fix LNK2005 when this header is included in multiple files, use "extern" keyword in front of declaration
the extern keyword causes the variable not to be created at this point. It will be created by the following line in one of the CPP files:
reaper_plugin_info_t* g_plugin_info;
*/
extern reaper_plugin_info_t* g_plugin_info;

class action_entry
{ //class for registering actions
public:
	action_entry(std::string description, std::string idstring, toggle_state togst, std::function<void(action_entry&)> func);
	action_entry(const action_entry&) = delete; // prevent copying
	action_entry& operator=(const action_entry&) = delete; // prevent copying
	action_entry(action_entry&&) = delete; // prevent moving
	action_entry& operator=(action_entry&&) = delete; // prevent moving

	int m_command_id = 0;
	gaccel_register_t m_accel_reg;
	std::function<void(action_entry&)> m_func;
	std::string m_desc;
	std::string m_id_string;
	toggle_state m_togglestate = CannotToggle;

	void* m_data = nullptr;
	template<typename T>
	T* getDataAs() { return static_cast<T*>(m_data); }
};