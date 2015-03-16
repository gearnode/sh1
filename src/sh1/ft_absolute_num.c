/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:23:40 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_absolute_num(long long arg, int precision)
{
	char				*num;
	unsigned long long	arg_over;

	if (arg == LONG_MIN)
	{
		arg++;
		arg *= -1;
		arg_over = (unsigned long long)(arg + 1);
		num = ft_itoa_unsigned(arg_over);
	}
	else if (arg < 0)
		num = ft_itoa_unsigned((unsigned long long)(-1 * arg));
	else if (precision == 0 && arg == 0)
		return ("\0");
	else
		num = ft_itoa_unsigned((unsigned long long)arg);
	return (num);
}
