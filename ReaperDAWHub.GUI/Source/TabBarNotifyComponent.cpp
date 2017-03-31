#include "../includes/TabBarNotifyComponent.h"
#include <string>

TabBarNotifyComponent::TabBarNotifyComponent()
{
	lblNumNotifications = new Label;
	addChildComponent(lblNumNotifications);
	Font f = lblNumNotifications.get()->getFont();
	f.setBold(true);
	lblNumNotifications.get()->setColour(Label::textColourId, Colours::white);
	lblNumNotifications.get()->setFont(f);
}

void TabBarNotifyComponent::init(TabBarButton *parentComponent) {
	addMouseListener(parentComponent, true);
}

void TabBarNotifyComponent::paint(Graphics& g)
{
	if (notificationCounter > 0) {
		g.setColour(notificationBubbleColour);
		g.fillEllipse(0, 7, 15, 15);
	}
}

void TabBarNotifyComponent::notify() {
	notificationCounter++;
	if (notificationCounter > 0) {
		if (notificationCounter < 10) {
			lblNumNotifications.get()->setText(std::to_string(notificationCounter), dontSendNotification);
		}
		else {
			lblNumNotifications.get()->setText(std::to_string(notificationCounter) + " +", dontSendNotification);
		}
		lblNumNotifications.get()->setVisible(true);
		setVisible(true);
	}
	if (notificationCounter > 0) {
		setSize(18, 20);
		lblNumNotifications.get()->setBounds(-2, 4, 20, 20);
		lblNumNotifications.get()->setVisible(true);
	}
}

void TabBarNotifyComponent::clearNotifications() {
	notificationCounter = 0;
	setVisible(false);
	lblNumNotifications.get()->setVisible(false);
}

