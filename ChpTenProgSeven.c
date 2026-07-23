/*
    Seven Segment Display (Win32 GUI version - RED segments)
    Uses only the built-in Windows API (user32, gdi32) -
    these ship with MinGW already, so there is NOTHING to download.

    Number entry is done entirely inside the GUI:
      - A white banner at the top shows a label + text box + Submit button
      - Pressing Enter in the text box submits
      - Clicking "Submit" also submits
      - No console window / no scanf involved anymore

    Compile:
        gcc SegWin32.c -o SegWin32.exe -lgdi32 -luser32 -mwindows

    Run:
        SegWin32.exe

    Note on the font: this requests "Roboto" by name. If Roboto isn't
    installed on the machine, Windows will silently substitute the
    closest matching font instead of erroring out - so this still
    compiles and runs with zero downloads either way.
*/

#include <windows.h>
#include <string.h>

#define MAX_DIGITS   10
#define ID_EDIT      101
#define ID_BUTTON    102
#define BANNER_HEIGHT 60

/*
    Segment order per digit:
    index 0 = top
    index 1 = upper-left
    index 2 = upper-right
    index 3 = middle
    index 4 = lower-left
    index 5 = lower-right
    index 6 = bottom
*/
const int segments[10][7] =
{
    {1,1,1,0,1,1,1}, //0
    {0,0,1,0,0,1,0}, //1
    {1,0,1,1,1,0,1}, //2
    {1,0,1,1,0,1,1}, //3
    {0,1,1,1,0,1,0}, //4
    {1,1,0,1,0,1,1}, //5
    {1,1,0,1,1,1,1}, //6
    {1,0,1,0,0,1,0}, //7
    {1,1,1,1,1,1,1}, //8
    {1,1,1,1,0,1,1}  //9
};

char g_number[MAX_DIGITS + 1] = "";  // nothing shown until the user submits

HWND     g_hEdit;
HWND     g_hButton;
HWND     g_hLabel;
HFONT    g_hFont;
WNDPROC  g_oldEditProc;

void DrawSegment(HDC hdc, int x, int y, int w, int h, int on)
{
    HBRUSH brush;

    if (on)
        brush = CreateSolidBrush(RGB(255, 0, 0));     // Red
    else
        brush = CreateSolidBrush(RGB(255, 255, 255)); // White (off segment)

    RECT rect = { x, y, x + w, y + h };
    FillRect(hdc, &rect, brush);
    DeleteObject(brush);
}

void DrawDigit(HDC hdc, int digit, int x, int y)
{
    const int thickness = 10;
    const int length = 50;

    // Top
    DrawSegment(hdc, x + thickness, y, length, thickness, segments[digit][0]);

    // Upper Left
    DrawSegment(hdc, x, y + thickness, thickness, length, segments[digit][1]);

    // Upper Right
    DrawSegment(hdc, x + thickness + length, y + thickness, thickness, length, segments[digit][2]);

    // Middle
    DrawSegment(hdc, x + thickness, y + thickness + length, length, thickness, segments[digit][3]);

    // Lower Left
    DrawSegment(hdc, x, y + 2 * thickness + length, thickness, length, segments[digit][4]);

    // Lower Right
    DrawSegment(hdc, x + thickness + length, y + 2 * thickness + length, thickness, length, segments[digit][5]);

    // Bottom
    DrawSegment(hdc, x + thickness, y + 2 * (thickness + length), length, thickness, segments[digit][6]);
}

// Subclass procedure for the edit control so we can catch Enter directly
LRESULT CALLBACK EditSubclassProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_KEYDOWN && wParam == VK_RETURN)
    {
        // Forward as if the Submit button was clicked
        SendMessage(GetParent(hwnd), WM_COMMAND, MAKEWPARAM(ID_BUTTON, BN_CLICKED), (LPARAM)hwnd);
        return 0; // swallow the beep/newline
    }

    return CallWindowProc(g_oldEditProc, hwnd, msg, wParam, lParam);
}

