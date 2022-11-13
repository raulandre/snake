#include <iostream>
#include "constants.h"
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

int constrainPosition_x(int pos_x) {
	if(pos_x < 0)
		return WIDTH - SCALE;
	if(pos_x >= WIDTH)
		return 0;		

	return pos_x;

}

int constrainPosition_y(int pos_y) {
	if(pos_y < 0)
		return HEIGHT - SCALE;
	if(pos_y >= HEIGHT)
		return 0;

	return pos_y;
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

	pos_x = constrainPosition_x(pos_x);
	pos_y = constrainPosition_y(pos_y);
}

int Snake::GetX() const {
	return pos_x;
}

int Snake::GetY() const {
	return pos_y;
}
