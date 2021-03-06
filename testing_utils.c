#include "cub3d.h"
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
	printf("ray->lineheight : %d\n", ray->lineheight);
	printf("ray->linebottom : %d\n", ray->linebottom);
	printf("ray->linetop : %d\n", ray->linetop);
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

void 	print_img_info(t_data *img_info)
{
	printf("\n\n-------- img_info : --------\n");
	printf(" img_info->addr: %p\n", img_info->int_ptr);
	printf(" img_info->int_ptr: %p\n", img_info->int_ptr);
	printf(" img_info->bits_per_pixel: %d\n", img_info->bits_per_pixel);
	printf(" img_info->line_length: %d\n", img_info->line_length);
	printf(" img_info->img_width: %d\n", img_info->img_width);
	printf(" img_info->img_height: %d\n", img_info->img_height);
	printf(" img_info->endian: %d\n", img_info->endian);
	printf("---------------------------\n");
}

void	print_map(int map[24][24], int lenx, int leny)
{
	int i;

	i = 0;
	printf("\n\n-------- map : --------\n");
	while (--leny >= 0)
	{
		printf(" y = %2d ", leny);
		while (i < lenx)
		{
			printf("|%2d", map[i][leny]);
			i++;
		}
		printf("|\n");
		i = 0;
	}
	printf("---------------------------\n");
}

void	print_map_ptr(int **map, int lenx, int leny)
{
	int i;

	i = 0;
	printf("\n\n-------- map : --------\n");
	while (--leny >= 0)
	{
		printf(" y = %2d ", leny);
		while (i < lenx)
		{
			printf("|%2d", map[i][leny]);
			i++;
		}
		printf("|\n");
		i = 0;
	}
	printf("---------------------------\n");
}

void	print_sprite(t_sprites *sprite)
{
	printf("\n\n-------- sprite : --------\n");
	printf("x : %f\n", sprite->x);
	printf("y : %f\n", sprite->y);
	printf("drawStartY : %d\n", sprite->drawStartY);
	printf("drawEndY : %d\n", sprite->drawEndY);
	printf("distance : %f\n", sprite->distance);
	printf("---------------------------\n");
}

void	print_sprlist(t_sprites *sprite)
{
	printf("\n\n-------- sprite_list : --------\n");
	while (sprite != NULL)
	{
		print_sprite(sprite);
		sprite = sprite->next;
	}
	printf("------------- end of list --------------\n");
}
