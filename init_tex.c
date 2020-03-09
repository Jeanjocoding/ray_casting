#include "lodev.h"
#include "minilibx_opengl_20191021/mlx.h"
#include "libft.h"

int		**textures;
char	**tex_tab;


int		tex_chooser(t_ray *ray, t_fov *fov)
{
	if (ray->side == 0)
	{
		if (ray->rayDirX < 0)
			return (3);
		else
			return (2);
	}
	else
	{
		if (ray->rayDirY < 0)
			return (1);
		else
			return (0);
	}

}

char	**get_tex_tab(char *texN, char *texS, char *texO, char *texE)
{
//	char	**tab;

	if (!(tex_tab = ft_stabmaker(4)))
		return (NULL);
	if (!(tex_tab[0] = ft_strdup(texN)))
		return (NULL);
	if (!(tex_tab[1] = ft_strdup(texS)))
		return (NULL);
	if (!(tex_tab[2] = ft_strdup(texO)))
		return (NULL);
	if (!(tex_tab[3] = ft_strdup(texE)))
		return (NULL);
	return (tex_tab);
}

int		**init_tex(char **tab, void	*mlx)
{
	int i;
	t_data	tex_img;
	int	addr_width;
	int	*temp_addr;

	i = 0;
	if (!(textures = (int**)malloc(sizeof(int*) * 5)))
		return (NULL);
	while (i < 4)
	{
		printf("tab : %s\n", tab[i]);
		tex_img.img = mlx_xpm_file_to_image(mlx, tab[i], &(tex_img.img_width), &(tex_img.img_height));
		temp_addr = (int*)mlx_get_data_addr(tex_img.img, &(tex_img.bits_per_pixel), &(tex_img.line_length), &(tex_img.endian));
		addr_width = tex_img.img_width * 4 * tex_img.img_height;
		if (!(textures[i] = (int*)malloc(sizeof(int) * addr_width + 1)))
			return ((void*)0);
		ft_memcpy(textures[i], temp_addr, addr_width);
		i++;
	}
	textures[4] = 0;
	return (textures);
}
