#include "MinesweeperWindow.h"

int main()
{
	constexpr int width = 15;
	constexpr int height = 15;
	constexpr int mines = 20;

	Point startPoint{ 200, 300 };
	MinesweeperWindow mw{startPoint.x, startPoint.y, width, height, mines, "Minesweeper" };
	mw.wait_for_close();

	return 0;
}
