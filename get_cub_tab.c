#include "cub3d.h"

int    mlen;
int    mheight;
int    pos_check = 0;
extern char   **tex_tab;
extern int    **worldMap;

void    int_set(int **dst, int nbr, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        (*dst)[i] = nbr;
        i++;
    }
}

int     set_int_tab(void)
{
    int i;

    i = 0;
    if (!(worldMap = (int**)malloc(sizeof(int*) * mlen + 1)))
        return (-1);
    while (i < mlen)
    {
        if (!(worldMap[i] = (int*)malloc(sizeof(int) * mheight + 1)))
            return (free_int_ret(&worldMap, i - 1));
        int_set(&(worldMap[i]), -6, mheight);
        i++;
    }
    return (1);
}

void    set_mlen_mheight(char **tab, int i)
{
    int len;
    int slen;

    len = ft_tablen(tab);
    mlen = 0;
    mheight = 0;
    ft_printf("tablen : %d\n", len);
    while (i < len)
    {
       if (ft_strchr(tab[i], '1') != NULL)
       {
           mheight++;
           slen = ft_strlen(tab[i]);
           if (slen > mlen)
                mlen = slen;
       }
       i++;
    }
}

int     set_map(char **tab, int i, t_fov *fov)
{
    set_mlen_mheight(tab, i);
    if ((set_int_tab()) == -1)
        return (-1);
    fill_map(&(tab[i]), fov);
    verify_int_map(&worldMap, mlen, mheight);
    return (3);
}

char    **get_cub_tab(int fd)
{
    char    **tab;
    int     ret;
    char    buf[251];
    char    *str;

    ret = read(fd, buf, 250);
    if (ret == -1)
        return (NULL);
    buf[ret] = '\0';
    if (!(str = ft_strdup(buf)))
        return (NULL);
    while (ret == 250)
    {
        ret = read(fd, buf, 250);
        buf[ret] = '\0';
        if (!(str = ft_join_free_left(&str, buf)))
            return (NULL);
    }
    if (!(tab = ft_cub_split(str, '\n')))
    {
        ft_strdel(&str);
        return (NULL);
    }
    ft_strdel(&str);
//    ft_printtab(tab);
    return (tab);
}