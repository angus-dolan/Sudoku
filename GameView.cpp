#include "GameView.h"

GameView::GameView()
{
	
}

GameView::~GameView()
{
	
}

void GameView::display()
{
	int diff = 1;
	bool newPuzzle = true;

	SudokuGenerator* generator = new SudokuGenerator(diff);
	std::vector<std::vector<int>> complete, hint, board;

	// Complete = fully solved puzzle
	if (newPuzzle) complete = generator->createNew();
	//else complete = generator->loadPuzzle();

	// Hint = what's initially displayed to user
	// Difficultly is dictated by how many cells are filled in
	hint = generator->createHint(complete);

	// Board = what user plays with, initialized with hint state
	board = hint;

	// Display UI and look for keyboard input
	int cursor = 0; // used to track cursor position on board
	int* cursorPtr = &cursor;
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
					if (cell == cursor)
					{ 
						color(10);
						std::cout << "x";
						color(15);
					}
					else std::cout << " ";
				}

				// Hint cell
				if (board[row][col] == hint[row][col] && board[row][col] != 0) {
					if (cell == cursor)
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
					if (cursor == cell) color(10);
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
		int key = 0;
		key = _getch();

		// Up [W]
		if (key == 119 || key == 87) W(cursorPtr);
		// Left [A]
		else if (key == 97 || key == 65) A(cursorPtr);
		// Down [S]
		else if (key == 115 || key == 83) S(cursorPtr);
		// Right [D]
		else if (key == 100 || key == 68) D(cursorPtr);

		// Numbers 1-9
		if (key >= 49 && key <= 57) EnterNumber(cursorPtr);

	} while (true);
}

bool GameView::ValidWASD(int& newPosition)
{
	if (newPosition >= 0 && newPosition <= 80) return true;
	return false;
}

void GameView::W(int* cursorPtr)
{
	int cursor = *cursorPtr;
	cursor = cursor - 9;

	if (ValidWASD(cursor)) *cursorPtr = cursor;
}

void GameView::A(int* cursorPtr)
{
	int cursor = *cursorPtr;
	cursor = cursor - 1;

	if (ValidWASD(cursor)) *cursorPtr = cursor;
}

void GameView::S(int* cursorPtr)
{
	int cursor = *cursorPtr;
	cursor = cursor + 9;

	if (ValidWASD(cursor)) *cursorPtr = cursor;
}

void GameView::D(int* cursorPtr)
{
	int cursor = *cursorPtr;
	cursor = cursor + 1;

	if (ValidWASD(cursor)) *cursorPtr = cursor;
}

void GameView::EnterNumber(int* cursorPointer)
{
	
}