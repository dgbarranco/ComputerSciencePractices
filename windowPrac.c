#include <windows.h>

void CreateUI(HWND hwnd);
void HandleSubmit(HWND hwnd);

/* ---------------- GLOBAL STATE ---------------- */
HWND hEdit = NULL;
HWND hNEdit = NULL;
HWND hResult = NULL;

int logicalAnd = 0;
int bitwiseAnd = 0;
int count = 0;
int N = 0;
int stage = 0;

/* ---------------- WINDOW PROCEDURE ---------------- */
LRESULT CALLBACK WindowProc(HWND hwnd,
                            UINT msg,
                            WPARAM wParam,
                            LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
            CreateUI(hwnd);
            return 0;

        case WM_COMMAND:
        {
            /* ✅ FIX: only react to button click */
            if (LOWORD(wParam) == 1001)
            {
                HandleSubmit(hwnd);
            }
            return 0;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}
