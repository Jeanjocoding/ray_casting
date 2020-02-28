#include "libft.h"
#include "lodev.h"

int	mapWidth = 24;
int 	mapHeight = 24;
int 	screenWidth = 640;
int 	screenHeight = 480;

/*typedef	struct	s_ray
{
	double cameraX;
	double cameraY;
	double rayDirX;
	double rayDirY;
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
*/
int worldMap[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

t_ray	initialize_ray(t_ray *ray)
{
	ray->cameraX = 0;
	ray->rayDirX = 0;
	ray->rayDirY = 0;
	ray->sideDistX = 0;
	ray->sideDistY = 0;
	ray->deltaDistX = 0;
	ray->deltaDistY = 0;
	ray->stepX = 0;
	ray->stepY = 0;
	ray->mapX = 0;
	ray->mapY = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->wallDist = 0;
	return (*ray);
}


void	get_steps_sides(t_ray *ray, t_fov *fov)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (fov->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - fov->posX) * ray->deltaDistX;
	}

	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (fov->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - fov->posY) * ray->deltaDistY;
	}
}

t_ray	*get_ray_info(int x, t_fov *fov, t_ray *ray) 
{
	ray->cameraX = 2 * x / (double)screenWidth - 1;
	ray->rayDirX = fov->dirX + fov->planeX * ray->cameraX;
	ray->rayDirY = fov->dirY + fov->planeY * ray->cameraX;
	ray->mapX = (int)fov->posX;
	ray->mapY = (int)fov->posY;
	ray->deltaDistX = sqrt(1 + (ray->rayDirY * ray->rayDirY) / (ray->rayDirX * ray->rayDirX));
	ray->deltaDistY = sqrt(1 + (ray->rayDirX * ray->rayDirX) / (ray->rayDirY * ray->rayDirY));
	get_steps_sides(ray, fov);
	return (ray);
}



int	main(void)
{
	t_fov	fov;
	t_ray	ray;

	fov.posX = 22.4;
	fov.posY = 12.2;
	fov.dirX = -1;
	fov.dirY = 0;
	fov.planeX = 0;
	fov.planeY = 0.66;
	fov.time = 0;
	fov.oldTime = 0;

	ray = initialize_ray(&ray);
	print_ray(&ray);
	print_fov(&fov);
	get_ray_info(0, &fov, &ray);
	print_ray(&ray);
	return (0);
}
