#include "../includes/ProjectBrowserComponent.h"

ProjectBrowserComponent::ProjectBrowserComponent() : m_btn("OK") {
	addAndMakeVisible(m_tabs);
	m_tabs.initProjects();
	setSize(500, 600);
}

ProjectBrowserComponent::~ProjectBrowserComponent() {
}

void ProjectBrowserComponent::resized() {
	m_btn.setBounds(0, 60, 50, cntrl_height);
	m_tabs.setBounds(0, 0, getLocalBounds().getWidth(), getLocalBounds().getHeight());
}

void ProjectBrowserComponent::initProjects()
{
	m_tabs.initProjects();
}
