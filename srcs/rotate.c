#include "cub3d.h"
#include "keys.h"

extern int	g_screenheight;
extern int	g_screenwidth;

void	rotate_right(t_fov *fov)
{
	double	rot_speed;
	double	olddirx;
	double	oldplanex;

	rot_speed = 0.1;
	olddirx = fov->dirx;
	oldplanex = fov->planeX;
	fov->dirx = fov->dirx * cos(-rot_speed) - fov->diry * sin(-rot_speed);
	fov->diry = olddirx * sin(-rot_speed) + fov->diry * cos(-rot_speed);
	fov->planeX = fov->planeX * cos(-rot_speed) - fov->planeY * sin(-rot_speed);
	fov->planeY = oldplanex * sin(-rot_speed) + fov->planeY * cos(-rot_speed);
}

void	rotate_left(t_fov *fov)
{
	double	rot_speed;
	double	olddirx;
	double	oldplanex;

	rot_speed = 0.1;
	olddirx = fov->dirx;
	oldplanex = fov->planeX;
	fov->dirx = fov->dirx * cos(rot_speed) - fov->diry * sin(rot_speed);
	fov->diry = olddirx * sin(rot_speed) + fov->diry * cos(rot_speed);
	fov->planeX = fov->planeX * cos(rot_speed) - fov->planeY * sin(rot_speed);
	fov->planeY = oldplanex * sin(rot_speed) + fov->planeY * cos(rot_speed);
}
