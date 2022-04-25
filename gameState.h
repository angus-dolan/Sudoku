#pragma once

struct Node {
	int move;
	int data;
	struct Node* next;
	struct Node* prev;
};

void insert(struct Node** head, int move);
void displayList(struct Node* node);