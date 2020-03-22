#include "lodev.h"
extern char **tex_tab;
extern int  screenHeight;
extern int  screenWidth;

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

int     get_north(char ***tab)
{
    if (ft_tablen(*tab) != 2)
        error_quit("Error: Invalid north texture format", tab);
    add_tex_num((*tab)[1], 0);
    return (0);
}

int     get_south(char ***tab)
{
    if (ft_tablen(*tab) != 2)
        error_quit("Error: Invalid south texture format", tab);
    add_tex_num((*tab)[1], 1);
    return (0);
}

int     get_west(char ***tab)
{
    if (ft_tablen(*tab) != 2)
        error_quit("Error: Invalid west texture format", tab);
    add_tex_num((*tab)[1], 2);
    return (0);
}

int     get_east(char ***tab)
{
    if (ft_tablen(*tab) != 2)
        error_quit("Error: Invalid east texture format", tab);
    add_tex_num((*tab)[1], 3);
    return (0);
}

int     get_sprite(char ***tab)
{
    if (ft_tablen(*tab) != 2)
        error_quit("Error: Invalid sprite texture format", tab);
    add_tex_num((*tab)[1], 4);
    return (0);
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
        return (-1);
    if (!(tab = ft_split(*line, ' ')))
        return (-1);
    ft_strdel(line);
//    ft_printtab(tab);
    if (ft_strcmp(tab[0], "R") == 0)
        get_res(&tab);
    if (ft_strcmp(tab[0], "NO") == 0)
        get_north(&tab);
    if (ft_strcmp(tab[0], "SO") == 0)
        get_south(&tab);
    if (ft_strcmp(tab[0], "WE") == 0)
        get_west(&tab);
    if (ft_strcmp(tab[0], "EA") == 0)
        get_east(&tab);
    if (ft_strcmp(tab[0], "S") == 0)
        get_sprite(&tab);
    ft_freetab(&tab);
    return (0);
}

int     parse_master(int fd)
{
    int     ret;
    char    *line;
    char    id[3];

    ret = 1;
    ft_memset(id, '\0', 3);
    while (ret > 0)
    {
        ret = get_next_line(fd, &line);
        get_right_func(&line);
    }
    return (1);
}