/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_them.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:01:36 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/12 10:14:29 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		let_me_handle_this(t_args *options, char *asciized_param,
	char craft_buffer[], int len_ascii)
{
	int i;
	int j;
	int pad;
	int start;
	int len_0;

	i = 1;
	j = 1;
	pad = options->min_width - (options->precision + 1);
	if (pad < 0)
		pad = 0;
	start = 0;
	if (options->minus == 0)
		start = fill_from_index(0, get_padded_char(options), pad, craft_buffer);
	craft_buffer[start++] = '-';
	len_0 = (options->precision - (len_ascii - 1)) + 1;
	while (i++ < len_0)
		craft_buffer[start++] = '0';
	while (asciized_param[j])
		craft_buffer[start++] = asciized_param[j++];
	craft_buffer[start] = '\0';
	if (options->minus == 1)
		start = fill_from_index(start, get_padded_char(options),
			pad, craft_buffer);
	return (start);
}

static int		let_me_handle_that(t_args *options, char *asciized_param,
	char craft_buffer[], int len_ascii)
{
	int i;
	int j;
	int len_0;

	i = 1;
	j = 1;
	craft_buffer[0] = '-';
	len_0 = options->min_width - (len_ascii);
	len_0++;
	while (i < len_0)
		craft_buffer[i++] = '0';
	while (asciized_param[j])
		craft_buffer[i++] = asciized_param[j++];
	craft_buffer[i] = '\0';
	return (i);
}

int				how_to_handle_it(t_args *options, char *asciized_param,
	char craft_buffer[], int len_ascii)
{
	if ((options->type > 2 && asciized_param[0] == '-')
		&& (options->precision > (len_ascii - 1)))
	{
		return (let_me_handle_this(options, asciized_param,
			craft_buffer, len_ascii));
	}
	if ((options->type > 2 && asciized_param[0] == '-')
		&& ((options->min_width > (len_ascii)) && options->zero == 1)
		&& options->precision == -1)
	{
		return (let_me_handle_that(options, asciized_param,
			craft_buffer, len_ascii));
	}
	return (0);
}
