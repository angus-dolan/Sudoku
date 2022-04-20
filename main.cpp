#include <string>
#include <iostream>

#include "ViewRouter.h"
#include "HomeView.h"

using namespace std;

int main()
{
	ViewRouter* router = new ViewRouter();

	// Main Menu
	// 1 = Start Game, 2 = Read Instructions, 3 = Exit Game 
	router->homeView->display();
	if (router->homeView->getChoice() == 1) {}
}