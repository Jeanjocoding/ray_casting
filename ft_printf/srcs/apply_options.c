/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:03:21 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/10 15:04:22 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fill_from_index(int start, char c, int len, char craft_buffer[])
{
	int	i;

	i = 0;
	while (i < len)
	{
		craft_buffer[start] = c;
		i++;
		start++;
	}
	return (start);
}

int		buff_copy(char buf[], char *made_ascii, int len)
{
	int	i;
	int	len_ascii;

	i = 0;
	len_ascii = ft_strlen(made_ascii);
	while (i < len_ascii && made_ascii[i] != '\0')
		buf[len++] = made_ascii[i++];
	buf[len] = '\0';
	return (len);
}

int		bufferize_prec_int(char *made_ascii, t_args *options,
	char craft_buffer[], int len)
{
	int i;
	int ascii_len;

	i = 0;
	ascii_len = ft_strlen(made_ascii);
	i = options->precision;
	while (i-- > ascii_len)
		craft_buffer[len++] = '0';
	i = 0;
	while (i < ascii_len)
		craft_buffer[len++] = made_ascii[i++];
	craft_buffer[len] = '\0';
	if (ascii_len == 1 && len > 0 && craft_buffer[len - 1] == '0'
		&& options->precision == 0)
	{
		craft_buffer[len - 1] = '\0';
		len--;
	}
	return (len);
}

int		bufferize_with_prec(char *made_ascii,
	t_args *options, char craft_buffer[], int len)
{
	int	i;

	i = 0;
	if (options->precision > -1)
	{
		if (options->type > 2)
			return (bufferize_prec_int(made_ascii, options, craft_buffer, len));
		else if (options->modif_null == 0)
		{
			while (made_ascii[i] && i < options->precision)
				craft_buffer[len++] = made_ascii[i++];
			craft_buffer[len] = '\0';
		}
		else
			len++;
	}
	else
	{
		if (options->modif_null == 0)
			len = buff_copy(craft_buffer, made_ascii, len);
		else
			len++;
	}
	return (len);
}

int		spaces_or_zeroes(t_args *options,
	char *asciized_param, char craft_buffer[])
{
	int		pad;
	int		len;
	int		len_ascii;

	len_ascii = ft_strlen(asciized_param);
	pad = pad_calculator(asciized_param, options);
	if ((len = how_to_handle_it(options, asciized_param,
		craft_buffer, len_ascii)) > 0)
		return (len);
	else if (options->minus == 0)
	{
		len = fill_from_index(0, get_padded_char(options), pad, craft_buffer);
		len = bufferize_with_prec(asciized_param, options, craft_buffer, len);
	}
	else
	{
		len = bufferize_with_prec(asciized_param, options, craft_buffer, 0);
		len = fill_from_index(len, get_padded_char(options), pad, craft_buffer);
	}
	return (len);
}
