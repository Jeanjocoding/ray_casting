#include "cub3d.h"

extern int	g_pos_check;
extern int	**g_worldmap;

int		set_fov_north(t_fov *fov)
{
	fov->dirX = 0;
	fov->dirY = 1;
	fov->planeX = 0.66;
	fov->planeY = 0;
	fov->time = 0;
	fov->oldTime = 0;
	return (0);
}

int		set_fov_south(t_fov *fov)
{
	fov->dirX = 0;
	fov->dirY = -1;
	fov->planeX = -0.66;
	fov->planeY = 0;
	fov->time = 0;
	fov->oldTime = 0;
	return (0);
}

int		set_fov_east(t_fov *fov)
{
	fov->dirX = 1;
	fov->dirY = 0;
	fov->planeX = 0;
	fov->planeY = -0.66;
	fov->time = 0;
	fov->oldTime = 0;
	return (0);
}

int		set_fov_west(t_fov *fov)
{
	fov->dirX = -1;
	fov->dirY = 0;
	fov->planeX = 0;
	fov->planeY = 0.66;
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
