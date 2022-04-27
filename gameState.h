#pragma once

#include <vector>

struct Node {
	int move;
	std::vector<std::vector<int>> data;
	struct Node* next;
	struct Node* prev;
};

void insert(struct Node** head, int move, std::vector<std::vector<int>>& newData);
std::vector<std::vector<int>> currentBoard(struct Node** head, int move);
int sumMoves(struct Node** head);
void displayList(struct Node* node);