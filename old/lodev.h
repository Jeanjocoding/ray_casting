#ifndef LODEV_H
# define LODEV_H

#include <math.h>

typedef	struct	s_ray
{
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
	int	screenX;
	double wallDist;
}		t_ray;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int		img_width;
    int		img_height;
}               t_data;

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

typedef struct  s_vars {
    void        *mlx;
    void        *win;
    t_fov	fov;
    t_data	temp_img;
    t_data	img;
}               t_vars;

typedef struct	s_line
{
	int	lineheight;
	int	bottom;
	int	top;
}		t_line;

void 	print_ray(t_ray *ray);
void 	print_fov(t_fov *fov);
void	print_map(int map[24][24], int lenx, int leny);
void 	print_img_info(t_data *img_info);
int	get_command(int keycode, t_vars *vars);
void	move_forward(t_fov *fov);
void	move_backward(t_fov *fov);
void	move_right(t_fov *fov);
void	move_left(t_fov *fov);
void	rotate_left(t_fov *fov);
void	rotate_right(t_fov *fov);
void	*load_img_getinfo(t_data *img_info, void *mlx, char *relative_path);
t_fov	initialize_fov(t_fov *fov, double posX, double posY);
t_ray	initialize_ray(t_ray *ray);
t_ray	*get_ray_info(int x, t_fov *fov, t_ray *ray); 
t_data	generate_image(t_vars *vars, t_data *img);

#endif
