/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long_signed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:37:20 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		ft_print_long_signed(va_list ap, t_fmt *arg_fmt)
{
	char		*num;
	long long	num_len;
	long long	arg;
	long long	printed;

	printed = 0;
	arg = va_arg(ap, long long);
	if (arg == 0 && arg_fmt->precision == 0)
	{
		printed += ft_long_signed_spaces_before(arg_fmt, 0, arg);
		printed += ft_long_signed_spaces_after(arg_fmt, 0, printed);
		return (printed);
	}
	num = ft_get_abs_num(arg);
	num_len = (long long)ft_strlen(num);
	printed += ft_long_signed_spaces_before(arg_fmt, num_len, arg);
	ft_putstr(num);
	printed += num_len;
	printed += ft_long_signed_spaces_after(arg_fmt, num_len, printed);
	free(num);
	return (printed);
}
