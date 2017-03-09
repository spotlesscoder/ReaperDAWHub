#include "../includes/ProjectEntryComponent.h"
#include "../includes/GUIConstants.h"

ProjectEntryComponent::ProjectEntryComponent() {
	lbl_name.setText("Name", dontSendNotification);
	lbl_version.setText("Version", dontSendNotification);
	lbl_date.setText("Mon, 2017-02-20 18:56", dontSendNotification);
	
	addAndMakeVisibleWithListener(lbl_name);
	addAndMakeVisibleWithListener(lbl_version);
	addAndMakeVisibleWithListener(lbl_date);

	setSize(200, 50);
}

ProjectEntryComponent::~ProjectEntryComponent() {
}

ProjectEntryComponent::ProjectEntryComponent(std::string name, std::string version) {
}

void ProjectEntryComponent::resized() {
	lbl_name.setBounds(0, 0, getWidth(), cntrl_height);
	lbl_version.setBounds(0, cntrl_height + cntrl_height, getWidth(), cntrl_height);
	lbl_date.setBounds(getWidth() - 125, cntrl_height + cntrl_height, getWidth(), cntrl_height);

	Font f_name = lbl_name.getFont();
	f_name.setHeight(font_height+10);
	lbl_name.setFont(f_name);

	Font f_date = lbl_date.getFont();
	f_date.setHeight(font_height - 4);
	lbl_date.setFont(f_date);

}

void ProjectEntryComponent::paint(Graphics& g) {
	g.fillAll(bgColour);
}

void ProjectEntryComponent::mouseEnter(const MouseEvent&)
{
	bgColour = bgColour.brighter();
	repaint();
}

void ProjectEntryComponent::mouseExit(const MouseEvent&) {
	bgColour = Colours::lightgrey;
	repaint();
}

void ProjectEntryComponent::addAndMakeVisibleWithListener(Component &child) {
	addAndMakeVisible(child);
	child.addMouseListener(this, true);
}
