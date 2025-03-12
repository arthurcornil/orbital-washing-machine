#include "../includes/flappigeon.h"

static void	draw(walls *walls)
{
	for (int i = 0; i < (walls->number); i ++)
	{
		DrawRectanglePro(
				(Rectangle){ (float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2, 20, 250 },
				(Vector2){ 10, 0 },
				(walls->collection)[i].angle * 180 / M_PI,
				*colors
		);
	}
}

static void update(walls *walls)
{
	for (int i = 0; i < (walls->number); i ++)
		walls->collection[i].angle += walls->speed;
}

void	init_walls(walls *walls)
{
	float angle = M_PI_4;
	for (int i = 0; i < 4; i ++)
	{
		walls->collection[i] = (wall){ angle, rand() % (300 - WALL_GAP_SIZE - 70) + 70 };
		angle += M_PI_2;
	}
	walls->number = 4;
	walls->draw = draw;
	walls->update = update;
	walls->speed = -0.002f;
}
