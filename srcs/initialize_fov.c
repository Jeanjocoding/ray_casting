#include "cub3d.h"

t_fov		initialize_fov(t_fov *fov, double posx, double posy)
{
	fov->posx = posx;
	fov->posy = posy;
	fov->dirx = 1;
	fov->diry = 0;
	fov->planeX = 0;
	fov->planeY = 0.66;
	fov->time = 0;
	fov->oldTime = 0;
	return (*fov);
}
