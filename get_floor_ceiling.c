#include "lodev.h"
extern int  ground;
extern int  ceiling;

int		get_rgb(int r, int g, int b)
{
    int rgb;

    rgb = r;
    rgb = (rgb << 8) + g;
    rgb = (rgb << 8) + b;
    return (rgb);
}

int     get_floor(char ***tab, char **line)
{
    int R;
    int G;
    int B;
    char **tab2;

  //  ft_strdel(line);
    if (ft_tablen(*tab) != 2)
        error_quit("Error: invalid floor format", tab);
    if (!(tab2 = ft_split((*tab)[1], ',')))
        return (-1);
    ft_freetab(tab);
    if (check_all_digit(tab2[0]) == -1
        || check_all_digit(tab2[1]) == -1
        || check_all_digit(tab2[2]) == -1)
        error_quit("Error: invalid floor format", tab);
    R = ft_atoi(tab2[0]);
    G = ft_atoi(tab2[1]);
    B = ft_atoi(tab2[2]);
    ground = get_rgb(R, G, B);
    ft_freetab(&tab2);
    return (1);
}

int     get_ceiling(char ***tab, char **line)
{
    int R;
    int G;
    int B;
    char **tab2;

//    ft_strdel(line);
    if (ft_tablen(*tab) != 2)
        error_quit("Error: invalid ceiling format", tab);
    if (!(tab2 = ft_split((*tab)[1], ',')))
        return (-1);
    ft_freetab(tab);
    if (check_all_digit(tab2[0]) == -1
        || check_all_digit(tab2[1]) == -1
        || check_all_digit(tab2[2]) == -1)
        error_quit("Error: invalid ceiling format", tab);
    R = ft_atoi(tab2[0]);
    G = ft_atoi(tab2[1]);
    B = ft_atoi(tab2[2]);
    ceiling = get_rgb(R, G, B);
    ft_freetab(&tab2);
    return (1);
}