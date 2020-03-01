#include "minilibx_opengl_20191021/mlx.h"
#include "libft.h"
#include "lodev.h"

extern int	mapWidth;
extern int 	mapHeight;
extern int 	screenWidth;
extern int 	screenHeight;
extern int 	worldMap[24][24];

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

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



int	main(int ac, char **av)
{
	void	*mlx_ptr;
	t_data	img;
	void	*win_ptr;
	int		offset;
	int		i;
	t_ray	ray;
	t_fov	fov;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "test");
	img.img = mlx_new_image(mlx_ptr, screenWidth, screenHeight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	fov = initialize_fov(&fov, ft_atoi(av[1]), ft_atoi(av[2]));
	i = 0;
	while (i < screenWidth)
	{
		ray = initialize_ray(&ray);
		get_ray_info(i, &fov, &ray);
		put_column(&img, i, &ray);
		i++;
	}
    	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}
