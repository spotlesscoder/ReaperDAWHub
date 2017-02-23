#pragma once
#include "ProjectEntryComponent.h"
#include "../JuceLibraryCode/JuceHeader.h";

/*
UI component to display projects stored locally. 
Displays the path to the project
If the project is not uploaded or the project was modified locally, a button to upload the changes is shown
*/
class LocalProjectEntryComponent : public ProjectEntryComponent
{
public:
	LocalProjectEntryComponent();
	LocalProjectEntryComponent(std::string name, std::string version);
	~LocalProjectEntryComponent();
	void resized() override;
private:
	Label lbl_name;
	Label lbl_version;
	Label lbl_date;
	Label lbl_path;
	TextButton m_btn_upload;
};