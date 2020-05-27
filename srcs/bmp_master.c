#include "bmp.h"
#include "cub3d.h"

extern int		g_screenwidth;
extern int		g_screenheight;
extern t_data	g_tex_list;

void	set_img(t_data *img, t_vars *vars)
{
	img->img = mlx_new_image(vars->mlx, g_screenwidth, g_screenheight);
	img->img_width = g_screenwidth;
	img->img_height = g_screenheight;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	get_sprite_distance(vars->sprite_list, &vars->fov);
	vars->sprite_list = sort_sprites(vars->sprite_list);
}

int		generate_bmp(t_vars *vars, t_data *img)
{
	t_bmpheader		head;
	int				*temp_ptr;
	int				img_size;
	int				fd;

	if ((fd = open("save.bmp", O_CREAT | O_TRUNC | O_WRONLY | O_APPEND,
			0777)) == -1)
	{
		ft_printf("error fd");
		return (-1);
	}
	set_img(img, vars);
	put_tex(vars, img, &g_tex_list);
	put_sprites(vars, vars->sprite_list, &g_tex_list, img);
	temp_ptr = (int*)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img_size = img->img_width * 4 * img->img_height;
	if (!(img->int_ptr = (int*)malloc(sizeof(int) * img_size)))
		return (-1);
	ft_memcpy(img->int_ptr, temp_ptr, img_size);
	set_bmp(&head, img);
	write_bmp(fd, &head, img, img_size);
	free(img->int_ptr);
	close(fd);
	return (1);
}
