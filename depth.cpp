#include "depth.h"
#include <stack>
#include <iostream>
#include <windows.h>

node* dfs(maze* maze, bool displayRealtime) {
	node* start = maze->get_start();
	node* end = maze->get_end();
	std::stack<node*> q;
	q.push(start);

	node* current;
	node* next;

	while (!q.empty()) {
		current = q.top();
		q.pop();
		current->visited = true;

		if (displayRealtime) {
			maze->output(current);
			//wait between frames only if maze size warrants it
			//realtime display struggles with larger mazes
			if (maze->height() * maze->width() < 10000)
				Sleep(50);
		}


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

void solve_dfs(maze* maze, bool displayRealtime) {
	node* end = dfs(maze, displayRealtime);
	while (end->parent != nullptr) {
		//std::cout << "row: " << end->row << "    col: " << end->col << std::endl;
		end->inSolution = true;
		end = end->parent;
	}
	maze->get_start()->inSolution = true;
	maze->output(false, true);
}