#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

extern HWND hEdit;
extern HWND hNEdit;
extern HWND hResult;

extern int logicalAnd;
extern int bitwiseAnd;
extern int count;
extern int N;
extern int stage;

/* ---------------- UI ---------------- */
void CreateUI(HWND hwnd)
{
    CreateWindowA(
        "STATIC",
        "Enter N (how many integers):",
        WS_VISIBLE | WS_CHILD,
        20, 10, 250, 20,
        hwnd, NULL, NULL, NULL);

    hNEdit = CreateWindowA(
        "EDIT",
        "",
        WS_VISIBLE | WS_CHILD | WS_BORDER,
        20, 35, 100, 25,
        hwnd, NULL, NULL, NULL);

    hEdit = CreateWindowA(
        "EDIT",
        "",
        WS_VISIBLE | WS_CHILD | WS_BORDER,
        20, 80, 100, 25,
        hwnd, NULL, NULL, NULL);

    CreateWindowA(
        "BUTTON",
        "Submit",
        WS_VISIBLE | WS_CHILD,
        150, 80, 100, 30,
        hwnd,
        (HMENU)1001,   /* ✅ MUST MATCH FIX */
        NULL,
        NULL);

    hResult = CreateWindowA(
        "STATIC",
        "Waiting...",
        WS_VISIBLE | WS_CHILD,
        20, 130, 500, 100,
        hwnd,
        NULL,
        NULL,
        NULL);
}

/* ---------------- HANDLE INPUT (SAFE) ---------------- */
void HandleSubmit(HWND hwnd)
{
    if (!hEdit || !hNEdit)
    {
        MessageBoxA(hwnd, "UI not initialized", "Error", MB_OK);
        return;
    }

    char buffer[100];
    GetWindowTextA(hEdit, buffer, sizeof(buffer));

    /* ---------------- STEP 1: READ N ---------------- */
    if (stage == 0)
    {
        char nbuf[50];
        GetWindowTextA(hNEdit, nbuf, sizeof(nbuf));

        char *endptr;
        long tempN = strtol(nbuf, &endptr, 10);

        if (nbuf[0] == '\0' || *endptr != '\0' || tempN <= 0)
        {
            MessageBoxA(hwnd, "Enter valid positive N", "Input Error", MB_OK);
            return;
        }

        N = (int)tempN;
        stage = 1;
        count = 0;

        SetWindowTextA(hResult, "Now enter integers...");
        return;
    }

    /* ---------------- STEP 2: READ NUMBERS ---------------- */
    char *endptr;
    long num = strtol(buffer, &endptr, 10);

    if (buffer[0] == '\0' || *endptr != '\0')
    {
        MessageBoxA(hwnd, "Invalid integer input", "Input Error", MB_OK);
        return;
    }

    if (count == 0)
    {
        logicalAnd = (int)num;
        bitwiseAnd = (int)num;
    }
    else
    {
        logicalAnd = logicalAnd && num;
        bitwiseAnd = bitwiseAnd & num;
    }

    count++;

    /* ---------------- DONE ---------------- */
    if (count >= N)
    {
        char out[200];
        sprintf(out,
            "FINAL RESULT\nLogical AND: %d\nBitwise AND: %d",
            logicalAnd, bitwiseAnd);

        SetWindowTextA(hResult, out);

        stage = 0;
        return;
    }

    /* ---------------- CONTINUE ---------------- */
    char msg[100];
    sprintf(msg, "Enter number %d of %d", count + 1, N);
    SetWindowTextA(hResult, msg);
}
