#include "../includes/LoginWindowComponent.h"


LoginWindowComponent::LoginWindowComponent() : m_btn("OK") {
	addAndMakeVisible(&m_password);
	addAndMakeVisible(&m_user_name);
	addAndMakeVisible(&m_btn);
	addAndMakeVisible(&m_lbl_user_name);
	addAndMakeVisible(&m_lbl_password);

	m_password.setPasswordCharacter('*');
	m_password.setColour(0x1000205, Colours::black);
	m_user_name.setColour(0x1000205, Colours::black);
	m_lbl_user_name.setColour(0x1000281, Colours::black);
	m_lbl_password.setColour(0x1000281, Colours::black);

	m_lbl_user_name.setText("User name:", dontSendNotification);
	m_lbl_password.setText("Password:", dontSendNotification);
	
	setSize(500, 600);
}

LoginWindowComponent::~LoginWindowComponent() {
}

void LoginWindowComponent::resized() {

	m_lbl_user_name.setBounds(0, 0, lbl_width, cntrl_height);
	m_user_name.setBounds(lbl_width, 0, getWidth() - lbl_width, cntrl_height);

	m_lbl_password.setBounds(0, 30, lbl_width, cntrl_height);
	m_password.setBounds(lbl_width, 30, getWidth(), cntrl_height);

	m_btn.setBounds(0, 60, 50, cntrl_height);
}
 