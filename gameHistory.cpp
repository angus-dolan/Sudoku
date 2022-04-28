#include "gameHistory.h"

GameHistory::GameHistory()
{

}

GameHistory::~GameHistory()
{
}

void GameHistory::createNew(string filename, int difficulty, std::vector<std::vector<int>>& complete, std::vector<std::vector<int>>& hint, struct Node** gameState)
{
    ofstream output("saved/" + filename + ".txt");

    // Save difficulty 
    output << difficulty << endl;
    output << "-" << endl;
    
    // Save complete
    int i = 0;
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            output << complete[row][col];
            if (i != 80) output << ",";
            i++;
        }
    }
    output << endl;
    output << "-" << endl;

    // Save hint
    i = 0;
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            output << hint[row][col];
            if (i != 80) output << ",";
            i++;
        }
    }
    output << endl;
    output << "-" << endl;

    // Save game state
    struct Node* current = *gameState;
    while (current != NULL) {
        // Move
        output << current->move;
        output << endl;
        // Data
        i = 0;
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                output << current->data[row][col];
                if (i != 80) output << ",";
                i++;
            }
        }
        output << endl;
        output << "*" << endl;

        current = current->next;
    }
    output << "-" << endl;
    
    output.close();
}