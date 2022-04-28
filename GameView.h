#include <iostream>
#include <vector>
#include <array>
#include <conio.h>
#include <iomanip>

#include "uiElements.h"
#include "sudokuGenerator.h"
#include "sudokuSolver.h"
#include "color.h"
#include "gameState.h"
#include "gameHistory.h"
#include "hideCursor.h"

#pragma once
class GameView
{
	public:
		GameView(); // Constructor
		~GameView(); // Destructor
		int display(int difficulty, bool newPuzzle, string filename);

		bool checkGame(std::vector<std::vector<int>>& complete);
		// Keyboard input
		bool ValidWASD(int& newPosition);
		void W(int*);
		void A(int*);
		void S(int*);
		void D(int*);
		bool EnterNumber(std::vector<std::vector<int>>* boardPtr, std::vector<int>& flatHint, int& cursor, int& key);
};

