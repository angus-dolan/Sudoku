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

#pragma once
class GameView
{
	public:
		GameView(); // Constructor
		~GameView(); // Destructor
		void display();

		// Keyboard input
		bool ValidWASD(int& newPosition);
		void W(int*);
		void A(int*);
		void S(int*);
		void D(int*);
		bool EnterNumber(std::vector<std::vector<int>>* boardPtr, std::vector<int>& flatHint, int& cursor, int& key);
};

