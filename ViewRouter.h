#pragma once

#include "HomeView.h"
#include "ExitView.h"

class ViewRouter
{
	public:
		ViewRouter(); // Constructor
		~ViewRouter(); // Destructor

		HomeView* homeView;
		ExitView* exitView;
};

