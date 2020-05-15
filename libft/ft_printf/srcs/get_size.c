/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:23:19 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/10 14:36:24 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			neg_check(int nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

static int			long_long_neg_check(long long int nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

int					base_len(int nb, int base)
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

int					long_long_base_len(long long int nb, int base)
{
	int	count;

	count = 0;
	if (long_long_neg_check(nb) == 1)
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

int					ft_get_size(char *arg, t_args *options)
{
	if (options->type == 1)
		return (ft_strlen(arg));
	if (options->type == 2)
		return (1);
	if (options->type == 3 || options->type == 5)
		return (base_len((int)arg, 10));
	if (options->type == 4)
		return (long_long_base_len((long long int)arg, 16) + 2);
	if (options->type == 6)
		return (base_len((unsigned int)arg, 10));
	if (options->type == 7 || options->type == 8)
		return (base_len((unsigned int)arg, 16));
	return (0);
}
