#include "lodev.h"

int     check_fov_char(char c)
{
    if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (1);
    return (0);
}

int     verify_int_map(int  ***map, int mlen, int mheight)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < mheight)
    {
        while (x < mlen)
        {
            if ((*map)[x][y] == 0 || check_fov_char((*map)[x][y]) == 1
                || (*map)[x][y] == 2)
            {
                if (x == 0 || x >= mlen -1 || (*map)[x - 1][y] == -6 
                    || (*map)[x + 1][y] == -6 || y == 0 || y >= mheight - 1
                    || (*map)[x][y + 1] == -6 || (*map)[x][y - 1] == -6)
                {
                    free_int_tab(map, mlen);
                    error_quit("Error : invalid map", NULL);
                }
            }
            x++;
        }
        x = 0;
        y++;
    }
    return (1);
}