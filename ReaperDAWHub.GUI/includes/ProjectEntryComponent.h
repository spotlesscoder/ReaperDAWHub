#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"

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
	ScopedPointer<Label> lbl_name;
	ScopedPointer<Label> lbl_version;
	ScopedPointer<Label> lbl_date;
	Colour bgColour = Colours::lightgrey;
	
	void mouseExit(const MouseEvent &);
	void addAndMakeVisibleWithListener(Component *child);
};