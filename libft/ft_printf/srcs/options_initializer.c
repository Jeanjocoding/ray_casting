/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:42:08 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/10 16:09:04 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	options_reinitializer(t_args *options)
{
	options->type = 0;
	options->minus = 0;
	options->zero = 0;
	options->precision = -1;
	options->min_width = 0;
	options->size = 0;
	options->error = 0;
	options->field = 0;
	options->modif_null = 0;
	options->nbr_nulls = 0;
	return (1);
}
