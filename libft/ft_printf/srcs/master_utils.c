/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:34:31 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/10 16:38:39 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buff_check(char buffer[], int *buf_len, int *real_len, int *nbr_nulls)
{
	if (*buf_len == BUF_SIZE - 2)
	{
		print_whole_buf(buffer, *buf_len, buf_len, nbr_nulls);
		ft_memset(buffer, '\0', BUF_SIZE);
		(*real_len) += (*buf_len);
		(*buf_len) = 0;
	}
}
