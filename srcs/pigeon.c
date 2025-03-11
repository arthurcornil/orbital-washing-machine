#include "../includes/flappigeon.h"

void	draw(pigeon *pigeon)
{
	DrawRectangle(pigeon->x, pigeon->y, 50, 50, BLACK);
}

void	init_pigeon(pigeon *pigeon)
{
	pigeon->x = SCREEN_WIDTH / 2 - 25;
	pigeon->y = SCREEN_HEIGHT / 2 - 150;
	pigeon->score = 0;
	pigeon->draw = draw;
}

