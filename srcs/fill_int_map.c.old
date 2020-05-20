#include "cub3d.h"
extern int **g_worldmap;
extern int g_mlen;
extern int g_mheight;
extern int pos_check;

int	 fill_map(char **tab, t_fov *fov)
{
	int xm;
	int ym;
	int xt;
	int yt;
	int len_line;

	xm = 0;
	ym = 0;
	xt = g_mheight -1;
	yt = 0;
	while (ym < g_mheight)
	{
		while (xm < g_mlen)
		{
//			ft_printf("tab[%d] : %s\n", xt, tab[xt]);
			len_line = ft_strlen(tab[xt]);
			if (yt < len_line)
			{
				if (ym == 0 || ym == g_mheight)
					get_right_char_first(tab[xt][yt], xm, ym);
				else
					get_right_char_mid(tab[xt][yt], xm, ym, fov);
			}
			xm++;
			yt++;
		}
//		print_map_ptr(g_worldmap, g_mlen, g_mheight);
		xm = 0;
		yt = 0;
		ym++;
		xt--;
	}
	return (0);
	print_map_ptr(g_worldmap, g_mlen, g_mheight);
}
