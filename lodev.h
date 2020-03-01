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
	int	lineheight;
	int	linebottom;
	int	linetop;
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

typedef struct	s_line
{
	int	lineheight;
	int	bottom;
	int	top;
}		t_line;

void 	print_ray(t_ray *ray);
void 	print_fov(t_fov *fov);
void	print_map(int map[24][24], int lenx, int leny);
t_fov	initialize_fov(t_fov *fov, double posX, double posY);
t_ray	initialize_ray(t_ray *ray);
t_ray	*get_ray_info(int x, t_fov *fov, t_ray *ray); 

#endif
