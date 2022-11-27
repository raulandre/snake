#include <random>
#include <raylib.h>
#include "food.h"
#include "constants.h"

Food::Food() {
	eatSound = LoadSound("sounds/eat.wav");
	SetSoundVolume(eatSound, 1.0f);
}

Food::Food(int x, int y) {
	this->x = x;
	this->y = y;
}

int clamp(int v, int l, int u) {
	return std::max(l, std::min(v, u));
}

void Food::Teleport(int x, int y, bool first) {
	SetX(x);
	SetY(y);
	if(!first) {
		PlaySound(eatSound);
	}
}

Food::~Food() {
	UnloadSound(eatSound);
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
