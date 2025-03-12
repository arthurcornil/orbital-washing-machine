#ifndef FLAPPIGEON_H
# define FLAPPIGEON_H

# include "raylib.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define SCREEN_HEIGHT 800
# define SCREEN_WIDTH 800
# define COLOR_NUMBER 5
# define WALL_GAP_SIZE 60

typedef struct pigeon
{
	Vector2 position;
	unsigned int score;
	float angle;
	float speed;
	int radius;
	void (*draw)(struct pigeon *);
	void (*update)(struct pigeon *);
}	pigeon;

typedef struct wall
{
	float angle;
	unsigned int gap_position;
}	wall;

typedef struct walls
{
	wall collection[20];
	unsigned int number;
	float speed;
	void (*draw)(struct walls *);
	void (*update)(struct walls *);
}	walls;

void	init_pigeon(pigeon *pigeon);
void	init_walls(walls *walls);
void	update_color(unsigned int score, Color *colors);

extern Color colors[COLOR_NUMBER];

#endif
