#include <iostream>
#include <vector>
#include <array>

#include "sudokuSolver.h"

bool solveBackTrack(std::vector<std::vector<int>>& board)
{
    int row, col;

    // Get first empty column
    // Sets row, col with first empty location by reference
    if (!findFirstEmpty(board, row, col)) return true;

    // Try candidates 1-9
    for (int num = 1; num <= 9; ++num)
    {
        // Check if candidate is valid
        if (checkCandidate(board, row, col, num))
        {

            // Assign candidate to first empty column
            board[row][col] = num;

            // Continue down path
            if (solveBackTrack(board))
                return true;

            // Revert back to unassigned if unsuccessful
            board[row][col] = UNASSIGNED;
        }
    }

    // Recursively trigger back tracking
    return false;
}

std::vector<std::vector<int>> flatBoardToVector(std::array<int, 81> const flat_board)
{
    std::vector<std::vector<int>> board;
    board.reserve(9);
    for (std::size_t row = 0; row < 9; ++row)
    {
        std::vector<int> this_row;
        this_row.reserve(9);
        for (std::size_t col = 0; col < 9; ++col)
        {
            this_row.push_back(flat_board[row * 9 + col]);
        }
        board.push_back(this_row);
    }
    return board;
}

bool findFirstEmpty(std::vector<std::vector<int>> board, int& row, int& col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (board[row][col] == UNASSIGNED)
                return true;

    // No empty columns found, 
    // board is complete
    return false;
}

bool checkCandidate(std::vector<std::vector<int>>& board, int row, int col, int num)
{
    // Returns false if candidate is present in row, column or box
    return !rowContainsCandidate(board, row, num)
        && !colContainsCandidate(board, col, num)
        && !boxContainsCandidate(board, row - row % 3,
            col - col % 3, num)
        && board[row][col] == UNASSIGNED;
}

bool rowContainsCandidate(std::vector<std::vector<int>>& board, int row, int num)
{
    for (int col = 0; col < N; col++)
        if (board[row][col] == num)
            return true;
    return false;
}

bool colContainsCandidate(std::vector<std::vector<int>>& board, int col, int num)
{
    for (int row = 0; row < N; row++)
        if (board[row][col] == num)
            return true;
    return false;
}

bool boxContainsCandidate(std::vector<std::vector<int>>& board, int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (board[row + boxStartRow]
                [col + boxStartCol] ==
                num)
                return true;
    return false;
}

void printBoard(std::vector<std::vector<int>> board)
{
    for (std::size_t row = 0; row < 9; ++row)
    {
        for (std::size_t col = 0; col < 9; ++col)
        {
            std::cout << board[row][col] << ", ";
        }
        std::cout << "\n";
    }
}

