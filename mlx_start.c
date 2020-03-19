#include "minilibx_opengl_20191021/mlx.h"
#include "libft.h"
#include "lodev.h"

extern int	mapWidth;
extern int 	mapHeight;
extern int 	screenWidth;
extern int 	screenHeight;
extern int 	worldMap[24][24];
extern int	map_lenX;
extern int	map_lenY;
extern int	**textures;
extern int	*Zbuffer;
extern char	**tex_tab;
extern t_data	tex_list;
int		ground;
int		ceiling;
//extern t_sprites	sprite_list;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void			put_floor_ceiling(t_data *data, int x, t_ray *ray)
{
	int y;

	ceiling = 0xBAA331;
	ground = 0x1544FF;
	y = 0;
	while (y < ray->linebottom)
	{
		my_mlx_pixel_put(data, x, y, ground);
		y++;
	}
	y = ray->linetop;
	while (y < screenHeight)
	{
		my_mlx_pixel_put(data, x, y, ceiling);
		y++;
	}
}

int	close_window(int keycode, t_vars *vars)
{
	ft_putchar('X');
//	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

t_data	generate_image(t_vars *vars, t_data *img)
{
	int 	i;
	t_ray	ray;

	i = 0;
	img->img = mlx_new_image(vars->mlx, screenWidth, screenHeight);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	get_sprite_distance(vars->sprite_list, &vars->fov);
	vars->sprite_list = sort_sprites(vars->sprite_list);
	mlx_clear_window(vars->mlx, vars->win);
	put_tex(vars, img, &tex_list);
	put_sprites(vars, vars->sprite_list, &tex_list, img);
	return (*img);
}

int	main(int ac, char **av)
{
	t_data	img;
	t_data	temp_img;
	void	*win_ptr;
	int		offset;
	int		i;
	t_vars	vars;
	t_ray	ray;
	t_data	tex;
	t_sprites *sprlist;
	char	**tab;


	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, screenWidth, screenHeight, "test");
	vars.fov = initialize_fov(&vars.fov, ft_atoi(av[1]), ft_atoi(av[2]));
	get_tex_tab("Karl_Marx.xpm", "redbrick.xpm", "greystone.xpm", "eagle.xpm");
	add_tex_sprite("jean-luc-mélenchon-png-3.xpm");
	init_tex(tex_tab, vars.mlx, &tex_list);
	print_map(worldMap, map_lenX, map_lenY);
	if (!(vars.sprite_list = get_sprite_list(sprlist)))
		return (-1);
	print_sprlist(vars.sprite_list);
	if (!(Zbuffer = (int*)malloc(sizeof(int) * screenWidth + 1)))
		return (-1);
//	load_img_getinfo(&tex, vars.mlx, "./redbrick.xpm");
	generate_image(&vars, &(vars.img));
//	put_tex(&(vars.img), "redbrick.xpm", vars.mlx, &ray);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
//    mlx_put_image_to_window(vars.mlx, vars.win, tex.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, get_command, &vars);
//	mlx_key_hook(vars.win, close_window, &vars);
	mlx_loop(vars.mlx);
}
