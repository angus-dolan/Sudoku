#include <string>
#include <iostream>

#include "HomeView.h"

using namespace std;

int main()
{
	// Declare Views
	HomeView* homeView = new HomeView();

	//
	homeView->display();

	system("cls");
	/*int& choice = homeView->getChoice();*/
	std::cout << homeView->getChoice() << std::endl;
}