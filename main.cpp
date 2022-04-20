#include <string>
#include <iostream>

#include "ViewRouter.h"
#include "hideCursor.h"

using namespace std;

int main()
{
	ViewRouter* router = new ViewRouter(); // Holds all the games views
	hideCursor(true); // Hide cursor in console

	// Main Menu
	// 1 = Start Game, 2 = Read Instructions, 3 = Exit Game 
	router->homeView->display();
	if (router->homeView->getChoice() == 1) {}
}