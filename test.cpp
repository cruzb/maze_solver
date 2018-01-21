#include "maze.h"
#include "graph.h"
#include "breadth.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	maze m("test.bmp");
	//m.print();
	//graph g(&m);
	//g.print();
	solve_bfs(&m, false);
	system("pause");
}
