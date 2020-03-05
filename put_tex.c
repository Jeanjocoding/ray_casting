#include "lodev.h"
#include "minilibx_opengl_20191021/mlx.h"
#include "libft.h"

extern int	screenWidth;
extern int	screenHeight;

int		create_trgb(int t, int r, int g, int b)
{
	return(b << 24 | g << 16 | r << 8 | t);
}


int		get_texX(t_ray *ray, t_data *tex_img)
{
	int texX;

// a verifier, pas sur du tout pour le temlpacement de texwidth par line_length
//pe qu'il faut utiliser les dimensions img_width et height

	texX = (int)(ray->wallX * (double)(tex_img->img_width)); // je compredns pas l'utilié de ce qui suit 
    if(ray->side == 0 && ray->rayDirX > 0)
		texX = tex_img->img_width - texX - 1;
    if(ray->side == 1 && ray->rayDirY < 0) 
	texX = tex_img->img_width - texX - 1;
	return (texX);
}


/*int		get_texX(t_ray *ray, t_data *tex_img)
{
	int texX;

// a verifier, pas sur du tout pour le temlpacement de texwidth par line_length
//pe qu'il faut utiliser les dimensions img_width et height

	texX = (int)(ray->wallX * (double)(tex_img->line_length / 64));
    if(ray->side == 0 && ray->rayDirX > 0)
		texX = tex_img->line_length / 64 - texX - 1;
    if(ray->side == 1 && ray->rayDirY < 0) 
	texX = tex_img->line_length / 64 - texX - 1;
	return (texX);
}
*/

void	put_tex_column(int tex_coor[2], t_data *main_img, t_data *tex_img, t_ray *ray, void *mlx)
{
	double	step;
	double	texPos;
	int	y;
	int 	*addr_t;
//	char 	dest*;
	int	addr_index;
	int	color_trgb;
	unsigned int	color;

	step = 1.0 * tex_img->img_height / ray->lineheight;
	texPos = (ray->linebottom - (screenHeight / 2) + ray->lineheight / 2) * step;
	y = ray->linebottom;
//	print_img_info(tex_img);
	while (y < ray->linetop)
	{
		tex_coor[1] = (int)texPos; //& (tex_img->img_height - 1); // mask de lodev sais pas a quoi ça sert
		texPos += step;
		printf("wallX : %f\n", ray->wallX);
		printf("tex x : %d\n", tex_coor[0]);
		printf("tex y : %d\n", tex_coor[1]);
		addr_t = tex_img->int_ptr + (tex_coor[1] * tex_img->line_length + tex_coor[0] * 4);
		addr_index = tex_coor[1] * tex_img->line_length + tex_coor[0] * 4;
		printf("addr_index : %d\n", addr_index);
//		printf("addr_t : %d\n", addr_t[0]);
//		color_trgb = create_trgb(tex_img->addr[0], tex_img->addr[1], tex_img->addr[2], tex_img->addr[3]);
	//	color_trgb = create_trgb(tex_img->addr_t[3], tex_img->addr_t[2], tex_img->addr_t[1], tex_img->addr_t[0]);
//		color_trgb = create_trgb(addr_t[3], addr_t[2], addr_t[1], addr_t[0]);
//	color_trgb = create_trgb(addr_t[3], addr_t[0], addr_t[1], addr_t[2]);
//		color_trgb = create_trgb(addr_t[0], addr_t[1], addr_t[2], addr_t[3]);
//		printf("addr[0] : %d\n", addr_t[0]);
//		printf("color: %d\n", color_trgb);
//		printf("addr: %d\n", addr_t[addr_index]);
//		color = mlx_get_color_value(mlx, (int)*addr_t);
		color = (unsigned int)(*addr_t);
//		if (ray->side == 1)
//			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(main_img, ray->screenX, y, color);
		y++;
	}
}

int	put_tex(t_data *main_img, char *relative_path, void *mlx, t_fov *fov)
{
	t_data	tex_img;
	int	x;
	int	tex_coor[2];
	t_ray	ray;

	load_img_getinfo(&tex_img, mlx, relative_path);
	print_img_info(&tex_img);
	x = 0;
	while (x < screenWidth)
	{
		ray = initialize_ray(&ray);
		get_ray_info(x, fov, &ray);
		tex_coor[0] = get_texX(&ray, &tex_img);
		put_tex_column(tex_coor, main_img, &tex_img, &ray, mlx);
		x++;
	}
	return (0);
}

void	*load_img_getinfo(t_data *img_info, void *mlx, char *relative_path)
{
	img_info->img = mlx_xpm_file_to_image(mlx, relative_path, &(img_info->img_width), &(img_info->img_height));
	img_info->int_ptr = (int*)mlx_get_data_addr(mlx, &(img_info->bits_per_pixel), &(img_info->line_length), &(img_info->endian));
	return (img_info->img);
}
