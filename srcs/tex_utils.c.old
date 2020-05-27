#include "cub3d.h"

int		tex_chooser(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->rayDirX < 0)
			return (3);
		else
			return (2);
	}
	else
	{
		if (ray->rayDirY < 0)
			return (1);
		else
			return (0);
	}
}

t_data	*get_right_tex(int tex_num, t_data *g_tex_list)
{
	int i;

	i = -1;
	g_tex_list = g_tex_list->first;
	while (++i < tex_num)
		g_tex_list = g_tex_list->next;
	return (g_tex_list);
}
