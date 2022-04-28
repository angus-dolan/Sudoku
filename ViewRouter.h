#pragma once

// Views
#include "HomeView.h"
#include "ExitView.h"
#include "GameView.h"

class ViewRouter
{
	public:
		ViewRouter(); // Constructor
		~ViewRouter(); // Destructor

		HomeView* homeView;
		ExitView* exitView;
		GameView* gameView;
};

