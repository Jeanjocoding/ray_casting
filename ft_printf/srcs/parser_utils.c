/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:24:55 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/10 14:51:50 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_width(char *str, t_args *options)
{
	int	i;

	i = 0;
	if (options->min_width > 0)
		options->error = 1;
	if (str[i] == '*')
	{
		options->field = 1;
		return (1);
	}
	if (ft_isdigit(str[i]) == 1 && str[i] != '0')
	{
		if (options->min_width > 0)
			options->error = 1;
		options->min_width = ft_atoi(str);
	}
	i = ft_nbrlen(str);
	return (i);
}

int	ft_nbrlen(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '0')
	{
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

int	get_format_len(char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == 's' || format[i] == 'd' || format[i] == 'c'
			|| format[i] == 'p' || format[i] == 'i' || format[i] == 'u'
			|| format[i] == 'x' || format[i] == 'X' || format[i] == '%')
			return (++i);
		i++;
	}
	return (0);
}

int	ft_get_minus(char *str, t_args *options)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		if (options->minus > 0)
			options->error = 3;
		options->minus = 1;
		++i;
	}
	if (options->minus == 1)
		options->zero = 0;
	return (i);
}

int	ft_get_zero(char *str, t_args *options)
{
	int	i;

	i = 0;
	if (options->zero > 0)
		options->error = 4;
	if (str[i] == '0' && ft_isdigit(str[i - 1]) != 1 && str[i - 1] != '.')
	{
		options->zero = 1;
		++i;
	}
	if (options->minus == 1)
		options->zero = 0;
	if (options->precision > -1 && options->type > 2)
		options->zero = 0;
	return (i);
}
