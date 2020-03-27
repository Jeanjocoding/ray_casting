#include "cub3d.h"

t_sprites	*get_sprite_distance(t_sprites *sprite, t_fov *fov)
{
	t_sprites	*first;
	first = sprite->first;
	while (sprite != NULL)
	{
		sprite->distance = (fov->posX - sprite->x) * (fov->posX - sprite->x) + (fov->posY - sprite->y) * (fov->posY - sprite->y);
		sprite = sprite->next;
	}
	return (first);
}
