#include "cub3d.h"
#include <stdio.h>

void 	print_ray(t_ray *ray)
{
	printf("\n\n-------- ray : --------\n");
	printf("ray->camerax : %f\n", ray->camerax);
	printf("ray->raydirx : %f\n", ray->raydirx);
	printf("ray->raydiry : %f\n", ray->raydiry);
	printf("ray->sidedistx : %f\n", ray->sidedistx);
	printf("ray->sidedisty : %f\n", ray->sidedisty);
	printf("ray->deltadistx : %f\n", ray->deltadistx);
	printf("ray->deltadisty : %f\n", ray->deltadisty);
	printf("ray->stepx : %f\n", ray->stepx);
	printf("ray->stepy : %f\n", ray->stepy);
	printf("ray->mapx : %d\n", ray->mapx);
	printf("ray->mapy : %d\n", ray->mapy);
	printf("ray->hit : %d\n", ray->hit);
	printf("ray->side : %d\n", ray->side);
	printf("ray->walldist : %f\n", ray->walldist);
	printf("ray->lineheight : %d\n", ray->lineheight);
	printf("ray->linebottom : %d\n", ray->linebottom);
	printf("ray->linetop : %d\n", ray->linetop);
	printf("---------------------------\n");
}

void 	print_fov(t_fov *fov)
{
	printf("\n\n-------- fov : --------\n");
	printf(" fov->posx: %f\n", fov->posx);
	printf(" fov->posy: %f\n", fov->posy);
	printf(" fov->dirx: %f\n", fov->dirx);
	printf(" fov->diry: %f\n", fov->diry);
	printf(" fov->planex: %f\n", fov->planex);
	printf(" fov->planey: %f\n", fov->planey);
	printf(" fov->time: %f\n", fov->time);
	printf(" fov->oldtime: %f\n", fov->oldtime);
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
	printf("drawstarty : %d\n", sprite->drawstarty);
	printf("drawendy : %d\n", sprite->drawendy);
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
