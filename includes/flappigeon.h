#ifndef FLAPPIGEON_H
# define FLAPPIGEON_H

# include "raylib.h"

# define SCREEN_HEIGHT 800
# define SCREEN_WIDTH 800

typedef struct pigeon
{
	int	x;
	int	y;
	unsigned int score;
	void (*draw)(struct pigeon *);
}	pigeon;

void	init_pigeon(pigeon *pigeon);

#endif
