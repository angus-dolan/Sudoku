#include "ViewRouter.h"

ViewRouter::ViewRouter()
{
	homeView = new HomeView();
	exitView = new ExitView();
	gameView = new GameView();
}

ViewRouter::~ViewRouter()
{
	delete& 
		homeView, 
		exitView,
		gameView
	;
}