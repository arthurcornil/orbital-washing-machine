#include "../includes/owm.h"

static void	draw(wm *wm)
{
	DrawRectanglePro(
        (Rectangle){ wm->position.x, wm->position.y, 20, 20 },
        (Vector2){ 10, 10 },
        wm->angle * 180 / M_PI,
        *colors
    );
	DrawTexturePro(
		wm->texture,
		(Rectangle){ 0, 0, wm->texture.width, wm->texture.height },
		(Rectangle){ wm->position.x, wm->position.y, 20, 20 },
		(Vector2){ 10, 10 },
		wm->angle * 180 / M_PI,
		WHITE
	);
}

static void	update(wm *wm, walls *walls)
{
	wm->angle += wm->speed;
	wm->acceleration -= GRAVITY;
	wm->radius += wm->acceleration;
	if (wm->radius >= 240)
		wm->radius = 240;
	if (wm->angle >= 2 * M_PI)
	{
		wm->score ++;
		if (!(wm->score % 5))
			walls->must_hide = true;
		wm->angle -= 2 * M_PI;
	}
	wm->position.x = (float)SCREEN_WIDTH / 2 + (wm->radius * sin(wm->angle));
	wm->position.y = (float)SCREEN_HEIGHT / 2 - (wm->radius * cos(wm->angle));
}

static void	propel(wm *wm)
{
	wm->acceleration += 2.2f;
	if (wm->acceleration > 3.2f)
		wm->acceleration = 3.2f;
}

void	init_wm(wm *wm)
{
	wm->score = 0;
	wm->speed = 0.02f;
	wm->radius = 150;
	wm->angle = 0;
	wm->acceleration = 0;
	wm->position.x = (float)SCREEN_WIDTH / 2;
	wm->position.y = (float)SCREEN_HEIGHT / 2 - (wm->radius * cos(wm->angle));
	wm->texture = LoadTexture("assets/wm.png");
	wm->draw = draw;
	wm->update = update;
	wm->propel = propel;
}

