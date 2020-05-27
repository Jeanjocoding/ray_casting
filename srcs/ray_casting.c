#include "cub3d.h"

int				g_screenwidth = 640;
int				g_screenheight = 480;
double			*g_zbuffer;
extern double	g_add_to_pos;
int				**g_worldmap;

t_ray		initialize_ray(t_ray *ray)
{
	ray->screenx = 0;
	ray->camerax = 0;
	ray->raydirx = 0;
	ray->raydiry = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->deltaDistX = 0;
	ray->deltadisty = 0;
	ray->stepx = 0;
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
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (fov->posx - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapX + 1.0 - fov->posx) * ray->deltaDistX;
	}
	if (ray->raydiry < 0)
	{
		ray->stepY = -1;
		ray->sidedisty = (fov->posy - ray->mapY) * ray->deltadisty;
	}
	else
	{
		ray->stepY = 1;
		ray->sidedisty = (ray->mapY + 1.0 - fov->posy) * ray->deltadisty;
	}
}

t_ray		*launch_ray(t_ray *ray, int **g_worldmap)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltaDistX;
			ray->mapX += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
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
				+ ((1 - ray->stepx) / 2)) / ray->raydirx;
	else
		ray->wallDist = (ray->mapY - fov->posy
				+ ((1 - ray->stepY) / 2)) / ray->raydiry;
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
	ray->screenx = x;
	ray->camerax = 2 * x / (double)g_screenwidth - 1;
	ray->raydirx = fov->dirx + fov->planex * ray->camerax;
	ray->raydiry = fov->diry + fov->planey * ray->camerax;
	ray->mapX = (int)fov->posx;
	ray->mapY = (int)fov->posy;
	ray->deltaDistX = sqrt(1 + (ray->raydiry * ray->raydiry)
		/ (ray->raydirx * ray->raydirx));
	ray->deltadisty = sqrt(1 + (ray->raydirx * ray->raydirx)
		/ (ray->raydiry * ray->raydiry));
	get_steps_sides(ray, fov);
	launch_ray(ray, g_worldmap);
	get_walldist_line(ray, fov);
	g_zbuffer[x] = (double)ray->wallDist + g_add_to_pos;
	if (ray->side == 0)
		ray->wallX = fov->posy + ray->wallDist * ray->raydiry;
	else
		ray->wallX = fov->posx + ray->wallDist * ray->raydirx;
	ray->wallX -= (int)(ray->wallX);
	ray->fov = fov;
	ray->texnum = tex_chooser(ray);
	return (ray);
}
