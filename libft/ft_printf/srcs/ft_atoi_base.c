/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:12:48 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/10 13:14:10 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

long long int	ft_atoi_base(const char *str, int base)
{
	unsigned long int	i;
	long long int		nb;
	long long int		check;
	int					len;

	nb = 0;
	i = 0;
	check = 1;
	len = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || \
			str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			check = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= (base - 1) + '0')
	{
		nb = nb * base + (check * (long long int)(str[i] - '0'));
		i++;
		len++;
	}
	return (nb);
}
