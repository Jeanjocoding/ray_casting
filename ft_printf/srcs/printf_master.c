/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_master.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:53:54 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/12 10:17:30 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	g_buffer[BUF_SIZE];
int		g_real_len;
int		g_nbr_nulls;
int		g_buf_len;

int		craft_to_global_buffer(char craft_buffer[], int craft_len)
{
	int		i;

	i = 0;
	while (i < craft_len)
	{
		buff_check(g_buffer, &g_buf_len, &g_real_len, &g_nbr_nulls);
		g_buffer[g_buf_len++] = craft_buffer[i++];
	}
	g_buffer[g_buf_len] = '\0';
	return (g_buf_len);
}

char	*char_to_string(char ascii[], char *arg, t_args *options)
{
	if (options->type == -1)
	{
		ascii[0] = '%';
		ascii[1] = '\0';
	}
	else if ((int)arg == 0)
	{
		options->modif_null = 1;
		ascii[0] = '\0';
		ascii[1] = '\0';
		g_nbr_nulls++;
	}
	else
	{
		ascii[0] = (char)arg;
		ascii[1] = '\0';
	}
	return (ascii);
}

int		allocated_ascii(char **made_ascii, t_args *options, char *arg,
	char *char_ascii)
{
	if (options->type < 2 && options->type != -1)
	{
		if (!(*made_ascii = null_handler(*made_ascii, options)))
			return (-1);
	}
	if (options->type > 2)
	{
		if (!(*made_ascii = get_ascii(arg, options)))
			return (-1);
	}
	if (options->type == 2 || options->type == -1)
		*made_ascii = char_to_string(char_ascii, arg, options);
	return (1);
}

int		put_all(char *format, t_args *options, va_list params)
{
	int		index[2];
	int		format_len;

	index[0] = 0;
	format_len = ft_strlen(format);
	while (index[0] < format_len)
	{
		index[1] = index[0];
		if (format[index[0]] == '%')
		{
			get_options((char*)&(format[index[0]]), options, params);
			if (is_there_arg(options, params, &g_real_len) == -1)
				return (-1);
			index[0] += (options->size);
			options_reinitializer(options);
		}
		buff_check(g_buffer, &g_buf_len, &g_real_len, &g_nbr_nulls);
		if (format[index[0]] != '%')
			g_buffer[g_buf_len++] = format[index[0]++];
	}
	return (g_buf_len);
}

int		ft_printf(const char *format, ...)
{
	va_list		params;
	int			index[2];
	t_args		options;

	g_real_len = 0;
	g_nbr_nulls = 0;
	index[0] = 0;
	g_buf_len = 0;
	ft_memset(g_buffer, '\0', BUF_SIZE);
	options_reinitializer(&options);
	va_start(params, format);
	if ((g_buf_len = put_all((char*)format, &options, params)) == -1)
		return (-1);
	va_end(params);
	print_whole_buf(g_buffer, g_buf_len, &g_buf_len, &g_nbr_nulls);
	return (g_buf_len + g_real_len);
}
