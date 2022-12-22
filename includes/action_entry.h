#pragma once
#include "reaper_plugin_functions.h"
#include <functional>
#include <vector>

extern reaper_plugin_info_t *g_plugin_info;

enum toggle_state { CannotToggle, ToggleOff, ToggleOn };

class action_entry { // class for registering actions
public:
  action_entry(std::string description, std::string idstring,
               toggle_state togst, std::function<void(action_entry &)> func);
  action_entry(const action_entry &) = delete;            // prevent copying
  action_entry &operator=(const action_entry &) = delete; // prevent copying
  action_entry(action_entry &&) = delete;                 // prevent moving
  action_entry &operator=(action_entry &&) = delete;      // prevent moving

  int m_command_id = 0;
  gaccel_register_t m_accel_reg;
  std::function<void(action_entry &)> m_func;
  std::string m_desc;
  std::string m_id_string;
  toggle_state m_togglestate = CannotToggle;

  void *m_data = nullptr;
  template <typename T> T *getDataAs() { return static_cast<T *>(m_data); }
};