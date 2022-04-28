#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "sudokuSolver.h"
#include "gameState.h"

using namespace std;

class GameHistory
{
	public:
		GameHistory(); // Constructor
		~GameHistory(); // Destructor
		void createNew(string filename, int difficulty, std::vector<std::vector<int>>& complete, std::vector<std::vector<int>>& hint, struct Node** gameState);
};