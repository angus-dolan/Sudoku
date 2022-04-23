#pragma once

#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>

#include "sudokuSolver.h"

class SudokuGenerator
{
	private:
		int difficulty;

	public:
		SudokuGenerator(int& Difficulty); // Constructor
		~SudokuGenerator(); // Destructor

		//std::vector<std::vector<int>> loadPuzzle();
		std::vector<std::vector<int>> createNew();
		std::vector<std::vector<int>> createHint(std::vector<std::vector<int>>& board);
};
