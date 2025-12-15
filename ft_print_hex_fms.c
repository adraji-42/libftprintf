/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_fms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 06:53:36 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 07:38:34 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_hex_fms.h"

static int	ft_hex_len(unsigned int n, t_flags *f)
{
	int				len;
    unsigned int	nbr;

	if (!n && f->dot && !f->precision)
		return (0);
    len = 0;
    nbr = n;
    if (nbr == 0)
        len = 1;
    else
    {
        while (nbr > 0)
        {
            nbr /= 16;
            len++;
        }
    }
	return (len);
}

static t_lens	ft_calc_hex_lens(unsigned int n, t_flags f)
{
	t_lens	len;
    int     prefix_len;
	
	len.len_zeros = 0;
	len.len_padding = 0;
	prefix_len = 0;
	if (n != 0 && f.hash)
		prefix_len = 2;
	len.len_hex = ft_hex_len(n, &f);
	if (f.dot && f.precision > len.len_hex)
		len.len_zeros = f.precision - len.len_hex;
	if (f.dot && len.len_hex > 0)
		f.zero = 0;
	len.total_content_len = len.len_hex + len.len_zeros + prefix_len;
	if (f.width > len.total_content_len)
		len.len_padding = f.width - len.total_content_len;
	return (len);
}

static int ft_putnbr_hex(unsigned int n, char case_c)
{
    int count = 0;
    int save = 0;
    char *base;
    
    if (case_c == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";

    if (n >= 16)
    {
        save = ft_putnbr_hex(n / 16, case_c);
        if (save < 0)
            return (-1);
        count += save;
    }
    save = ft_putchar_len(base[n % 16], 1);
    if (save < 0)
        return (-1);
    count += save;
    return (count);
}

static int ft_put_hex_prefix(t_flags f, t_vars *var)
{
    int count = 0;

    if (f.hash)
    {
        if (f.specifier == 'x')
        {
            count += ft_putchar_len('0', 1);
            count += ft_putchar_len('x', 1);
        }
        else
        {
            count += ft_putchar_len('0', 1);
            count += ft_putchar_len('X', 1);
        }
    }
    if (count < 0) return (-1);
    var->total_printed += count;
    return (1);
}

int	ft_print_hex_fms(va_list args, t_flags f)
{
	unsigned int	n;
	t_vars			var;
	t_lens			len;
    char			pad_char;

    n = va_arg(args, unsigned int);
	ft_calc_hex_lens(n, f);
	var.total_printed = 0;
    pad_char = ' ';
	if (f.zero && !f.minus)
		pad_char = '0';
    if (!f.minus && pad_char == ' ')
		if (ft_put_padding(' ', &len, &var) < 0)
			return (-1);
    if (n != 0)
        if (ft_put_hex_prefix(f, &var) < 0)
            return (-1);
    if (!f.minus && pad_char == '0')
		if (ft_put_padding('0', &len, &var) < 0)
			return (-1);
	if (ft_put_zeros(len.len_zeros, &var) < 0)
		return (-1);
	if (len.len_hex > 0)
	{
		var.current_print = ft_putnbr_hex(n, f.specifier);
		if (var.current_print < 0)
			return (-1);
		var.total_printed += var.current_print;
	}
	if (f.minus)
		if (ft_put_padding(' ', &len, &var) < 0)
			return (-1);
	return (var.total_printed);
}
