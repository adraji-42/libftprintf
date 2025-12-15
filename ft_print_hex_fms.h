/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_fms.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 06:54:02 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 06:55:20 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_HEX_FMS_H
# define FT_PRINT_HEX_FMS_H

# include "ft_printf.h"

typedef struct s_lens_print_hex
{
	int	len_hex;
	int	len_zeros;
	int	len_padding;
	int	total_content_len;
}	t_lens;

#endif