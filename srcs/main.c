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

int	main(void)
{
	pigeon pigeon;
	walls walls;

	init_pigeon(&pigeon);
	init_walls(&walls);

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappigeon");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		//Take user input

		//Update state
		pigeon.update(&pigeon);
		walls.update(&walls);
		update_color(pigeon.score, colors);

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
