#include "cub3d.h"

// a verif:
//  - 4 caracteres 0, 1, 2, NSEW
//  -entouré de 1
extern char **tex_tab;
extern int  alloc_check[5];


int     check_first_map(char **line)
{
    int count;
    int i;
    int len;

    i = 0;
    count = 0;
    len = ft_strlen(*line);
    while ((*line)[i])
    {
        if ((*line)[i] == ' ')
            i++;
        else if (i < len && (*line)[i] == '1')
        {
            i++;
            count++;
        }
        else
        {
            ft_strdel(line);
            custom_freetab(&tex_tab);
            return (-1);
        }
    }
    if (count > 0)
        return (1);
    else
        return (0); 
}