#include "grid.h"
#include "constants.h"
#include "snake.h"
#include <raylib.h>

Grid::Grid() {
	m_Size = WIDTH * HEIGHT / SCALE;

	auto lineCount = HEIGHT / SCALE;
	auto squaresPerLine = WIDTH / SCALE;

	for(int i = 0; i < lineCount; i++) {
		std::vector<Rectangle> line;
		for(int j = 0; j < squaresPerLine; j++) {
			auto rec = Rectangle{.x = (float)j * SCALE, .y = (float)i * SCALE, .width = SCALE, .height = SCALE};
			line.push_back(rec);
		}

		m_Grid.push_back(line);
	}

	snake.SetX(squaresPerLine / 2 * SCALE);
	snake.SetY(lineCount / 2 * SCALE);
}

void Grid::Update() {
	snake.Update();
	if(CheckCollisionRecs(snake.AsRec(), food.AsRec())) {
		food.Teleport();
		snake.Eat();
	}
}

void Grid::Draw() {
	DrawRectangle(food.GetX(), food.GetY(), SCALE, SCALE, FOOD_COLOR);

	for(auto &line : m_Grid) {
		for(auto &square : line) {
			if(square.x == snake.GetX() && square.y == snake.GetY())
				DrawRectangle(square.x, square.y, SCALE, SCALE, SNAKE_COLOR);
#ifdef GRID
			else
				DrawRectangleLines(square.x, square.y, SCALE, SCALE, GRID_COLOR);
#endif
		}
	}

	for(auto &tailRec : snake.Tail()) {
		DrawRectangle(tailRec.x, tailRec.y, SCALE, SCALE, RED);
	}
}
