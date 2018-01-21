#pragma once
#include "maze.h"
#include <vector>

class graph {
public:
	graph(maze* maze);
	int size();
	std::vector<int>* at(int r);
	int at(int r, int c);
	int node_count();
	int edge_count();
	void print();
private:
	int num_nodes;
	int num_edges;
	std::vector<std::vector<int> > adjList;

	bool areNeighbors(maze* maze, int r1, int c1, int r2, int c2);
	bool areNeighbors(maze* maze, node* n1, node* n2);
};