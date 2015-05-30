// draw.cpp : defines the entry point for the application.
//

#include "stdafx.h"
#include "draw.h"
#include <queue>;
#include <Windows.h>;
#include <time.h>;
#include <ctime>;
#include <cstdlib>;
using namespace std;


#define MAX_LOADSTRING 100
#define TMR_1 1

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
HWND hwndButton;
HWND hWnd;

INT value = 590;
queue  <int> kolejnosc_pieter;
INT x = 0;
int liczba_osob_w_windzie = 4;


// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

RECT drawArea1 = { 97, 8, 158, 672 };





/*void poczatek(HDC hdc, LPARAM lParam){
	Graphics graphics(hdc);
	Pen pen_czlowiek(Color(255, 255, 0, 0), 5);
	srand(time(NULL));
	
	if ((HWND)lParam == ButtonP || (HWND)lParam == Button1 || (HWND)lParam == Button2 || (HWND)lParam == Button3 || (HWND)lParam == Button4
		|| (HWND)lParam == Button5 || (HWND)lParam == Button6){
		liczba_osob_w_windzie = (rand() % 8) + 1;
		graphics.DrawRectangle(&pen_czlowiek, 135, 75, 4, 8);
	}
	

}*/

void rysuj_czlowieka(HDC &hdc)
{
	Graphics graphics(hdc);
	Pen pen_czlowiek(Color(255, 255, 0, 0), 5);
	for (int i = 0; i <= liczba_osob_w_windzie; i++){
		if (i % 2 == 0 && i != 0){
			graphics.DrawRectangle(&pen_czlowiek, 135, 75 + value - (i - 1) * 8, 4, 8);
		}
		else if (i % 2 != 0 && i != 0) graphics.DrawRectangle(&pen_czlowiek, 115, 75 + value - i * 8, 4, 8);
		else;
	}
}


/*void wsiadanie(HDC &hdc)
{
	Graphics graphics(hdc);
	SolidBrush napis(Color::RoyalBlue);
	Font l_osob(&FontFamily(L"Arial"), 25);
	Pen pen_winda(Color(255, 255, 0, 0), 3);
	graphics.DrawRectangle(&pen_winda, 200, 400, 55, 70);
	if ((liczba_osob_w_windzie + ile_osob_wsiada) <= 8){
		liczba_osob_w_windzie = liczba_osob_w_windzie + ile_osob_wsiada;
	}
	else graphics.DrawString(L"SCHODAMI KURWA!!!", -1, &l_osob, PointF(290, 400), &napis);


}


void wysiadanie(HDC &hdc)
{
        liczba_osob_w_windzie = liczba_osob_w_windzie - ile_osob_wysiada; 
		
}*/



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
			if (value > ((kolejnosc_pieter.front() * 96) + 14) && x == 0) value++;
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
	graphics.DrawString(L"Max. liczba osob w windzie: 8", -1, &l_osob, PointF(290, 600), &napis);
	graphics.DrawString(L"Ile os�b wsiada?", -1, &n_napis, PointF(570, 50), &napis);
	graphics.DrawString(L"Ile os�b wysiada?", -1, &n_napis, PointF(950, 50), &napis);


	rysuj_czlowieka(hdc);
