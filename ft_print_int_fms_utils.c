/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_fms_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:26:27 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 05:59:04 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_int_fms.h"

int	ft_putnbr_abs(int n)
{
	long long	nbr;
	int			save;
	int			count;

	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	count = 0;
	save = 0;
	if (nbr >= 10)
	{
		save = ft_putnbr_abs(nbr / 10);
		if (save < 0)
			return (-1);
		count += save;
	}
	save = ft_putchar_len((nbr % 10) + '0', 1);
	if (save < 0)
		return (-1);
	count += save;
	return (count);
}

int	ft_put_padding(char pad_char, t_lens *len, t_vars *var)
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

int	ft_put_zeros(int len_zeros, t_vars *var)
{
	int	current_print = 0;
	
	while (len_zeros-- > 0)
	{
		var->current_print = ft_putchar_len('0', 1);
		if (var->current_print < 0)
			return (-1);
		current_print += var->current_print;
	}
	var->total_printed += current_print;
	return (1);
}
