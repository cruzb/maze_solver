#include "breadth.h"
#include <queue>
#include <iostream>
#include <windows.h>

node* bfs(maze* maze, node* start, node* end, bool displayRealtime) {
	std::queue<node*> q;
	q.push(start);
	node* current;
	node* next;

	while (!q.empty()) {
		if (displayRealtime) {
			maze->output(true, false);
			//wait between frames only if maze size warrants it
			//realtime display struggles with larger mazes
			if(maze->height() * maze->width() < 2000)
				Sleep(50);
		}
		
		current = q.front();
		q.pop();
		current->visited = true;
		

		if (current == end) {
			return current;
		}

		next = maze->top(current);
		if (next) {
			if (next->passable && !next->visited) { //if top should be added
				next->parent = current; //for backtrack
				q.push(next);
			}
		}

		next = maze->bottom(current);
		if (next) {
			if (next->passable && !next->visited) {
				next->parent = current;
				q.push(next);
			}
		}
		
		next = maze->right(current);
		if (next) {
			if (next->passable && !next->visited) {
				next->parent = current;
				q.push(next);
			}
		}

		next = maze->left(current);
		if (next) {
			if (next->passable && !next->visited) {
				next->parent = current;
				q.push(next);
			}
		}
	}

}

void solve_bfs(maze* maze, bool displayRealtime) {
	node* end = bfs(maze, maze->get_start(), maze->get_end(), displayRealtime);
	while (end->parent != nullptr) {
		//std::cout << "row: " << end->row << "    col: " << end->col << std::endl;
		end->inSolution = true;
		end = end->parent;
	}
	maze->get_start()->inSolution = true;
	maze->output(false, true);
}