#include "../JuceLibraryCode/JuceHeader.h"
#include "../includes/action_entry.h"
#include "../includes/LoginWindow.h"
#include "../includes/ReaperDAWHub.h"

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
	BrowserComponent() : m_btn("OK")
	{
		addAndMakeVisible(&m_password);
		addAndMakeVisible(&m_user_name);
		addAndMakeVisible(&m_btn);
		
		setSize(100, 100);
	}
	void resized() override
	{
		m_user_name.setBounds(0, 0, getWidth(), 19);
		m_password.setBounds(0, 50, getWidth(), 19);
		m_btn.setBounds(0, 100, getWidth(), getHeight() - 20);
	}
private:
	TextEditor m_user_name;
	juce::TextEditor m_password;
	juce::TextButton m_btn;
};

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
		: ResizableWindow("Reaoer DAW Hub Login", bgcolor, false)
	{
		setContentNonOwned(&m_browser, true);
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
	BrowserComponent m_browser;
};

LoginWindow* g_login_wnd = nullptr;

void toggleLoginWindow(action_entry&)
{
	LoginWindow::initGUIifNeeded();
	if (g_login_wnd == nullptr)
	{
		g_login_wnd = new LoginWindow(700, 400, true, reabgColour);
		// This call order is important, the window should not be set visible
		// before adding it into the Reaper window hierarchy
		// Currently this only works for Windows, OS-X needs some really annoying special handling
		// not implemented yet
#ifdef WIN32
		g_login_wnd->addToDesktop(g_login_wnd->getDesktopWindowStyleFlags(), GetMainHwnd());
#else
		w->addToDesktop(w->getDesktopWindowStyleFlags(), 0);
		makeWindowFloatingPanel(w);
#endif
	}
	g_login_wnd->setVisible(!g_login_wnd->isVisible());
}
