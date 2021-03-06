#include "cub3d.h"
extern int 	**worldMap;
extern int	mlen;
extern int	**textures;
extern double	*Zbuffer;
extern char	**tex_tab;
extern t_data	tex_list;
extern int  alloc_check[5];


int		free_all_bmp_fail(t_vars *vars)
{
	free_tex_list(&tex_list, vars);
	free_int_tab(&worldMap, mlen);
	free_int_tab(&textures, 5);
	ft_freetab(&tex_tab);
	free_sprites(vars->sprite_list);
	free(Zbuffer);
    error_quit("Error: malloc error", NULL);
	return (-1);
}

int     free_tab_ret(char ***tab)
{
    ft_freetab(tab);
    return (-1);
}

int	    custom_freetab(char ***tab)
{
	int i;

	i = ft_tablen(*tab);
	while (--i >= 0)
    {
        if (alloc_check[i] == 1)
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
	ft_printf("tablen : %d\n", i);
	while (--i >= 0)
	{
		ft_printf("tab[%d] : %s\n", i, (*tab)[i]);
		ft_strdel(&((*tab)[i]));
	}
	free(*tab);
	tab = NULL;
}

int	    free_int_ret(int ***tab, int len)
{
	free_int_tab(tab, len);
	return (-1);
}