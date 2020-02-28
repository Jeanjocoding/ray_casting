#include "lodev.h"
#include <stdio.h>

void 	print_ray(t_ray *ray)
{
	printf("\n\n-------- ray : --------\n");
	printf("ray->cameraX : %f\n", ray->cameraX);
	printf("ray->rayDirX : %f\n", ray->rayDirX);
	printf("ray->rayDirY : %f\n", ray->rayDirY);
	printf("ray->sideDistX : %f\n", ray->sideDistX);
	printf("ray->sideDistY : %f\n", ray->sideDistY);
	printf("ray->deltaDistX : %f\n", ray->deltaDistX);
	printf("ray->deltaDistY : %f\n", ray->deltaDistY);
	printf("ray->stepX : %f\n", ray->stepX);
	printf("ray->stepY : %f\n", ray->stepY);
	printf("ray->mapX : %d\n", ray->mapX);
	printf("ray->mapY : %d\n", ray->mapY);
	printf("ray->hit : %d\n", ray->hit);
	printf("ray->side : %d\n", ray->side);
	printf("ray->wallDist : %f\n", ray->wallDist);
	printf("---------------------------\n");
}

void 	print_fov(t_fov *fov)
{
	printf("\n\n-------- fov : --------\n");
	printf(" fov->posX: %f\n", fov->posX);
	printf(" fov->posY: %f\n", fov->posY);
	printf(" fov->dirX: %f\n", fov->dirX);
	printf(" fov->dirY: %f\n", fov->dirY);
	printf(" fov->planeX: %f\n", fov->planeX);
	printf(" fov->planeY: %f\n", fov->planeY);
	printf(" fov->time: %f\n", fov->time);
	printf(" fov->oldTime: %f\n", fov->oldTime);
	printf("---------------------------\n");
}


