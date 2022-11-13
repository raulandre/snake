#include <raylib.h>

#include "constants.h"
#include "grid.h"

int main() {
	InitWindow(WIDTH, HEIGHT, "Snake Game");
	SetTargetFPS(FRAMERATE);

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
