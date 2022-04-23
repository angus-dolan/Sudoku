#include "sudokuSolver.h"

bool checkBoard(std::vector<std::vector<int>>& board)
{
    // Rows
    for (int row = 0; row < N; row++) {
        if (std::accumulate(board[row].begin(), board[row].end(), 0) != 45) return false;
    }

    // Columns
    for (int col = 0; col < N; col++) {
        int sum = 0;
        for (int row = 0; row < N; row++) {
            sum = sum + board[row][col];
        }

        if (sum != 45) return false;
    }

    // Boxes
    int gridStartCol = 0;
    for (int row = 0; row < 3; row++) {
        int boxStartCol = 0;
        int boxEndCol = 3;
        for (int gridCol = 0; gridCol < 3; gridCol++) {
            int sumBoxRow1 = std::accumulate(board[gridStartCol].begin() + boxStartCol, board[gridStartCol].begin() + boxEndCol, 0);
            int sumBoxRow2 = std::accumulate(board[gridStartCol + 1].begin() + boxStartCol, board[gridStartCol + 1].begin() + boxEndCol, 0);
            int sumBoxRow3 = std::accumulate(board[gridStartCol + 2].begin() + boxStartCol, board[gridStartCol + 2].begin() + boxEndCol, 0);
            
            if (sumBoxRow1 + sumBoxRow2 + sumBoxRow3 != 45) return false;

            boxStartCol = boxStartCol + 3;
            boxEndCol = boxEndCol + 3;
        }
        gridStartCol = gridStartCol + 3;
    }

    return true;
}

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

