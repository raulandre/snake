#ifndef GRID_H
#define GRID_H
#include <raylib.h>
#include <vector>
#include "constants.h"
#include "snake.h"
#include "food.h"

class Grid {
	private:
		Snake snake;
		Food food;
		std::vector<std::vector<Rectangle>> m_Grid;		
		unsigned int m_Size;
	public:
		Grid();
		void Update();
		void Draw();
		std::vector<Rectangle> GetEmptySpots() const;
};

#endif
