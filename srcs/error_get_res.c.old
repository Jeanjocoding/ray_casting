#include "cub3d.h"

extern char	**g_tex_tab;
extern int	g_screenheight;
extern int	g_screenwidth;
extern int	**g_worldmap;

int		check_all_digit(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (-1);
		str++;
	}
	return (1);
}

int		error_quit(char *msg, char ***tab)
{
	ft_printf("%s\n", msg);
	if (tab != NULL)
		ft_freetab(tab);
	exit(1);
	return (1);
}

int		get_res(char ***tab)
{
	if (check_all_digit((*tab)[1]) == -1
		|| check_all_digit((*tab)[2]) == -1
		|| ft_tablen(*tab) != 3)
	{
		custom_freetab(&g_tex_tab);
		error_quit("error: invalid resolution format", tab);
	}
	g_screenwidth = ft_atoi((*tab)[1]);
	g_screenheight = ft_atoi((*tab)[2]);
	ft_freetab(tab);
	return (1);
}
