#include "Tile.h"
#include "iostream"


// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol{{Cell::closed, ""},
												{Cell::open, ""},
									 	  		{Cell::flagged, "|>"}};

Tile::Tile(TDT4102::Point pos, int size) : 
	Button({pos.x, pos.y}, 1.5*size, size, "") {
		setButtonColor(TDT4102::Color::silver);
	}

void Tile::open(int n) {	
	if (Tile::getState() == Cell::closed) {
		Tile::state = Cell::open;
		Tile::setButtonColor(TDT4102::Color::white);
		if (n != 0) {
			Tile::set_label(std::to_string(n));
		}
		if (Tile::getMine() == true) {
			Tile::setButtonColor(TDT4102::Color::red);
		} 
	}
}

void Tile::flag() {
	if (Tile::state == Cell::flagged) {
		Tile::state = Cell::closed;
		Tile::set_label(cellToSymbol.at(Cell::closed));
		Tile::setButtonColor(TDT4102::Color::silver);
	} else if (Tile::state == Cell::closed) {
		Tile::state = Cell::flagged;
		Tile::setButtonColor(TDT4102::Color::black);
		Tile::set_label(cellToSymbol.at(Cell::flagged));
	}
}

void Tile::setAdjMines(int n) {
	Tile::set_label(static_cast<std::string>(std::to_string(n)));
	Tile::set_label_color(minesToColor.at(n));
}

bool Tile::getMine() { return isMine;}
void Tile::setMine(bool state) {isMine = state;}

