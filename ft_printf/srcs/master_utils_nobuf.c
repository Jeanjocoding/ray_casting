/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_master.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:53:54 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/12 10:17:20 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_whole_buf(char buffer[], int len, int *buf_len, int *nbr_nulls)
{
	int i;
	int temp_nulls;

	i = 0;
	temp_nulls = (*nbr_nulls);
	while (temp_nulls > 0 && i < len)
	{
		ft_putstr(&(buffer[i]));
		if (temp_nulls > 0)
		{
			i += ft_strlen(&(buffer[i]));
			if (i < len)
			{
				write(1, &(buffer[i]), 1);
				temp_nulls--;
				i++;
			}
		}
	}
	ft_putstr(&(buffer[i]));
	i += ft_strlen(&(buffer[i]));
	(*buf_len) = i - ((*nbr_nulls) - temp_nulls);
	(*nbr_nulls) = temp_nulls;
}

int		ft_apply_options(t_args *options, char *arg, int *real_len)
{
	char	*made_ascii;
	char	char_ascii[3];
	int		craft_len;
	char	craft_buffer[options->min_width +

	ft_get_size(arg, options) + options->precision
	+ 1 + options->modif_null + 10];
	char_ascii[1] = '\0';
	craft_len = options->min_width +
		ft_get_size(arg, options) + options->precision
		+ 1 + options->modif_null + 10;
	ft_memset(craft_buffer, '\0', craft_len);
	made_ascii = arg;
	if (allocated_ascii(&made_ascii, options, arg, char_ascii) == -1)
		return (-1);
	craft_len = spaces_or_zeroes(options, made_ascii, craft_buffer);
	if (options->type != 2 && options->type != -1)
		ft_strdel(&made_ascii);
	if (options->type == 2 && made_ascii[0] == '\0')
		(*real_len)++;
	craft_to_global_buffer(craft_buffer, craft_len);
	return (craft_len);
}

int		is_there_arg(t_args *options, va_list params, int *real_len)
{
	if (options->type == 0)
		return (0);
	if (options->type != -1)
	{
		if (ft_apply_options(options, (char*)(va_arg(params, char*)),
			real_len) == -1)
			return (-1);
	}
	else
	{
		if (ft_apply_options(options, NULL,
			real_len) == -1)
			return (-1);
	}
	return (0);
}
