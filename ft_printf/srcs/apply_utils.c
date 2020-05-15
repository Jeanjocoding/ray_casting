/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:24:20 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/12 10:25:27 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			get_padded_char(t_args *options)
{
	if (options->zero == 0 || (options->zero == 1 && options->precision > -1)
		|| (options->type > 2 && options->precision > 0))
		return (' ');
	else
		return ('0');
}

int				ft_biggest(int n, int m)
{
	if (n > m)
		return (n);
	else
		return (m);
}

void			joiner_init(char joiner[])
{
	joiner[0] = '0';
	joiner[1] = 'x';
	joiner[2] = '\0';
}

static int		get_pad_with_prec(t_args *options, int len)
{
	int pad;

	pad = 0;
	if (options->type > 2)
		pad = options->min_width - ft_biggest(len, options->precision);
	else
	{
		if (options->precision >= len)
			pad = options->min_width - len;
		else
			pad = options->min_width - options->precision;
	}
	return (pad);
}

int				pad_calculator(char *asciized_param, t_args *options)
{
	int	pad;
	int	len;

	len = ft_strlen(asciized_param);
	if (len == 1 && asciized_param[0] == '0'
		&& options->precision == 0)
		len--;
	if (options->precision >= 0)
		pad = get_pad_with_prec(options, len);
	else
	{
		if (len == 0 && options->modif_null == 1)
			len = 1;
		pad = options->min_width - len;
	}
	if (pad < 0)
		pad = 0;
	return (pad);
}
