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
	olddirx = fov->dirX;
	oldplanex = fov->planeX;
	fov->dirX = fov->dirX * cos(-rot_speed) - fov->dirY * sin(-rot_speed);
	fov->dirY = olddirx * sin(-rot_speed) + fov->dirY * cos(-rot_speed);
	fov->planeX = fov->planeX * cos(-rot_speed) - fov->planeY * sin(-rot_speed);
	fov->planeY = oldplanex * sin(-rot_speed) + fov->planeY * cos(-rot_speed);
}

void	rotate_left(t_fov *fov)
{
	double	rot_speed;
	double	olddirx;
	double	oldplanex;

	rot_speed = 0.1;
	olddirx = fov->dirX;
	oldplanex = fov->planeX;
	fov->dirX = fov->dirX * cos(rot_speed) - fov->dirY * sin(rot_speed);
	fov->dirY = olddirx * sin(rot_speed) + fov->dirY * cos(rot_speed);
	fov->planeX = fov->planeX * cos(rot_speed) - fov->planeY * sin(rot_speed);
	fov->planeY = oldplanex * sin(rot_speed) + fov->planeY * cos(rot_speed);
}
