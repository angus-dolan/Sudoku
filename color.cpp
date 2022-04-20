#include <windows.h>

void color(int tint) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tint);
}