#ifndef FOOD_H
#define FOOD_H
#include <raylib.h>
#include <stdbool.h>

class Food {
	private:
		int x, y;
		Sound eatSound;
	public:
		Food();
		Food(int x, int y);
		~Food();
		int GetX() const;
		int GetY() const;
		void SetX(int x);
		void SetY(int y);
		void Teleport(bool first = false);
		Rectangle AsRec();
};

#endif
