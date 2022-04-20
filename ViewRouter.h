#pragma once

// Views
#include "HomeView.h"
#include "ExitView.h"
#include "InstructionsView.h"

class ViewRouter
{
	public:
		ViewRouter(); // Constructor
		~ViewRouter(); // Destructor

		HomeView* homeView;
		ExitView* exitView;
		InstructionsView* instructionsView;
};

