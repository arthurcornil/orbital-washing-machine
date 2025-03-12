#include "../includes/flappigeon.h"

static void	draw(pigeon *p)
{
	DrawRectanglePro(
		(Rectangle){ p->position.x - 10, p->position.y - 10, 20, 20 },
		(Vector2){ 10, 10 },
		p->angle * 180 / M_PI,
		*colors
	);
}

static void	update(pigeon *p)
{
	p->angle += p->speed;
	if (p->angle >= 2 * M_PI)
	{
		p->score ++;
		p->angle -= 2 * M_PI;
	}
	p->position.x = (float)SCREEN_WIDTH / 2 + (p->radius * sin(p->angle));
	p->position.y = (float)SCREEN_HEIGHT / 2 - (p->radius * cos(p->angle));
}

void	init_pigeon(pigeon *pigeon)
{
	pigeon->score = 0;
	pigeon->speed = 0.02f;
	pigeon->radius = 150;
	pigeon->angle = 0;
	pigeon->draw = draw;
	pigeon->update = update;
}

