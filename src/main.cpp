#include <raylib.h>

#include "constants.h"
#include "grid.h"

int main() {
	InitWindow(WIDTH, HEIGHT, "Snake Game");
	InitAudioDevice();
	SetTargetFPS(FRAMERATE);

	Grid g;
	while(!WindowShouldClose()) {
		g.Update();
		BeginDrawing();
			ClearBackground(RAYWHITE);
			g.Draw();
		EndDrawing();
	}

	StopSoundMulti();
	CloseAudioDevice();
	CloseWindow();
}
