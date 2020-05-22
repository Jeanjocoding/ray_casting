#include "cub3d.h"

int		**g_textures;
t_data	g_tex_list;
char	**g_tex_tab;

char	**add_tex_sprite(char *tex_sprite)
{
	if (!(g_tex_tab[4] = ft_strdup(tex_sprite)))
		return (NULL);
	return (g_tex_tab);
}

char	**add_tex_num(char *path, int num)
{
	if (!(g_tex_tab[num] = ft_strdup(path)))
		return (NULL);
	return (g_tex_tab);
}

t_data	*create_tex_node(t_data *g_tex_list, t_vars *vars, int i)
{
	int addr_width;
	int	*temp_addr;

	temp_addr = (int*)mlx_get_data_addr(g_tex_list->img,
			&(g_tex_list->bits_per_pixel),
		&(g_tex_list->line_length), &(g_tex_list->endian));
	addr_width = g_tex_list->img_width * 4 * g_tex_list->img_height;
	if (!(g_textures[i] = (int*)malloc(sizeof(int) * addr_width + 1)))
		return (free_int_tex_nl(&g_textures, i - 1, g_tex_list, vars));
	g_tex_list->int_ptr = g_textures[i];
	ft_memcpy(g_textures[i], temp_addr, addr_width);
	if (!(g_tex_list->next = (t_data*)malloc(sizeof(t_data))))
		return (free_int_tex_nl(&g_textures, i, g_tex_list, vars));
	g_tex_list->next->first = g_tex_list->first;
	g_tex_list = g_tex_list->next;
	return (g_tex_list);
}

int		init_tex(char **tab, void *mlx, t_data *g_tex_list, t_vars *vars)
{
	int i;

	i = 0;
	if (!(g_textures = (int**)malloc(sizeof(int*) * 5)))
		return (-1);
	g_tex_list->first = g_tex_list;
	g_tex_list->img = NULL;
	while (i < 5)
	{
		if (!(g_tex_list->img = mlx_xpm_file_to_image(mlx, tab[i],
			&(g_tex_list->img_width), &(g_tex_list->img_height))))
			return (free_int_tex(&g_textures, i - 1, g_tex_list, vars));
		if (!(g_tex_list = create_tex_node(g_tex_list, vars, i)))
			return (-1);
		i++;
	}
	g_textures[4] = 0;
	return (1);
}
