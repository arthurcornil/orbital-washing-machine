#include "../includes/flappigeon.h"

static void	draw(pigeon *p)
{
	DrawRectanglePro(
		(Rectangle){ p->position.x, p->position.y, 20, 20 },
		(Vector2){ 10, 10 },
		p->angle * 180 / M_PI,
		*colors
	);
}

static void	update(pigeon *p)
{
	p->angle += p->speed;
	p->acceleration -= GRAVITY;
	printf("%f\n", p->acceleration);
	p->radius += p->acceleration;
	if (p->angle >= 2 * M_PI)
	{
		p->score ++;
		p->angle -= 2 * M_PI;
	}
	p->position.x = (float)SCREEN_WIDTH / 2 + (p->radius * sin(p->angle));
	p->position.y = (float)SCREEN_HEIGHT / 2 - (p->radius * cos(p->angle));
}

static void	flap(pigeon *p)
{
	p->acceleration += 1;
	if (p->acceleration > 3.0f)
		p->acceleration = 3.0f;
}

void	init_pigeon(pigeon *p)
{
	p->score = 0;
	p->speed = 0.02f;
	p->radius = 150;
	p->angle = 0;
	p->acceleration = 0;
	p->position.x = (float)SCREEN_WIDTH / 2;
	p->position.y = (float)SCREEN_HEIGHT / 2 - (p->radius * cos(p->angle));
	p->draw = draw;
	p->update = update;
	p->flap = flap;
}

