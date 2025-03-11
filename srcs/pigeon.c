#include "../includes/flappigeon.h"

void	draw(pigeon *p)
{
	DrawRectanglePro(
		(Rectangle){ p->position.x - 10, p->position.y - 10, 20, 20 },
		(Vector2){ 10, 10 },
		p->angle * 180 / M_PI,
		*colors
	);
}

void	update(pigeon *p)
{
	p->angle += p->speed;
	if (p->angle >= 2 * M_PI)
		p->angle -= 2 * M_PI;
	p->position.x = (float)SCREEN_WIDTH / 2 + (150 * cos(p->angle));
	p->position.y = (float)SCREEN_HEIGHT / 2 + (150 * sin(p->angle));
}

void	init_pigeon(pigeon *pigeon)
{
	pigeon->score = 0;
	pigeon->speed = 0.03f;
	pigeon->angle = (0 - pigeon->speed);
	pigeon->draw = draw;
	pigeon->update = update;
}

