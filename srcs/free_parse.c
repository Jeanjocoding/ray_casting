#include "cub3d.h"

extern int		**g_worldmap;
extern int		g_mlen;
extern int		**g_textures;
extern double	*g_zbuffer;
extern char		**g_tex_tab;
extern t_data	g_tex_list;
extern int		g_alloc_check[5];

int		free_all_bmp_fail(t_vars *vars)
{
	free_tex_list(&g_tex_list, vars);
	free_int_tab(&g_worldmap, g_mlen);
	free_int_tab(&g_textures, 5);
	ft_freetab(&g_tex_tab);
	free_sprites(vars->sprite_list);
	free(g_zbuffer);
	error_quit("Error: malloc error", NULL);
	return (-1);
}

int		free_tab_ret(char ***tab)
{
	ft_freetab(tab);
	return (-1);
}

int		custom_freetab(char ***tab)
{
	int i;

	i = ft_tablen(*tab);
	while (--i >= 0)
	{
		if (g_alloc_check[i] == 1)
			ft_strdel(&((*tab)[i]));
	}
	free(*tab);
	tab = NULL;
	return (-1);
}

void	classic_freetab(char ***tab)
{
	int i;

	i = ft_tablen(*tab);
	while (--i >= 0)
		ft_strdel(&((*tab)[i]));
	free(*tab);
	tab = NULL;
}

int		free_int_ret(int ***tab, int len)
{
	free_int_tab(tab, len);
	return (-1);
}
