/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:38:42 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putwchar(long long n)
{
	char		*mask_unicode;
	int			*bin;
	int			index;
	int			dec;

	if (0 <= n && n <= 255)
	{
		ft_putchar(n);
		return (1);
	}
	dec = 0;
	index = 0;
	mask_unicode = ft_mask_unicode(n);
	bin = ft_convert_binary(mask_unicode);
	while (bin[index] != -42)
	{
		dec = ft_bin_to_dec(bin[index]);
		write(1, &dec, 1);
		index++;
	}
	return (index);
}
