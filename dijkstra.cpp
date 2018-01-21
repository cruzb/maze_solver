#include "graph.h"
#include "maze.h"
#include <queue>
#include <vector>
#include <functional>

typedef std::pair<int, int> ind_dist_pair;

struct comparator {
	bool operator()(std::pair<int, int> p1, std::pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

node* dijkstra(graph* graph, maze* maze, bool displayRealtime) {
	node* start = maze->get_start();
	node* end = maze->get_end();

	int verticies = graph->node_count();
	std::vector<int> distances(maze->height() * maze->width(), INT_MAX);

	std::priority_queue<ind_dist_pair, std::vector<ind_dist_pair>, 
						comparator> pq;

	pq.push(std::make_pair(maze->get_start()->index, 0));
	distances[maze->get_start()->index] = 0;
	

	while (!pq.empty()) {
		int index = pq.top().first;
		pq.pop();
		maze->at(index)->visited = true;

		if (displayRealtime) {
			maze->output(maze->at(index));
			//wait between frames only if maze size warrants it
			//realtime display struggles with larger mazes
			if (maze->height() * maze->width() < 1000)
				Sleep(50);
		}

		if (maze->at(index) == end)
			return end;

		//loop through all adjacent to current
		for (int adjIndex = 0; adjIndex < graph->at(index)->size(); adjIndex++) {
			int i = graph->at(index, adjIndex);
			
			if (distances[i] > distances[index] + 1) {
				distances[i] = distances[index] + 1;
				pq.push(std::make_pair(i, distances[i]));
				maze->at(i)->parent = maze->at(index);
			}
		}
	}
}

void solve_dijkstra(graph* graph, maze* maze, bool displayRealtime) {
	node* end = dijkstra(graph, maze, displayRealtime);
	while (end->parent != nullptr) {
		//std::cout << "row: " << end->row << "    col: " << end->col << std::endl;
		end->inSolution = true;
		end = end->parent;
	}
	maze->get_start()->inSolution = true;
	maze->output(false, true);
}