// check if the build environment is Windows, and then include the Windows API header,
// else include SWELL which provides functions with the same names but are implemented
// for another operating system (namely, OS-X)

#ifdef _WIN32
#include <windows.h>
#else
#include "../../WDL/swell/swell.h"
#endif

#include "stdio.h"

// super nasty looking macro here but allows importing functions from Reaper with simple looking code
#define IMPAPI(x) if (!((*((void **)&(x)) = (void *)rec->GetFunc(#x)))) errcnt++;

#define REAPERAPI_DECL
#define REAPERAPI_IMPLEMENT
#include "reaper_plugin_functions.h"

int g_registered_command01 = 0;
int g_registered_command02 = 0;
int g_registered_command03 = 0;
int g_registered_command04 = 0;

// handle to the dll instance? could be useful for making win32 API calls
REAPER_PLUGIN_HINSTANCE g_hInst;

// global variable that holds the handle to the Reaper main window, useful for various win32 API calls
HWND g_parent;

// Action default keyboard shortcut and action text set here
gaccel_register_t acreg01 = { { 0,0,0 },"Simple extension test action" };
gaccel_register_t acreg02 = { { 0,0,0 },"Simple extension togglable test action" };

// *** HERE THE ACTIONS DO THEIR WORK ***

void doAction1()
{
	WinMain(g_hInst, g_hInst, "10", 1);
}

// global variable to hold the toggle state of the togglable action
// each togglable action of course needs its own variable for this...

int g_togglestate; // will be inited in main() function to 0 or value from ini-file

void doAction2()
{
	// this action does nothing else but toggles the global variable that keeps track of the toggle state
	// so it's useless as such but you can see the action state changing in the toolbar buttons and the actions list
	if (g_togglestate == 0)
		g_togglestate = 1; // toggle state on
	else g_togglestate = 0;
	// store new state of toggle action to ini file immediately
	char buf[8];
	// the REAPER api for ini-files only deals with strings, so form a string from the action
	// toggle state number.
	sprintf(buf, "%d", g_togglestate);
	SetExtState("simple_extension", "toggleaction_state", buf, true);
}

// Reaper calls back to this when it wants to execute an action registered by the extension plugin
bool hookCommandProc(int command, int flag)
{
	// it might happen Reaper calls with 0 for the command and if the action
	// registration has failed the plugin's command id would also be 0
	// therefore, check the plugins command id is not 0 and then if it matches with
	// what Reaper called with
	if (g_registered_command01 != 0 && command == g_registered_command01)
	{
		doAction1();
		return true;
	}
	if (g_registered_command02 != 0 && command == g_registered_command02)
	{
		doAction2();
		return true;
	}
	// failed to run relevant action
	return false;
}

// Reaper calls back to this when it wants to know an actions's toggle state
int toggleActionCallback(int command_id)
{
	if (command_id && command_id == g_registered_command02)
		return g_togglestate;
	// -1 if action not provided by this extension or is not togglable
	return -1;
}

extern "C"
{
	// this is the only function that needs to be exported by a Reaper extension plugin dll
	// everything then works from function pointers and others things initialized within this
	// function
	REAPER_PLUGIN_DLL_EXPORT int REAPER_PLUGIN_ENTRYPOINT(REAPER_PLUGIN_HINSTANCE hInstance, reaper_plugin_info_t *rec)
	{
		g_hInst = hInstance;
		if (rec)
		{
			if (rec->caller_version != REAPER_PLUGIN_VERSION || !rec->GetFunc)
				return 0;
			// initialize API function pointers from Reaper
			// REMEMBER to initialize the needed functions here, otherwise calling them results in a crash!
			int errcnt = 0; // this error counter variable will be "magically" incremented by the IMPAPI macro on errors
			IMPAPI(Main_OnCommand);
			IMPAPI(InsertMedia);
			IMPAPI(GetProjectPath);
			IMPAPI(GetResourcePath);
			IMPAPI(SetExtState);
			IMPAPI(GetExtState);
			IMPAPI(HasExtState);
			
			// if even one api function fails to initialize, it's not wise to continue, so abort plugin loading
			if (errcnt>0)
				return 0;
			acreg01.accel.cmd = g_registered_command01 = rec->Register("command_id", (void*)"EXAMPLE_ACTION_01");
			acreg02.accel.cmd = g_registered_command02 = rec->Register("command_id", (void*)"EXAMPLE_ACTION_02");
			if (!g_registered_command01) return 0; // failed getting a command id, fail!
			if (!g_registered_command02) return 0; // failed getting a command id, fail!

			rec->Register("gaccel", &acreg01);
			rec->Register("gaccel", &acreg02);
			rec->Register("hookcommand", (void*)hookCommandProc);
			rec->Register("toggleaction", toggleActionCallback);

			g_parent = rec->hwnd_main;
			// restore extension global settings
			// saving extension data into reaper project files is another thing and 
			// at the moment not done in this example plugin
			const char* numberString = GetExtState("simple_extension", "toggleaction_state");
			g_togglestate = 0;
			if (numberString)
				g_togglestate = atoi(numberString);
			// our plugin registered, return success
			
			return 1;
		}
		else
		{
			return 0;
		}
	}

};

#ifndef _WIN32 // MAC resources
#include "../../WDL/swell/swell-dlggen.h"
#include "res.rc_mac_dlg"
#undef BEGIN
#undef END
#include "../../WDL/swell/swell-menugen.h"
#include "res.rc_mac_menu"
#endif
