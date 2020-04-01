#include "cub3d.h"

// a verif:
//  - 4 caracteres 0, 1, 2, NSEW
//  -entouré de 1

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
            error_quit("Error: wrong map formatting", NULL);
        }
    }
    if (count > 0)
    {
        ft_printf("first line map: %s\n", *line);
        return (1);
    }
    else
        return (0); 
}