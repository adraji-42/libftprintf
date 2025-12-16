/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_data_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:30:37 by adraji            #+#    #+#             */
/*   Updated: 2025/12/16 18:07:42 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DATA_UTILS_H
# define FT_PRINTF_DATA_UTILS_H

# include <stdarg.h>
# include "libft/libft.h"

# define INT_MAX __INT_MAX__
# define INT_MIN _SC_INT_MIN

typedef char	t_bool;

typedef struct s_lens_print_data
{
	int	len_data;
	int	len_zeros;
	int	len_padding;
	int	total_content_len;
}	t_lens;

typedef struct s_print_count
{
	int	index;
	int	current_print;
	int	total_printed;
}	t_vars;

typedef struct s_norminette
{
	t_lens	len;
	t_vars	var;
}	t_levas;

typedef struct s_flags
{
	t_bool	minus;
	t_bool	zero;
	t_bool	dot;
	t_bool	hash;
	t_bool	plus;
	t_bool	space;
	long	width;
	long	precision;
	char	specifier;
}	t_flags;

int	ft_atoi_int_max(const char *nptr);
int	ft_putchar_len(char c, int len);
int	ft_put_padding(char pad_char, t_lens *len, t_vars *var);
int	ft_put_zeros(int len_zeros, t_vars *var);
int	ft_putnbr_abs(int n);
int	ft_parse_flags(const char *fmt, t_flags *f, va_list args);
int	ft_print_int_fms(int n, t_flags f);
int	ft_print_char_fms(int c, t_flags f);
int	ft_print_ptr_fms(void *ptr, t_flags f);
int	ft_print_str_fms(const char *s, t_flags f);
int	ft_print_hex_fms(unsigned int n, t_flags f);
int	ft_print_unsigned_fms(unsigned int n, t_flags f);
int	ft_print_percent_fms(t_flags f);

#endif