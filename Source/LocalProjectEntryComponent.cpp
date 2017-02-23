#include "../includes/ProjectEntryComponent.h"
#include "../includes/GUIConstants.h"
#include "../includes/LocalProjectEntryComponent.h"

LocalProjectEntryComponent::LocalProjectEntryComponent() : m_btn_upload("Upload") {
	
	setSize(200, 100);
}

LocalProjectEntryComponent::~LocalProjectEntryComponent() {
}

LocalProjectEntryComponent::LocalProjectEntryComponent(std::string name, std::string version) {

}

void LocalProjectEntryComponent::resized() {
	m_btn_upload.setBounds(50, 0, 50, 20);
	lbl_path.setBounds(lbl_version.getBounds());
}