/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_fms.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 06:14:06 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 06:25:30 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_STR_FMS_H
# define FT_PRINT_STR_FMS_H

# include "ft_printf.h"

typedef struct s_lens_print_str
{
	int	len_str;
	int	len_zeros;
	int	len_padding;
	int	total_content_len;
}	t_lens;

#endif

