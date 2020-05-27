#include "cub3d.h"

extern char	**g_tex_tab;
extern int	g_screenheight;
extern int	g_screenwidth;
extern int	**g_worldmap;
extern int	g_mlen;
extern int	g_mheight;
int			g_alloc_check[5];

int		func_utils(char ***tab)
{
	if (ft_strcmp((*tab)[0], "R") == 0)
		return (get_res(tab));
	if (ft_strcmp((*tab)[0], "NO") == 0)
		return (get_north(tab));
	if (ft_strcmp((*tab)[0], "SO") == 0)
		return (get_south(tab));
	if (ft_strcmp((*tab)[0], "WE") == 0)
		return (get_west(tab));
	if (ft_strcmp((*tab)[0], "EA") == 0)
		return (get_east(tab));
	if (ft_strcmp((*tab)[0], "S") == 0)
		return (get_sprite(tab));
	if (ft_strcmp((*tab)[0], "F") == 0)
		return (get_floor(tab));
	if (ft_strcmp((*tab)[0], "C") == 0)
		return (get_g_ceiling(tab));
	return (-2);
}

int		get_right_func(char **line, char ***full_tab, int i, t_fov *fov)
{
	char	**tab;
	int		ret;
	int		ret2;

	if (*line == NULL || (*line)[0] == '\0'
		|| (ft_strlen(*line) == 1 && (*line)[0] == ' '))
		return (0);
	if (!(tab = ft_split(*line, ' ')))
		return (-1);
	if ((ret = func_utils(&tab)) != -2)
		return (ret);
	if ((ret2 = check_first_map(line)) == 1)
	{
		ft_freetab(&tab);
		return (set_map(*full_tab, i, fov));
	}
	if (ret2 == -1)
	{
		ft_freetab(&tab);
		ft_freetab(full_tab);
		error_quit("Error: wrong map formatting", NULL);
	}
	ft_freetab(&tab);
	return (0);
}

void	allocarray_set(int dst[5], int nbr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = nbr;
		i++;
	}
}

int		parse_master(int fd, t_fov *fov)
{
	int		ret;
	int		i;
	int		tablen;
	char	**tab;

	if (!(tab = get_cub_tab(fd)))
		return (-1);
	allocarray_set(g_alloc_check, 0, 5);
	tablen = ft_tablen(tab);
	i = 0;
	while (i < tablen)
	{
		ret = get_right_func(&(tab[i]), &tab, i, fov);
		if (ret == -1)
			free_tab_ret(&tab);
		if (ret == 3)
		{
			ft_freetab(&tab);
			return (1);
		}
		i++;
	}
	ft_freetab(&tab);
	return (1);
}
