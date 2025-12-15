/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_fms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 06:28:25 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 06:55:52 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_char_fms.h"

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

static t_lens	ft_calc_c_lens(t_flags f)
{
	t_lens	len;

	len.len_zeros = 0;
	len.len_char = 1;
	len.len_padding = 0;
	len.total_content_len = 1;
	if (f.width > len.total_content_len)
		len.len_padding = f.width - len.total_content_len;
	return (len);
}

int	ft_print_c_fms(va_list args, t_flags f)
{
	int		c;
	t_vars	var;
	t_lens	len;
	char	pad_char;

	c = va_arg(args, int);
	len = ft_calc_c_lens(f);
	var.total_printed = 0;
	pad_char = ' '; 
	if (!f.minus)
		if (ft_put_padding(pad_char, &len, &var) < 0)
			return (-1);
	var.current_print = ft_putchar_len((char)c, 1);
	if (var.current_print < 0)
		return (-1);
	var.total_printed += var.current_print;
	if (f.minus)
		if (ft_put_padding(pad_char, &len, &var) < 0)
			return (-1);
	return (var.total_printed);
}
