// draw.cpp : defines the entry point for the application.
//

#include "stdafx.h"
#include "draw.h"
#include <queue>;
#include <Windows.h>;
using namespace std;

#define MAX_LOADSTRING 100
#define TMR_1 1

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

INT value = 590;
queue  <int> kolejnosc_pieter;
int kolejnosc;
INT x = 0;
int liczba_osob_w_windzie = 0;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
HWND ButtonP, Button1, Button2, Button3, Button4, Button5, Button6;
HWND hWnd;
HWND ButtonP_panel, Button1_panel, Button2_panel, Button3_panel, Button4_panel, Button5_panel, Button6_panel;

RECT drawArea1 = { 97, 8, 158, 672 };

void rysuj_czlowieka(HDC hdc)
{
	Graphics graphics(hdc);
    Pen pen_czlowiek(Color(255, 255, 0, 0), 5);    
	for (int i = 1; i <= 8; i++){
		if (liczba_osob_w_windzie == i && i % 2 == 0){
			graphics.DrawRectangle(&pen_czlowiek, 130, 60 + value - i * 10, 5, 10);
		}
		else graphics.DrawRectangle(&pen_czlowiek, 110, 60 + value - i * 10, 5, 10);

	}
}

void MyOnPaint(HDC hdc)
{

	if (!kolejnosc_pieter.empty())
	{
		if (value < ((kolejnosc_pieter.front() * 96) + 14))  value++;
		if (value >((kolejnosc_pieter.front() * 96) + 14))  value--;
		if (value == ((kolejnosc_pieter.front() * 96) + 14))
		{
			x = 0;
			if (value < ((kolejnosc_pieter.front() * 96) + 14) && x == 0) value--;
			if (value >((kolejnosc_pieter.front() * 96) + 14) && x == 0) value++;
			if (x == 0)
			{
				kolejnosc_pieter.pop();
			}
		}
	}


	Graphics graphics(hdc);
	SolidBrush p_pietro(Color::Brown);
	SolidBrush napis(Color::RoyalBlue);
	Font numery(&FontFamily(L"Arial"), 40);
	Font n_napis(&FontFamily(L"Arial"), 35);
	Font l_osob(&FontFamily(L"Arial"), 25);
	Pen pen_winda(Color(255, 255, 0, 0), 3);
	Pen pen_sciana(Color(255, 0, 0, 0), 3);
	Pen pen_lina(Color(255, 0, 0, 255), 2);
	Pen pen_pietro(Color(255, 0, 0, 255), 8);
	

	graphics.DrawLine(&pen_sciana, 97, 0, 97, 674);
	graphics.DrawLine(&pen_sciana, 158, 0, 158, 674);
	graphics.DrawLine(&pen_lina, 127, 8, 127, 10 + value);


	graphics.DrawLine(&pen_pietro, 45, 4, 210, 4);

	graphics.DrawString(L"6", -1, &numery, PointF(45, 42), &p_pietro);
	graphics.DrawLine(&pen_pietro, 45, 100, 97, 100);
	graphics.DrawLine(&pen_pietro, 158, 100, 210, 100);

	graphics.DrawString(L"5", -1, &numery, PointF(45, 138), &p_pietro);
	graphics.DrawLine(&pen_pietro, 45, 196, 97, 196);
	graphics.DrawLine(&pen_pietro, 158, 196, 210, 196);

	graphics.DrawString(L"4", -1, &numery, PointF(45, 234), &p_pietro);
	graphics.DrawLine(&pen_pietro, 45, 292, 97, 292);
	graphics.DrawLine(&pen_pietro, 158, 292, 210, 292);

	graphics.DrawString(L"3", -1, &numery, PointF(45, 330), &p_pietro);
	graphics.DrawLine(&pen_pietro, 45, 388, 97, 388);
	graphics.DrawLine(&pen_pietro, 158, 388, 210, 388);

	graphics.DrawString(L"2", -1, &numery, PointF(45, 426), &p_pietro);
	graphics.DrawLine(&pen_pietro, 45, 484, 97, 484);
	graphics.DrawLine(&pen_pietro, 158, 484, 210, 484);

	graphics.DrawString(L"1", -1, &numery, PointF(45, 522), &p_pietro);
	graphics.DrawLine(&pen_pietro, 45, 580, 97, 580);
	graphics.DrawLine(&pen_pietro, 158, 580, 210, 580);

	graphics.DrawString(L"P", -1, &numery, PointF(45, 618), &p_pietro);
	graphics.DrawLine(&pen_pietro, 45, 676, 210, 676);


	graphics.DrawRectangle(&pen_winda, 100, 10 + value, 55, 70);
	graphics.DrawString(L"Panel", -1, &n_napis, PointF(420, 50), &napis);
	graphics.DrawString(L"Max. liczba osób w windzie: 8", -1, &l_osob, PointF(290, 600), &napis);


	rysuj_czlowieka(HDC hdc)

}

