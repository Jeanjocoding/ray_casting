#include "cub3d.h"
#include "keys.h"

extern int	**g_worldmap;

void	move_forward(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.3;
	if (g_worldmap[(int)(fov->posx + fov->dirx
			* movespeed)][(int)(fov->posy)] == 0)
		fov->posx += fov->dirx * movespeed;
	if (g_worldmap[(int)(fov->posx)]
			[(int)(fov->posy + fov->diry * movespeed)] == 0)
		fov->posy += fov->diry * movespeed;
}

void	move_backward(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.3;
	if (g_worldmap[(int)(fov->posx - fov->dirx * movespeed)]
		[(int)(fov->posy)] == 0)
		fov->posx -= fov->dirx * movespeed;
	if (g_worldmap[(int)(fov->posx)]
		[(int)(fov->posy - fov->diry * movespeed)] == 0)
		fov->posy -= fov->diry * movespeed;
}

void	move_right(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.3;
	if (g_worldmap[(int)(fov->posx + fov->planex * movespeed)]
		[(int)(fov->posy)] == 0)
		fov->posx += fov->planex * movespeed;
	if (g_worldmap[(int)(fov->posx)]
		[(int)(fov->posy + fov->planey * movespeed)] == 0)
		fov->posy += fov->planey * movespeed;
}

void	move_left(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.3;
	if (g_worldmap[(int)(fov->posx - fov->planex * movespeed)]
		[(int)(fov->posy)] == 0)
		fov->posx -= fov->planex * movespeed;
	if (g_worldmap[(int)(fov->posx)]
		[(int)(fov->posy - fov->planey * movespeed)] == 0)
		fov->posy -= fov->planey * movespeed;
}
