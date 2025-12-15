/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_fms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 06:45:48 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 06:52:40 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_unsigned_fms.h"

static int	ft_unbr_len(unsigned int n, t_flags *f)
{
	int	len;
	if (!n && f->dot && !f->precision)
		return (0);
	len = 0;
	unsigned int temp = n;
	if (temp == 0)
		len = 1;
	else
	{
		while (temp > 0)
		{
			temp /= 10;
			len++;
		}
	}
	return (len);
}

t_lens	ft_calc_u_lens(unsigned int n, t_flags f)
{
	t_lens	len;
	int		sign_len;

	sign_len = 0;
	len.len_zeros = 0;
	len.len_padding = 0;
	len.len_unbr = ft_unbr_len(n, &f);
	if (f.dot && f.precision > len.len_unbr)
		len.len_zeros = f.precision - len.len_unbr;
	if (f.dot && len.len_unbr > 0)
		f.zero = 0;
	len.total_content_len = len.len_unbr + len.len_zeros + sign_len;
	if (f.width > len.total_content_len)
		len.len_padding = f.width - len.total_content_len;
	return (len);
}

static int	ft_putnbr_unsigned_abs(unsigned int n)
{
	size_t	nbr;
	int		save;
	int		count;

	nbr = n;
	save = 0;
	count = 0;
	if (nbr >= 10)
	{
		save = ft_putnbr_unsigned_abs(nbr / 10);
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

int	ft_print_u_fms(va_list args, t_flags f)
{
	unsigned int	n;
	t_vars			var;
	t_lens			len;
	char			pad_char;

	n = va_arg(args, unsigned int);
	len = ft_calc_u_lens(n, f);
	var.total_printed = 0;
	pad_char = (f.zero && !f.minus) ? '0' : ' ';
	if (!f.minus && pad_char == ' ')
		if (ft_put_padding(' ', &len, &var) < 0)
			return (-1);
	if (!f.minus && pad_char == '0')
		if (ft_put_padding('0', &len, &var) < 0)
			return (-1);
	if (ft_put_zeros(len.len_zeros, &var) < 0)
		return (-1);
	if (len.len_unbr > 0)
	{
		var.current_print = ft_putnbr_unsigned_abs(n);
		if (var.current_print < 0)
			return (-1);
		var.total_printed += var.current_print;
	}
	if (f.minus)
		if (ft_put_padding(' ', &len, &var) < 0)
			return (-1);
	return (var.total_printed);
}