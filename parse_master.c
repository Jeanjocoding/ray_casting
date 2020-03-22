#include "lodev.h"
extern char **tex_tab;
extern int  screenHeight;
extern int  screenWidth;
//int         north_ok;
//int         

int     error_quit(char *msg, char ***tab)
{
    ft_printf("%s\n", msg);
    ft_freetab(tab);
    exit(1);
    return (1);
}

int     check_all_digit(char *str)
{
    while (*str)
    {
        if (ft_isdigit(*str) == 0)
            return (-1);
        str++;
    }
    return (1);
}

int     get_res(char ***tab)
{
    if (check_all_digit((*tab)[1]) == -1
        || check_all_digit((*tab)[2]) == -1)
        error_quit("error: invalid resolution format", tab);
    screenWidth = ft_atoi((*tab)[1]);
    screenHeight = ft_atoi((*tab)[2]);
    return (1);
}

int     get_right_func(char **line)
{
    char    **tab;

    if (*line == NULL || (*line)[0] == '\0')
        return (0);
    if (!(tab = ft_split(*line, ' ')))
        return (-1);
    ft_strdel(line);
    if (ft_strcmp(tab[0], "R") == 0)
        return (get_res(&tab));
    if (ft_strcmp(tab[0], "NO") == 0)
        return (get_north(&tab));
    if (ft_strcmp(tab[0], "SO") == 0)
        return (get_south(&tab));
    if (ft_strcmp(tab[0], "WE") == 0)
        return (get_west(&tab));
    if (ft_strcmp(tab[0], "EA") == 0)
        return (get_east(&tab));
    if (ft_strcmp(tab[0], "S") == 0)
        return (get_sprite(&tab));
    if (ft_strcmp(tab[0], "F") == 0)
        return (get_floor(&tab));
    if (ft_strcmp(tab[0], "C") == 0)
        return (get_ceiling(&tab));
//    ft_freetab(&tab);
    return (0);
}

int     parse_master(int fd)
{
    int     ret;
    char    *line;

    ret = 1;
    while (ret > 0)
    {
        ret = get_next_line(fd, &line);
        if (get_right_func(&line) == -1)
            return (-1);
    }
    return (1);
}