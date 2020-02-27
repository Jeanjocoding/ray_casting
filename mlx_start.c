#include "minilibx_opengl_20191021/mlx.h"
#include "libft.h"

int res_vert = 1080;
int res_hor = 1920;
int map_len = 10;
int *init_pos;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

char	**mapper(char str)
{
	char **tab;

	tab = ft_split("1111111111,100000000001,1001111001,1001001001,1001001001, 1001001001,1000000001,1000000001,1000000001,1111111111", ',');
	return (tab);
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void			put_column(t_data *data, int x,  int res_ver, int bas, int haut)
{
	int green;
	int blue;
	int y;

	green = 0x0000FF00;
	blue = 0x000000FF;
	y = 0;
	while (y < bas)
	{
		my_mlx_pixel_put(data, x, y, green);
		y++;
	}
	while (y < haut)
	{
		my_mlx_pixel_put(data, x, y, blue);
		y++;
	}
	while (y < res_ver)
	{
		my_mlx_pixel_put(data, x, y, green);
		y++;
	}
}

int	main(void)
{
	void	*mlx_ptr;
	t_data	img;
	void	*win_ptr;
	int		offset;
	int		i;

	init_pos[0] = 0;
	init_pos[1] = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, res_hor, res_vert, "test");
	img.img = mlx_new_image(mlx_ptr, res_hor, res_vert);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	offset = (y * line_length + x * (bits_per_pixel / 8));
//
//	need to create temp images
	while (i < 1920)
	{
		put_column(&img, i, 1080, 300, 600);
		i++;
	}
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}
