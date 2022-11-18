#include "grid.h"
#include "constants.h"
#include "snake.h"
#include <raylib.h>
#include <random>
#include <algorithm>

//https://stackoverflow.com/questions/6942273/how-to-get-a-random-element-from-a-c-container
template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

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

	auto available_positions = GetEmptySpots();
	auto pos = *select_randomly(available_positions.begin(), available_positions.end());
	food.Teleport(pos.x, pos.y, true);
}

void Grid::Update() {
	if(!snake.dead) {
		snake.Update();
		if(CheckCollisionRecs(snake.AsRec(), food.AsRec())) {
			auto available_positions = GetEmptySpots();
			auto pos = *select_randomly(available_positions.begin(), available_positions.end());
			food.Teleport(pos.x, pos.y);
			snake.Eat();
		}
	} else {
		if(IsKeyDown(KEY_SPACE)) {
			snake.Reset();
			auto available_positions = GetEmptySpots();
			auto pos = *select_randomly(available_positions.begin(), available_positions.end());
			food.Teleport(pos.x, pos.y, true);
		}
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

	if(snake.dead) {
		auto msg1 = "GAME OVER!";
		auto msg2 = "Hold [SPACE] to restart";
		auto len = MeasureText(msg1, 28);
		DrawText(msg1, WIDTH/2 - len/2, HEIGHT/2 - 28, 28, BLACK);
		len = MeasureText(msg2, 14);
		DrawText(msg2, WIDTH/2 - len/2, HEIGHT/2 + 28, 14, BLACK);
	}
}

std::vector<Rectangle> Grid::GetEmptySpots() const {
	std::vector<Rectangle> g;
	for(auto &line : m_Grid) {
		for(auto &r : line) {
			if(snake.GetX() == r.x && snake.GetY() == r.y) continue;

			bool isTail = false;
			for(auto &t : snake.Tail()) {
				if(r.x == t.x && r.y == t.y) { isTail = true; break; }
			}

			if(!isTail) {
				g.emplace_back(r);
			}
		}
	}

	return g;
}
