#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

#include "HomeView.h"
#include "hideCursor.h"
#include "color.h"
#include "uiElements.h"

HomeView::HomeView()
{
	choice = NULL;
}

HomeView::~HomeView()
{
	delete &choice;
}

void HomeView::display()
{
	hideCursor(true); // Hide cursor in console

	while (true)
	{
		system("cls");

		// Header
		color(5); // purple
		ui::lineSmallLeft();
		color(15); // white
		std::cout << "SUDOKU";
		color(5); // purple
		ui::lineSmallRight();

		// (1): Start Game
		color(7); // dark white
		std::cout << "[1] ";
		color(10); // green
		std::cout << "START GAME" << std::endl;
		

		// (2): Read Instructions
		color(7); // white
		std::cout<<"[2] ";
		color(11); // light blue
		std::cout << "INSTRUCTIONS" << std::endl;

		// (3): Exit Game
		color(7); // dark white
		std::cout << "[3] ";
		color(12); // light red
		std::cout << "EXIT" << std::endl;

		// Footer 
		color(5); // purple
		ui::seperator();
		color(7); // dark white
		std::cout << "(Select your choice) ";
		color(15); // white

		char selection = _getch();
		if (!(selection < '1' || selection > '3')) {
			int selection_int = (int)((char)selection - '0');
			int* selection_int_ptr = &selection_int;

			setChoice(selection_int);
			break;
		}
	}
}

void HomeView::setChoice(int payload)
{
	choice = payload;
}

int& HomeView::getChoice()
{
	return choice;
}