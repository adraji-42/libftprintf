/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_fms.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 05:54:43 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 06:25:24 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_INT_FMS_H
# define FT_PRINT_INT_FMS_H

# include "ft_printf.h"

typedef struct s_lens_print_int
{
	int	len_nbr;
	int	len_zeros;
	int	len_padding;
	int	total_content_len;
}	t_lens;

int		ft_putnbr_abs(int n);
int		ft_put_zeros(int len_zeros, t_vars *var);
int		ft_put_padding(char pad_char, t_lens *len, t_vars *var);

#endif
