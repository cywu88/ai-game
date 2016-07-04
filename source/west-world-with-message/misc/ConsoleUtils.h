#pragma once

#ifdef WIN32
#include <windows.h>
#include <iostream>
#include <conio.h>

inline void SetTextColor(WORD colors)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, colors);
}

inline void PressAnyKeyToContinue()
{
	//change text color to white
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

	std::cout << "\n\nPress any key to continue" << std::endl;

	while (!_kbhit()) {}

	return;
}


#endif // WIN32

