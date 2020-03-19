#include "lodev.h"

t_sprites	*swap_node(t_sprites *a, t_sprites *b)
{
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
	if (b->prev != NULL)
		b->prev->next = b;
	if (a->next != NULL)
		a->next->prev = a;
	return (b);
}

t_sprites	*sort_sprites(t_sprites *list)
{
	while (list->next != NULL && list->distance >= list->next->distance)
		list = list->next;
	if (list->next == NULL)
	{
		while (list->prev != NULL)
			list = list->prev;
		return (list);
	}
	else
	{
		list = swap_node(list, list->next);

		if (list->prev != NULL)
			return (sort_sprites(list->prev));
		else
		{
//			print_sprite(list);
			return (sort_sprites(list));
		}

	}
}
