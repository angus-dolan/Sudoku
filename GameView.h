#include <iostream>
#include <vector>
#include <array>
#include <conio.h>

#include "uiElements.h"
#include "sudokuSolver.h"
#include "color.h"

#pragma once
class GameView
{
	public:
		GameView(); // Constructor
		~GameView(); // Destructor
		void display();
};

