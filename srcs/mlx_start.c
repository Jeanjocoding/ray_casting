#include "cub3d.h"

extern int	mapWidth;
extern int 	mapHeight;
extern int 	g_screenwidth;
extern int 	g_screenheight;
extern int 	**g_worldmap;
extern int	g_mlen;
//extern int	map_lenY;
extern int	**textures;
extern double	*Zbuffer;
extern char	**g_tex_tab;
extern t_data	g_tex_list;
int		ground;
int		ceiling;
extern int	keytab[400];
//extern t_data	g_tex_list;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void			put_floor_ceiling(t_data *data, int x, t_ray *ray)
{
	int y;

//	ceiling = 0xBAA331;
//	ground = 0x1544FF;
	y = 0;
	while (y < ray->linebottom)
	{
		my_mlx_pixel_put(data, x, y, ceiling);
		y++;
	}
	y = ray->linetop;
	while (y < g_screenheight)
	{
		my_mlx_pixel_put(data, x, y, ground);
		y++;
	}
}

int		free_all(t_vars *vars)
{
	free_tex_list(&g_tex_list, vars);
	free_int_tab(&g_worldmap, g_mlen);
	free_int_tab(&textures, 5);
	ft_freetab(&g_tex_tab);
	free_sprites(vars->sprite_list);
	free(Zbuffer);
	return (-1);
}

int		check_cub(char *path)
{
	int	len;

	len = ft_strlen(path);
	len--;
	if (path[len] != 'b' || path[len - 1] != 'u' || path[len - 2] != 'c'
		|| path[len - 3] != '.')
	error_quit("Error: invalid configuration file", NULL);
	return (-1);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img);
//	list_ptr = get_right_tex(0, &g_tex_list);
//	free_tex_list(list_ptr, vars);
	free_tex_list(&g_tex_list, vars);
	free_int_tab(&g_worldmap, g_mlen);
	free_int_tab(&textures, 5);
	ft_freetab(&g_tex_tab);
	free_sprites(vars->sprite_list);
	free(Zbuffer);
	exit(0);
	return (0);
}

t_data	generate_image(t_vars *vars, t_data *img)
{
//	int 	i;
//	t_ray	ray;

//	i = 0;
	mlx_destroy_image(vars->mlx, vars->img.img);
	img->img = mlx_new_image(vars->mlx, g_screenwidth, g_screenheight);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	get_sprite_distance(vars->sprite_list, &vars->fov);
	vars->sprite_list = sort_sprites(vars->sprite_list);
	mlx_clear_window(vars->mlx, vars->win);
	put_tex(vars, img, &g_tex_list);
	put_sprites(vars, vars->sprite_list, &g_tex_list, img);
	return (*img);
}

void    intarray_set(int dst[400], int nbr, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        dst[i] = nbr;
        i++;
    }
}

int	main(int ac, char **av)
{
	int		fd;
	t_vars	vars;
	t_sprites *sprlist;


	sprlist = NULL;
	if (ac < 2  || ac > 3)
		error_quit("USAGE: PRGRM_NAME MAP_FILE [--save]", NULL);
	check_cub(av[1]);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error_quit("Error : unable to open map file", NULL);
	if (!(g_tex_tab = ft_stabmaker(5)))
		error_quit("Error: malloc error", NULL);
	if ((parse_master(fd, &vars.fov)) == -1)
		free_all_parse_fail(&g_tex_tab);
	close(fd);
	vars.mlx = mlx_init();
	vars.img.img = mlx_new_image(vars.mlx, g_screenwidth, g_screenheight);
	if ((init_tex(g_tex_tab, vars.mlx, &g_tex_list, &vars)) == -1)
		free_all_tex_fail();
	if (!(vars.sprite_list = get_sprite_list(sprlist)))
		free_all_sprite_fail(&vars);
	if (!(Zbuffer = (double*)malloc(sizeof(double) * g_screenwidth + 1)))
		free_all_zbuf_fail(&vars);
	intarray_set(keytab, 0, 400);
	if (ac > 2 && ft_strcmp(av[2], "--save") == 0)
	{
		if ((generate_bmp(&vars, &vars.img)) == -1)
			free_all_bmp_fail(&vars);
		free_all(&vars);
		return (0);
	}
	vars.win = mlx_new_window(vars.mlx, g_screenwidth, g_screenheight, "test");
	mlx_hook(vars.win, 2, 1L<<0, get_command, &vars);
	mlx_hook(vars.win, 3, 1L<<1, release_command, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop_hook(vars.mlx, apply_command, &vars);
	mlx_loop(vars.mlx);
}
