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

	for (int i=0; i<mines; i++) {
		std::random_device rd;
		std::mt19937 generator(rd());
		std::uniform_int_distribution<int> distr(0, numberList.size()-1);
		

		int randomNumber = distr(rd);
		tiles.at(numberList.at(randomNumber))->setMine(true);
		numberList.erase(numberList.begin() + randomNumber);
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

int MinesweeperWindow::countMines(vector<Point> points) const {
	int mines = 0;
	for (Point& point : points) {
		int tile = point.x/cellSize + width*std::floor(point.y/cellSize);
		if (tiles.at(tile)->getMine()) {
			mines++;
		}
	}
	return mines;
}

void MinesweeperWindow::openTile(Point xy) {
	int tile = xy.x/cellSize + width*std::floor(xy.y/cellSize);
	vector<Point> adjacentPointsList;
	if (countMines(adjacentPoints(xy))==0) {
		tiles.at(tile)->open(0);
		for (Point& point : adjacentPoints(xy)) {
			if (tiles.at(point.x/cellSize + width*std::floor(point.y/cellSize))->getState() == Cell::closed) {
				bool present = false;
				for (Point& pointList : adjacentPointsList) {
					if (pointList.x == point.x && pointList.y == point.y) {
						present = true;
					}
				}
				if (!present) {
					adjacentPointsList.push_back(point);
				}
			}
		}
		for (Point& point : adjacentPointsList) {
			openTile(point);
		}
	} else {
		tiles.at(tile)->open(countMines(adjacentPoints(xy)));
	}
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
		checkLoss();
		checkWin();
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}
bool win = true;
bool loss = false;
void MinesweeperWindow::checkWin() {
	win = true;
	for (shared_ptr<Tile>& tile : tiles) {
		if (tile->getState() == Cell::closed && tile->getMine()==false) {
			win = false;
		}
	}
	if (win && !loss) {
		add(winTxt);
	}
}
void MinesweeperWindow::checkLoss() {
	loss = false;
	for (shared_ptr<Tile>& tile : tiles) {
		if (tile->getState() == Cell::open && tile->getMine()==true) {
			loss = true;
		}
	}
	if (loss) {
		for (shared_ptr<Tile>& tile : tiles) {
			if (tile->getMine()) {
				tile->setLabel("|>");
				tile->setButtonColor(TDT4102::Color::red);
			} else {
				tile->setButtonColor(TDT4102::Color::white);
				tile->setLabel("");
			}
		}
	}
}