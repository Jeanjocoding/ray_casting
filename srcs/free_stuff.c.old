#include "cub3d.h"

extern int 	**g_worldmap;
extern int	**textures;
extern double	*Zbuffer;
extern char	**g_tex_tab;
extern int  g_mlen;
extern t_data	g_tex_list;

void	free_tex_list(t_data *list, t_vars *vars)
{
	t_data *temp;
	int	 i;

	i = 1;
	list = list->first;
	list = list->next;
	
	while (i < 5)
	{
		if (list == NULL || list->img == NULL)
			break;
		temp = list->next;
		mlx_destroy_image(vars->mlx, list->img);
//		ft_printf("int ptr : %d\n", list->int_ptr[0]);
//		if (list->int_ptr[0] > 0)

		free(list);
		list = temp;
		i++;
	}
	if (list)
		free(list);
}

void	free_sprites(t_sprites *sprites)
{
	t_sprites   *temp;

	while (sprites->prev != NULL)
		sprites = sprites->prev;
	while (sprites->next != NULL)
	{
		temp = sprites->next;
		free(sprites);
		sprites = NULL;
		sprites = temp;
	}
	free(sprites);
	sprites = NULL;
}

int		free_all_parse_fail(char ***tab)
{
//	free_tex_list(&g_tex_list, vars);
//	free_int_tab(&g_worldmap, g_mlen);
//	free_int_tab(&textures, 5);
	ft_freetab(tab);
//	free_sprites(vars->sprite_list);
//	free(Zbuffer);
	error_quit("Error: malloc error", NULL);
	return (-1);
}

int		free_all_tex_fail(void)
{
//	free_tex_list(&g_tex_list, vars);
	free_int_tab(&g_worldmap, g_mlen);
//	free_int_tab(&textures, 5);
	ft_freetab(&g_tex_tab);
//	free_sprites(vars->sprite_list);
//	free(Zbuffer);
	error_quit("Error: Error while initializing textures", NULL);
	return (-1);
}

int		free_all_sprite_fail(t_vars *vars)
{
	free_tex_list(&g_tex_list, vars);
	free_int_tab(&g_worldmap, g_mlen);
	free_int_tab(&textures, 5);
	ft_freetab(&g_tex_tab);
//	free_sprites(vars->sprite_list);
//	free(Zbuffer);
	error_quit("Error: malloc error", NULL);
	return (-1);
}

int		free_all_zbuf_fail(t_vars *vars)
{
	free_tex_list(&g_tex_list, vars);
	free_int_tab(&g_worldmap, g_mlen);
	free_int_tab(&textures, 5);
	ft_freetab(&g_tex_tab);
	free_sprites(vars->sprite_list);
//	free(Zbuffer);
	error_quit("Error: malloc error", NULL);
	return (-1);
}
