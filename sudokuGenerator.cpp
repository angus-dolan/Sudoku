#include "sudokuGenerator.h"

#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>

SudokuGenerator::SudokuGenerator(int& Difficulty)
{
	difficulty = Difficulty;
}

SudokuGenerator::~SudokuGenerator()
{
	delete&
		difficulty
	;
}

//std::vector<std::vector<int>> SudokuGenerator::loadPuzzle()
//{
//	// Get from data store
//	// Convert to flat array
//	// Convert to vector
//}

std::vector<std::vector<int>> SudokuGenerator::createNew()
{
	// Start with default board
	std::array<int, 81> const defaultFlatBoard = {1,2,3,4,5,6,7,8,9,4,5,6,7,8,9,1,2,3,7,8,9,1,2,3,4,5,6,2,3,4,5,6,7,8,9,1,5,6,7,8,9,1,2,3,4,8,9,1,2,3,4,5,6,7,3,4,5,6,7,8,9,1,2,6,7,8,9,1,2,3,4,5,9,1,2,3,4,5,6,7,8};
	std::vector<std::vector<int>> defaultBoard = flatBoardToVector(defaultFlatBoard);

	// Shuffle groups
	std::srand(std::time(nullptr));
	int fromGroup = std::rand() % 3 + 1;
	int toGroup = std::rand() % 3 + 1;
	if (fromGroup != toGroup) {
		using  Triple = std::array<int, 3>;
		Triple row1 = { 0,1,2 };
		Triple row2 = { 3,4,5 };
		Triple row3 = { 6,7,8 };
		std::map<int, Triple> rows;
		rows.insert(std::make_pair(1, row1));
		rows.insert(std::make_pair(2, row2));
		rows.insert(std::make_pair(3, row3));

		std::iter_swap(defaultBoard.begin() + rows[fromGroup][0], defaultBoard.begin() + rows[toGroup][0]);
		std::iter_swap(defaultBoard.begin() + rows[fromGroup][1], defaultBoard.begin() + rows[toGroup][1]);
		std::iter_swap(defaultBoard.begin() + rows[fromGroup][2], defaultBoard.begin() + rows[toGroup][2]);
	}
	// Shuffle column group 1
	int shuffleCol = std::rand() % 2;
	if (shuffleCol > 0) {
		for (int row = 0; row < 9; row++) {
			std::swap(defaultBoard[row][0], defaultBoard[row][2]);
		}
	}
	// Shuffle column group 2
	int shuffleCol2 = std::rand() % 2;
	if (shuffleCol2 > 0) {
		for (int row = 0; row < 9; row++) {
			std::swap(defaultBoard[row][3], defaultBoard[row][5]);
		}
	}	
	// Shuffle column group 3
	int shuffleCol3 = std::rand() % 2;
	if (shuffleCol3 > 0) {
		for (int row = 0; row < 9; row++) {
			std::swap(defaultBoard[row][6], defaultBoard[row][8]);
		}
	}
	// Shuffle row group 1
	int shuffleRow = std::rand() % 2;
	if (shuffleRow > 0) {
		std::iter_swap(defaultBoard.begin() + 0, defaultBoard.begin() + 2);
	}
	// Shuffle row group 2
	int shuffleRow2 = std::rand() % 2;
	if (shuffleRow2 > 0) {
		std::iter_swap(defaultBoard.begin() + 3, defaultBoard.begin() + 5);
	}
	// Shuffle row group 3
	int shuffleRow3 = std::rand() % 2;
	if (shuffleRow3 > 0) {
		std::iter_swap(defaultBoard.begin() + 6, defaultBoard.begin() + 8);
	}	

	if (!checkBoard(defaultBoard)) std::cout << "No solution exists";

	return defaultBoard;
}

std::vector<std::vector<int>> SudokuGenerator::createHint(std::vector<std::vector<int>>& board)
{
	std::vector<std::vector<int>> hiddenBoard = board;

	// Define number of hidden cells in board
	int numHidden;
	if (difficulty == 1) numHidden = 45; // easy
	else if (difficulty == 2) numHidden = 50; // medium
	else if (difficulty == 3) numHidden = 55; // hard

	// Generate cells to hide
	std::vector<int> unknowns;
	for (int i = 0; i < numHidden; i++) {
		bool unique = false;

		int unknown;
		while (unique == false) {
			unknown = std::rand() % 81;
			if (!(std::find(std::begin(unknowns), std::end(unknowns), unknown) != std::end(unknowns)))
				unique = true;
		}
		unknowns.push_back(unknown);
	}

	// Hide cells
	int i = 0;
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (std::find(std::begin(unknowns), std::end(unknowns), i) != std::end(unknowns)) {
				hiddenBoard[row][col] = 0;
			}
			i++;
		}
	}

	return hiddenBoard;
}
