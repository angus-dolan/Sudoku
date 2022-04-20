#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

#include "HomeView.h"
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
	while (true)
	{
		system("cls");

		// Header
		ui::header();

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
		ui::footerText("(Select your choice) ");

		// Handle user input
		char selection = _getch();
		if (!(selection < '1' || selection > '3')) {
			int selection_int = (int)((char)selection - '0');

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