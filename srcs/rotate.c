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
	oldplanex = fov->planex;
	fov->dirx = fov->dirx * cos(-rot_speed) - fov->diry * sin(-rot_speed);
	fov->diry = olddirx * sin(-rot_speed) + fov->diry * cos(-rot_speed);
	fov->planex = fov->planex * cos(-rot_speed) - fov->planey * sin(-rot_speed);
	fov->planey = oldplanex * sin(-rot_speed) + fov->planey * cos(-rot_speed);
}

void	rotate_left(t_fov *fov)
{
	double	rot_speed;
	double	olddirx;
	double	oldplanex;

	rot_speed = 0.1;
	olddirx = fov->dirx;
	oldplanex = fov->planex;
	fov->dirx = fov->dirx * cos(rot_speed) - fov->diry * sin(rot_speed);
	fov->diry = olddirx * sin(rot_speed) + fov->diry * cos(rot_speed);
	fov->planex = fov->planex * cos(rot_speed) - fov->planey * sin(rot_speed);
	fov->planey = oldplanex * sin(rot_speed) + fov->planey * cos(rot_speed);
}
