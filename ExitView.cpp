#include <windows.h>
#include <conio.h>
#include <iostream>
#include <iomanip>

#include "ExitView.h"
#include "uiElements.h"
#include "color.h"

ExitView::ExitView()
{
	
}

ExitView::~ExitView()
{
}

int ExitView::display()
{
	do {
		system("cls");

		// Header
		ui::header();

		// Text
		color(5); // purple
		std::cout << "" << std::endl;
		std::cout << std::setw(28) << std::right << "ARE YOU SURE YOU WISH TO EXIT?" << std::endl;
		std::cout << "" << std::endl;
		
		// (1) Yes
		color(15); // white
		std::cout << "[1] ";
		color(12); // red
		std::cout << "YES" << std::endl;

		// (2) No
		color(15); // white
		std::cout << "[2] ";
		color(10); // green
		std::cout << "NO" << std::endl;

		// Footer 
		std::cout << "" << std::endl;
		ui::footerText("(Select your choice) ");

		// Handle user input
		char select = _getch();
		if (!(select < '1' || select > '2')) {
			if (select == '1') {
				return 0; // exit game
			}
			else {
				return 1; // main menu
			}
		}
	} while (true);
}