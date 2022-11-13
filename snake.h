#ifndef SNAKE_H
#define SNAKE_H
#include <raylib.h>

class Grid;
class Snake {
	private:
			int pos_x, pos_y;
			Color color;
	public:
			Snake();
			Snake(int pos_x, int pos_y, Color color);
};

#endif
