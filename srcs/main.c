#include "../includes/flappigeon.h"

void	draw_middle_circle(pigeon *p)
{
		DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 70, *colors);
		DrawText(
			TextFormat("%i", p->score), 
			(SCREEN_WIDTH / 2) - (MeasureText(TextFormat("%i", p->score), 60) / 2), 
			(SCREEN_HEIGHT / 2) - 30,
			60, 
			WHITE
		);
}

void	update_state(pigeon *pigeon, walls *walls)
{
		pigeon->update(pigeon);
		walls->update(walls);
		update_color(pigeon->score, colors);
}

int	main(void)
{
	pigeon	pigeon;
	walls	walls;
	bool	has_game_begun = false;

	init_pigeon(&pigeon);
	init_walls(&walls);

	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappigeon");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		//Take user input
		if (IsKeyDown(KEY_SPACE) || IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			if (!has_game_begun)
				has_game_begun = true;
			pigeon.flap(&pigeon);
		}

		//Update state
		if (has_game_begun)
			update_state(&pigeon, &walls);

		//Draw
		BeginDrawing();
		DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 250, WHITE);
		pigeon.draw(&pigeon);
		walls.draw(&walls);
		draw_middle_circle(&pigeon);
		ClearBackground(*colors);
		EndDrawing();
	}
	CloseWindow();
}
