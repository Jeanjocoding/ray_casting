#include "minilibx_opengl_20191021/mlx.h"
#include "cub3d.h"

extern int	mapWidth;
extern int 	mapHeight;
extern int 	screenWidth;
extern int 	screenHeight;
extern int 	**worldMap;
extern int	mlen;
//extern int	map_lenY;
extern int	**textures;
extern double	*Zbuffer;
extern char	**tex_tab;
extern t_data	tex_list;
int		ground;
int		ceiling;
extern int	keytab[400];
//extern t_data	tex_list;

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
	while (y < screenHeight)
	{
		my_mlx_pixel_put(data, x, y, ground);
		y++;
	}
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img);
//	list_ptr = get_right_tex(0, &tex_list);
//	free_tex_list(list_ptr, vars);
	free_tex_list(&tex_list, vars);
	free_int_tab(&worldMap, mlen);
	free_int_tab(&textures, 5);
	ft_freetab(&tex_tab);
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
	img->img = mlx_new_image(vars->mlx, screenWidth, screenHeight);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	get_sprite_distance(vars->sprite_list, &vars->fov);
	vars->sprite_list = sort_sprites(vars->sprite_list);
	mlx_clear_window(vars->mlx, vars->win);
	put_tex(vars, img, &tex_list);
	put_sprites(vars, vars->sprite_list, &tex_list, img);
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


	(void)ac;
	(void)av;
	sprlist = NULL;
	fd = open("map.cub", O_RDONLY);
	if (!(tex_tab = ft_stabmaker(5)))
		return (-1);
	parse_master(fd, &vars.fov);
	close(fd);
//	sleep(5);
//	return (0);
//	sleep(5);
//	return (0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, screenWidth, screenHeight, "test");
//	vars.img.img = mlx_new_image(vars.mlx, screenWidth, screenHeight);
	init_tex(tex_tab, vars.mlx, &tex_list);
	if (!(vars.sprite_list = get_sprite_list(sprlist)))
		return (-1);
	if (!(Zbuffer = (double*)malloc(sizeof(double) * screenWidth + 1)))
		return (-1);
//	close_window(1, &vars);
//	generate_image(&vars, &(vars.img));
	intarray_set(keytab, 0, 400);
	if ((generate_bmp(&vars, &vars.img)) == -1)
		return (-1);
//    mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, get_command, &vars);
	mlx_hook(vars.win, 3, 1L<<1, release_command, &vars);
	mlx_loop_hook(vars.mlx, apply_command, &vars);
	mlx_loop(vars.mlx);
}
