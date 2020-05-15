/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:37:33 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/10 13:16:28 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		neg_check(long long int nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

static int		litoa_counter(long long int nb)
{
	int	count;

	count = 0;
	if (neg_check(nb) == 1)
	{
		count++;
		nb = -nb;
	}
	while ((nb / 10) > 0)
	{
		count++;
		nb = nb / 10;
	}
	count++;
	return (count);
}

char			*ft_litoa(long long int n)
{
	char			*mlc;
	int				n_char;
	long long int	nb;

	nb = n;
	n_char = litoa_counter(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (neg_check(n) == 1)
		n = -n;
	if (!(mlc = ft_strnew(n_char)))
		return (NULL);
	mlc[n_char] = '\0';
	while (--n_char > 0)
	{
		mlc[n_char] = (n % 10) + '0';
		n = n / 10;
	}
	if (neg_check(nb) == 1)
		mlc[0] = '-';
	else
		mlc[0] = (n % 100) + '0';
	return (mlc);
}
