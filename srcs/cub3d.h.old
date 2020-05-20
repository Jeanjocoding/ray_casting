#ifndef CUB3D_H
# define CUB3D_H

#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include "mlx.h"
#include "libft.h"
#include "bmp.h"

typedef	struct	s_fov
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double time;
	double oldTime;
}		t_fov;

typedef	struct	s_ray
{
	int screenX;
	double cameraX;
//	double cameraY;
	double rayDirX;
	double rayDirY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double stepX;
	double stepY;
	int	mapX;
	int	mapY;
	int	hit;
	int	side;
	int	lineheight;
	int	linebottom;
	int	linetop;
	double wallDist;
	double wallX;
	t_fov	*fov;
	int		texnum;
//	double texX;
}		t_ray;

typedef struct	s_sprites
{
	double		x;
	double		y;
	double		distance;
	double		spriteX;
	double		spriteY;
	double 		invDet;
	double		transformX;
	double		transformY;
	int		screenX;
	int		drawStartY;
	int		drawEndY;
	int		drawStartX;
	int		drawEndX;
	int		spriteHeight;
	int		spriteWidth;
	struct s_sprites	*next;
	struct s_sprites	*prev;
	struct s_sprites	*first;
}				t_sprites;

typedef struct  s_data 
{
    void        *img;
    char        *addr;
    int        *int_ptr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	int			img_width;
	int			img_height;
	struct s_data	*next;
	struct s_data	*first;
}               t_data;

typedef struct  s_vars {
    void        *mlx;
    void        *win;
    t_fov	fov;
    t_data	img;
    t_sprites	*sprite_list;
}               t_vars;

typedef struct	s_line
{
	int	lineheight;
	int	bottom;
	int	top;
}		t_line;

typedef struct		s_lmap
{
	int		size;
	char		*content;
	struct s_lmap	*next;
	struct s_lmap	*prev;
}			t_lmap;

void 	print_ray(t_ray *ray);
void 	print_fov(t_fov *fov);
void	print_map(int map[24][24], int lenx, int leny);
int	get_command(int keycode, t_vars *vars);
void	move_forward(t_fov *fov);
void	move_backward(t_fov *fov);
void	move_right(t_fov *fov);
void	move_left(t_fov *fov);
void	rotate_left(t_fov *fov);
void	rotate_right(t_fov *fov);
int	close_window(t_vars *vars);
t_fov	initialize_fov(t_fov *fov, double posX, double posY);
t_ray	initialize_ray(t_ray *ray);
t_ray	*get_ray_info(int x, t_fov *fov, t_ray *ray); 
t_data	generate_image(t_vars *vars, t_data *img);
int	put_tex(t_vars *vars, t_data *main_img, t_data *tex_list);
void	*load_img_getinfo(t_data *img_info, void *mlx, char *relative_path);
void 	print_img_info(t_data *img_info);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		init_tex(char **tab, void *mlx, t_data *tex_list, t_vars *vars);
char	**get_tex_tab(char *texN, char *texS, char *texO, char *texE);
int		tex_chooser(t_ray *ray);
t_data	*get_right_tex(int tex_num, t_data *tex_list);
void	put_floor_ceiling(t_data *data, int x, t_ray *ray);
t_sprites	*get_sprite_list(t_sprites *sprite);
void	print_sprlist(t_sprites *sprite);
void	print_sprite(t_sprites *sprite);
t_sprites	*get_sprite_distance(t_sprites *sprite, t_fov *fov);
t_sprites	*sort_sprites(t_sprites *list);
t_sprites	*put_sprites(t_vars *vars, t_sprites *sprite_list, t_data *tex_list, t_data *main_img);
char	**add_tex_sprite(char *tex_sprite);
char	**add_tex_num(char *path, int num);
int     parse_master(int fd, t_fov *fov);
int     error_quit(char *msg, char ***tab);
int     check_all_digit(char *str);
int     get_north(char ***tab);
int     get_south(char ***tab);
int     get_west(char ***tab);
int     get_east(char ***tab);
int     get_sprite(char ***tab);
int     get_ceiling(char ***tab);
int     get_floor(char ***tab);
int	get_rgb(int r, int g, int b);
int     check_first_map(char **line);
char    **get_cub_tab(int fd);
int     set_map(char **tab, int i, t_fov *fov);
void	print_map_ptr(int **map, int lenx, int leny);
int     set_fov(char c, t_fov *fov, int x, int y);
int     get_right_char_first(char c, int x, int y);
int     get_right_char_mid(char c, int x, int y, t_fov *fov);
int     fill_map(char **tab, t_fov *fov);
void    free_int_tab(int ***tab, int len);
int     verify_int_map(int  ***map, int mlen, int mheight);
char	**ft_cub_split(char const *s, char c);
int	release_command(int keycode, t_vars *vars);
int	apply_command(t_vars *vars);
void    int_set(int **dst, int nbr, int len);
void	free_tex_list(t_data *list, t_vars *vars);
void    free_sprites(t_sprites *sprites);
int     set_bmp(t_bmpHeader *head, t_data *img_file);
int	generate_bmp(t_vars *vars, t_data *img);
int     write_bmp(int fd, t_bmpHeader *head, t_data *img_file, int img_size);
int		free_all_parse_fail(char ***tab);
int		free_all_sprite_fail(t_vars *vars);
int		free_all_zbuf_fail(t_vars *vars);
int		free_all_bmp_fail(t_vars *vars);
int     free_tab_ret(char ***tab);
int	    custom_freetab(char ***tab);
int	    free_int_ret(int ***tab, int len);
void	classic_freetab(char ***tab);
int		free_all_tex_fail(void);
int	    free_int_tex(int ***tab, int len, t_data *tex_list, t_vars *vars);

#endif
