#include "cub3d.h"

extern int **g_worldmap;
extern int g_mlen;
extern int g_mheight;
extern int g_pos_check;

int		get_right_char_first(char c, int x, int y)
{
	if (c == '1')
		g_worldmap[x][y] = 1;
	else if (c != ' ')
	{
		free_int_tab(&g_worldmap, g_mlen);
		error_quit("Error : invalid map", NULL);
	}
	return (0);
}

int		get_right_char_mid(char c, int x, int y, t_fov *fov)
{
	if (c == '1')
		g_worldmap[x][y] = 1;
	else if (c == '0' || c == '2')
	{
		g_worldmap[x][y] = c - '0';
	}
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (set_fov(c, fov, x, y) == -1)
		{
			free_int_tab(&g_worldmap, g_mlen);
			error_quit("Error : two different initial positions", NULL);
		}
		g_worldmap[x][y] = 0;
	}
	else if (c != ' ')
	{
		free_int_tab(&g_worldmap, g_mlen);
		error_quit("Error : invalid map, uknown object number", NULL);
	}
	return (0);
}
