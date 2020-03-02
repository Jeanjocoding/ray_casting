#include "minilibx_opengl_20191021/mlx.h"
#include "libft.h"
#include "lodev.h"
#include "keys.h"

extern int	worldMap[24][24];
extern int	screenHeight;
extern int	screenWidth;

void	rotate_left(t_fov *fov)
{
	double	rot_speed;
	double	oldDirX;
      	double	oldPlaneX;

	rot_speed = 0.05;
	oldDirX = fov->dirX;
	oldPlaneX = fov->planeX;
	fov->dirX = fov->dirX * cos(-rot_speed) - fov->dirY * sin(-rot_speed);
      	fov->dirY = oldDirX * sin(-rot_speed) + fov->dirY * cos(-rot_speed);
	fov->planeX = fov->planeX * cos(-rot_speed) - fov->planeY * sin(-rot_speed);
	fov->planeY = oldPlaneX * sin(-rot_speed) + fov->planeY * cos(-rot_speed);
}

void	rotate_right(t_fov *fov)
{
	double	rot_speed;
	double	oldDirX;
      	double	oldPlaneX;

	rot_speed = 0.05;
	oldDirX = fov->dirX;
	oldPlaneX = fov->planeX;
	fov->dirX = fov->dirX * cos(rot_speed) - fov->dirY * sin(rot_speed);
      	fov->dirY = oldDirX * sin(rot_speed) + fov->dirY * cos(rot_speed);
	fov->planeX = fov->planeX * cos(rot_speed) - fov->planeY * sin(rot_speed);
	fov->planeY = oldPlaneX * sin(rot_speed) + fov->planeY * cos(rot_speed);
}
