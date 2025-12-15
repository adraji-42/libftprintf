#include "ft_print_ptr_fms.h"

static int	ft_ptr_len(unsigned long long n)
{
	int		len;
    size_t	temp;

    len = 0;
    temp = n;
    
    if (temp == 0)
        len = 1;
    else
    {
        while (temp > 0)
        {
            temp /= 16;
            len++;
        }
    }
	return (len);
}

t_lens	ft_calc_p_lens(unsigned long long n, t_flags f)
{
	t_lens	len;
    int     prefix_len;
	
	len.len_zeros = 0;
	len.len_padding = 0;
	prefix_len = 2;
	len.len_ptr = ft_ptr_len(n);
	len.total_content_len = len.len_ptr + prefix_len;
	if (f.width > len.total_content_len)
		len.len_padding = f.width - len.total_content_len;
	
	return (len);
}

static int ft_putnbr_ptr(unsigned long long n)
{
    int count = 0;
    int save = 0;
    char *base = "0123456789abcdef";

    if (n >= 16)
    {
        save = ft_putnbr_ptr(n / 16);
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

int	ft_print_p_fms(va_list args, t_flags f)
{
	size_t	n;
	t_vars	var;
	t_lens	len;
    char	pad_char;

	n = (size_t)va_arg(args, void *);
	pad_char = ' ';
	len = ft_calc_p_lens(n, f);
	var.total_printed = 0;
    if (!f.minus)
		if (ft_put_padding(pad_char, &len, &var) < 0)
			return (-1);
    var.current_print = ft_putchar_len('0', 1);
    var.current_print += ft_putchar_len('x', 1);
    if (var.current_print < 0) return (-1);
    var.total_printed += var.current_print;
	if (len.len_ptr > 0)
	{
		var.current_print = ft_putnbr_ptr(n);
		if (var.current_print < 0)
			return (-1);
		var.total_printed += var.current_print;
	}
	if (f.minus)
		if (ft_put_padding(' ', &len, &var) < 0)
			return (-1);
	return (var.total_printed);
}