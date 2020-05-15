/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ascii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:47:31 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/12 10:13:14 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_unsigned_alloc(char *arg)
{
	char *made_ascii;

	if ((int)arg >= 0)
	{
		if (!(made_ascii = ft_litoa((int)arg)))
			return (NULL);
	}
	else if ((int)arg == -2147483648)
	{
		if (!(made_ascii = ft_strdup("2147483648")))
			return (NULL);
	}
	else
	{
		if (!(made_ascii = get_unsigned_int((int)arg)))
			return (NULL);
	}
	return (made_ascii);
}

static char	*get_ascii_3578(char *arg, t_args *options)
{
	char	*made_ascii;

	if (options->type == 3 || options->type == 5)
	{
		if (!(made_ascii = ft_itoa((int)arg)))
			return (NULL);
	}
	if (options->type == 7 || options->type == 8)
	{
		if (!(made_ascii = ft_litoa_base((unsigned int)(arg),
			16, options->type - 7)))
			return (NULL);
	}
	return (made_ascii);
}

static char	*get_char_ascii(t_args *options, char *arg, char joiner[])
{
	char *joined;
	char *made_ascii;

	if (!(made_ascii = ft_litoa_base((long long int)(arg),
		16, options->type - 7)))
		return (NULL);
	if (!(joined = ft_strjoin(joiner, made_ascii)))
	{
		ft_strdel(&made_ascii);
		return (NULL);
	}
	ft_strdel(&made_ascii);
	return (joined);
}

char		*get_ascii(char *arg, t_args *options)
{
	char	*made_ascii;
	char	joiner[3];

	joiner_init(joiner);
	if (options->type == 6)
	{
		if (!(made_ascii = get_unsigned_alloc(arg)))
			return (NULL);
	}
	if (options->type == 3 || options->type == 5 || options->type == 7
		|| options->type == 8)
	{
		if (!(made_ascii = get_ascii_3578(arg, options)))
			return (NULL);
	}
	if (options->type == 4)
	{
		if (!(made_ascii = get_char_ascii(options, arg, joiner)))
			return (NULL);
	}
	return (made_ascii);
}
