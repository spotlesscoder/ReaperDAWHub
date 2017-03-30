#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "GUIConstants.h"

class LoginWindowComponent : public Component
{
public:
	LoginWindowComponent();
	~LoginWindowComponent();
    void resized() override;
	void cancelPendingActions();

private:
	ScopedPointer<TextEditor> m_user_name;
	ScopedPointer<TextEditor> m_password;
	ScopedPointer<TextButton> m_btn;
	ScopedPointer<Label> m_lbl_user_name;
	ScopedPointer<Label> m_lbl_password;

};