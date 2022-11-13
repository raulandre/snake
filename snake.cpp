#include "grid.h"
#include "snake.h"
#include <raylib.h>

Snake::Snake() {
	pos_x = 0;
	pos_y = 0;
	color = RED;
	speed_x = 1.0f;
	speed_y = 0.0f;
}

Snake::Snake(int pos_x, int pos_y, Color color) {
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->color = color;
	speed_x = 1.0f;
	speed_y = 0.0f;
}

void Snake::Update() {
	if(IsKeyPressed(KEY_W)) {
		speed_x = 0;
		speed_y = -1;
	}
	else if(IsKeyPressed(KEY_A)) {
		speed_y = 0;
		speed_x = -1;
	}
	else if(IsKeyPressed(KEY_S)) { 
		speed_x = 0;
		speed_y = 1;
	}
	else if(IsKeyPressed(KEY_D)) { 
		speed_y = 0;
		speed_x = 1;
	}

	pos_x += speed_x * SCALE;
	pos_y += speed_y * SCALE;
}

int Snake::GetX() const {
	return pos_x;
}

int Snake::GetY() const {
	return pos_y;
}
