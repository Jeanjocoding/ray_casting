#include "cub3d.h"
extern char **tex_tab;
extern int  screenHeight;
extern int  screenWidth;

int     get_north(char ***tab)
{
    if (ft_tablen(*tab) != 2)
        error_quit("Error: Invalid north texture format", tab);
    add_tex_num((*tab)[1], 0);
    ft_freetab(tab);
//    ft_strdel(line);
    return (0);
}

int     get_south(char ***tab)
{
    if (ft_tablen(*tab) != 2)
        error_quit("Error: Invalid south texture format", tab);
    add_tex_num((*tab)[1], 1);
    ft_freetab(tab);
//    ft_strdel(line);
    return (0);
}

int     get_west(char ***tab)
{
    if (ft_tablen(*tab) != 2)
        error_quit("Error: Invalid west texture format", tab);
    add_tex_num((*tab)[1], 2);
    ft_freetab(tab);
  //  ft_strdel(line);
    return (0);
}

int     get_east(char ***tab)
{
    if (ft_tablen(*tab) != 2)
        error_quit("Error: Invalid east texture format", tab);
    add_tex_num((*tab)[1], 3);
    ft_freetab(tab);
//    ft_strdel(line);
    return (0);
}

int     get_sprite(char ***tab)
{
    if (ft_tablen(*tab) != 2)
        error_quit("Error: Invalid sprite texture format", tab);
    add_tex_num((*tab)[1], 4);
    ft_freetab(tab);
//    ft_strdel(line);
    return (0);
}