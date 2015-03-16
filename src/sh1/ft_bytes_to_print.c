/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytes_to_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:24:19 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_bytes_to_print(wchar_t *buf, int precision)
{
	int	index;
	int	buf_len;
	int	b_index;

	buf_len = ft_buflen(buf);
	index = 0;
	b_index = 0;
	while (index < buf_len && (precision == -1 ||
		(b_index + ft_nb_bytes(buf[index])) <= precision))
	{
		b_index = b_index + ft_nb_bytes(buf[index]);
		index++;
	}
	return (b_index);
}
