#pragma once
#include "../../ReaperDAWHub.GUI.Controller/includes/ProjectBrowserWindowController.h"
#include "../../ReaperDAWHub.GUI/includes/ProjectBrowserWindow.h"

class ProjectBrowserWindowController
{
public:
	ProjectBrowserWindowController(ProjectBrowserWindow *wnd);
	void initProjectsAsync();

private:
	ProjectBrowserWindow* wnd;
};
