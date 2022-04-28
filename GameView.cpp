#include "GameView.h"

GameView::GameView()
{
	
}

GameView::~GameView()
{
	
}

int GameView::display(int difficulty, bool newPuzzle, string filename  )
{
	// IO for saving game history
	GameHistory* gameHistory = new GameHistory();

	SudokuGenerator* generator = new SudokuGenerator(difficulty);
	std::vector<std::vector<int>> complete, hint, board;

	// Complete = fully solved puzzle
	if (newPuzzle) complete = generator->createNew();
	else complete = generator->loadPuzzle("new");

	// Difficulty
	if(!newPuzzle) difficulty = generator->loadDifficulty("new");

	// Hint = what's initially displayed to user
	// Difficultly is dictated by how many cells are filled in
	if (newPuzzle) hint = generator->createHint(complete);
	else hint = generator->loadHint("new");
	std::vector<int> flatHint = vectorToFlatBoard(hint);

	// Board = what user plays with, initialized with hint state
	board = hint;
	std::vector<std::vector<int>>* boardPtr = &board;

	// Game state
	struct Node* gameState = NULL;
	if (!newPuzzle) generator->loadGameState(&gameState, "new");

	int move = 1;

	// FOR DEMO!!
	ofstream output("saved/SOLUTION.txt");
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			output << complete[row][col];
		}
		output << endl;
	}
	output.close();

	// Display UI and look for keyboard input
	int cursor = 0; // used to track cursor position on board
	int* cursorPtr = &cursor;
	do {
		int numMovesStored = sumMoves(&gameState);
		system("cls");

		// Get current board from game state
		if (move == 1) {
			board = hint;
		}
		else {
			board = currentBoard(&gameState, move-1);
		}

		// Difficulty banner
		switch (difficulty) {
		case 1:
			ui::headerText(" EASY ");
			break;
		case 2:
			ui::headerText("MEDIUM");
			break;
		default:
			ui::headerText(" HARD ");
		}	
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

		// Correct count (easy)
		if (difficulty == 1) {
			int correctCount = 0;
			for (int row = 0; row < 9; ++row)
			{
				for (int col = 0; col < 9; ++col)
				{
					if (hint[row][col] == 0) {
						if (board[row][col] == complete[row][col]) correctCount++;
					}
				}
			}
			color(10);
			std::cout << " Correct: ";
			color(15);
			std::cout << correctCount;
			std::cout << "/81";
		}
		else {
			std::cout << "               ";
		}

		// Move count
		color(11);
		std::cout << "                ";
		std::cout << "Move: ";
		color(15);
		std::cout << move << std::endl;
		std::cout << std::endl;

		color(8);
		std::cout << " Controls:" << std::endl;
		std::cout << std::endl;
		color(15);

		// WASD
		color(12);
		std::cout << " [WASD]";
		color(15);
		std::cout << " keys to move cursor" << std::endl;

		// Arrow Keys
		color(12);
		std::cout << " [arrow-left]";
		color(15);
		std::cout << " to UNDO a move" << std::endl;		
		color(12);
		std::cout << " [arrow-right]";
		color(15);
		std::cout << " to REDO a move" << std::endl;

		// ESC
		color(12);
		std::cout << " [ESC]";
		color(15);
		std::cout << " to QUIT game" << std::endl;
		color(15);

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
		if (key >= 49 && key <= 57) {
			bool result = EnterNumber(boardPtr, flatHint, cursor, key);
			if (result) { 
				insert(&gameState, move, board);				
				move++;
			}
		}

		// Arrow keys
		if (key == 224) {
			key = 256 + _getch();
			// Undo [arrow-left]
			if (key == 331 && move > 1) {
				move--;
			}
			// Redo [arrow-right]
			if (key == 333 && move <= numMovesStored) {
				move++;
			}
		}

		// Escape key
		if (key == 27 || key == 112) {
			return 0;
		}

		// Check game
		bool gameFinished = checkGame(board);
		if (move == 81) gameFinished = true;
		if (gameFinished) {
			bool result = checkBoard(board);
			system("cls");
			hideCursor(false);

			ui::header();
			if (!result) {
				color(12);
				cout << endl;
				cout << " Sorry, you did not complete" << endl
					<< " the sudoku puzzle." << endl;
				color(14);
				cout << endl;
				cout << " Save the game and replay!" << endl;
				cout << endl;
				color(15);
			}
			else if (result) {
				color(10);
				cout << endl;
				cout << " Congratulations! you completed" << endl
					<< " the sudoku puzzle." << endl;
				color(14);
				cout << endl;
				cout << " Save the game and replay!" << endl;
				cout << endl;
				color(15);
			}

			ui::footerText("Enter a save file name:");
			cout << endl;

			string filename;
			std::getline(cin, filename);

			gameHistory->createNew(filename, difficulty, complete, hint, &gameState);

			hideCursor(true);
			return 0;
		}

	} while (true);
}

bool GameView::checkGame(std::vector<std::vector<int>>& complete)
{
	int filled = 0;

	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (complete[row][col] != 0) filled++;
		}
	}

	if (filled == 81) return true;
	else return false;
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

bool GameView::EnterNumber(std::vector<std::vector<int>>* boardPtr, std::vector<int>& flatHint, int& cursor, int& key)
{
	bool flag = false;

	// Check cell is NOT a hint
	if (flatHint[cursor] == 0)
	{
		// Determine number entered
		int num = 0;
		if (key == 49) num = 1; // [1]
		else if (key == 50) num = 2; // [2]
		else if (key == 51) num = 3; // [3] 
		else if (key == 52) num = 4; // [4]
		else if (key == 53) num = 5; // [5]
		else if (key == 54) num = 6; // [6]
		else if (key == 55) num = 7; // [7]
		else if (key == 56) num = 8; // [8]
		else if (key == 57) num = 9; // [9]

		// Place number into cell
		int i = 0;
		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) {
				if (i == cursor && (*boardPtr).at(row).at(col) == 0) {
					(*boardPtr).at(row).at(col) = num;
					flag = true;
				}
				i++;
			}
		}
	}

	return flag;
}