#include <iostream>

#include "uiElements.h"


void ui::lineSmallLeft() {
	std::cout << "=============== ";
}

void ui::lineSmallRight() {
	std::cout << " ================" << std::endl;
}

void ui::seperator() {
	std::cout << "=======================================" << std::endl;
}

void ui::sudokuOuterBorder() {
	std::cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
}

void ui::sudokuOuterVerticalBorderSmall() {
	std::cout << " $ ";
}

void ui::sudokuOuterVerticalBorderNextLine() {
	std::cout << " $" << std::endl;
}

void ui::sudokuInnerVerticalBorderSmall() {
	std::cout << " | ";
}

void ui::sudokuInnerBorder() {
	std::cout << " $---*---*---$---*---*---$---*---*---$" << std::endl;
}