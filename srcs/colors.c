#include "../includes/flappigeon.h"

Color colors[COLOR_NUMBER] = {
    {103, 194, 89, 255},
    {0, 255, 0, 255},
    {0, 0, 255, 255},
    {255, 255, 0, 255},
    {255, 0, 255, 255}
};

void	update_color(unsigned int score, Color *colors)
{
	int index = (score / 5) % COLOR_NUMBER;
	*colors = colors[index];
}
