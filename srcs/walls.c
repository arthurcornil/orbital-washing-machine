#include "../includes/owm.h"

static void	draw(walls *walls)
{
	for (int i = 0; i < (walls->number); i ++)
	{
		DrawRectanglePro(
				(Rectangle){
					(float)SCREEN_WIDTH / 2 + (69 * -sin(walls->collection[i].angle)),
					(float)SCREEN_HEIGHT / 2 - (69 * -cos(walls->collection[i].angle)),
					20,
					(walls->collection[i].gap_position) * (walls->collection[i].grown_percentage / 100)
				},
				(Vector2){ 10, 0 },
				(walls->collection)[i].angle * 180 / M_PI,
				*colors
		);
		DrawRectanglePro(
				(Rectangle){ 
					(float)SCREEN_WIDTH / 2 + (250 * -sin(walls->collection[i].angle)),
					(float)SCREEN_HEIGHT / 2 - (250 * -cos(walls->collection[i].angle)),
					20,
					(180 - walls->collection[i].gap_position - WALL_GAP_SIZE) * (walls->collection[i].grown_percentage / 100)
				},
				(Vector2){ 10, 0 },
				((walls->collection)[i].angle * 180 / M_PI) - 180,
				*colors
		);
	}
}

static void	grow(walls *walls)
{
	unsigned int fully_grown = 0;

	for (int i = 0; i < (walls->number); i++)
	{
		if (walls->collection[i].grown_percentage >= 100)
		{
			fully_grown ++;
			continue ;
		}
		walls->collection[i].grown_percentage += 2;
		if (walls->collection[i].grown_percentage < 50)
			break ;
		if (walls->collection[i].grown_percentage > 100)
			walls->collection[i].grown_percentage = 100;
	}
	if (fully_grown == walls->number)
		walls->grown = true;
}

static void update(walls *walls)
{
	if (!walls->grown)
		grow(walls);
	for (int i = 0; i < (walls->number); i ++)
		walls->collection[i].angle += walls->speed;
}

void	init_walls(walls *walls)
{
	float angle = -M_PI_4;
	srand(time(NULL));
	for (int i = 0; i < 4; i ++)
	{
		walls->collection[i] = (wall){ angle, rand() % (181 - WALL_GAP_SIZE) };
		walls->collection[i].grown_percentage = 0.0f;
		angle += M_PI_2;
	}
	walls->number = 4;
	walls->grown = false;
	walls->draw = draw;
	walls->update = update;
	walls->speed = -0.002f;
}
