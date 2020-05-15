/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nulls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:33:29 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/10 16:05:27 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*null_handler(char *str, t_args *options)
{
	options->type = options->type + 1 - 1;
	if (str == NULL)
		return (ft_strdup("(null)"));
	if (str[0] == '\0')
		return (ft_strnew(1));
	else
		return (ft_strdup(str));
}
