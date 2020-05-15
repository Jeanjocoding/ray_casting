#include "cub3d.h"
#include "keys.h"

extern int	**worldMap;
extern int	screenHeight;
extern int	screenWidth;
int			keytab[400];


int	apply_command(t_vars *vars)
{
//	t_data	temp_img;

//	print_fov(&vars->fov);
	if (keytab[KEY_W] == 1) // Z chez moi
		move_forward(&(vars->fov));
	if (keytab[KEY_S] == 1) // Z chez moi
		move_backward(&(vars->fov));
	if (keytab[KEY_D] == 1) // Z chez moi
		move_right(&(vars->fov));
	if (keytab[KEY_A] == 1) // Z chez moi
		move_left(&(vars->fov));
	if (keytab[KEY_LEFT] == 1) // Z chez moi
		rotate_left(&(vars->fov));
	if (keytab[KEY_RIGHT] == 1) // Z chez moi
		rotate_right(&(vars->fov));
	if (keytab[KEY_ESCAPE] == 1) // Z chez moi
		close_window(vars);
	generate_image(vars, &vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	get_command(int keycode, t_vars *vars)
{
	keytab[keycode] = 1;
	apply_command(vars);
	return (0);
}

int	release_command(int keycode, t_vars *vars)
{
	keytab[keycode] = 0;
	apply_command(vars);
	return (0);
}

void	move_forward(t_fov *fov)
{
	double	moveSpeed;

	moveSpeed = 0.3;
	if (worldMap[(int)(fov->posX + fov->dirX * moveSpeed)][(int)(fov->posY)] == 0)
		fov->posX += fov->dirX * moveSpeed;
	if (worldMap[(int)(fov->posX)][(int)(fov->posY + fov->dirY *moveSpeed)] == 0)
		fov->posY += fov->dirY * moveSpeed;
}

void	move_backward(t_fov *fov)
{
	double	moveSpeed;

	moveSpeed = 0.3;
	if (worldMap[(int)(fov->posX - fov->dirX * moveSpeed)][(int)(fov->posY)] == 0)
		fov->posX -= fov->dirX * moveSpeed;
	if (worldMap[(int)(fov->posX)][(int)(fov->posY - fov->dirY * moveSpeed)] == 0)
		fov->posY -= fov->dirY * moveSpeed;
}


void	move_right(t_fov *fov)
{
	double	moveSpeed;

	moveSpeed = 0.3;
	if (worldMap[(int)(fov->posX + fov->planeX * moveSpeed)][(int)(fov->posY)] == 0)
		fov->posX += fov->planeX * moveSpeed;
	if (worldMap[(int)(fov->posX)][(int)(fov->posY + fov->planeY * moveSpeed)] == 0)
		fov->posY += fov->planeY * moveSpeed;
}

void	move_left(t_fov *fov)
{
	double	moveSpeed;

	moveSpeed = 0.3;
	if (worldMap[(int)(fov->posX - fov->planeX * moveSpeed)][(int)(fov->posY)] == 0)
		fov->posX -= fov->planeX * moveSpeed;
	if (worldMap[(int)(fov->posX)][(int)(fov->posY - fov->planeY * moveSpeed)] == 0)
		fov->posY -= fov->planeY * moveSpeed;
}

