#include "cub3d.h"
extern char **tex_tab;
extern int  screenHeight;
extern int  screenWidth;
extern int  alloc_check[5];

int     get_north(char ***tab)
{
    if (ft_tablen(*tab) != 2)
    {
        custom_freetab(&tex_tab);
        new_freetab(tab);
        error_quit("Error: Invalid north texture format", tab);
    }
    add_tex_num((*tab)[1], 0);
    alloc_check[0] = 1;
    ft_freetab(tab);
//    ft_strdel(line);
    return (0);
}

int     get_south(char ***tab)
{
    if (ft_tablen(*tab) != 2)
    {
        custom_freetab(&tex_tab);
        new_freetab(tab);
        error_quit("Error: Invalid south texture format", tab);
    }
    add_tex_num((*tab)[1], 1);
    ft_freetab(tab);
    alloc_check[1] = 1;
//    ft_strdel(line);
    return (0);
}

int     get_west(char ***tab)
{
    if (ft_tablen(*tab) != 2)
   {
        custom_freetab(&tex_tab);
        new_freetab(tab);
        error_quit("Error: Invalid west texture format", tab);
    } 
    add_tex_num((*tab)[1], 2);
    ft_freetab(tab);
    alloc_check[2] = 1;
  //  ft_strdel(line);
    return (0);
}

int     get_east(char ***tab)
{
    if (ft_tablen(*tab) != 2)
    {
        custom_freetab(&tex_tab);
        new_freetab(tab);
        error_quit("Error: Invalid east texture format", tab);
    }
    add_tex_num((*tab)[1], 3);
    ft_freetab(tab);
    alloc_check[3] = 1;
//    ft_strdel(line);
    return (0);
}

int     get_sprite(char ***tab)
{
    if (ft_tablen(*tab) != 2)
    {
        custom_freetab(&tex_tab);
        new_freetab(tab);
        error_quit("Error: Invalid sprite texture format", tab);
    }
    add_tex_num((*tab)[1], 4);
    ft_freetab(tab);
    alloc_check[4] = 1;
    return (0);
}