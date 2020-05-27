#include "cub3d.h"

extern int		g_screenwidth;
extern int		g_screenheight;
extern int		**g_worldmap;
extern int		g_mlen;
extern int		**g_textures;
extern double	*g_zbuffer;
extern char		**g_tex_tab;
extern t_data	g_tex_list;
int				g_ground;
int				g_ceiling;
extern int		g_keytab[400];

int			free_all(t_vars *vars)
{
	free_tex_list(&g_tex_list, vars);
	free_int_tab(&g_worldmap, g_mlen);
	free_int_tab(&g_textures, 5);
	ft_freetab(&g_tex_tab);
	free_sprites(vars->sprite_list);
	free(g_zbuffer);
	return (-1);
}

int			close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img);
	free_tex_list(&g_tex_list, vars);
	free_int_tab(&g_worldmap, g_mlen);
	free_int_tab(&g_textures, 5);
	ft_freetab(&g_tex_tab);
	free_sprites(vars->sprite_list);
	free(g_zbuffer);
	exit(0);
	return (0);
}

t_data		generate_image(t_vars *vars, t_data *img)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	img->img = mlx_new_image(vars->mlx, g_screenwidth, g_screenheight);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	get_sprite_distance(vars->sprite_list, &vars->fov);
	vars->sprite_list = sort_sprites(vars->sprite_list);
	mlx_clear_window(vars->mlx, vars->win);
	put_tex(vars, img, &g_tex_list);
	put_sprites(vars, vars->sprite_list, &g_tex_list, img);
	return (*img);
}

int			parse_map_init(t_vars *vars, char *map_file)
{
	int			fd;
	t_sprites	*sprlist;

	sprlist = NULL;
	check_cub(map_file);
	if ((fd = open(map_file, O_RDONLY)) == -1)
		error_quit("Error : unable to open map file", NULL);
	if (!(g_tex_tab = ft_stabmaker(5)))
		error_quit("Error: malloc error", NULL);
	if ((parse_master(fd, &vars->fov)) == -1)
		free_all_parse_fail(&g_tex_tab);
	close(fd);
	vars->mlx = mlx_init();
	vars->img.img = mlx_new_image(vars->mlx, g_screenwidth, g_screenheight);
	if ((init_tex(g_tex_tab, vars->mlx, &g_tex_list, vars)) == -1)
		free_all_tex_fail();
	if (!(vars->sprite_list = get_sprite_list(sprlist)))
		free_all_sprite_fail(vars);
	if (!(g_zbuffer = (double*)malloc(sizeof(double) * g_screenwidth + 1)))
		free_all_zbuf_fail(vars);
	return (0);
}

int			main(int ac, char **av)
{
	t_vars		vars;
	t_sprites	*sprlist;

	sprlist = NULL;
	if (ac < 2 || ac > 3)
		error_quit("USAGE: PRGRM_NAME MAP_FILE [--save]", NULL);
	parse_map_init(&vars, av[1]);
	intarray_set(g_keytab, 0, 400);
	if (ac > 2 && ft_strcmp(av[2], "--save") == 0)
	{
		if ((generate_bmp(&vars, &vars.img)) == -1)
			free_all_bmp_fail(&vars);
		free_all(&vars);
		return (0);
	}
	vars.win = mlx_new_window(vars.mlx, g_screenwidth, g_screenheight, "test");
	mlx_hook(vars.win, 2, 1L << 0, get_command, &vars);
	mlx_hook(vars.win, 3, 1L << 1, release_command, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop_hook(vars.mlx, apply_command, &vars);
	mlx_loop(vars.mlx);
}
