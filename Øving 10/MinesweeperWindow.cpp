#include "MinesweeperWindow.h"
#include <iostream>
#include <vector>
#include <random>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}
	std::vector<int> numberList;
	for (int i=0; i<width*height; i++) {
		numberList.push_back(i);
	}

	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distr(0, numberList.size()-1);

	for (int i=0; i<mines; i++) {
		int randomNumber = numberList.at(distr(rd));
		numberList.erase(numberList.begin() + distr(rd));
		tiles.at(randomNumber)->setMine(true);
	}
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	int tile = xy.x/cellSize + width*std::floor(xy.y/cellSize);
	tiles.at(tile)->open();
}

void MinesweeperWindow::flagTile(Point xy) {
	int tile = xy.x/cellSize + width*std::floor(xy.y/cellSize);
	tiles.at(tile)->flag();
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	
	Point xy{this->get_mouse_coordinates()};

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}
