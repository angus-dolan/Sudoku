#include "ViewRouter.h"

// Views
#include "HomeView.h"
#include "ExitView.h"
#include "LoadGameView.h"
#include "GameView.h"

ViewRouter::ViewRouter()
{
	homeView = new HomeView();
	exitView = new ExitView();
	loadGameView = new LoadGameView();
	gameView = new GameView();
}

ViewRouter::~ViewRouter()
{
	delete& 
		homeView, 
		exitView,
		loadGameView,
		gameView
	;
}