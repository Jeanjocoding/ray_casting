#ifndef LODEV_H
# define LODEV_H

#include <math.h>

typedef	struct	s_ray
{
	double cameraX;
//	double cameraY;
	double rayDirX;
	double rayDirY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double stepX;
	double stepY;
	int	mapX;
	int	mapY;
	int	hit;
	int	side;
	double wallDist;
}		t_ray;

typedef	struct	s_fov
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double time;
	double oldTime;
}		t_fov;



void 	print_ray(t_ray *ray);
void 	print_fov(t_fov *fov);

#endif
