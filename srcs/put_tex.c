#include "cub3d.h"

extern int	g_screenwidth;
extern int	g_screenheight;
extern int	**g_textures;
extern char	**g_tex_tab;
extern char	g_tex_list;

int		get_texx(t_ray *ray, t_data *tex_img)
{
	int texx;

	texx = (int)(ray->wallx * (double)(tex_img->img_width));
	return (texx);
}

void	put_tex_column(int tex_coor[2], t_data *main_img,
		t_data *tex_img, t_ray *ray)
{
	double			step;
	double			texpos;
	int				y;
	int				*addr_t;
	unsigned int	color;

	step = 1.0 * tex_img->img_height / ray->lineheight;
	texpos = (ray->linebottom - g_screenheight / 2
		+ ray->lineheight / 2) * step;
	y = ray->linebottom;
	while (y < ray->linetop)
	{
		tex_coor[1] = (int)texpos;
		addr_t = tex_img->int_ptr + (tex_coor[1]
			* tex_img->img_width + tex_coor[0]);
		color = (int)(*addr_t);
		put_my_pixel(main_img, ray->screenx, y, color);
		texpos += step;
		y++;
	}
}

int		put_tex(t_vars *vars, t_data *main_img, t_data *g_tex_list)
{
	int		x;
	int		check;
	int		tex_coor[2];
	t_ray	ray;

	x = 0;
	check = -1;
	while (x < g_screenwidth)
	{
		ray = initialize_ray(&ray);
		get_ray_info(x, &vars->fov, &ray);
		put_floor_g_ceiling(main_img, x, &ray);
		if (ray.texnum != check)
			g_tex_list = get_right_tex(ray.texnum, g_tex_list);
		tex_coor[0] = get_texx(&ray, g_tex_list);
		put_tex_column(tex_coor, main_img, g_tex_list, &ray);
		check = ray.texnum;
		x++;
	}
	return (0);
}
