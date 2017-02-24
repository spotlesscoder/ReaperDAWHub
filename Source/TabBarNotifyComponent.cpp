#include "../includes/TabBarNotifyComponent.h"

TabBarNotifyComponent::TabBarNotifyComponent()
{
	addChildComponent(lblNumNotifications);
	Font f = lblNumNotifications.getFont();
	f.setBold(true);
	lblNumNotifications.setColour(Label::textColourId, Colours::white);
	lblNumNotifications.setFont(f);
}

void TabBarNotifyComponent::paint(Graphics& g)
{
	if (notificationCounter > 0) {
		g.setColour(notificationBubbleColour);
		g.fillEllipse(2, 7, 15, 15);
	}
}

void TabBarNotifyComponent::notify() {
	notificationCounter++;
	if (notificationCounter > 0) {
		if (notificationCounter < 10) {
			lblNumNotifications.setText(std::to_string(notificationCounter), dontSendNotification);
		}
		else {
			lblNumNotifications.setText(std::to_string(notificationCounter) + " +", dontSendNotification);
		}
		lblNumNotifications.setVisible(true);
		setVisible(true);
	}
	if (notificationCounter > 0) {
		setSize(20, 20);
		lblNumNotifications.setBounds(0, 4, 20, 20);
		lblNumNotifications.setVisible(true);
	}
}

void TabBarNotifyComponent::clearNotifications() {
	notificationCounter = 0;
	setVisible(false);
	lblNumNotifications.setVisible(false);
}

