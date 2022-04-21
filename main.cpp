#include <string>
#include <iostream>
#include <vector>
#include <array>

#include "ViewRouter.h"
#include "hideCursor.h"
#include "sudokuSolver.h"

using namespace std;

int main()
{
    std::array<int, 81> const flat_board = { 5, 3, 0, 0, 7, 0, 0, 0, 0, 6, 0, 0, 1, 9, 5, 0, 0, 0, 0, 9, 8, 0, 0, 0, 0, 6, 0, 8, 0, 0, 0, 6, 0, 0, 0, 3, 4, 0, 0, 8, 0, 3, 0, 0, 1, 7, 0, 0, 0, 2, 0, 0, 0, 6, 0, 6, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 4, 1, 9, 0, 0, 5, 0, 0, 0, 0, 8, 0, 0, 7, 9 };
    std::array<int, 81> const flat_expected = { 5, 3, 4, 6, 7, 8, 9, 1, 2, 6, 7, 2, 1, 9, 5, 3, 4, 8, 1, 9, 8, 3, 4, 2, 5, 6, 7, 8, 5, 9, 7, 6, 1, 4, 2, 3, 4, 2, 6, 8, 5, 3, 7, 9, 1, 7, 1, 3, 9, 2, 4, 8, 5, 6, 9, 6, 1, 5, 3, 7, 2, 8, 4, 2, 8, 7, 4, 1, 9, 6, 3, 5, 3, 4, 5, 2, 8, 6, 1, 7, 9 };
    std::vector<std::vector<int>> board = flatBoardToVector(flat_board);
    std::vector<std::vector<int>> const expected = flatBoardToVector(flat_expected);

    std::cout << "initial\n";
    printBoard(board);
    std::cout << "actual\n";

    if (solveBackTrack(board) == true)
        printBoard(board);
    else
        cout << "No solution exists";

    std::cout << "expected\n";
    printBoard(expected);

    //std::cout << "initial\n";
    //printBoard(board);

    //std::cout << "expected\n";
    //printBoard(expected);

	//ViewRouter* router = new ViewRouter(); // Holds all the games views
	//hideCursor(true); // Hide cursor in console

	//// Main Menu
	//// 1 = Start Game, 2 = Read Instructions, 3 = Exit Game 
	//router->homeView->display();
	//if (router->homeView->getChoice() == 3) 
	//{
	//	int exitChoice = router->exitView->display();

	//	if (exitChoice == 0) exit(0); // 0 = exit
	//	else main(); // 1 = return to main menu
	//}
}