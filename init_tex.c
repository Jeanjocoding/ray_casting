#include "cub3d.h"

int		**textures;
t_data	tex_list;
char	**tex_tab;


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

t_data	*get_right_tex(int tex_num, t_data *tex_list)
{
	int i;

	i = -1;
	tex_list = tex_list->first;
	while (++i < tex_num)
		tex_list = tex_list->next;
	return (tex_list);
}

char	**add_tex_sprite(char *tex_sprite)
{
	if (!(tex_tab[4] = ft_strdup(tex_sprite)))
		return (NULL);
	return (tex_tab);
}

char	**add_tex_num(char *path, int num)
{ 
//	printf("path: %s\n", path);
	if (!(tex_tab[num] = ft_strdup(path)))
		return (NULL);
	return (tex_tab);
}

/*char	**get_tex_tab(char *texN, char *texS, char *texO, char *texE)
{
	if (!(tex_tab = ft_stabmaker(5)))
		return (NULL);
	if (!(tex_tab[0] = ft_strdup(texN)))
		return (NULL);
	if (!(tex_tab[1] = ft_strdup(texS)))
		return (NULL);
	if (!(tex_tab[2] = ft_strdup(texO)))
		return (NULL);
	if (!(tex_tab[3] = ft_strdup(texE)))
		return (NULL);
	return (tex_tab);
}*/


int		init_tex(char **tab, void *mlx, t_data *tex_list, t_vars *vars)
{
	int i;
	int	addr_width;
	int	*temp_addr;

	i = 0;
	if (!(textures = (int**)malloc(sizeof(int*) * 5)))
		return (-1);
//	if (!(tex_list = (t_data*)malloc(sizeof(t_data))))
//		return ((int**)0);
	tex_list->first = tex_list;
	tex_list->img = NULL;
	while (i < 5)
	{
		// faire check ici
//		ft_printf("tab : %s\n", tab[i]);
		if (!(tex_list->img = mlx_xpm_file_to_image(mlx, tab[i], &(tex_list->img_width), &(tex_list->img_height))))
			return (free_int_tex(&textures, i - 1, tex_list, vars));
		temp_addr = (int*)mlx_get_data_addr(tex_list->img, &(tex_list->bits_per_pixel), &(tex_list->line_length), &(tex_list->endian));
		addr_width = tex_list->img_width * 4 * tex_list->img_height;
		if (!(textures[i] = (int*)malloc(sizeof(int) * addr_width + 1)))
			return (free_int_tex(&textures, i - 1, tex_list, vars));
		tex_list->int_ptr = textures[i];
		ft_memcpy(textures[i], temp_addr, addr_width);
//		free(temp_addr);
		if (!(tex_list->next = (t_data*)malloc(sizeof(t_data))))
			return (free_int_tex(&textures, i, tex_list, vars));
		tex_list->next->first = tex_list->first;
		i++;
		tex_list = tex_list->next;
	}
	textures[4] = 0;
	return (1);
}
