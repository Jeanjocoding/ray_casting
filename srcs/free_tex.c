#include "cub3d.h"

int		free_int_tex(int ***tab, int len, t_data *g_tex_list, t_vars *vars)
{
	free_int_tab(tab, len);
	free_tex_list(g_tex_list, vars);
	return (-1);
}

void	*free_int_tex_nl(int ***tab, int len, t_data *g_tex_list, t_vars *vars)
{
	free_int_tab(tab, len);
	free_tex_list(g_tex_list, vars);
	return (NULL);
}
