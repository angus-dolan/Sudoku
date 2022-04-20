#include <iostream>

#include "uiElements.h"
#include "color.h"

// Compound Elements
void ui::header() {
	color(5); // purple
	ui::lineSmallLeft();
	color(15); // white
	std::cout << "SUDOKU";
	color(5); // purple
	ui::lineSmallRight();
}

void ui::footerText(std::string label) {
	color(5); // purple
	ui::seperator();
	color(7); // dark white
	std::cout << label;
	color(15); // white
}

// Atomic Elements
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