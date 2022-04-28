#pragma once

#include <vector>
#include <iostream>
#include <array>
#include <numeric>

// UNASSIGNED defines the marker for an empty cell in sudoku grid
#define UNASSIGNED 0

// N defines the grid size, e.g. NxN
#define N 9

// Checks complete board, returns true||false 
bool checkBoard(std::vector<std::vector<int>>& board);

// Entry point for back tracking algorithm
// Uses generative recursion to fill in board
bool solveBackTrack(std::vector<std::vector<int>>& board);

// Helper function to convert flat array to vector to be used in algorithm
std::vector<std::vector<int>> flatBoardToVector(std::vector<int> flat_board);
// Helper function to convert vector board to flat array
std::vector<int> vectorToFlatBoard(std::vector<std::vector<int>> const vectorBoard);

// Finds the first empty column in board, 0 in a column denotes an empty column
bool findFirstEmpty(std::vector<std::vector<int>> board, int& row, int& col);

// Checks to see if candidate (num) is present in row, column or board box
bool checkCandidate(std::vector<std::vector<int>>& board, int row, int col, int num);

// Used by checkCandidate() to assess rows
bool rowContainsCandidate(std::vector<std::vector<int>>& board, int row, int num);

// Used by checkCandidate() to assess columns
bool colContainsCandidate(std::vector<std::vector<int>>& board, int col, int num);

// Used by checkCandidate() to assess board boxes
bool boxContainsCandidate(std::vector<std::vector<int>>& board, int boxStartRow, int boxStartCol, int num);

// Prints board to console
void printBoard(std::vector<std::vector<int>> board);
