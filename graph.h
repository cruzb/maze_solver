#pragma once
#include "maze.h"
#include <vector>

class graph {
public:
	graph(maze* maze);
	int size();
	bool at(int r, int c);
	void print();
private:
	std::vector<std::vector<int> > adjList;

	bool areNeighbors(maze* maze, int r1, int c1, int r2, int c2);
	bool areNeighbors(maze* maze, node* n1, node* n2);
};