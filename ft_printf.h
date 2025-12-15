/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:09:44 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 06:27:45 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef char	t_bool;

typedef struct s_print_count
{
	int		index;
	int		current_print;
	int		total_printed;
}	t_vars;

typedef struct s_flags
{
	t_bool	minus;
	t_bool	zero;
	t_bool	dot;
	t_bool	hash;
	t_bool	plus;
	t_bool	space;
	int		width;
	int		precision;
	char	specifier;
}	t_flags;

int		ft_printf(const char *fms, ...);
int		ft_putchar_len(char c, int len);
int		ft_parse_flags(const char *fmt, t_flags *f, va_list args);

int		ft_print_int_fms(int n, t_flags f);
int		ft_print_char_fms(int c, t_flags f);
int		ft_print_str_fms(char *s, t_flags f);

int		ft_print_ptr_fms(void *ptr, t_flags f);

int		ft_print_hex_fms(unsigned int n, t_flags f);

int		ft_print_unsigned_fms(unsigned int n, t_flags f);

int		ft_print_percent_fms(t_flags f);

#endif
