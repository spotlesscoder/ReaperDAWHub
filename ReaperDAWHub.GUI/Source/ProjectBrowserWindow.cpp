#include "../includes/ProjectBrowserWindow.h"

ProjectBrowserWindow::ProjectBrowserWindow(String name)
	: DocumentWindow(name, Colours::lightgrey,
		DocumentWindow::allButtons)
{
	setContentNonOwned(&m_projbrowser, true);
	m_projbrowser.initProjects();
	setTopLeftPosition(10, 60);
	setSize(500, 600);
	setResizable(true, false);
	setOpaque(true);
	setUsingNativeTitleBar(true);
	centreWithSize(getWidth(), getHeight());
	setVisible(true);

}


int ProjectBrowserWindow::getDesktopWindowStyleFlags() const {
	if (isResizable() == true)
		return ComponentPeer::windowHasCloseButton | ComponentPeer::windowHasTitleBar | ComponentPeer::windowIsResizable | ComponentPeer::windowHasMinimiseButton;
	return ComponentPeer::windowHasCloseButton | ComponentPeer::windowHasTitleBar | ComponentPeer::windowHasMinimiseButton;
}
void  ProjectBrowserWindow::userTriedToCloseWindow()
{
	setVisible(false);
}
