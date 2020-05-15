/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:25:08 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/14 11:12:10 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_precision(char *str, t_args *options)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		++i;
		while (str[i] == '0')
			i++;
		if (str[i] == '*')
		{
			options->field += 10;
			++i;
			return (2);
		}
		if (ft_isdigit(str[i]) == 1)
			get_prec(str, &i, options);
		else
			options->precision = 0;
		i += ft_nbrlen(&(str[i]));
	}
	if (options->precision > -1 && options->type > 2)
		options->zero = 0;
	return (i);
}

static int		ft_get_type(char c)
{
	if (c == 's')
		return (1);
	if (c == 'c')
		return (2);
	if (c == 'd')
		return (3);
	if (c == 'p')
		return (4);
	if (c == 'i')
		return (5);
	if (c == 'u')
		return (6);
	if (c == 'x')
		return (7);
	if (c == 'X')
		return (8);
	if (c == '%')
		return (-1);
	return (0);
}

static int		optionalize(char *format, int i, t_args *options)
{
	int adder;

	adder = 0;
	adder += ft_get_zero(&(format[i]), options);
	adder += ft_get_minus(&(format[i + adder]), options);
	adder += ft_get_width(&(format[i + adder]), options);
	adder += ft_get_precision(&(format[i + adder]), options);
	return (adder);
}

static void		get_field(va_list params, t_args *options)
{
	int temp;

	temp = options->min_width;
	if (options->type != -1)
	{
		if (options->field == 1 || options->field == 11)
		{
			options->min_width = (int)va_arg(params, char*);
			if (temp > 0)
				options->min_width = temp;
			if (options->min_width < 0)
			{
				options->min_width = -(options->min_width);
				options->minus = 1;
				options->zero = 0;
			}
		}
		if (options->field == 10 || options->field == 11)
		{
			options->precision = (int)va_arg(params, char*);
			if (options->precision < 0)
				options->precision = -1;
		}
	}
}

t_args			*get_options(char *format, t_args *options, va_list params)
{
	int		i;
	int		f_len;
	int		check;

	i = 1;
	f_len = get_format_len(&format[i]);
	while (format[i] && i <= f_len)
	{
		check = i;
		i += optionalize(format, i, options);
		if (format[i] == 's' || format[i] == 'd' || format[i] == 'c'
			|| format[i] == 'p' || format[i] == 'i' || format[i] == 'u'
			|| format[i] == 'x' || format[i] == 'X' || format[i] == '%')
		{
			options->type = ft_get_type(format[i]);
			i++;
			break ;
		}
		if (i == check)
			i++;
	}
	get_field(params, options);
	options->size = f_len + 1;
	return (options);
}
