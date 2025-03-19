#include "../includes/owm.h"

void	draw_middle_circle(wm *wm)
{
		DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 70, *g_colors);
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
	int padding = SCREEN_WIDTH - SETTINGS_ICON_WIDTH - 20;
	settings->sprite = LoadTexture("assets/settings_sprite.png");
	settings->buttons[0] = (Rectangle){ padding - 40, 20, SETTINGS_ICON_WIDTH, SETTINGS_ICON_HEIGHT };
	settings->buttons[1] = (Rectangle){ padding, 20, SETTINGS_ICON_WIDTH, SETTINGS_ICON_HEIGHT };
}

void	draw_settings(settings *settings)
{
	Rectangle source = (Rectangle){SETTINGS_ICON_WIDTH, 0, SETTINGS_ICON_WIDTH, SETTINGS_ICON_HEIGHT};
	for (int i = 0; i < 2; i ++)
	{
		DrawTextureRec(settings->sprite, source, (Vector2){ settings->buttons[i].x, settings->buttons[i].y }, WHITE);
		source.x += SETTINGS_ICON_WIDTH;
	}
}

int	main(void)
{
	wm			wm;
	walls		walls;
	settings	settings;
	Music		music;
	game		game;

	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Orbital Washing Machine");
	InitAudioDevice();
	SetTargetFPS(60);

	init_wm(&wm);
	init_walls(&walls);
	init_settings(&settings);
	game.is_music_playing = true;
	game.is_fx_playing = true;
	music = LoadMusicStream("assets/music.wav");

	PlayMusicStream(music);
	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_SPACE))
		{
			if (!game.is_playing)
				game.is_playing = true;
			propel(&wm, game.is_fx_playing);
		}
		else if (wm.is_propelling)
		{
			wm.is_propelling = false;
			StopSound(wm.flame->fx);
		}

		//TODO: Use collision checker
		if (game.is_playing)
		{
			update_color(wm.score, g_colors);
			update_wm(&wm, &walls);
			update_walls(&walls);
		}
		for (int i = 0; i < 2; i ++)
		{
			if (CheckCollisionPointRec(GetMousePosition(), settings.buttons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				switch (i) {
					case 0:
						game.is_music_playing = !game.is_music_playing;
						break ;
					case 1:
						game.is_fx_playing = !game.is_fx_playing;
						break ;
				}
			}
		}
		if (game.is_music_playing)
			UpdateMusicStream(music);

		BeginDrawing();
		draw_settings(&settings);
		DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 250, (Color){2, 12, 28, 255});
		DrawRectangle(SCREEN_WIDTH / 2 - 2, SCREEN_HEIGHT / 2 - 250, 4, 250, (Color){255, 255, 255, 20});
		draw_walls(&walls);
		draw_wm(&wm);
		draw_middle_circle(&wm);
		ClearBackground(*g_colors);
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
