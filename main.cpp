#include <raylib.h>

#include "constants.h"
#include "grid.h"

int main() {
	InitWindow(WIDTH, HEIGHT, "Snake Game");
	SetTargetFPS(10);

	Grid g;
	while(!WindowShouldClose()) {
		g.Update();
		BeginDrawing();
			ClearBackground(RAYWHITE);
			g.Draw();
		EndDrawing();
	}

	CloseWindow();
}
