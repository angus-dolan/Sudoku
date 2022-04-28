#pragma once

#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
#include <sstream>
#include <fstream>

#include "sudokuSolver.h"
#include "gameState.h"

using namespace std;

class SudokuGenerator
{
	private:
		int difficulty;

	public:
		SudokuGenerator(int& Difficulty); // Constructor
		~SudokuGenerator(); // Destructor

		std::vector<std::vector<int>> loadPuzzle(std::string filename);
		std::vector<std::vector<int>> loadHint(std::string filename);
		void loadGameState(struct Node** gameState, std::string filename);
		vector<int> split(string s, string delimiter);
		int loadDifficulty(std::string filename);
		std::vector<std::vector<int>> createNew();
		std::vector<std::vector<int>> createHint(std::vector<std::vector<int>>& board);
};
