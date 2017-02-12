#pragma once
#include "Main.h"
#include "action_entry.h"
REAPERDAWHUBDLL_API void toggleLoginWindow(action_entry&);
class LoginWindowComponent : public Component
{
public:
	REAPERDAWHUBDLL_API LoginWindowComponent();
	

private:
	TextEditor m_user_name;
	TextEditor m_password;
	TextButton m_btn;
	Label m_lbl_user_name;
	Label m_lbl_password;
	void resized() override;
};