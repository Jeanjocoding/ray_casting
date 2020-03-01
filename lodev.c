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

t_ray	*launch_ray(t_ray *ray, t_fov *fov, int	worldMap[24][24])
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
		//	printf("mapx : %d, mapy : %d\n", ray->mapX, ray->mapY);
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
//			(*worldMap)[ray->mapX][ray->mapY] = -9;
			ray->side = 1;
		}
		if (worldMap[ray->mapX][ray->mapY] > 0)
			ray->hit = 1;
//		else 
//			worldMap[ray->mapX][ray->mapY] = -9;
	}
	return (ray);
}

t_ray	*get_wallDist_line(t_ray *ray, t_fov *fov)
{
	if (ray->side == 0)
		ray->wallDist = (ray->mapX - fov->posX + ((1 - ray->stepX) / 2)) / ray->rayDirX;
	else
		ray->wallDist = (ray->mapY - fov->posY + ((1 - ray->stepY) / 2)) / ray->rayDirY;
	ray->lineheight = (int)(screenHeight / ray->wallDist);
	ray->linebottom = (screenHeight / 2 ) - (ray->lineheight / 2);
	if (ray->linebottom < 0)
		ray->linebottom = 0;
	ray->linetop = ray->linebottom + ray->lineheight;
	if (ray->linetop > screenHeight)
		ray->linetop = screenHeight - 1;
	return (ray);
}

t_fov	initialize_fov(t_fov *fov, double posX, double posY)
{
	fov->posX = posX;
	fov->posY = posY;
	fov->dirX = 1;
	fov->dirY = 0;
	fov->planeX = 0;
	fov->planeY = 0.66;
	fov->time = 0;
	fov->oldTime = 0;
	return (*fov);
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
	launch_ray(ray, fov, worldMap);
	get_wallDist_line(ray, fov);
	return (ray);
}

/*int	main(void)
{
	t_fov	fov;
	t_ray	ray;

	fov.posX = 12;
	fov.posY = 12;
	fov.dirX = 1;
	fov.dirY = 0;
	fov.planeX = 0;
	fov.planeY = 0.66;
	fov.time = 0;
	fov.oldTime = 0;

	ray = initialize_ray(&ray);
	print_ray(&ray);
	print_fov(&fov);
	print_map(worldMap, 24, 24);
	get_ray_info(0, &fov, &ray);
	print_ray(&ray);
	print_map(worldMap, 24, 24);
	return (0);
}*/
