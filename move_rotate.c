#include "minilibx_opengl_20191021/mlx.h"
#include "lodev.h"
#include "keys.h"

extern int	**worldMap;
extern int	screenHeight;
extern int	screenWidth;

int	get_command(int keycode, t_vars *vars)
{
	t_data	temp_img;

	print_fov(&vars->fov);
	if (keycode == KEY_W) // Z chez moi
		move_forward(&(vars->fov));
	if (keycode == KEY_S) // S chez moi
		move_backward(&(vars->fov));
	if (keycode == KEY_D) // D chez moi
		move_right(&(vars->fov));
	if (keycode == KEY_A) // Q chez moi
		move_left(&(vars->fov));
	if (keycode == KEY_LEFT) 
		rotate_left(&(vars->fov));
	if (keycode == KEY_RIGHT) 
		rotate_right(&(vars->fov));
	if (keycode == KEY_ESCAPE) 
		close_window(keycode, vars);
	generate_image(vars, &temp_img);
	mlx_put_image_to_window(vars->mlx, vars->win, temp_img.img, 0, 0);
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

