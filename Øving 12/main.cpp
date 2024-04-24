#include "Tetromino.h"
#include "TetrisWindow.h"



int main()
{
	TetrisWindow win(300, 30, 900, 800);
	win.run();
	win.wait_for_close();
	return 0;
}
