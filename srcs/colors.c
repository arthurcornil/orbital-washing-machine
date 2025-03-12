#include "../includes/owm.h"

Color colors[COLOR_NUMBER] = {
    {103, 194, 89, 255},
    {81, 111, 201, 255},
    {166, 109, 201, 255},
    {222, 75, 42, 255},
    {53, 219, 214, 255}
};

void	update_color(unsigned int score, Color *colors)
{
	int index = (score / 5) % COLOR_NUMBER;
	*colors = colors[index];
}
