/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_neg_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:30:58 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/12 10:12:00 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		fill_from_index_to_len(int start, char c, int len, char **str)
{
	while (start < len)
	{
		(*str)[start] = c;
		start++;
	}
	return (start);
}

static char		*invert_bits_add_1(char **bit_string)
{
	int	i;
	int	len;
	int	j;

	i = -1;
	len = ft_strlen(*bit_string);
	while ((*bit_string)[++i])
	{
		if ((*bit_string)[i] == '0')
			(*bit_string)[i] = '1';
		else
			(*bit_string)[i] = '0';
	}
	j = len - 1;
	while (j)
	{
		if ((*bit_string)[j] == '0')
		{
			(*bit_string)[j] = '1';
			fill_from_index_to_len(j + 1, '0', len, bit_string);
			break ;
		}
		j--;
	}
	return (*bit_string);
}

char			*get_neg_hex(int nb, int maj)
{
	char				*mlc;
	char				*join;
	int					nbr_len;
	unsigned long long	new_nbr;
	char				buffer[33];

	nb = -nb;
	ft_memset(buffer, '\0', 33);
	if (!(mlc = ft_itoa_base(nb, 2, maj)))
		return (NULL);
	nbr_len = ft_strlen(mlc);
	ft_memset(buffer, '0', 32 - nbr_len);
	if (!(join = ft_strjoin(buffer, mlc)))
		return (NULL);
	invert_bits_add_1(&join);
	ft_strdel(&mlc);
	new_nbr = ft_atoi_base(join, 2);
	ft_strdel(&join);
	if (!(mlc = ft_litoa_base(new_nbr, 16, maj)))
		return (NULL);
	return (mlc);
}
