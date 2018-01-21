#pragma once
#include "graph.h"
#include "maze.h"

node* dijkstra(graph* graph, maze* maze, bool displayRealtime);
void solve_dijkstra(graph* graph, maze* maze, bool displayRealtime);