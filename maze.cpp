#include "maze.h"
#include <stdio.h>
#include <string>
#include <iostream>



maze::maze(std::string filename) {
	CImg<float> img(filename.c_str());
	image = img;
	int height = image.height();
	int width = image.width();

	if (height > 500 || width > 500) {
		CImgDisplay disp(width, height);
		display = disp;
	}
	else {
		CImgDisplay disp(500, 500);
		display = disp;
	}
	

	grid.resize(height);
	for (int i = 0; i < height; i++)
		grid[i].resize(width);

	for (int r = 0; r < height; r++) {
		for (int c = 0; c < width; c++) {
			//new node base configuration
			node* n = new node;
			n->index = r * grid[0].size() + c;
			n->row = r;
			n->col = c;
			n->visited = false;
			n->inSolution = false;
			n->parent = nullptr;

			//if white
			if (image(c, r, 0, 0) == 255 &&
				image(c, r, 0, 1) == 255 &&
				image(c, r, 0, 2) == 255) {
				
				n->passable = true;
				grid[r][c] = n;

				if (r == 0) start = n;
				if (r == height - 1) end = n;
			}
			//if black
			else if (image(c, r, 0, 0) == 0 &&
					image(c, r, 0, 1) == 0 &&
					image(c, r, 0, 1) == 0) {

				n->passable = false;
				grid[r][c] = n;
			}

			else {
				std::cout << "Improper input" << std::endl;
				exit(1);
			}
		}
	}
}



node* maze::at(int r, int c) {
	return grid[r][c];
}

node* maze::at(int index) {
	return grid[index / grid[0].size()][index % grid[0].size()];
}

node* maze::right(node* n) {
	if (n->col + 1 < grid[0].size())
		return grid[n->row][n->col + 1];
	else return nullptr;
}

node* maze::left(node* n) {
	if (n->col - 1 > -1)
		return grid[n->row][n->col - 1];
	else return nullptr;
}

node* maze::top(node* n) {
	if (n->row - 1 > -1)
		return grid[n->row - 1][n->col];
	else return nullptr;
}

node* maze::bottom(node* n) {
	if (n->row + 1 < grid.size())
		return grid[n->row + 1][n->col];
	else return nullptr;
}

node* maze::get_start(){
	return start;
}
node* maze::get_end() {
	return end;
}

int maze::height() {
	return grid.size();
}

int maze::width() {
	return grid[0].size();
}

void maze::print() {
	for (int r = 0; r < grid.size(); r++) {
		for (int c = 0; c < grid[0].size(); c++) {
			if (grid[r][c]->passable)
				std::cout << ".";
			else
				std::cout << "0";
		}
		std::cout << std::endl;
	}
}

//TODO make this more efficient or make an alternate function
//which takes the original file and edits that
//instead of making a new image and changing it pixel to pixel
//this is the time limitation on display 
void maze::output(bool displayVisited, bool save) {
	//CImg<float> out(grid[0].size(), grid.size(), 1, 3);
	/*for (int r = 0; r < grid.size(); r++) {
		for (int c = 0; c < grid[0].size(); c++) {
			if (grid[r][c]->inSolution) {
				image(c, r, 0, 0) = 255;
				image(c, r, 0, 1) = 0;
				image(c, r, 0, 2) = 0;
			}
			else if (grid[r][c]->visited && displayVisited) {
				image(c, r, 0, 0) = 0;
				image(c, r, 0, 1) = 0;
				image(c, r, 0, 2) = 255;
			}
			else if (!grid[r][c]->passable) {
				image(c, r, 0, 0) = 0;
				image(c, r, 0, 1) = 0;
				image(c, r, 0, 2) = 0;
			}
		}
	}

	if (save) {
		image.save("output.bmp");
		image.display(display);
	}
	else
		image.display(display);*/
	CImg<float> out(grid[0].size(), grid.size(), 1, 3);
	for (int r = 0; r < grid.size(); r++) {
		for (int c = 0; c < grid[0].size(); c++) {
			if (grid[r][c]->inSolution) {
				out(c, r, 0, 0) = 255;
				out(c, r, 0, 1) = 0;
				out(c, r, 0, 2) = 0;
			}
			else if (grid[r][c]->visited && displayVisited) {
				out(c, r, 0, 0) = 0;
				out(c, r, 0, 1) = 0;
				out(c, r, 0, 2) = 255;
			}
			else if (!grid[r][c]->passable) {
				out(c, r, 0, 0) = 0;
				out(c, r, 0, 1) = 0;
				out(c, r, 0, 2) = 0;
			}
			else {
				out(c, r, 0, 0) = 255;
				out(c, r, 0, 1) = 255;
				out(c, r, 0, 2) = 255;
			}
		}
	}

	if (save){
		out.save("output.bmp");
		out.display(display);
	}
	else 
		out.display(display);
}


void maze::output(node* n) {
	int r = n->row;
	int c = n->col;
	if (n->inSolution) {
		image(c, r, 0, 0) = 255;
		image(c, r, 0, 1) = 0;
		image(c, r, 0, 2) = 0;
	}
	else if (n->visited) {
		image(c, r, 0, 0) = 0;
		image(c, r, 0, 1) = 0;
		image(c, r, 0, 2) = 255;
	}
	else if (!n->passable) {
		image(c, r, 0, 0) = 0;
		image(c, r, 0, 1) = 0;
		image(c, r, 0, 2) = 0;
	}

	image.display(display);
}
