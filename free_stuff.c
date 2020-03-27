#include "cub3d.h"

void	free_tex_list(t_data *list, t_vars *vars)
{
    t_data *temp;
    int     i;

    i = 1;
    list = list->first;
    ft_printf("int ptr : %d\n", list->int_ptr[0]);
    list = list->next;
    ft_printf("int ptr : %d\n", list->int_ptr[0]);
    while (i < 5)
    {
        temp = list->next;
        mlx_destroy_image(vars->mlx, list->img);
//        ft_printf("int ptr : %d\n", list->int_ptr[0]);
//        if (list->int_ptr[0] > 0)

        free(list);
        list = temp;
        i++;
    }
}

void    free_sprites(t_sprites *sprites)
{
    t_sprites   *temp;

    while (sprites->prev != NULL)
        sprites = sprites->prev;
    while (sprites->next != NULL)
    {
        temp = sprites->next;
        free(sprites);
        sprites = NULL;
        sprites = temp;
    }
    free(sprites);
    sprites = NULL;
}