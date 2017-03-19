#pragma once

#include <map>
#include <functional>
#include "../../JuceLibraryCode/JuceHeader.h"

class ButtonListenerHandler : public Button::Listener
{
public:
	typedef std::function< void(void) > TButtonClickedHandler;

	void setHandler(Button* button, TButtonClickedHandler handler);
	void buttonClicked(Button* buttonThatWasClicked);

private:
	typedef std::map<Button*, TButtonClickedHandler> TButtonClickedMap;
	TButtonClickedMap m_map;
};

