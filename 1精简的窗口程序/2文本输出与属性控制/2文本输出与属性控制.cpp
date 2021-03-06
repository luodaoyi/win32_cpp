//2文本输出与属性控制.cpp: 定义应用程序的入口点。
//

#include "stdafx.h"
#include "2文本输出与属性控制.h"

#define BUFFER_LENGTH 255
#define RED_COLOR RGB(255,0,0)
#define YELLOW_COLOR RGB(255,255,0)

LRESULT CALLBACK myWindowProc(
	HWND hwnd,      // handle to window
	UINT uMsg,      // message identifier
	WPARAM wParam,  // first message parameter
	LPARAM lParam   // second message parameter
);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	MSG msg = { 0 };
	//1初始化一个WNDCLASS
	WNDCLASS wndclass = { 0 };
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = myWindowProc;
	wndclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wndclass.lpszClassName = TEXT("my first wnd");


	//2向OS注册一下

	RegisterClass(&wndclass);

	//3调用CreateWindows()创建窗口
	HWND hwnd = CreateWindow(TEXT("my first wnd"), TEXT("啦啦啦"), WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 400, 400, NULL, NULL, hInstance, NULL);
	//4获取OS发来的各类消息
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		//5分发获取到的消息
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}


LRESULT CALLBACK myWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = { 0 };
	TCHAR szBuff[BUFFER_LENGTH] = TEXT("欢迎大爷来玩!");
	LOGFONT lf = { 0 };
	HFONT hfont = NULL;
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		//MessageBox(NULL, TEXT("鼠标左键按下"), TEXT("提示"), 0);
		ZeroMemory(szBuff, BUFFER_LENGTH);
		swprintf_s(szBuff, L"%s", TEXT("编程达人"));

		hdc = GetDC(hwnd);
		
		lf.lfWeight = 50;
		lf.lfHeight = 50;
		hfont= CreateFontIndirect(&lf);
		
		//SetBkMode(hdc, TRANSPARENT);
		SetBkColor(hdc, RED_COLOR);
		SelectObject(hdc, hfont); //关联起来
		TextOut(hdc, 20, 40, szBuff, _tcslen(szBuff));
		ReleaseDC(hwnd, hdc);

		return 0;
	case WM_RBUTTONDOWN:
		//MessageBox(NULL, TEXT("鼠标右键按下"), TEXT("提示"), 0);
		//MessageBox(NULL, TEXT("鼠标左键按下"), TEXT("提示"), 0);
		ZeroMemory(szBuff, BUFFER_LENGTH);

		swprintf_s(szBuff, L"%s", TEXT("欢迎你    "));
		hdc = GetDC(hwnd);
		SetBkColor(hdc, YELLOW_COLOR);
		TextOut(hdc, 20, 40, szBuff, _tcslen(szBuff));
		ReleaseDC(hwnd, hdc);

		return 0;
	case WM_PAINT:

		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 20, 20, szBuff, _tcslen(szBuff));
		EndPaint(hwnd, &ps);

		return 0;
	default:
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


