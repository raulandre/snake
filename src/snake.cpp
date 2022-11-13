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
	if(IsKeyPressed(KEY_W) && speed_y == 0) {
		speed_x = 0;
		speed_y = -1;
	}
	else if(IsKeyPressed(KEY_A) && speed_x == 0) {
		speed_y = 0;
		speed_x = -1;
	}
	else if(IsKeyPressed(KEY_S) && speed_y == 0) { 
		speed_x = 0;
		speed_y = 1;
	}
	else if(IsKeyPressed(KEY_D) && speed_x == 0) {
		speed_y = 0;
		speed_x = 1;
	}

	if(tail.size() > 0) {
		for(int i = 0; i < tail.size() - 1; i++) {
			tail[i] = tail[i+1];
		}
		tail[tail.size() - 1] = Rectangle{.x = (float)pos_x, .y = (float)pos_y, .width = SCALE, .height = SCALE };
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

std::vector<Rectangle> Snake::Tail() const {
	return tail;
}

void Snake::SetX(int pos_x) {
	this->pos_x = pos_x;
}

void Snake::SetY(int pos_y) {
	this->pos_y = pos_y;
}

void Snake::Eat() {
	tail.push_back(Rectangle{.x = (float)pos_x, .y = (float)pos_y, .width = SCALE, .height = SCALE });
}

Rectangle Snake::AsRec() {
	return Rectangle{ .x = (float)pos_x, .y = (float)pos_y, .width = SCALE, .height = SCALE };
}