int OnCreate(HWND window)
{
   SetTimer(window, TMR_1, 25, 0);
   return 0;
}



int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}


	ButtonP = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "P", WS_CHILD | WS_VISIBLE,
		165, 625, 45, 45, hWnd, NULL, hInstance, NULL);

	Button1 = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "1", WS_CHILD | WS_VISIBLE,
		165, 529, 45, 45, hWnd, NULL, hInstance, NULL);

	Button2 = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "2", WS_CHILD | WS_VISIBLE,
		165, 433, 45, 45, hWnd, NULL, hInstance, NULL);

	Button3 = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "3", WS_CHILD | WS_VISIBLE,
		165, 337, 45, 45, hWnd, NULL, hInstance, NULL);

	Button4 = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "4", WS_CHILD | WS_VISIBLE,
		165, 241, 45, 45, hWnd, NULL, hInstance, NULL);

	Button5 = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "5", WS_CHILD | WS_VISIBLE,
		165, 145, 45, 45, hWnd, NULL, hInstance, NULL);

	Button6 = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "6", WS_CHILD | WS_VISIBLE,
		165, 49, 45, 45, hWnd, NULL, hInstance, NULL);

	ButtonP_panel = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "P", WS_CHILD | WS_VISIBLE,
		445, 110, 40, 40, hWnd, NULL, hInstance, NULL);

	Button1_panel = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "1", WS_CHILD | WS_VISIBLE,
		485, 110, 40, 40, hWnd, NULL, hInstance, NULL);

	Button2_panel = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "2", WS_CHILD | WS_VISIBLE,
		445, 150, 40, 40, hWnd, NULL, hInstance, NULL);

	Button3_panel = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "3", WS_CHILD | WS_VISIBLE,
		485, 150, 40, 40, hWnd, NULL, hInstance, NULL);

	Button4_panel = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "4", WS_CHILD | WS_VISIBLE,
		445, 190, 40, 40, hWnd, NULL, hInstance, NULL);

	Button5_panel = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "5", WS_CHILD | WS_VISIBLE,
		485, 190, 40, 40, hWnd, NULL, hInstance, NULL);

	Button6_panel = CreateWindowEx(WS_EX_WINDOWEDGE, "BUTTON", "6", WS_CHILD | WS_VISIBLE,
		445, 230, 40, 40, hWnd, NULL, hInstance, NULL);



	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int) msg.wParam;
}

void repaintWindow(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea)
{
	if (drawArea == NULL)
		InvalidateRect(hWnd, NULL, TRUE); // repaint all
	else
		InvalidateRect(hWnd, drawArea, TRUE); //repaint drawArea
	hdc = BeginPaint(hWnd, &ps);
	MyOnPaint(hdc);
	EndPaint(hWnd, &ps);
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
 

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
   
   OnCreate(hWnd);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	//OnCreate(hWnd,wParam,lParam);
	//OnTimer(hWnd,wParam,lParam);

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		if ((HWND)lParam == ButtonP) kolejnosc_pieter.push(6);
		if ((HWND)lParam == Button1) kolejnosc_pieter.push(5);
		if ((HWND)lParam == Button2) kolejnosc_pieter.push(4);
		if ((HWND)lParam == Button3) kolejnosc_pieter.push(3);
		if ((HWND)lParam == Button4) kolejnosc_pieter.push(2);
		if ((HWND)lParam == Button5) kolejnosc_pieter.push(1);
		if ((HWND)lParam == Button6) kolejnosc_pieter.push(0);
		if ((HWND)lParam == ButtonP_panel) kolejnosc_pieter.push(6);
		if ((HWND)lParam == Button1_panel) kolejnosc_pieter.push(5);
		if ((HWND)lParam == Button2_panel) kolejnosc_pieter.push(4);
		if ((HWND)lParam == Button3_panel) kolejnosc_pieter.push(3);
		if ((HWND)lParam == Button4_panel) kolejnosc_pieter.push(2);
		if ((HWND)lParam == Button5_panel) kolejnosc_pieter.push(1);
		if ((HWND)lParam == Button6_panel) kolejnosc_pieter.push(0);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
			case TMR_1:
				//force window to repaint
				repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;
		}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
