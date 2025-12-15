/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_fms.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 06:29:00 by adraji            #+#    #+#             */
/*   Updated: 2025/12/13 06:54:16 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_CHAR_FMS_H
# define FT_PRINT_CHAR_FMS_H

# include "ft_printf.h"

typedef struct s_lens_print_char
{
	int	len_char;
	int	len_zeros;
	int	len_padding;
	int	total_content_len;
}	t_lens;

#endif