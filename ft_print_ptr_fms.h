/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_fms.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 07:35:27 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 07:40:21 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_PTR_FMS_H
# define FT_PRINT_PTR_FMS_H

# include "ft_printf.h"

typedef struct s_lens_print_ptr
{
	int	len_ptr;
	int	len_zeros;
	int	len_padding;
	int	total_content_len;
}	t_lens;

#endif