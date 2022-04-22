#include "GameView.h"

GameView::GameView()
{
	
}

GameView::~GameView()
{
	
}

void GameView::display()
{
	// Game board data
	std::array<int, 81> const flat_board = { 0,7,0,0,2,0,0,4,6,0,6,0,0,0,0,8,9,0,2,0,0,8,0,0,7,1,5,0,8,4,0,9,7,0,0,0,7,1,0,0,0,0,0,5,9,0,0,0,1,3,0,4,8,0,6,9,7,0,0,2,0,0,8,0,5,8,0,0,0,0,6,0,4,3,0,0,8,0,0,7,0 };	
	std::vector<std::vector<int>> board = flatBoardToVector(flat_board);
	std::vector<std::vector<int>> complete = flatBoardToVector(flat_board);
	std::vector<std::vector<int>> hint = flatBoardToVector(flat_board);
	
	// Store solved puzzle in complete
	solveBackTrack(complete);

	int boardPosition = 0; // used with keyboard controls
	do {
		system("cls");

		// Header
		ui::header();
		std::cout << std::endl;

		// Print game board
		ui::sudokuOuterBorder();
		std::cout << std::endl;
		int cell = 0;
		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) {  
				// Outer border-left
				if (col == 0) ui::sudokuOuterVerticalBorderSmall();

				// Empty cell
				if (board[row][col] == 0) {
					// Display x when empty cell is highlighted
					if (cell == boardPosition) 
					{ 
						color(10);
						std::cout << "x";
						color(15);
					}
					else std::cout << " ";
				}

				// Hint cell
				if (board[row][col] == hint[row][col] && board[row][col] != 0) {
					if (cell == boardPosition) 
					{
						color(12); // yellow
						std::cout << board[row][col];
						color(15);
					}
					else
					{
						color(6); // yellow
						std::cout << board[row][col];
						color(15);
					}
				}

				// User filled cell
				if (board[row][col] != hint[row][col]) 
				{
					if (boardPosition == cell) color(10);
					std::cout << board[row][col];
					color(15);
				}

				// Cell border-right
				if (col == 2 || col == 5) ui::sudokuOuterVerticalBorderSmall();
				if (col != 2 && col != 5 && col != 8) ui::sudokuInnerVerticalBorderSmall();

				// Outer border-right
				if (col == 8) ui::sudokuOuterVerticalBorderNextLine();

				cell++;
			}

			//
			if (row != 2 && row != 5 && row != 8) ui::sudokuInnerBorder();

			// Outer border-bottom
			if (row == 2 || row == 5 || row == 8)
			{
				std::cout << std::endl;
				ui::sudokuOuterBorder();
				std::cout << std::endl;
			}
		}

		// Keyboard controls
		int key;
		key = 0;
		key = _getch();

		// Up [W]
		if (key == 119 || key == 87) boardPosition = boardPosition - 9;
		// Left [A]
		else if (key == 97 || key == 65) boardPosition = boardPosition - 1;
		// Down [S]
		else if (key == 115 || key == 83) boardPosition = boardPosition + 9;
		// Right [D]
		else if (key == 100 || key == 68) boardPosition = boardPosition + 1;

	} while (true);
}