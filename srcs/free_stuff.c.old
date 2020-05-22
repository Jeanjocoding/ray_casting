#include "cub3d.h"

extern int		**g_worldmap;
extern int		**g_textures;
extern double	*g_zbuffer;
extern char		**g_tex_tab;
extern int		g_mlen;
extern t_data	g_tex_list;

void	free_tex_list(t_data *list, t_vars *vars)
{
	t_data	*temp;
	int		i;

	i = 1;
	list = list->first;
	list = list->next;
	while (i < 5)
	{
		if (list == NULL || list->img == NULL)
			break ;
		temp = list->next;
		mlx_destroy_image(vars->mlx, list->img);
		free(list);
		list = temp;
		i++;
	}
	if (list)
		free(list);
}

int		free_all_parse_fail(char ***tab)
{
	ft_freetab(tab);
	error_quit("Error: malloc error", NULL);
	return (-1);
}

int		free_all_tex_fail(void)
{
	free_int_tab(&g_worldmap, g_mlen);
	ft_freetab(&g_tex_tab);
	error_quit("Error: Error while initializing g_textures", NULL);
	return (-1);
}

int		free_all_sprite_fail(t_vars *vars)
{
	free_tex_list(&g_tex_list, vars);
	free_int_tab(&g_worldmap, g_mlen);
	free_int_tab(&g_textures, 5);
	ft_freetab(&g_tex_tab);
	error_quit("Error: malloc error", NULL);
	return (-1);
}

int		free_all_zbuf_fail(t_vars *vars)
{
	free_tex_list(&g_tex_list, vars);
	free_int_tab(&g_worldmap, g_mlen);
	free_int_tab(&g_textures, 5);
	ft_freetab(&g_tex_tab);
	free_sprites(vars->sprite_list);
	error_quit("Error: malloc error", NULL);
	return (-1);
}
