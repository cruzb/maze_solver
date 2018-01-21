#pragma once
#include "node.h"
#include "maze.h"

node* bfs(maze* maze, node* start, node* end, bool displayRealtime);
void solve_bfs(maze* maze, bool displayRealtime);