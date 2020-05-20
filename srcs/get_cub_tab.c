#include "cub3d.h"

int    g_mlen;
int    g_mheight;
int    g_pos_check = 0;
extern char   **g_tex_tab;
extern int    **g_worldmap;

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
    if (!(g_worldmap = (int**)malloc(sizeof(int*) * g_mlen + 1)))
        return (-1);
    while (i < g_mlen)
    {
        if (!(g_worldmap[i] = (int*)malloc(sizeof(int) * g_mheight + 1)))
            return (free_int_ret(&g_worldmap, i - 1));
        int_set(&(g_worldmap[i]), -6, g_mheight);
        i++;
    }
    return (1);
}

void    set_g_mlen_g_mheight(char **tab, int i)
{
    int len;
    int slen;

    len = ft_tablen(tab);
    g_mlen = 0;
    g_mheight = 0;
    while (i < len)
    {
       if (ft_strchr(tab[i], '1') != NULL)
       {
           g_mheight++;
           slen = ft_strlen(tab[i]);
           if (slen > g_mlen)
                g_mlen = slen;
       }
       i++;
    }
}

int     set_map(char **tab, int i, t_fov *fov)
{
    set_g_mlen_g_mheight(tab, i);
    if ((set_int_tab()) == -1)
        return (-1);
    fill_map(&(tab[i]), fov);
    verify_int_map(&g_worldmap, g_mlen, g_mheight);
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
