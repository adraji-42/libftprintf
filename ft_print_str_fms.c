/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_fms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 06:15:23 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 06:37:15 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_str_fms.h"

static int	ft_put_padding(char pad_char, t_lens *len, t_vars *var)
{
	int	current_char_count;

	current_char_count = 0;
	while ((len->len_padding)-- > 0)
	{
		var->current_print = ft_putchar_len(pad_char, 1);
		if (var->current_print < 0)
			return (-1);
		current_char_count += var->current_print;
	}
	var->total_printed += current_char_count;
	return (1);
}

static void	ft_calc_str_lens(const char *s, t_flags *f, t_lens *len)
{
	size_t	s_len;

	len->len_zeros = 0;
	len->len_padding = 0;
	if (!s)
		s_len = 6;
	else
		s_len = ft_strlen(s);
	if (f->dot && f->precision >= 0 && f->precision < (int)s_len)
		len->len_str = f->precision;
	else
		len->len_str = (int)s_len;
	len->total_content_len = len->len_str;
	if (f->width > len->total_content_len)
		len->len_padding = f->width - len->total_content_len;
}

int	ft_print_str_fms(const char *s, t_flags f)
{
	t_vars	var;
	t_lens	len;
	char	*str_to_print;

	if (!s)
		str_to_print = "(null)";
	else
		str_to_print = (char *)s;
	ft_calc_str_lens(s, &f, &len);
	var.total_printed = 0;
	if (!f.minus)
		if (ft_put_padding(' ', &len, &var) < 0)
			return (-1);
	if (len.len_str > 0)
	{
		var.current_print = write(1, str_to_print, len.len_str);
		if (var.current_print < 0)
			return (-1);
		var.total_printed += var.current_print;
	}
	if (f.minus)
		if (ft_put_padding(' ', &len, &var) < 0)
			return (-1);
	return (var.total_printed);
}
