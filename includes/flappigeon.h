#ifndef FLAPPIGEON_H
# define FLAPPIGEON_H

# include "raylib.h"
# include <math.h>
# include <stdio.h>

# define SCREEN_HEIGHT 800
# define SCREEN_WIDTH 800
# define COLOR_NUMBER 5

typedef struct pigeon
{
	Vector2 position;
	unsigned int score;
	float angle;
	float speed;
	void (*draw)(struct pigeon *);
	void (*update)(struct pigeon *);
}	pigeon;

void	init_pigeon(pigeon *pigeon);
void	update_color(unsigned int score, Color *colors);

extern Color colors[COLOR_NUMBER];

#endif
