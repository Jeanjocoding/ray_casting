#include "cub3d.h"

extern int		g_ground;
extern int		g_ceiling;
extern int		g_screenheight;

void		intarray_set(int dst[400], int nbr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = nbr;
		i++;
	}
}

int			check_cub(char *path)
{
	int	len;

	len = ft_strlen(path);
	len--;
	if (path[len] != 'b' || path[len - 1] != 'u' || path[len - 2] != 'c'
		|| path[len - 3] != '.')
		error_quit("Error: invalid configuration file", NULL);
	return (-1);
}

void		put_my_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		put_floor_g_ceiling(t_data *data, int x, t_ray *ray)
{
	int y;

	y = 0;
	while (y < ray->linebottom)
	{
		put_my_pixel(data, x, y, g_ceiling);
		y++;
	}
	y = ray->linetop;
	while (y < g_screenheight)
	{
		put_my_pixel(data, x, y, g_ground);
		y++;
	}
}
