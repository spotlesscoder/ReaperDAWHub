#include "../../JuceLibraryCode/JuceHeader.h"
#include "../../includes/Main.h"
#include "../includes/LoginWindow.h"

class LoginWindow : public ResizableWindow
{
public:
	static void initGUIifNeeded()
	{
		if (g_juce_inited == false)
		{
			initialiseJuce_GUI();
			g_juce_inited = true;
		}
	}
	LoginWindow(int w, int h, bool resizable, Colour bgcolor)
		: ResizableWindow("Reaper DAW Hub Login", bgcolor, false)
	{
		setContentNonOwned(&m_login, true);
		setTopLeftPosition(10, 60);
		setSize(w, h);
		setResizable(resizable, false);
		setOpaque(true);
	}
	~LoginWindow() {}
	int getDesktopWindowStyleFlags() const override
	{
		if (isResizable() == true)
			return ComponentPeer::windowHasCloseButton | ComponentPeer::windowHasTitleBar | ComponentPeer::windowIsResizable | ComponentPeer::windowHasMinimiseButton;
		return ComponentPeer::windowHasCloseButton | ComponentPeer::windowHasTitleBar | ComponentPeer::windowHasMinimiseButton;
	}
	void userTriedToCloseWindow() override
	{
		setVisible(false);
	}
private:
	LoginWindowComponent m_login;
};

LoginWindow* g_login_wnd = nullptr;

void toggleLoginWindow(action_entry&)
{
	toggleLoginWindow();
}
void toggleLoginWindow()
{
	LoginWindow::initGUIifNeeded();
	if (g_login_wnd == nullptr)
	{
		g_login_wnd = new LoginWindow(700, 400, true, Colours::white);
		// This call order is important, the window should not be set visible
		// before adding it into the Reaper window hierarchy
		// Currently this only works for Windows, OS-X needs some really annoying special handling
		// not implemented yet
#ifdef WIN32
		//if plugin info != NULL, this should indicate that window is loaded from Reaper.
		//Otherwise, (e.g. from the GUIDemo project) GetMainHwnd() will point to 0x0000000 which leads to a crash
		if(g_plugin_info != NULL) { 
			
			g_login_wnd->addToDesktop(g_login_wnd->getDesktopWindowStyleFlags(), GetMainHwnd());
		}
#else
		w->addToDesktop(w->getDesktopWindowStyleFlags(), 0);
		makeWindowFloatingPanel(w);
#endif
	}
	g_login_wnd->setVisible(!g_login_wnd->isVisible());
}