void SubmitNumber(HWND hwnd)
{
    char buffer[64];
    GetWindowText(g_hEdit, buffer, sizeof(buffer));

    // Copy only digit characters, up to MAX_DIGITS
    int j = 0;
    for (int i = 0; buffer[i] != '\0' && j < MAX_DIGITS; i++)
    {
        if (buffer[i] >= '0' && buffer[i] <= '9')
            g_number[j++] = buffer[i];
    }
    g_number[j] = '\0';

    InvalidateRect(hwnd, NULL, TRUE); // trigger repaint with the new number
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
        {
            g_hFont = CreateFont(
                -18, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Roboto");

            g_hLabel = CreateWindowEx(
                0, "STATIC", "Enter a number (up to 10 digits) : ",
                WS_CHILD | WS_VISIBLE | SS_LEFT,
                15, 18, 300, 25,
                hwnd, NULL, NULL, NULL);

            g_hEdit = CreateWindowEx(
                WS_EX_CLIENTEDGE, "EDIT", "",
                WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL | ES_NUMBER,
                320, 15, 140, 28,
                hwnd, (HMENU)ID_EDIT, NULL, NULL);
            SendMessage(g_hEdit, EM_LIMITTEXT, MAX_DIGITS, 0);

            g_hButton = CreateWindowEx(
                0, "BUTTON", "Submit",
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                475, 14, 90, 30,
                hwnd, (HMENU)ID_BUTTON, NULL, NULL);

            SendMessage(g_hLabel, WM_SETFONT, (WPARAM)g_hFont, TRUE);
            SendMessage(g_hEdit, WM_SETFONT, (WPARAM)g_hFont, TRUE);
            SendMessage(g_hButton, WM_SETFONT, (WPARAM)g_hFont, TRUE);

            // Subclass the edit box so pressing Enter submits
            g_oldEditProc = (WNDPROC)SetWindowLongPtr(g_hEdit, GWLP_WNDPROC, (LONG_PTR)EditSubclassProc);

            SetFocus(g_hEdit);
            return 0;
        }

        case WM_COMMAND:
        {
            if (LOWORD(wParam) == ID_BUTTON && HIWORD(wParam) == BN_CLICKED)
            {
                SubmitNumber(hwnd);
                SetFocus(g_hEdit);
            }
            return 0;
        }

        case WM_CTLCOLORSTATIC:
        {
            // White banner background behind the label text, black text
            HDC hdcStatic = (HDC)wParam;
            SetBkColor(hdcStatic, RGB(255, 255, 255));
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            return (LRESULT)GetStockObject(WHITE_BRUSH);
        }

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            RECT clientRect;
            GetClientRect(hwnd, &clientRect);

            // Black background for the digit area
            HBRUSH bg = CreateSolidBrush(RGB(0, 0, 0));
            FillRect(hdc, &clientRect, bg);
            DeleteObject(bg);

            // White banner strip at the top (behind label/edit/button)
            RECT bannerRect = { 0, 0, clientRect.right, BANNER_HEIGHT };
            HBRUSH white = CreateSolidBrush(RGB(255, 255, 255));
            FillRect(hdc, &bannerRect, white);
            DeleteObject(white);

            // Draw each digit below the banner
            for (int i = 0; g_number[i] != '\0'; i++)
            {
                if (g_number[i] >= '0' && g_number[i] <= '9')
                {
                    DrawDigit(hdc, g_number[i] - '0', 30 + i * 85, BANNER_HEIGHT + 30);
                }
            }

            EndPaint(hwnd, &ps);
            return 0;
        }

        case WM_DESTROY:
            DeleteObject(g_hFont);
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "SevenSegmentClass";
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        "SevenSegmentClass",
        "Seven Segment Display",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        900, 320,
        NULL, NULL, hInstance, NULL
    );

    ShowWindow(hwnd, SW_SHOW);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
