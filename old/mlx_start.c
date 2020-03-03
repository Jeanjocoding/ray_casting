#include "minilibx_opengl_20191021/mlx.h"
#include "libft.h"
#include "lodev.h"

extern int	mapWidth;
extern int 	mapHeight;
extern int 	screenWidth;
extern int 	screenHeight;
extern int 	worldMap[24][24];

/*char	**mapper(char str)
{
	char **tab;

	tab = ft_split("1111111111,100000000001,1001111001,1001001001,1001001001, 1001001001,1000000001,1000000001,1000000001,1111111111", ',');
	return (tab);
}*/

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}



void			put_column(t_data *data, int x, t_ray *ray)
{
	int green;
	int blue;
	int y;

	green = 0x0000FF00;
	blue = 0x000000FF;
	y = 0;
	if (ray->side == 1)
		blue = blue / 2;
	while (y < ray->linebottom)
	{
		my_mlx_pixel_put(data, x, y, green);
		y++;
	}
	while (y < ray->linetop)
	{
		my_mlx_pixel_put(data, x, y, blue);
		y++;
	}
	while (y < screenHeight)
	{
		my_mlx_pixel_put(data, x, y, green);
		y++;
	}
}

int	put_tex(t_data *main_img, char *relative_path, void *mlx, t_ray *ray)
{
	t_data	tex_img_info;

	load_img_getinfo(&tex_img_info, mlx, relative_path);
	print_img_info(&tex_img_info);
	return (0);
}



int	close_window(int keycode, t_vars *vars)
{
	ft_putchar('X');
//	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	*load_img_getinfo(t_data *img_info, void *mlx, char *relative_path)
{
	img_info->img = mlx_xpm_file_to_image(mlx, relative_path, &(img_info->img_width), &(img_info->img_height));
	mlx_get_data_addr(mlx, &(img_info->bits_per_pixel), &(img_info->line_length), &(img_info->endian));
	return (img_info->img);
}

/*t_data	*get_img_info(t_data *img_info, void *img, void *mlx)
{
	mlx_get_data_addr(mlx, &(img_info->bits_per_pixel), &(img_info->line_length), &(img_info->endian));
	return (img_info);
}
*/

t_data	generate_image(t_vars *vars, t_data *img)
{
	int 	i;
	int 	douille; //permet d'eviter replacement non décidé de posX
	t_ray	ray;

	i = 0;
	douille = vars->fov.posX;
//	printf("1st generate\n");
//	print_fov(&vars->fov);
	img->img = mlx_new_image(&vars->mlx, screenWidth, screenHeight);
//	printf("2nd generate\n");
//	print_fov(&vars->fov);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
//	ray = initialize_ray(&ray); // la pour test
//	get_ray_info(i, &(vars->fov), &ray); //idem
//	put_tex(img, "./redbrick.xpm", vars->mlx, &ray);
//	printf("before launching\n");
//	vars->fov.posX = 4;
//	print_fov(&vars->fov);
	vars->fov.posX = douille;
	while (i < screenWidth)
	{
		ray = initialize_ray(&ray);
		get_ray_info(i, &vars->fov, &ray);
	//	print_ray(&ray);
	//@	print_fov(&vars->fov);
		put_column(img, i, &ray);
		i++;
	}
	return (*img);
}

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	t_data	img;
	t_data	temp_img;
	void	*win_ptr;
	int		offset;
	int		i;
	t_vars	vars;
	t_ray	ray;
//	t_fov	fov;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, screenWidth, screenHeight, "test");
	vars.fov = initialize_fov(&vars.fov, 4, 4); //ft_atoi(av[1]), ft_atoi(av[2]));
//	print_fov(&vars.fov);
	generate_image(&vars, &(vars.img));
/*	img.img = mlx_new_image(mlx_ptr, screenWidth, screenHeight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 0;
	while (i < screenWidth)
	{
		ray = initialize_ray(&ray);
		get_ray_info(i, &fov, &ray);
		put_column(&img, i, &ray);
		i++;
	}*/

    	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, get_command, &vars);
//	mlx_key_hook(vars.win, close_window, &vars);
	mlx_loop(vars.mlx);
}
