#include <string>
#include <iostream>

#include "ViewRouter.h"
#include "hideCursor.h"

using namespace std;

int main()
{
    ViewRouter* router = new ViewRouter(); // Holds all the games views
    hideCursor(true); // Hide cursor in console

    //std::array<int, 81> const flat_board = {0,7,0,0,2,0,0,4,6,0,6,0,0,0,0,8,9,0,2,0,0,8,0,0,7,1,5,0,8,4,0,9,7,0,0,0,7,1,0,0,0,0,0,5,9,0,0,0,1,3,0,4,8,0,6,9,7,0,0,2,0,0,8,0,5,8,0,0,0,0,6,0,4,3,0,0,8,0,0,7,0};
    //std::array<int, 81> const flat_board = { 5, 3, 0, 0, 7, 0, 0, 0, 0, 6, 0, 0, 1, 9, 5, 0, 0, 0, 0, 9, 8, 0, 0, 0, 0, 6, 0, 8, 0, 0, 0, 6, 0, 0, 0, 3, 4, 0, 0, 8, 0, 3, 0, 0, 1, 7, 0, 0, 0, 2, 0, 0, 0, 6, 0, 6, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 4, 1, 9, 0, 0, 5, 0, 0, 0, 0, 8, 0, 0, 7, 9 };
    //std::vector<std::vector<int>> board = flatBoardToVector(flat_board);

    router->gameView->display();

    //std::cout << "initial\n";
    //printBoard(board);
    //std::cout << "actual\n";

    //if (solveBackTrack(board) == true)
    //    printBoard(board);
    //else
    //    cout << "No solution exists";


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