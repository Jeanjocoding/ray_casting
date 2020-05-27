#include "cub3d.h"

extern int	g_pos_check;
extern int	**g_worldmap;

int		set_fov_north(t_fov *fov)
{
	fov->dirx = 0;
	fov->diry = 1;
	fov->planex = 0.66;
	fov->planey = 0;
	fov->time = 0;
	fov->oldTime = 0;
	return (0);
}

int		set_fov_south(t_fov *fov)
{
	fov->dirx = 0;
	fov->diry = -1;
	fov->planex = -0.66;
	fov->planey = 0;
	fov->time = 0;
	fov->oldTime = 0;
	return (0);
}

int		set_fov_east(t_fov *fov)
{
	fov->dirx = 1;
	fov->diry = 0;
	fov->planex = 0;
	fov->planey = -0.66;
	fov->time = 0;
	fov->oldTime = 0;
	return (0);
}

int		set_fov_west(t_fov *fov)
{
	fov->dirx = -1;
	fov->diry = 0;
	fov->planex = 0;
	fov->planey = 0.66;
	fov->time = 0;
	fov->oldTime = 0;
	return (0);
}

int		set_fov(char c, t_fov *fov, int x, int y)
{
	if (g_pos_check > 0)
		return (-1);
	if (c == 'N')
		set_fov_north(fov);
	if (c == 'S')
		set_fov_south(fov);
	if (c == 'E')
		set_fov_east(fov);
	if (c == 'W')
		set_fov_west(fov);
	fov->posx = (double)x * 1.0 + 0.5;
	fov->posy = (double)y * 1.0 + 0.5;
	g_worldmap[x][y] = 0;
	return (0);
}
