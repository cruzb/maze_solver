#include "graph.h"
#include <iostream>

graph::graph(maze* maze) {
	adjList.resize(maze->height() * maze->width());

	for (int i = 0; i < adjList.size(); i++) {
		node* n = maze->at(i);
		if (n->passable) {
			if (maze->top(n) && maze->top(n)->passable)
				adjList[i].push_back(i - maze->width());
			if (maze->bottom(n) && maze->bottom(n)->passable)
				adjList[i].push_back(i + maze->width());
			if (maze->left(n) && maze->left(n)->passable)
				adjList[i].push_back(i - 1);
			if (maze->right(n) && maze->right(n)->passable)
				adjList[i].push_back(i + 1);
		}
	}

}

int graph::size() {
	return adjList.size();
}

bool graph::at(int r, int c) {
	return adjList[r][c];
}

bool graph::areNeighbors(maze* maze, int r1, int c1, int r2, int c2) {
	return areNeighbors(maze, maze->at(r1, c1), maze->at(r2, c2));
}

bool graph::areNeighbors(maze* maze, node* n1, node* n2) {
	if (!n1->passable || !n2->passable) //if either is a wall, no adjacency
		return false;
	else if (n1 == n2)
		return false;
	else return maze->top(n1) == n2 || maze->bottom(n1) == n2 ||
		maze->left(n1) == n2 || maze->right(n1) == n2;
}

void graph::print() {
	for (int r = 0; r < adjList.size(); r++) {
		std::cout << r << ": ";
		for (int c = 0; c < adjList[r].size(); c++)
			std::cout << adjList[r][c] << " ";
		std::cout << std::endl;
	}
}