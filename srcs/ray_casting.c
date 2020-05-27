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
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->mapx = 0;
	ray->mapy = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->walldist = 0;
	ray->wallx = 0;
	return (*ray);
}

void		get_steps_sides(t_ray *ray, t_fov *fov)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (fov->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - fov->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (fov->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - fov->posy) * ray->deltadisty;
	}
}

t_ray		*launch_ray(t_ray *ray, int **g_worldmap)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (g_worldmap[ray->mapx][ray->mapy] > 0
				&& g_worldmap[ray->mapx][ray->mapy] != 2)
			ray->hit = 1;
	}
	return (ray);
}

t_ray		*get_walldist_line(t_ray *ray, t_fov *fov)
{
	if (ray->side == 0)
		ray->walldist = (ray->mapx - fov->posx
				+ ((1 - ray->stepx) / 2)) / ray->raydirx;
	else
		ray->walldist = (ray->mapy - fov->posy
				+ ((1 - ray->stepy) / 2)) / ray->raydiry;
	ray->lineheight = (int)(g_screenheight / ray->walldist);
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
	ray->mapx = (int)fov->posx;
	ray->mapy = (int)fov->posy;
	ray->deltadistx = sqrt(1 + (ray->raydiry * ray->raydiry)
		/ (ray->raydirx * ray->raydirx));
	ray->deltadisty = sqrt(1 + (ray->raydirx * ray->raydirx)
		/ (ray->raydiry * ray->raydiry));
	get_steps_sides(ray, fov);
	launch_ray(ray, g_worldmap);
	get_walldist_line(ray, fov);
	g_zbuffer[x] = (double)ray->walldist + g_add_to_pos;
	if (ray->side == 0)
		ray->wallx = fov->posy + ray->walldist * ray->raydiry;
	else
		ray->wallx = fov->posx + ray->walldist * ray->raydirx;
	ray->wallx -= (int)(ray->wallx);
	ray->fov = fov;
	ray->texnum = tex_chooser(ray);
	return (ray);
}
