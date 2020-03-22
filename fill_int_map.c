#include "lodev.h"
extern int **worldMap;
extern int mlen;
extern int mheight;
extern int pos_check;

int     fill_map(char **tab, t_fov *fov)
{
    int xm;
    int ym;
    int xt;
    int yt;
    int len_line;

    xm = 0;
    ym = 0;
    xt = mheight -1;
    yt = 0;
    while (ym < mheight)
    {
        while (xm < mlen)
        {
            ft_printf("tab[%d] : %s\n", xt, tab[xt]);
            len_line = ft_strlen(tab[xt]);
            if (yt < len_line)
            {
                if (ym == 0 || ym == mheight)
                    get_right_char_first(tab[xt][yt], xm, ym, fov);
                else
                    get_right_char_mid(tab[xt][yt], xm, ym, fov);
            }
            xm++;
            yt++;
        }
        print_map_ptr(worldMap, mlen, mheight);
        xm = 0;
        yt = 0;
        ym++;
        xt--;
    }
    return (0);
}