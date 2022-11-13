#ifndef FOOD_H
#define FOOD_H
#include <raylib.h>

class Food {
	private:
		int x, y;
	public:
		Food();
		Food(int x, int y);
		int GetX() const;
		int GetY() const;
		void SetX(int x);
		void SetY(int y);
		void Teleport();
		Rectangle AsRec();
};

#endif
