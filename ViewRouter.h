#pragma once

#include "HomeView.h"

class ViewRouter
{
	public:
		ViewRouter(); // Constructor
		~ViewRouter(); // Destructor

		HomeView* homeView;
		ExitView* exitView;
};

