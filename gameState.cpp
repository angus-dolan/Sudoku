#include <iostream>

#include "gameState.h"

using namespace std;

// Update game state
void insert(struct Node** head, int move, std::vector<std::vector<int>>& newData)
{
	struct Node* newNode = new Node;
	newNode->data = newData;
	newNode->move = move;
	newNode->next = NULL;

	// Check if list is empty, if yes make new node the head of list
	if (*head == NULL) {
		newNode->prev = NULL;
		*head = newNode;
		return;
	}
	else {
		struct Node* current = *head;
		if (current->move == move) {
			// Replace head
			newNode->prev = NULL;
			*head = newNode;
			return;
		}

		struct Node* target = *head;
		bool found = false;
		while (current->next != NULL) {
			if (current->move == move) {
				target = current;
				found = true;
			}
			current = current->next;
		}

		if (current->next == NULL && current->move == move) {
			// Replace tail
			struct Node* previous = current->prev;
			newNode->prev = previous;
			previous->next = newNode;
			return;
		}

		if (!found) {
			// Insert at end
			current->next = newNode;
			newNode->prev = current;
		}
		else {
			if (target->prev == NULL) {
				// Insert at start
				newNode->prev = NULL;
				*head = newNode;
				return;
			}
			else {
				// Replace existing move 
				struct Node* previous = target->prev;
				newNode->prev = previous;
				previous->next = newNode;
			}
		}
	}
}

std::vector<std::vector<int>> currentBoard(struct Node** head, int move) {
	struct Node* current = *head;
	while (current->move >= move || current->next != NULL) {
		if (current->move == move) return current->data;
		current = current->next;
	}
}

// Get number of moves stored in game state
int sumMoves(struct Node** head) {
	struct Node* current = *head;
	int sum = 0;

	if (*head == NULL) return sum;

	while (current->next != NULL) {
		sum++;
		current = current->next;
	}

	return sum + 1;
}

// Prints contents of game state starting from the given node
void displayList(struct Node* node) {
	struct Node* last;

	while (node != NULL) {

		cout << node << " : ";
		cout << node->prev << " [";
		cout << node->move << "] ";
		cout << node->next << " ";

		cout << "<==>" << endl;
		last = node;
		node = node->next;
	}
	if (node == NULL)
		cout << "NULL";
}
