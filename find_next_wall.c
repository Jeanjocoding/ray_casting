extern int res_vert;
extern int res_hor;
extern int map_len;
int *pos;

char	**mapper(char str);

/*int		*find_next_wall(int pos, int pente, char **map)
{
	
}*/

int		get_pixls_per_sq(int res_hor, int map_len)
{
	int pxls;

	pxls = res_hor / map_len;
	return (pxls);
}

int		get_next_x(int pos_x, 
{
	int	pxls;

	pxls = get_pixls_per_sq(res_hor, map_len);
	return (pxls);
}

int		*find_next_x_intersec(int *pos, int pente, char **map)
{
	int *intersec;
	int	temp1;
	int	temp2;
	int	pxls;

	if (pente > 0)
	{
		
	}
}
