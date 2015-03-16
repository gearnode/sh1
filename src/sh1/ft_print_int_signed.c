/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:37:17 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_get_arg(va_list ap, t_fmt *arg_fmt)
{
	long long arg;

	arg = 0;
	if (arg_fmt->converter == 'l')
		arg = va_arg(ap, long);
	else if (arg_fmt->converter == 'L')
		arg = va_arg(ap, long long);
	else if (arg_fmt->converter == 'j')
		arg = va_arg(ap, intmax_t);
	else if (arg_fmt->converter == 'z')
		arg = va_arg(ap, size_t);
	else
		arg = va_arg(ap, int);
	if (arg_fmt->converter == 'H')
		arg = (signed char)arg;
	else if (arg_fmt->converter == 'h')
		arg = (short int)arg;
	return (arg);
}

long long			ft_print_int_signed(va_list ap, t_fmt *arg_fmt)
{
	char		*num;
	long long	num_len;
	long long	arg;
	long long	printed;

	printed = 0;
	arg = ft_get_arg(ap, arg_fmt);
	if (arg == 0 && arg_fmt->precision == 0)
	{
		printed += ft_int_signed_spaces_before(arg_fmt, 0, arg);
		printed += ft_int_signed_spaces_after(arg_fmt, 0, printed);
		return (printed);
	}
	num = ft_get_abs_num(arg);
	num_len = (long long)ft_strlen(num);
	printed += ft_int_signed_spaces_before(arg_fmt, num_len, arg);
	ft_putstr(num);
	printed += num_len;
	printed += ft_int_signed_spaces_after(arg_fmt, num_len, printed);
	free(num);
	return (printed);
}
