#pragma once

#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

#include "uiElements.h"
#include "color.h"

class HomeView
{
	private:
		int choice;
		void setChoice(int);

	public: 
		HomeView(); // Constructor
		~HomeView(); // Destructor
		void display();
		int& getChoice();
};

