#include "../includes/owm.h"

void	draw_middle_circle(wm *wm)
{
		DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 70, *colors);
		DrawText(
			TextFormat("%u", wm->score), 
			(SCREEN_WIDTH / 2) - (MeasureText(TextFormat("%u", wm->score), 60) / 2), 
			(SCREEN_HEIGHT / 2) - 30,
			60, 
			(Color){2, 12, 28, 255}
		);
}

void	init_settings(settings *settings)
{
	settings->sprite = LoadTexture("assets/settings_sprite.png");
}

void	draw_settings(settings *settings)
{
	int padding = SCREEN_WIDTH - SETTINGS_ICON_WIDTH - 20;
	Rectangle source = (Rectangle){0, 0, SETTINGS_ICON_WIDTH, SETTINGS_ICON_HEIGHT};
	//DrawTextureRec(settings->sprite, source, (Vector2){ padding - 100, 20 }, WHITE);
	source.x += SETTINGS_ICON_WIDTH;
	DrawTextureRec(settings->sprite, source, (Vector2){ padding - 40, 20 }, WHITE);
	source.x += SETTINGS_ICON_WIDTH;
	DrawTextureRec(settings->sprite, source, (Vector2){ padding, 20 }, WHITE);
}

int	main(void)
{
	wm			wm;
	walls		walls;
	settings	settings;
	bool		play = false;
	Music		music;

	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Orbital Washing Machine");
	InitAudioDevice();
	SetTargetFPS(60);

	init_wm(&wm);
	init_walls(&walls);
	init_settings(&settings);
	music = LoadMusicStream("assets/music.wav");

	PlayMusicStream(music);
	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_SPACE))
		{
			if (!play)
				play = true;
			propel(&wm);
		}
		else if (wm.is_propelling)
		{
			wm.is_propelling = false;
			StopSound(wm.flame->fx);
		}

		if (play)
		{
			update_color(wm.score, colors);
			update_wm(&wm, &walls);
			update_walls(&walls);
		}
		UpdateMusicStream(music);

		BeginDrawing();
		draw_settings(&settings);
		DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 250, (Color){2, 12, 28, 255});
		DrawRectangle(SCREEN_WIDTH / 2 - 2, SCREEN_HEIGHT / 2 - 250, 4, 250, (Color){255, 255, 255, 20});
		draw_walls(&walls);
		draw_wm(&wm);
		draw_middle_circle(&wm);
		ClearBackground(*colors);
		EndDrawing();
	}
	CloseAudioDevice();
	UnloadTexture(wm.texture);
	UnloadTexture(settings.sprite);
	UnloadTexture(wm.flame->atlas);
	UnloadMusicStream(music);
	UnloadSound(wm.flame->fx);
	CloseWindow();
}
