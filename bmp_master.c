#include "bmp.h"
#include "cub3d.h"
extern int screenWidth;
extern int screenHeight;
extern t_data tex_list;


int	    generate_bmp(t_vars *vars, t_data *img)
{
//	int 	i;
//	t_raiy	ray;
    t_bmpHeader head;
    int *temp_ptr;
    int img_size;
    int fd;
//	i = 0;
    if ((fd = open("save.bmp", O_CREAT | O_WRONLY | O_APPEND, 0777)) == -1)
    {
        ft_printf("error fd");
        return (-1);
    }
    ft_printf("fd : %d\n", fd);
	img->img = mlx_new_image(vars->mlx, screenWidth, screenHeight);
    img->img_width = screenWidth;
    img->img_height = screenHeight;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	get_sprite_distance(vars->sprite_list, &vars->fov);
	vars->sprite_list = sort_sprites(vars->sprite_list);
	mlx_clear_window(vars->mlx, vars->win);
	put_tex(vars, img, &tex_list);
	put_sprites(vars, vars->sprite_list, &tex_list, img);
//    temp_ptr = (int*)img->addr;
	temp_ptr = (int*)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    img_size = img->img_width * 4 * img->img_height;
    if (!(img->int_ptr = (int*)malloc(sizeof(int) * img_size)))
        return (-1);
    ft_memcpy(img->int_ptr, temp_ptr, img_size);
    set_bmp(&head, img);
    write_bmp(fd, &head, img, img_size);
    free(img->int_ptr);
//    mlx_destroy_image(vars->mlx, img->img);
    close (fd);
	return (1);
}