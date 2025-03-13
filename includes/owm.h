#ifndef OWM_H
# define OWM_H

# include "raylib.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SCREEN_HEIGHT 800
# define SCREEN_WIDTH 800
# define GRAVITY 0.2f
# define COLOR_NUMBER 5
# define WALL_GAP_SIZE 60
# define SETTINGS_ICON_WIDTH 23
# define SETTINGS_ICON_HEIGHT 25
# define ANIMATION_FPS 24

typedef struct wall
{
	float angle;
	float gap_position;
	float grown_percentage;
	bool going_up;
}	wall;

typedef struct walls
{
	wall collection[20];
	unsigned int number;
	float speed;
	bool grown;
	bool must_hide;
	void (*draw)(struct walls *);
	void (*update)(struct walls *);
}	walls;

typedef struct flame
{
	Texture2D atlas;
	Rectangle frames[6];
	void (*show)(struct flame *);
}	flame;

typedef struct wm
{
	Vector2 position;
	unsigned int score;
	float angle;
	float speed;
	int radius;
	float acceleration;
	Texture2D texture;
	flame *flame;
	bool is_propelling;
	void (*draw)(struct wm *);
	void (*update)(struct wm *, walls *);
	void (*propel)(struct wm *);
	void (*show_flame)(struct wm *);
}	wm;

typedef struct settings
{
	Texture2D sprite;
	void (*play);
	void (*toggle_music);
	void (*toggle_fx);
}	settings;

void	init_wm(wm *wm);
void	init_walls(walls *walls);
void	update_color(unsigned int score, Color *colors);

extern Color colors[COLOR_NUMBER];

#endif
