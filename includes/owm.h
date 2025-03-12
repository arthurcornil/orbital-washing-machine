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

typedef struct wm
{
	Vector2 position;
	unsigned int score;
	float angle;
	float speed;
	int radius;
	float acceleration;
	Texture2D texture;
	void (*draw)(struct wm *);
	void (*update)(struct wm *, walls *);
	void (*propel)(struct wm *);
}	wm;

void	init_wm(wm *wm);
void	init_walls(walls *walls);
void	update_color(unsigned int score, Color *colors);

extern Color colors[COLOR_NUMBER];

#endif
