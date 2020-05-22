#include "cub3d.h"
#include "keys.h"

extern int	**g_worldmap;

void	move_forward(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.3;
	if (g_worldmap[(int)(fov->posX + fov->dirX
			* movespeed)][(int)(fov->posY)] == 0)
		fov->posX += fov->dirX * movespeed;
	if (g_worldmap[(int)(fov->posX)]
			[(int)(fov->posY + fov->dirY * movespeed)] == 0)
		fov->posY += fov->dirY * movespeed;
}

void	move_backward(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.3;
	if (g_worldmap[(int)(fov->posX - fov->dirX * movespeed)]
		[(int)(fov->posY)] == 0)
		fov->posX -= fov->dirX * movespeed;
	if (g_worldmap[(int)(fov->posX)]
		[(int)(fov->posY - fov->dirY * movespeed)] == 0)
		fov->posY -= fov->dirY * movespeed;
}

void	move_right(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.3;
	if (g_worldmap[(int)(fov->posX + fov->planeX * movespeed)]
		[(int)(fov->posY)] == 0)
		fov->posX += fov->planeX * movespeed;
	if (g_worldmap[(int)(fov->posX)]
		[(int)(fov->posY + fov->planeY * movespeed)] == 0)
		fov->posY += fov->planeY * movespeed;
}

void	move_left(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.3;
	if (g_worldmap[(int)(fov->posX - fov->planeX * movespeed)]
		[(int)(fov->posY)] == 0)
		fov->posX -= fov->planeX * movespeed;
	if (g_worldmap[(int)(fov->posX)]
		[(int)(fov->posY - fov->planeY * movespeed)] == 0)
		fov->posY -= fov->planeY * movespeed;
}
