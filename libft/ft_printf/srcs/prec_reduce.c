/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_reduce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:05:22 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/14 11:10:37 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_prec(char *str, int *i, t_args *options)
{
	options->precision = ft_atoi(&(str[(*i)]));
	if (options->precision == 0)
		(*i)++;
	return (*i);
}
