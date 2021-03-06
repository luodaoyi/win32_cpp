//1精简的窗口程序.cpp: 定义应用程序的入口点。
//

#include "stdafx.h"
#include "1精简的窗口程序.h"

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
	while (GetMessage(&msg, hwnd, 0, 0))
	{
		//5分发获取到的消息
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK myWindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam   // second message parameter
) 
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		MessageBox(NULL, TEXT("鼠标左键按下"), TEXT("提示"),0);
		return 0;
	case WM_RBUTTONDOWN:
		MessageBox(NULL, TEXT("鼠标右键按下"), TEXT("提示"), 0);
	default:
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


