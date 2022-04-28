#include "ViewRouter.h"
#include "hideCursor.h"

using namespace std;

int main()
{
    ViewRouter* router = new ViewRouter(); // Holds all the games views
    hideCursor(true); // Hide cursor in console

	// Main Menu
	// 1 = Start Game, 2 = Load Saved Game, 3 = Exit Game 
	router->homeView->display();
	if (router->homeView->getChoice() == 1)
	{
		// Select difficulty
		system("cls");
		// Header
		ui::header();

		// (0): Go Back
		color(7); // dark white
		std::cout << "[0] ";
		color(13); // green
		std::cout << "GO BACK" << std::endl;
		std::cout << std::endl;

		// (1): Start Game
		color(7); // dark white
		std::cout << "[1] ";
		color(10); // green
		std::cout << "EASY" << std::endl;

		// (2): Load Saved Game
		color(7); // white
		std::cout << "[2] ";
		color(14); // light blue
		std::cout << "MEDIUM" << std::endl;

		// (3): Exit Game
		color(7); // dark white
		std::cout << "[3] ";
		color(12); // light red
		std::cout << "HARD" << std::endl;

		// Footer 
		ui::footerText("(Select your difficulty) ");

		// Handle user input
		char selection = _getch();
		int selection_int;
		if (!(selection < '0' || selection > '3')) {
			selection_int = (int)((char)selection - '0');

			// Go back
			if (selection_int == 0) main();

			// Load game view
			int gameViewChoice = router->gameView->display(selection_int, true, "");
			if (gameViewChoice == 0) exit(0); // quit game
		}
	}	
	else if (router->homeView->getChoice() == 2)
	{
		// Load Game
		system("cls");
		hideCursor(false);

		// Header
		ui::header();

		color(10);
		cout << endl;
		cout << " Load a saved game from" << endl
			<< " the /saved directory." << endl;
		cout << endl;

		// Footer 
		ui::footerText("(Enter saved file name) ");
		cout << endl;
		string filename;
		std::getline(cin, filename);

		hideCursor(true);
		int gameViewChoice = router->gameView->display(1, false, filename);
	}
	else if (router->homeView->getChoice() == 3) 
	{
		// Exit view
		int exitChoice = router->exitView->display();

		if (exitChoice == 0) exit(0); // 0 = exit
		else main(); // 1 = return to main menu
	}
}