/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_fms.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 06:40:21 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 06:59:48 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_percent_fms.h"

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

static void	ft_calc_percent_lens(t_flags *f, t_lens *len)
{
	len->len_zeros = 0;
	len->len_precent = 1;
	len->len_padding = 0;
	len->total_content_len = 1;
	if (f->width > len->total_content_len)
		len->len_padding = f->width - len->total_content_len;
}

int	ft_print_percent_fms(t_flags f)
{
	t_vars	var;
	t_lens	len;
    char    pad_char;

	ft_calc_percent_lens(&f, &len);
	var.total_printed = 0;
    pad_char = ' ';
	if (f.zero && !f.minus)
		pad_char = '0';
    if (!f.minus)
        if (ft_put_padding(pad_char, &len, &var) < 0)
            return (-1);
    var.current_print = ft_putchar_len('%', 1);
    if (var.current_print < 0)
        return (-1);
    var.total_printed += var.current_print;
	if (f.minus)
    {
		if (ft_put_padding(' ', &len, &var) < 0)
			return (-1);
    }
	return (var.total_printed);
}
