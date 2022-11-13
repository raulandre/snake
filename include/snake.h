#ifndef SNAKE_H
#define SNAKE_H
#include <raylib.h>
#include <vector>

class Grid;
class Snake {
	private:
			int pos_x, pos_y;
			float speed_x, speed_y;
			std::vector<Rectangle> tail;
			Color color;
	public:
			Snake();
			Snake(int pos_x, int pos_y, Color color);
			void Update();
			void Draw(Grid *grid);

			int GetX() const;
			int GetY() const;
			std::vector<Rectangle> Tail() const;

			void SetX(int pos_x);
			void SetY(int pos_y);
			void Eat();
			Rectangle AsRec();
};

#endif
