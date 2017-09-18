// L2P1Win.cpp : Defines the entry point for the application.
//
#include "Wrapper.h"
#include "AirportRecord.h"
#include "AirportSequence.h"
#include "stdafx.h"
#include "L2P1Win.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
AirportSequence globalAirportDataSeq;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



void doPaintData(HDC hdc, AirportSequence& s);


void doInputAirportDataFromFile(AirportSequence& s, Text& filename);
//! replaces s
//! restores filename
//! ensures: loads into s all the airport records 
//!          from the airport data file named filename
//!          the order of the records stored in s does not matter


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_L2P1WIN, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_L2P1WIN));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_L2P1WIN));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_L2P1WIN);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
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
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			doPaintData(hdc, globalAirportDataSeq);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;


	case WM_CREATE: {
		Text filename = "air15.dat";
		doInputAirportDataFromFile(globalAirportDataSeq, filename);
		}break;
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


void doInputAirportDataFromFile(AirportSequence& s, Text& filename) {

	File input;
	Boolean successful;
	AirportRecord r;
	Integer dataSize;

	input.openFile(filename, File::openForRead, successful);

	if (successful) {
		input.read(dataSize, successful);
		for (int j = 0; j < dataSize; j++) {
			input.read(r.iata, successful);
			input.read(r.name, successful);
			input.read(r.city, successful);
			input.read(r.country, successful);
			input.read(r.latDegrees, successful);
			input.read(r.latMinutes, successful);
			input.read(r.latSeconds, successful);
			input.read(r.latDirection, successful);
			input.read(r.longDegrees, successful);
			input.read(r.longMinutes, successful);
			input.read(r.longSeconds, successful);
			input.read(r.longDirection, successful);
			input.read(r.altitude, successful);
			s.add(0, r);

		} // end for
		input.closeFile(successful);
	} // end if
	else {
		wcout << "File Not Found." << endl;
	}
}

void doPaintData(HDC hdc, AirportSequence& s) {
	
	AirportRecord r;
	for (int i = 0; i < s.length(); i++) {
		r.iata = s.entry(i).iata;
		r.name = s.entry(i).name;
		r.city = s.entry(i).city;
		r.country = s.entry(i).country;
		r.latDegrees = s.entry(i).latDegrees;
		r.latMinutes = s.entry(i).latMinutes;
		r.latSeconds = s.entry(i).latSeconds;
		r.latDirection = s.entry(i).latDirection;
		r.longDegrees = s.entry(i).longDegrees;
		r.longMinutes = s.entry(i).longMinutes;
		r.longSeconds = s.entry(i).longSeconds;
		r.longDirection = s.entry(i).longDirection;
		r.altitude = s.entry(i).altitude;
		Text t;
		r.toString(r,t);
		Integer yLoc, xLoc;
		Integer lineHeight;
		xLoc = 10;
		yLoc = -10 + (i*(20));
		SIZE text_Size;
		GetTextExtentPoint32(hdc, t, t.size(), &text_Size);
		lineHeight = text_Size.cy;
		yLoc += lineHeight;
		TextOut(hdc, xLoc, yLoc, t, t.size());
	}
}
