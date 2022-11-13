#ifndef GRID_H
#define GRID_H
#include <raylib.h>
#include <vector>
#include "constants.h"
#include "snake.h"

class Grid {
	private:
		Snake snake;
		std::vector<std::vector<Rectangle>> m_Grid;		
		unsigned int m_Size;
	public:
		Grid();
		void Update();
		void Draw();
};

#endif
