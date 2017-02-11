#define REAPERAPI_IMPLEMENT

#include <memory>
#include <vector>
#include <functional>
#include "../JuceLibraryCode/JuceHeader.h"
#include "../includes/action_entry.h"
#include "../includes/LoginWindow.h"
#include "../includes/ReaperDAWHub.h"

reaper_plugin_info_t* g_plugin_info;
bool g_juce_inited = false;
Colour reabgColour;

HINSTANCE g_hInst;
HWND g_parent;

std::vector<std::shared_ptr<action_entry>> g_actions;

std::shared_ptr<action_entry> add_action(std::string name, std::string id, toggle_state togst, std::function<void(action_entry&)> f)
{
	auto entry = std::make_shared<action_entry>(name, id, togst, f);
	g_actions.push_back(entry);
	return entry;
}

bool hookCommandProc(int command, int flag) {
	for (auto& e : g_actions) {
		if (e->m_command_id != 0 && e->m_command_id == command) {
			e->m_func(*e);
			return true;
		}
	}
	return false; // failed to run relevant action
}

class MyWebBrowserComponent : public WebBrowserComponent
{
public:
	MyWebBrowserComponent(TextEditor* editor) : m_url_edit(editor) {}
	bool pageAboutToLoad(const String& url) override
	{
		m_url_edit->setText(url, dontSendNotification);
		return true;
	}
private:
	TextEditor* m_url_edit = nullptr;
};

class BrowserComponent : public Component
{
public:
	BrowserComponent() : m_browser(&m_address_line)
	{
		m_address_line.setText("http://www.reaper.fm/", dontSendNotification);
		addAndMakeVisible(&m_address_line);
		addAndMakeVisible(&m_browser);
		m_browser.goToURL(m_address_line.getText());
		setSize(100, 100);
	}
	void resized() override
	{
		m_address_line.setBounds(0, 0, getWidth(), 19);
		m_browser.setBounds(0, 20, getWidth(), getHeight() - 20);
	}
private:
	TextEditor m_address_line;
	MyWebBrowserComponent m_browser;
};

class Window : public ResizableWindow
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
	Window(String title, int w, int h, bool resizable, Colour bgcolor)
		: ResizableWindow(title, bgcolor, false)
	{
		setContentNonOwned(&m_browser, true);
		setTopLeftPosition(10, 60);
		setSize(w, h);
		setResizable(resizable, false);
		setOpaque(true);
	}
	~Window() {}
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
	BrowserComponent m_browser;
};

Window* g_browser_wnd = nullptr;

void toggleBrowserWindow(action_entry&)
{
	Window::initGUIifNeeded();
	if (g_browser_wnd == nullptr)
	{
		g_browser_wnd = new Window("The Inter Webs", 700, 400, true, Colours::black);
		// This call order is important, the window should not be set visible
		// before adding it into the Reaper window hierarchy
		// Currently this only works for Windows, OS-X needs some really annoying special handling
		// not implemented yet
#ifdef WIN32
		g_browser_wnd->addToDesktop(g_browser_wnd->getDesktopWindowStyleFlags(), GetMainHwnd());
#else
		w->addToDesktop(w->getDesktopWindowStyleFlags(), 0);
		makeWindowFloatingPanel(w);
#endif
	}
	g_browser_wnd->setVisible(!g_browser_wnd->isVisible());
}

extern "C"
{
	REAPER_PLUGIN_DLL_EXPORT int REAPER_PLUGIN_ENTRYPOINT(REAPER_PLUGIN_HINSTANCE hInstance, reaper_plugin_info_t *rec) {
		if (rec != nullptr) {
			if (rec->caller_version != REAPER_PLUGIN_VERSION || !rec->GetFunc) return 0;
			g_hInst = hInstance;
			g_plugin_info = rec;
			g_parent = rec->hwnd_main;
			if (REAPERAPI_LoadAPI(rec->GetFunc) > 0) return 0;
			
			reabgColour = Colours::grey;

			add_action("JUCE test : Show browser", "JUCETEST_SHOW_BROWSER", CannotToggle, [](action_entry& ae)
			{
				toggleBrowserWindow(ae);
			});
			add_action("JUCE test : Show Login", "JUCETEST_SHOW_Login", CannotToggle, [](action_entry& ae2)
			{
				toggleLoginWindow(ae2);
			});
			rec->Register("hookcommand", (void*)hookCommandProc);
			return 1; // our plugin registered, return success
		}
		else
		{
			if (g_juce_inited == true)
			{
				if (g_browser_wnd != nullptr)
					delete g_browser_wnd;
				shutdownJuce_GUI();
			}
			return 0;
		}
	}
};
