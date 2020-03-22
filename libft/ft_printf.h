/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:52:11 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/14 11:10:51 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define BUF_SIZE 1000

typedef	struct	s_args
{
	int		min_width;
	int		minus;
	int		zero;
	int		precision;
	int		type;
	int		size;
	int		error;
	int		field;
	int		modif_null;
	int		nbr_nulls;
}				t_args;

int				ft_printf(const char *format, ...);
t_args			*get_options(char *format, t_args *options, va_list params);
int				get_type(char c);
int				options_reinitializer(t_args *options);
int				ft_get_minus(char *str, t_args *options);
int				ft_get_zero(char *str, t_args *options);
int				ft_get_width(char *str, t_args *options);
int				print_options(t_args *options);
int				print_buff(char buffer[], int len);
int				ft_apply_options(t_args *options, char *arg, int *real_len);
char			get_padded_char(t_args *options);
int				pad_calculator(char *asciized_param, t_args *options);
int				ft_get_size(char *arg, t_args *options);
int				ft_nbrlen(char *str);
int				ft_biggest(int n, int m);
int				spaces_or_zeroes(t_args *options,
					char *asciized_param, char craft_buffer[]);
int				fill_from_index(int start, char c, int len,
					char craft_buffer[]);
char			*get_ascii(char *arg, t_args *options);
char			*ft_itoa_base(int n, int base, int hex_maj);
char			*ft_litoa_base(long long int n, int base, int hex_maj);
void			free_options(t_args *options);
void			buff_check(char buffer[], int *buf_len, int *real_len,
					int *nbr_nulls);
long long int	ft_atoi_base(const char *str, int base);
char			*get_neg_hex(int nb, int maj);
int				base_len(int nb, int base);
char			*null_handler(char *str, t_args *options);
int				get_format_len(char *format);
char			*get_unsigned_int(int nb);
char			*ft_litoa(long long int n);
char			*ft_litoa_base_unsigned(long long int n, int base, int hex_maj);
void			print_whole_buf(char buffer[], int len, int *buf_len,
					int *nbr_nulls);
void			joiner_init(char joiner[]);
int				how_to_handle_it(t_args *options, char *asciized_param,
					char craft_buffer[], int len_ascii);
char			*char_to_string(char ascii[], char *arg, t_args *options);
int				allocated_ascii(char **made_ascii, t_args *options, char *arg,
					char *char_ascii);
int				is_there_arg(t_args *options, va_list params, int *real_len);
int				craft_to_global_buffer(char craft_buffer[], int craft_len);
int				get_prec(char *str, int *i, t_args *options);

#endif
