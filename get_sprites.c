#include "lodev.h"

extern int	**worldMap;
extern int	mlen;
int			mheight;

//t_sprites	sprite_list;

// faire func init sprite

t_sprites	*get_sprite_list(t_sprites *sprite)
{
	int x;
	int	y;
	int	check;
	t_sprites *deb;

	x = -1;
	y = -1;
	check = -1; // sert juste comme condition pr qu'il aille pas tout le temps dans premiere cond
	while (++x < mlen)
	{
		while (++y < mheight)
		{
			if (worldMap[x][y] == 2)
			{
				if (check == -1)
				{
					if (!(sprite = (t_sprites*)malloc(sizeof(t_sprites))))
						return (NULL);
					sprite->first = sprite;
					sprite->prev = NULL;
					sprite->x = (double)x;
					sprite->y = (double)y;
					++check;
				}
				else
				{
					if (!(sprite->next = (t_sprites*)malloc(sizeof(t_sprites))))
						return (NULL);
					sprite->next->x = (double)x;
					sprite->next->y = (double)y;
					sprite->next->prev = sprite;
					sprite->next->first = sprite->first;
					sprite = sprite->next;
//					print_sprite(sprite->first);
				}
//				print_sprite(sprite);
			}
		}
		y = 0;
	}
	sprite->next = NULL;
	sprite = sprite->first;
	return (sprite);
}
