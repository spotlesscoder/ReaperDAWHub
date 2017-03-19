#include "../includes/ButtonListenerHandler.h"

void ButtonListenerHandler::setHandler(Button* button, TButtonClickedHandler handler) {
	button->addListener(this);
	m_map[button] = handler;
}

void ButtonListenerHandler::buttonClicked(Button* buttonThatWasClicked) {
	auto it = m_map.find(buttonThatWasClicked);
	if (it != m_map.end())
	{
		(it->second)();
	}
}