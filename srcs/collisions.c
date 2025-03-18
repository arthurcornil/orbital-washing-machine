#include "../includes/owm.h"

bool	check_collision(wm *wm, walls *walls)
{
	for (int i = 0; i < (walls->number); i ++)
	{
		DrawRectanglePro(
				(Rectangle){ 
					(float)SCREEN_WIDTH / 2 + (-sin(walls->collection[i].angle)),
					(float)SCREEN_HEIGHT / 2 - (-cos(walls->collection[i].angle)),
					20,
					(180 - walls->collection[i].gap_position - WALL_GAP_SIZE) * (walls->collection[i].grown_percentage / 100)
				},
				(Vector2){ 10, 0 },
				((walls->collection)[i].angle * 180 / M_PI) - 180,
				*g_colors
		);
	}
	return (false);
}
