#include "lodev.h"
#include "minilibx_opengl_20191021/mlx.h"
#include "libft.h"

double		get_texX(t_ray *ray, t_data *tex_img)
{
	int texX;

// a verifier, pas sur du tout pour le temlpacement de texwidth par line_length

	texX = (int)(ray->wallX * (double)(tex_img->line_length));
    if(ray->side == 0 && ray->rayDirX > 0)
		texX = tex_img->line_length - texX - 1;
    if(ray->side == 1 && ray->rayDirY < 0) 
	texX = tex_img->line_length - texX - 1;
	return (texX);
}

int	put_tex(t_data *main_img, char *relative_path, void *mlx, t_ray *ray)
{
	t_data	tex_img_info;

	load_img_getinfo(&tex_img_info, mlx, relative_path);
	print_img_info(&tex_img_info);
	return (0);
}

void	*load_img_getinfo(t_data *img_info, void *mlx, char *relative_path)
{
	img_info->img = mlx_xpm_file_to_image(mlx, relative_path, &(img_info->img_width), &(img_info->img_height));
	mlx_get_data_addr(mlx, &(img_info->bits_per_pixel), &(img_info->line_length), &(img_info->endian));
	return (img_info->img);
}
