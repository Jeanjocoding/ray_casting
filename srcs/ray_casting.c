#include "cub3d.h"

int				g_screenwidth = 640;
int				g_screenheight = 480;
double			*g_zbuffer;
extern double	g_add_to_pos;
int				**g_worldmap;

t_ray		initialize_ray(t_ray *ray)
{
	ray->screenX = 0;
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
	ray->wallX = 0;
	return (*ray);
}

void		get_steps_sides(t_ray *ray, t_fov *fov)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (fov->posx - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - fov->posx) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (fov->posy - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - fov->posy) * ray->deltaDistY;
	}
}

t_ray		*launch_ray(t_ray *ray, int **g_worldmap)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (g_worldmap[ray->mapX][ray->mapY] > 0
				&& g_worldmap[ray->mapX][ray->mapY] != 2)
			ray->hit = 1;
	}
	return (ray);
}

t_ray		*get_walldist_line(t_ray *ray, t_fov *fov)
{
	if (ray->side == 0)
		ray->wallDist = (ray->mapX - fov->posx
				+ ((1 - ray->stepX) / 2)) / ray->rayDirX;
	else
		ray->wallDist = (ray->mapY - fov->posy
				+ ((1 - ray->stepY) / 2)) / ray->rayDirY;
	ray->lineheight = (int)(g_screenheight / ray->wallDist);
	ray->linebottom = (g_screenheight / 2) - (ray->lineheight / 2);
	if (ray->linebottom < 0)
		ray->linebottom = 0;
	ray->linetop = ray->linebottom + ray->lineheight;
	if (ray->linetop > g_screenheight)
		ray->linetop = g_screenheight - 1;
	return (ray);
}

t_ray		*get_ray_info(int x, t_fov *fov, t_ray *ray)
{
	ray->screenX = x;
	ray->cameraX = 2 * x / (double)g_screenwidth - 1;
	ray->rayDirX = fov->dirx + fov->planeX * ray->cameraX;
	ray->rayDirY = fov->diry + fov->planeY * ray->cameraX;
	ray->mapX = (int)fov->posx;
	ray->mapY = (int)fov->posy;
	ray->deltaDistX = sqrt(1 + (ray->rayDirY * ray->rayDirY)
		/ (ray->rayDirX * ray->rayDirX));
	ray->deltaDistY = sqrt(1 + (ray->rayDirX * ray->rayDirX)
		/ (ray->rayDirY * ray->rayDirY));
	get_steps_sides(ray, fov);
	launch_ray(ray, g_worldmap);
	get_walldist_line(ray, fov);
	g_zbuffer[x] = (double)ray->wallDist + g_add_to_pos;
	if (ray->side == 0)
		ray->wallX = fov->posy + ray->wallDist * ray->rayDirY;
	else
		ray->wallX = fov->posx + ray->wallDist * ray->rayDirX;
	ray->wallX -= (int)(ray->wallX);
	ray->fov = fov;
	ray->texnum = tex_chooser(ray);
	return (ray);
}
