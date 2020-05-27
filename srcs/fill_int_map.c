#include "cub3d.h"
#include "string.h"

extern int **g_worldmap;
extern int g_mlen;
extern int g_mheight;
extern int g_pos_check;

int		put_the_cell(char c, int xm, int ym, t_fov *fov)
{
	if (ym == 0 || ym == g_mheight)
		get_right_char_first(c, xm, ym);
	else
		get_right_char_mid(c, xm, ym, fov);
	return (0);
}

/*int		fill_map(char **tab, t_fov *fov)
{
	int xm;
	int ym;
	int xt;
	int yt;
	int len_line;

	xm = 0;
	ym = -1;
	xt = g_mheight - 1;
	yt = 0;
	while (++ym < g_mheight)
	{
		while (xm < g_mlen)
		{
			len_line = ft_strlen(tab[xt]);
			if (yt < len_line)
				put_the_cell(tab[xt][yt], xm, ym, fov);
			xm++;
			yt++;
		}
		xm = 0;
		yt = 0;
		xt--;
	}
	print_map_ptr(g_worldmap, g_mlen, g_mheight);
	return (0);
}*/

int		fill_map(char **tab, t_fov *fov)
{
	int xm;
	int ym;
	int xt;
	int yt;
	int len_line;

	ft_printtab(tab);
	xm = 0;
	ym = -1;
	xt = g_mheight - 1;
	yt = 0;
	while (++ym < g_mheight)
	{
		while (xm < g_mlen)
		{
			len_line = ft_strlen(tab[xt]);
			if (yt < len_line)
				put_the_cell(tab[xt][yt], xm, ym, fov);
			xm++;
			yt++;
		}
		xm = 0;
		yt = 0;
		xt--;
	}
	print_map_ptr(g_worldmap, g_mlen, g_mheight);
	return (0);
}

/*int		fill_map(char **tab, t_fov *fov)
{
	int xm;
	int ym;
	int xt;
	int yt;
	int len_line;

	xm = 0;
	ym = g_mheight;
	xt = g_mheight - 1;
	yt = 0;
	while (--ym >= 0)
	{
		while (xm < g_mlen)
		{
			len_line = ft_strlen(tab[xt]);
			if (yt < len_line)
				put_the_cell(tab[xt][yt], xm, ym, fov);
			xm++;
			yt++;
		}
		xm = 0;
		yt = 0;
		xt--;
	}
	print_map_ptr(g_worldmap, g_mlen, g_mheight);
	return (0);
}*/

/*int		fill_map(char **tab, t_fov *fov)
{
	int xm;
	int ym;
	int xt;
	int yt;
	int len_line;

	xm = 0;
	ym = -1;
	xt = 0;
	yt = 0;
	while (++ym < g_mheight)
	{
		while (xm < g_mlen)
		{
			len_line = ft_strlen(tab[xt]);
			if (yt < len_line)
				put_the_cell(tab[xt][yt], xm, ym, fov);
			xm++;
			yt++;
		}
		xm = 0;
		yt = 0;
		xt++;
	}
	print_map_ptr(g_worldmap, g_mlen, g_mheight);
	return (0);
}*/
