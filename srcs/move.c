#include "cub3d.h"
#include "keys.h"

extern int	**g_worldmap;

void	move_forward(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.3;
	if (g_worldmap[(int)(fov->posx + fov->dirX
			* movespeed)][(int)(fov->posy)] == 0)
		fov->posx += fov->dirX * movespeed;
	if (g_worldmap[(int)(fov->posx)]
			[(int)(fov->posy + fov->dirY * movespeed)] == 0)
		fov->posy += fov->dirY * movespeed;
}

void	move_backward(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.3;
	if (g_worldmap[(int)(fov->posx - fov->dirX * movespeed)]
		[(int)(fov->posy)] == 0)
		fov->posx -= fov->dirX * movespeed;
	if (g_worldmap[(int)(fov->posx)]
		[(int)(fov->posy - fov->dirY * movespeed)] == 0)
		fov->posy -= fov->dirY * movespeed;
}

void	move_right(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.3;
	if (g_worldmap[(int)(fov->posx + fov->planeX * movespeed)]
		[(int)(fov->posy)] == 0)
		fov->posx += fov->planeX * movespeed;
	if (g_worldmap[(int)(fov->posx)]
		[(int)(fov->posy + fov->planeY * movespeed)] == 0)
		fov->posy += fov->planeY * movespeed;
}

void	move_left(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.3;
	if (g_worldmap[(int)(fov->posx - fov->planeX * movespeed)]
		[(int)(fov->posy)] == 0)
		fov->posx -= fov->planeX * movespeed;
	if (g_worldmap[(int)(fov->posx)]
		[(int)(fov->posy - fov->planeY * movespeed)] == 0)
		fov->posy -= fov->planeY * movespeed;
}
