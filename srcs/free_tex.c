#include "cub3d.h"

int		free_int_tex(int ***tab, int len, t_data *tex_list, t_vars *vars)
{
	free_int_tab(tab, len);
	free_tex_list(tex_list, vars);
	return (-1);
}
