#include <random>
#include <raylib.h>
#include "food.h"
#include "constants.h"

Food::Food() {
	Teleport();
}

Food::Food(int x, int y) {
	this->x = x;
	this->y = y;
}

int clamp(int v, int l, int u) {
	return std::max(l, std::min(v, u));
}

void Food::Teleport() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr_x(0, WIDTH / SCALE);
	std::uniform_int_distribution<> distr_y(0, HEIGHT / SCALE);
	
	x = clamp(distr_x(gen) * SCALE, 0, WIDTH - SCALE);
	y = clamp(distr_y(gen) * SCALE, 0, HEIGHT - SCALE);
}

int Food::GetX() const {
	return x;
}

int Food::GetY() const {
	return y;
}

void Food::SetX(int x) {
	this->x = x;
}

void Food::SetY(int y) {
	this->y = y;
}

Rectangle Food::AsRec() {
	return Rectangle{ .x = (float)x, .y = (float)y, .width = SCALE, .height = SCALE };
}
