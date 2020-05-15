/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:22:16 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/10 13:22:33 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			neg_check(long long int nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

static int			long_base_len(long long int nb, int base)
{
	int	count;

	count = 0;
	if (neg_check(nb) == 1)
	{
		count++;
		nb = -nb;
	}
	while ((nb / base) > 0)
	{
		count++;
		nb = nb / base;
	}
	count++;
	return (count);
}

static char			capitalize_if(char c, int hex_maj)
{
	if (hex_maj == 1)
		c = c - 32;
	return (c);
}

static char			get_hex_char(int n, int hex_maj)
{
	if (n == 10)
		return (capitalize_if('a', hex_maj));
	if (n == 11)
		return (capitalize_if('b', hex_maj));
	if (n == 12)
		return (capitalize_if('c', hex_maj));
	if (n == 13)
		return (capitalize_if('d', hex_maj));
	if (n == 14)
		return (capitalize_if('e', hex_maj));
	if (n == 15)
		return (capitalize_if('f', hex_maj));
	return (n + '0');
}

char				*ft_litoa_base(long long int n, int base, int hex_maj)
{
	char			*mlc;
	int				n_char;
	long long int	nb;

	nb = n;
	n_char = long_base_len(n, base);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (neg_check(n) == 1 && base == 16)
		return (get_neg_hex(nb, hex_maj));
	if (!(mlc = ft_strnew(n_char)))
		return (NULL);
	mlc[n_char] = '\0';
	while (--n_char > 0)
	{
		mlc[n_char] = get_hex_char((n % base), hex_maj);
		n = n / base;
	}
	if (neg_check(nb) == 1)
		mlc[0] = '-';
	else
		mlc[0] = get_hex_char((n % (base * base)), hex_maj);
	return (mlc);
}
