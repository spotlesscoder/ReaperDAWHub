#include <windows.h>

#define IDC_LOGIN_OK_BUTTON 101
#define IDC_LOGIN_CANCEL_BUTTON 102

#define IDC_LOGIN_USERNAME_BOX 103
#define IDC_LOGIN_PASSWORD_BOX 104

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

char szClassName[] = "ReaperDAWHubLoginWindow";

const int EDIT_WIDTH = 200;
const int EDIT_HEIGHT = 24;

const int BTN_WIDHT = 70;
const int BTN_HEIGHT = EDIT_HEIGHT;

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance,
	LPSTR lpszArgument, int nCmdShow)
{
	HWND hwnd;
	MSG messages;
	WNDCLASSEX wincl;
	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = szClassName;
	wincl.lpfnWndProc = WindowProcedure;
	wincl.style = CS_DBLCLKS;
	wincl.cbSize = sizeof(WNDCLASSEX);
	wincl.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wincl.hIconSm = LoadIcon(NULL, IDI_ASTERISK);
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;
	wincl.cbClsExtra = 0;
	wincl.cbWndExtra = 0;
	wincl.hbrBackground = (HBRUSH)COLOR_BACKGROUND;

	
	if (!RegisterClassEx(&wincl))
		return 0;
	
	hwnd = CreateWindowEx(
		0,
		szClassName,
		"Code::Blocks Template Windows App",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		500,
		230,
		HWND_DESKTOP,
		NULL,
		hThisInstance,
		NULL
	);

	HWND hWndButtonOK = CreateWindowEx(NULL,
		"BUTTON",
		"OK",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		340, //x
		160, //y
		BTN_WIDHT, //width
		BTN_HEIGHT, //height
		hwnd,
		(HMENU)IDC_LOGIN_OK_BUTTON,
		GetModuleHandle(NULL),
		NULL);

	HWND hWndButtonCancel = CreateWindowEx(NULL,
		"BUTTON",
		"Cancel",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		340+BTN_WIDHT,
		160,
		BTN_WIDHT,
		BTN_HEIGHT,
		hwnd,
		(HMENU)IDC_LOGIN_CANCEL_BUTTON,
		GetModuleHandle(NULL),
		NULL);

	int editY = 50;
	int editX = 150;

	HWND hEditUsername = CreateWindowEx(WS_EX_CLIENTEDGE,
		"EDIT",
		"Username",
		WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
		editX,
		editY,
		EDIT_WIDTH,
		EDIT_HEIGHT,
		hwnd,
		(HMENU)IDC_LOGIN_USERNAME_BOX,
		GetModuleHandle(NULL),
		NULL);

	 HWND hEditPassword = CreateWindowEx(WS_EX_CLIENTEDGE,
		 "EDIT",
		 NULL,
		 WS_CHILD | WS_VISIBLE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_PASSWORD,
		 editX,
		 editY+EDIT_HEIGHT,
		 EDIT_WIDTH,
		 EDIT_HEIGHT,
		 hwnd,
		 (HMENU)IDC_LOGIN_PASSWORD_BOX,
		 GetModuleHandle(NULL),
		 NULL);

	ShowWindow(hwnd, nCmdShow);

	while (GetMessage(&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}

	return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}