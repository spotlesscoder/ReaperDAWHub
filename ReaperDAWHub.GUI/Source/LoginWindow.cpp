#include "../../JuceLibraryCode/JuceHeader.h"
#include "../../includes/Main.h"
#include "../includes/LoginWindow.h"

	LoginWindow::LoginWindow(String name)
		: ResizableWindow(name, Colours::black, true)
	{
		setContentNonOwned(&m_login, true);
		
		setTopLeftPosition(10, 60);
		setSize(500, 600);
		setResizable(true, false);
		setOpaque(true);

	}
	int LoginWindow::getDesktopWindowStyleFlags() const
	{
		if (isResizable() == true)
			return ComponentPeer::windowHasCloseButton | ComponentPeer::windowHasTitleBar | ComponentPeer::windowIsResizable | ComponentPeer::windowHasMinimiseButton;
		return ComponentPeer::windowHasCloseButton | ComponentPeer::windowHasTitleBar | ComponentPeer::windowHasMinimiseButton;
	}
	void LoginWindow::userTriedToCloseWindow() 
	{
		setVisible(false);
	}

