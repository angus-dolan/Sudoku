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
	color(15); // white
}
void ui::headerText(std::string label) {
	color(5); // purple
	ui::lineSmallLeft();
	color(15); // white
	std::cout << label;
	color(5); // purple
	ui::lineSmallRight();
	color(15); // white
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
	color(5); // purple
	std::cout << " |||||||||||||||||||||||||||||||||||||" << std::endl;
	color(15); // white
}

void ui::sudokuOuterVerticalBorderSmall() {
	color(5); // purple
	std::cout << " | ";
	color(15); // white
}

void ui::sudokuOuterVerticalBorderNextLine() {
	color(5); // purple
	std::cout << " |" << std::endl;
	color(15); // white
}

void ui::sudokuInnerVerticalBorderSmall() {
	color(5); // purple
	std::cout << " | ";
	color(15); // white
}

void ui::sudokuInnerBorder() {
	color(5); // purple
	std::cout << " |-----------|---*---*---|---*---*---|" << std::endl;
	color(15); // white
}