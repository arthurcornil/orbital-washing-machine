#include "../includes/flappigeon.h"

int	main(void)
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappigeon");
	SetTargetFPS(20);

	Color green = {103, 194, 89, 255};
	pigeon pigeon;

	init_pigeon(&pigeon);
	
	while (!WindowShouldClose())
	{
		BeginDrawing();

		DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 250, WHITE);
		DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 70, green);
		DrawText(
			TextFormat("%i", pigeon.score), 
			(SCREEN_WIDTH / 2) - (MeasureText(TextFormat("%i", pigeon.score), 60) / 2), 
			(SCREEN_HEIGHT / 2) - 30,
			60, 
			WHITE
		);
		pigeon.draw(&pigeon);
		ClearBackground(green);
		EndDrawing();
	}
	CloseWindow();
}
