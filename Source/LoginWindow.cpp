#include "JuceHeader.h"
#include "Main.h"
#include "LoginWindow.h"

int lbl_width = 100;
int cntrl_height = 19;
int cntrl_spacing_y = 10;

LoginWindowComponent::LoginWindowComponent() : m_btn("OK")
	{
		addAndMakeVisible(&m_password);
		addAndMakeVisible(&m_user_name);
		addAndMakeVisible(&m_btn);
		addAndMakeVisible(&m_lbl_user_name);
		addAndMakeVisible(&m_lbl_password);

		m_password.setPasswordCharacter('*');
		m_password.setColour(0x1000205, Colours::black);
		m_user_name.setColour(0x1000205, Colours::black);
		m_lbl_user_name.setColour(0x1000281, Colours::black);
		m_lbl_password.setColour(0x1000281, Colours::black);

		m_lbl_user_name.setText("User name:", dontSendNotification);
		m_lbl_password.setText("Password:", dontSendNotification);

		setSize(500, 600);
	}
void LoginWindowComponent::resized()
	{
		
		m_lbl_user_name.setBounds(0, 0, lbl_width, cntrl_height);
		m_user_name.setBounds(lbl_width, 0, getWidth()-lbl_width, cntrl_height);

		m_lbl_password.setBounds(0, 30, lbl_width, cntrl_height);
		m_password.setBounds(0, 30, getWidth(), cntrl_height);

		m_btn.setBounds(0, 60, 50, cntrl_height);
		

	}




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
