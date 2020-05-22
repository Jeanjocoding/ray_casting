#include "cub3d.h"

extern int	**g_worldmap;
extern int	g_mlen;
int			g_mheight;
double		g_add_to_pos = 0.5;

t_sprites	*create_first_sprite(t_sprites *sprite, int x, int y, int *check)
{
	if (!(sprite = (t_sprites*)malloc(sizeof(t_sprites))))
		return (NULL);
	sprite->first = sprite;
	sprite->prev = NULL;
	sprite->x = (double)x + g_add_to_pos;
	sprite->y = (double)y + g_add_to_pos;
	(*check)++;
	return (sprite);
}

t_sprites	*add_sprite(t_sprites *sprite, int x, int y)
{
	if (!(sprite->next = (t_sprites*)malloc(sizeof(t_sprites))))
		return (NULL);
	sprite->next->x = (double)x + g_add_to_pos;
	sprite->next->y = (double)y + g_add_to_pos;
	sprite->next->prev = sprite;
	sprite->next->first = sprite->first;
	sprite = sprite->next;
	return (sprite);
}

t_sprites	*put_adequate_sprite(t_sprites *sprite, int x, int y, int *check)
{
	if (*check == -1)
		sprite = create_first_sprite(sprite, x, y, check);
	else
		sprite = add_sprite(sprite, x, y);
	return (sprite);
}

t_sprites	*get_sprite_list(t_sprites *sprite)
{
	int x;
	int	y;
	int	check;

	x = -1;
	y = -1;
	check = -1;
	while (++x < g_mlen)
	{
		while (++y < g_mheight)
		{
			if (g_worldmap[x][y] == 2)
			{
				sprite = put_adequate_sprite(sprite, x, y, &check);
				if (sprite == NULL)
					return (NULL);
			}
		}
		y = 0;
	}
	sprite->next = NULL;
	sprite = sprite->first;
	return (sprite);
}
