#include "cub3d.h"
extern int **worldMap;
extern int mlen;
extern int mheight;
extern int pos_check;

int     get_right_char_first(char c, int x, int y)
{
    if (c == '1')
        worldMap[x][y] = 1;
    else if (c != ' ')
    {
       free_int_tab(&worldMap, mlen) ;
       error_quit("Error : invalid map", NULL);
    }
    return (0);
}

int     get_right_char_mid(char c, int x, int y, t_fov *fov) //marche pas car faut deja carte remplie avant de vérif
{
    if (c == '1')
        worldMap[x][y] = 1;
    else if (c == '0' || c == '2')
    {
            worldMap[x][y] = c - '0';
    }
    else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
    {
        if (set_fov(c, fov, x, y) == -1)
        {
            free_int_tab(&worldMap, mlen) ;
            error_quit("Error : two different initial positions", NULL);
        }
        worldMap[x][y] = 0;
    }
    else if (c != ' ')
    {
       free_int_tab(&worldMap, mlen) ;
       error_quit("Error : invalid map, uknown object number", NULL);
    }
    return (0);
}
