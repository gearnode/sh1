/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strwchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:37:46 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_print_wchar_string(wchar_t *buf, long long b_index)
{
	long long	b_count;
	long long	outcome;
	long long	index;

	b_count = 0;
	outcome = 0;
	index = 0;
	while (b_count + ft_nb_bytes(buf[index]) <= b_index)
	{
		outcome += ft_putwchar(buf[index]);
		b_count = b_count + ft_nb_bytes(buf[index]);
		index++;
	}
	return (outcome);
}

long long			ft_print_strwchar(va_list ap, t_fmt *arg_fmt)
{
	long long	outcome;
	long long	b_index;
	wchar_t		*buf;

	buf = va_arg(ap, wchar_t *);
	if (!buf)
	{
		ft_putstr("(null)");
		return (6);
	}
	outcome = 0;
	b_index = ft_bytes_to_print(buf, arg_fmt->precision);
	if (!arg_fmt->flags[1])
		outcome += ft_buf_spaces(arg_fmt->width, b_index, arg_fmt->flags);
	outcome += ft_print_wchar_string(buf, b_index);
	if (arg_fmt->flags[1])
		outcome += ft_buf_spaces(arg_fmt->width, b_index, arg_fmt->flags);
	return (outcome);
}
