#include "ViewRouter.h"

// Views
#include "HomeView.h"
#include "ExitView.h"
#include "InstructionsView.h"

ViewRouter::ViewRouter()
{
	homeView = new HomeView();
	exitView = new ExitView();
	instructionsView = new InstructionsView();
}

ViewRouter::~ViewRouter()
{
	delete& 
		homeView, 
		exitView,
		instructionsView
	;
}