/*	poczatek(hdc, lParam);
	rysuj_czlowieka(hdc);
	while (liczba_osob_w_windzie != 0){
		wysiadanie(hdc, lParam);
		rysuj_czlowieka(hdc);
		wsiadanie(hdc);
		rysuj_czlowieka(hdc);
	}
	
*/
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


	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("P"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 165, 625, 45, 45, hWnd, (HMENU)ID_BUTTONP, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 165, 529, 45, 45, hWnd, (HMENU)ID_BUTTON1, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 165, 433, 45, 45, hWnd, (HMENU)ID_BUTTON2, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 165, 337, 45, 45, hWnd, (HMENU)ID_BUTTON3, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 165, 241, 45, 45, hWnd, (HMENU)ID_BUTTON4, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 165, 145, 45, 45, hWnd, (HMENU)ID_BUTTON5, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("6"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 165, 49, 45, 45, hWnd, (HMENU)ID_BUTTON6, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("P"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 445, 110, 40, 40, hWnd, (HMENU)ID_BUTTONP_panel, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 485, 110, 40, 40, hWnd, (HMENU)ID_BUTTON1_panel, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 445, 150, 40, 40, hWnd, (HMENU)ID_BUTTON2_panel, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 485, 150, 40, 40, hWnd, (HMENU)ID_BUTTON3_panel, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 445, 190, 40, 40, hWnd, (HMENU)ID_BUTTON4_panel, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 485, 190, 40, 40, hWnd, (HMENU)ID_BUTTON5_panel, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("6"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 445, 230, 40, 40, hWnd, (HMENU)ID_BUTTON6_panel, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("0"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 690, 120, 40, 40, hWnd, (HMENU)ID_BUTTON0_cz, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 730, 120, 40, 40, hWnd, (HMENU)ID_BUTTON1_cz, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 690, 160, 40, 40, hWnd, (HMENU)ID_BUTTON2_cz, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 730, 160, 40, 40, hWnd, (HMENU)ID_BUTTON3_cz, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 690, 200, 40, 40, hWnd, (HMENU)ID_BUTTON4_cz, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 730, 200, 40, 40, hWnd, (HMENU)ID_BUTTON5_cz, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("6"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 690, 240, 40, 40, hWnd, (HMENU)ID_BUTTON6_cz, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("7"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 730, 240, 40, 40, hWnd, (HMENU)ID_BUTTON7_cz, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("8"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 690, 280, 40, 40, hWnd, (HMENU)ID_BUTTON8_cz, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("0"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1070, 120, 40, 40, hWnd, (HMENU)ID_BUTTON0_wys, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1110, 120, 40, 40, hWnd, (HMENU)ID_BUTTON1_wys, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1070, 160, 40, 40, hWnd, (HMENU)ID_BUTTON2_wys, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1110, 160, 40, 40, hWnd, (HMENU)ID_BUTTON3_wys, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1070, 200, 40, 40, hWnd, (HMENU)ID_BUTTON4_wys, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1110, 200, 40, 40, hWnd, (HMENU)ID_BUTTON5_wys, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("6"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1070, 240, 40, 40, hWnd, (HMENU)ID_BUTTON6_wys, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("7"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1110, 240, 40, 40, hWnd, (HMENU)ID_BUTTON7_wys, hInstance, NULL);

	hwndButton = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("button"), TEXT("8"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1070, 280, 40, 40, hWnd, (HMENU)ID_BUTTON8_wys, hInstance, NULL);


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

void repaintWindow(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea, LPARAM lParam)
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
	int ile_osob_wsiada = 0;
	int ile_osob_wysiada=0;
	//OnCreate(hWnd,wParam,lParam);
	//OnTimer(hWnd,wParam,lParam);

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_BUTTONP:
			kolejnosc_pieter.push(6);
			if ((liczba_osob_w_windzie + ile_osob_wsiada) <= 8){
				liczba_osob_w_windzie = liczba_osob_w_windzie + ile_osob_wsiada;
			}
				rysuj_czlowieka(hdc);
				SetFocus(hWnd);
				break;
		case ID_BUTTON1:
			kolejnosc_pieter.push(5);
			if ((liczba_osob_w_windzie + ile_osob_wsiada) <= 8){
				liczba_osob_w_windzie = liczba_osob_w_windzie + ile_osob_wsiada;
			}
				rysuj_czlowieka(hdc);
				SetFocus(hWnd);
				break;
		case ID_BUTTON2:
			kolejnosc_pieter.push(4);
			if ((liczba_osob_w_windzie + ile_osob_wsiada) <= 8){
				liczba_osob_w_windzie = liczba_osob_w_windzie + ile_osob_wsiada;
			}
			rysuj_czlowieka(hdc);
			SetFocus(hWnd);
				break;
		case ID_BUTTON3:
			kolejnosc_pieter.push(3);
			if ((liczba_osob_w_windzie + ile_osob_wsiada) <= 8){
				liczba_osob_w_windzie = liczba_osob_w_windzie + ile_osob_wsiada;
			}
			rysuj_czlowieka(hdc);
			SetFocus(hWnd);
				break;
		case ID_BUTTON4:
			kolejnosc_pieter.push(2);
			if ((liczba_osob_w_windzie + ile_osob_wsiada) <= 8){
				liczba_osob_w_windzie = liczba_osob_w_windzie + ile_osob_wsiada;
			}
			rysuj_czlowieka(hdc);
			SetFocus(hWnd);
			break;
		case ID_BUTTON5:
			kolejnosc_pieter.push(1);
			if ((liczba_osob_w_windzie + ile_osob_wsiada) <= 8){
				liczba_osob_w_windzie = liczba_osob_w_windzie + ile_osob_wsiada;
			}
			rysuj_czlowieka(hdc);
			SetFocus(hWnd);
			break;
		case ID_BUTTON6:
			kolejnosc_pieter.push(0);
			if ((liczba_osob_w_windzie + ile_osob_wsiada) <= 8){
				liczba_osob_w_windzie = liczba_osob_w_windzie + ile_osob_wsiada;
			}
			
			rysuj_czlowieka(hdc);
			SetFocus(hWnd);
			break;
		case ID_BUTTONP_panel:
			kolejnosc_pieter.push(6);
			liczba_osob_w_windzie = liczba_osob_w_windzie - ile_osob_wysiada;
			rysuj_czlowieka(hdc);
			SetFocus(hWnd);
			break;
		case ID_BUTTON1_panel:
			kolejnosc_pieter.push(5);
			liczba_osob_w_windzie = liczba_osob_w_windzie - ile_osob_wysiada;
			rysuj_czlowieka(hdc);
			SetFocus(hWnd);
			break;
		case ID_BUTTON2_panel:
			kolejnosc_pieter.push(4);
			liczba_osob_w_windzie = liczba_osob_w_windzie - ile_osob_wysiada;
			rysuj_czlowieka(hdc);
			SetFocus(hWnd);
			break;
		case ID_BUTTON3_panel:
			kolejnosc_pieter.push(3);
			liczba_osob_w_windzie = liczba_osob_w_windzie - ile_osob_wysiada;
			rysuj_czlowieka(hdc);
			SetFocus(hWnd);
			break;
		case ID_BUTTON4_panel:
			kolejnosc_pieter.push(2);
			liczba_osob_w_windzie = liczba_osob_w_windzie - ile_osob_wysiada;
			rysuj_czlowieka(hdc);
			SetFocus(hWnd);
			break;
		case ID_BUTTON5_panel:
			kolejnosc_pieter.push(1);
			liczba_osob_w_windzie = liczba_osob_w_windzie - ile_osob_wysiada;
			rysuj_czlowieka(hdc);
			SetFocus(hWnd);
			break;
		case ID_BUTTON6_panel:
			kolejnosc_pieter.push(0);
			liczba_osob_w_windzie = liczba_osob_w_windzie - ile_osob_wysiada;
			rysuj_czlowieka(hdc);
			SetFocus(hWnd);
			break;
		case ID_BUTTON0_cz:
			ile_osob_wsiada = 0;
			SetFocus(hWnd);
			break;
		case ID_BUTTON1_cz:
			ile_osob_wsiada = 1;
			SetFocus(hWnd);
			break;
		case ID_BUTTON2_cz:
			ile_osob_wsiada = 2;
			SetFocus(hWnd);
			break;
		case ID_BUTTON3_cz:
			ile_osob_wsiada = 3;
			SetFocus(hWnd);
			break;
		case ID_BUTTON4_cz:
			ile_osob_wsiada = 4;
			SetFocus(hWnd);
			break;
		case ID_BUTTON5_cz:
			ile_osob_wsiada = 5;
			SetFocus(hWnd);
			break;
		case ID_BUTTON6_cz:
			ile_osob_wsiada = 6;
			SetFocus(hWnd);
			break;
		case ID_BUTTON7_cz:
			ile_osob_wsiada = 7;
			SetFocus(hWnd);
			break;
		case ID_BUTTON8_cz:
			ile_osob_wsiada = 8;
			SetFocus(hWnd);
            break;
		case ID_BUTTON0_wys:
			ile_osob_wysiada = 0;
			SetFocus(hWnd);
			break;
		case ID_BUTTON1_wys:
			ile_osob_wysiada = 1;
			SetFocus(hWnd);
			break;
		case ID_BUTTON2_wys:
			ile_osob_wysiada = 2;
			SetFocus(hWnd);
			break;
		case ID_BUTTON3_wys:
			ile_osob_wysiada = 3;
			SetFocus(hWnd);
			break;
		case ID_BUTTON4_wys:
			ile_osob_wysiada = 4;
			SetFocus(hWnd);
			break;
		case ID_BUTTON5_wys:
			ile_osob_wysiada = 5;
			SetFocus(hWnd);
			break;
		case ID_BUTTON6_wys:
			ile_osob_wysiada = 6;
			SetFocus(hWnd);
			break;
		case ID_BUTTON7_wys:
			ile_osob_wysiada = 7;
			SetFocus(hWnd);
			break;
		case ID_BUTTON8_wys:
			ile_osob_wysiada = 8;
			SetFocus(hWnd);
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
				repaintWindow(hWnd, hdc, ps, &drawArea1, lParam);
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
