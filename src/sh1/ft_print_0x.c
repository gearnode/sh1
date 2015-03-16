/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_0x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:31:07 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 17:36:32 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_print_0x(t_fmt *arg_fmt, long long *i)
{
	if (arg_fmt->specifier == 'X')
	{
		ft_putstr("0X");
		*i = *i + 2;
		return (2);
	}
	else
	{
		ft_putstr("0x");
		*i = *i + 2;
		return (2);
	}
	return (0);
}

long long			ft_needs_0x(t_fmt *arg_fmt, unsigned long long arg)
{
	if ((arg_fmt->flags[0] && arg != 0) || arg_fmt->specifier == 'p')
		return (2);
	return (0);
}

long long			ft_print_0x_before(t_fmt *arg_fmt, unsigned long long arg,
					long long num_len)
{
	long long i;

	i = 0;
	if (arg == 0)
	{
		if (arg_fmt->specifier == 'p' && arg_fmt->precision == -1 &&
			(arg_fmt->width <= (ft_get_max(arg_fmt->precision, num_len) + 2) ||
			arg_fmt->flags[4]))
			ft_print_0x(arg_fmt, &i);
	}
	if (0 < arg && (arg_fmt->flags[0] || arg_fmt->specifier == 'p'))
	{
		if (arg_fmt->width <= (ft_get_max(arg_fmt->precision, num_len) + 2))
			ft_print_0x(arg_fmt, &i);
		else if (arg_fmt->flags[4] &&
			ft_get_max(arg_fmt->precision, num_len) <= arg_fmt->width &&
			arg_fmt->precision == -1)
			ft_print_0x(arg_fmt, &i);
		else if (arg_fmt->flags[1])
			ft_print_0x(arg_fmt, &i);
	}
	return (i);
}

long long			ft_print_0x_after(t_fmt *arg_fmt, unsigned long long arg,
					long long num_len)
{
	long long i;

	i = 0;
	if (arg == 0)
	{
		if (arg_fmt->specifier == 'p' &&
			((ft_get_max(arg_fmt->precision, num_len) + 2 < arg_fmt->width &&
			!arg_fmt->flags[4]) || arg_fmt->precision != -1))
			ft_print_0x(arg_fmt, &i);
	}
	if (0 < arg && (arg_fmt->flags[0] || arg_fmt->specifier == 'p') &&
		!arg_fmt->flags[1])
	{
		if (!arg_fmt->flags[1] && !arg_fmt->flags[4] &&
			ft_get_max(arg_fmt->precision, num_len) + 2 < arg_fmt->width)
			ft_print_0x(arg_fmt, &i);
		else if (!arg_fmt->flags[1] && arg_fmt->flags[4] &&
			ft_get_max(arg_fmt->precision, num_len) + 2 < arg_fmt->width &&
			arg_fmt->precision != -1)
			ft_print_0x(arg_fmt, &i);
	}
	return (i);
}
