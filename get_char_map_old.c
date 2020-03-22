#include "lodev.h"

int     map_nbr_lines;
int     longest_line;


int     get_lmap_elem(int fd, t_lmap *map_ptr, t_lmap *prev)
{
    if (!(map_ptr = (t_lmap*)malloc(sizeof(t_lmap))))
        return (NULL);
    ret = get_next_line(fd, &(map_ptr->content));
    map_ptr->size = ft_strlen(map_ptr->content);
    map_ptr->prev = prev;
    return (ret);
}

t_lmap      *list_map(int fd)
{
    t_lmap  list;
    t_lmap  list_ptr;
    int     ret;

    if (!(list = (t_lmap)malloc(sizeof(t_lmap))))
        return (NULL);
    ret = get_next_line(fd, &(list.content));
    list.size = ft_strlen(list.content);
    list.prev = NULL;
    list_ptr = &list;
    while (ret > 0)
    {
        ret = get_lmap_elem(fd, list_ptr->next, list_ptr);
        list_ptr = list_ptr->next;
    }
    while (list_ptr->prev != NULL)
        list_ptr = list_ptr->prev;    
}