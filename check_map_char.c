#include "lodev.h"
extern int **worldMap;
extern int mlen;
extern int mheight;
extern int pos_check;

int     set_fov(char c, t_fov *fov, int x, int y)
{
    if (pos_check > 0)
        return (-1);
	fov->posX = 1.0 * x;
	fov->posY = 1.0 * y;
    if (c == 'N')
    {
	    fov->dirX = 0;
	    fov->dirY = 1;
    }
    if (c == 'S')
    {
	    fov->dirX = 0;
	    fov->dirY = -1;
    }
    if (c == 'E')
    {
	    fov->dirX = 1;
	    fov->dirY = 0;
    }
    if (c == 'W')
    {
	    fov->dirX = 0;
	    fov->dirY = -1;
    }
	fov->planeX = 0;
	fov->planeY = 0.66;
	fov->time = 0;
	fov->oldTime = 0;
    worldMap[x][y] = 0;
	return (0);
}

int     get_right_char_first(char c, int x, int y, t_fov *fov)
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
/*        if (x == 0 || x >= mlen -1 || temp_map[x - 1][y] == -6 
            || temp_map[x + 1][y] == -6 || y == 0 || y >= mheight - 1
            || temp_map[x][y + 1] == -6 || temp_map[x][y - 1] == -6)
            free_int_tab(&temp_map, mlen);
            error_quit("Error : invalid map", NULL);
        else*/
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
