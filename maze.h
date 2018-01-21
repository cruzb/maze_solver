#pragma once
#include "node.h"
#include "CImg.h"
#include <string>
#include <vector>

using namespace cimg_library;


//TODO desructor
class maze {
public:
	maze(std::string filename);
	node* at(int r, int c);
	node* at(int index);
	node* right(node* n);
	node* left(node* n);
	node* top(node* n);
	node* bottom(node* n);
	node* get_start();
	node* get_end();
	int height();
	int width();
	void print();
	void output(bool displayVisited, bool save);
	void output(node* n);
private:
	CImgDisplay display;
	CImg<float> image;
	node* start;
	node* end;
	std::vector<std::vector<node*> > grid;
};