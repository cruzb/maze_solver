#include "graph.h"
#include "maze.h"
#include <iostream>
#include <queue>

graph::graph(maze* maze) {
	num_nodes = 0;
	num_edges = 0;

	adjList.resize(maze->height() * maze->width());

	for (int i = 0; i < adjList.size(); i++) {
		node* n = maze->at(i);
		if (n->passable) {
			num_nodes++;
			if (maze->top(n) && maze->top(n)->passable) {
				adjList[i].push_back(i - maze->width());
				num_edges++;
			}
			if (maze->bottom(n) && maze->bottom(n)->passable) {
				adjList[i].push_back(i + maze->width());
				num_edges++;
			}
			if (maze->left(n) && maze->left(n)->passable) {
				adjList[i].push_back(i - 1);
				num_edges++;
			}
			if (maze->right(n) && maze->right(n)->passable) {
				adjList[i].push_back(i + 1);
				num_edges++;
			}
		}
	}

}

int graph::size() {
	return adjList.size();
}

std::vector<int>* graph::at(int r) {
	return &adjList[r];
}

int graph::at(int r, int c) {
	return adjList[r][c];
}

int graph::node_count() {
	return num_nodes;
}

int graph::edge_count() {
	return num_edges;
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