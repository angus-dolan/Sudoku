#include <string>
#include <iostream>

#include "ViewRouter.h"
#include "hideCursor.h"

using namespace std;

int main()
{
    ViewRouter* router = new ViewRouter(); // Holds all the games views
    hideCursor(true); // Hide cursor in console

    router->gameView->display();

	// Main Menu
	// 1 = Start Game, 2 = Load Saved Game, 3 = Exit Game 
	//router->homeView->display();
	//if (router->homeView->getChoice() == 3) 
	//{
	//	int exitChoice = router->exitView->display();

	//	if (exitChoice == 0) exit(0); // 0 = exit
	//	else main(); // 1 = return to main menu
	//}
}