#pragma once
class HomeView
{
	private:
		int choice;
		void setChoice(int);

	public: 
		HomeView(); // Constructor
		~HomeView(); // Destructor
		void display();
		int& getChoice();
};

