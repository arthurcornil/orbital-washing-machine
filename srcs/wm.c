#include "../includes/owm.h"

static void	show_flame(wm *wm)
{
	int frame_index = (int)(GetTime() * ANIMATION_FPS) % 6;
	Rectangle dest = (Rectangle){ wm->position.x, wm->position.y, 16, 20 };
	DrawTexturePro(
		wm->flame->atlas,
		wm->flame->frames[frame_index],
		dest,
		(Vector2){8, 30},
		(wm->angle * 180 / M_PI) - 180,
		WHITE
	);
}

void	draw_wm(wm *wm)
{
	DrawTexturePro(
		wm->texture,
		(Rectangle){ 0, 0, wm->texture.width, wm->texture.height },
		(Rectangle){ wm->position.x, wm->position.y, 20, 20 },
		(Vector2){ 10, 10 },
		wm->angle * 180 / M_PI,
		WHITE
	);
	if (wm->is_propelling)
		show_flame(wm);
}

void	update_wm(wm *wm, walls *walls)
{
	wm->angle += wm->speed;
	wm->acceleration -= GRAVITY;
	wm->radius += wm->acceleration;
	if (wm->radius >= 240)
		wm->radius = 240;
	else if (wm->radius <= 80)
		wm->radius = 80;
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

void	propel(wm *wm)
{
	wm->acceleration += 2.2f;
	if (wm->acceleration > 3.2f)
		wm->acceleration = 3.2f;
	if (!wm->is_propelling)
		wm->is_propelling = true;
	if (!IsSoundPlaying(wm->flame->fx))
		PlaySound(wm->flame->fx);
}

static void	init_flame(flame *flame)
{
	int curr_x = 0;
	int curr_y = 0;

	flame->atlas = LoadTexture("assets/fire.png");
	flame->fx = LoadSound("assets/engine.mp3");
	for (int i = 0; i < 6; i ++)
	{
		flame->frames[i] = (Rectangle){
			curr_x,
			curr_y,
			58,
			72
		};
		curr_x += 58;
		curr_x %= 174;
		if (curr_x == 0)
			curr_y += 72;
	}
}

void	init_wm(wm *wm)
{
	static flame f;

	wm->score = 0;
	wm->speed = 0.02f;
	wm->radius = 150;
	wm->angle = 0;
	wm->acceleration = 0;
	wm->position.x = (float)SCREEN_WIDTH / 2;
	wm->position.y = (float)SCREEN_HEIGHT / 2 - (wm->radius * cos(wm->angle));
	wm->texture = LoadTexture("assets/wm.png");
	init_flame(&f);
	wm->flame = &f;
	wm->is_propelling = false;
}

