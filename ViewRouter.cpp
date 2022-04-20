#include "ViewRouter.h"

// Views
#include "HomeView.h"
#include "ExitView.h"

ViewRouter::ViewRouter()
{
	homeView = new HomeView();
	exitView = new ExitView();
}

ViewRouter::~ViewRouter()
{
	delete& 
		homeView, 
		exitView
	;
}