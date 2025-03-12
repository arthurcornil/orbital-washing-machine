#include "../includes/owm.h"

void	draw_middle_circle(wm *wm)
{
		DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 70, *colors);
		DrawText(
			TextFormat("%u", wm->score), 
			(SCREEN_WIDTH / 2) - (MeasureText(TextFormat("%u", wm->score), 60) / 2), 
			(SCREEN_HEIGHT / 2) - 30,
			60, 
			(Color){2, 12, 28, 255}
		);
}

void	update_state(wm *wm, walls *walls)
{
		update_color(wm->score, colors);
		wm->update(wm, walls);
		walls->update(walls);
}

int	main(void)
{
	wm		wm;
	walls	walls;
	bool	play = false;

	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Orbital Washing Machine");
	SetTargetFPS(60);

	init_wm(&wm);
	init_walls(&walls);

	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_SPACE) || IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			if (!play)
				play = true;
			wm.propel(&wm);
		}

		if (play)
			update_state(&wm, &walls);

		BeginDrawing();
		DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 250, (Color){2, 12, 28, 255});
		DrawRectangle(SCREEN_WIDTH / 2 - 2, SCREEN_HEIGHT / 2 - 250, 4, 250, (Color){255, 255, 255, 20});
		walls.draw(&walls);
		wm.draw(&wm);
		draw_middle_circle(&wm);
		ClearBackground(*colors);
		EndDrawing();
	}
	UnloadTexture(wm.texture);
	CloseWindow();
}
