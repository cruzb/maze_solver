#pragma once

struct node {
	int index;
	int row;
	int col;
	bool visited;
	bool passable;
	bool inSolution;
	node* parent;
};
