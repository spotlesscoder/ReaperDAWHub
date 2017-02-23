#pragma once
#include "../JuceLibraryCode/JuceHeader.h";

class ProjectEntryComponent : public Component
{
public:
	ProjectEntryComponent();
	ProjectEntryComponent(std::string name, std::string version);
	~ProjectEntryComponent();
	void resized() override;
	void paint(Graphics & g) override;
	void mouseEnter(const MouseEvent &) override;

	

private:
	Label lbl_name;
	Label lbl_version;
	Label lbl_date;
	Colour bgColour = Colours::lightgrey;
	
	void mouseExit(const MouseEvent &);
	void addAndMakeVisibleWithListener(Component &child);

};