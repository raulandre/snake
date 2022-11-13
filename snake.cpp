#include "grid.h"
#include "snake.h"

Snake::Snake() {
	pos_x = 0;
	pos_y = 0;
	color = RED;
}

Snake::Snake(int pos_x, int pos_y, Color color) {
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->color = color;
}
