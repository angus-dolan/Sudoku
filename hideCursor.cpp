#include <windows.h>

void hideCursor(bool condition)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    // Set cursor visability
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = (!(condition));
    SetConsoleCursorInfo(out, &cursorInfo);
}