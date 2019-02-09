# Maze Solver
Solves mazes by a variety of algorithms. 

### Algorithms
Implements the following:
* Breadth First Search
* Depth First Search
* Dijkstra's Algorithm

#### Todo:
* Implement A*
* Add command line parameters
* Makefile

### Usage
Main entry point in "test.cpp"
Provide within "test.cpp" a .bmp format maze, and algorithm to use.
Compile and run with any cpp compiler.

#### Maze Rules
Mazes must adhere to the following rules to be valid:
* One pixel is one space
* Black pixels are walls, white pixels are paths
* There must be one white pixel on the first and last rows to serve as entrance and exit to the maze
* All other pixels on the outside edges of the image must be black
