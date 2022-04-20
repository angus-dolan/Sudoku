#pragma once

#include <string>

class ui {
	public:
		// Compound Elements 
		static void header();
		static void footerText(std::string label);

		// Atomic Elements
		static void lineSmallLeft();
		static void lineSmallRight();
		static void seperator();
		static void sudokuOuterBorder();
		static void sudokuOuterVerticalBorderSmall();
		static void sudokuOuterVerticalBorderNextLine();
		static void sudokuInnerVerticalBorderSmall();
		static void sudokuInnerBorder();

	private:
		ui() {} // Disallow creation of ui object
};