#include "maze.h"
#include "graph.h"
#include "breadth.h"
#include "dijkstra.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	maze m("test.bmp");
	//m.print();
	//graph g(&m);
	//g.print();
	solve_bfs(&m, true);
	//solve_dijkstra(&g, &m, true);
	system("pause");
}
