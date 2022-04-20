#pragma once

class ui {
	public:
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