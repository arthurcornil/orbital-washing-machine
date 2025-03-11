#ifndef COLORS_H
# define COLORS_H

# include "flappigeon.h"

# define COLOR_CYCLE_COUNT 5  

extern Color playerColors[COLOR_CYCLE_COUNT];

void updateColors(int level, Color *playerColor, Color *wallColor);

# endif
