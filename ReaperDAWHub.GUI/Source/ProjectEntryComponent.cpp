#include "../includes/ProjectEntryComponent.h"
#include "../includes/GUIConstants.h"

ProjectEntryComponent::ProjectEntryComponent() {
	lbl_name = new Label;
	lbl_version = new Label;
	lbl_date = new Label;
	lbl_name.get()->setText("Name", dontSendNotification);
	lbl_version.get()->setText("Version", dontSendNotification);
	lbl_date.get()->setText("Mon, 2017-02-20 18:56", dontSendNotification);
	
	addAndMakeVisibleWithListener(lbl_name.get());
	addAndMakeVisibleWithListener(lbl_version);
	addAndMakeVisibleWithListener(lbl_date);

	setSize(500, 50);
}

ProjectEntryComponent::~ProjectEntryComponent() {
}

ProjectEntryComponent::ProjectEntryComponent(std::string name, std::string version) {
	lbl_name = new Label;
	lbl_version = new Label;
	lbl_date = new Label;
	lbl_name.get()->setText(name, dontSendNotification);
	lbl_version.get()->setText(version, dontSendNotification);
	lbl_date.get()->setText("Mon, 2017-02-20 18:56", dontSendNotification);

	addAndMakeVisibleWithListener(lbl_name);
	addAndMakeVisibleWithListener(lbl_version);
	addAndMakeVisibleWithListener(lbl_date);

	setSize(500, 50);
}

void ProjectEntryComponent::resized() {
	lbl_name.get()->setBounds(2, 0, getWidth(), cntrl_height);
	lbl_version.get()->setBounds(2, cntrl_height + cntrl_height, getWidth(), cntrl_height);
	lbl_date.get()->setBounds(getWidth() - 125, cntrl_height + cntrl_height, getWidth(), cntrl_height);

	Font f_name = lbl_name.get()->getFont();
	f_name.setHeight(font_height+10);
	lbl_name.get()->setFont(f_name);

	Font f_date = lbl_date.get()->getFont();
	f_date.setHeight(font_height - 4);
	lbl_date.get()->setFont(f_date);

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

void ProjectEntryComponent::addAndMakeVisibleWithListener(Component *child) {
	addAndMakeVisible(child);
	child->addMouseListener(this, true);
}
