#include "../includes/ProjectBrowserComponent.h"
#include "../includes/ProjectEntryComponent.h"
#include <future>
#include <string>
#include <iostream>
#include <algorithm>

ProjectBrowserComponent::ProjectBrowserComponent() : m_btn("OK") {

	addAndMakeVisible(m_tabs);
    std::future<std::vector<Project>> f = std::async(&ProjectsController::getProjects,&pc);
	setSize(500, 600);
}

ProjectBrowserComponent::~ProjectBrowserComponent() {
}

void ProjectBrowserComponent::resized() {
	m_btn.setBounds(0, 60, 50, cntrl_height);
	m_tabs.setBounds(0, 0, getLocalBounds().getWidth(), getLocalBounds().getHeight());
}
