#include "cub3d.h"

t_sprites	*get_sprite_distance(t_sprites *sprite, t_fov *fov)
{
	t_sprites	*first;

	first = sprite->first;
	while (sprite != NULL)
	{
		sprite->distance = (fov->posx - sprite->x) *
			(fov->posx - sprite->x) + (fov->posy - sprite->y) *
			(fov->posy - sprite->y);
		sprite = sprite->next;
	}
	return (first);
}
