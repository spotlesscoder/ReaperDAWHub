#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <string>

class TabBarNotifyComponent : public Component
{
	public:
		TabBarNotifyComponent();
		void paint(Graphics &g) override;
		void notify();
		void clearNotifications();

	private:
		uint8_t notificationCounter = 0;
		Label lblNumNotifications;
		Colour notificationBubbleColour = Colours::red;
};